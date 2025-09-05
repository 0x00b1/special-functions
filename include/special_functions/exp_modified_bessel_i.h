#ifndef SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_I_H
#define SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_I_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    exp_modified_bessel_i(T n, U x) {
        using type = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_I_H
