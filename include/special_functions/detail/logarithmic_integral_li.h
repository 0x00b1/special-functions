#ifndef SPECIAL_FUNCTIONS_DETAIL_LOGARITHMIC_INTEGRAL_LI_H
#define SPECIAL_FUNCTIONS_DETAIL_LOGARITHMIC_INTEGRAL_LI_H

#include "exponential_integral_ei.h"

namespace detail {
    template<typename T>
    T
    logarithmic_integral_li(const T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(x) == T{1}) {
            return std::numeric_limits<T>::infinity();
        }

        return exponential_integral_ei(std::log(x));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOGARITHMIC_INTEGRAL_LI_H
