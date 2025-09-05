#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_F_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_F_H

namespace detail {
    template<typename T>
    T
    carlson_elliptic_r_f(T x, T y, T z) {
        using U = num_traits_t<T>;

        bool neg_arg = false;

        if constexpr (!is_complex_v<T>) {
            if (std::real(x) < U{0} || std::real(y) < U{0} || std::real(z) < U{0}) {
                neg_arg = true;
            }
        }

        if (std::isnan(x) || std::isnan(y) || std::isnan(z)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        if (neg_arg) {
            throw std::domain_error("ellint_rf: argument less than zero");
        }

        if (std::abs(x) + std::abs(y) < U(5) * numeric_limits::lim_min(U{}) ||
            std::abs(x) + std::abs(z) < U(5) * numeric_limits::lim_min(U{}) ||
            std::abs(y) + std::abs(z) < U(5) * numeric_limits::lim_min(U{})) {
            throw std::domain_error("ellint_rf: argument too small");
        }

        if (std::abs(z) < std::numeric_limits<U>::epsilon()) {
            return complete_carlson_elliptic_r_f(x, y);
        }

        if (std::abs(z - y) < std::numeric_limits<U>::epsilon()) {
            return carlson_elliptic_r_c(x, y);
        }

        auto xt = x;
        auto yt = y;
        auto zt = z;
        auto A0 = (x + y + z) / U{3};
        auto Q = std::pow(U{3} * std::numeric_limits<U>::epsilon(), -U{1} / U{6}) *
                 std::max(std::abs(A0 - z), std::max(std::abs(A0 - x), std::abs(A0 - y)));
        auto A = A0;
        auto f = U{1};

        while (true) {
            auto lambda = std::sqrt(xt) * std::sqrt(yt) + std::sqrt(yt) * std::sqrt(zt) + std::sqrt(zt) * std::sqrt(xt);
            A = (A + lambda) / U{4};
            xt = (xt + lambda) / U{4};
            yt = (yt + lambda) / U{4};
            zt = (zt + lambda) / U{4};
            f *= U{4};
            if (Q < f * std::abs(A)) {
                auto Xi = (A0 - x) / (f * A);
                auto Yi = (A0 - y) / (f * A);
                auto Zi = -(Xi + Yi);
                auto E2 = Xi * Yi - Zi * Zi;
                auto E3 = Xi * Yi * Zi;
                return (U{1} - E2 / U{10} + E3 / U{14} + E2 * E2 / U{24} - U{3} * E2 * E3 / U{44}) / std::sqrt(A);
            }
        }

        return T{0};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_F_H
