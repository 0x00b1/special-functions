#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H

#include <special_functions/detail/spherical_hankel_h_1.h>

namespace special_functions {
    template<typename T>
    std::complex<fp_promote_t<T>>
    spherical_hankel_h_1(unsigned int n, T z) {
        using U = fp_promote_t<T>;

        return detail::sph_hankel_1<U>(n, z);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H
