#ifndef SPECIAL_FUNCTIONS_GAMMA_H
#define SPECIAL_FUNCTIONS_GAMMA_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    gamma(T a) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::gamma<U>(a);
    }

    template<typename T>
    inline std::complex<special_functions::fp_promote_t<T>>
    gamma(std::complex<T> a) {
        using U = std::complex<special_functions::fp_promote_t<T>>;

        // return emsr::detail::gamma<U>(a);
    }
}

#endif // SPECIAL_FUNCTIONS_GAMMA_H
