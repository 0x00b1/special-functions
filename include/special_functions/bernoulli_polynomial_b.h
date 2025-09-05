#ifndef SPECIAL_FUNCTIONS_BERNOULLI_POLYNOMIAL_B_H
#define SPECIAL_FUNCTIONS_BERNOULLI_POLYNOMIAL_B_H

#include <special_functions/detail/bernoulli_polynomial_b.h>

namespace special_functions {
    template<typename T>
    T
    bernoulli_polynomial_b(unsigned int n, T x) {
        return detail::bernoulli_polynomial_b(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_BERNOULLI_POLYNOMIAL_B_H
