#ifndef SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H
#define SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H

#include <special_functions/detail/fermi_dirac_integral_f.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    fermi_dirac_integral_f(T s, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::fermi_dirac<V>(s, x);
    }
}

#endif // SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H
