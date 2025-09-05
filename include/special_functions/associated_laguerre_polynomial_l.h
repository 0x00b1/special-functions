#ifndef SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H
#define SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H

#include <special_functions/detail/associated_laguerre_polynomial_l.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    associated_laguerre_polynomial_l(unsigned int n, unsigned int m, T x) {
        using U = fp_promote_t<T>;

        return detail::assoc_laguerre<U>(n, m, x);
    }

    template<typename T, typename U>
    fp_promote_t<T, U>
    associated_laguerre_polynomial_l(unsigned int n, T a, U x) {
        using V = fp_promote_t<T, U>;

        return detail::assoc_laguerre<V>(n, alpha1, x);
    }
}

#endif // SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H
