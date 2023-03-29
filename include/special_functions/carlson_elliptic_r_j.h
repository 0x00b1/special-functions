#ifndef SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_J_H
#define SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_J_H

#include <special_functions/detail/carlson_elliptic_r_j.h>

namespace special_functions {
    template<typename T, typename U, typename V, typename W>
    inline special_functions::fp_promote_t<T, U, V, W>
    carlson_elliptic_r_j(T x, U y, V z, W p) {
        using X = special_functions::fp_promote_t<T, U, V, W>;

        return special_functions::detail::carlson_elliptic_r_j<X>(x, y, z, p);
    }
}

#endif // SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_J_H
