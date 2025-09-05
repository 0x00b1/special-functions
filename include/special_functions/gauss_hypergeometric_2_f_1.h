#ifndef SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
#define SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/gauss_hypergeometric_2_f_1.h>

namespace special_functions {
    template<typename T, typename U, typename V, typename W>
    fp_promote_t<T, U, V, W>
    gauss_hypergeometric_2_f_1(T a, U b, V c, W x) {
        using X = fp_promote_t<T, U, V, W>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
