#ifndef SPECIAL_FUNCTIONS_DETAIL_JACOBI_POLYNOMIAL_P_H
#define SPECIAL_FUNCTIONS_DETAIL_JACOBI_POLYNOMIAL_P_H

#include "jacobi_polynomial_p_t.h"

namespace special_functions::detail {
    template<typename Tp>
    jacobi_t<Tp>
    jacobi_polynomial_p(unsigned int n, Tp alpha1, Tp beta1, Tp x) {
        if (std::isnan(alpha1) || std::isnan(beta1) || std::isnan(x)) {
            return {
                    n,
                    alpha1,
                    beta1,
                    x,
                    std::numeric_limits<Tp>::quiet_NaN(x),
                    std::numeric_limits<Tp>::quiet_NaN(x),
                    std::numeric_limits<Tp>::quiet_NaN(x),
            };
        }

        auto P_nm2 = Tp{1};

        if (n == 0) {
            return {
                    n,
                    alpha1,
                    beta1,
                    x,
                    P_nm2,
                    Tp{0},
                    Tp{0},
            };
        }

        const auto apb = alpha1 + beta1;
        const auto amb = alpha1 - beta1;
        auto P_nm1 = (amb + (apb + Tp{2}) * x) / Tp{2};

        if (n == 1) {
            return {n, alpha1, beta1, x, P_nm1, P_nm2, Tp{0}};
        }

        const auto a2mb2 = amb * apb;
        const auto bah = ((apb + Tp{2}) + Tp{2});
        const auto poo = (bah - Tp{1});

        auto P_n = (((poo * a2mb2) + ((poo - Tp{1}) * poo * bah) * x) * P_nm1 -
                    (Tp{2} * (alpha1 + Tp{1}) * (beta1 + Tp{1}) * bah) * P_nm2) /
                   (Tp{4} * (apb + Tp{2}) * (poo - Tp{1}));

        for (auto k = 3u; k <= n; ++k) {
            const auto apbpk = apb + Tp(k);
            const auto apbp2k = apbpk + Tp(k);
            const auto apbp2km1 = apbp2k - Tp{1};
            const auto apbp2km2 = apbp2km1 - Tp{1};
            const auto d = Tp{2} * k * apbpk * apbp2km2;
            const auto a = apbp2km2 * apbp2km1 * apbp2k;
            const auto b = apbp2km1 * a2mb2;
            const auto c = Tp{2} * (alpha1 + Tp(k - 1)) * (beta1 + Tp(k - 1)) * apbp2k;

            if (d == Tp{0}) {
                throw std::runtime_error("jacobi_recur: Failure in recursion");
            }

            P_nm2 = P_nm1;
            P_nm1 = P_n;
            P_n = ((b + a * x) * P_nm1 - c * P_nm2) / d;
        }

        return {
                n,
                alpha1,
                beta1,
                x,
                P_n,
                P_nm1,
                P_nm2,
        };
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_JACOBI_POLYNOMIAL_P_H
