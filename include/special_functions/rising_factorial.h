#ifndef SPECIAL_FUNCTIONS_RISING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_RISING_FACTORIAL_H

#include <special_functions/detail/rising_factorial.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    rising_factorial(T a, U n) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::rising_factorial<V>(a, n);
    }
}

#endif // SPECIAL_FUNCTIONS_RISING_FACTORIAL_H
