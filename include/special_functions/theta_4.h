#ifndef SPECIAL_FUNCTIONS_THETA_4_H
#define SPECIAL_FUNCTIONS_THETA_4_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    theta_4(T n, U x) {
        using V = fp_promote_t<T, U>;

        return detail::theta_4<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_4_H
