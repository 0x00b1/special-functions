#ifndef SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H
#define SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H

#include <special_functions/detail/bose_einstein_integral_g.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    bose_einstein_integral_g(T s, U x) {
        using V = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H
