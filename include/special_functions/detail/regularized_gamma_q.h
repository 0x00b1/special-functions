#ifndef SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_Q_H
#define SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_Q_H

namespace special_functions::detail {
    template<typename T>
    T
    regularized_gamma_q(T a, T x) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        if (std::isnan(a) || std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        auto is_integer_a = special_functions::fp_is_integer(a);

        if (is_integer_a && is_integer_a() <= 0) {
            throw std::domain_error("gamma_q: non-positive integer argument a");
        }

        if (std::real(x) < std::real(a + V{1})) {
            return U{1} - gamma_series(a, x).first;
        }

        return gamma_cont_frac(a, x).first;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_Q_H
