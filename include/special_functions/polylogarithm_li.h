#ifndef SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H
#define SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H

#include <special_functions/detail/polylogarithm_li.h>

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    polylogarithm_li(T s, U w) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::polylog<V>(s, w);
    }

    template<typename T, typename U>
    inline std::complex<special_functions::fp_promote_t<T, U>>
    polylogarithm_li(T s, std::complex<T> w) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::polylog<V>(s, w);
    }
}

#endif // SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H
