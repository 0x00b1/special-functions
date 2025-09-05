#ifndef SPECIAL_FUNCTIONS_KUMMER_CONFLUENT_HYPERGEOMETRIC_1_F_1_H
#define SPECIAL_FUNCTIONS_KUMMER_CONFLUENT_HYPERGEOMETRIC_1_F_1_H


#include <complex>


namespace special_functions {
    template<typename T, typename U, typename V>
    fp_promote_t<T, U, V>
    kummer_confluent_hypergeometric_1_f_1(T a, U c, V x) {
        using W = fp_promote_t<T, U, V>;

        return x;
    }
}

#endif // SPECIAL_FUNCTIONS_KUMMER_CONFLUENT_HYPERGEOMETRIC_1_F_1_H
