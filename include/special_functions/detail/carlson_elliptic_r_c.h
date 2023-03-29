#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_C_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_C_H

#include <cmath>
#include <complex>
#include "fp_type_util.h"
#include "complex_util.h"

namespace special_functions::detail {
    template<typename T>
    T
    carlson_elliptic_r_c(T x, T y) {
        using U = special_functions::num_traits_t<T>;

        bool negative_x = false;
        bool negative_y = false;

        if constexpr (!special_functions::is_complex_v<T>) {
            if (std::real(x) < U{0}) {
                negative_x = true;
            }

            if (std::real(y) < U{0}) {
                negative_y = true;
            }
        }

        if (std::isnan(x) || std::isnan(y)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        if (negative_x) {
            throw std::domain_error("ellint_rc: argument less than zero");
        }

        if (std::abs(x) + std::abs(y) < U{5} * std::numeric_limits<U>::lim_min()) {
            throw std::domain_error("ellint_rc: arguments too small");
        }

        if (negative_y) {
            if (std::abs(x) == U{0}) {
                return T{};
            }

            return std::sqrt(x / (x - y)) * carlson_elliptic_r_c(x - y, -y);
        }

        auto xt = x;
        auto yt = y;
        auto A0 = (x + U{2} * y) / U{3};
        auto Q = std::pow(U{3} * std::numeric_limits<U>::epsilon(), -U{1} / U{8}) * std::abs(A0 - x);
        auto A = A0;
        auto f = U{1};

        while (true) {
            auto lambda = U{2} * std::sqrt(xt) * std::sqrt(yt) + yt;
            A = (A + lambda) / U{4};
            xt = (xt + lambda) / U{4};
            yt = (yt + lambda) / U{4};
            f *= U{4};

            if (Q < f * std::abs(A)) {
                auto s = (y - A0) / (f * A);

                return (U{1} + s * s * (U{3} / U{10} + s * (U{1} / U{7} + s * (U{3} / U{8} + s * (U{9} / U{22} + s * (U{159} / U{208} + s * (U{9} / U{8}))))))) / std::sqrt(A);
            }
        }

        return T{0};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_C_H
