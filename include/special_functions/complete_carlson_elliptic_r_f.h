#ifndef SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_F_H
#define SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_F_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/complete_carlson_elliptic_r_f.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    complete_carlson_elliptic_r_f(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::complete_carlson_elliptic_r_f<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_CARLSON_ELLIPTIC_R_F_H
