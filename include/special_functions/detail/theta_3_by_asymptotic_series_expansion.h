#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_ASYMPTOTIC_SERIES_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_ASYMPTOTIC_SERIES_EXPANSION_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    theta_3_by_asymptotic_series_expansion(Tp nu, Tp x) {
        using Real = special_functions::num_traits_t<Tp>;
        const auto s_eps = std::numeric_limits<Tp>::epsilon();
        const auto s_pi = std::numbers::pi_v<Real>;
        auto sum = Tp{0};
        for (auto k = 1; k < 20; ++k) {
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
