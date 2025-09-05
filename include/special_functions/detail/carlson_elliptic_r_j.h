#ifndef SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_J_H
#define SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_J_H

namespace detail {
    template<typename T>
    T
    carlson_elliptic_r_j(T x, T y, T z, T p) {
        using U = num_traits_t<T>;
        const auto s_min = numeric_limits::lim_min(U{});
        const auto s_eps = std::numeric_limits<U>::epsilon();
        const auto s_lolim = U(5) * s_min;

        bool negative = false;

        if constexpr (!is_complex_v<T>) {
            const auto real_x = std::real(x);
            const auto real_y = std::real(y);
            const auto real_z = std::real(z);

            if (real_x < U{0} || real_y < U{0} || real_z < U{0}) {
                negative = true;
            }
        }

        if (std::isnan(x) || std::isnan(y) || std::isnan(z) || std::isnan(p)) {
            return std::numeric_limits<U>::quiet_NaN();
        }

        if (negative) {
            throw std::domain_error("ellint_rj: argument less than zero");
        }

        const auto abs_x = std::abs(x);
        const auto abs_y = std::abs(y);
        const auto abs_z = std::abs(z);

        if (abs_x + abs_y < s_lolim || abs_y + abs_z < s_lolim || abs_z + abs_x < s_lolim || std::abs(p) < s_lolim) {
            throw std::domain_error("ellint_rj: argument less than minimum");
        }

        if (std::abs(p - z) < s_eps) {
            return carlson_elliptic_r_d(x, y, z);
        }

        auto x_t = x;
        auto y_t = y;
        auto z_t = z;
        auto p_t = p;

        auto A0 = (x + y + z + U{2} * p) / U{5};
        auto delta = (p - x) * (p - y) * (p - z);
        auto Q = std::pow(s_eps / U{4}, -U{1} / U{6}) * std::max(std::abs(A0 - z), std::max(std::abs(A0 - x), std::max(std::abs(A0 - y), std::abs(A0 - p))));
        auto a_t = A0;
        auto f = U{1};
        auto fe = U{1};
        auto sum = T{0};

        while (true) {
            auto sqrt_x_t = std::sqrt(x_t);
            auto sqrt_y_t = std::sqrt(y_t);
            auto sqrt_z_t = std::sqrt(z_t);
            auto sqrt_p_t = std::sqrt(p_t);

            a_t = (a_t + (sqrt_x_t * sqrt_y_t + sqrt_y_t * sqrt_z_t + sqrt_z_t * sqrt_x_t)) / U{4};

            x_t = (x_t + (sqrt_x_t * sqrt_y_t + sqrt_y_t * sqrt_z_t + sqrt_z_t * sqrt_x_t)) / U{4};
            y_t = (y_t + (sqrt_x_t * sqrt_y_t + sqrt_y_t * sqrt_z_t + sqrt_z_t * sqrt_x_t)) / U{4};
            z_t = (z_t + (sqrt_x_t * sqrt_y_t + sqrt_y_t * sqrt_z_t + sqrt_z_t * sqrt_x_t)) / U{4};
            p_t = (p_t + (sqrt_x_t * sqrt_y_t + sqrt_y_t * sqrt_z_t + sqrt_z_t * sqrt_x_t)) / U{4};

            auto d = (sqrt_p_t + sqrt_x_t) * (sqrt_p_t + sqrt_y_t) * (sqrt_p_t + sqrt_z_t);

            auto E = delta / (fe * d * d);

            sum += ellint_rc(T{1}, T{1} + E) / (f * d);
            f *= U{4};
            fe *= U{64};

            if (Q < f * std::abs(a_t)) {
                auto Xi = (A0 - x) / (f * a_t);
                auto Yi = (A0 - y) / (f * a_t);
                auto Zi = (A0 - z) / (f * a_t);
                auto XYZ = Xi * Yi * Zi;
                auto Pi = -(Xi + Yi + Zi) / U{2};
                auto PP = Pi * Pi;
                auto PPP = PP * Pi;
                auto E2 = Xi * Yi + Yi * Zi + Zi * Xi - U{3} * PP;
                auto E3 = XYZ + U{2} * E2 * Pi + T{4} * PPP;
                auto E4 = Pi * (U{2} * XYZ + E2 * Pi + U{3} * PPP);
                auto E5 = XYZ * PP;
                return (U{1} - U{3} * E2 / U{14} + E3 / U{6} + U{9} * E2 * E2 / U{88} - U{3} * E4 / U{22} - U{9} * E2 * E3 / U{52} + U{3} * E5 / U{26}) / f / a_t / std::sqrt(a_t) + U{6} * sum;
            }
        }

        return T{};
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CARLSON_ELLIPTIC_R_J_H
