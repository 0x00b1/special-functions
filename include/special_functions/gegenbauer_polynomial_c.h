#ifndef SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H
#define SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/gegenbauer_polynomial_c.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    gegenbauer_polynomial_c(unsigned int n, T l, U x) {
        using V = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H
