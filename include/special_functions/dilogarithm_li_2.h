#ifndef SPECIAL_FUNCTIONS_DILOGARITHM_LI_2_H
#define SPECIAL_FUNCTIONS_DILOGARITHM_LI_2_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    dilogarithm_li_2(T x) {
        using U = fp_promote_t<T>;

        return detail::dilogarithm_li_2<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DILOGARITHM_LI_2_H
