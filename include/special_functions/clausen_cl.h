#ifndef SPECIAL_FUNCTIONS_CLAUSEN_CL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_CL_H

#include <special_functions/detail/clausen_cl.h>

namespace special_functions {
    template<typename Tp>
    inline special_functions::fp_promote_t<Tp>
    clausen_cl(unsigned int m, Tp x)
    {
        using type = special_functions::fp_promote_t<Tp>;
        return emsr::detail::clausen_cl<type>(m, x);
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_CL_H
