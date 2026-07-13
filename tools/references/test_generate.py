import mpmath as mp
import numpy as np

from tools.references.generate import FUNCTIONS, _round_to, build_table


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


def test_round_to_float32_ties():
    # Reviewer's reproduction: the exact tie midpoint between the two
    # adjacent float32 values printed as 0.017754791 (0x3c91727f) and
    # 0.017754793 (0x3c917280). Built from the *exact* float32 values
    # (widened to float64/mpf, which is exact) rather than from the bare
    # decimal literals -- averaging the literals directly lands ~0.13 ULP
    # off the true float32 boundary and is not an actual tie.
    lo = np.float32(0.017754791)
    hi = np.float32(0.017754793)
    assert hex(int(lo.view(np.uint32))) == "0x3c91727f"
    assert hex(int(hi.view(np.uint32))) == "0x3c917280"

    with mp.workdps(60):
        a = mp.mpf(float(lo))
        b = mp.mpf(float(hi))
        mid = (a + b) / 2

        # Just below the tie midpoint must round down (the old
        # str -> float64 -> float32 path double-rounded this up to `hi`).
        just_below = mid - mp.mpf(2) ** -60
        assert _round_to(just_below, np.float32) == lo

        # Exactly at the tie: nearest-even wins. Compute which neighbor
        # has the even mantissa rather than hardcoding it.
        lo_even = int(lo.view(np.uint32)) & 1 == 0
        expected = lo if lo_even else hi
        assert _round_to(mid, np.float32) == expected

    # Overflow rule: beyond max-float32 + half a ULP rounds to infinity.
    assert _round_to(mp.mpf("1e60"), np.float32) == np.inf
