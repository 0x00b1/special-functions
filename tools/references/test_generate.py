import numpy as np

from tools.references.generate import FUNCTIONS, build_table


def test_log_gamma_known_values():
    x, expected = build_table("log_gamma", np.float64)
    # Table must contain exact probe points with correctly-rounded truth.
    idx = np.where(x == 2.0)[0]
    assert idx.size == 1 and expected[idx][0] == 0.0
    idx = np.where(x == -1.0)[0]
    assert idx.size == 1 and np.isposinf(expected[idx][0])


def test_digamma_known_values():
    x, expected = build_table("digamma", np.float64)
    idx = np.where(x == 1.0)[0]
    # psi(1) = -euler_gamma, correctly rounded.
    assert expected[idx][0] == -0.5772156649015329
    idx = np.where((x == 0.0) & ~np.signbit(x))[0]
    assert np.isneginf(expected[idx][0])
    idx = np.where((x == 0.0) & np.signbit(x))[0]
    assert np.isposinf(expected[idx][0])
    idx = np.where(x == -2.0)[0]
    assert np.isnan(expected[idx][0])


def test_float32_tables_are_float32():
    x, expected = build_table("log_gamma", np.float32)
    assert x.dtype == np.float32 and expected.dtype == np.float32
