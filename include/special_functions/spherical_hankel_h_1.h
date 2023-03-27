#ifndef SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H
#define SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H

namespace special_functions {
    template<typename T>
    inline std::complex<special_functions::fp_promote_t<T>>
    spherical_hankel_h_1(unsigned int n, T z) {
        using type = special_functions::fp_promote_t<T>;

        // return emsr::detail::sph_hankel_1<type>(n, z);
    }
}

#endif // SPECIAL_FUNCTIONS_SPHERICAL_HANKEL_H_1_H
