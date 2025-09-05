#ifndef SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H
#define SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/bose_einstein_integral_g.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    bose_einstein_integral_g(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::bose_einstein_integral_g<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_BOSE_EINSTEIN_INTEGRAL_G_H
