#ifndef SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_W_H
#define SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_W_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    chebyshev_polynomial_w(unsigned int n, T x) {
        using type = fp_promote_t<T>;

        return detail::chebyshev_w_t<type>(n, x).W_n;
    }
}

#endif // SPECIAL_FUNCTIONS_CHEBYSHEV_POLYNOMIAL_W_H
