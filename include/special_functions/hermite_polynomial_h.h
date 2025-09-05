#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/hermite_polynomial_h.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hermite_polynomial_h(T x) {
        using result_type = fp_promote_t<T>;
        return detail::hermite_polynomial_h<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H
