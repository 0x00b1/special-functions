#ifndef SPECIAL_FUNCTIONS_LOG_FACTORIAL_H
#define SPECIAL_FUNCTIONS_LOG_FACTORIAL_H

#include <special_functions/detail/log_factorial.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    log_factorial(unsigned int n) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::log_factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_FACTORIAL_H
