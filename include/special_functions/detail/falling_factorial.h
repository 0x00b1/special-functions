#ifndef SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H

#include <special_functions/numeric_limits.h>

namespace detail {
    template<typename T>
    T
    falling_factorial(T a, int n) {
        using numbers::MAXIMUM_FACTORIAL_INDEX;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto is_integer_a = fp_is_integer(a);

        if (std::isnan(a)) {
            return std::numeric_limits<V>::quiet_NaN();
        }

        if (n == 0) {
            return T{1};
        }

        if (is_integer_a) {
            auto integer_a = is_integer_a();

            if (integer_a < n) {
                return T{0};
            }

            if (integer_a < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<V> ) &&
                integer_a - n < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<V> )) {
                return factorial<V>(integer_a) / factorial<V>(integer_a - n);
            }

            return std::exp(log_factorial<V>(integer_a) - log_factorial<V>(integer_a - n));
        }

        if (std::abs(a) < MAXIMUM_FACTORIAL_INDEX<V> && std::abs(a - n) < MAXIMUM_FACTORIAL_INDEX<V>) {
            auto prod = a;

            for (int k = 1; k < n; ++k) {
                prod *= (a - k);
            }

            return prod;
        }

        auto logpoch = log_gamma(a + T{1}) - log_gamma(a - n + T{1});

        auto sign = log_gamma_sign(a + T{1}) * log_gamma_sign(a - n + T{1});

        if (logpoch < numeric_limits::log_max(a)) {
            return sign * std::exp(logpoch);
        }

        return sign * std::numeric_limits<T>::infinity();
    }

    template<typename T>
    T
    falling_factorial(T a, T n) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto integer_n = fp_is_integer(n);
        const auto integer_a = fp_is_integer(a);

        if (std::isnan(n) || std::isnan(a)) {
            return std::numeric_limits<V>::quiet_NaN();
        }

        if (n == T{0}) {
            return T{1};
        }

        if (integer_n) {
            if (integer_a && integer_a() < integer_n()) {
                return T{0};
            }

            return falling_factorial(a, integer_n());
        }

        auto logpoch = log_gamma(a + T{1}) - log_gamma(a - n + T{1});
        auto sign = log_gamma_sign(a + T{1}) * log_gamma_sign(a - n + T{1});

        if (logpoch < numeric_limits::log_max(a)) {
            return sign * std::exp(logpoch);
        }

        return sign * std::numeric_limits<T>::infinity();
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H
