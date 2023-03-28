#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H

namespace special_functions::detail {
    template<typename T>
    T
    log_falling_factorial(T a, T n) {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto is_integer_n = special_functions::fp_is_integer(n);
        const auto is_integer_a = special_functions::fp_is_integer(a);

        if (std::isnan(n) || std::isnan(a)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        if (n == T{0}) {
            return T{0};
        }

        if (is_integer_n) {
            if (is_integer_a) {
                if (is_integer_a() < is_integer_n()) {
                    return -std::numeric_limits<U>::infinity();
                }

                return log_factorial<U>(unsigned(is_integer_a())) -
                       log_factorial<U>(unsigned(is_integer_a() - is_integer_n()));
            }

            return std::log(std::abs(falling_factorial(a, is_integer_n())));
        }

        if (std::abs(a) < MAXIMUM_FACTORIAL_INDEX<V> && std::abs(a - n) < MAXIMUM_FACTORIAL_INDEX<V>) {
            return std::log(std::abs(falling_factorial(a, n)));
        }

        return log_gamma(a + T{1}) - log_gamma(a - n + T{1});
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H
