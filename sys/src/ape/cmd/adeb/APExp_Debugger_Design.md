# APExp Debugger Design: `adeb` (A Native Plan 9 /proc + libdwarf Debugger)

This document outlines the architecture and design for a lightweight, native Plan 9 / 9front debugger (`adeb`) tailored for the **APExp** project. It leverages the clean, file-based `/proc` file system of Plan 9 for process tracing and control, combined with the lightweight, C99-compliant `libdwarf` library for reading DWARF2 debugging symbols embedded by the patched APExp toolchain.

---

## 1. Architectural Philosophy

Traditional debuggers (like GNU `gdb`) rely heavily on highly complex POSIX primitives like `ptrace()`, asynchronous signals, and massive platform-dependent abstraction layers. This architectural bloat conflicts with the minimalist, file-centric philosophy of Plan 9.

`adeb` follows the core Plan 9 principles:
1. **Control via Files**: Use native `/proc/<pid>/ctl`, `regs`, and `mem` primitives for execution flow and state monitoring.
2. **Standard C Implementation**: Written in clean, modular C99, requiring no C++ or heavy execution runtimes (like Go).
3. **Decoupled Architecture**: Separation of concerns between the OS process controller, the DWARF-to-source mapping engine, and the user CLI.

---

## 2. Core Components

```
+-------------------------------------------------------------+
|                     Custom Debugger Tool (adeb)             |
|                                                             |
|   +-----------------------+     +-----------------------+   |
|   |   libdwarf Frontend   |     |  /proc Interface      |   |
|   +-----------+-----------+     +-----------+-----------+   |
+---------------|-----------------------------|---------------+
                |                             |
                v                             v
     +--------------------+        +--------------------+
     | ELF/A.out Binary   |        | Kernel /proc       |
     | (DWARF2 Sections)  |        | (ctl, status, mem) |
     +--------------------+        +--------------------+
```

### A. The `/proc` File System Subsystem
Instead of complex syscall hooks, process interaction maps directly to open file descriptors pointing to `/proc/<pid>/`:
* **`ctl`**: Handles thread/process state changes. Commands are written as plain strings (e.g., `"stop"`, `"start"`, `"step"`).
* **`regs`**: Exposes machine register architecture. Reading this provides the hardware Program Counter (`PC`) and Stack Pointer (`SP`).
* **`mem`**: Represents the virtual memory space of the target. `seek()` and `read()` allow immediate extraction of variable values, heap segments, or stack variables.
* **`status`**: Monitored to detect transitions between execution states or trap conditions (Notes).

### B. The `libdwarf` Symbol Engine
The `libdwarf` library processes the binary's ELF sections to parse DWARF2 data structures:
* **Line Number Program**: Maps hardware instruction addresses (read from `/proc/.../regs`) back to specific files and source code line numbers.
* **Debugging Information Entries (DIEs)**: Parses functions, local scopes, parameters, and structural variable names.
* **Location Expressions**: Translates a variable name into its current physical location (either a hardware register or a relative offset from the Stack Pointer).

---

## 3. Execution Control & Event Loop

The debugger implements a synchronous event loop that treats target execution transitions as logical file reads:

```
  +-------------------------------------------------+
  |  1. Parse DWARF symbols via libdwarf            |
  +-------------------------------------------------+
                           |
                           v
  +-------------------------------------------------+
  |  2. Fork/Exec target & write "stop" to ctl      |
  +-------------------------------------------------+
                           |
                           v
+----> [ START OF EVENT LOOP ]
|                          |
|                          v
| +-------------------------------------------------+
| |  3. Read Program Counter (PC) from regs         |
| +-------------------------------------------------+
|                          |
|                          v
| +-------------------------------------------------+
| |  4. Query libdwarf: Translate PC -> File:Line   |
| +-------------------------------------------------+
|                          |
|                          v
| +-------------------------------------------------+
| |  5. Present interactive CLI prompt to user      |
| +-------------------------------------------------+
|                          |
|                          v
| +-------------------------------------------------+
| |  6. If user requests data/variables:            |
| |     - Calculate variable address via libdwarf   |
| |     - Read value from mem file descriptor       |
| +-------------------------------------------------+
|                          |
|                          v
| +-------------------------------------------------+
| |  7. Issue execution directive ("step" / "start")|
| |     to ctl file. Block until status is "stopped"|
| +-------------------------------------------------+
|                          |
+--------------------------+
```

---

## 4. Key Implementation Steps for APExp

1. **Compile `libdwarf`**: Build a clean static archive (`libdwarf.a`) using the APExp patched compiler and musl libc integration.
2. **Implement `/proc` Abstraction**: Write a compact file management layer to cleanly map `regs` parsing (e.g., matching the host CPU architecture layout like `amd64` or `386`) and tracking data streams.
3. **Map Breakpoints**: Implement software breakpoints by reading a target memory location via `mem`, saving the original instruction bytecode, writing the host trap instruction, and restoring it upon hitting the exception.
4. **Build CLI Frontend**: Write a minimalist text-driven frontend reading user input to coordinate the execution cycle.

---
*Document designed for integration with the APExp ecosystem.*
