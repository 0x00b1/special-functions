
/**
 * @file solver_quadratic.h Class declaration for the quadratic solver.
 */

/**
 * @def  SOLVER_QUADRATIC_H
 *
 * @brief  A guard for the _QuadraticSolver class header.
 */
#ifndef SOLVER_QUADRATIC_H
#define SOLVER_QUADRATIC_H 1

#include <complex>

#include <polynomial/polynomial.h>

namespace emsr
{

  /**
   * A solver for complex-coefficient polynomials due to Laguerre.
   */
  template<typename Real>
    class QuadraticSolver
    {
    public:

      QuadraticSolver(Polynomial<std::complex<Real>>& P)
      : m_poly(P), m_num_iters{0}
      { }

      //std::vector<Solution<Real>> solve();
      std::vector<std::complex<Real>> solve();

      Polynomial<std::complex<Real>>
      step()
      {
	const auto q = this->m_root_quadratic();
	this->m_poly.deflate(q, Real{10} * s_eps);
	return q;
      }

      int
      num_iters() const
      { return this->m_num_iters; }

      int
      max_num_iters() const
      { return this->m_max_num_iters; }

      const Polynomial<std::complex<Real>>&
      polynomial() const
      { return this->m_poly; }

    private:

      // Estimated fractional roundoff error.
      static constexpr Real s_eps = std::numeric_limits<Real>::epsilon();
      static constexpr Real s_tiny = Real{10} * s_eps;

      // Fractional roundoff error.
      Real m_eps = Real{100} * s_eps;

      int m_max_iter = 50;

      Polynomial<std::complex<Real>> m_root_quadratic();

      Polynomial<std::complex<Real>> m_poly;

      int m_num_iters = 0;
    };

} // namespace emsr

#include <emsr/solver_quadratic.tcc>

#endif // SOLVER_QUADRATIC_H
