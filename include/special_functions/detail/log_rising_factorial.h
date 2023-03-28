#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_RISING_FACTORIAL_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_RISING_FACTORIAL_H

namespace special_functions::detail {
    template<typename Tp>
    Tp
    log_rising_factorial(Tp a, Tp nu)
    {
        using Val = Tp;
        using Real = emsr::num_traits_t<Val>;

        if (std::isnan(nu) || std::isnan(a)) {
            return emsr::quiet_NaN(a);
        } else if (nu == Tp{0}) {
            return Tp{0};
        } else if (std::abs(a) < s_num_factorials < Real > && std::abs(a + nu) < s_num_factorials < Real >) {
            return std::log(rising_factorial(a, nu));
        } else {
            return log_gamma(a + nu) - log_gamma(a);
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_RISING_FACTORIAL_H
