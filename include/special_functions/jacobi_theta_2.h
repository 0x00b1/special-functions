#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_2_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_2_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    jacobi_theta_2(T q, U x) {
        using V = fp_promote_t<T, U>;

        return detail::jacobi_theta_2<V>(q, x);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_2_H
