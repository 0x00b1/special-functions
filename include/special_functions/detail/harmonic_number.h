#ifndef SPECIAL_FUNCTIONS_DETAIL_HARMONIC_NUMBER_H
#define SPECIAL_FUNCTIONS_DETAIL_HARMONIC_NUMBER_H

namespace special_functions::detail {
    template<typename T>
    T
    harmonic_number(unsigned int n) {
        using special_functions::numbers::MAXIMUM_HARMONIC_NUMBER_INDEX;

        using special_functions::numbers::HARMONIC_NUMBER_NUMERATORS;
        using special_functions::numbers::HARMONIC_NUMBER_DENOMINATORS;

        if (n <= MAXIMUM_HARMONIC_NUMBER_INDEX) {
            return T(HARMONIC_NUMBER_NUMERATORS[n - 1]) / T(HARMONIC_NUMBER_DENOMINATORS[n - 1]);
        }

        unsigned int k = MAXIMUM_HARMONIC_NUMBER_INDEX - 1;

        auto v = T(HARMONIC_NUMBER_NUMERATORS[k]) / T(HARMONIC_NUMBER_DENOMINATORS[k]);

        for (k = MAXIMUM_HARMONIC_NUMBER_INDEX + 1; k <= n; k++) v += T{1} / T(k);

        return v;
    }
}

#endif // SPECIAL_FUNCTIONS_DETAIL_HARMONIC_NUMBER_H
