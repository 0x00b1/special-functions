"""Self-consistency identities, no mpmath needed at test time."""

import numpy as np
import pytest

SEED = 20260713


@pytest.fixture(scope="module")
def xs():
    rng = np.random.default_rng(SEED)
    x = rng.uniform(0.1, 40.0, 5000)
    return x[np.abs(x - np.round(x)) > 1e-3]  # stay clear of poles/zeros of factors


def test_log_gamma_recurrence(sf_cpu, xs):
    # log|Gamma(x+1)| = log|Gamma(x)| + log(x) for x > 0.
    lhs = sf_cpu.call("log_gamma", "float64", xs + 1.0)
    rhs = sf_cpu.call("log_gamma", "float64", xs) + np.log(xs)
    np.testing.assert_allclose(lhs, rhs, rtol=5e-14, atol=5e-14)


def test_digamma_recurrence(sf_cpu, xs):
    # psi(x+1) = psi(x) + 1/x for x > 0.
    lhs = sf_cpu.call("digamma", "float64", xs + 1.0)
    rhs = sf_cpu.call("digamma", "float64", xs) + 1.0 / xs
    np.testing.assert_allclose(lhs, rhs, rtol=5e-13, atol=5e-13)


def test_digamma_reflection(sf_cpu, xs):
    # psi(1-x) - psi(x) = pi * cot(pi * x); test on shifted negatives.
    x = -xs[:1000]
    frac = np.abs(x - np.round(x))
    x = x[(frac > 1e-2) & (frac < 0.49)]
    lhs = sf_cpu.call("digamma", "float64", 1.0 - x) - sf_cpu.call("digamma", "float64", x)
    rhs = np.pi / np.tan(np.pi * (x - np.round(x)))
    np.testing.assert_allclose(lhs, rhs, rtol=1e-10)


def test_float32_matches_float64_coarsely(sf_cpu, xs):
    # fp32 path is an independent implementation; it must agree with the
    # fp64 path to fp32 precision on benign arguments.
    for fn in ("log_gamma", "digamma"):
        f64 = sf_cpu.call(fn, "float64", xs).astype(np.float32)
        f32 = sf_cpu.call(fn, "float32", xs.astype(np.float32))
        np.testing.assert_allclose(f32, f64, rtol=1e-5, atol=1e-6)
