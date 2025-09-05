#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/bulirsch_elliptic_integral_el1.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    bulirsch_elliptic_integral_el1(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::bulirsch_elliptic_integral_el1<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
