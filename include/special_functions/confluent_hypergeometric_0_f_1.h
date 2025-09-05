#ifndef SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H
#define SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H

#include <special_functions/detail/confluent_hypergeometric_0_f_1.h>

namespace special_functions {
    template<typename Tpc, typename Tp>
    typename fp_promote_t<Tpc, Tp>
    confluent_hypergeometric_0_f_1(Tpc c, Tp x) {
        typedef typename fp_promote_t<Tpc, Tp> type;

        return detail::confluent_hypergeometric_0_f_1<type>(c, x);
    }
}

#endif // SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H
