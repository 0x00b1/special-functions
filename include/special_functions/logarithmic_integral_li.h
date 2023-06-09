#ifndef SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
#define SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H

#include <special_functions/detail/logarithmic_integral_li.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    logarithmic_integral_li(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::logarithmic_integral_li<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
