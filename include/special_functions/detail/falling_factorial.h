#ifndef SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H

namespace special_functions::detail {
    template<typename T>
    T
    falling_factorial(T a, int n) {
        return 0;
    }

    template<typename T>
    T
    falling_factorial(T a, T n) {
        return 0;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_FALLING_FACTORIAL_H
