#ifndef SPECIAL_FUNCTIONS_BESSEL_Y_H
#define SPECIAL_FUNCTIONS_BESSEL_Y_H

namespace special_functions {
    template<typename T, typename U>
    inline special_functions::fp_promote_t<T, U>
    bessel_y(T n, U x) {
        using type = special_functions::fp_promote_t<T, U>;

        // return detail::cyl_neumann_n<type>(n, x);
    }
}

#endif // SPECIAL_FUNCTIONS_BESSEL_Y_H
