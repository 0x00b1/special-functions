#ifndef SPECIAL_FUNCTIONS_FACTORIAL_H
#define SPECIAL_FUNCTIONS_FACTORIAL_H

#include <special_functions/detail/factorial.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    factorial(unsigned int n) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_FACTORIAL_H
