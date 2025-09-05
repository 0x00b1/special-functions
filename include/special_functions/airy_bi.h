#ifndef SPECIAL_FUNCTIONS_AIRY_BI_H
#define SPECIAL_FUNCTIONS_AIRY_BI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/airy_bi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    airy_bi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::airy_bi<result_type>(x);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    airy_bi(const std::complex<T>& z) {
        return detail::airy_bi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_BI_H
