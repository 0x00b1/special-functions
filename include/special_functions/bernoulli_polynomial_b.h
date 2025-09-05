#ifndef SPECIAL_FUNCTIONS_BERNOULLI_POLYNOMIAL_B_H
#define SPECIAL_FUNCTIONS_BERNOULLI_POLYNOMIAL_B_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/bernoulli_polynomial_b.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    bernoulli_polynomial_b(T x) {
        using result_type = fp_promote_t<T>;
        return detail::bernoulli_polynomial_b<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_BERNOULLI_POLYNOMIAL_B_H
