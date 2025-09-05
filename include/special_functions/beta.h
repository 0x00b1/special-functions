#ifndef SPECIAL_FUNCTIONS_BETA_H
#define SPECIAL_FUNCTIONS_BETA_H

#include <special_functions/detail/beta.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    beta(T a, U b) {
        using V = fp_promote_t<T, U>;

        return detail::beta<V>(a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BETA_H
