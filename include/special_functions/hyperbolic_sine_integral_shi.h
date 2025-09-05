#ifndef SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H
#define SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/hyperbolic_sine_integral_shi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hyperbolic_sine_integral_shi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::hyperbolic_sine_integral_shi<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H
