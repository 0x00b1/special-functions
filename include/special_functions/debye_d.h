#ifndef SPECIAL_FUNCTIONS_DEBYE_D_H
#define SPECIAL_FUNCTIONS_DEBYE_D_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/debye_d.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    debye_d(T x) {
        using result_type = fp_promote_t<T>;
        return detail::debye_d<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DEBYE_D_H
