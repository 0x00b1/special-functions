#ifndef SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_W_T_H
#define SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_W_T_H

namespace detail {
    template<typename Tp>
    struct chebyshev_w_t
    {
        unsigned int n;
        Tp x;
        Tp W_n;
        Tp W_nm1;
        Tp W_nm2;

        constexpr Tp
        deriv() const noexcept
        {
            auto apbp2k = Tp(2 * n);
            return (n * (Tp{-1} - apbp2k * x) * W_nm1
                    + Tp(2 * (n - 0.5L) * (n + 0.5L)) * W_nm2)
                   / (apbp2k * (Tp{1} - x * x));
        }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_W_T_H
