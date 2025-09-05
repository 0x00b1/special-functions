#ifndef SPECIAL_FUNCTIONS_DIRICHLET_BETA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_BETA_H

#include <special_functions/detail/dirichlet_beta.h>

namespace special_functions {
    template<typename T>
    T
    dirichlet_beta(T s) {
        using U = fp_promote_t<T>;

        return s;
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_BETA_H
