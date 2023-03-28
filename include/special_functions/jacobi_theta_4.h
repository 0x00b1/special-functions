#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_4_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_4_H

namespace special_functions {
    template<typename Tpq, typename Tp>
    inline special_functions::fp_promote_t<Tpq, Tp>
    jacobi_theta_4(Tpq q, Tp x)
    {
        using type = special_functions::fp_promote_t<Tpq, Tp>;
        return special_functions::detail::jacobi_theta_4<type>(q, x);
    }
}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_4_H
