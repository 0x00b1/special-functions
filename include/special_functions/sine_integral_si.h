#ifndef SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
#define SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sine_integral_si(T x) {
        using type = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_SINE_INTEGRAL_SI_H
