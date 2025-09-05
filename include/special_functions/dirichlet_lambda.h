#ifndef SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/dirichlet_lambda.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    dirichlet_lambda(T x) {
        using result_type = fp_promote_t<T>;
        return detail::dirichlet_lambda<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H
