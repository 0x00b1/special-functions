#ifndef SPECIAL_FUNCTIONS_EULER_NUMBER_H
#define SPECIAL_FUNCTIONS_EULER_NUMBER_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/euler_number.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    euler_number(T x) {
        using result_type = fp_promote_t<T>;
        return detail::euler_number<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_EULER_NUMBER_H
