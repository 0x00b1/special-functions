#ifndef SPECIAL_FUNCTIONS_DETAIL_SINHC_PI_H
#define SPECIAL_FUNCTIONS_DETAIL_SINHC_PI_H

namespace detail {
    template<typename T>
    special_functions::fp_promote_t<T>
    sinhc_pi(T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(std::numbers::pi_v<T> * x) < T{4} * numeric_limits::sqrt_min(x)) {
            return T{1} + std::numbers::pi_v<T> * x * (std::numbers::pi_v<T> * x) / T{6};
        }

        return sinh_pi(x) / (std::numbers::pi_v<T> * x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINHC_PI_H
