#ifndef SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_P_H
#define SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_P_H

namespace special_functions::detail {
    /**
     * @brief  Return the regularized lower incomplete gamma function.
     * The regularized lower incomplete gamma function is defined by
     * @f[
     *   P(a,x) = \frac{\gamma(a,x)}{\Gamma(a)}
     * @f]
     * where @f$ \Gamma(a) @f$ is the gamma function and
     * @f[
     *   \gamma(a,x) = \int_0^x e^{-t}t^{a-1}dt  (a > 0)
     * @f]
     * is the lower incomplete gamma function.
     */
    template<typename Tp>
    Tp
    gamma_p(Tp a, Tp x)
    {
        using Val = Tp;
        using Real = emsr::num_traits_t<Val>;
        const auto s_NaN = emsr::quiet_NaN(a);

        if (std::isnan(a) || std::isnan(x))
            return s_NaN;

        auto ia = emsr::fp_is_integer(a);
        if (ia && ia() <= 0)
            throw std::domain_error("gamma_p: non-positive integer argument a");
        else if (std::real(x) < std::real(a + Real{1}))
            return gamma_series(a, x).first;
        else
            return Val{1} - gamma_cont_frac(a, x).first;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_REGULARIZED_GAMMA_P_H
