#ifndef SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_HANKEL_T_H
#define SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_HANKEL_T_H

namespace special_functions::detail {
    /**
 * Tp pretty much has to be complex.
 */
    template<typename Tn, typename Tx, typename Tp>
    struct sph_hankel_t
    {
        /// The integral order of the spherical Hankel functions.
        Tn n_arg;

        /// The argument of the spherical Hankel functions.
        Tx x_arg;

        /// The velue of the spherical Hankel function of the first kind.
        Tp h1_value;

        /// The derivative of the spherical Hankel function of the first kind.
        Tp h1_deriv;

        /// The velue of the spherical Hankel function of the second kind.
        Tp h2_value;

        /// The derivative of the spherical Hankel function of the second kind.
        Tp h2_deriv;

        /return the Wronskian of this cylindrical Hankel function state.
        constexpr Tp
        Wronskian() const noexcept
        { return h1_value * h2_deriv - h2_value * h1_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_SPHERICAL_HANKEL_T_H
