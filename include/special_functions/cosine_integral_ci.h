#ifndef SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H
#define SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H

#include <special_functions/detail/cosine_integral_ci.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    cosine_integral_ci(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::sincosint<type>(x).second;
    }
}

#endif // SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H
