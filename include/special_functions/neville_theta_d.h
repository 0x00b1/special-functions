#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H

namespace special_functions {
    template<typename Tpk, typename Tp>
    inline special_functions::fp_promote_t<Tpk, Tp>
    theta_d(Tpk k, Tp x) {
        using type = special_functions::fp_promote_t<Tpk, Tp>;
        return special_functions::detail::theta_d<type>(k, x);
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_D_H
