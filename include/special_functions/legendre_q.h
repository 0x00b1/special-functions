#ifndef SPECIAL_FUNCTIONS_LEGENDRE_Q_H
#define SPECIAL_FUNCTIONS_LEGENDRE_Q_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/legendre_q.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    legendre_q(T x) {
        using result_type = fp_promote_t<T>;
        return detail::legendre_q<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LEGENDRE_Q_H
