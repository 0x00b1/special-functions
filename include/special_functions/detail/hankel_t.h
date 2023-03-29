#ifndef SPECIAL_FUNCTIONS_DETAIL_HANKEL_T_H
#define SPECIAL_FUNCTIONS_DETAIL_HANKEL_T_H

namespace special_functions::detail {
    template<typename Tnu, typename Tx, typename Tp>
    struct cyl_hankel_t
    {
        /// The real order of the cylindrical Hankel functions.
        Tnu nu_arg;

        /// The argument of the modified Hankel functions.
        Tx x_arg;

        /// The value of the cylindrical Hankel function of the first kind.
        Tp H1_value;

        /// The derivative of the cylindrical Hankel function of the first kind.
        Tp H1_deriv;

        /// The value of the cylindrical Hankel function of the second kind.
        Tp H2_value;

        /// The derivative of the cylindrical Hankel function of the second kind.
        Tp H2_deriv;

        /// Return the Wronskian of this cylindrical Hankel function state.
        constexpr Tp
        Wronskian() const noexcept
        { return H1_value * H2_deriv - H2_value * H1_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HANKEL_T_H
