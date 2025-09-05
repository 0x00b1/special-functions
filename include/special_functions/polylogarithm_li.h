#ifndef SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H
#define SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/polylogarithm_li.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    polylogarithm_li(T s, U w) {
        using V = fp_promote_t<T, U>;

        return w;
    }

    template<typename T, typename U>
    std::complex<fp_promote_t<T, U>>
    polylogarithm_li(T s, std::complex<T> w) {
        using V = fp_promote_t<T, U>;

        return w;
    }
}

#endif // SPECIAL_FUNCTIONS_POLYLOGARITHM_LI_H
