#ifndef SPECIAL_FUNCTIONS_BETA_H
#define SPECIAL_FUNCTIONS_BETA_H

#include <special_functions/detail/beta.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    beta(T a, U b) {
        using type = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::beta<type>(a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BETA_H
