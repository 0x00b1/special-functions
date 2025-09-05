#ifndef SPECIAL_FUNCTIONS_CLAUSEN_CL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_CL_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/clausen_cl.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    clausen_cl(T x) {
        using result_type = fp_promote_t<T>;
        return detail::clausen_cl<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_CL_H
