#ifndef SPECIAL_FUNCTIONS_SINC_H
#define SPECIAL_FUNCTIONS_SINC_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinc(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::sinc<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINC_H
