#ifndef SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H
#define SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H

#include <special_functions/detail/bose_einstein_integral_g.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    bose_einstein_integral_g(T s, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::bose_einstein<V>(s, x);
    }
}

#endif // SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H
