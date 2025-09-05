#ifndef SPECIAL_FUNCTIONS_COSH_PI_H
#define SPECIAL_FUNCTIONS_COSH_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/cosh_pi.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    cosh_pi(T x) {
        using U = fp_promote_t<T>;

        return detail::cosh_pi<U>(x);
    }

    template<typename T>
    std::complex<T>
    cosh_pi(std::complex<T> z) {
        return detail::cosh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_COSH_PI_H
