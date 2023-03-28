#ifndef SPECIAL_FUNCTIONS_DETAIL_POLYGAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_POLYGAMMA_H

#include "math_util.h"

namespace special_functions::detail {
    template<typename T>
    T
    polygamma(unsigned int m, T x) {
        if (m == 0) {
            return digamma(x);
        } else if (const auto n = special_functions::fp_is_integer(x); n && n() <= 0) {
            return std::numeric_limits<T>::quiet_NaN();
        } else {
            const auto hzeta = hurwitz_zeta(T(m + 1), x);

            const auto ln_nfact = log_gamma(T(m + 1));

            auto result = std::exp(ln_nfact) * hzeta;

            if (m % 2 == 0) {
                result = -result;
            }

            return result;
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_POLYGAMMA_H
