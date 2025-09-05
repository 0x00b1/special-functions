#ifndef SPECIAL_FUNCTIONS_SINHC_H
#define SPECIAL_FUNCTIONS_SINHC_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/sinhc.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinhc(T x) {
        using result_type = fp_promote_t<T>;
        return detail::sinhc<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINHC_H
