#ifndef SPECIAL_FUNCTIONS_LEGENDRE_Q_H
#define SPECIAL_FUNCTIONS_LEGENDRE_Q_H

#include <special_functions/detail/legendre_q.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    legendre_q(unsigned int l, T x) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::legendre_q<U>(l, x).Q_l;
    }
}

#endif // SPECIAL_FUNCTIONS_LEGENDRE_Q_H
