#ifndef SPECIAL_FUNCTIONS_SINC_PI_H
#define SPECIAL_FUNCTIONS_SINC_PI_H

#include <special_functions/detail/sinc_pi.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinc_pi(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::sinc_pi<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINC_PI_H
