#ifndef SPECIAL_FUNCTIONS_AIRY_BI_H
#define SPECIAL_FUNCTIONS_AIRY_BI_H

namespace special_functions {
    template<typename T>
    inline special_functions::fp_promote_t<T>
    airy_bi(T x) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::airy<type>(x).Bi_value;
    }

    template<typename T>
    inline std::complex<special_functions::fp_promote_t<T>>
    airy_bi(const std::complex<T> &z) {
        using type = special_functions::fp_promote_t<T>;

        // return special_functions::detail::airy_bi<type>(z);
    }
}

#endif // SPECIAL_FUNCTIONS_AIRY_BI_H
