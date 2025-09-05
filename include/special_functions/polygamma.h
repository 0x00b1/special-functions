#ifndef SPECIAL_FUNCTIONS_POLYGAMMA_H
#define SPECIAL_FUNCTIONS_POLYGAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/polygamma.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    polygamma(T x) {
        using result_type = fp_promote_t<T>;
        return detail::polygamma<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_POLYGAMMA_H
