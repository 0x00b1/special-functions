#ifndef SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H
#define SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/reciprocal_gamma.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    reciprocal_gamma(T x) {
        using result_type = fp_promote_t<T>;
        return detail::reciprocal_gamma<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_RECIPROCAL_GAMMA_H
