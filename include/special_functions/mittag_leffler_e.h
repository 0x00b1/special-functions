#ifndef SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
#define SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/mittag_leffler_e.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    mittag_leffler_e(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::mittag_leffler_e<result_type>(x, y, z);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    mittag_leffler_e(const std::complex<T>& z) {
        return detail::mittag_leffler_e(z);
    }
}

#endif // SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
