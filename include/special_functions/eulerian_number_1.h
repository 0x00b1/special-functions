#ifndef SPECIAL_FUNCTIONS_EULERIAN_NUMBER_1_H
#define SPECIAL_FUNCTIONS_EULERIAN_NUMBER_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/eulerian_number_1.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    eulerian_number_1(T x) {
        using result_type = fp_promote_t<T>;
        return detail::eulerian_number_1<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_EULERIAN_NUMBER_1_H
