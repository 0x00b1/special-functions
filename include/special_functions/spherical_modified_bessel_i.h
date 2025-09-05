#ifndef SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_I_H
#define SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_I_H

#include <special_functions/detail/spherical_modified_bessel_i.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_modified_bessel_i(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_I_H
