#ifndef SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_SIGN_H
#define SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_SIGN_H

#include <complex>

namespace special_functions::detail {
    template<typename T>
    T
    log_binomial_coefficient_sign(T n, unsigned int k) {
        return 0;
    }

    template<typename T>
    std::complex<T>
    log_binomial_coefficient_sign(std::complex<T> n, unsigned int k) {
        return std::complex<T>{0};
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_BINOMIAL_COEFFICIENT_SIGN_H
