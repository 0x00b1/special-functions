#ifndef SPECIAL_FUNCTIONS_GAMMA_H
#define SPECIAL_FUNCTIONS_GAMMA_H

#include <special_functions/detail/gamma.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    gamma(T a) {
        using U = fp_promote_t<T>;

        return detail::gamma<U>(a);
    }

    template<typename T>
    std::complex<fp_promote_t<T>>
    gamma(std::complex<T> a) {
        using U = std::complex<fp_promote_t<T>>;

        return detail::gamma<U>(a);
    }
}

#endif // SPECIAL_FUNCTIONS_GAMMA_H
