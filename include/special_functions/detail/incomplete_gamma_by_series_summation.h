#ifndef SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_GAMMA_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_GAMMA_BY_SERIES_SUMMATION_H

namespace detail {
    template<typename Tp>
    std::pair<Tp, Tp>
    incomplete_gamma_by_series_summation(Tp a, Tp x) {
        using Val = Tp;
        using Real = num_traits_t<Val>;
        const auto s_eps = Real{3} * std::numeric_limits<Tp>::epsilon();
        unsigned int s_itmax = 10 * int(10 + std::sqrt(std::abs(a)));

        auto lngam = log_gamma(a);
        auto sign = log_gamma_sign(a);
        auto ia = fp_is_integer(a);

        if (ia && ia() <= 0)
            throw std::domain_error("gamma_series: non-positive integer argument a");
        else if (x == Real{0})
            return std::make_pair(Val{0}, lngam);
        else if (std::real(x) < Real{0})
            throw std::domain_error("gamma_series: negative argument x");
        else {
            auto aa = a;
            Val term, sum;
            term = sum = Tp{1} / a;
            for (unsigned int n = 1; n <= s_itmax; ++n) {
                aa += Real{1};
                term *= x / aa;
                sum += term;
                if (std::abs(term) < s_eps * std::abs(sum)) {
                    auto gamser = std::exp(-x + a * std::log(x) - lngam)
                                  * sum * sign;
                    return std::make_pair(gamser, lngam);
                }
            }
            throw std::logic_error("gamma_series: a too large, itmax too small in routine.");
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_GAMMA_BY_SERIES_SUMMATION_H
