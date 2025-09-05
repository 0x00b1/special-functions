#ifndef SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
#define SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/gauss_hypergeometric_2_f_1.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    gauss_hypergeometric_2_f_1(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::gauss_hypergeometric_2_f_1<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
