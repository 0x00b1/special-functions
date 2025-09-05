#ifndef SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/jacobi_polynomial_p.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    jacobi_polynomial_p(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::jacobi_polynomial_p<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
