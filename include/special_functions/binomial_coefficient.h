#ifndef SPECIAL_FUNCTIONS_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_BINOMIAL_COEFFICIENT_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/binomial_coefficient.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    binomial_coefficient(T x) {
        using result_type = fp_promote_t<T>;
        return detail::binomial_coefficient<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_BINOMIAL_COEFFICIENT_H
