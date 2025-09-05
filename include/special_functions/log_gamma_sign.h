#ifndef SPECIAL_FUNCTIONS_LOG_GAMMA_SIGN_H
#define SPECIAL_FUNCTIONS_LOG_GAMMA_SIGN_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/log_gamma_sign.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    log_gamma_sign(T x) {
        using result_type = fp_promote_t<T>;
        return detail::log_gamma_sign<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    log_gamma_sign(const std::complex<T>& z) {
        return detail::log_gamma_sign(z);
    }
}

#endif // SPECIAL_FUNCTIONS_LOG_GAMMA_SIGN_H
