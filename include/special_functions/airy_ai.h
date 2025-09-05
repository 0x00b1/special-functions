#ifndef SPECIAL_FUNCTIONS_AIRY_AI_H
#define SPECIAL_FUNCTIONS_AIRY_AI_H


#include <complex>


namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    airy_ai(T x) {
        using type = fp_promote_t<T>;

        return x;
    }

    template<typename T>
    std::complex<fp_promote_t<T> >
    airy_ai(const std::complex<T> &z) {
        using type = fp_promote_t<T>;

        return z;
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_AI_H
