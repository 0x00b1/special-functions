#ifndef SPECIAL_FUNCTIONS_SINHC_H
#define SPECIAL_FUNCTIONS_SINHC_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinhc(T x) {
        using U = fp_promote_t<T>;

        return detail::sinhc<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINHC_H
