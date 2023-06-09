#ifndef SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H
#define SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H

#include <special_functions/detail/harmonic_number.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    harmonic_number(unsigned int n) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::harmonic_number<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_HARMONIC_NUMBER_H
