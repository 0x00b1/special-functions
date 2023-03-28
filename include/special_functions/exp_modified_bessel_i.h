#ifndef SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_I_H
#define SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_I_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    exp_modified_bessel_i(T n, U x) {
        using type = special_functions::fp_promote_t<T, U>;

        // return special_functions::detail::cyl_bessel_i_scaled<type>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_EXP_MODIFIED_BESSEL_I_H
