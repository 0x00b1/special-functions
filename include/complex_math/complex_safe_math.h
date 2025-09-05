#ifndef COMPLEX_SAFE_MATH_H
#define COMPLEX_SAFE_MATH_H 1

#include <complex>

namespace emsr
{

  /**
   * Carefully compute @c z1/z2 avoiding overflow and destructive underflow.
   * If the quotient is successfully computed it is returned.
   * Otherwise, std::runtime_error is thrown.
   */
  template<typename Tp>
    std::complex<Tp>
    safe_div(const std::complex<Tp>& z1, const std::complex<Tp>& z2);

  /**
   * Carefully compute @c s/z2 avoiding overflow and destructive underflow.
   * If the quotient is successfully computed it is returned.
   * Otherwise, @c false is returned and the quotient is not.
   */
  template<typename _Sp, typename Tp>
    inline std::complex<Tp>
    safe_div(_Sp s, const std::complex<Tp>& z)
    { return safe_div(std::complex<Tp>(s), z); }

  /**
   * Carefully compute @c z1/s avoiding overflow and destructive underflow.
   * If the quotient is successfully computed it is returned.
   * Otherwise, @c false is returned and the quotient is not.
   */
  template<typename _Sp, typename Tp>
    inline std::complex<Tp>
    safe_div(const std::complex<Tp>& z, _Sp s)
    { return safe_div(z, std::complex<Tp>(s)); }

  /**
   * @brief Carefully compute and return @c s1*s2 avoiding overflow.
   *	   If the product can be successfully computed it is returned.
   *	   Otherwise, std::runtime_error is thrown.
   */
  template<typename Tp>
    Tp
    safe_mul(Tp s1, Tp s2);

  /**
   * Carefully compute @c z1*z2 avoiding overflow.
   * If the product is successfully computed it is returned.
   * Otherwise, std::runtime_error is thrown.
   */
  template<typename Tp>
    std::complex<Tp>
    safe_mul(const std::complex<Tp>& z1, const std::complex<Tp>& z2);

  /**
   * Carefully compute @c s*z avoiding overflow.
   * If the product is successfully computed it is returned.
   * Otherwise, std::runtime_error is thrown.
   */
  template<typename _Sp, typename Tp>
    inline std::complex<Tp>
    safe_mul(_Sp s, const std::complex<Tp>& z)
    { return safe_mul(std::complex<Tp>(s), z); }

  /**
   * Carefully compute @c z*s avoiding overflow.
   * If the product is successfully computed it is returned.
   * Otherwise, std::runtime_error is thrown.
   */
  template<typename _Sp, typename Tp>
    inline std::complex<Tp>
    safe_mul(const std::complex<Tp>& z, _Sp s)
    { return safe_mul(z, std::complex<Tp>(s)); }

  /**
   * Carefully compute @c z*z avoiding overflow.
   * If the square is successfully computed it is returned.
   * Otherwise, std::runtime_error is thrown.
   */
  template<typename Tp>
    std::complex<Tp>
    safe_sqr(const std::complex<Tp>& z);

} // namespace emsr

#include <emsr/complex_safe_math.tcc>

#endif // COMPLEX_SAFE_MATH_H
