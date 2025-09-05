#ifndef SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H
#define SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H

#include <special_functions/detail/cosine_integral_ci.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    cosine_integral_ci(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H
