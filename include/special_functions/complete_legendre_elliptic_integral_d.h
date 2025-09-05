#ifndef SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
#define SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/complete_legendre_elliptic_integral_d.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    complete_legendre_elliptic_integral_d(T x) {
        using result_type = fp_promote_t<T>;
        return detail::complete_legendre_elliptic_integral_d<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
