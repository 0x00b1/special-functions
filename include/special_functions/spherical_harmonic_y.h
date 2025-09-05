#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H

#include <special_functions/detail/spherical_harmonic_y.h>

namespace special_functions {
    template<typename T, typename U>
    std::complex<fp_promote_t<T, U>>
    spherical_harmonic_y(unsigned int l, int m, T t, U p) {
        using V = fp_promote_t<T, U>;

        return detail::sph_harmonic<V>(l, m, t, p);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H
