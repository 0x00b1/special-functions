#ifndef SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_POLYNOMIAL_B_H
#define SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_POLYNOMIAL_B_H

namespace special_functions::detail {
    template<typename T>
    T
    bernoulli_polynomial_b(unsigned int n, T x) {
        if (std::isnan(x)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        auto b = bernoulli_number<T>(0);

        auto binomial = T{1};

        for (auto k = 1u; k <= n; k++) {
            binomial *= T(n + 1 - k) / T(k);

            b = x * b + binomial * bernoulli_number<T>(k);
        }

        return b;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_BERNOULLI_POLYNOMIAL_B_H
