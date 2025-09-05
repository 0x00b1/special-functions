#ifndef SPECIAL_FUNCTIONS_BELL_POLYNOMIAL_B_H
#define SPECIAL_FUNCTIONS_BELL_POLYNOMIAL_B_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/bell_polynomial_b.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    bell_polynomial_b(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::bell_polynomial_b<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_BELL_POLYNOMIAL_B_H
