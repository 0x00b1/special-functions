#ifndef SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_EI_H
#define SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_EI_H

#include <special_functions/detail/exponential_integral_ei.h>
#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    exponential_integral_ei(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::exponential_integral_ei<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_EI_H
