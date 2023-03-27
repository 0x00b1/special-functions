#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    incomplete_elliptic_integral_e(T k, U phi) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::ellint_2<V>(k, phi);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_E_H
