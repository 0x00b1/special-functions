#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H


#include <complex>


namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    incomplete_elliptic_integral_pi(T k, U n, V p) {
        using W = fp_promote_t<T, U, V>;

        return detail::incomplete_elliptic_integral_pi<W>(k, n, p);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_ELLIPTIC_INTEGRAL_PI_H
