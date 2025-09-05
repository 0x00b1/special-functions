#ifndef SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/dirichlet_lambda.h>

namespace special_functions {
    template<typename T>
    T
    dirichlet_lambda(T s) {
        using U = fp_promote_t<T>;

        return s;
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H
