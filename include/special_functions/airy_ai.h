#ifndef SPECIAL_FUNCTIONS_AIRY_AI_H
#define SPECIAL_FUNCTIONS_AIRY_AI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/airy_ai.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    airy_ai(T x) {
        using result_type = fp_promote_t<T>;
        return detail::airy_ai<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    airy_ai(const std::complex<T>& z) {
        return detail::airy_ai(z);
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_AI_H
