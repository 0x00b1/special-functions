#ifndef SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
#define SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    complete_legendre_elliptic_integral_d(T k) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::comp_ellint_d<type>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
