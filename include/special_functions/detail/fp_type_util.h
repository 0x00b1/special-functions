#ifndef SPECIAL_FUNCTIONS_DETAIL_FP_TYPE_UTIL_H
#define SPECIAL_FUNCTIONS_DETAIL_FP_TYPE_UTIL_H

#include <utility>
#include <ratio>
#include <limits>

namespace special_functions {
    /**
     * A class to reach into compound numeric types to extract the
     * value or element type.  This will be specialized for complex
     * and other types as appropriate.
     */
    template<typename Tp>
    struct num_traits {
        using value_type = Tp;
    };

    template<typename Tp>
    using num_traits_t = typename num_traits<Tp>::value_type;


    /**
     * Return a fraction as a real number.
     */
    template<intmax_t Num, intmax_t Den = 1, typename Tp = double>
    constexpr Tp
    frac() {
        using rat_t = std::ratio<Num, Den>;
        return Tp(rat_t::num) / Tp(rat_t::den);
    }


    /**
     * Create a NaN.
     * This will be overloaded for complex and vector types.
     */
    template<typename Tp>
    struct make_NaN {
        constexpr Tp
        operator()() { return std::numeric_limits<Tp>::quiet_NaN(); }
    };

    /**
     * This is a more modern version of promote_N in ext/type_traits.
     * This is used for numeric argument promotion of complex and cmath.
     */
    template<typename Tp, bool = std::is_integral_v<Tp>>
    struct fp_promote_help {
        using type = double;
    };

    // No nested type member for non-integer non-floating point types,
    // allows this type to be used for SFINAE to constrain overloads in
    // <cmath> and <complex> to only the intended types.
    template<typename Tp>
    struct fp_promote_help<Tp, false> {
    }; // using type = void?

    template<>
    struct fp_promote_help<float> {
        using type = float;
    };

    template<>
    struct fp_promote_help<double> {
        using type = double;
    };

    template<>
    struct fp_promote_help<long double> {
        using type = long double;
    };

    template<typename... Types>
    using fp_promote_help_t = typename fp_promote_help<Types...>::type;

    template<typename Type, typename... Types>
    struct fp_promote {
        using type = decltype(fp_promote_help_t<std::decay_t<Type>>{} + typename fp_promote<Types...>::type{});
    };

    template<typename Type>
    struct fp_promote<Type> {
        using type = decltype(fp_promote_help_t<std::decay_t<Type>>{});
    };

    template<typename... Types>
    using fp_promote_t = typename fp_promote<Types...>::type;
}

#endif //SPECIAL_FUNCTIONS_DETAIL_FP_TYPE_UTIL_H
