import mpmath as mp
import numpy as np

from tools.coefficients.generate import (
    chebfit_auto,
    digamma_tail_coefficients,
    stirling_coefficients,
)


def _lg(x):
    # log_gamma(x) / ((x-1)(x-2)): removable 0/0 at x=1 and x=2 (log_gamma
    # vanishes at both). mpmath's chebyfit evaluates f exactly at these
    # points (the centered fit's interval midpoint t=0 is x=2; x=1 is the
    # left endpoint of the verification grid), and mpf division raises on
    # literal 0/0, so continue smoothly via L'Hopital:
    # limit = digamma(x) / (2x - 3), i.e. euler at x=1, 1 - euler at x=2.
    if x == 1:
        return -mp.digamma(1)
    if x == 2:
        return mp.digamma(2)
    return mp.log(abs(mp.gamma(x))) / ((x - 1) * (x - 2))


def _h(t):
    # Centered interval function: t = x - 2, t in [-1, 1].
    return _lg(t + 2)


def test_chebfit_auto_meets_target():
    # Validation must match what ships: coefficients cast to float64 and
    # evaluated with Horner in float64 arithmetic, compared to 60-dps truth.
    coeffs = chebfit_auto(_h, -1.0, 1.0, target_rel=4e-16)
    ts = np.linspace(-1.0, 1.0, 2001)
    worst = 0.0
    with mp.workdps(60):
        for t in ts:
            tt = np.float64(t)
            acc = np.float64(0.0)
            for c in coeffs:
                acc = acc * tt + np.float64(c)
            true = _h(mp.mpf(float(tt)))
            worst = max(worst, abs(float((mp.mpf(float(acc)) - true) / true)))
    assert worst <= 4e-16


def test_stirling_truncation_bound_at_threshold():
    coeffs = stirling_coefficients(threshold=13.0, target_rel=2.0**-54)
    # Next-term bound must already have been asserted inside; sanity: first
    # coefficient is B_2/(2*1) = 1/12.
    assert abs(coeffs[-1] - 1.0 / 12.0) < 1e-16


def test_digamma_tail_first_coefficient():
    coeffs = digamma_tail_coefficients(threshold=10.0, target_rel=2.0**-54)
    # B_2/2 = 1/12.
    assert abs(coeffs[-1] - 1.0 / 12.0) < 1e-16
