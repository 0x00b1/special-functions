#ifndef SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H
#define SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hyperbolic_sine_integral_shi(T x) {
        using U = fp_promote_t<T>;

        return detail::hyperbolic_sine_integral_shi<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H
