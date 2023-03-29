#ifndef SPECIAL_FUNCTIONS_DETAIL_JACOBI_POLYNOMIAL_P_T_H
#define SPECIAL_FUNCTIONS_DETAIL_JACOBI_POLYNOMIAL_P_T_H

namespace special_functions::detail {
    template<typename Tp>
    struct jacobi_t
    {
        unsigned int n;
        Tp alpha1;
        Tp beta1;
        Tp x;
        Tp P_n;
        Tp P_nm1;
        Tp P_nm2;

        constexpr Tp
        deriv() const noexcept
        {
            auto apbp2k = alpha1 + beta1 + Tp(2 * n);
            return (n * (alpha1 - beta1 - apbp2k * x) * P_nm1
                    + Tp{2} * (n + alpha1) * (n + beta1) * P_nm2)
                   / (apbp2k * (Tp{1} - x * x));
        }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_JACOBI_POLYNOMIAL_P_T_H
