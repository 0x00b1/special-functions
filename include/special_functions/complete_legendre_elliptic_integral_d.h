#ifndef SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
#define SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H

#include <special_functions/detail/complete_legendre_elliptic_integral_d.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    complete_legendre_elliptic_integral_d(T k) {
        using type = fp_promote_t<T>;

        return detail::complete_legendre_elliptic_integral_d<type>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_LEGENDRE_ELLIPTIC_INTEGRAL_D_H
