#ifndef SPECIAL_FUNCTIONS_DETAIL_RADIAL_POLYNOMIAL_R_H
#define SPECIAL_FUNCTIONS_DETAIL_RADIAL_POLYNOMIAL_R_H

namespace special_functions::detail {
    template<typename T>
    T
    radial_polynomial_r(unsigned int n, unsigned int m, T r) {
        if (std::isnan(r)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (int(n) - int(m) < 0) {
            return T{0};
        }

        if ((int(n) - int(m)) % 2 == 1) {
            return T{0};
        }

        auto k = (int(n) - int(m)) / 2;

        return (k % 2 == 0 ? +1 : -1) * std::pow(r, m) * jacobi_recur(k, T(m), T{0}, T{1} - T{2} * r * r).P_n;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_RADIAL_POLYNOMIAL_R_H
