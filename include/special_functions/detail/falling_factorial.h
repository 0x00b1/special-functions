#ifndef SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H

namespace special_functions::detail {
    /**
     * @brief  Return the logarithm of the falling factorial function
     * or the lower Pochhammer symbol for real argument @f$ a @f$
     * and integral order @f$ n @f$.
     * The falling factorial function is defined by
     * @f[
     *   a^{\underline{n}} = \prod_{k=0}^{n-1} (a - k), (a)_0 = 1
     *	     = \Gamma(a + 1) / \Gamma(a - n + 1)
     * @f]
     * In particular, @f$ n^{\underline{n}} = n! @f$.
     */
    template<typename Tp>
    Tp
    falling_factorial(Tp a, int n)
    {
        using Val = Tp;
        using Real = emsr::num_traits_t<Val>;
        const auto ia = emsr::fp_is_integer(a);

        if (std::isnan(a))
            return emsr::quiet_NaN(Real{});
        else if (n == 0)
            return Tp{1};
        else if (ia)
        {
            auto na = ia();
            if (na < n)
                return Tp{0};
            else if (na < static_cast<int>(s_num_factorials<Real>)
                     && na - n < static_cast<int>(s_num_factorials<Real>))
                return factorial<Real>(na) / factorial<Real>(na - n);
            else
                return std::exp(log_factorial<Real>(na)
                                - log_factorial<Real>(na - n));
        }
        else if (std::abs(a) < s_num_factorials<Real>
                 && std::abs(a - n) < s_num_factorials<Real>)
        {
            auto prod = a;
            for (int k = 1; k < n; ++k)
                prod *= (a - k);
            return prod;
        }
        else
        {
            auto logpoch = log_gamma(a + Tp{1})
                           - log_gamma(a - n + Tp{1});
            auto sign = log_gamma_sign(a + Tp{1})
                        * log_gamma_sign(a - n + Tp{1});
            if (logpoch < emsr::log_max(a))
                return sign * std::exp(logpoch);
            else
                return sign * emsr::infinity(a);
        }
    }

    /**
     * @brief Return the falling factorial function
     * or the lower Pochhammer symbol for real argument @f$ a @f$
     * and order @f$ \nu @f$.
     * The falling factorial function is defined by
     * @f[
     *   a^{\underline{\nu}} = \Gamma(a + 1) / \Gamma(a - \nu + 1)
     * @f]
     */
    template<typename Tp>
    Tp
    falling_factorial(Tp a, Tp nu)
    {
        using Val = Tp;
        using Real = emsr::num_traits_t<Val>;
        const auto inu = emsr::fp_is_integer(nu);
        const auto ia = emsr::fp_is_integer(a);

        if (std::isnan(nu) || std::isnan(a))
            return emsr::quiet_NaN(Real{});
        else if (nu == Tp{0})
            return Tp{1};
        else if (inu)
        {
            if (ia && ia() < inu())
                return Tp{0};
            else
                return falling_factorial(a, inu());
        }
        else
        {
            auto logpoch = log_gamma(a + Tp{1})
                           - log_gamma(a - nu + Tp{1});
            auto sign = log_gamma_sign(a + Tp{1})
                        * log_gamma_sign(a - nu + Tp{1});
            if (logpoch < emsr::log_max(a))
                return sign * std::exp(logpoch);
            else
                return sign * emsr::infinity(a);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H
