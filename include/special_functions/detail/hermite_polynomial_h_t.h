#ifndef SPECIAL_FUNCTIONS_DETAIL_HERMITE_POLYNOMIAL_H_T_H
#define SPECIAL_FUNCTIONS_DETAIL_HERMITE_POLYNOMIAL_H_T_H

namespace special_functions::detail {
    template<typename T>
    struct hermite_polynomial_h_t {
        unsigned int n;
        T x;
        T H_n;
        T H_nm1;
        T H_nm2;

        constexpr T
        deriv() const noexcept { return T(2 * n) * H_nm1; }

        constexpr T
        deriv2() const noexcept { return T(4 * n * (n - 1)) * H_nm2; }
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HERMITE_POLYNOMIAL_H_T_H
