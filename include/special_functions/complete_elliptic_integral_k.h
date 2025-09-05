#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    complete_elliptic_integral_k(T k) {
        using U = fp_promote_t<T>;

        return detail::complete_elliptic_integral_k<U>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H
