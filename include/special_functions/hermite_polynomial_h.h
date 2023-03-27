#ifndef SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H
#define SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    hermite_polynomial_h(unsigned int n, T x) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::hermite<type>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_HERMITE_POLYNOMIAL_H_H
