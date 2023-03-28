#ifndef SPECIAL_FUNCTIONS_SINHC_H
#define SPECIAL_FUNCTIONS_SINHC_H

#include <special_functions/detail/sinhc.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    sinhc(T x) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::sinhc<U>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINHC_H
