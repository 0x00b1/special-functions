#ifndef SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
#define SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H

#include <special_functions/detail/sine_integral_si.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sine_integral_si(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::sincosint<type>(x).first;
    }
}

#endif // SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
