#ifndef SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_V_T_H
#define SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_V_T_H

namespace special_functions::detail {
    template<typename Tp>
    struct chebyshev_v_t
    {
        unsigned int n;
        Tp x;
        Tp V_n;
        Tp V_nm1;
        Tp V_nm2;

        constexpr Tp
        deriv() const noexcept
        {
            auto apbp2k = Tp(2 * n);
            return (n * (Tp{1} - apbp2k * x) * V_nm1
                    + Tp(2 * (n + 0.5L) * (n + -0.5L)) * V_nm2)
                   / (apbp2k * (Tp{1} - x * x));
        }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_V_T_H
