#ifndef SPECIAL_FUNCTIONS_LOG_FACTORIAL_H
#define SPECIAL_FUNCTIONS_LOG_FACTORIAL_H

#include <special_functions/detail/log_factorial.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    log_factorial(unsigned int n) {
        using U = fp_promote_t<T>;

        return detail::log_factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_FACTORIAL_H
