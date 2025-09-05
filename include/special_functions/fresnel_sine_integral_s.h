#ifndef SPECIAL_FUNCTIONS_FRESNEL_SINE_INTEGRAL_S_H
#define SPECIAL_FUNCTIONS_FRESNEL_SINE_INTEGRAL_S_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/fresnel_sine_integral_s.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    fresnel_sine_integral_s(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_FRESNEL_SINE_INTEGRAL_S_H
