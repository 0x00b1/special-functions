#ifndef SPECIAL_FUNCTIONS_THETA_2_H
#define SPECIAL_FUNCTIONS_THETA_2_H

namespace special_functions {
    template<typename Tpnu, typename Tp>
    inline special_functions::fp_promote_t<Tpnu, Tp>
    theta_2(Tpnu nu, Tp x) {
        using type = special_functions::fp_promote_t<Tpnu, Tp>;
        return special_functions::detail::theta_2<type>(nu, x);
    }
}

#endif // SPECIAL_FUNCTIONS_THETA_2_H
