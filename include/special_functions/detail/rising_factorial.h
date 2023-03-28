#ifndef SPECIAL_FUNCTIONS_DETAIL_RISING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_RISING_FACTORIAL_H

#include "numeric_limits.h"

namespace special_functions::detail {
    template<typename Tp>
    Tp
    rising_factorial(Tp a, int n)
    {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        using Val = Tp;
        using Real = special_functions::num_traits_t<Val>;
        const auto s_eps = std::numeric_limits<Real>::epsilon();

        if (std::isnan(a))
            return std::numeric_limits<Real>::quiet_NaN();
        else if (n == 0)
            return Tp{1};
        else if (std::abs(a - std::nearbyint(a)) < s_eps)
        {
            auto na = int(std::nearbyint(a));
            if (na < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<Real>)
                && a + n < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<Real>))
                return factorial<Real>(na + n - Real{1})
                       / factorial<Real>(na - Real{1});
            else
                return std::exp(log_factorial<Real>(na + n - Real{1})
                                - log_factorial<Real>(na) - Real{1});
        }
        else if (std::abs(a) < MAXIMUM_FACTORIAL_INDEX<Real>
                 && std::abs(a + n) < MAXIMUM_FACTORIAL_INDEX<Real>)
        {
            auto prod = a;
            for (int k = 1; k < n; ++k)
                prod *= (a + k);
            return prod;
        }
        else
        {
            auto logpoch = log_gamma(a + n) - log_gamma(a);
            auto sign = log_gamma_sign(a + n) * log_gamma_sign(a);
            if (logpoch < special_functions::numeric_limits::log_max(a)) {
                return sign * std::exp(logpoch);
            }

            return sign * std::numeric_limits<Tp>::infinity();
        }
    }

    /**
     * @brief  Return the rising factorial function
     * or the (upper) Pochhammer function.
     * The rising factorial function is defined by
     * @f[
     *   a^{\overline{\nu}} = \Gamma(a + \nu) / \Gamma(\nu)
     * @f]
     * Many notations exist for this function: @f[ (a)_\nu @f],
     * (especially in the literature of special functions),
     *  @f[ \left[ \begin{array}{c}
     *	  a \\
     *	  n \end{array} \right] @f], and others.
     */
    template<typename Tp>
    Tp
    rising_factorial(Tp a, Tp nu)
    {
        const auto s_eps = std::numeric_limits<Tp>::epsilon();

        if (std::isnan(nu) || std::isnan(a))
            return std::numeric_limits<Tp>::quiet_NaN();
        else if (nu == Tp{0})
            return Tp{1};
        else if (std::abs(nu - std::nearbyint(nu)) < s_eps)
        {
            auto n = int(std::nearbyint(nu));
            return rising_factorial(a, n);
        }
        else
        {
            auto logpoch = log_gamma(a + nu) - log_gamma(a);
            auto sign = log_gamma_sign(a + nu) * log_gamma_sign(a);
            if (logpoch < special_functions::numeric_limits::log_max(a))
                return sign * std::exp(logpoch);
            else
                return sign * std::numeric_limits<Tp>::infinity();
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_RISING_FACTORIAL_H
