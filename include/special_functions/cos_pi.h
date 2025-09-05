#ifndef SPECIAL_FUNCTIONS_COS_PI_H
#define SPECIAL_FUNCTIONS_COS_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/cos_pi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    cos_pi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::cos_pi<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    cos_pi(const std::complex<T>& z) {
        return detail::cos_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_COS_PI_H
