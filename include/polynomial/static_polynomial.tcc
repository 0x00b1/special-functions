/**
 * @file static_polynomial.tcc Class outline definitions for static polynomial.
 */

/**
 * @def  STATIC_POLYNOMIAL_TCC
 *
 * @brief  A guard for the static_polynomial class header.
 */
#ifndef STATIC_POLYNOMIAL_TCC
#define STATIC_POLYNOMIAL_TCC 1

#include <iostream>

namespace emsr
{

  /**
   * Write a polynomial to a stream.
   * The format is a parenthesized comma-delimited list of coefficients.
   */
  template<typename CharT, typename Traits, typename Tp, std::size_t Size>
    std::basic_ostream<CharT, Traits>&
    operator<<(std::basic_ostream<CharT, Traits>& os,
	       const StaticPolynomial<Tp, Size>& poly)
    {
      int old_prec = os.precision(std::numeric_limits<Tp>::max_digits10);
      os << "(";
      for (size_t i = 0; i < poly.degree(); ++i)
        os << poly.coefficient(i) << ",";
      os << poly.coefficient(poly.degree());
      os << ")";
      os.precision(old_prec);
      return os;
    }

  /**
   * Divide two polynomials returning the quotient and remainder.
   */
  template<typename Tp, std::size_t SizeN, std::size_t SizeD>
    constexpr divmod_t<Tp, SizeN, SizeD>
    divmod(StaticPolynomial<Tp, SizeN> num,
	   StaticPolynomial<Tp, SizeD> den)
    {
      constexpr auto DegN = num.degree();
      constexpr auto DegD = den.degree();
      auto rem = num;
      auto quo = StaticPolynomial<Tp, SizeN>{};
      if (DegD <= DegN)
	{
	  for (std::ptrdiff_t k = DegN - DegD; k >= 0; --k)
	    {
	      quo.coefficient(k, rem.coefficient(DegD + k)
				   / den.coefficient(DegD));
	      for (int j = DegD + k - 1; j >= k; --j)
		rem.coefficient(j, rem.coefficient(j)
				       - quo.coefficient(k)
				       * den.coefficient(j - k));
	    }
	}
      divmod_t<Tp, SizeN, SizeD> ret;
      for (std::size_t i = 0ULL; i < divmod_t<Tp, SizeN, SizeD>::SizeQuo; ++i)
        ret.quo[i] = quo[i];
      for (std::size_t i = 0ULL; i < divmod_t<Tp, SizeN, SizeD>::SizeRem; ++i)
        ret.rem[i] = rem[i];
      return ret;
    }

} // namespace emsr

#endif // STATIC_POLYNOMIAL_TCC
