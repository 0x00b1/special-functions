#ifndef SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H
#define SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    zernike_polynomial_z(unsigned int n, int m, T rho, U phi) {
        using type = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::zernike<type>(n, m, rho, phi);
    }
}

#endif // SPECIAL_FUNCTIONS_ZERNIKE_POLYNOMIAL_Z_H
