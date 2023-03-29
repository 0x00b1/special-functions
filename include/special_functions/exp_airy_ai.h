#ifndef SPECIAL_FUNCTIONS_EXP_AIRY_AI_H
#define SPECIAL_FUNCTIONS_EXP_AIRY_AI_H

#include <special_functions/detail/exp_airy_ai.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    exp_airy_ai(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::airy<type>(x, true).Ai_value;
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_AIRY_AI_H
