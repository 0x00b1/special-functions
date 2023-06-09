#ifndef SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
#define SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H

#include <special_functions/detail/hyperbolic_cosine_integral_chi.h>
#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    hyperbolic_cosine_integral_chi(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::hyperbolic_cosine_integral_chi<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
