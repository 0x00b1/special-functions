#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H

namespace special_functions::detail {
    template<typename T>
    T
    log_binomial_coefficient(unsigned int n, unsigned int k) {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (k > n) {
            return -U(std::numeric_limits<V>::infinity());
        }

        if (k == 0 || k == n) {
            return U{0};
        }

        if (n < MAXIMUM_FACTORIAL_INDEX<V> && k < MAXIMUM_FACTORIAL_INDEX<V>) {
            return log_factorial<U>(n) - log_factorial<U>(k) - log_factorial<U>(n - k);
        }

        return log_gamma(U(1 + n)) - log_gamma(U(1 + k)) - log_gamma(U(1 + n - k));
    }

    template<typename T>
    T
    log_binomial_coefficient(T n, unsigned int k) {
        auto nearby_n = std::nearbyint(n);

        if (nearby_n >= 0 && n == nearby_n) {
            return log_binomial_coefficient<T>(static_cast<unsigned int>(nearby_n), k);
        }

        return log_gamma(T(1) + n) - log_gamma(T(1 + k)) - log_gamma(T(1 - k) + n);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H
