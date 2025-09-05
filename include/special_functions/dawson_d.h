#ifndef SPECIAL_FUNCTIONS_DAWSON_D_H
#define SPECIAL_FUNCTIONS_DAWSON_D_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/dawson_d.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    dawson_d(T x) {
        using result_type = fp_promote_t<T>;
        return detail::dawson_d<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DAWSON_D_H
