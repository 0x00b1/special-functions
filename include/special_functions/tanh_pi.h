#ifndef SPECIAL_FUNCTIONS_TANH_PI_H
#define SPECIAL_FUNCTIONS_TANH_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/tanh_pi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    tanh_pi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::tanh_pi<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    tanh_pi(const std::complex<T>& z) {
        return detail::tanh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_TANH_PI_H
