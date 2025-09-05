#ifndef SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_V_H
#define SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_V_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    shifted_chebyshev_polynomial_v(unsigned int n, T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_V_H
