#ifndef SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
#define SPECIAL_FUNCTIONS_EXP_AIRY_BI_H

#include <special_functions/detail/exp_airy_bi.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    exp_airy_bi(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::airy<type>(x, true).Bi_value;
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
