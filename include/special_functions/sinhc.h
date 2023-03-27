#ifndef SPECIAL_FUNCTIONS_SINHC_H
#define SPECIAL_FUNCTIONS_SINHC_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinhc(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::sinhc<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINHC_H
