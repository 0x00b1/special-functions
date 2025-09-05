
/**
 * @file solver_laguerre.h Class declaration for the Laguerre solver.
 */

/**
 * @def  SOLVER_LAGUERRE_H
 *
 * @brief  A guard for the _LaguerreSolver class header.
 */
#ifndef SOLVER_LAGUERRE_H
#define SOLVER_LAGUERRE_H 1

#include <complex>

#include <polynomial/polynomial.h>

namespace emsr
{

  /**
   * A solver for complex-coefficient polynomials due to Laguerre.
   */
  template<typename Real>
    class LaguerreSolver
    {
    public:

      LaguerreSolver(Polynomial<std::complex<Real>>& P)
      : m_poly(P), m_num_iters{0}
      { }

      std::vector<std::complex<Real>> solve();

      std::complex<Real>
      step()
      {
	using cmplx = std::complex<Real>;

	const auto z0 = this->m_root_laguerre();

	Polynomial<cmplx> zpoly({-z0, cmplx{1}});
	this->m_poly /= zpoly;

	return z0;
      }

      int
      num_iters() const
      { return this->m_num_iters; }

      int
      max_num_iters() const
      { return this->m_max_iter(); }

      int
      num_steps_per_frac() const
      { return this->m_steps_per_frac; }

      const Polynomial<std::complex<Real>>&
      polynomial() const
      { return this->m_poly; }

      LaguerreSolver&
      num_steps_per_frac(int num)
      {
	this->m_steps_per_frac = num;
	return *this;
      }

    private:

      // Estimated fractional roundoff error.
      static constexpr Real s_eps = std::numeric_limits<Real>::epsilon();

      // Number of fractional values.
      static constexpr int s_num_fracs = 8;
      // Fractions used to break a limit cycle (in a heap).
      static constexpr Real
      s_frac[s_num_fracs + 1]
      {0.0, 0.5, 0.25, 0.75, 0.125, 0.375, 0.625, 0.875, 1.0};

      // Number of steps taken before trying a new fraction.
      int m_steps_per_frac = 10;

      int
      m_max_iter()
      { return this->m_steps_per_frac * s_num_fracs; }

      std::complex<Real> m_root_laguerre();

      Polynomial<std::complex<Real>> m_poly;

      int m_num_iters = 0;
    };

} // namespace emsr

#include <emsr/solver_laguerre.tcc>

#endif // SOLVER_LAGUERRE_H
