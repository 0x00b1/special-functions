#ifndef SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
#define SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H

#include <special_functions/detail/gauss_hypergeometric_2_f_1.h>

namespace special_functions {
    template<typename T, typename U, typename V, typename W>
    inline typename special_functions::fp_promote_t<T, U, V, W>
    gauss_hypergeometric_2_f_1(T a, U b, V c, W x) {
        using X = special_functions::fp_promote_t<T, U, V, W>;

        return special_functions::detail::gauss_hypergeometric_2_f_1<X>(a, b, c, x);
    }
}

#endif // SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
