#ifndef SPECIAL_FUNCTIONS_DIGAMMA_H
#define SPECIAL_FUNCTIONS_DIGAMMA_H

#include <special_functions/detail/digamma.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    digamma(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::digamma<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DIGAMMA_H
