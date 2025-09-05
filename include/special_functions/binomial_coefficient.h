#ifndef SPECIAL_FUNCTIONS_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_BINOMIAL_COEFFICIENT_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    binomial_coefficient(unsigned int n, unsigned int k) {
        using U = fp_promote_t<T>;

        return detail::binomial_coefficient<U>(n, k);
    }
}

#endif // SPECIAL_FUNCTIONS_BINOMIAL_COEFFICIENT_H
