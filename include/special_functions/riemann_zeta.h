#ifndef SPECIAL_FUNCTIONS_RIEMANN_ZETA_H
#define SPECIAL_FUNCTIONS_RIEMANN_ZETA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/riemann_zeta.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    riemann_zeta(T x) {
        using result_type = fp_promote_t<T>;
        return detail::riemann_zeta<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_RIEMANN_ZETA_H
