#ifndef SPECIAL_FUNCTIONS_DETAIL_COMPLETE_CARLSON_ELLIPTIC_R_G_H
#define SPECIAL_FUNCTIONS_DETAIL_COMPLETE_CARLSON_ELLIPTIC_R_G_H

namespace special_functions::detail {
    template<typename T>
    T
    complete_carlson_elliptic_r_g(T x, T y) {
        using special_functions::numeric_limits::sqrt_eps;

        using U = special_functions::num_traits_t<T>;

        if (std::isnan(x) || std::isnan(y)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        if (x == T{0} && y == T{}) {
            return T{};
        }

        if (x == T{0}) {
            return std::sqrt(y) / U{2};
        }

        if (y == T{0}) {
            return std::sqrt(x) / U{2};
        }

        auto xt = std::sqrt(x);
        auto yt = std::sqrt(y);
        const auto A = (xt + yt) / U{2};
        auto sum = T{};
        auto sf = U{1} / U{2};
        while (true) {
            auto xtt = xt;
            xt = (xt + yt) / U{2};
            yt = std::sqrt(xtt) * std::sqrt(yt);
            auto del = xt - yt;

            if (std::abs(del) < U{2.7L} * sqrt_eps(U{}) * std::abs(xt)) {
                return (A * A - sum) * std::numbers::pi_v<U> / (xt + yt) / U{2};
            }

            sum += sf * del * del;
            sf *= U{2};
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_COMPLETE_CARLSON_ELLIPTIC_R_G_H
