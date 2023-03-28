#ifndef SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    spherical_modified_bessel_k(unsigned int n, T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::spherical_modified_bessel_k<U>(n, x).k_value;
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H
