#ifndef SPECIAL_FUNCTIONS_SPHERICAL_LEGENDRE_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_LEGENDRE_Y_H

#include <special_functions/detail/spherical_legendre_y.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_legendre_y(unsigned int l, unsigned int m, T t) {
        using U = fp_promote_t<T>;

        return t;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_LEGENDRE_Y_H
