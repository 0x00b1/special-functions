#ifndef SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
#define SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/sine_integral_si.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sine_integral_si(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
