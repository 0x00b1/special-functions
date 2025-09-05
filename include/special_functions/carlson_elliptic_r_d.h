#ifndef SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_D_H
#define SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_D_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/carlson_elliptic_r_d.h>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    carlson_elliptic_r_d(T x, U y, V z) {
        using W = fp_promote_t<T, U, V>;

        return detail::carlson_elliptic_r_d<W>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_D_H
