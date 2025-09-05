#ifndef SPECIAL_FUNCTIONS_OWENS_T_H
#define SPECIAL_FUNCTIONS_OWENS_T_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/owens_t.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    owens_t(T x) {
        using result_type = fp_promote_t<T>;
        return detail::owens_t<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_OWENS_T_H
