#ifndef SPECIAL_FUNCTIONS_RADIAL_POLYNOMIAL_R_H
#define SPECIAL_FUNCTIONS_RADIAL_POLYNOMIAL_R_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/radial_polynomial_r.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    radial_polynomial_r(unsigned int n, unsigned int m, T r) {
        using type = fp_promote_t<T>;

        return r;
    }
}

#endif // SPECIAL_FUNCTIONS_RADIAL_POLYNOMIAL_R_H
