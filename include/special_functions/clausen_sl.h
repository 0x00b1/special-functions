#ifndef SPECIAL_FUNCTIONS_CLAUSEN_SL_H
#define SPECIAL_FUNCTIONS_CLAUSEN_SL_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/clausen_sl.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    clausen_sl(T x) {
        using result_type = fp_promote_t<T>;
        return detail::clausen_sl<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_CLAUSEN_SL_H
