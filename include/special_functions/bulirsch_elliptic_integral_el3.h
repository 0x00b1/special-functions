#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H

#include <special_functions/detail/bulirsch_elliptic_integral_el3.h>

namespace special_functions {
    template<typename Tx, typename Tk, typename Tp>
    inline special_functions::fp_promote_t<Tx, Tk, Tp>
    bulirsch_elliptic_integral_el3(Tx x, Tk k_c, Tp p) {
        using type = special_functions::fp_promote_t<Tx, Tk, Tp>;

        return special_functions::detail::bulirsch_elliptic_integral_el3<type>(x, k_c, p);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL3_H
