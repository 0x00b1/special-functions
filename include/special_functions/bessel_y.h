#ifndef SPECIAL_FUNCTIONS_BESSEL_Y_H
#define SPECIAL_FUNCTIONS_BESSEL_Y_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/bessel_y.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    bessel_y(T n, U x) {
        using type = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_BESSEL_Y_H
