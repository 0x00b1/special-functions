#ifndef SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H

namespace special_functions {
    template<typename T, typename U, typename V>
    inline special_functions::fp_promote_t<T, U, V>
    jacobi_polynomial_p(unsigned n, T alpha, U beta, V x) {
        using type = special_functions::fp_promote_t<T, U, V>;

        // return emsr::detail::jacobi_recur<type>(n, alpha, beta, x).P_n;
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_POLYNOMIAL_P_H
