#ifndef SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H
#define SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H

#include <special_functions/detail/tricomi_confluent_hypergeometric_u.h>

namespace special_functions {
    template<typename T, typename U, typename V>
    inline special_functions::fp_promote_t<T, U, V>
    tricomi_confluent_hypergeometric_u(T a, U c, V x) {
        using W = special_functions::fp_promote_t<T, U, V>;

        return special_functions::detail::tricomi_confluent_hypergeometric_u<W>(a, c, x);
    }
}

#endif // SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H
