#ifndef SPECIAL_FUNCTIONS_TAN_PI_H
#define SPECIAL_FUNCTIONS_TAN_PI_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    tan_pi(T x) {
        using U = special_functions::fp_promote_t<T>;

        // return special_functions::detail::tan_pi<U>(x);
    }

    template<typename T>
    inline std::complex<T>
    tan_pi(std::complex<T> z) {
        // return special_functions::detail::tan_pi(z);
    }
}

#endif // SPECIAL_FUNCTIONS_TAN_PI_H
