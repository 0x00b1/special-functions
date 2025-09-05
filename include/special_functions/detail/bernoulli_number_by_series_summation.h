#ifndef SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_BY_SERIES_SUMMATION_H
#define SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_BY_SERIES_SUMMATION_H

#include <special_functions/detail/math_constants.h>

namespace detail {
    template<typename T>
    constexpr T
    bernoulli_number_by_series_summation(unsigned int n) {
        constexpr unsigned long MAXIMUM_BERNOULLI_NUMBER_INDEX = 12;

        constexpr T BERNOULLI_NUMBERS_2N[MAXIMUM_BERNOULLI_NUMBER_INDEX]
                {
                        +T{1ULL},
                        +T{1ULL} / T{6ULL},
                        -T{1ULL} / T{30ULL},
                        +T{1ULL} / T{42ULL},
                        -T{1ULL} / T{30ULL},
                        +T{5ULL} / T{66ULL},
                        -T{691ULL} / T{2730ULL},
                        +T{7ULL} / T{6ULL},
                        -T{3617ULL} / T{510ULL},
                        +T{43867ULL} / T{798ULL},
                        -T{174611ULL} / T{330ULL},
                        +T{854513ULL} / T{138ULL}
                };

        if (n == 0) {
            return T{1};
        }

        if (n == 1) {
            return -T{1} / T{2};
        }

        if (n % 2 == 1) {
            return T{0};
        }

        if (n / 2 < MAXIMUM_BERNOULLI_NUMBER_INDEX) {
            return BERNOULLI_NUMBERS_2N[n / 2];
        }

        constexpr auto s_2pi = tau_v<T>;

        auto fact = T{1};

        if ((n / 2) % 2 == 0) {
            fact *= -T{1};
        }

        for (unsigned int k = 1; k <= n; ++k) {
            fact *= k / s_2pi;
        }

        fact *= T{2};

        auto sum = T{0};

        for (unsigned int i = 2; i < 1000; ++i) {
            auto term = std::pow(T(i), -T(n));
            sum += term;

            if (term < std::numeric_limits<T>::epsilon() * sum) {
                break;
            }
        }

        return fact + fact * sum;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_NUMBER_BY_SERIES_SUMMATION_H
