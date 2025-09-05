#ifndef SPECIAL_FUNCTIONS_SINC_H
#define SPECIAL_FUNCTIONS_SINC_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinc(T x) {
        using U = fp_promote_t<T>;

        return detail::sinc<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINC_H
