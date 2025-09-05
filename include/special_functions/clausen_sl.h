#ifndef SPECIAL_FUNCTIONS_CLAUSEN_SL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_SL_H

#include <special_functions/detail/clausen_sl.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    clausen_sl(unsigned int m, T x) {
        using U = fp_promote_t<T>;

        return detail::clausen_sl<U>(m, x);
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_SL_H
