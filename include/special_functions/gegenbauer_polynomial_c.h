#ifndef SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H
#define SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/gegenbauer_polynomial_c.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    gegenbauer_polynomial_c(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::gegenbauer_polynomial_c<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_GEGENBAUER_POLYNOMIAL_C_H
