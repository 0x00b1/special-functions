#ifndef SPECIAL_FUNCTIONS_FACTORIAL_H
#define SPECIAL_FUNCTIONS_FACTORIAL_H

#include <special_functions/detail/factorial.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    factorial(unsigned int n) {
        using U = fp_promote_t<T>;

        return detail::factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_FACTORIAL_H
