#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H

#include <limits>

namespace special_functions::detail {
    template<typename T>
    T
    log_binomial_coefficient(unsigned int n, unsigned int k) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (k > n) {
            return -U(std::numeric_limits<V>::infinity());
        } else if (k == 0 || k == n) {
            return U{0};
        } else if (n < special_functions::numbers::MAXIMUM_FACTORIAL_INDEX<V> &&
                   k < special_functions::numbers::MAXIMUM_FACTORIAL_INDEX<V>) {
            return log_factorial<U>(n) - log_factorial<U>(k) - log_factorial<U>(n - k);
        } else {
            return log_gamma(U(1 + n)) - log_gamma(U(1 + k)) - log_gamma(U(1 + n - k));
        }
    }

    template<typename Tp>
    Tp
    log_binomial_coefficient(Tp nu, unsigned int k) {
        auto n = std::nearbyint(nu);

        if (n >= 0 && nu == n) {
            return log_binomial<Tp>(static_cast<unsigned int>(n), k);
        } else {
            return log_gamma(Tp(1) + nu) - log_gamma(Tp(1 + k)) - log_gamma(Tp(1 - k) + nu);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H
