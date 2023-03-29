#ifndef SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_Q_H
#define SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_Q_H

#include <special_functions/detail/associated_legendre_q.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    associated_legendre_q(unsigned int l, unsigned int m, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::assoc_legendre_q<type>(l, m, x).Q_lm;
    }
}

#endif // SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_Q_H
