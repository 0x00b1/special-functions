#ifndef SPECIAL_FUNCTIONS_DIRICHLET_ETA_H
#define SPECIAL_FUNCTIONS_DIRICHLET_ETA_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/dirichlet_eta.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    dirichlet_eta(T x) {
        using result_type = fp_promote_t<T>;
        return detail::dirichlet_eta<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_DIRICHLET_ETA_H
