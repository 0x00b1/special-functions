#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_S_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_S_H

#include <special_functions/detail/neville_theta_s.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    neville_theta_s(T k, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::neville_theta_s<V>(k, x);
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_S_H
