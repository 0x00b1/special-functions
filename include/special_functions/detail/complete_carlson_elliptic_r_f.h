#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_CARLSON_ELLIPTIC_R_F_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_CARLSON_ELLIPTIC_R_F_H

namespace special_functions::detail {
    template<typename T>
    T
    complete_carlson_elliptic_r_f(T x, T y) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x) || std::isnan(y)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        x = std::sqrt(x);
        y = std::sqrt(y);

        while (true) {
            auto previous_x = x;

            x = (x + y) / U{2};
            y = std::sqrt(previous_x) * std::sqrt(y);

            if (std::abs(x - y) < U{2.7L} * special_functions::numeric_limits::sqrt_eps(U{}) * std::abs(x)) {
                return std::numbers::pi_v<U> / (x + y);
            }
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_CARLSON_ELLIPTIC_R_F_H
