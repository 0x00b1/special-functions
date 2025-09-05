#ifndef SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_P_H
#define SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_P_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/associated_legendre_p.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    associated_legendre_p(unsigned int l, unsigned int m, T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_P_H
