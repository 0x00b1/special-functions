#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_W_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_W_H

#include <special_functions/detail/chebyshev_polynomial_w.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    chebyshev_polynomial_w(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::chebyshev_w<type>(n, x).W_n;
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_W_H
