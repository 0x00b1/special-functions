#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    neville_theta_d(T k, U x) {
        using V = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H
