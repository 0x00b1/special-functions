#ifndef SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H
#define SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H

#include <special_functions/detail/zernike_polynomial_z.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    zernike_polynomial_z(unsigned int n, int m, T r, U p) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::zernike_polynomial_z<V>(n, m, r, p);
    }
}

#endif // SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H
