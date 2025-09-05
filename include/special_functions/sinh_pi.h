#ifndef SPECIAL_FUNCTIONS_SINH_PI_H
#define SPECIAL_FUNCTIONS_SINH_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/sinh_pi.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinh_pi(T x) {
        using U = fp_promote_t<T>;

        return detail::sinh_pi<U>(x);
    }

    template<typename T>
    std::complex<T>
    sinh_pi(std::complex<T> z) {
        return detail::sinh_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SINH_PI_H
