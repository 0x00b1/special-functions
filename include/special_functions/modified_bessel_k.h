#ifndef SPECIAL_FUNCTIONS_MODIFIED_BESSEL_K_H
#define SPECIAL_FUNCTIONS_MODIFIED_BESSEL_K_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    modified_bessel_k(T n, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        return special_functions::detail::modified_bessel_k<V>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_MODIFIED_BESSEL_K_H
