#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_N_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_N_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/neville_theta_n.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    neville_theta_n(T k, U x) {
        using V = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_N_H
