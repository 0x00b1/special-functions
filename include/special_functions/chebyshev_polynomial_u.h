#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_U_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_U_H

#include <special_functions/detail/chebyshev_polynomial_u.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    chebyshev_polynomial_u(unsigned int n, T x) {
        using type = fp_promote_t<T>;

        return detail::chebyshev_u_t<type>(n, x).U_n;
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_U_H
