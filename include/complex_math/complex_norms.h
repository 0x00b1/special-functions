#ifndef COMPLEX_NORMS_H
#define COMPLEX_NORMS_H 1

#include <complex>

namespace emsr
{

  /**
   * Return the L1 norm modulus or the Manhattan metric distance of a complex number.
   */
  template<typename Tp>
    inline constexpr Tp
    l1_norm(const std::complex<Tp>& z)
    { return std::abs(std::real(z)) + std::abs(std::imag(z)); }

  /**
   * Return the L2 norm modulus or the Euclidean metric distance of a complex number.
   */
  template<typename Tp>
    inline constexpr Tp
    l2_norm(const std::complex<Tp>& z)
    { return std::norm(z); }

  /**
   * Return the Linf norm modulus of a complex number.
   */
  template<typename Tp>
    inline constexpr Tp
    linf_norm(const std::complex<Tp>& z)
    { return std::max(std::abs(std::real(z)), std::abs(std::imag(z))); }


  /**
   * Return the L1 norm modulus or the Manhattan metric distance of a real number.
   */
  template<typename Tp>
    inline constexpr Tp
    l1_norm(Tp x)
    { return std::abs(x); }

  /**
   * Return the L2 norm modulus or the Euclidean metric distance of a real number.
   */
  template<typename Tp>
    inline constexpr Tp
    l2_norm(Tp x)
    { return std::abs(x); }

  /**
   * Return the Linf norm modulus of a real number.
   */
  template<typename Tp>
    inline constexpr Tp
    linf_norm(Tp x)
    { return std::abs(x); }

} // namespace emsr

#endif // COMPLEX_NORMS_H
