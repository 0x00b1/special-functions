#ifndef SPECIAL_FUNCTIONS_DETAIL_GAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_GAMMA_H

namespace detail {
    template<typename T>
    T
    gamma(T a) {
        using numbers::MAXIMUM_FACTORIAL_INDEX;
        using numbers::FACTORIALS;

        using U = T;
        using V = num_traits_t<U>;

        auto is_integer_a = fp_is_integer(a);

        if (is_integer_a) {
            const auto integer_a = is_integer_a();

            if (integer_a <= 0) {
                return std::numeric_limits<V>::quiet_NaN();
            }

            if (integer_a < static_cast<int>(MAXIMUM_FACTORIAL_INDEX<V>)) {
                return static_cast<V>(FACTORIALS[integer_a - 1]);
            }

            return std::numeric_limits<V>::infinity();
        }

        if (std::real(a) > V{1} && std::abs(a) < MAXIMUM_FACTORIAL_INDEX<T>) {
            auto f = T{1};

            auto b = a;

            while (std::real(b) > V{1}) {
                f *= (b -= V{1});
            }

            return f / gamma_reciprocal_series(b);
        }

        return log_gamma_sign(a) * std::exp(log_gamma(a));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_GAMMA_H
