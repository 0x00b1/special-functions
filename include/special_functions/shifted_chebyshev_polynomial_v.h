#ifndef SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_V_H
#define SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_V_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    shifted_chebyshev_polynomial_v(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::chebyshev_v<type>(n, x).V_n;
    }
}

#endif // SPECIAL_FUNCTIONS_SHIFTED_CHEBYSHEV_POLYNOMIAL_V_H
