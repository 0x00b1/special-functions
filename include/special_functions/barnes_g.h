#ifndef SPECIAL_FUNCTIONS_BARNES_G_H
#define SPECIAL_FUNCTIONS_BARNES_G_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/barnes_g.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    barnes_g(T x) {
        using result_type = fp_promote_t<T>;
        return detail::barnes_g<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_BARNES_G_H
