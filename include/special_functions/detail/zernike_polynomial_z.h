#ifndef SPECIAL_FUNCTIONS_DETAIL_ZERNIKE_POLYNOMIAL_Z_H
#define SPECIAL_FUNCTIONS_DETAIL_ZERNIKE_POLYNOMIAL_Z_H

#include "radial_polynomial_r.h"

namespace detail {
    template<typename T>
    special_functions::fp_promote_t<T>
    zernike_polynomial_z(unsigned int n, int m, T r, T p) {
        if (std::isnan(r) || std::isnan(p)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        return radial_polynomial_r(n, std::abs(m), r) * (m >= 0 ? std::cos(m * p) : std::sin(m * p));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_ZERNIKE_POLYNOMIAL_Z_H
