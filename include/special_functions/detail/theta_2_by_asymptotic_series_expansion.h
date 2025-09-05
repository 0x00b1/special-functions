#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_ASYMPTOTIC_SERIES_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_ASYMPTOTIC_SERIES_EXPANSION_H

namespace detail {
    template<typename T>
    T
    theta_2_by_asymptotic_series_expansion(T n, T x) {
        using U = num_traits_t<T>;

        auto summation = T{0};

        for (auto k = 0; k < 20; k++) {
            summation += std::exp(-(T(2 * k + 1) * std::numbers::pi_v<U> * (T(2 * k + 1) * std::numbers::pi_v<U>) * x / T{4})) * std::cos(n * (T(2 * k + 1) * std::numbers::pi_v<U>));

            if (std::abs(std::exp(-(T(2 * k + 1) * std::numbers::pi_v<U> * (T(2 * k + 1) * std::numbers::pi_v<U>) * x / T{4})) * std::cos(n * (T(2 * k + 1) * std::numbers::pi_v<U>))) < std::numeric_limits<T>::epsilon() * std::abs(summation)) {
                break;
            }
        }

        return T{2} * summation;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_ASYMPTOTIC_SERIES_EXPANSION_H
