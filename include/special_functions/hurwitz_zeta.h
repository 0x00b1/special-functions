#ifndef SPECIAL_FUNCTIONS_HURWITZ_ZETA_H
#define SPECIAL_FUNCTIONS_HURWITZ_ZETA_H

#include <special_functions/detail/hurwitz_zeta.h>

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<T, U>
    hurwitz_zeta(T s, U a) {
        using V = fp_promote_t<T, U>;

        return detail::hurwitz_zeta<V>(s, a);
    }
}

#endif // SPECIAL_FUNCTIONS_HURWITZ_ZETA_H
