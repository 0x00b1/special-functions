#ifndef SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/spherical_modified_bessel_k.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    spherical_modified_bessel_k(T x) {
        using result_type = fp_promote_t<T>;
        return detail::spherical_modified_bessel_k<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_MODIFIED_BESSEL_K_H
