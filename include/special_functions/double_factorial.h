#ifndef SPECIAL_FUNCTIONS_DOUBLE_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DOUBLE_FACTORIAL_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/double_factorial.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    double_factorial(int n) {
        using U = fp_promote_t<T>;

        return detail::double_factorial<U>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_DOUBLE_FACTORIAL_H
