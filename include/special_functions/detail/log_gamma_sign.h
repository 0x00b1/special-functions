#ifndef SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_SIGN_H
#define SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_SIGN_H

#include <complex>

namespace special_functions::detail {
    /**
     * @brief Return the sign of @f$ \Gamma(x) @f$.
     * At nonpositive integers zero is returned indicating @f$ \Gamma(x) @f$
     * is undefined.
     *
     * @param a The argument of the gamma function.
     * @return  The sign of the gamma function.
     */
    template<typename Tp>
    Tp
    log_gamma_sign(Tp a)
    {
        if (a >= Tp{0})
            return Tp{1};
        else if (a == std::nearbyint(a))
            return Tp{0};
        else
            return (int(-a) % 2 == 0) ? -Tp{1} : Tp{1};
    }

    template<typename Tp>
    std::complex<Tp>
    log_gamma_sign(std::complex<Tp>)
    { return std::complex<Tp>{1}; }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_LOG_GAMMA_SIGN_H
