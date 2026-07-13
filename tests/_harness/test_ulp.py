import numpy as np

from tests._harness.ulp import ulp_distance


def test_zero_distance():
    x = np.array([1.0, -2.5, 0.0], dtype=np.float64)
    assert (ulp_distance(x, x.copy()) == 0).all()


def test_adjacent_float64():
    a = np.array([1.0], dtype=np.float64)
    b = np.nextafter(a, np.inf)
    assert ulp_distance(a, b)[0] == 1
    assert ulp_distance(b, a)[0] == 1


def test_adjacent_float32():
    a = np.array([1.0], dtype=np.float32)
    b = np.nextafter(a, -np.inf, dtype=np.float32)
    assert ulp_distance(a, b)[0] == 1


def test_across_zero():
    # -0.0 and +0.0 are 0 ULP apart; smallest subnormals straddle zero.
    a = np.array([-0.0], dtype=np.float64)
    b = np.array([0.0], dtype=np.float64)
    assert ulp_distance(a, b)[0] == 0
    tiny = np.array([5e-324], dtype=np.float64)
    assert ulp_distance(-tiny, tiny)[0] == 2


def test_large_gap():
    a = np.array([1.0], dtype=np.float64)
    b = np.array([2.0], dtype=np.float64)
    assert ulp_distance(a, b)[0] == 2**52
