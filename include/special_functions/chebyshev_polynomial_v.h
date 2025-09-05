#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_V_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_V_H

#include <special_functions/detail/chebyshev_polynomial_v.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    chebyshev_polynomial_v(unsigned int n, T x) {
        using type = fp_promote_t<T>;

        return detail::chebyshev_v_t<type>(n, x).V_n;
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_V_H
