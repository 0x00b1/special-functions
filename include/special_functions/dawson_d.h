#ifndef SPECIAL_FUNCTIONS_DAWSON_D_H
#define SPECIAL_FUNCTIONS_DAWSON_D_H

#include <special_functions/detail/dawson_d.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    dawson_d(T x) {
        using type = fp_promote_t<T>;

        return detail::dawson<type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DAWSON_D_H
