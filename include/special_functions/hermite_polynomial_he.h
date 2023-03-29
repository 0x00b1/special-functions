#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H

#include <special_functions/detail/hermite_polynomial_he.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    hermite_polynomial_he(unsigned int n, T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::hermite_polynomial_he<U>(n, x).He_n;
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
