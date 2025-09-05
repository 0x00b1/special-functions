#ifndef SPECIAL_FUNCTIONS_THETA_1_H
#define SPECIAL_FUNCTIONS_THETA_1_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/theta_1.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    theta_1(T n, U x) {
        using V = fp_promote_t<T, U>;

        return detail::theta_1<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_1_H
