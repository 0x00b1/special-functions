#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H

#include <special_functions/detail/bulirsch_elliptic_integral_cel.h>
#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    template<typename T, typename U, typename V, typename W>
    fp_promote_t<T, U, V, W>
    bulirsch_elliptic_integral_cel(T k_c, U p, V a, W b) {
        using X = fp_promote_t<T, U, V, W>;

        return detail::bulirsch_elliptic_integral_cel<X>(k_c, p, a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
