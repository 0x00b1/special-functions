#ifndef SPECIAL_FUNCTIONS_BESSEL_J_H
#define SPECIAL_FUNCTIONS_BESSEL_J_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/bessel_j.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    bessel_j(T n, U x) {
        using type = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_BESSEL_J_H
