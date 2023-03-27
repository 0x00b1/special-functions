#ifndef SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
#define SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    logarithmic_integral_li(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::logint<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
