#ifndef SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H
#define SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H

#include <special_functions/detail/gegenbauer_polynomial_c.h>

namespace special_functions {
    template<typename T, typename U>
    inline typename special_functions::fp_promote_t<T, U>
    gegenbauer_polynomial_c(unsigned int n, T l, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::gegenbauer_recur<V>(n, l, x).C_n;
    }
}

#endif // SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H
