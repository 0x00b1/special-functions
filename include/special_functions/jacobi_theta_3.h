#ifndef SPECIAL_FUNCTIONS_JACOBI_THETA_3_H
#define SPECIAL_FUNCTIONS_JACOBI_THETA_3_H

namespace special_functions {
    template<typename Tpq, typename Tp>
    inline special_functions::fp_promote_t<Tpq, Tp>
    jacobi_theta_3(Tpq q, Tp x)
    {
        using type = special_functions::fp_promote_t<Tpq, Tp>;
        return special_functions::detail::jacobi_theta_3<type>(q, x);
    }

}

#endif // SPECIAL_FUNCTIONS_JACOBI_THETA_3_H
