#ifndef SPECIAL_FUNCTIONS_PRIME_NUMBER_H
#define SPECIAL_FUNCTIONS_PRIME_NUMBER_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/prime_number.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    prime_number(T x) {
        using result_type = fp_promote_t<T>;
        return detail::prime_number<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_PRIME_NUMBER_H
