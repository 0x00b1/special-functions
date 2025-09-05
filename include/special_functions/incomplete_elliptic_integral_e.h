#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/incomplete_elliptic_integral_e.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    incomplete_elliptic_integral_e(T k, U p) {
        using V = fp_promote_t<T, U>;

        return detail::incomplete_elliptic_integral_e<V>(k, p);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
