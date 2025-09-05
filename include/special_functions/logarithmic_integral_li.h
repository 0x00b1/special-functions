#ifndef SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
#define SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/logarithmic_integral_li.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    logarithmic_integral_li(T x) {
        using result_type = fp_promote_t<T>;
        return detail::logarithmic_integral_li<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
