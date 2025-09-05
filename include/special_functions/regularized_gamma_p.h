#ifndef SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_P_H
#define SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_P_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/regularized_gamma_p.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    regularized_gamma_p(T a, U x) {
        using V = fp_promote_t<T, U>;

        return detail::regularized_gamma_p<V>(a, x);
    }
}

#endif // SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_P_H
