#ifndef SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H
#define SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/fermi_dirac_integral_f.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    fermi_dirac_integral_f(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::fermi_dirac_integral_f<result_type>(x, y, z);
    }
}

#endif // SPECIAL_FUNCTIONS_FERMI_DIRAC_INTEGRAL_F_H
