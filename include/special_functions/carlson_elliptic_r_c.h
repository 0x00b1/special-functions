#ifndef SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_C_H
#define SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_C_H

#include <special_functions/detail/carlson_elliptic_r_c.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    carlson_elliptic_r_c(T x, U y) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::carlson_elliptic_r_c<V>(x, y);
    }
}

#endif // SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_C_H
