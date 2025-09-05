#ifndef SPECIAL_FUNCTIONS_PERIODIC_ZETA_F_H
#define SPECIAL_FUNCTIONS_PERIODIC_ZETA_F_H

namespace special_functions {
    template<typename T, typename U>
    fp_promote_t<std::complex<T>, U>
    periodic_zeta(T x, U s) {
        using V = fp_promote_t<T, U>;

        return x;
    }

    template<typename T, typename U>
    fp_promote_t<std::complex<T>, std::complex<U>>
    periodic_zeta(std::complex<U> z, T s) {
        using V = fp_promote_t<T, U>;

        return z;
    }
}

#endif // SPECIAL_FUNCTIONS_PERIODIC_ZETA_F_H
