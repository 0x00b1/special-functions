#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_FACTORIAL_H

#include <special_functions/numbers.h>

namespace detail {
    template<typename T>
    constexpr T
    log_factorial(unsigned int n) {
        if (n < numbers::MAXIMUM_FACTORIAL_INDEX<T>) {
            return numbers::LOG_FACTORIALS[n];
        }

        if (n < numbers::MAXIMUM_DOUBLE_FACTORIAL_INDEX<T>) {
            const auto a = numbers::LOG_DOUBLE_FACTORIALS[n];
            const auto b = numbers::LOG_DOUBLE_FACTORIALS[n - 1];

            return a + b;
        }

        return log_gamma(T(n + 1));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_FACTORIAL_H
