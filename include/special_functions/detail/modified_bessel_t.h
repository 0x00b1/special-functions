#ifndef SPECIAL_FUNCTIONS_DETAIL_MODIFIED_BESSEL_T_H
#define SPECIAL_FUNCTIONS_DETAIL_MODIFIED_BESSEL_T_H

namespace special_functions::detail {
    template<typename Tnu, typename Tx, typename Tp>
    struct cyl_mod_bessel_t
    {
        /// The real order of the modified cylindrical Bessel functions.
        Tnu nu_arg;

        /// The argument of the modified cylindrical Bessel functions.
        Tx x_arg;

        /// The value of the modified cylindrical Bessel function
        /// of the first kind.
        Tp I_value;

        /// The derivative of the modified cylindrical Bessel function
        /// of the first kind.
        Tp I_deriv;

        /// The value of the modified cylindrical Bessel function
        /// of the second kind.
        Tp K_value;

        /// The derivative of the modified cylindrical Bessel function
        /// of the second kind.
        Tp K_deriv;

        /// Return the Wronskian of this modified cylindrical Bessel function
        /// state.
        constexpr Tp
        Wronskian() const noexcept
        { return I_value * K_deriv - K_value * I_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_MODIFIED_BESSEL_T_H
