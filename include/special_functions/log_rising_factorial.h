#ifndef SPECIAL_FUNCTIONS_LOG_RISING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_LOG_RISING_FACTORIAL_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/log_rising_factorial.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    log_rising_factorial(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::log_rising_factorial<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_RISING_FACTORIAL_H
