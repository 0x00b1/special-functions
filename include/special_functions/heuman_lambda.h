#ifndef SPECIAL_FUNCTIONS_HEUMAN_LAMBDA_H
#define SPECIAL_FUNCTIONS_HEUMAN_LAMBDA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/heuman_lambda.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    heuman_lambda(T x) {
        using result_type = fp_promote_t<T>;
        return detail::heuman_lambda<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_HEUMAN_LAMBDA_H
