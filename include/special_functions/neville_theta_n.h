#ifndef SPECIAL_FUNCTIONS_NEVILLE_THETA_N_H
#define SPECIAL_FUNCTIONS_NEVILLE_THETA_N_H

namespace special_functions {
    template<typename Tpk, typename Tp>
    inline special_functions::fp_promote_t<Tpk, Tp>
    theta_n(Tpk k, Tp x) {
        using type = special_functions::fp_promote_t<Tpk, Tp>;
        return special_functions::detail::theta_n<type>(k, x);
    }
}

#endif // SPECIAL_FUNCTIONS_NEVILLE_THETA_N_H
