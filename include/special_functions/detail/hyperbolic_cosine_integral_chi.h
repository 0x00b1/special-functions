#ifndef SPECIAL_FUNCTIONS_DETAIL_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
#define SPECIAL_FUNCTIONS_DETAIL_HYPERBOLIC_COSINE_INTEGRAL_CHI_H

#include "exponential_integral_e1.h"
#include "exponential_integral_ei.h"

namespace detail {
    template<typename T>
    T
    hyperbolic_cosine_integral_chi(const T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (x == T{0}) {
            return T{0};
        }

        return (exponential_integral_ei(x) - exponential_integral_e1(x)) / T{2};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
