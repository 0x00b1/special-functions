#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H

#include <special_functions/detail/spherical_hankel_h_2.h>

namespace special_functions {
    template<typename T>
    inline std::complex<special_functions::fp_promote_t<T>>
    spherical_hankel_h_2(unsigned int n, T z) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::sph_hankel_2<type>(n, z);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_2_H
