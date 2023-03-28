#ifndef SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_BY_ASYMPTOTIC_EXPANSION_H
#define SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_BY_ASYMPTOTIC_EXPANSION_H

namespace special_functions::detail {
    template<typename T>
    T
    digamma_by_asymptotic_expansion(T x) {
        using U = special_functions::num_traits_t<T>;

        auto summation = std::log(x) - U{0.5L} / x;

        auto p = x * x;

        for (unsigned int iteration = 1; iteration < 100; iteration++) {
            const T q = bernoulli_number<U>(2 * iteration) / (U(2 * iteration) * p);

            summation = summation - q;

            if (std::abs(q / summation) < std::numeric_limits<U>::epsilon()) break;

            p = p * (x * x);
        }

        return summation;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_DIGAMMA_BY_ASYMPTOTIC_EXPANSION_H
