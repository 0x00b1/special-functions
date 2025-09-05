#ifndef SPECIAL_FUNCTIONS_DETAIL_RISING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_RISING_FACTORIAL_H

#include <special_functions/numeric_limits.h>

namespace detail {
    template<typename T>
    T
    rising_factorial(T a, int n) {
        using numbers::MAXIMUM_FACTORIAL_INDEX;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (std::isnan(a)) {
            return std::numeric_limits<V>::quiet_NaN();
        }

        if (n == 0) {
            return T{1};
        }

        if (std::abs(a - std::nearbyint(a)) < std::numeric_limits<V>::epsilon()) {
            auto nearby_integer_a = int(std::nearbyint(a));

            if (nearby_integer_a < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<V>) &&
                a + n < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<V>)) {
                return factorial<V>(nearby_integer_a + n - V{1}) / factorial<V>(nearby_integer_a - V{1});
            }

            return std::exp(log_factorial<V>(nearby_integer_a + n - V{1}) - log_factorial<V>(nearby_integer_a) - V{1});
        }

        if (std::abs(a) < MAXIMUM_FACTORIAL_INDEX<V> && std::abs(a + n) < MAXIMUM_FACTORIAL_INDEX<V>) {
            auto b = a;

            for (int k = 1; k < n; k++) {
                b *= (a + k);
            }

            return b;
        }

        if (log_gamma(a + n) - log_gamma(a) < numeric_limits::log_max(a)) {
            return log_gamma_sign(a + n) * log_gamma_sign(a) * std::exp(log_gamma(a + n) - log_gamma(a));
        }

        return log_gamma_sign(a + n) * log_gamma_sign(a) * std::numeric_limits<T>::infinity();
    }

    template<typename T>
    T
    rising_factorial(T a, T n) {
        if (std::isnan(n) || std::isnan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (n == T{0}) {
            return T{1};
        }

        if (std::abs(n - std::nearbyint(n)) < std::numeric_limits<T>::epsilon()) {
            return rising_factorial(a, int(std::nearbyint(n)));
        }

        if (log_gamma(a + n) - log_gamma(a) < numeric_limits::log_max(a)) {
            return log_gamma_sign(a + n) * log_gamma_sign(a) * std::exp(log_gamma(a + n) - log_gamma(a));
        }

        return log_gamma_sign(a + n) * log_gamma_sign(a) * std::numeric_limits<T>::infinity();
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_RISING_FACTORIAL_H
