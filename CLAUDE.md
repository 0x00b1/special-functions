# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build and Development Commands

### Building
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

### Testing  
```bash
ctest -C Release
# Working directory: build/
```

### Running Single Tests
The project uses GoogleTest. To run specific tests:
```bash
./build/special_functions_test --gtest_filter="cos_pi_test.accuracy"
```

## Architecture Overview

This is a **header-only C++23 library** providing mathematical special functions. The architecture follows a clean separation:

### Core Structure
- **Main header**: `include/special_functions.h` - Single include point for all functions
- **Individual headers**: `include/special_functions/*.h` - Each function has its own header
- **Implementation details**: `include/special_functions/detail/*.h` - Internal implementation helpers
- **Type utilities**: `include/special_functions/detail/fp_type_util.h` - Core type promotion and utilities

### Key Design Patterns
- **Header-only**: All functionality in headers, no compiled libraries
- **Template-based**: Extensive use of templates for type safety and performance
- **Type promotion**: Automatic promotion of integral types to floating-point as needed
- **Namespace organization**: All functions in `special_functions` namespace
- **INTERFACE library**: CMake INTERFACE library pattern for header-only distribution

### Special Functions Categories
The library implements 150+ mathematical special functions across categories:
- **Basic functions**: gamma, beta, factorial variants
- **Bessel functions**: regular, modified, spherical variants  
- **Polynomials**: Chebyshev, Legendre, Hermite, Laguerre, etc.
- **Hypergeometric functions**: confluent and Gauss hypergeometric
- **Elliptic functions**: complete and incomplete integrals
- **Number theory**: prime numbers, Stirling numbers, Euler numbers
- **Special integrals**: Fresnel, exponential, sine/cosine integrals

### Development Considerations
- **C++23 requirement**: Uses modern C++ features including `std::numbers`
- **GoogleTest integration**: Automatically fetched via FetchContent
- **Cross-platform**: Designed to work across different platforms
- **GitHub Actions**: Automated testing on Ubuntu latest with Release builds