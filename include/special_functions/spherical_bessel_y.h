#ifndef SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_Y_H

#include <special_functions/detail/spherical_bessel_y.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_bessel_y(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return detail::spherical_bessel_y<U>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_Y_H
