#ifndef SPECIAL_FUNCTIONS_LEGENDRE_Q_H
#define SPECIAL_FUNCTIONS_LEGENDRE_Q_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/legendre_q.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    legendre_q(unsigned int l, T x) {
        using U = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_LEGENDRE_Q_H
