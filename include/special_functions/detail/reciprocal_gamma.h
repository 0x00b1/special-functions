#ifndef SPECIAL_FUNCTIONS_DETAIL_RECIPROCAL_GAMMA_H
#define SPECIAL_FUNCTIONS_DETAIL_RECIPROCAL_GAMMA_H

#include "../sin_pi.h"
#include "math_util.h"

namespace special_functions::detail {
    template<typename T>
    T
    reciprocal_gamma(T a) {
        using U = special_functions::num_traits_t<T>;

        if (std::isnan(a)) {
            return std::numeric_limits<T>::quiet_NaN();
        } else {
            const auto s_pi = std::numbers::pi_v<U>;

            const auto an = emsr::fp_is_integer(a);

            if (an) {
                auto n = an();

                if (n <= 0) {
                    return T{0};
                } else if (n < int(special_functions::numbers::MAXIMUM_FACTORIAL_INDEX<U>)) {
                    return T{1} / U(special_functions::numbers::FACTORIALS[n - 1]);
                } else {
                    auto k = int(special_functions::numbers::MAXIMUM_FACTORIAL_INDEX<U>);

                    auto rgam = T{1} / U(special_functions::numbers::FACTORIALS[k - 1]);

                    while (k < n && std::abs(rgam) > U{0}) {
                        rgam /= U(k++);
                    }

                    return rgam;
                }
            } else if (std::real(a) > U{1}) {
                auto n = int(std::floor(std::real(a)));
                auto nu = a - T(n);
                auto rgam = gamma_reciprocal_series(nu);

                while (std::real(a) > U{1} && std::abs(rgam) > T{0}) {
                    rgam /= (a -= U{1});
                }

                return rgam;
            } else if (std::real(a) > U{0}) {
                return gamma_reciprocal_series(a);
            } else {
                return special_functions::sin_pi(a) * gamma(T{1} - a) / s_pi;
            }
        }
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_RECIPROCAL_GAMMA_H
