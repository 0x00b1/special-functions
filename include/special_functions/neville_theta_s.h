#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_S_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_S_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/neville_theta_s.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    neville_theta_s(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::neville_theta_s<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_S_H
