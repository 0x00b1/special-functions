#ifndef SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/legendre_polynomial_p.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    legendre_polynomial_p(T x) {
        using result_type = fp_promote_t<T>;
        return detail::legendre_polynomial_p<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H
