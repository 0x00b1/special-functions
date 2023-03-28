#ifndef SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_H

#include "math_constants.h"
#include "math_util.h"
#include "../tan_pi.h"

namespace special_functions::detail {
    template<typename T>
    T
    digamma(unsigned int n) {
        using U = special_functions::num_traits_t<T>;

        if (n > 1) {
            return -std::numbers::egamma_v<U> + harmonic_number<U>(n - 1);
        } else {
            return -std::numbers::egamma_v<U>;
        }
    }

    template<typename Tp>
    Tp
    digamma_series(Tp x) {
        using Val = special_functions::num_traits_t<Tp>;

        Tp sum = -std::numbers::egamma_v<Val>;

        const unsigned int s_max_iter = 100000;

        for (unsigned int k = 0; k < s_max_iter; ++k) {
            const auto term = (x - Tp{1}) / (Tp(k + 1) * (Tp(k) + x));

            sum += term;

            if (std::abs(term) < std::numeric_limits<Val>::epsilon()) {
                break;
            }
        }

        return sum;
    }

    template<typename Tp>
    Tp
    digamma_asymp(Tp x) {
        using Val = special_functions::num_traits_t<Tp>;

        auto sum = std::log(x) - Val{0.5L} / x;

        const auto xx = x * x;

        auto xp = xx;

        const unsigned int max_iter = 100;

        for (unsigned int k = 1; k < max_iter; k++) {
            const Tp term = bernoulli_number<Val>(2 * k) / (Val(2 * k) * xp);

            sum -= term;

            if (std::abs(term / sum) < std::numeric_limits<Val>::epsilon()) {
                break;
            }

            xp *= xx;
        }

        return sum;
    }

    template<typename Tp>
    Tp
    digamma(Tp x) {
        using Val = special_functions::num_traits_t<Tp>;
        const auto s_x_asymp = Val{20};
        const auto s_gamma_E = std::numbers::egamma_v<Val>;
        const auto s_2_ln_2 = Tp{2} * special_functions::ln2_v<Val>;
        const auto s_pi = special_functions::pi_v<Val>;

        const auto n = special_functions::fp_is_integer(x);
        const auto m = special_functions::fp_is_half_odd_integer(x);
        if (std::real(x) <= Val{0}) {
            if (n) {
                return std::numeric_limits<Tp>::quiet_NaN();
            } else {
                return digamma(Val{1} - x) - s_pi / special_functions::tan_pi(x);
            }
        } else if (n) {
            return digamma<Tp>(n());
        } else if (m) {
            Tp sum = -s_gamma_E - s_2_ln_2;
            for (int k = 1; k <= m(); k++) {
                sum += Tp{2} / Tp(2 * k - 1);
            }
            return sum;
        } else if (std::real(x) > s_x_asymp) {
            return digamma_asymp(x);
        } else {
            // The series does not converge quickly enough.
            // Reflect to larger argument and use asymptotic expansion.
            auto w = Tp{0};
            auto y = x;
            while (std::real(y) <= s_x_asymp) {
                w += Val{1} / y;
                y += Val{1};
            }
            return digamma_asymp(y) - w;
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_H
