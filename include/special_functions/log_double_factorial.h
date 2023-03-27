#ifndef SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H
#define SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    log_double_factorial(int n) {
        using U = special_functions::fp_promote_t<T>;

        // return special_functions::detail::log_double_factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_DOUBLE_FACTORIAL_H
