#ifndef SPECIAL_FUNCTIONS_AIRY_AI_H
#define SPECIAL_FUNCTIONS_AIRY_AI_H

#include <special_functions/detail/airy_ai.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    airy_ai(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::airy<type>(x).Ai_value;
    }

    template<typename T>
    inline std::complex<special_functions::fp_promote_t<T>>
    airy_ai(const std::complex<T> &z) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::airy_ai<type>(z);
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_AI_H
