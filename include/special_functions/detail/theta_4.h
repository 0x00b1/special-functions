#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_4_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_4_H

#include "theta_3.h"

namespace special_functions::detail {
    template<typename T>
    T
    theta_4(T n, T x) {
        if (std::isnan(n) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        return theta_3(n + T{0.5L}, x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_4_H
