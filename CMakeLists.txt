cmake_minimum_required(VERSION 3.23)

project(special_functions)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_library(
        special_functions
        INTERFACE
        include/special_functions.h
        include/special_functions/detail/math_util.h
        include/special_functions/detail/airy_ai.h include/special_functions/detail/airy_bi.h include/special_functions/detail/bernoulli_number.h include/special_functions/detail/bernoulli_polynomial_b.h include/special_functions/detail/bessel_j.h include/special_functions/detail/bessel_y.h include/special_functions/detail/beta.h include/special_functions/detail/bulirsch_elliptic_integral_cel.h include/special_functions/detail/bulirsch_elliptic_integral_el1.h include/special_functions/detail/bulirsch_elliptic_integral_el2.h include/special_functions/detail/bulirsch_elliptic_integral_el3.h include/special_functions/detail/chebyshev_polynomial_t.h include/special_functions/detail/chebyshev_polynomial_u.h include/special_functions/detail/chebyshev_polynomial_v.h include/special_functions/detail/chebyshev_polynomial_w.h include/special_functions/detail/complete_elliptic_integral_e.h include/special_functions/detail/complete_elliptic_integral_k.h include/special_functions/detail/complete_elliptic_integral_pi.h include/special_functions/detail/complete_legendre_elliptic_integral_d.h include/special_functions/detail/dawson_d.h include/special_functions/detail/euler_number.h include/special_functions/detail/eulerian_number_1.h include/special_functions/detail/eulerian_number_2.h include/special_functions/detail/exp_airy_ai.h include/special_functions/detail/exp_airy_bi.h include/special_functions/detail/exp_modified_bessel_i.h include/special_functions/detail/exp_modified_bessel_k.h include/special_functions/detail/fresnel_cosine_integral_c.h include/special_functions/detail/fresnel_sine_integral_s.h include/special_functions/detail/hankel_h_1.h include/special_functions/detail/hankel_h_2.h include/special_functions/detail/hermite_polynomial_h.h include/special_functions/detail/hermite_polynomial_he.h include/special_functions/detail/hyperbolic_cosine_integral_chi.h include/special_functions/detail/hyperbolic_sine_integral_shi.h include/special_functions/detail/incomplete_elliptic_integral_e.h include/special_functions/detail/incomplete_elliptic_integral_f.h include/special_functions/detail/incomplete_elliptic_integral_pi.h include/special_functions/detail/incomplete_legendre_elliptic_integral_d.h include/special_functions/detail/jacobi_polynomial_p.h include/special_functions/detail/logarithmic_integral_li.h include/special_functions/detail/mittag_leffler_e.h include/special_functions/detail/modified_bessel_i.h include/special_functions/detail/modified_bessel_k.h include/special_functions/detail/spherical_modified_bessel_i.h include/special_functions/detail/spherical_modified_bessel_k.h include/special_functions/detail/shifted_chebyshev_polynomial_t.h include/special_functions/detail/shifted_chebyshev_polynomial_u.h include/special_functions/detail/shifted_chebyshev_polynomial_v.h include/special_functions/detail/shifted_chebyshev_polynomial_w.h include/special_functions/detail/spherical_bessel_j.h include/special_functions/detail/spherical_bessel_y.h include/special_functions/detail/spherical_hankel_h_1.h include/special_functions/detail/spherical_hankel_h_2.h include/special_functions/detail/stirling_number_s_1.h include/special_functions/detail/stirling_number_s_2.h include/special_functions/detail/zernike_polynomial_z.h include/special_functions/detail/associated_laguerre_polynomial_l.h include/special_functions/detail/associated_legendre_p.h include/special_functions/detail/associated_legendre_q.h include/special_functions/detail/barnes_g.h include/special_functions/detail/bell_polynomial_b.h include/special_functions/detail/bose_einstein_integral_g.h include/special_functions/detail/carlson_elliptic_r_c.h include/special_functions/detail/carlson_elliptic_r_d.h include/special_functions/detail/carlson_elliptic_r_f.h include/special_functions/detail/carlson_elliptic_r_g.h include/special_functions/detail/carlson_elliptic_r_j.h include/special_functions/detail/clausen_cl.h include/special_functions/detail/clausen_sl.h include/special_functions/detail/complete_carlson_elliptic_r_f.h include/special_functions/detail/complete_carlson_elliptic_r_g.h include/special_functions/detail/confluent_hypergeometric_0_f_1.h include/special_functions/detail/debye_d.h include/special_functions/detail/dilogarithm_li_2.h include/special_functions/detail/dirichlet_beta.h include/special_functions/detail/dirichlet_eta.h include/special_functions/detail/dirichlet_lambda.h include/special_functions/detail/exponential_integral_e.h include/special_functions/detail/exponential_integral_e1.h include/special_functions/detail/exponential_integral_ei.h include/special_functions/detail/fermi_dirac_integral_f.h include/special_functions/detail/gauss_hypergeometric_2_f_1.h include/special_functions/detail/gegenbauer_polynomial_c.h include/special_functions/detail/heuman_lambda.h include/special_functions/detail/hurwitz_zeta.h include/special_functions/detail/incomplete_beta.h include/special_functions/detail/jacobi_theta_1.h include/special_functions/detail/jacobi_theta_2.h include/special_functions/detail/jacobi_theta_3.h include/special_functions/detail/jacobi_theta_4.h include/special_functions/detail/jacobi_zeta.h include/special_functions/detail/kummer_confluent_hypergeometric_1_f_1.h include/special_functions/detail/laguerre_polynomial_l.h include/special_functions/detail/lah_number.h include/special_functions/detail/legendre_polynomial_p.h include/special_functions/detail/legendre_q.h include/special_functions/detail/neville_theta_c.h include/special_functions/detail/neville_theta_d.h include/special_functions/detail/neville_theta_n.h include/special_functions/detail/neville_theta_s.h include/special_functions/detail/nome_q.h include/special_functions/detail/owens_t.h include/special_functions/detail/polylogarithm_li.h include/special_functions/detail/radial_polynomial_r.h include/special_functions/detail/theta_1.h include/special_functions/detail/theta_2.h include/special_functions/detail/theta_3.h include/special_functions/detail/theta_4.h include/special_functions/detail/tricomi_confluent_hypergeometric_u.h include/special_functions/detail/trigamma.h include/special_functions/detail/spherical_legendre_y.h include/special_functions/detail/spherical_harmonic_y.h include/special_functions/detail/riemann_zeta.h include/special_functions/detail/q_gamma.h include/special_functions/detail/q_factorial.h include/special_functions/detail/q_beta.h include/special_functions/detail/prime_number.h include/special_functions/detail/polar_pi.h include/special_functions/detail/log_gamma_sign.h include/special_functions/detail/log_binomial_coefficient_sign.h include/special_functions/sinc.h include/special_functions/sinc_pi.h include/special_functions/sinhc.h include/special_functions/sinhc_pi.h include/special_functions/numbers.h)

target_include_directories(special_functions INTERFACE include)

enable_testing()

add_executable(
        special_functions_test
        test/special_functions_test.cpp
)

target_link_libraries(
        special_functions_test
        GTest::gtest_main
        special_functions
)

include(GoogleTest)

gtest_discover_tests(special_functions_test)
