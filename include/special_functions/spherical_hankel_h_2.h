#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H

#include <special_functions/detail/spherical_hankel_h_2.h>

namespace special_functions {
    template<typename T>
    std::complex<fp_promote_t<T>>
    spherical_hankel_h_2(unsigned int n, T z) {
        using U = fp_promote_t<T>;

        return z;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H
