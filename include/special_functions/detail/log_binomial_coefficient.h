#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H

namespace special_functions::detail {
    template<typename T>
    T
    log_binomial_coefficient(unsigned int n, unsigned int k) {
        return 0;
    }

    template<typename T>
    T
    log_binomial_coefficient(T n, unsigned int k) {
        return 0;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_BINOMIAL_COEFFICIENT_H
