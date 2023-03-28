#ifndef SPECIAL_FUNCTIONS_DEBYE_D_H
#define SPECIAL_FUNCTIONS_DEBYE_D_H

#include <special_functions/detail/debye_d.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    debye_d(unsigned int n, T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::debye_d<U>(n, x);
    }

}

#endif // SPECIAL_FUNCTIONS_DEBYE_D_H
