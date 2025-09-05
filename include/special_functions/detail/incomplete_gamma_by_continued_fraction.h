#ifndef SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_GAMMA_BY_CONTINUED_FRACTION_H
#define SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_GAMMA_BY_CONTINUED_FRACTION_H

namespace detail {
    template<typename Tp>
    std::pair<Tp, Tp>
    incomplete_gamma_by_continued_fraction(Tp a, Tp x) {
        using Val = Tp;
        using Real = special_functions::num_traits_t<Val>;
        const auto s_fpmin = Real{3} * std::numeric_limits<Tp>::lim_min();
        const auto s_eps = Real{3} * std::numeric_limits<Tp>::epsilon();
        unsigned int s_itmax = 10 * int(10 + std::sqrt(std::abs(a)));

        auto lngam = log_gamma(a);
        auto sign = log_gamma_sign(a);

        auto b = x + Real{1} - a;
        auto c = Real{1} / s_fpmin;
        auto d = Real{1} / b;
        auto h = d;
        for (unsigned int n = 1; n <= s_itmax; ++n) {
            auto an = -Real(n) * (Real(n) - a);
            b += Real{2};
            d = an * d + b;
            if (std::abs(d) < s_fpmin)
                d = s_fpmin;
            c = b + an / c;
            if (std::abs(c) < s_fpmin)
                c = s_fpmin;
            d = Real{1} / d;
            auto del = d * c;
            h *= del;
            if (std::abs(del - Real{1}) < s_eps) {
                auto gamcf = std::exp(-x + a * std::log(x) - lngam)
                             * h * sign;
                return std::make_pair(gamcf, lngam);
            }
        }
        throw std::logic_error("gamma_cont_fraction: a too large, itmax too small in routine.");
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_INCOMPLETE_GAMMA_BY_CONTINUED_FRACTION_H
