#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    hermite_polynomial_he(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::prob_hermite_recur<type>(n, x).He_n;
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_HE_H
