#ifndef SPECIAL_FUNCTIONS_DILOGARITHM_LI_2_H
#define SPECIAL_FUNCTIONS_DILOGARITHM_LI_2_H

#include <special_functions/detail/dilogarithm_li_2.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    dilogarithm_li_2(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::dilogarithm_li_2<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DILOGARITHM_LI_2_H
