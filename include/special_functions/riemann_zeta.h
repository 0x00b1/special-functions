#ifndef SPECIAL_FUNCTIONS_RIEMANN_ZETA_H
#define SPECIAL_FUNCTIONS_RIEMANN_ZETA_H

#include <special_functions/detail/riemann_zeta.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    riemann_zeta(T s) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::riemann_zeta<U>(s);
    }
}

#endif // SPECIAL_FUNCTIONS_RIEMANN_ZETA_H
