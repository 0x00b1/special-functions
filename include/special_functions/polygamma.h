#ifndef SPECIAL_FUNCTIONS_POLYGAMMA_H
#define SPECIAL_FUNCTIONS_POLYGAMMA_H

#include <special_functions/detail/polygamma.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    polygamma(unsigned int m, T x) {
        using U = fp_promote_t<T>;

        return detail::polygamma<U>(m, x);
    }
}

#endif // SPECIAL_FUNCTIONS_POLYGAMMA_H
