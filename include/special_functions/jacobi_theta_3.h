#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_3_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_3_H

#include <special_functions/detail/jacobi_theta_3.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    jacobi_theta_3(T q, U x) {
        using V = fp_promote_t<T, U>;

        return detail::jacobi_theta_3<V>(q, x);
    }

}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_3_H
