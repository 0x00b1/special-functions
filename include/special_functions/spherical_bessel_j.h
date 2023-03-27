#ifndef SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_J_H
#define SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_J_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    spherical_bessel_j(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return detail::sph_bessel<type>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_J_H
