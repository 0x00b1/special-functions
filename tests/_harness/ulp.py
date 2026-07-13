"""Exact ULP distance between two float arrays of identical dtype.

IEEE-754 bit patterns are mapped onto a single monotonic integer line
(negative floats are reflected), and the distance is the absolute
difference of those ordinals. Computed in Python ints (object dtype) so
float64 never overflows. Callers must pre-filter NaN/inf.
"""

import numpy as np

_INT_VIEW = {np.dtype(np.float32): np.int32, np.dtype(np.float64): np.int64}


def _ordinal(a: np.ndarray) -> np.ndarray:
    bits = a.view(_INT_VIEW[a.dtype]).astype(object)
    sign_reflect = 1 << (a.dtype.itemsize * 8 - 1)
    return np.where(bits < 0, -(bits + sign_reflect), bits)


def ulp_distance(a: np.ndarray, b: np.ndarray) -> np.ndarray:
    a = np.ascontiguousarray(a)
    b = np.ascontiguousarray(b)
    if a.dtype != b.dtype or a.dtype not in _INT_VIEW:
        raise TypeError(f"need matching float32/float64 arrays, got {a.dtype}/{b.dtype}")
    return np.abs(_ordinal(a) - _ordinal(b))
