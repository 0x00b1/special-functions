#ifndef SPECIAL_FUNCTIONS_THETA_2_H
#define SPECIAL_FUNCTIONS_THETA_2_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/theta_2.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    theta_2(T n, U x) {
        using V = fp_promote_t<T, U>;

        return detail::theta_2<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_2_H
