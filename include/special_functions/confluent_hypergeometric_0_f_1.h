#ifndef SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H
#define SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H


#include <complex>


namespace special_functions {
    template<typename Tpc, typename Tp>
    fp_promote_t<Tpc, Tp>
    confluent_hypergeometric_0_f_1(Tpc c, Tp x) {
        typedef fp_promote_t<Tpc, Tp> type;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H
