#ifndef SPECIAL_FUNCTIONS_POLYGAMMA_H
#define SPECIAL_FUNCTIONS_POLYGAMMA_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    polygamma(unsigned int m, T x) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::polygamma<U>(m, x);
    }
}

#endif // SPECIAL_FUNCTIONS_POLYGAMMA_H
