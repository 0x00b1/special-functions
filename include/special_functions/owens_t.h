#ifndef SPECIAL_FUNCTIONS_OWENS_T_H
#define SPECIAL_FUNCTIONS_OWENS_T_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    owens_t(T h, T a) {
        using type = fp_promote_t<T>;

        return h;
    }
}

#endif // SPECIAL_FUNCTIONS_OWENS_T_H
