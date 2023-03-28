#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H

namespace special_functions {
    template<typename Tp, typename Tk, typename Ta, typename Tb>
    inline special_functions::fp_promote_t<Tp, Tk, Ta, Tb>
    bulirsch_elliptic_integral_el2(Tp x, Tk k_c, Ta a, Tb b) {
        using type = special_functions::fp_promote_t<Tp, Tk, Ta, Tb>;

        return special_functions::detail::bulirsch_elliptic_integral_el2<type>(x, k_c, a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL2_H
