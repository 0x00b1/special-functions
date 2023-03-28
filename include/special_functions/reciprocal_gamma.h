#ifndef SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H
#define SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H

#include <special_functions/detail/reciprocal_gamma.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    reciprocal_gamma(T a) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::reciprocal_gamma<U>(a);
    }
}

#endif // SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H
