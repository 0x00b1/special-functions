#ifndef SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_BESSEL_T_H
#define SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_BESSEL_T_H

namespace detail {
    template<typename Tn, typename Tx, typename Tp>
    struct sph_bessel_t
    {
        /// The integral order of the spherical Bessel functions.
        Tn n_arg;

        /// The argument of the spherical Bessel functions.
        Tx x_arg;

        /// The value of the spherical Bessel function of the first kind.
        Tp j_value;

        /// The derivative of the spherical Bessel function of the first kind.
        Tp j_deriv;

        /// The value of the spherical Bessel function of the second kind.
        Tp n_value;

        /// The derivative of the spherical Bessel function of the second kind.
        Tp n_deriv;

        /return the Wronskian of this spherical Bessel function state.
        constexpr Tp
        Wronskian() const noexcept
        { return j_value * n_deriv - n_value * j_deriv; }
    };

}

#endif // SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_BESSEL_T_H
