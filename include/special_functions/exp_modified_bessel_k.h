#ifndef SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_K_H

#include <special_functions/detail/

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    exp_modified_bessel_k(T n, U x) {
        using type = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::cyl_bessel_k_scaled<type>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_K_H
