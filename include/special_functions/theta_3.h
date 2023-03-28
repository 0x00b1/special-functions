#ifndef SPECIAL_FUNCTIONS_THETA_3_H
#define SPECIAL_FUNCTIONS_THETA_3_H

#include <special_functions/detail/theta_3.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    theta_3(T n, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::theta_3<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_3_H
