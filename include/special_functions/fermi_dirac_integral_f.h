#ifndef SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H
#define SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/fermi_dirac_integral_f.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    fermi_dirac_integral_f(T s, U x) {
        using V = fp_promote_t<T, U>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H
