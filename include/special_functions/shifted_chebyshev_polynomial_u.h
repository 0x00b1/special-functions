#ifndef SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_U_H
#define SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_U_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/shifted_chebyshev_polynomial_u.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    shifted_chebyshev_polynomial_u(T x) {
        using result_type = fp_promote_t<T>;
        return detail::shifted_chebyshev_polynomial_u<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_U_H
