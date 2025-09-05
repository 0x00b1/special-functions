#ifndef SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_T_T_H
#define SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_T_T_H

namespace detail {
    template<typename Tp>
    struct chebyshev_t_t
    {
        unsigned int n;
        Tp x;
        Tp T_n;
        Tp T_nm1;
        Tp T_nm2;

        constexpr Tp
        deriv() const noexcept
        { return Tp(n) * (T_nm1 - x * T_n) / (Tp{1} - x * x); }

        constexpr Tp
        deriv2() const noexcept
        {
            const auto xx = x * x;
            const auto num = Tp{1} - xx;
            return Tp(n)
                   * (x * T_nm1 + (Tp(n - 1) * xx - Tp(n)) * T_n)
                   / num / num;
        }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_T_T_H
