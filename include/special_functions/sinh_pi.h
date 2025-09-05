#ifndef SPECIAL_FUNCTIONS_SINH_PI_H
#define SPECIAL_FUNCTIONS_SINH_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/sinh_pi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinh_pi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::sinh_pi<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    sinh_pi(const std::complex<T>& z) {
        return detail::sinh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SINH_PI_H
