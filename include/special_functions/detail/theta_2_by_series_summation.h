#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_SERIES_SUMMATION_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    theta_2_by_series_summation(Tp nu, Tp x)
    {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        const auto s_pi = std::numbers::pi_v<Real>;
        auto sum = std::exp(-nu * nu / x);
        auto sign = Tp{-1};
        for (auto k = 1; k < 20; ++k)
        {
            const auto nup = nu + Tp(k);
            const auto termp = sign * std::exp(-nup * nup / x);
            const auto num = nu - Tp(k);
            const auto termm = sign * std::exp(-num * num / x);
            sum += termp + termm;
            sign = -sign;
            if (std::abs(termp) < s_eps * std::abs(sum)
                && std::abs(termm) < s_eps * std::abs(sum))
                break;
        }
        return sum / std::sqrt(s_pi * x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_SERIES_SUMMATION_H
