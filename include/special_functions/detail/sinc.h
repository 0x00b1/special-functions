#ifndef SPECIAL_FUNCTIONS_DETAIL_SINC_H
#define SPECIAL_FUNCTIONS_DETAIL_SINC_H

namespace detail {
    template<typename T>
    special_functions::fp_promote_t<T>
    sinc(T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(x) == std::numeric_limits<T>::infinity()) {
            return T{0};
        }

        if (std::abs(x) < numeric_limits::sqrt_min(x)) {
            return T{1} - x * x / T{6};
        }

        return std::sin(x) / x;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINC_H
