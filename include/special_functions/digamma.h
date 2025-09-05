#ifndef SPECIAL_FUNCTIONS_DIGAMMA_H
#define SPECIAL_FUNCTIONS_DIGAMMA_H

#include <special_functions/detail/digamma.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    digamma(T x) {
        using U = fp_promote_t<T>;

        return detail::digamma<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DIGAMMA_H
