#ifndef SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H
#define SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    harmonic_number(unsigned int n) {
        using U = fp_promote_t<T>;

        return detail::harmonic_number<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H
