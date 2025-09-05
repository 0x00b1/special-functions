#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_4_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_4_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/jacobi_theta_4.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    jacobi_theta_4(T q, U x) {
        using V = fp_promote_t<T, U>;

        return detail::jacobi_theta_4<V>(q, x);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_4_H
