#ifndef SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
#define SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H

namespace special_functions {
    template<typename T, typename U, typename V>
    inline std::complex<special_functions::fp_promote_t<T, U, V>>
    mittag_leffler_e(U a, V b, const std::complex<T> &z) {
        using W = special_functions::fp_promote_t<T, U, V>;

        return special_functions::detail::mittag_leffler<W>(a, b, z);
    }
}

#endif // SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
