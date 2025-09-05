#ifndef SPECIAL_FUNCTIONS_TRIGAMMA_H
#define SPECIAL_FUNCTIONS_TRIGAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/trigamma.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    trigamma(T x) {
        using result_type = fp_promote_t<T>;
        return detail::trigamma<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_TRIGAMMA_H
