"""Builds special_functions_cpu/*.cpp into a dylib with clang++ and exposes
a ctypes dispatcher fixture. Rebuilds only when sources change."""

import ctypes
import hashlib
import subprocess
from pathlib import Path

import numpy as np
import pytest

ROOT = Path(__file__).resolve().parents[1]
CPU_DIR = ROOT / "special_functions_cpu"
BUILD_DIR = ROOT / "build"

_CTYPES = {
    "float64": (np.float64, ctypes.POINTER(ctypes.c_double)),
    "float32": (np.float32, ctypes.POINTER(ctypes.c_float)),
}


def _build_dylib() -> Path:
    sources = sorted(CPU_DIR.glob("*.cpp"))
    headers = sorted(CPU_DIR.glob("*.h")) + sorted((CPU_DIR / "generated").glob("*.h"))
    digest = hashlib.sha256()
    for p in sources + headers:
        digest.update(p.read_bytes())
    lib_path = BUILD_DIR / f"libsf_cpu_{digest.hexdigest()[:16]}.dylib"
    if not lib_path.exists():
        BUILD_DIR.mkdir(exist_ok=True)
        cmd = [
            "clang++", "-std=c++17", "-O2", "-fno-fast-math", "-fPIC",
            "-shared", "-o", str(lib_path), *map(str, sources),
        ]
        subprocess.run(cmd, check=True)
    return lib_path


class _Dispatcher:
    def __init__(self, lib: ctypes.CDLL):
        self._lib = lib

    def call(self, fn: str, dtype: str, x: np.ndarray) -> np.ndarray:
        np_dtype, ptr_t = _CTYPES[dtype]
        cfn = getattr(self._lib, f"sf_cpu_{fn}_{dtype}")
        cfn.restype = None
        cfn.argtypes = [ptr_t, ptr_t, ctypes.c_int64]
        x = np.ascontiguousarray(x, dtype=np_dtype)
        out = np.empty_like(x)
        cfn(x.ctypes.data_as(ptr_t), out.ctypes.data_as(ptr_t), x.size)
        return out


@pytest.fixture(scope="session")
def sf_cpu() -> _Dispatcher:
    return _Dispatcher(ctypes.CDLL(str(_build_dylib())))
