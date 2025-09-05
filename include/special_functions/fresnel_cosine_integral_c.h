#ifndef SPECIAL_FUNCTIONS_FRESNEL_COSINE_INTEGRAL_C_H
#define SPECIAL_FUNCTIONS_FRESNEL_COSINE_INTEGRAL_C_H

#include <special_functions/detail/fresnel_cosine_integral_c.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    fresnel_cosine_integral_c(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_FRESNEL_COSINE_INTEGRAL_C_H
