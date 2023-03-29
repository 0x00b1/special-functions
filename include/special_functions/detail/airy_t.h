#ifndef SPECIAL_FUNCTIONS_DETAIL_AIRY_T_H
#define SPECIAL_FUNCTIONS_DETAIL_AIRY_T_H

namespace special_functions::detail {
    template<typename Tx, typename Tp>
    struct airy_t
    {
        /// The argument of the Airy fuctions.
        Tx x_arg;

        /// The value of the Airy function Ai.
        Tp Ai_value;

        /// The derivative of the Airy function Ai.
        Tp Ai_deriv;

        /// The value of the Airy function Bi.
        Tp Bi_value;

        /// The derivative of the Airy function Bi.
        Tp Bi_deriv;

        /// Return the Wronskian of this Airy function state.
        constexpr Tp
        Wronskian() const noexcept
        { return Ai_value * Bi_deriv - Bi_value * Ai_deriv; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_AIRY_T_H
