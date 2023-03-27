#ifndef SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_P_H
#define SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_P_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    regularized_gamma_p(T a, U x) {
        using V = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::gamma_p<V>(a, x);
    }
}

#endif // SPECIAL_FUNCTIONS_REGULARIZED_GAMMA_P_H
