#ifndef SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
#define SPECIAL_FUNCTIONS_EXP_AIRY_BI_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    exp_airy_bi(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::airy<type>(x, true).Bi_value;
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
