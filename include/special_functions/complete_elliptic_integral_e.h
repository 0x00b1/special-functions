#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_E_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/complete_elliptic_integral_e.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    complete_elliptic_integral_e(T x) {
        using result_type = fp_promote_t<T>;
        return detail::complete_elliptic_integral_e<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_E_H
