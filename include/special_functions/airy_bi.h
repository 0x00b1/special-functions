#ifndef SPECIAL_FUNCTIONS_AIRY_BI_H
#define SPECIAL_FUNCTIONS_AIRY_BI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    airy_bi(T x) {
        using type = fp_promote_t<T>;

        return x;
    }

    template<typename T>
    std::complex<fp_promote_t<T> >
    airy_bi(const std::complex<T> &z) {
        using type = fp_promote_t<T>;

        return z;
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_BI_H
