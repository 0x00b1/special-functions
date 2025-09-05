#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/bulirsch_elliptic_integral_el1.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    bulirsch_elliptic_integral_el1(T x, U k_c) {
        using V = fp_promote_t<T, U>;

        return detail::bulirsch_elliptic_integral_el1<V>(x, k_c);
    }

}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
