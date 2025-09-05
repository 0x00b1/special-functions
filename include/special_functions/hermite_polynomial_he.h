#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/hermite_polynomial_he.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hermite_polynomial_he(T x) {
        using result_type = fp_promote_t<T>;
        return detail::hermite_polynomial_he<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
