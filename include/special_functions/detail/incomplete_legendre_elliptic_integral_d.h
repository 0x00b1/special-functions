#ifndef SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
#define SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H

namespace detail {
    template<typename T>
    T
    incomplete_legendre_elliptic_integral_d(T k, T p)
    {
        using U = num_traits_t<T>;

        if (std::isnan(k) || std::isnan(p)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) > U{1}) {
            throw std::domain_error("`k` must be in [-1, 1]");
        }

        const auto x = T{1} - std::sin(p) * std::sin(p);
        const auto y = T{1} - k * k * (std::sin(p) * std::sin(p));
        const auto z = T{1};

        return std::sin(p) * (std::sin(p) * std::sin(p)) * carlson_elliptic_r_d(x, y, z) / T{3};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
