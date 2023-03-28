#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H

#include <special_functions/detail/neville_theta_d.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    neville_theta_d(T k, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::neville_theta_d<V>(k, x);
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H
