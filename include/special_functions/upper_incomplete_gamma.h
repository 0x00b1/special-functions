#ifndef SPECIAL_FUNCTIONS_UPPER_INCOMPLETE_GAMMA_H
#define SPECIAL_FUNCTIONS_UPPER_INCOMPLETE_GAMMA_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    upper_incomplete_gamma(T a, U x) {
        using V = fp_promote_t<T, U>;

        return detail::upper_incomplete_gamma<V>(a, x);
    }
}

#endif // SPECIAL_FUNCTIONS_UPPER_INCOMPLETE_GAMMA_H
