#ifndef SPECIAL_FUNCTIONS_DIRICHLET_ETA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_ETA_H

#include <special_functions/detail/dirichlet_eta.h>

namespace special_functions {
    template<typename T>
    inline T
    dirichlet_eta(T s) {
        using U = special_functions::fp_promote_t<T>;

        // return emsr::detail::dirichlet_eta<U>(s);
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_ETA_H
