#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_2_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_2_H

#include <special_functions/detail/jacobi_theta_2.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    jacobi_theta_2(T q, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::jacobi_theta_2<V>(q, x);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_2_H
