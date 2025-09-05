#ifndef SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H
#define SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/stirling_number_s_2.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    stirling_number_s_2(T x) {
        using result_type = fp_promote_t<T>;
        return detail::stirling_number_s_2<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_STIRLING_NUMBER_S_2_H
