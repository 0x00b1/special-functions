#ifndef SPECIAL_FUNCTIONS_DETAIL_BESSEL_T_H
#define SPECIAL_FUNCTIONS_DETAIL_BESSEL_T_H

namespace special_functions::detail {
    template<typename Tnu, typename Tx, typename Tp>
    struct cyl_bessel_t
    {
        /// The real order of the cylindrical Bessel functions.
        Tnu nu_arg;

        /// The argument of the cylindrical Bessel functions.
        Tx x_arg;

        /// The value of the Bessel function of the first kind.
        Tp J_value;

        /// The derivative of the Bessel function of the first kind.
        Tp J_deriv;

        /// The value of the Bessel function of the second kind.
        Tp N_value;

        /// The derivative of the Bessel function of the second kind.
        Tp N_deriv;

        /return the Wronskian of this cylindrical Bessel function state.
        constexpr Tp
        Wronskian() const noexcept
        { return J_value * N_deriv - N_value * J_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BESSEL_T_H
