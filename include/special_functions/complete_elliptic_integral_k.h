#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H

#include <special_functions/detail/complete_elliptic_integral_k.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    complete_elliptic_integral_k(T k) {
        using type = special_functions::fp_promote_t<T>;

        return special_functions::detail::complete_elliptic_integral_k<type>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H
