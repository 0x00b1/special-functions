#ifndef SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
#define SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H

namespace special_functions {
    template<typename T, typename U, typename V>
    inline std::complex<special_functions::fp_promote_t<T, U, V>>
    mittag_leffler_e(U alpha, V beta, const std::complex<T> &z) {
        using type = special_functions::fp_promote_t<T, U, V>;

        // return emsr::detail::mittag_leffler<type>(alpha, beta, z);
    }
}

#endif // SPECIAL_FUNCTIONS_MITTAG_LEFFLER_E_H
