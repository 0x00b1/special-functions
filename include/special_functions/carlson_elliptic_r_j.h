#ifndef SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_J_H
#define SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_J_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/carlson_elliptic_r_j.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    carlson_elliptic_r_j(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::carlson_elliptic_r_j<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_CARLSON_ELLIPTIC_R_J_H
