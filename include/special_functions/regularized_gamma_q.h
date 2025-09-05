#ifndef SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_Q_H
#define SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_Q_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/regularized_gamma_q.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    regularized_gamma_q(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::regularized_gamma_q<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_Q_H
