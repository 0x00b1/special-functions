#ifndef SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_H
#define SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_H

#include "math_constants.h"

namespace special_functions::detail {
    /**
     * @brief This returns Bernoulli numbers from a table or by summation
     * for larger values.
     * @f[
     *    B_{2n} = (-1)^{n+1} 2\frac{(2n)!}{(2\pi)^{2n}} \zeta(2n)
     * @f]
     *
     * Note that
     * @f[
     *    \zeta(2n) - 1 = (-1)^{n+1} \frac{(2\pi)^{2n}}{(2n)!} B_{2n} - 2
     * @f]
     * are small and rapidly decreasing finctions of n.
     *
     * @param n the order n of the Bernoulli number.
     * @return  The Bernoulli number of order n.
     */
    template<typename Tp>
    constexpr Tp
    bernoulli_series(unsigned int n) {
        constexpr unsigned long s_num_bern_tab = 12;
        constexpr Tp s_bernoulli_2n[s_num_bern_tab]{
                Tp{1ULL},
                Tp{1ULL} / Tp{6ULL},
                -Tp{1ULL} / Tp{30ULL},
                Tp{1ULL} / Tp{42ULL},
                -Tp{1ULL} / Tp{30ULL},
                Tp{5ULL} / Tp{66ULL},
                -Tp{691ULL} / Tp{2730ULL},
                Tp{7ULL} / Tp{6ULL},
                -Tp{3617ULL} / Tp{510ULL},
                Tp{43867ULL} / Tp{798ULL},
                -Tp{174611ULL} / Tp{330ULL},
                Tp{854513ULL} / Tp{138ULL}
        };

        if (n == 0)
            return Tp{1};
        else if (n == 1)
            return -Tp{1} / Tp{2};
            // Take care of the rest of the odd ones.
        else if (n % 2 == 1)
            return Tp{0};
            // Take care of some small evens that are painful for the series.
        else if (n / 2 < s_num_bern_tab)
            return s_bernoulli_2n[n / 2];
        else {
            constexpr auto s_2pi = special_functions::tau_v<Tp>;
            auto fact = Tp{1};
            if ((n / 2) % 2 == 0)
                fact *= -Tp{1};
            for (unsigned int k = 1; k <= n; ++k)
                fact *= k / s_2pi;
            fact *= Tp{2};

            // Riemann zeta function minus-1 for even integer argument.
            auto sum = Tp{0};
            for (unsigned int i = 2; i < 1000; ++i) {
                auto term = std::pow(Tp(i), -Tp(n));
                sum += term;
                if (term < std::numeric_limits<Tp>::epsilon() * sum)
                    break;
            }

            return fact + fact * sum;
        }
    }

    template<typename T>
    constexpr T
    bernoulli_number(unsigned int n) {
        return bernoulli_series<T>(n);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_H
