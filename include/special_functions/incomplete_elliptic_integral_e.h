#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H

#include <special_functions/detail/incomplete_elliptic_integral_e.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    incomplete_elliptic_integral_e(T k, U p) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::incomplete_elliptic_integral_e<V>(k, p);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
