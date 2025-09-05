#ifndef SPECIAL_FUNCTIONS_PERIODIC_ZETA_F_H
#define SPECIAL_FUNCTIONS_PERIODIC_ZETA_F_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/periodic_zeta_f.h>
#include <complex>

namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    periodic_zeta_f(T x, U y, V z) {
        using result_type = fp_promote_t<T, U, V>;
        return detail::periodic_zeta_f<result_type>(x, y, z);
    }
    
    template<typename T>
    std::complex<fp_promote_t<T>>
    periodic_zeta_f(const std::complex<T>& z) {
        return detail::periodic_zeta_f(z);
    }
}

#endif // SPECIAL_FUNCTIONS_PERIODIC_ZETA_F_H
