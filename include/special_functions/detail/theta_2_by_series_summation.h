#ifndef SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_SERIES_SUMMATION_H

namespace detail {
    template<typename T>
    T
    theta_2_by_series_summation(T n, T x) {
        using U = num_traits_t<T>;

        auto sum = std::exp(-n * n / x);
        auto sign = T{-1};

        for (auto k = 1; k < 20; k++) {
            sum += sign * std::exp(-(n + T(k)) * (n + T(k)) / x) + sign * std::exp(-(n - T(k)) * (n - T(k)) / x);
            sign = -sign;

            if (std::abs(sign * std::exp(-(n + T(k)) * (n + T(k)) / x)) < std::numeric_limits<T>::epsilon() * std::abs(sum) && std::abs(
                    sign * std::exp(-(n - T(k)) * (n - T(k)) / x)) < std::numeric_limits<T>::epsilon() * std::abs(sum)) {
                break;
            }
        }

        return sum / std::sqrt(std::numbers::pi_v<U> * x);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_THETA_2_BY_SERIES_SUMMATION_H
