#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    log_falling_factorial(Tp a, Tp nu) {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        using Val = Tp;
        using Real = special_functions::num_traits_t<Val>;
        const auto s_NaN = std::numeric_limits<Val>::quiet_NaN();
        const auto s_inf = std::numeric_limits<Val>::infinity();
        const auto inu = special_functions::fp_is_integer(nu);
        const auto ia = special_functions::fp_is_integer(a);

        if (std::isnan(nu) || std::isnan(a)) {
            return s_NaN;
        }

        if (nu == Tp{0}) {
            return Tp{0};
        }

        if (inu) {
            if (ia) {
                if (ia() < inu()) {
                    return -s_inf;
                }

                return log_factorial<Val>(unsigned(ia())) - log_factorial<Val>(unsigned(ia() - inu()));
            }

            return std::log(std::abs(falling_factorial(a, inu())));
        }

        if (std::abs(a) < MAXIMUM_FACTORIAL_INDEX<Real> && std::abs(a - nu) < MAXIMUM_FACTORIAL_INDEX<Real>) {
            return std::log(std::abs(falling_factorial(a, nu)));
        }

        return log_gamma(a + Tp{1}) - log_gamma(a - nu + Tp{1});
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_FALLING_FACTORIAL_H
