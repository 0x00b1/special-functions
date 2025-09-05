#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_1_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_1_H

#include <special_functions/detail/jacobi_theta_1.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    jacobi_theta_1(T q, U x) {
        using V = fp_promote_t<T, U>;

        return detail::jacobi_theta_1<V>(q, x);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_1_H
