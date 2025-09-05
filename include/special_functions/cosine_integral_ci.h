#ifndef SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H
#define SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/cosine_integral_ci.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    cosine_integral_ci(T x) {
        using result_type = fp_promote_t<T>;
        return detail::cosine_integral_ci<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_COSINE_INTEGRAL_CI_H
