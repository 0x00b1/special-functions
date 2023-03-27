#ifndef SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_T_H
#define SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_T_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    shifted_chebyshev_polynomial_t(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::chebyshev_t<type>(n, x).T_n;
    }
}

#endif // SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_T_H
