# special-functions: Hub kernel package for special functions

**Date:** 2026-07-13 (revised same day after spec review)
**Status:** Approved, revised in review
**Repository:** `0x00b1/special-functions` (GitHub and Hugging Face Hub)

## Summary

A Python package of GPU/CPU compute kernels for special functions, built with
Hugging Face `kernel-builder` and loadable from the Kernel Hub via
`kernels.get_kernel("0x00b1/special-functions")`. Version 1 implements the
Γ/ψ chain — eight functions — across five backends (CUDA, ROCm, XPU, Metal,
CPU) with per-backend hand-written implementations, real **and complex**
arguments, full autograd (double backward and beyond falls out automatically
because the family is closed under differentiation), `torch.compile` support
via fake ops, dual binding frameworks (`torch` and `tvm-ffi`), and a
ULP-audited accuracy contract validated against mpmath reference tables. The
torch bindings are built against the Torch stable ABI (`[torch.stable-abi]`)
on every backend, collapsing the per-Torch-version build matrix.

The incomplete gamma functions (P, Q, their inverses, and their a-derivatives)
were dropped from v1 during spec review and are documented under Future work
with their approved design, so they can return without re-litigating
decisions.

## Goals

- Establish the package architecture with one coherent, complete function
  family, so later families (incomplete gamma, Bessel, elliptic, …) are
  additive.
- Accuracy as the headline feature: explicit, tested, per-region ULP budgets
  identical across all backends.
- Complex arguments as first-class: complex64/complex128 for every function,
  not a bolt-on.
- Full differentiability: backward and double backward (and higher, which the
  ψ chain gives for free), `torch.compile` without graph breaks.
- Framework reach: `[torch]` bindings for the PyTorch ecosystem and
  `[tvm-ffi]` bindings (DLPack, stable C ABI) for framework-neutral consumers
  such as JAX.
- ABI stability: torch bindings written to the Torch stable ABI on all five
  backends, so each backend ships one build that works on the pinned Torch
  version and everything later, instead of one build per Torch release.

## Non-goals (v1)

- Incomplete gamma functions P, Q, inverses, and a-derivatives — deferred
  entirely; see Future work.
- Explicit CPU SIMD (compiler autovectorization only).
- Function families beyond the Γ/ψ chain.

## Decisions

| Decision | Choice |
|---|---|
| Scope | Γ/ψ chain: 8 public functions (P/Q family dropped in review; see Future work) |
| Backends | cuda, rocm, xpu, metal, cpu (all five from the start) |
| Dtypes | float32, float64, float16, bfloat16, complex64, complex128. Halves computed internally in fp32. Metal has no fp64: fp32, halves, and complex64 only there |
| Architecture | Per-backend hand-written implementations (idiomatic per platform), with shared *generated* coefficient tables and a shared accuracy contract as the anti-drift mechanisms |
| Binding frameworks | Both `[torch]` and `[tvm-ffi]` in v1. Autograd/compile are torch-side; tvm-ffi exposes forward functions via DLPack |
| Torch ABI | `[torch.stable-abi]` on all five backends (demonstrated by the `relu-torch-stable-abi` reference example), pinned at Torch "2.11" — exact pin confirmed at implementation as the oldest release whose stable ABI covers the bindings' needs |
| Autograd | backward + backward_backward (and higher orders); backwards composed from the package's own public ops; fake ops registered for `torch.compile`; complex gradients per PyTorch's Wirtinger/conjugate convention |
| Naming | Kernel/module name `special_functions`; full descriptive snake_case public names |
| Publishing | Develop and publish at `0x00b1/special-functions`; propose to `kernels-community` via PR to `huggingface/kernels-community` once mature |
| Accuracy validation | ULP budgets vs checked-in mpmath reference tables (per-component for complex) + identity/recurrence property tests |

## Repository layout

```
special-functions/
├── .github/workflows/
│   ├── build-kernel.yml            # HF Jobs build → build-and-upload to the Hub
│   └── run-tests.yml               # HF Jobs GPU test of published Hub artifacts
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
├── tvm-ffi-ext/
│   ├── tvm_ffi_binding.cpp         # TVM-FFI (DLPack) exports of the forward functions
│   └── special_functions/          # thin Python surface for ffi consumers
├── tools/
│   ├── coefficients/               # mpmath generators → per-backend coefficient headers
│   └── references/                 # mpmath reference-table generator
├── tests/                          # ULP + property + gradient tests
├── scripts/
│   └── ci_test.py                  # uv inline-deps smoke test run on HF Jobs GPUs
├── benchmarks/
└── docs/superpowers/specs/
```

`build.toml`:

- `[general]`: `name = "special_functions"`, `version = 1`, `edition = 5`,
  `backends = ["cuda", "rocm", "xpu", "metal", "cpu"]`.
- `[general.hub]`: `repo-id = "0x00b1/special-functions"`.
- `[torch]`: `torch-ext/torch_binding.cpp`, `torch-ext/torch_binding.h`.
- `[torch.stable-abi]`: all five backends pinned to the same Torch version
  (target `"2.11"`, per the `relu-torch-stable-abi` reference example).
- `[tvm-ffi]`: `tvm-ffi-ext/tvm_ffi_binding.cpp`.
- One `[kernel.special_functions_<backend>]` section per backend, each with
  `backend`, `depends`, and `src` pointing at its own directory. Kernel
  entry points are framework-agnostic (raw device pointers + sizes), so both
  binding layers call the same compiled kernels.

Op schemas are registered once in `torch_binding.cpp`; each build variant
compiles exactly one backend's sources and registers its
`ops.impl(..., torch::kCUDA | kMPS | kXPU | kCPU, ...)` behind
kernel-builder's per-backend macros. The tvm-ffi bindings export the same
entry points as direct DLPack-consuming functions (no torch dispatcher, no
libtorch dependency where the backend permits). Generated coefficient headers
are checked in (regenerable via `tools/`), so builds never run Python
generators.

## Public API

Loaded as `k = kernels.get_kernel("0x00b1/special-functions")`. Eight public
functions:

| Function | Signature | Definition |
|---|---|---|
| `gamma` | `(x: Tensor) -> Tensor` | Γ(x) |
| `log_gamma` | `(x: Tensor) -> Tensor` | real dtypes: log\|Γ(x)\| (matches `torch.lgamma`); complex dtypes: principal-branch analytic log-gamma (mpmath `loggamma` convention) |
| `reciprocal_gamma` | `(x: Tensor) -> Tensor` | 1/Γ(x), entire; finite everywhere |
| `digamma` | `(x: Tensor) -> Tensor` | ψ(x) = ψ⁽⁰⁾(x) |
| `trigamma` | `(x: Tensor) -> Tensor` | ψ⁽¹⁾(x) |
| `tetragamma` | `(x: Tensor) -> Tensor` | ψ⁽²⁾(x) |
| `pentagamma` | `(x: Tensor) -> Tensor` | ψ⁽³⁾(x) |
| `polygamma` | `(n: int, x: Tensor) -> Tensor` | ψ⁽ⁿ⁾(x), runtime n ≥ 0 |

Conventions:

- Python layer (`torch-ext/special_functions/__init__.py`) follows torch
  idioms: optional `out=` at the Python level, integer inputs promote to the
  default float dtype, fp16/bf16 upcast to fp32 internally and the result
  cast back.
- Op layer uses functional schemas (e.g. `"gamma(Tensor x) -> Tensor"`), not
  out-variants, for clean `register_fake` and `register_autograd`. All op
  registration from Python goes through `add_op_namespace_prefix` from the
  generated `_ops` module (no rewrapping, no import fallbacks), per
  kernel-builder's multi-version-loading requirement.
- **Complex semantics.** All eight functions accept complex64/complex128.
  `log_gamma` is the one convention fork: for complex input it is the
  analytic continuation (continuous on ℂ ∖ (−∞, 0], imaginary part tracked
  across recurrence/reflection — *not* `log(Γ(z))` with a principal log), so
  `log_gamma(complex(x)) ≠ complex(log_gamma(x))` for x < 0. This is
  documented prominently. All other functions satisfy
  `f(complex(x)) = complex(f(x))` up to accuracy budgets.
- Edge behavior is part of the contract, encoded in the reference tables and
  identical across backends:
  - `gamma`: poles at non-positive integers. Real: ±inf at ±0 by approach
    direction, NaN at negative integers; complex: NaN+NaNj at poles.
  - `log_gamma`: real: +inf at non-positive integers; complex: NaN+NaNj at
    the poles, branch cut along (−∞, 0].
  - `reciprocal_gamma`: exactly 0 at non-positive integers (real and
    complex).
  - ψ-family: poles at non-positive integers (sign per function order for
    real; NaN+NaNj for complex).
  - NaN inputs propagate (component-wise for complex).

## Numerical algorithms

Per-precision coefficient sets throughout: fp32 gets its own minimax fits,
not truncated fp64 coefficients. Complex evaluation reuses the same
asymptotic-series coefficients (valid in ℂ) with complex arithmetic.

- **gamma**: real — minimax rational core on a reduction interval, Stirling
  for large x, reflection for x < 0, overflow to ±inf with correct sign.
  Complex — recurrence to push Re z above the asymptotic threshold, complex
  Stirling series, reflection Γ(z)Γ(1−z) = π/sin(πz) for Re z < ½ with
  overflow-safe complex sin handling.
- **log_gamma**: real — interval rational approximations + Stirling series;
  reflection through log|sin(πx)|. Complex — principal-branch log-gamma:
  complex Stirling for large Re z, recurrence with accumulated logarithm
  (branch-tracked) otherwise, reflection with branch-consistent
  log(sin(πz)).
- **reciprocal_gamma**: dedicated Chebyshev series (not computed as
  `1/gamma`); exact zeros at the poles of Γ. Complex via
  exp(−log_gamma(z)) with sign/branch care, or direct series where more
  accurate.
- **digamma / trigamma / tetragamma / pentagamma**: upward recurrence to
  shift the argument past a per-function threshold, Bernoulli asymptotic
  series there, reflection formulas below (real x < 0, complex Re z < ½).
  The identical algorithm structure works in ℂ; thresholds are on Re z /
  |z|.
- **polygamma(n)**: ψ⁽ⁿ⁾(x) = (−1)ⁿ⁺¹ n! ζ(n+1, x) via Hurwitz zeta
  (recurrence shift + Euler–Maclaurin asymptotic series), handling runtime
  n; valid for complex x with the same structure. Orders 0–3 dispatch to the
  dedicated tuned kernels.

### Coefficient pipeline

`tools/coefficients/` holds mpmath-based generators (Chebyshev/minimax fits
and Bernoulli/asymptotic tables) that emit identical constants into
per-backend headers: C arrays for CUDA/HIP/SYCL/CPU and MSL-compatible
headers for Metal. Generated files are checked in, regenerable, and never
hand-edited. This is the single source of truth for constants even though
kernel code is per-backend.

### Per-backend notes

- **CUDA / ROCm**: explicit FMA-ordered Horner evaluation; fp64 full
  algorithms; grid-stride elementwise launchers. Complex arithmetic via a
  small local complex header (value-pair based, works under both `[torch]`
  and torch-free `[tvm-ffi]` builds).
- **Metal**: fp32, halves, complex64 only (no hardware fp64). Complex64 as
  `float2` with explicit arithmetic helpers. Compile with fast-math disabled
  or `metal::precise::` intrinsics — Metal's default fast-math would violate
  ULP budgets. Host dispatch in ObjC++ against the MPS device.
- **XPU**: SYCL kernels, `sycl::` math intrinsics.
- **CPU**: scalar loops under `at::parallel_for` (torch builds) with a plain
  threaded fallback for tvm-ffi builds; vectorization left to the compiler
  in v1.

## Bindings: torch and tvm-ffi

Kernel entry points are framework-agnostic (device pointers, counts, stream
handle), so both binding layers are thin:

- **`[torch]`** (`torch-ext/`): op registration of functional schemas,
  per-device `ops.impl`, Python public API, autograd, fake ops. This is the
  full-featured surface: autograd, double backward, `torch.compile`.
  **Written against the Torch stable ABI** on every backend: bindings
  include `<torch/csrc/stable/library.h>` and register through
  `STABLE_TORCH_LIBRARY_EXPAND` / `STABLE_TORCH_LIBRARY_IMPL_EXPAND` with
  `TORCH_BOX()`-wrapped entry points, using only stable-ABI types
  (`torch::stable::Tensor`). Consequences: one build per backend that runs
  on the pinned Torch version and later (the per-Torch-version matrix
  collapses), at the cost of not loading on older Torch releases. If output
  allocation for functional schemas proves awkward in the stable subset, the
  C++ ops become out-variant and the functional surface (with autograd and
  fake ops) is registered at the Python custom-op layer instead — public API
  unchanged.
- **`[tvm-ffi]`** (`tvm-ffi-ext/`): DLPack-consuming exports of the eight
  forward functions with a stable C ABI and no libtorch dependency where the
  backend permits (per the `relu-tvm-ffi` reference example, cuda/cpu can be
  torch-free; xpu currently still depends on torch). Forward-only: autograd
  and compile integration are torch concepts and remain torch-side.
  Consumers: JAX and anything DLPack-capable.

If kernel-builder turns out not to support both framework sections in a
single `build.toml` (undocumented either way; see Risks), the fallback is a
sibling Hub repo `0x00b1/special-functions-tvm-ffi` sharing the same kernel
sources via `[general].source`.

## Autograd and torch.compile

Backwards are compositions of the package's own public differentiable ops —
no dedicated backward kernels anywhere in v1. Because the ψ chain is closed
under differentiation (ψ⁽ⁿ⁾′ = ψ⁽ⁿ⁺¹⁾), autograd composes to arbitrary
order; double backward is just the second rung.

| Op | Gradient |
|---|---|
| `gamma` | `gamma(x) · digamma(x)` |
| `log_gamma` | `digamma(x)` (real and complex — ψ is the derivative of the analytic branch too) |
| `reciprocal_gamma` | `−digamma(x) · reciprocal_gamma(x)` |
| `digamma` | `trigamma(x)` |
| `trigamma` | `tetragamma(x)` |
| `tetragamma` | `pentagamma(x)` |
| `pentagamma` | `polygamma(4, x)` |
| `polygamma(n, ·)` | `polygamma(n+1, x)`; n is a non-differentiable static arg |

Mechanics:

- `torch.library.register_autograd` per op; backward functions call the
  public Python wrappers so their graphs are themselves differentiable.
- **Complex gradients** follow PyTorch's Wirtinger/conjugate convention: all
  eight functions are holomorphic away from poles (and `log_gamma`'s branch
  cut), so backward returns `grad_output * conj(f′(z))`; the conjugation
  lives in the shared autograd wrapper, not per-function code.
- Fake ops via `torch.library.register_fake(add_op_namespace_prefix(...))`
  returning `empty` on the input shape/dtype — `torch.compile` traces
  forward and all backward orders without graph breaks.
- Half-dtype upcasting happens in the Python wrappers, so autograd flows
  through the casts naturally.

## Testing and accuracy validation

- **Reference tables**: `tools/references/` generates mpmath truth at 50
  significant digits, correctly rounded to each target dtype, stored as
  checked-in `.npz`. Real grids concentrate where algorithms are fragile:
  recurrence/reflection thresholds, near poles and near the zeros of ψ,
  subnormals, near-overflow arguments — plus log-spaced and pseudo-random
  coverage and special values (±0, ±inf, NaN, integer and half-integer x).
  Complex grids cover rectangles around the origin and poles, strips along
  the negative real axis (branch-cut neighborhoods for `log_gamma`), rays at
  varied arg(z), and large-|z| asymptotic territory.
- **ULP harness**: exact ULP distance via integer reinterpretation; for
  complex results, per-component (real/imag) ULP distance. Per-function,
  per-region budgets in a checked-in TOML manifest — the manifest is the
  accuracy contract and is identical for all five backends. Default budget
  ≤4 ULP for fp64 and fp32 (each vs correctly-rounded truth at that
  precision), with explicit documented per-region exceptions near poles, ψ
  zeros, and the `log_gamma` branch cut, where pole/branch behavior is
  contract-tested instead of relative error.
- **Property tests**: Γ(x+1) = xΓ(x); reflection formulas; ψ(x+1) = ψ(x) +
  1/x; conjugate symmetry f(conj(z)) = conj(f(z)) for complex inputs off the
  branch cut; real-slice consistency f(complex(x)) = complex(f(x)) for all
  functions except `log_gamma` on x < 0 (documented convention fork).
- **Gradient tests**: `torch.autograd.gradcheck` / `gradgradcheck` in fp64
  and complex128 on CPU and CUDA. On Metal (no fp64/complex128), gradients
  are checked against differentiated mpmath references instead —
  finite-difference gradcheck is unreliable at single precision.
- **tvm-ffi parity tests**: for each backend built with both frameworks, the
  ffi-exposed functions are checked bit-identical to the torch-op results on
  shared grids (same kernels underneath — this guards binding-layer bugs,
  not numerics).
- **Harness mechanics**: tests load the kernel via `kernels.get_kernel`
  (never direct imports), parametrized over available devices and dtypes.
  A `kernels_ci`-marked subset runs in under 60 seconds via
  `nix run .#ci-test`. fp16/bf16 are validated against mpmath truth rounded
  to the half type, with a small ULP allowance for the
  fp32-compute-then-round pipeline.

## Benchmarks, docs, CI, publishing

- **Benchmarks**: `benchmarks/benchmark.py` measures throughput (elements/s)
  across sizes and dtypes against `torch.special` counterparts where they
  exist (`lgamma`, `digamma`, `polygamma`) and SciPy on CPU; complex paths
  benchmarked against SciPy/mpmath-backed references for correctness-scaled
  comparisons. Informational only in v1 — no gates.
- **Docs**: `CARD.md` auto-filled by the builder becomes the Hub README.
  Per-function docs cover domain (real and complex), branch-cut conventions,
  algorithm sketch, gradient support matrix, and a ULP budget table rendered
  from the accuracy manifest so docs cannot drift from the tested contract.
- **Dev workflow**: local development on macOS builds and tests the Metal
  and CPU variants via Nix (`kernel-builder devshell`, `nix run .#ci-test`).
  The kernel-builder agent skills (installed via
  `kernel-builder skills add --claude`) support agent-driven kernel
  authoring per the kernels agents guide.
- **CI (GitHub Actions + HF Jobs)**: GitHub's runners neither build (CPU
  cost) nor test (no accelerator) kernels well, so both steps offload to
  Hugging Face Jobs per the kernel-builder GitHub Actions guide:
  - `.github/workflows/build-kernel.yml` — on push to `main` touching
    kernel sources, uses `huggingface/kernel-builder-job` to run the Nix
    builder on an HF Jobs `cpu-xl` flavor and `build-and-upload` the
    variants to `0x00b1/special-functions`. Requires an `HF_TOKEN`
    repository secret with `job.write` permission (workflows `set +x`
    before exporting it so it never hits streamed logs).
  - `.github/workflows/run-tests.yml` — uses `huggingface/hf-jobs-action`
    on a GPU flavor (`l4x1`) to run `scripts/ci_test.py` (a uv
    inline-dependency script) that pulls the just-published kernel from the
    Hub via `get_kernel` and exercises load, dispatch, sanity values, and
    autograd — guarding the published artifacts end-to-end, complementing
    the in-repo suite.
  - **Coverage limits, recorded honestly**: HF Jobs is Linux-only, so Metal
    variants are built and uploaded from local macOS; HF Jobs GPU flavors
    are NVIDIA-only, so ROCm/XPU accuracy sign-off stays a manual
    pre-release step on real hardware (kernel-builder's Terraform example
    covers CUDA-class boxes).
- **Publishing**: GitHub `0x00b1/special-functions`; Hub repo the same;
  releases via `kernel-builder build-and-upload` to the `v1` version branch.
  Once mature, propose the kernel to `kernels-community` via PR to
  `huggingface/kernels-community`.

## Future work (approved direction, not in v1)

- **Incomplete gamma family** (dropped from v1 in spec review to keep scope
  tractable once complex support was promoted to a goal). When it returns,
  the reviewed design stands:
  - `regularized_incomplete_gamma_p`/`_q` via the standard trichotomy
    (Kummer series for x < a+1, modified-Lentz continued fraction otherwise,
    Temme uniform asymptotics for large a; compute the smaller of P/Q and
    complement).
  - Inverses via Temme asymptotic inversion + Halley refinement; the
    inverses are intrinsically real (they invert a monotone real map) and
    stay real even once P/Q gain complex arguments.
  - ∂P/∂a as a dedicated op (AS 187/Moore lineage), and — since P(a, x) is
    real-analytic in a on a > 0, so it is mathematically well-defined —
    ∂²P/∂a² as a second dedicated op, making double backward complete in all
    direction pairs; non-differentiability cutoff at third order in a.
  - Complex-argument P/Q (analytic continuation) as a further step after the
    real implementation lands.
- Explicit CPU SIMD.
- Further families: Bessel, elliptic integrals, error-function family.

## Risks

- **Dual framework sections in one repo**: both `[torch]` and `[tvm-ffi]` in
  a single `build.toml` is not explicitly documented as supported. Mitigation
  if unsupported: sibling repo `0x00b1/special-functions-tvm-ffi` reusing the
  same kernel sources via `[general].source`. To be verified in the first
  implementation milestone.
- **Stable ABI is experimental** in kernel-builder, and its API surface is a
  restricted subset of libtorch: risks are functional-schema output
  allocation and stream/queue access per backend (MPS command queue, SYCL
  queue) within the stable subset. The reference example proves all five
  backends work for out-variant elementwise ops; the fallback (out-variant
  C++ ops + Python-layer functional registration) is recorded in the
  Bindings section. Pinning at "2.11" also sets the minimum supported Torch
  version — acceptable, and revisited if users need older Torch.
- **tvm-ffi backend coverage**: reference examples demonstrate cpu/cuda/xpu
  only; Metal and ROCm through tvm-ffi are unproven. Acceptable outcome:
  tvm-ffi bindings ship for the subset of backends where they work, torch
  bindings cover all five.
- **Cross-backend numerical drift** (inherent to per-backend
  implementations): mitigated by the shared coefficient pipeline, the shared
  reference tables, and the identical ULP manifest applied to every backend.
- **Complex accuracy near branch cuts and poles**: hardest accuracy
  territory; handled by dedicated grid density there, region-scoped budgets,
  and contract tests for branch/pole behavior rather than raw ULP where
  relative error is ill-conditioned.
- **GPU CI availability**: CUDA/ROCm/XPU test hardware is not guaranteed in
  CI; the manual pre-release sign-off step covers the gap.
- **kernel-builder cpu backend is experimental**: its build interface may
  change; the CPU sources themselves are plain C++ and portable regardless.
