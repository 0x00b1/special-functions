#ifndef SPECIAL_FUNCTIONS_FRESNEL_SINE_INTEGRAL_S_H
#define SPECIAL_FUNCTIONS_FRESNEL_SINE_INTEGRAL_S_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    fresnel_sine_integral_s(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return std::imag(special_functions::detail::fresnel<type>(x));
    }
}

#endif // SPECIAL_FUNCTIONS_FRESNEL_SINE_INTEGRAL_S_H
