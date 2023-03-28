#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H

namespace special_functions::detail {
    /**
     * @brief  Return the logarithm of the falling factorial function
     * or the lower Pochhammer symbol.
     * The lower Pochammer symbol is defined by
     * @f[
     *   a^{\underline{n}} = \Gamma(a + 1) / \Gamma(a - \nu + 1)
     *	     = \prod_{k=0}^{n-1} (a - k), (a)_0 = 1
     * @f]
     * In particular, @f$ n^{\underline{n}} = n! @f$.
     * Thus this function returns
     * @f[
     *   ln[a^{\underline{n}}] = ln[\Gamma(a + 1)] - ln[\Gamma(a - \nu + 1)],
     *      ln[a^{\underline{0}}] = 0
     * @f]
     * Many notations exist for this function: @f[ (a)_\nu @f],
     *  @f[ \{ \begin{array}{c}
     *	  a \\
     *	  \nu \end{array} \} @f], and others.
     */
    template<typename Tp>
    Tp
    log_falling_factorial(Tp a, Tp nu)
    {
        using Val = Tp;
        using Real = emsr::num_traits_t<Val>;
        const auto s_NaN = emsr::quiet_NaN<Val>();
        const auto s_inf = emsr::infinity<Val>();
        const auto inu = emsr::fp_is_integer(nu);
        const auto ia = emsr::fp_is_integer(a);

        if (std::isnan(nu) || std::isnan(a))
            return s_NaN;
        else if (nu == Tp{0})
            return Tp{0};
        else if (inu)
        {
            if (ia)
            {
                if (ia() < inu())
                    return -s_inf;
                else
                    return log_factorial<Val>(unsigned(ia()))
                           - log_factorial<Val>(unsigned(ia() - inu()));
            }
            else
                return std::log(std::abs(falling_factorial(a, inu())));
        }
        else if (std::abs(a) < s_num_factorials<Real>
                 && std::abs(a - nu) < s_num_factorials<Real>)
            return std::log(std::abs(falling_factorial(a, nu)));
        else
            return log_gamma(a + Tp{1}) - log_gamma(a - nu + Tp{1});
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H
