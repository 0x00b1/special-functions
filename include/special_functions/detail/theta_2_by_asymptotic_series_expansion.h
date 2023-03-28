#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_ASYMPTOTIC_SERIES_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_ASYMPTOTIC_SERIES_EXPANSION_H

namespace special_functions::detail {
    template<typename T>
    T
    theta_2_by_asymptotic_series_expansion(T n, T x) {
        using Real = special_functions::num_traits_t<T>;
        const auto s_eps = std::numeric_limits<T>::epsilon();
        const auto s_pi = std::numbers::pi_v<Real>;
        auto sum = T{0};
        for (auto k = 0; k < 20; ++k) {
            const auto thing = T(2 * k + 1) * s_pi;
            const auto cosarg = n * thing;
            const auto exparg = thing * thing * x / T{4};
            const auto term = std::exp(-exparg) * std::cos(cosarg);
            sum += term;
            if (std::abs(term) < s_eps * std::abs(sum))
                break;
        }
        return T{2} * sum;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_ASYMPTOTIC_SERIES_EXPANSION_H
