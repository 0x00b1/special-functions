#ifndef SPECIAL_FUNCTIONS_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_FALLING_FACTORIAL_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    falling_factorial(T a, U n) {
        using V = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::falling_factorial<V>(a, n);
    }
}

#endif // SPECIAL_FUNCTIONS_FALLING_FACTORIAL_H
