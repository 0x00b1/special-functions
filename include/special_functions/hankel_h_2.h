#ifndef SPECIAL_FUNCTIONS_HANKEL_H_2_H
#define SPECIAL_FUNCTIONS_HANKEL_H_2_H

namespace special_functions {
    template<typename T, typename U>
    inline std::complex<special_functions::fp_promote_t<T, U>>
    hankel_h_2(T n, U z) {
        using type = special_functions::fp_promote_t<T, U>;

        // return emsr::detail::cyl_hankel_2<type>(n, z);
    }
}

#endif // SPECIAL_FUNCTIONS_HANKEL_H_2_H
