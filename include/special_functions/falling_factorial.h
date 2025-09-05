#ifndef SPECIAL_FUNCTIONS_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_FALLING_FACTORIAL_H


#include <complex>


namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    falling_factorial(T a, U n) {
        using V = fp_promote_t<T, U>;

        return detail::falling_factorial<V>(a, n);
    }
}

#endif // SPECIAL_FUNCTIONS_FALLING_FACTORIAL_H
