#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H

#include <special_functions/detail/complete_elliptic_integral_pi.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    complete_elliptic_integral_pi(T k, U n) {
        using V = fp_promote_t<T, U>;

        return detail::complete_elliptic_integral_pi<V>(k, n);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
