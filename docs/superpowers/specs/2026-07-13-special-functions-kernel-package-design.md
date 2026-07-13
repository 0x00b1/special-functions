# special-functions: Hub kernel package for special functions

**Date:** 2026-07-13
**Status:** Approved
**Repository:** `0x00b1/special-functions` (GitHub and Hugging Face Hub)

## Summary

A Python package of GPU/CPU compute kernels for special functions, built with
Hugging Face `kernel-builder` and loadable from the Kernel Hub via
`kernels.get_kernel("0x00b1/special-functions")`. Version 1 implements the
gamma family across five backends (CUDA, ROCm, XPU, Metal, CPU) with
per-backend hand-written implementations, full first-order autograd (including
∂/∂a of the incomplete gamma functions), double backward in all direction
pairs except a–a, `torch.compile` support via fake ops, and a ULP-audited
accuracy contract validated against mpmath reference tables.

## Goals

- Establish the package architecture with one coherent, complete function
  family, so later families (Bessel, elliptic, error-function, …) are additive.
- Accuracy as the headline feature: explicit, tested, per-region ULP budgets
  identical across all backends.
- Full differentiability: backward and double backward, `torch.compile`
  without graph breaks.

## Non-goals (v1)

- ∂²P/∂a² (the a–a second derivative of the incomplete gamma functions);
  marked non-differentiable with a clear error.
- Explicit CPU SIMD (compiler autovectorization only).
- Complex arguments.
- Function families beyond the gamma family.
- `tvm-ffi` and Torch stable-ABI build variants.

## Decisions

| Decision | Choice |
|---|---|
| Scope | Gamma family seed set (12 public ops) |
| Backends | cuda, rocm, xpu, metal, cpu (all five from the start) |
| Dtypes | float32, float64, float16, bfloat16 (halves computed internally in fp32; Metal has no fp64 — fp32 + halves only there) |
| Architecture | Per-backend hand-written implementations (idiomatic per platform), with shared *generated* coefficient tables and a shared accuracy contract as the anti-drift mechanisms |
| Autograd | backward + backward_backward; backwards composed from the package's own public ops; fake ops registered for `torch.compile` |
| ∂P/∂a | Included in v1 via a dedicated per-backend op |
| Naming | Kernel/module name `special_functions`; full descriptive snake_case public names |
| Publishing | Develop and publish at `0x00b1/special-functions`; propose to `kernels-community` via PR to `huggingface/kernels-community` once mature |
| Accuracy validation | ULP budgets vs checked-in mpmath reference tables + identity/recurrence property tests |

## Repository layout

```
special-functions/
├── build.toml                      # edition 5; backends: cuda, rocm, xpu, metal, cpu
├── flake.nix                       # kernel-builder Nix entry point
├── CARD.md                         # kernel card template → Hub README
├── example.py
├── special_functions_cuda/         # .cu sources, one file per function group
├── special_functions_rocm/         # HIP sources
├── special_functions_xpu/          # SYCL sources
├── special_functions_metal/        # .metal shaders + ObjC++ host dispatch
├── special_functions_cpu/          # plain C++ (kernel-builder cpu backend, experimental)
├── torch-ext/
│   ├── torch_binding.h             # entry-point declarations
│   ├── torch_binding.cpp           # op schemas + per-device impls (gated by per-backend macros)
│   └── special_functions/          # Python: public API, autograd, fake ops
├── tools/
│   ├── coefficients/               # mpmath generators → per-backend coefficient headers
│   └── references/                 # mpmath reference-table generator
├── tests/                          # ULP + property + gradient tests
├── benchmarks/
└── docs/superpowers/specs/
```

`build.toml`:

- `[general]`: `name = "special_functions"`, `version = 1`, `edition = 5`,
  `backends = ["cuda", "rocm", "xpu", "metal", "cpu"]`.
- `[general.hub]`: `repo-id = "0x00b1/special-functions"`.
- `[torch]`: `torch-ext/torch_binding.cpp`, `torch-ext/torch_binding.h`.
- One `[kernel.special_functions_<backend>]` section per backend, each with
  `backend`, `depends = ["torch"]`, and `src` pointing at its own directory.

Op schemas are registered once in `torch_binding.cpp`; each build variant
compiles exactly one backend's sources and registers its
`ops.impl(..., torch::kCUDA | kMPS | kXPU | kCPU, ...)` behind
kernel-builder's per-backend macros. Generated coefficient headers are checked
in (regenerable via `tools/`), so builds never run Python generators.

## Public API

Loaded as `k = kernels.get_kernel("0x00b1/special-functions")`. Twelve public
functions plus one gradient op:

| Function | Signature | Definition |
|---|---|---|
| `gamma` | `(x: Tensor) -> Tensor` | Γ(x) |
| `log_gamma` | `(x: Tensor) -> Tensor` | log\|Γ(x)\| (matches `torch.lgamma` convention) |
| `reciprocal_gamma` | `(x: Tensor) -> Tensor` | 1/Γ(x), entire; finite everywhere |
| `digamma` | `(x: Tensor) -> Tensor` | ψ(x) = ψ⁽⁰⁾(x) |
| `trigamma` | `(x: Tensor) -> Tensor` | ψ⁽¹⁾(x) |
| `tetragamma` | `(x: Tensor) -> Tensor` | ψ⁽²⁾(x) |
| `pentagamma` | `(x: Tensor) -> Tensor` | ψ⁽³⁾(x) |
| `polygamma` | `(n: int, x: Tensor) -> Tensor` | ψ⁽ⁿ⁾(x), runtime n ≥ 0 |
| `regularized_incomplete_gamma_p` | `(a: Tensor, x: Tensor) -> Tensor` | P(a, x), broadcasting |
| `regularized_incomplete_gamma_q` | `(a: Tensor, x: Tensor) -> Tensor` | Q(a, x) = 1 − P(a, x), broadcasting |
| `inverse_regularized_incomplete_gamma_p` | `(a: Tensor, p: Tensor) -> Tensor` | solves P(a, x) = p for x |
| `inverse_regularized_incomplete_gamma_q` | `(a: Tensor, q: Tensor) -> Tensor` | solves Q(a, x) = q for x |
| `regularized_incomplete_gamma_p_grad_a` | `(a: Tensor, x: Tensor) -> Tensor` | ∂P/∂a; public, used internally by autograd |

Conventions:

- Python layer (`torch-ext/special_functions/__init__.py`) follows torch
  idioms: broadcasting on binary ops, optional `out=` at the Python level,
  integer inputs promote to the default float dtype, fp16/bf16 upcast to fp32
  internally and the result cast back.
- Op layer uses functional schemas (e.g. `"gamma(Tensor x) -> Tensor"`), not
  out-variants, for clean `register_fake` and `register_autograd`. All op
  registration from Python goes through `add_op_namespace_prefix` from the
  generated `_ops` module (no rewrapping, no import fallbacks), per
  kernel-builder's multi-version-loading requirement.
- Edge behavior is part of the contract, encoded in the reference tables and
  identical across backends:
  - `gamma`: poles at non-positive integers; ±inf at ±0 with the sign of the
    approach direction; NaN at negative integers; overflow → ±inf.
  - `log_gamma`: +inf at non-positive integers.
  - `reciprocal_gamma`: exactly 0 at non-positive integers.
  - ψ-family: poles at non-positive integers (sign per function order).
  - P/Q domain: `a > 0`, `x ≥ 0`; outside → NaN. `P(a, 0) = 0`, `Q(a, 0) = 1`,
    `P(a, +inf) = 1`.
  - Inverses: domain `p ∈ [0, 1]` (resp. `q`); endpoints map to 0 / +inf;
    outside → NaN.
  - NaN inputs propagate.

## Numerical algorithms

Per-precision coefficient sets throughout: fp32 gets its own minimax fits, not
truncated fp64 coefficients.

- **gamma**: minimax rational core on a reduction interval, Stirling for large
  x, reflection formula for x < 0; overflow to ±inf with correct sign.
- **log_gamma**: interval rational approximations + Stirling series for large
  x; reflection through log|sin(πx)| for x < 0.
- **reciprocal_gamma**: dedicated Chebyshev series (not computed as
  `1/gamma`); exact zeros at the poles of Γ.
- **digamma / trigamma / tetragamma / pentagamma**: upward recurrence to shift
  the argument past a per-function threshold, Bernoulli asymptotic series
  there, reflection formulas for x < 0.
- **polygamma(n)**: ψ⁽ⁿ⁾(x) = (−1)ⁿ⁺¹ n! ζ(n+1, x) via Hurwitz zeta
  (recurrence shift + Euler–Maclaurin asymptotic series), handling runtime n.
  Orders 0–3 dispatch to the dedicated tuned kernels.
- **P / Q**: standard trichotomy — Kummer series for x < a + 1,
  modified-Lentz continued fraction otherwise, Temme's uniform asymptotic
  expansion (erfc-based) for large a. Always compute the smaller of P/Q
  directly and complement, avoiding cancellation.
- **Inverses**: Temme asymptotic inversion for the initial estimate, then 2–3
  Halley iterations against the forward algorithms, converging to
  approximately the forward function's accuracy.
- **∂P/∂a**: dedicated algorithm (AS 187 `digami` lineage: differentiated
  series / continued fraction, matching the forward trichotomy's regions).

### Coefficient pipeline

`tools/coefficients/` holds mpmath-based generators (Chebyshev/minimax fits)
that emit identical constants into per-backend headers: C arrays for
CUDA/HIP/SYCL/CPU and MSL-compatible headers for Metal. Generated files are
checked in, regenerable, and never hand-edited. This is the single source of
truth for constants even though kernel code is per-backend.

### Per-backend notes

- **CUDA / ROCm**: explicit FMA-ordered Horner evaluation; fp64 full
  algorithms; grid-stride elementwise launchers.
- **Metal**: fp32 + halves only (no hardware fp64). Compile with fast-math
  disabled or use `metal::precise::` intrinsics — Metal's default fast-math
  would violate ULP budgets. Host dispatch in ObjC++ against the MPS device.
- **XPU**: SYCL kernels, `sycl::` math intrinsics.
- **CPU**: scalar loops under `at::parallel_for`; vectorization left to the
  compiler in v1.

## Autograd and torch.compile

Backwards are compositions of the package's own public differentiable ops —
no dedicated backward kernels except `regularized_incomplete_gamma_p_grad_a`.
Because every op in a backward composition has its own registered derivative,
double backward falls out of autograd automatically (to arbitrary order for
the ψ chain).

| Op | Gradient |
|---|---|
| `gamma` | `gamma(x) · digamma(x)` |
| `log_gamma` | `digamma(x)` |
| `reciprocal_gamma` | `−digamma(x) · reciprocal_gamma(x)` |
| `digamma` | `trigamma(x)` |
| `trigamma` | `tetragamma(x)` |
| `tetragamma` | `pentagamma(x)` |
| `pentagamma` | `polygamma(4, x)` |
| `polygamma(n, ·)` | `polygamma(n+1, x)`; n is a non-differentiable static arg |
| `P(a, x)` | ∂P/∂x = `exp((a−1)·log(x) − x − log_gamma(a))`; ∂P/∂a = `regularized_incomplete_gamma_p_grad_a(a, x)` |
| `Q(a, x)` | negations of the P gradients |
| `inverse_p(a, p)` | IFT at x = output: ∂x/∂p = 1/(∂P/∂x); ∂x/∂a = −(∂P/∂a)/(∂P/∂x) |
| `inverse_q(a, q)` | analogous with sign flips |
| `grad_a(a, x)` | w.r.t. x: closed form ∂²P/∂a∂x = ∂P/∂x · (log(x) − digamma(a)); w.r.t. a: non-differentiable in v1 (∂²P/∂a² excluded) |

Mechanics:

- `torch.library.register_autograd` per op; backward functions call the
  public Python wrappers so their graphs are themselves differentiable.
- Fake ops via `torch.library.register_fake(add_op_namespace_prefix(...))`
  returning `empty` on broadcast result shapes — `torch.compile` traces
  forward and both backward orders without graph breaks.
- Half-dtype upcasting happens in the Python wrappers, so autograd flows
  through the casts naturally.

## Testing and accuracy validation

- **Reference tables**: `tools/references/` generates mpmath truth at 50
  significant digits, correctly rounded to each target dtype, stored as
  checked-in `.npz`. Grids concentrate where algorithms are fragile:
  algorithm-switching boundaries (x ≈ a + 1, recurrence and reflection
  thresholds), near poles and near the zeros of ψ, subnormals, near-overflow
  arguments — plus log-spaced and pseudo-random coverage and special values
  (±0, ±inf, NaN, integer and half-integer x). ∂P/∂a truth via high-precision
  `mpmath.diff`.
- **ULP harness**: exact ULP distance via integer reinterpretation.
  Per-function, per-region budgets in a checked-in TOML manifest — the
  manifest is the accuracy contract and is identical for all five backends.
  Default budget ≤4 ULP for fp64 and fp32 (each vs correctly-rounded truth at
  that precision), with explicit documented per-region exceptions near poles
  and ψ zeros, where pole/sign behavior is contract-tested instead of
  relative error.
- **Property tests**: Γ(x+1) = xΓ(x); reflection formulas; ψ(x+1) = ψ(x) +
  1/x; P + Q = 1; inverse round-trips P(a, P⁻¹(a, p)) ≈ p; monotonicity of P
  in x.
- **Gradient tests**: `torch.autograd.gradcheck` / `gradgradcheck` in fp64 on
  CPU and CUDA. On Metal (fp32-only), gradients are checked against
  differentiated mpmath references instead — finite-difference gradcheck is
  unreliable at fp32.
- **Harness mechanics**: tests load the kernel via `kernels.get_kernel`
  (never direct imports), parametrized over available devices and dtypes.
  A `kernels_ci`-marked subset runs in under 60 seconds via
  `nix run .#ci-test`. fp16/bf16 are validated against mpmath truth rounded
  to the half type, with a small ULP allowance for the
  fp32-compute-then-round pipeline.

## Benchmarks, docs, CI, publishing

- **Benchmarks**: `benchmarks/benchmark.py` measures throughput (elements/s)
  across sizes and dtypes against `torch.special` counterparts where they
  exist (`lgamma`, `digamma`, `polygamma`, `igamma`, `igammac`) and SciPy on
  CPU. Informational only in v1 — no gates.
- **Docs**: `CARD.md` auto-filled by the builder becomes the Hub README.
  Per-function docs cover domain, algorithm sketch, gradient support matrix,
  and a ULP budget table rendered from the accuracy manifest so docs cannot
  drift from the tested contract.
- **Dev workflow**: local development on macOS builds and tests the Metal and
  CPU variants via Nix. GitHub Actions (Nix + HF binary cache) builds all
  five backends on every PR; tests run on CPU always and on GPU runners where
  available. Full-matrix accuracy sign-off (CUDA/ROCm/XPU on real hardware)
  is a manual pre-release step on a cloud builder (kernel-builder's Terraform
  example covers CUDA).
- **Publishing**: GitHub `0x00b1/special-functions`; Hub repo the same;
  releases via `kernel-builder build-and-upload` to the `v1` version branch.
  Once mature, propose the kernel to `kernels-community` via PR to
  `huggingface/kernels-community`.

## Risks

- **Cross-backend numerical drift** (inherent to per-backend implementations):
  mitigated by the shared coefficient pipeline, the shared reference tables,
  and the identical ULP manifest applied to every backend.
- **∂P/∂a difficulty**: the hardest single piece of numerics in v1, times
  five backends. If it stalls, it is severable — everything else ships with a
  marked non-differentiable `a` — but as approved, v1 includes it.
- **GPU CI availability**: CUDA/ROCm/XPU test hardware is not guaranteed in
  CI; the manual pre-release sign-off step covers the gap.
- **kernel-builder cpu backend is experimental**: its build interface may
  change; the CPU sources themselves are plain C++ and portable regardless.
