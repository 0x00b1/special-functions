#ifndef SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H
#define SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/confluent_hypergeometric_0_f_1.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    confluent_hypergeometric_0_f_1(T x) {
        using result_type = fp_promote_t<T>;
        return detail::confluent_hypergeometric_0_f_1<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_CONFLUENT_HYPERGEOMETRIC_0_F_1_H
