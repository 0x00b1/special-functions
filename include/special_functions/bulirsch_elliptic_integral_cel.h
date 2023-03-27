#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H

namespace special_functions {
    template<typename Tk, typename Tp, typename Ta, typename Tb>
    inline special_functions::fp_promote_t<Tk, Tp, Ta, Tb>
    bulirsch_elliptic_integral_cel(Tk k_c, Tp p, Ta a, Tb b) {
        using type = special_functions::fp_promote_t<Tk, Tp, Ta, Tb>;

        // return emsr::detail::ellint_cel<type>(k_c, p, a, b);
    }
}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_CEL_H
