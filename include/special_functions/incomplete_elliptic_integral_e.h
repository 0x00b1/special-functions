#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/incomplete_elliptic_integral_e.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    incomplete_elliptic_integral_e(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::incomplete_elliptic_integral_e<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
