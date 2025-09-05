#ifndef SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_BY_RECURSION_H
#define SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_BY_RECURSION_H

namespace detail {
    template<typename Tp>
    std::tuple <Tp, Tp, Tp>
    chebyshev_polynomial_by_recursion(unsigned int n, Tp x, Tp C0, Tp C1) {
        auto Ck = Tp{2} * x * C1 - C0;
        for (unsigned int j = 2; j < n; ++j) {
            C0 = C1;
            C1 = Ck;
            Ck = Tp{2} * x * C1 - C0;
        }
        return std::make_tuple(Ck, C1, C0);
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_CHEBYSHEV_POLYNOMIAL_BY_RECURSION_H
