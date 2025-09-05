#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/complete_elliptic_integral_pi.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    complete_elliptic_integral_pi(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::complete_elliptic_integral_pi<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
