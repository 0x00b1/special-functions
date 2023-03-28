#ifndef SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_H

#include <special_functions/detail/log_binomial_coefficient.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    log_binomial_coefficient(unsigned int n, unsigned int k) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::log_binomial_coefficient<U>(n, k);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_H
