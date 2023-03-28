#ifndef SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H
#define SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    hyperbolic_sine_integral_shi(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::sinhint<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HYPERBOLIC_SINE_INTEGRAL_SHI_H
