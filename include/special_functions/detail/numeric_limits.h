#ifndef SPECIAL_FUNCTIONS_DETAIL_NUMERIC_LIMITS_H
#define SPECIAL_FUNCTIONS_DETAIL_NUMERIC_LIMITS_H

#include <cmath>
#include <limits>

namespace special_functions {
    template<typename Tp>
    constexpr bool
    is_specialized(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_specialized; }

    template<typename Tp>
    constexpr Tp
    lim_min(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::min(); }

    template<typename Tp>
    constexpr Tp
    lim_max(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::max(); }

    template<typename Tp>
    constexpr Tp
    lowest(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::lowest(); }

    template<typename Tp>
    constexpr int
    digits(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::digits; }

    template<typename Tp>
    constexpr int
    digits10(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::digits10; }

    template<typename Tp>
    constexpr int
    max_digits10(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::max_digits10; }

    template<typename Tp>
    constexpr bool
    is_signed(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_signed; }

    template<typename Tp>
    constexpr bool
    is_integer(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_integer; }

    template<typename Tp>
    constexpr bool
    is_exact(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_exact; }

    template<typename Tp>
    constexpr int
    radix(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::radix; }

    template<typename Tp>
    constexpr Tp
    epsilon(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::epsilon(); }

    template<typename Tp>
    constexpr Tp
    round_error(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::round_error(); }

    template<typename Tp>
    constexpr int
    min_exponent(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::min_exponent; }

    template<typename Tp>
    constexpr int
    min_exponent10(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::min_exponent10; }

    template<typename Tp>
    constexpr int
    max_exponent(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::max_exponent; }

    template<typename Tp>
    constexpr int
    max_exponent10(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::max_exponent10; }

    template<typename Tp>
    constexpr bool
    has_infinity(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::has_infinity; }

    template<typename Tp>
    constexpr bool
    has_quiet_NaN(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::has_quiet_NaN; }

    template<typename Tp>
    constexpr bool
    has_signaling_NaN(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::has_signaling_NaN; }

    template<typename Tp>
    constexpr std::float_denorm_style
    has_denorm(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::has_denorm; }

    template<typename Tp>
    constexpr bool
    has_denorm_loss(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::has_denorm_loss; }

    template<typename Tp>
    constexpr Tp
    infinity(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::infinity(); }

    template<typename Tp>
    constexpr Tp
    quiet_NaN(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::quiet_NaN(); }

    template<typename Tp>
    constexpr Tp
    signaling_NaN(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::signaling_NaN(); }

    template<typename Tp>
    constexpr Tp
    denorm_min(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::denorm_min(); }

    template<typename Tp>
    constexpr bool
    is_iec559(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_iec559; }

    template<typename Tp>
    constexpr bool
    is_bounded(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_bounded; }

    template<typename Tp>
    constexpr bool
    is_modulo(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::is_modulo; }

    template<typename Tp>
    constexpr bool
    traps(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::traps; }

    template<typename Tp>
    constexpr bool
    tinyness_before(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::tinyness_before; }

    template<typename Tp>
    constexpr std::float_round_style
    round_style(Tp = Tp{}) noexcept { return std::numeric_limits<Tp>::round_style; }

    // Extra bits to help with numerics...
    // These depend on constexpr math functions.

    template<typename Tp>
    inline Tp
    max_integer(Tp = Tp{}) noexcept { return std::ldexp(Tp{1}, digits(Tp{})); }

    template<typename Tp>
    inline Tp
    sqrt_max(Tp = Tp{}) noexcept { return std::sqrt(lim_max(Tp{})); }

    template<typename Tp>
    inline Tp
    cbrt_max(Tp = Tp{}) noexcept { return std::cbrt(lim_max(Tp{})); }

    template<typename Tp>
    inline Tp
    root_max(Tp root) noexcept { return std::pow(lim_max(Tp{}), 1 / root); }

    template<typename Tp>
    inline Tp
    log_max(Tp = Tp{}) noexcept { return std::log(lim_max(Tp{})); }

    template<typename Tp>
    inline Tp
    log10_max(Tp = Tp{}) noexcept { return std::log10(lim_max(Tp{})); }

    template<typename Tp>
    inline Tp
    sqrt_min(Tp = Tp{}) noexcept { return std::sqrt(lim_min(Tp{})); }

    template<typename Tp>
    inline Tp
    cbrt_min(Tp = Tp{}) noexcept { return std::cbrt(lim_min(Tp{})); }

    template<typename Tp>
    inline Tp
    root_min(Tp root) noexcept { return std::pow(lim_min(Tp{}), 1 / root); }

    template<typename Tp>
    inline Tp
    log_min(Tp = Tp{}) noexcept { return std::log(lim_min(Tp{})); }

    template<typename Tp>
    inline Tp
    log10_min(Tp = Tp{}) noexcept { return std::log10(lim_min(Tp{})); }

    template<typename Tp>
    inline Tp
    sqrt_eps(Tp = Tp{}) noexcept { return std::sqrt(epsilon(Tp{})); }

    template<typename Tp>
    inline Tp
    cbrt_eps(Tp = Tp{}) noexcept { return std::cbrt(epsilon(Tp{})); }

    template<typename Tp>
    inline Tp
    root_eps(Tp root) noexcept { return std::pow(epsilon(Tp{}), 1 / root); }

    template<typename Tp>
    inline Tp
    log_eps(Tp = Tp{}) noexcept { return std::log(epsilon(Tp{})); }

    template<typename Tp>
    inline Tp
    log10_eps(Tp = Tp{}) noexcept { return std::log10(epsilon(Tp{})); }
} // namespace special_functions

#endif // SPECIAL_FUNCTIONS_DETAIL_NUMERIC_LIMITS_H
