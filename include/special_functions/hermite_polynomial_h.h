#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H

#include <special_functions/detail/hermite_polynomial_h.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hermite_polynomial_h(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return detail::hermite_polynomial_h<U>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H
