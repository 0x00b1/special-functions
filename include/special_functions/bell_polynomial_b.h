#ifndef SPECIAL_FUNCTIONS_BELL_POLYNOMIAL_B_H
#define SPECIAL_FUNCTIONS_BELL_POLYNOMIAL_B_H

#include <special_functions/detail/bell_polynomial_b.h>

namespace special_functions {
    template<typename T, typename U>
    U
    bell_polynomial_b(unsigned int n, U x) {
        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_BELL_POLYNOMIAL_B_H
