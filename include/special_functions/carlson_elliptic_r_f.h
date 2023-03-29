#ifndef SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_F_H
#define SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_F_H

#include <special_functions/detail/carlson_elliptic_r_f.h>

namespace special_functions {
    template<typename T, typename U, typename V>
    inline special_functions::fp_promote_t<T, U, V>
    carlson_elliptic_r_f(T x, U y, V z) {
        using W = special_functions::fp_promote_t<T, U, V>;

        return special_functions::detail::carlson_elliptic_r_f<W>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_F_H
