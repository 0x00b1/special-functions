#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_4_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_4_H

#include <special_functions/detail/jacobi_theta_4.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    jacobi_theta_4(T q, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::jacobi_theta_4<V>(q, x);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_4_H
