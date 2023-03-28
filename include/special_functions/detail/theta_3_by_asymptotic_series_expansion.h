#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_ASYMPTOTIC_SERIES_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_ASYMPTOTIC_SERIES_EXPANSION_H

namespace special_functions::detail {
    /**
 * Compute and return the exponential @f$ \theta_3 @f$ function
 * by asymptotic series expansion:
 * @f[
 *    \theta_3(\nu, x) = 1 + 2\sum_{k=1}^{\infty} e^{-(k\pi)^2 x}
 *                           \cos(2k\nu\pi)
 * @f]
 */
    template<typename Tp>
    Tp
    theta_3_asymp(Tp nu, Tp x)
    {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        const auto s_pi = std::numbers::pi_v<Real>;
        auto sum = Tp{0};
        for (auto k = 1; k < 20; ++k)
        {
            const auto thing = Tp(2 * k) * s_pi;
            const auto cosarg = nu * thing;
            const auto exparg = thing * thing * x / Tp{4};
            const auto term = std::exp(-exparg) * std::cos(cosarg);
            sum += term;
            if (std::abs(term) < s_eps * std::abs(sum))
                break;
        }
        return Tp{1} + Tp{2} * sum;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_ASYMPTOTIC_SERIES_EXPANSION_H
