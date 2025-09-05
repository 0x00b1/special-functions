#ifndef SPECIAL_FUNCTIONS_EULERIAN_NUMBER_2_H
#define SPECIAL_FUNCTIONS_EULERIAN_NUMBER_2_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/eulerian_number_2.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    eulerian_number_2(T x) {
        using result_type = fp_promote_t<T>;
        return detail::eulerian_number_2<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_EULERIAN_NUMBER_2_H
