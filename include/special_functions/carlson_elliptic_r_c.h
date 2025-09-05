#ifndef SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_C_H
#define SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_C_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/carlson_elliptic_r_c.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    carlson_elliptic_r_c(T x, U y) {
        using V = fp_promote_t<T, U>;

        return detail::carlson_elliptic_r_c<V>(x, y);
    }
}

#endif // SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_C_H
