#ifndef SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_E_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/exponential_integral_e.h>
#include "special_functions/detail/fp_type_util.h"

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    exponential_integral_e(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return detail::exponential_integral_e<U>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_E_H
