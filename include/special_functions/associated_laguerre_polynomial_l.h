#ifndef SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H
#define SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/associated_laguerre_polynomial_l.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    associated_laguerre_polynomial_l(unsigned int n, unsigned int m, T x) {
        using U = fp_promote_t<T>;

        return x;
    }

    template<typename T, typename U>
    fp_promote_t<T, U>
    associated_laguerre_polynomial_l(unsigned int n, T a, U x) {
        using V = fp_promote_t<T, U>;

       return x;
    }
}

#endif // SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H
