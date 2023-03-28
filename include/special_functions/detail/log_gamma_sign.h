#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_SIGN_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_SIGN_H

namespace special_functions::detail {
    template<typename T>
    T
    log_gamma_sign(T a) {
        if (a >= T{0}) {
            return T{1};
        }

        if (a == std::nearbyint(a)) {
            return T{0};
        }

        if (int(-a) % 2 == 0) {
            return -T{1};
        }

        return T{1};
    }

    template<typename T>
    std::complex<T>
    log_gamma_sign(std::complex<T>) {
        return std::complex<T>{1};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_SIGN_H
