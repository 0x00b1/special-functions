#ifndef SPECIAL_FUNCTIONS_DETAIL_NOME_Q_H
#define SPECIAL_FUNCTIONS_DETAIL_NOME_Q_H

#include "nome_q_by_maclaurin_series.h"

namespace detail {
    template<typename T>
    T
    nome_q(T k) {
        if (std::isnan(k)) {
            return std::numeric_limits<T>::quiet_NaN();
        }

        if (std::abs(k) > T{1}) {
            throw std::domain_error("`k` must be in [-1, 1]");
        }

        if (k < std::pow(T{67} * std::numeric_limits<T>::epsilon(), T{0.125L})) {
            return nome_q_by_maclaurin_series(k);
        }

        return std::exp(-std::numbers::pi_v<T> * complete_elliptic_integral_k(std::sqrt(T{1} - k * k)) / complete_elliptic_integral_k(k));
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_NOME_Q_H
