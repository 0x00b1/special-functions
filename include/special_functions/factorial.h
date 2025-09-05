#ifndef SPECIAL_FUNCTIONS_FACTORIAL_H
#define SPECIAL_FUNCTIONS_FACTORIAL_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/factorial.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    factorial(T x) {
        using result_type = fp_promote_t<T>;
        return detail::factorial<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_FACTORIAL_H
