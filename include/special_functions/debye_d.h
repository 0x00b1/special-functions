#ifndef SPECIAL_FUNCTIONS_DEBYE_D_H
#define SPECIAL_FUNCTIONS_DEBYE_D_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/debye_d.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    debye_d(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return detail::debye_d<U>(n, x);
    }

}

#endif // SPECIAL_FUNCTIONS_DEBYE_D_H
