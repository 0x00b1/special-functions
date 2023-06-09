#ifndef SPECIAL_FUNCTIONS_THETA_4_H
#define SPECIAL_FUNCTIONS_THETA_4_H

#include <special_functions/detail/theta_4.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    theta_4(T n, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::theta_4<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_4_H
