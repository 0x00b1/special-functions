#ifndef SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_Y_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    spherical_bessel_y(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return detail::sph_neumann<type>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_BESSEL_Y_H
