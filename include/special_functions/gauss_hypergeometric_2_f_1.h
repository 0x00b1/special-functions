#ifndef SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
#define SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H

#include <special_functions/detail/gauss_hypergeometric_2_f_1.h>

namespace special_functions {
    template<typename Tpa, typename Tpb, typename Tpc, typename Tp>
    inline typename special_functions::fp_promote_t<Tpa, Tpb, Tpc, Tp>
    gauss_hypergeometric_2_f_1(Tpa a, Tpb b, Tpc c, Tp x) {
        using type = special_functions::fp_promote_t<Tpa, Tpb, Tpc, Tp>;
        return special_functions::detail::gauss_hypergeometric_2_f_1<type>(a, b, c, x);
    }
}

#endif // SPECIAL_FUNCTIONS_GAUSS_HYPERGEOMETRIC_2_F_1_H
