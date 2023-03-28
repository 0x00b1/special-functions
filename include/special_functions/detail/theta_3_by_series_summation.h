#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_SERIES_SUMMATION_H

namespace special_functions::detail {
    /**
   * Compute and return the exponential @f$ \theta_3 @f$ function
   * by series expansion:
   * @f[
   *    \theta_3(\nu, x) = \frac{1}{\sqrt{\pi x}}
   *                       \sum_{k=-\infty}^{\infty} e^{-(\nu+k)^2/x}
   * @f]
   */
    template<typename Tp>
    Tp
    theta_3_sum(Tp nu, Tp x) {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        const auto s_pi = std::numbers::pi_v<Real>;
        auto sum = std::exp(-nu * nu / x);
        for (auto k = 1; k < 20; ++k) {
            const auto nup = nu + Tp(k);
            const auto termp = std::exp(-nup * nup / x);
            const auto num = nu - Tp(k);
            const auto termm = std::exp(-num * num / x);
            sum += termp + termm;
            if (std::abs(termp) < s_eps * std::abs(sum)
                && std::abs(termm) < s_eps * std::abs(sum))
                break;
        }
        return sum / std::sqrt(s_pi * x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_SERIES_SUMMATION_H
