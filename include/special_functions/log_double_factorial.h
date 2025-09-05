#ifndef SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H
#define SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/log_double_factorial.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    log_double_factorial(T x) {
        using result_type = fp_promote_t<T>;
        return detail::log_double_factorial<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H
