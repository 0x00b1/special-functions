#ifndef SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_P_H
#define SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_P_H

#include <special_functions/detail/fp_type_util.h>
#include <special_functions/detail/associated_legendre_p.h>
#include <complex>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    associated_legendre_p(T x) {
        using result_type = fp_promote_t<T>;
        return detail::associated_legendre_p<result_type>(x);
    }
}

#endif // SPECIAL_FUNCTIONS_ASSOCIATED_LEGENDRE_P_H
