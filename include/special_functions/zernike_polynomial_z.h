#ifndef SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H
#define SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/zernike_polynomial_z.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    zernike_polynomial_z(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::zernike_polynomial_z<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H
