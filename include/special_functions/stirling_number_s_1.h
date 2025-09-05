#ifndef SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H
#define SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/stirling_number_s_1.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    stirling_number_s_1(T x) {
        using result_type = fp_promote_t<T>;
        return detail::stirling_number_s_1<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_1_H
