#ifndef SPECIAL_FUNCTIONS_MODIFIED_BESSEL_I_H
#define SPECIAL_FUNCTIONS_MODIFIED_BESSEL_I_H

#include <special_functions/detail/modified_bessel_i.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    modified_bessel_i(T n, U x) {
        using V = fp_promote_t<T, U>;

        return detail::modified_bessel_i<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_MODIFIED_BESSEL_I_H
