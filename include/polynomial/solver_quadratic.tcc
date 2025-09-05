
/**
 * @file solver_quadratic.tcc Class declaration for the quadratic solver.
 */

/**
 * @def  SOLVER_QUADRATIC_TCC
 *
 * @brief  A guard for the _QuadraticSolver class header.
 */
#ifndef SOLVER_QUADRATIC_TCC
#define SOLVER_QUADRATIC_TCC 1

namespace emsr
{

  /**
   * I think this is trying to factor out a quadratic
   * from a complex-coefficient polynomial.
   */
  template<typename Tp>
    Polynomial<std::complex<Tp>>
    QuadraticSolver<Tp>::m_root_quadratic()
    {
      using Cmplx = std::complex<Tp>;
      using Poly = Polynomial<Cmplx>;

      if (this->m_poly.degree() <= 2)
	return this->m_poly;

      this->m_num_iters = 0;

      Cmplx c, b;
      Poly q, qq, rem;
      for (int iter = 0; iter < this->m_max_iter; ++iter)
	{
	  ++this->m_num_iters;

	  Poly d({c, b, Cmplx{1}});

	  // First division: r, s.
	  divmod(this->m_poly, d, q, rem);
	  const auto s = rem[0];
	  const auto r = rem[1];

	  // Second division: partial r, s with respect to c.
	  divmod(q, d, qq, rem);
	  const auto sc = -rem[0];
	  const auto rc = -rem[1];
	  const auto sb = -c * rc;
	  const auto rb = -b * rc + sc;

	  // Solve 2x2 equation.
	  const auto dv = Tp{1} / (sb * rc - sc * rb);
	  const auto delb = ( r * sc - s * rc) * dv;
	  b += delb;
	  const auto delc = (-r * sb + s * rb) * dv;
	  c += delc;
	  if ((std::abs(delb) <= this->m_eps * std::abs(b)
	      || std::abs(b) < s_tiny)
           && (std::abs(delc) <= this->m_eps * std::abs(c)
	      || std::abs(c) < s_tiny))
	    return Poly({c, b, Cmplx{1}});
	}
      throw std::runtime_error("m_root_quadratic: Maximum number of iterations exceeded");
    }

} // namespace emsr

#endif // SOLVER_QUADRATIC_TCC
