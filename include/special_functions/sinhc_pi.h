#ifndef SPECIAL_FUNCTIONS_SINHC_PI_H
#define SPECIAL_FUNCTIONS_SINHC_PI_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinhc_pi(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::sinhc_pi<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINHC_PI_H
