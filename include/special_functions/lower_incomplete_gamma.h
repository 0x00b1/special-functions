#ifndef SPECIAL_FUNCTIONS_LOWER_INCOMPLETE_GAMMA_H
#define SPECIAL_FUNCTIONS_LOWER_INCOMPLETE_GAMMA_H

#include <special_functions/detail/lower_incomplete_gamma.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    lower_incomplete_gamma(T a, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::lower_incomplete_gamma<V>(a, x);
    }
}

#endif // SPECIAL_FUNCTIONS_LOWER_INCOMPLETE_GAMMA_H
