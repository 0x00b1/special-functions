#ifndef SPECIAL_FUNCTIONS_SIN_PI_H
#define SPECIAL_FUNCTIONS_SIN_PI_H

#include <special_functions/detail/sin_pi.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sin_pi(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::sin_pi<U>(x);
    }

    template<typename T>
    inline std::complex<T>
    sin_pi(std::complex<T> z) {
        return special_functions::detail::sin_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SIN_PI_H
