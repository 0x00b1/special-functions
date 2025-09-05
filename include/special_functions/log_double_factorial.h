#ifndef SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H
#define SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/log_double_factorial.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    log_double_factorial(int n) {
        using U = fp_promote_t<T>;

        return detail::log_double_factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H
