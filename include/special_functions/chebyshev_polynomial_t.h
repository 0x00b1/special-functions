#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_T_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_T_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/chebyshev_polynomial_t.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    chebyshev_polynomial_t(T x) {
        using result_type = fp_promote_t<T>;
        return detail::chebyshev_polynomial_t<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_T_H
