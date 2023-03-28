#ifndef SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H

namespace special_functions {
    template<typename T, typename U, typename V>
    inline special_functions::fp_promote_t<T, U, V>
    jacobi_polynomial_p(unsigned n, T a, U b, V x) {
        using W = special_functions::fp_promote_t<T, U, V>;

        return special_functions::detail::jacobi_polynomial_p<W>(n, a, b, x).P_n;
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
