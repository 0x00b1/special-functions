#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_G_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_G_H

namespace special_functions::detail {
    template<typename T>
    T
    carlson_elliptic_r_g(T x, T y, T z) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x) || std::isnan(y) || std::isnan(z)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        if (z == T{0}) {
            return complete_carlson_elliptic_r_g(x, y);
        }

        if (x == T{0}) {
            return complete_carlson_elliptic_r_g(y, z);
        }

        if (y == T{0}) {
            return complete_carlson_elliptic_r_g(z, x);
        }

        const auto r_d_xyz = carlson_elliptic_r_d(x, y, z);
        const auto r_d_yzx = carlson_elliptic_r_d(y, z, x);
        const auto r_d_zxy = carlson_elliptic_r_d(z, x, y);

        return (x * (y + z) * r_d_yzx + y * (z + x) * r_d_zxy + z * (x + y) * r_d_xyz) / U{6};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_G_H
