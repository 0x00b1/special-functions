#ifndef SPECIAL_FUNCTIONS_SINH_PI_H
#define SPECIAL_FUNCTIONS_SINH_PI_H

#include <special_functions/detail/sinh_pi.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinh_pi(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::sinh_pi<U>(x);
    }

    template<typename T>
    inline std::complex<T>
    sinh_pi(std::complex<T> z) {
        return special_functions::detail::sinh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SINH_PI_H
