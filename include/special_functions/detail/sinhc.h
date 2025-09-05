#ifndef SPECIAL_FUNCTIONS_DETAIL_SINHC_H
#define SPECIAL_FUNCTIONS_DETAIL_SINHC_H

namespace detail {
    template<typename T>
    special_functions::fp_promote_t<T>
    sinhc(T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(x) < T{4} * numeric_limits::sqrt_min(x)) {
            return T{1} + x * x / T{6};
        }

        return std::sinh(x) / x;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SINHC_H
