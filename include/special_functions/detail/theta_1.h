#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_1_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_1_H

namespace detail {
    template<typename T>
    T
    theta_1(T n, T x) {
        if (std::isnan(n) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN(std::abs(x));
        }

        if (fp_is_zero(x)) {
            return T{0};
        }

        return theta_2(n - T{0.5L}, x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_1_H
