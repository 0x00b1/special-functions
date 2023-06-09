#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H

#include <special_functions/detail/bulirsch_elliptic_integral_el3.h>

namespace special_functions {
    template<typename T, typename U, typename V>
    inline special_functions::fp_promote_t<T, U, V>
    bulirsch_elliptic_integral_el3(T x, U k_c, V p) {
        using W = special_functions::fp_promote_t<T, U, V>;

        return special_functions::detail::bulirsch_elliptic_integral_el3<W>(x, k_c, p);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
