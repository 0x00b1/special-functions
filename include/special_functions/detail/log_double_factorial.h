#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_DOUBLE_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_DOUBLE_FACTORIAL_H

#include <special_functions/cos_pi.h>
#include <special_functions/log_gamma.h>

namespace special_functions::detail {
    template<typename T>
    constexpr T
    log_double_factorial(T n) {
        return n / T{2} * std::log(T{2}) +
               (special_functions::cos_pi(n) - T{1}) * std::log(std::numbers::pi_v<T> / T{2}) / T{4} +
               special_functions::log_gamma(T{1} + n / T{2});
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_DOUBLE_FACTORIAL_H
