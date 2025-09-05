#ifndef SPECIAL_FUNCTIONS_RIEMANN_ZETA_H
#define SPECIAL_FUNCTIONS_RIEMANN_ZETA_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    riemann_zeta(T s) {
        using U = fp_promote_t<T>;

        return detail::riemann_zeta<U>(s);
    }
}

#endif // SPECIAL_FUNCTIONS_RIEMANN_ZETA_H
