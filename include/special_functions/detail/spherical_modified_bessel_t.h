#ifndef SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_MODIFIED_BESSEL_T_H
#define SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_MODIFIED_BESSEL_T_H

namespace detail {
    template<typename Tn, typename Tx, typename Tp>
    struct sph_mod_bessel_t
    {
        /// The integral order of the modified spherical Bessel functions.
        Tn n_arg;

        /// The argument of the modified spherical Bessel functions.
        Tx x_arg;

        /// The value of the modified spherical Bessel function
        /// of the first kind.
        Tp i_value;

        /// The derivative of the modified spherical Bessel function
        /// of the first kind.
        Tp i_deriv;

        /// The value of the modified spherical Bessel function
        /// of the second kind.
        Tp k_value;

        /// The derivative of the modified spherical Bessel function
        /// of the second kind.
        Tp k_deriv;

        /return the Wronskian of this modified cylindrical Bessel function
        /// state.
        constexpr Tp
        Wronskian() const noexcept
        { return i_value * k_deriv - k_value * i_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_MODIFIED_BESSEL_T_H
