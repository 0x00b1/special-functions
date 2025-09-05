#ifndef SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
#define SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H

#include <special_functions/detail/sine_integral_si.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sine_integral_si(T x) {
        using type = fp_promote_t<T>;

        return detail::sincosint<type>(x).first;
    }
}

#endif // SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
