#ifndef SPECIAL_FUNCTIONS_SIN_PI_H
#define SPECIAL_FUNCTIONS_SIN_PI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sin_pi(T x) {
        using U = fp_promote_t<T>;

        return detail::sin_pi<U>(x);
    }

    template<typename T>
    std::complex<T>
    sin_pi(std::complex<T> z) {
        return detail::sin_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_SIN_PI_H
