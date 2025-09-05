#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H

#include <limits>
#include <special_functions/sin_pi.h>

#include "complex_util.h"
#include "math_constants.h"

namespace detail {
    template<typename T>
    constexpr T
    log_gamma_asymptotic_expansion_bernoulli_coefficients(T x) {
        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto s_ln2pi = special_functions::ln2_v<V> + special_functions::lnpi_v<V>;

        auto lg = (x - V{0.5L}) * std::log(x) - x + V{0.5L} * s_ln2pi;

        const auto xx = V{1} / (x * x);

        auto xk = V{1} / x;

        for (unsigned int iteration = 1; iteration < 100; iteration++) {
            const auto term =
                    bernoulli_number<T>(T(2 * iteration)) * xk / (T(2 * iteration) * (T(2 * iteration) - T{1}));

            lg += term;

            if (std::abs(term) < V{0.01L} * std::numeric_limits<V>::epsilon() * std::abs(lg)) {
                break;
            }

            xk *= xx;
        }

        return lg;
    }

    template<typename T>
    constexpr T
    spouge_binet1p(T z) {
        using numbers::SPOUGE;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto chebyshev_coefficients = SPOUGE<V>::chebyshev_coefficients;

        U summation = special_functions::sqrttau_v<V>;

        for (unsigned long long k = 0; k < chebyshev_coefficients.size(); k++) {
            summation = summation + (chebyshev_coefficients[k] / (z + V(k + 1)));
        }

        return summation;
    }

    template<typename T>
    constexpr T
    spouge_log_gamma1p(T z) {
        using numbers::SPOUGE;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        auto a = V{SPOUGE<V>::chebyshev_coefficients.size() + 1};

        if (std::real(z) < V{-1}) {
            auto sin_fact = sin_pi(z);

            if (!special_functions::is_complex_v<U>) {
                sin_fact = std::abs(sin_fact);
            }

            return special_functions::lnpi_v<V> - std::log(sin_fact) - spouge_log_gamma1p(-V{1} - z);
        }

        auto summation = spouge_binet1p(z);

        if (!special_functions::is_complex_v<U>) {
            summation = std::abs(summation);
        }

        return std::log(summation) + (z + V{0.5L}) * std::log(z + a) - (z + a);
    }

    template<typename T>
    constexpr T
    lanczos_binet1p(T z) {
        using numbers::LANCOZ;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto chebyshev_coefficients = LANCOZ<V>::chebyshev_coefficients;

        auto f = U{1};

        auto v = U{0.5L} * chebyshev_coefficients[0];

        for (unsigned int k = 1, n = chebyshev_coefficients.size(); k < n; k++) {
            f *= (z - V(k - 1)) / (z + V(k));

            v += f * chebyshev_coefficients[k];
        }

        return special_functions::sqrttau_v<V> * v;
    }

    template<typename T>
    constexpr T
    lanczos_log_gamma1p(T z) {
        using numbers::LANCOZ;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto s_ln_pi = special_functions::lnpi_v<V>;

        auto g = LANCOZ<V>::s_g;

        if (std::real(z) < V{-1}) {
            auto sin_fact = sin_pi(z);

            if (!special_functions::is_complex_v<U>) {
                sin_fact = std::abs(sin_fact);
            }

            return s_ln_pi - std::log(sin_fact) - lanczos_log_gamma1p(-V{1} - z);
        }

        auto summation = lanczos_binet1p(z);

        if (!special_functions::is_complex_v<U>) {
            summation = std::abs(summation);
        }

        return std::log(summation) + (z + V{0.5L}) * std::log(z + g + V{0.5L}) - (z + g + V{0.5L});
    }

    template<typename T>
    T
    log_gamma(T a) {
        using numbers::MAXIMUM_FACTORIAL_INDEX;

        using U = T;
        using V = special_functions::num_traits_t<U>;

        const auto s_eps = std::numeric_limits<V>::epsilon();
        const auto s_logpi = special_functions::lnpi_v<T>;

        if (std::real(a) < V{0.5L}) {
            const auto sin_fact = std::abs(sin_pi(a));

            if (sin_fact < s_eps) {
                return std::numeric_limits<V>::infinity();
            }

            return s_logpi - std::log(sin_fact) - log_gamma(U{1} - a);
        }

        if (std::real(a) > V{1} && std::abs(a) < MAXIMUM_FACTORIAL_INDEX<T>) {
            auto f = T{1};
            auto arg = a;

            while (std::real(arg) > V{1}) {
                f *= (arg -= V{1});
            }

            return std::log(f) + log_gamma(arg);
        }

        return spouge_log_gamma1p(a - V{1});
    }

    template<typename T>
    std::complex<T>
    log_gamma(std::complex<T> a) {
        using numbers::MAXIMUM_FACTORIAL_INDEX;
        using numbers::LOG_FACTORIALS;

        using U = T;
        using V = special_functions::num_traits_t<U>;
        using W = std::complex<V>;

        auto is_integer = fp_is_integer(a);

        if (is_integer) {
            auto integer = is_integer();

            if (integer <= 0) {
                return std::numeric_limits<V>::quiet_NaN();
            }

            if (integer < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<V>)) {
                return V(LOG_FACTORIALS[integer - 1]);
            }

            return log_gamma(V(integer));
        }

        if (std::real(a) >= V{0.5L}) {
            return spouge_log_gamma1p(a - V{1});
        }

        if (std::abs(sin_pi(a)) < std::numeric_limits<V>::epsilon()) {
            return W(std::numeric_limits<V>::quiet_NaN(), V{0});
        }

        return special_functions::lnpi_v<V> - std::log(sin_pi(a)) - log_gamma(U{1} - a);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_H
