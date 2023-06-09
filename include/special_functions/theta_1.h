#ifndef SPECIAL_FUNCTIONS_THETA_1_H
#define SPECIAL_FUNCTIONS_THETA_1_H

#include <special_functions/detail/theta_1.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    theta_1(T n, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::theta_1<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_1_H
