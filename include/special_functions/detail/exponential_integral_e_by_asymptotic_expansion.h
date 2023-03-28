#ifndef SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E_BY_ASYMPTOTIC_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E_BY_ASYMPTOTIC_EXPANSION_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    exponential_integral_e_by_asymptotic_expansion(unsigned int n, Tp x) {
        auto term = Tp{1};
        auto sum = Tp{1};
        for (unsigned int i = 1; i <= n; ++i) {
            auto prev = term;
            term *= -Tp(n - i + 1) / x;
            if (std::abs(term) > std::abs(prev))
                break;
            sum += term;
        }

        return std::exp(-x) * sum / x;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_EXPONENTIAL_INTEGRAL_E_BY_ASYMPTOTIC_EXPANSION_H
