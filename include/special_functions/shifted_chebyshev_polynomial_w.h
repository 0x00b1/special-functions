#ifndef SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_W_H
#define SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_W_H

#include <special_functions/detail/shifted_chebyshev_polynomial_w.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    shifted_chebyshev_polynomial_w(unsigned int n, T x) {
        using U = special_functions::fp_promote_t<T>;

        // return special_functions::detail::chebyshev_w<U>(n, x).W_n;
    }
}

#endif // SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_W_H
