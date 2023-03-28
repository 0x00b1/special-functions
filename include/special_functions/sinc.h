#ifndef SPECIAL_FUNCTIONS_SINC_H
#define SPECIAL_FUNCTIONS_SINC_H

#include <special_functions/detail/sinc.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinc(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::sinc<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINC_H
