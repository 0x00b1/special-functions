#ifndef SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_J_H
#define SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_J_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_bessel_j(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_J_H
