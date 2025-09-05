#ifndef SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
#define SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H


#include <complex>


namespace special_functions {
    template<typename T, typename U, typename V>
    std::complex<fp_promote_t<T, U, V>>
    mittag_leffler_e(U a, V b, const std::complex<T> &z) {
        using W = fp_promote_t<T, U, V>;

        return z;
    }
}

#endif // SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
