#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    hermite_polynomial_he(unsigned int n, T x) {
        using U = fp_promote_t<T>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
