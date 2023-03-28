#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_U_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_U_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    chebyshev_polynomial_u(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::chebyshev_u<type>(n, x).U_n;
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_U_H
