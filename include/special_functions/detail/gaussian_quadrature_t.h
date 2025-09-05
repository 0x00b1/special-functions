#ifndef SPECIAL_FUNCTIONS_DETAIL_GAUSSIAN_QUADRATURE_T_H
#define SPECIAL_FUNCTIONS_DETAIL_GAUSSIAN_QUADRATURE_T_H

namespace detail {
    enum gaussian_quadrature_t {
        Gauss,             ///< Gauss quadrature
        Gauss_Lobatto,     ///< Gauss-Lobatto quadrature
        Gauss_Radau_lower, ///< Gauss-Radau quadrature including the node -1
        Gauss_Radau_upper  ///< Gauss-Radau quadrature including the node +1
    };
}

#endif // SPECIAL_FUNCTIONS_DETAIL_GAUSSIAN_QUADRATURE_T_H
