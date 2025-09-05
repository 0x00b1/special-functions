#ifndef SPECIAL_FUNCTIONS_DETAIL_SINC_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_SINC_PI_H

namespace detail {
    template<typename T>
    fp_promote_t<T>
    sinc_pi(T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(x) == std::numeric_limits<T>::infinity()) {
            return T{0};
        }

        if (std::abs(std::numbers::pi_v<T> * x) < T{4} * numeric_limits::sqrt_min(x)) {
            return T{1} - std::numbers::pi_v<T> * x * (std::numbers::pi_v<T> * x) / T{6};
        }

        return sin_pi(x) / (std::numbers::pi_v<T> * x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINC_PI_H
