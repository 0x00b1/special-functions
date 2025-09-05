#ifndef SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H


#include <complex>


namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    jacobi_polynomial_p(unsigned n, T a, U b, V x) {
        using W = fp_promote_t<T, U, V>;

        return detail::jacobi_polynomial_p<W>(n, a, b, x).P_n;
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
