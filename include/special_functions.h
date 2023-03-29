#ifndef SPECIAL_FUNCTIONS_H
#define SPECIAL_FUNCTIONS_H

#include <complex>
#include <numbers>

#include "special_functions/detail/fp_type_util.h"

#include <special_functions/airy_ai.h>
#include <special_functions/airy_bi.h>
#include <special_functions/associated_laguerre_polynomial_l.h>
#include <special_functions/associated_legendre_p.h>
#include <special_functions/associated_legendre_q.h>
#include <special_functions/barnes_g.h>
#include <special_functions/bell_polynomial_b.h>
#include <special_functions/bernoulli_number.h>
#include <special_functions/bernoulli_polynomial_b.h>
#include <special_functions/bessel_j.h>
#include <special_functions/bessel_y.h>
#include <special_functions/beta.h>
#include <special_functions/binomial_coefficient.h>
#include <special_functions/bose_einstein_integral_g.h>
#include <special_functions/bulirsch_elliptic_integral_cel.h>
#include <special_functions/bulirsch_elliptic_integral_el1.h>
#include <special_functions/bulirsch_elliptic_integral_el2.h>
#include <special_functions/bulirsch_elliptic_integral_el3.h>
#include <special_functions/carlson_elliptic_r_c.h>
#include <special_functions/carlson_elliptic_r_d.h>
#include <special_functions/carlson_elliptic_r_f.h>
#include <special_functions/carlson_elliptic_r_g.h>
#include <special_functions/carlson_elliptic_r_j.h>
#include <special_functions/chebyshev_polynomial_t.h>
#include <special_functions/chebyshev_polynomial_u.h>
#include <special_functions/chebyshev_polynomial_v.h>
#include <special_functions/chebyshev_polynomial_w.h>
#include <special_functions/clausen_cl.h>
#include <special_functions/clausen_sl.h>
#include <special_functions/complete_carlson_elliptic_r_f.h>
#include <special_functions/complete_carlson_elliptic_r_g.h>
#include <special_functions/complete_elliptic_integral_e.h>
#include <special_functions/complete_elliptic_integral_k.h>
#include <special_functions/complete_elliptic_integral_pi.h>
#include <special_functions/complete_legendre_elliptic_integral_d.h>
#include <special_functions/confluent_hypergeometric_0_f_1.h>
#include <special_functions/cos_pi.h>
#include <special_functions/cosh_pi.h>
#include <special_functions/cosine_integral_ci.h>
#include <special_functions/dawson_d.h>
#include <special_functions/debye_d.h>
#include <special_functions/digamma.h>
#include <special_functions/dilogarithm_li_2.h>
#include <special_functions/dirichlet_beta.h>
#include <special_functions/dirichlet_eta.h>
#include <special_functions/dirichlet_lambda.h>
#include <special_functions/double_factorial.h>
#include <special_functions/euler_number.h>
#include <special_functions/eulerian_number_1.h>
#include <special_functions/eulerian_number_2.h>
#include <special_functions/exp_airy_ai.h>
#include <special_functions/exp_airy_bi.h>
#include <special_functions/exp_modified_bessel_i.h>
#include <special_functions/exp_modified_bessel_k.h>
#include <special_functions/exponential_integral_e.h>
#include <special_functions/exponential_integral_e1.h>
#include <special_functions/exponential_integral_ei.h>
#include <special_functions/factorial.h>
#include <special_functions/falling_factorial.h>
#include <special_functions/fermi_dirac_integral_f.h>
#include <special_functions/fresnel_cosine_integral_c.h>
#include <special_functions/fresnel_sine_integral_s.h>
#include <special_functions/gamma.h>
#include <special_functions/gauss_hypergeometric_2_f_1.h>
#include <special_functions/gegenbauer_polynomial_c.h>
#include <special_functions/hankel_h_1.h>
#include <special_functions/hankel_h_2.h>
#include <special_functions/harmonic_number.h>
#include <special_functions/hermite_polynomial_h.h>
#include <special_functions/hermite_polynomial_he.h>
#include <special_functions/heuman_lambda.h>
#include <special_functions/hurwitz_zeta.h>
#include <special_functions/hyperbolic_cosine_integral_chi.h>
#include <special_functions/hyperbolic_sine_integral_shi.h>
#include <special_functions/incomplete_beta.h>
#include <special_functions/incomplete_elliptic_integral_e.h>
#include <special_functions/incomplete_elliptic_integral_f.h>
#include <special_functions/incomplete_elliptic_integral_pi.h>
#include <special_functions/incomplete_legendre_elliptic_integral_d.h>
#include <special_functions/jacobi_polynomial_p.h>
#include <special_functions/jacobi_theta_1.h>
#include <special_functions/jacobi_theta_2.h>
#include <special_functions/jacobi_theta_3.h>
#include <special_functions/jacobi_theta_4.h>
#include <special_functions/jacobi_zeta.h>
#include <special_functions/kummer_confluent_hypergeometric_1_f_1.h>
#include <special_functions/laguerre_polynomial_l.h>
#include <special_functions/lah_number.h>
#include <special_functions/legendre_polynomial_p.h>
#include <special_functions/legendre_q.h>
#include <special_functions/log_binomial_coefficient.h>
#include <special_functions/log_binomial_coefficient_sign.h>
#include <special_functions/log_double_factorial.h>
#include <special_functions/log_factorial.h>
#include <special_functions/log_falling_factorial.h>
#include <special_functions/log_gamma.h>
#include <special_functions/log_gamma_sign.h>
#include <special_functions/log_rising_factorial.h>
#include <special_functions/logarithmic_integral_li.h>
#include <special_functions/lower_incomplete_gamma.h>
#include <special_functions/mittag_leffler_e.h>
#include <special_functions/modified_bessel_i.h>
#include <special_functions/modified_bessel_k.h>
#include <special_functions/neville_theta_c.h>
#include <special_functions/neville_theta_d.h>
#include <special_functions/neville_theta_n.h>
#include <special_functions/neville_theta_s.h>
#include <special_functions/nome_q.h>
#include <special_functions/numeric_limits.h>
#include <special_functions/owens_t.h>
#include <special_functions/polar_pi.h>
#include <special_functions/polygamma.h>
#include <special_functions/polylogarithm_li.h>
#include <special_functions/prime_number.h>
#include <special_functions/q_beta.h>
#include <special_functions/q_factorial.h>
#include <special_functions/q_gamma.h>
#include <special_functions/radial_polynomial_r.h>
#include <special_functions/reciprocal_gamma.h>
#include <special_functions/regularized_gamma_p.h>
#include <special_functions/regularized_gamma_q.h>
#include <special_functions/riemann_zeta.h>
#include <special_functions/rising_factorial.h>
#include <special_functions/shifted_chebyshev_polynomial_t.h>
#include <special_functions/shifted_chebyshev_polynomial_u.h>
#include <special_functions/shifted_chebyshev_polynomial_v.h>
#include <special_functions/shifted_chebyshev_polynomial_w.h>
#include <special_functions/sin_pi.h>
#include <special_functions/sinc.h>
#include <special_functions/sinc_pi.h>
#include <special_functions/sine_integral_si.h>
#include <special_functions/sinh_pi.h>
#include <special_functions/sinhc.h>
#include <special_functions/sinhc_pi.h>
#include <special_functions/spherical_bessel_j.h>
#include <special_functions/spherical_bessel_y.h>
#include <special_functions/spherical_hankel_h_1.h>
#include <special_functions/spherical_hankel_h_2.h>
#include <special_functions/spherical_harmonic_y.h>
#include <special_functions/spherical_legendre_y.h>
#include <special_functions/spherical_modified_bessel_i.h>
#include <special_functions/spherical_modified_bessel_k.h>
#include <special_functions/stirling_number_s_1.h>
#include <special_functions/stirling_number_s_2.h>
#include <special_functions/tan_pi.h>
#include <special_functions/tanh_pi.h>
#include <special_functions/theta_1.h>
#include <special_functions/theta_2.h>
#include <special_functions/theta_3.h>
#include <special_functions/theta_4.h>
#include <special_functions/tricomi_confluent_hypergeometric_u.h>
#include <special_functions/trigamma.h>
#include <special_functions/upper_incomplete_gamma.h>
#include <special_functions/zernike_polynomial_z.h>

#endif // SPECIAL_FUNCTIONS_H
