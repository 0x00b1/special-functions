#ifndef SPECIAL_FUNCTIONS_LOG_GAMMA_SIGN_H
#define SPECIAL_FUNCTIONS_LOG_GAMMA_SIGN_H


#include <complex>


namespace special_functions {
    template<typename T>
    T
    log_gamma_sign(T a) {
        return 0;
    }

    template<typename T>
    std::complex<T>
    log_gamma_sign(std::complex<T>) {
        return std::complex<T>{0};
    }

}

#endif // SPECIAL_FUNCTIONS_LOG_GAMMA_SIGN_H
