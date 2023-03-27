#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H

namespace special_functions::detail {
    template<typename T>
    T
    log_gamma(T a) {
        return 0;
    }

    template<typename T>
    std::complex<T>
    log_gamma(std::complex<T> a) {
        return 0;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H
