#ifndef SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H
#define SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/polylogarithm_li.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    polylogarithm_li(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::polylogarithm_li<result_type>(x, y, z);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    polylogarithm_li(const std::complex<T>& z) {
        return detail::polylogarithm_li(z);
    }
}

#endif // SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H
