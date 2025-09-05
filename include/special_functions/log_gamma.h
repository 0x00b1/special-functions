#ifndef SPECIAL_FUNCTIONS_LOG_GAMMA_H
#define SPECIAL_FUNCTIONS_LOG_GAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/log_gamma.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    log_gamma(T a) {
        using U = fp_promote_t<T>;

        return detail::log_gamma<U>(a);
    }

    template<typename T>
    std::complex<fp_promote_t<T>>
    log_gamma(std::complex<T> a) {
        using U = std::complex<fp_promote_t<T>>;

        return detail::log_gamma<U>(a);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_GAMMA_H
