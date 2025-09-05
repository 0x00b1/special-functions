#ifndef SPECIAL_FUNCTIONS_TANH_PI_H
#define SPECIAL_FUNCTIONS_TANH_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/tanh_pi.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    tanh_pi(T x) {
        using U = fp_promote_t<T>;

        return detail::tanh_pi<U>(x);
    }

    template<typename T>
    std::complex<T>
    tanh_pi(std::complex<T> z) {
        return detail::tanh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_TANH_PI_H
