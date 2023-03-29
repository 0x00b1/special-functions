#ifndef SPECIAL_FUNCTIONS_RADIAL_POLYNOMIAL_R_H
#define SPECIAL_FUNCTIONS_RADIAL_POLYNOMIAL_R_H

#include <special_functions/detail/radial_polynomial_r.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    radial_polynomial_r(unsigned int n, unsigned int m, T r) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::radial_jacobi<type>(n, m, r);
    }
}

#endif // SPECIAL_FUNCTIONS_RADIAL_POLYNOMIAL_R_H
