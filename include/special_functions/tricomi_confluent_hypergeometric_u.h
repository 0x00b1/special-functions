#ifndef SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H
#define SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/tricomi_confluent_hypergeometric_u.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    tricomi_confluent_hypergeometric_u(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::tricomi_confluent_hypergeometric_u<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H
