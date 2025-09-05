#ifndef SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H
#define SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/associated_laguerre_polynomial_l.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    associated_laguerre_polynomial_l(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::associated_laguerre_polynomial_l<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_ASSOCIATED_LAGUERRE_POLYNOMIAL_L_H
