#ifndef SPECIAL_FUNCTIONS_DETAIL_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_FACTORIAL_H

#include <array>

#include <special_functions/numbers.h>

namespace special_functions::detail {
    template<typename T>
    constexpr T
    factorial(unsigned int n) {
        if (n < special_functions::numbers::MAXIMUM_FACTORIAL_INDEX<T>) {
            return special_functions::numbers::FACTORIALS[n];
        }

        return std::numeric_limits<T>::infinity();
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_FACTORIAL_H
