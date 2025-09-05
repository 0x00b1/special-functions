#ifndef SPECIAL_FUNCTIONS_AIRY_BI_H
#define SPECIAL_FUNCTIONS_AIRY_BI_H

#include <special_functions/detail/airy_bi.h>

namespace special_functions {
    template<typename T>
    fp_promote_t<T>
    airy_bi(T x) {
        using type = fp_promote_t<T>;

        return detail::airy<type>(x).Bi_value;
    }

    template<typename T>
    std::complex<fp_promote_t<T>>
    airy_bi(const std::complex<T> &z) {
        using type = fp_promote_t<T>;

        return detail::airy_bi<type>(z);
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_BI_H
