#ifndef SPECIAL_FUNCTIONS_SINC_PI_H
#define SPECIAL_FUNCTIONS_SINC_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/sinc_pi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    sinc_pi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::sinc_pi<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_SINC_PI_H
