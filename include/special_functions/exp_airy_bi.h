#ifndef SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
#define SPECIAL_FUNCTIONS_EXP_AIRY_BI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    exp_airy_bi(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_AIRY_BI_H
