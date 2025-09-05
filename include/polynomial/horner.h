#ifndef HORNER_H
#define HORNER_H 1

#include <type_traits>

namespace emsr
{

/**
 * Perform compile-time evaluation of a constant zero-order polynomial.
 */
template<typename ArgT, typename Coef0>
  constexpr std::conditional_t<std::is_integral<ArgT>::value, double, ArgT>
  horner(ArgT, Coef0 c0)
  {
    using arg_t = std::conditional_t<std::is_integral<ArgT>::value,
				     double, ArgT>;
    return arg_t(c0);
  }

/**
 * Perform compile-time evaluation of a constant polynomial.
 * The polynomial coefficients are lowest-order first.
 */
template<typename ArgT, typename Coef0, typename... Coef>
  constexpr std::conditional_t<std::is_integral<ArgT>::value, double, ArgT>
  horner(ArgT x, Coef0 c0, Coef... c)
  {
    using arg_t = std::conditional_t<std::is_integral<ArgT>::value,
				     double, ArgT>;
    return arg_t(c0) + x * horner(x, c...);
  }


/**
 * Perform compile-time evaluation of a constant zero-order polynomial.
 * The polynomial coefficients are highest-order first.
 */
template<typename ArgT, typename Coef0>
  constexpr std::conditional_t<std::is_integral<ArgT>::value, double, ArgT>
  horner_big_end(ArgT, Coef0 c0)
  {
    using arg_t = std::conditional_t<std::is_integral<ArgT>::value,
				     double, ArgT>;
    return arg_t(c0);
  }

/**
 * Perform compile-time evaluation of a constant first-order polynomial.
 * The polynomial coefficients are highest-order first.
 */
template<typename ArgT, typename Coef1, typename Coef0>
  constexpr std::conditional_t<std::is_integral<ArgT>::value, double, ArgT>
  horner_big_end(ArgT x, Coef1 c1, Coef0 c0)
  {
    using arg_t = std::conditional_t<std::is_integral<ArgT>::value,
				     double, ArgT>;
    return horner_big_end(x, x * arg_t(c1) + arg_t(c0));
  }

/**
 * Perform compile-time evaluation of a constant polynomial.
 * The polynomial coefficients are highest-order first.
 */
template<typename ArgT, typename CoefN, typename CoefNm1, typename... Coef>
  constexpr std::conditional_t<std::is_integral<ArgT>::value, double, ArgT>
  horner_big_end(ArgT x, CoefN cn, CoefNm1 cnm1, Coef... c)
  {
    using arg_t = std::conditional_t<std::is_integral<ArgT>::value,
				     double, ArgT>;
    return horner_big_end(x, x * arg_t(cn) + arg_t(cnm1), c...);
  }

} // namespace emsr

#endif // HORNER_H
