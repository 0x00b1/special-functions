#ifndef SPECIAL_FUNCTIONS_TANH_PI_H
#define SPECIAL_FUNCTIONS_TANH_PI_H

#include <complex>

#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    tanh_pi(T x) {
        using U = special_functions::fp_promote_t<T>;

        // return special_functions::detail::tanh_pi<U>(x);
    }

    template<typename T>
    std::complex<T>
    tanh_pi(std::complex<T> z) {
        // return special_functions::detail::tanh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_TANH_PI_H
