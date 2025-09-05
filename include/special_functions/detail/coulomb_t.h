#ifndef SPECIAL_FUNCTIONS_DETAIL_COULOMB_T_H
#define SPECIAL_FUNCTIONS_DETAIL_COULOMB_T_H

namespace detail {
    template<typename Teta, typename Trho, typename Tp>
    struct coulomb_t
    {
        /// The nonnegative order of the Coulomb functions.
        unsigned int l;

        /// The real parameter of the Coulomb functions.
        Teta eta_arg;

        /// The argument of the Coulomb functions.
        Trho rho_arg;

        /// The value of the regular Coulomb function.
        Tp F_value;

        /// The derivative of the regular Coulomb function.
        Tp F_deriv;

        /// The value of the irregular Coulomb function.
        Tp G_value;

        /// The derivative of the irregular Coulomb function.
        Tp G_deriv;

        /return the Wronskian of this Coulomb function state.
        constexpr Tp
        Wronskian() const noexcept
        { return F_value * G_deriv - G_value * F_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COULOMB_T_H
