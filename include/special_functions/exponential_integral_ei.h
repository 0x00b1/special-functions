#ifndef SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_EI_H
#define SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_EI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/exponential_integral_ei.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    exponential_integral_ei(T x) {
        using result_type = fp_promote_t<T>;
        return detail::exponential_integral_ei<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_EXPONENTIAL_INTEGRAL_EI_H
