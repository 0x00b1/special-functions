#ifndef SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
#define SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/hyperbolic_cosine_integral_chi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hyperbolic_cosine_integral_chi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::hyperbolic_cosine_integral_chi<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HYPERBOLIC_COSINE_INTEGRAL_CHI_H
