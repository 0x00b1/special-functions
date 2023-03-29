#ifndef SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H

#include <special_functions/detail/dirichlet_lambda.h>

namespace special_functions {
    template<typename T>
    inline T
    dirichlet_lambda(T s) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::dirichlet_lambda<U>(s);
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_LAMBDA_H
