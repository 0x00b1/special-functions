#ifndef SPECIAL_FUNCTIONS_CLAUSEN_SL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_SL_H

#include <special_functions/detail/clausen_sl.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    clausen_sl(unsigned int m, T x) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::clausen_sl<U>(m, x);
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_SL_H
