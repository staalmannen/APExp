# GTest Integration Strategy for APExp on 9front

Here is the structured strategy for compiling **GoogleTest (gtest)** and **Paragon Portable STL (PSTL)** within the **APExp** environment on **9front**, utilizing the **EDG (Edison Design Group)** C++ frontend port and the initial PSTL-based library in `sys/include/ape/c++`.

---

## 1. Core Architectural Constraints & Options

Building GoogleTest for a highly customized environment like 9front requires adapting to specific language limits:

*   **No RTTI Yet:** By default, GoogleTest relies on Run-Time Type Information (`dynamic_cast`). Disabling this forces it to fall back to standard `static_cast` layouts.
*   **Disabled Exceptions:** GoogleTest traditionally catches test assertions via standard C++ exceptions (`try`, `catch`, `throw`). In an exception-free environment, it falls back to immediate test aborts and standard logging.
*   **Single-Threaded Context:** Since Plan 9 manages threading models differently than standard POSIX desktop targets via specialized syscalls (`rfork`), disabling `pthread` ensures stability during early stages.

---

## 2. Hard-Disabling Features in GoogleTest

You must pass explicit compiler configuration macros down to your preprocessor tools. These adjust `googletest/include/gtest/internal/gtest-port.h` internally:

*   `-DGTEST_HAS_RTTI=0` – Strips out internal type reflection and structural verification logic.
*   `-DGTEST_HAS_EXCEPTIONS=0` – Prevents stack unwinding mechanisms, turning assertion crashes into direct structural exits.
*   `-DGTEST_HAS_PTHREAD=0` – Eliminates reliance on `<pthread.h>` mappings.

---

## 3. Adapting Paragon Portable STL (PSTL)

APExp uses Paragon PSTL as the starting implementation for its C++ library. Common standard header names are exposed through EDC `.stdh` entrypoints under `sys/include/ape/c++`.

The library is an initial integration, not a complete standard-library
implementation. Its expected-based container APIs differ from standard
signatures, and broader coverage remains planned. Use the EDC public header
entrypoints from `sys/include/ape/c++`; see `docs/notes/cxx-library.md` for
supported headers and follow-up work.

---

## 4. The Compilation & Transpilation Pipeline

Since your EDG frontend port acts as a transpiler (lowering C++ source code down into ISO standard C files), the execution chain moves through the following stages:

```
 [ C++ Source Files ] (tests + GTest + APExp C++ headers)
         │
         ▼
 ┌───────────────┐
 │ EDG Frontend  │  <-- Compiles C++ down to ISO C
 └───────┬───────┘      (Flags: -DGTEST_HAS_RTTI=0 -DGTEST_HAS_EXCEPTIONS=0)
         │
         ▼
 [ Intermediate ISO C Code ] 
         │
         ▼
 ┌───────────────┐
 │ APExp 'pcc'   │  <-- Adapts ISO C to 9front environment
 └───────┬───────┘      (Uses your POSIX/musl headers & libap)
         │
         ▼
 ┌───────────────┐
 │ 9front '6c'   │  <-- Emits native Plan 9 machine code
 └───────────────┘
```

### The Role of APExp
The native 9front C compiler (`cc`/`6c`/`8c`) expects a strict, proprietary Plan 9 C dialect rather than standard ANSI/ISO C. Because EDG generates clean ISO C (such as C99/C11 features), handing its output directly to native 9front components will fail. 

You must pipe the resulting intermediate `.c` code directly through your **APExp `pcc` wrapper**, linking it against your experimental POSIX/musl head spaces and `libap` layers.

---

## 5. Blueprint Strategy for the Plan 9 Mkfile

To avoid complex CMake toolchains, merge the GoogleTest components together into a single translation unit layout ("fused format"). You can reference it directly inside your APExp build architecture:

```mk
# Fused GoogleTest compilation within APExp
TARG=gtest_apex_run
OFILES=    gtest-all.o    my_edg_tests.o
# Core compilation overrides passed to your EDG frontend layer
CFLAGS=-DGTEST_HAS_RTTI=0 -DGTEST_HAS_EXCEPTIONS=0 -DGTEST_HAS_PTHREAD=0 -I/sys/include/ape/c++ -I./googletest/include -I./googletest

include /sys/src/cmd/mkone
```
