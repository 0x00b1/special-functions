#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/spherical_harmonic_y.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    spherical_harmonic_y(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::spherical_harmonic_y<result_type>(x, y, z);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    spherical_harmonic_y(const std::complex<T>& z) {
        return detail::spherical_harmonic_y(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HARMONIC_Y_H
