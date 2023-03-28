#ifndef SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_E_H
#define SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_E_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    complete_elliptic_integral_e(T k) {
        using U = special_functions::fp_promote_t<T>;

        return special_functions::detail::complete_elliptic_integral_e<U>(k);
    }
}

#endif // SPECIAL_FUNCTIONS_COMPLETE_ELLIPTIC_INTEGRAL_E_H
