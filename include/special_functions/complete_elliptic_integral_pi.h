#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    complete_elliptic_integral_pi(T k, U n) {
        using V = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::comp_ellint_3<V>(k, n);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_PI_H
