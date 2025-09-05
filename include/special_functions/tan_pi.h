#ifndef SPECIAL_FUNCTIONS_TAN_PI_H
#define SPECIAL_FUNCTIONS_TAN_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/tan_pi.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    tan_pi(T x) {
        using U = fp_promote_t<T>;

        return detail::tan_pi<U>(x);
    }

    template<typename T>
    std::complex<T>
    tan_pi(std::complex<T> z) {
        return detail::tan_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_TAN_PI_H
