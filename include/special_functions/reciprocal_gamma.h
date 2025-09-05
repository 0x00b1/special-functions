#ifndef SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H
#define SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    reciprocal_gamma(T a) {
        using U = fp_promote_t<T>;

        return detail::reciprocal_gamma<U>(a);
    }
}

#endif // SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H
