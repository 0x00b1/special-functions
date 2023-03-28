#ifndef SPECIAL_FUNCTIONS_DAWSON_D_H
#define SPECIAL_FUNCTIONS_DAWSON_D_H

#include <special_functions/detail/

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    dawson_d(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::dawson<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DAWSON_D_H
