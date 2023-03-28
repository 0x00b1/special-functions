#ifndef SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H
#define SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H

#include <special_functions/detail/tricomi_confluent_hypergeometric_u.h>

namespace special_functions {
    template<typename Tpa, typename Tpc, typename Tp>
    inline special_functions::fp_promote_t<Tpa, Tpc, Tp>
    tricomi_confluent_hypergeometric_u(Tpa a, Tpc c, Tp x) {
        using type = special_functions::fp_promote_t<Tpa, Tpc, Tp>;
        return special_functions::detail::tricomi_confluent_hypergeometric_u<type>(a, c, x);
    }
}

#endif // SPECIAL_FUNCTIONS_TRICOMI_CONFLUENT_HYPERGEOMETRIC_U_H
