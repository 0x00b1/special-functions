#ifndef SPECIAL_FUNCTIONS_LOWER_INCOMPLETE_GAMMA_H
#define SPECIAL_FUNCTIONS_LOWER_INCOMPLETE_GAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/lower_incomplete_gamma.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    lower_incomplete_gamma(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::lower_incomplete_gamma<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_LOWER_INCOMPLETE_GAMMA_H
