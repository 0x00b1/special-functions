#ifndef SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H

#include <special_functions/detail/legendre_polynomial_p.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    legendre_polynomial_p(unsigned int l, T x) {
        using U = fp_promote_t<T>;

        return detail::legendre_p<U>(l, x).P_l;
    }
}

#endif // SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H
