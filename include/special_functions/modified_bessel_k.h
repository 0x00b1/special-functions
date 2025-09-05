#ifndef SPECIAL_FUNCTIONS_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_MODIFIED_BESSEL_K_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/modified_bessel_k.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    modified_bessel_k(T n, U x) {
        using V = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_MODIFIED_BESSEL_K_H
