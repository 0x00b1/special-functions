#ifndef SPECIAL_FUNCTIONS_BETA_H
#define SPECIAL_FUNCTIONS_BETA_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    beta(T a, U b) {
        using type = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::beta<type>(a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BETA_H
