#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_T_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_T_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    chebyshev_polynomial_t(unsigned int n, T x) {
        using type = fp_promote_t<T>;

        return detail::chebyshev_t_t<type>(n, x).T_n;
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_T_H
