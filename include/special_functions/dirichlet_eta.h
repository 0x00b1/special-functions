#ifndef SPECIAL_FUNCTIONS_DIRICHLET_ETA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_ETA_H

#include <special_functions/detail/fp_type_util.h>
#include <complex>
#include <special_functions/detail/dirichlet_eta.h>

namespace special_functions {
    template<typename T>
    T
    dirichlet_eta(T s) {
        using U = fp_promote_t<T>;

        return s;
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_ETA_H
