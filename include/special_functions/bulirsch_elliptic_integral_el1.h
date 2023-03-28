#ifndef SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
#define SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H

namespace special_functions {
    template<typename Tp, typename Tk>
    inline special_functions::fp_promote_t<Tp, Tk>
    bulirsch_elliptic_integral_el1(Tp x, Tk k_c) {
        using type = special_functions::fp_promote_t<Tp, Tk>;

        return special_functions::detail::bulirsch_elliptic_integral_el1<type>(x, k_c);
    }

}

#endif // SPECIAL_FUNCTIONS_BULIRSCH_ELLIPTIC_INTEGRAL_EL1_H
