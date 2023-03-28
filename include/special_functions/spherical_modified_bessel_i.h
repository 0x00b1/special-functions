#ifndef SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_I_H
#define SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_I_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    spherical_modified_bessel_i(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::sph_bessel_ik<type>(n, x).i_value;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_I_H
