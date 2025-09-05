#ifndef SPECIAL_FUNCTIONS_INCOMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
#define SPECIAL_FUNCTIONS_INCOMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    incomplete_legendre_elliptic_integral_d(T k, U p) {
        using V = fp_promote_t<T, U>;

        return detail::incomplete_legendre_elliptic_integral_d<V>(k, p);
    }
}

#endif // SPECIAL_FUNCTIONS_INCOMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
