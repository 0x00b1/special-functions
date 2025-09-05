#ifndef SPECIAL_FUNCTIONS_COSH_PI_H
#define SPECIAL_FUNCTIONS_COSH_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/cosh_pi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    cosh_pi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::cosh_pi<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    cosh_pi(const std::complex<T>& z) {
        return detail::cosh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_COSH_PI_H
