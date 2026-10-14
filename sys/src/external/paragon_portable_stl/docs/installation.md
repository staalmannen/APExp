## Download and Install

1. Clone the repository:
   
   ```bash
   git clone https://github.com/<repo>/pstl.git
   ```

2. Build PSTL using CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

---

## Prerequisites

Before installing PSTL, ensure your development environment meets the following requirements:

- **Compiler**:  
  - GCC 7.1 or higher  
  - Clang 6.0 or higher  
  - MSVC 2019 or higher  
- **C++ Standard**: C++14 or later.  
- **Build Tools**:  
  - CMake (recommended for project integration).

---

## Installation Options

### 1. Using Git
Clone the repository:

```bash
git clone https://github.com/<repo>/pstl.git
```

### 2. Include as a Submodule
Add PSTL to your project as a submodule:

```bash
git submodule add https://github.com/<repo>/pstl.git external/pstl
```

### 3. Build from Source
To build PSTL, use the following commands:

```bash
mkdir build && cd build
cmake ..
make
```

---

## Compiler Flags

### Required

- **Enable C++14**: Add the flag `-std=c++14` (or higher standard, if preferred).

### Optional

- **Disable Exceptions**: Use `-fno-exceptions` for environments where exceptions are not allowed.
- **Custom Allocators**: No specific flags are required; the library automatically detects external allocators.

Example build command:

```bash
g++ -std=c++14 -fno-exceptions -Iinclude your_code.cpp -o your_program
```

---

## Next Steps

After installation, [configure your PSTL project](configuring.md)
