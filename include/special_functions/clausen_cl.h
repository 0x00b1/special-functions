#ifndef SPECIAL_FUNCTIONS_CLAUSEN_CL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_CL_H

#include <special_functions/detail/clausen_cl.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    clausen_cl(unsigned int m, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::clausen_cl<type>(m, x);
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_CL_H
