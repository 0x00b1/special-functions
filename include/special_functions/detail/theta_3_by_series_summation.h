#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_SERIES_SUMMATION_H

namespace special_functions::detail {
    template<typename T>
    T
    theta_3_by_series_summation(T n, T x) {
        using U = special_functions::num_traits_t<T>;

        auto sum = std::exp(-n * n / x);

        for (auto k = 1; k < 20; ++k) {
            sum += std::exp(-(n + T(k)) * (n + T(k)) / x) + std::exp(-(n - T(k)) * (n - T(k)) / x);
            if (std::abs(std::exp(-(n + T(k)) * (n + T(k)) / x)) < std::numeric_limits<T>::epsilon() * std::abs(sum)
                && std::abs(std::exp(-(n - T(k)) * (n - T(k)) / x)) < std::numeric_limits<T>::epsilon() * std::abs(sum))
                break;
        }
        return sum / std::sqrt(std::numbers::pi_v<U> * x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_3_BY_SERIES_SUMMATION_H
