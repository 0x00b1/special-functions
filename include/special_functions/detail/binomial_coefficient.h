#ifndef SPECIAL_FUNCTIONS_DETAIL_BINOMIAL_COEFFICIENT_H
#define SPECIAL_FUNCTIONS_DETAIL_BINOMIAL_COEFFICIENT_H

#include <limits>

#include <special_functions/numbers.h>
#include <special_functions/numeric_limits.h>

namespace special_functions::detail {
    template<typename Tp>
    Tp
    binomial_coefficient(unsigned int n, unsigned int k) {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        using Val = Tp;
        using Real = special_functions::num_traits_t<Val>;
        // Max e exponent before overflow.
        const auto max_binom
                = special_functions::numeric_limits::max_exponent10<Real>()
                  * std::log(Real(10)) - Real(1);

        if (k > n)
            return Tp{0};

        if (k == 0 || k == n)
            return Tp{1};
        else {
            unsigned int nmk = n - k;
            if (n < MAXIMUM_FACTORIAL_INDEX<Real>
                && k < MAXIMUM_FACTORIAL_INDEX<Real>
                && nmk < MAXIMUM_FACTORIAL_INDEX<Real>)
                return factorial<Tp>(n)
                       / factorial<Tp>(k) / factorial<Tp>(nmk);
            else {
                const auto log_coeff = log_binomial<Val>(n, k);
                if (std::abs(log_coeff) > max_binom)
                    return std::numeric_limits<Tp>::infinity();
                else
                    return std::exp(log_coeff);
            }
        }
    }

    template<typename Tp>
    Tp
    binomial_coefficient(Tp nu, unsigned int k) {
        using special_functions::numbers::MAXIMUM_FACTORIAL_INDEX;

        using Val = Tp;
        using Real = special_functions::num_traits_t<Val>;

        auto n = int(std::nearbyint(nu));

        if (std::isnan(nu))
            return std::numeric_limits<Tp>::quiet_NaN();

        if (nu == n && n >= 0 && n < MAXIMUM_FACTORIAL_INDEX<Real>)
            return binomial<Tp>(static_cast<unsigned int>(n), k);

        if (std::abs(nu) < MAXIMUM_FACTORIAL_INDEX<Real> && k < MAXIMUM_FACTORIAL_INDEX<Real>)
            return gamma(nu + Tp{1}) / gamma(Tp(k + 1)) / gamma(nu - Tp(k + 1));

        const auto max_binom = special_functions::numeric_limits::max_exponent10(nu) * std::log(Tp{10}) - Tp{1};

        const auto log_coeff = log_binomial(nu, k);
        const auto sign = log_binomial_sign(nu, k);

        if (log_coeff > max_binom)
            return std::numeric_limits<Tp>::infinity() * sign;

        return std::exp(log_coeff) * sign;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BINOMIAL_COEFFICIENT_H
