#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_1_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/jacobi_theta_1.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    jacobi_theta_1(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::jacobi_theta_1<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_1_H
