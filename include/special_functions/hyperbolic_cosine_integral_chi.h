#ifndef SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
#define SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H

#include <special_functions/detail/

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    hyperbolic_cosine_integral_chi(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::coshint<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
