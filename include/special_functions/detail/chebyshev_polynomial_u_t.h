#ifndef SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_U_T_H
#define SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_U_T_H

namespace detail {
    template<typename Tp>
    struct chebyshev_u_t
    {
        unsigned int n;
        Tp x;
        Tp U_n;
        Tp U_nm1;
        Tp U_nm2;

        constexpr Tp
        deriv() const noexcept
        {
            return (Tp(n + 1) * U_nm1 - Tp(n) * x * U_n)
                   / (Tp{1} - x * x);
        }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_U_T_H
