#ifndef SPECIAL_FUNCTIONS_DETAIL_HYPERBOLIC_SINE_INTEGRAL_SHI_H
#define SPECIAL_FUNCTIONS_DETAIL_HYPERBOLIC_SINE_INTEGRAL_SHI_H

#include "exponential_integral_e1.h"
#include "exponential_integral_ei.h"

namespace detail {
    template<typename T>
    T
    hyperbolic_sine_integral_shi(const T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        return (exponential_integral_ei(x) + exponential_integral_e1(x)) / T{2};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HYPERBOLIC_SINE_INTEGRAL_SHI_H
