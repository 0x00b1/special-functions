#ifndef SPECIAL_FUNCTIONS_DIGAMMA_H
#define SPECIAL_FUNCTIONS_DIGAMMA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/digamma.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    digamma(T x) {
        using result_type = fp_promote_t<T>;
        return detail::digamma<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DIGAMMA_H
