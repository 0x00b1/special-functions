#ifndef SPECIAL_FUNCTIONS_CLAUSEN_CL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_CL_H

#include <special_functions/detail/clausen_cl.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    clausen_cl(unsigned int m, T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_CL_H
