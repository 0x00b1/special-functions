#ifndef SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
#define SPECIAL_FUNCTIONS_EXP_AIRY_BI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/exp_airy_bi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    exp_airy_bi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::exp_airy_bi<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
