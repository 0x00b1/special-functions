#ifndef SPECIAL_FUNCTIONS_GAMMA_H
#define SPECIAL_FUNCTIONS_GAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/gamma.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    gamma(T x) {
        using result_type = fp_promote_t<T>;
        return detail::gamma<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    gamma(const std::complex<T>& z) {
        return detail::gamma(z);
    }
}

#endif // SPECIAL_FUNCTIONS_GAMMA_H
