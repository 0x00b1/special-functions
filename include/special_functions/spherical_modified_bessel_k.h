#ifndef SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/spherical_modified_bessel_k.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_modified_bessel_k(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H
