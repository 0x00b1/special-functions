#ifndef SPECIAL_FUNCTIONS_THETA_3_H
#define SPECIAL_FUNCTIONS_THETA_3_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/theta_3.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    theta_3(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::theta_3<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_3_H
