#ifndef SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_G_H
#define SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_G_H

#include <special_functions/detail/complete_carlson_elliptic_r_g.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    complete_carlson_elliptic_r_g(T x, U y) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::complete_carlson_elliptic_r_g<V>(x, y);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_G_H
