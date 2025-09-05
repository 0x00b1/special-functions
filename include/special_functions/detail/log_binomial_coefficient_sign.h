#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_SIGN_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_SIGN_H

namespace detail {
    template<typename T>
    T
    log_binomial_coefficient_sign(T n, unsigned int k) {
        auto nearby_n = std::nearbyint(n);

        if (nearby_n >= 0 && n == nearby_n) {
            return T{1};
        }

        return log_gamma_sign(T(1) + n) * log_gamma_sign(T(1 + k)) * log_gamma_sign(T(1 - k) + n);
    }

    template<typename T>
    std::complex<T>
    log_binomial_coefficient_sign(std::complex<T> n, unsigned int k) {
        return std::complex<T>{1};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_SIGN_H
