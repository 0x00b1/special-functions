#ifndef SPECIAL_FUNCTIONS_OWENS_T_H
#define SPECIAL_FUNCTIONS_OWENS_T_H

#include <special_functions/detail/owens_t.h>

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    owens_t(T h, T a) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::owens_t<type>(h, a);
    }
}

#endif // SPECIAL_FUNCTIONS_OWENS_T_H
