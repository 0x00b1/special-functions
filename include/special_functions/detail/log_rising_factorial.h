#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_RISING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_RISING_FACTORIAL_H

namespace detail {
    template<typename T>
    T
    log_rising_factorial(T a, T n) {
        using numbers::MAXIMUM_FACTORIAL_INDEX;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (std::isnan(n) || std::isnan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (n == T{0}) {
            return T{0};
        }

        if (std::abs(a) < MAXIMUM_FACTORIAL_INDEX<V> && std::abs(a + n) < MAXIMUM_FACTORIAL_INDEX<V>) {
            return std::log(rising_factorial(a, n));
        }

        return log_gamma(a + n) - log_gamma(a);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_RISING_FACTORIAL_H
