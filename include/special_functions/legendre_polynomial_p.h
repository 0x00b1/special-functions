#ifndef SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    legendre_polynomial_p(unsigned int l, T x) {
        using U = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_LEGENDRE_POLYNOMIAL_P_H
