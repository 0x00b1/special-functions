#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H

#include <special_functions/detail/spherical_harmonic_y.h>

namespace special_functions {
    template<typename T, typename U>
    inline std::complex<special_functions::fp_promote_t<T, U>>
    spherical_harmonic_y(unsigned int l, int m, T t, U p) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::sph_harmonic<V>(l, m, t, p);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H
