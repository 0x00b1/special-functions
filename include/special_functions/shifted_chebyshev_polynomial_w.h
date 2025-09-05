#ifndef SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_W_H
#define SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_W_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/shifted_chebyshev_polynomial_w.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    shifted_chebyshev_polynomial_w(T x) {
        using result_type = fp_promote_t<T>;
        return detail::shifted_chebyshev_polynomial_w<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_W_H
