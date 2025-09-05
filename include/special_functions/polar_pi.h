#ifndef SPECIAL_FUNCTIONS_POLAR_PI_H
#define SPECIAL_FUNCTIONS_POLAR_PI_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/polar_pi.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    polar_pi(T x) {
        using result_type = fp_promote_t<T>;
        return detail::polar_pi<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_POLAR_PI_H
