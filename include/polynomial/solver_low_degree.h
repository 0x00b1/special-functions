


/**
 * @file solver_low_degree.h
 *
 * This file is a GNU extension to the Standard C++ Library.
 *
 * This file contains the declarations of free functions for solving
 * quadratic, cubic, and quartic equations with real coefficients.
 */

/**
 * @def  SOLVER_LOW_DEGREE_H
 *
 * @brief  A guard for the low-degree polynomial solver functions header.
 */
#ifndef SOLVER_LOW_DEGREE_H
#define SOLVER_LOW_DEGREE_H 1

#include <array>

#include <polynomial/solution.h>

namespace emsr
{

  template<std::size_t Dim, typename Iter, typename NumTp>
    NumTp
    refine_solution_newton(NumTp z, const Iter& CC);

  template<std::size_t Dim, typename Iter, typename NumTp>
    NumTp
    refine_solution_halley(NumTp z, const Iter& CC);

  template<typename Real, typename Iter>
    std::array<Solution<Real>, 2>
    quadratic(const Iter& coef);

  template<typename Real>
    inline std::array<Solution<Real>, 2>
    quadratic(Real c0, Real c1, Real c2)
    {
      return quadratic<Real>(std::array<Real, 3>{c0, c1, c2});
    }

  template<typename Real, typename Iter>
    std::array<Solution<Real>, 3>
    cubic(const Iter& coef);

  template<typename Real>
    inline std::array<Solution<Real>, 3>
    cubic(Real c0, Real c1, Real c2, Real c3)
    {
      return cubic<Real>(std::array<Real, 4>{c0, c1, c2, c3});
    }

  template<typename Real, typename Iter>
    std::array<Solution<Real>, 4>
    quartic(const Iter& coef);

  template<typename Real>
    inline std::array<Solution<Real>, 4>
    quartic(Real c0, Real c1, Real c2, Real c3, Real c4)
    {
      return quartic<Real>(std::array<Real, 5>{c0, c1, c2, c3, c4});
    }

} // namespace emsr

#include <emsr/solver_low_degree.tcc>

#endif // SOLVER_LOW_DEGREE_H
