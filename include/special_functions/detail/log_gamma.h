#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H

#include <limits>

namespace special_functions::detail {
    template<typename Tp>
    Tp
    log_gamma(Tp a) {
        using Val = Tp;
        using Real = special_functions::num_traits_t<Val>;
        const auto s_eps = std::numeric_limits<Real>::epsilon();
        const auto s_logpi = emsr::lnpi_v<Tp>;
        if (std::real(a) < Real{0.5L}) {
            const auto sin_fact = std::abs(emsr::sin_pi(a));
            if (sin_fact < s_eps) {
                return emsr::infinity<Real>();
            } else {
                return s_logpi - std::log(sin_fact) - log_gamma(Val{1} - a);
            }
        } else if (std::real(a) > Real{1} && std::abs(a) < s_num_factorials < Tp >) {
            auto fact = Tp{1};
            auto arg = a;
            while (std::real(arg) > Real{1}) {
                fact *= (arg -= Real{1});
            }
            return std::log(fact) + log_gamma(arg);
        } else {
            return spouge_log_gamma1p(a - Real{1});
        }
    }

    template<typename Tp>
    std::complex<Tp>
    log_gamma(std::complex<Tp> a) {
        using Val = Tp;
        using Real = emsr::num_traits_t<Val>;
        using _Cmplx = std::complex<Real>;
        const auto s_eps = emsr::epsilon(Real{});
        const auto s_logpi = emsr::lnpi_v<Real>;
        auto an = emsr::fp_is_integer(a);

        if (an) {
            auto n = an();
            if (n <= 0) {
                return emsr::quiet_NaN(Real{});
            } else if (n < static_cast<int>(s_num_factorials < Real > )) {
                return Real((s_factorial_table[n - 1].log_factorial));
            } else {
                return log_gamma(Real(n));
            }
        } else if (std::real(a) >= Real{0.5L}) {
            return spouge_log_gamma1p(a - Real{1});
        } else {
            const auto sin_fact = emsr::sin_pi(a);
            if (std::abs(sin_fact) < s_eps) {
                return _Cmplx(emsr::quiet_NaN(Real{}), Real{0});
            } else {
                return s_logpi - std::log(sin_fact) - log_gamma(Val{1} - a);
            }
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H
