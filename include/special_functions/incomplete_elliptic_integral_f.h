#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_F_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_F_H

#include <special_functions/detail/incomplete_elliptic_integral_f.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    incomplete_elliptic_integral_f(T k, U p) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::incomplete_elliptic_integral_f<V>(k, p);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_F_H
