#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H

namespace special_functions {
    template<typename T, typename U, typename V>
    inline special_functions::fp_promote_t<T, U, V>
    incomplete_elliptic_integral_pi(T k, U nu, V phi) {
        using W = special_functions::fp_promote_t<T, U, V>;

        // return emsr::detail::ellint_3<W>(k, nu, phi);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H
