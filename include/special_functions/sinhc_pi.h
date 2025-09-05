#ifndef SPECIAL_FUNCTIONS_SINHC_PI_H
#define SPECIAL_FUNCTIONS_SINHC_PI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinhc_pi(T x) {
        using U = fp_promote_t<T>;

        return detail::sinhc_pi<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINHC_PI_H
