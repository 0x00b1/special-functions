#ifndef SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    log_binomial_coefficient(unsigned int n, unsigned int k) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::log_binomial<U>(n, k);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_H
