#ifndef SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
#define SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    logarithmic_integral_li(T x) {
        using U = fp_promote_t<T>;

        return detail::logarithmic_integral_li<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_LOGARITHMIC_INTEGRAL_LI_H
