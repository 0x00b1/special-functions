#ifndef SPECIAL_FUNCTIONS_FRESNEL_COSINE_INTEGRAL_C_H
#define SPECIAL_FUNCTIONS_FRESNEL_COSINE_INTEGRAL_C_H

#include <special_functions/detail/fresnel_cosine_integral_c.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    fresnel_cosine_integral_c(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return std::real(special_functions::detail::fresnel<type>(x));
    }
}

#endif // SPECIAL_FUNCTIONS_FRESNEL_COSINE_INTEGRAL_C_H
