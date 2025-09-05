#ifndef SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_K_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/exp_modified_bessel_k.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    exp_modified_bessel_k(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::exp_modified_bessel_k<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_K_H
