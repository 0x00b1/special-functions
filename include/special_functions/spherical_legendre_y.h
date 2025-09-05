#ifndef SPECIAL_FUNCTIONS_SPHERICAL_LEGENDRE_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_LEGENDRE_Y_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/spherical_legendre_y.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_legendre_y(T x) {
        using result_type = fp_promote_t<T>;
        return detail::spherical_legendre_y<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_LEGENDRE_Y_H
