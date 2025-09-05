#ifndef SPECIAL_FUNCTIONS_EXP_AIRY_AI_H
#define SPECIAL_FUNCTIONS_EXP_AIRY_AI_H

#include <special_functions/detail/exp_airy_ai.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    exp_airy_ai(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_AIRY_AI_H
