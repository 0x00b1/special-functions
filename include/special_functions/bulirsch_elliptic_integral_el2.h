#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H

#include <special_functions/detail/bulirsch_elliptic_integral_el2.h>

namespace special_functions {
    template<typename T, typename U, typename V, typename W>
    inline special_functions::fp_promote_t<T, U, V, W>
    bulirsch_elliptic_integral_el2(T x, U k_c, V a, W b) {
        using X = special_functions::fp_promote_t<T, U, V, W>;

        return special_functions::detail::bulirsch_elliptic_integral_el2<X>(x, k_c, a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H
