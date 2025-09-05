#ifndef SPECIAL_FUNCTIONS_BETA_H
#define SPECIAL_FUNCTIONS_BETA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/beta.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    beta(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::beta<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_BETA_H
