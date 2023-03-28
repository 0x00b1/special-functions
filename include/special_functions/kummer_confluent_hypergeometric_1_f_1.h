#ifndef SPECIAL_FUNCTIONS_KUMMER_CONFLUENT_HYPERGEOMETRIC_1_F_1_H
#define SPECIAL_FUNCTIONS_KUMMER_CONFLUENT_HYPERGEOMETRIC_1_F_1_H

#include <special_functions/detail/kummer_confluent_hypergeometric_1_f_1.h>

namespace special_functions {
    template<typename Tpa, typename Tpc, typename Tp>
    inline special_functions::fp_promote_t<Tpa, Tpc, Tp>
    kummer_confluent_hypergeometric_1_f_1(Tpa a, Tpc c, Tp x) {
        using type = special_functions::fp_promote_t<Tpa, Tpc, Tp>;
        return special_functions::detail::kummer_confluent_hypergeometric_1_f_1<type>(a, c, x);
    }
}

#endif // SPECIAL_FUNCTIONS_KUMMER_CONFLUENT_HYPERGEOMETRIC_1_F_1_H
