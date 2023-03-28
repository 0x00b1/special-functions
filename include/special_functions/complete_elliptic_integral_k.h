#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    complete_elliptic_integral_k(T k) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::comp_ellint_1<type>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_K_H
