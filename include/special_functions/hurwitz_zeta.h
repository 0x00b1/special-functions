#ifndef SPECIAL_FUNCTIONS_HURWITZ_ZETA_H
#define SPECIAL_FUNCTIONS_HURWITZ_ZETA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/hurwitz_zeta.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    hurwitz_zeta(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::hurwitz_zeta<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_HURWITZ_ZETA_H
