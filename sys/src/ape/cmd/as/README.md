# as — GNU assembler syntax front-end for 9front

A drop-in `as` replacement for 9front that translates GNU assembler (GAS)
syntax — both AT&T and Intel — into Plan 9 assembly, then invokes the
appropriate native Plan 9 assembler (`6a`, `8a`, `5a`, etc.).

This allows `.s` files written for GNU `as` to be assembled on 9front
without modification, fitting naturally into the Plan 9 build system and
tool chain.

Part of the **APExp** project.

## Design

```
  foo.s  (AT&T or Intel syntax)
    │
    ▼
   as   ← this tool
    │  translate to Plan 9 syntax
    ▼
  /tmp/as_PID_N.s  (Plan 9 syntax)
    │
    ▼
  6a / 8a / 5a / ...  (native Plan 9 assembler)
    │
    ▼
  foo.6 / foo.8 / foo.5 / ...  (object file)
```

The translator is a single-pass text transformer. It is intentionally not a
full parser — it handles the common cases well and comments out directives it
cannot translate, so the output is always valid Plan 9 assembly (some
features may be elided).

Plan 9 assembly files are detected automatically and passed through to the
native assembler unmodified.

## Supported architectures

| `-march=` value         | Target    | Assembler |
|-------------------------|-----------|-----------|
| `amd64`, `x86_64`       | amd64     | `6a`      |
| `386`, `i386`, `i686`   | 386       | `8a`      |
| `arm`, `armv7`          | arm       | `5a`      |
| `arm64`, `aarch64`      | arm64     | `7a`      |
| `ppc64`, `powerpc64`    | ppc64     | `9a`      |
| `powerpc`, `ppc`        | power     | `qa`      |
| `mips`, `mipsel`        | mips      | `va`      |
| `sparc`, `sparc64`      | sparc     | `ka`      |
| `m68k`, `68000`         | 68000     | `1a`      |
| `m68020`                | 68020     | `2a`      |

Default target is `amd64` (`6a`).

## Syntax translation

### Registers (x86/amd64)

| AT&T / Intel  | Plan 9 |
|---------------|--------|
| `%rax` / `rax` | `AX` |
| `%eax` / `eax` | `AX` |
| `%ax`  / `ax`  | `AX` |
| `%al`  / `al`  | `AL` |
| `%xmm0` / `xmm0` | `X0` |
| `%mm0`  / `mm0`  | `M0` |
| `%st(0)` / `st`  | `F0` |
| `%cs` / `cs`     | `CS` |

RISC register aliases are also handled: ARM ABI names (`sp`→`R13`,
`lr`→`R14`, `pc`→`R15`), MIPS ABI names (`$zero`, `$ra`, `$sp`, etc.),
SPARC register windows (`%g0`–`%i7`→`R0`–`R31`), and so on.

### Memory addressing

| AT&T                | Plan 9              |
|---------------------|---------------------|
| `(%rsp)`            | `0(SP)`             |
| `8(%rbp)`           | `8(BP)`             |
| `-4(%rbp)`          | `-4(BP)`            |
| `(%rax,%rbx,4)`     | `0(AX)(BX*4)`       |
| `16(%rax,%rbx,8)`   | `16(AX)(BX*8)`      |
| `symbol(%rip)`      | `symbol(SB)`        |
| `[rax+rbx*4+16]`    | `16(AX)(BX*4)`      |

### Operand order

- **AT&T**: `src, dst` — Plan 9: `src, dst` — same, no change needed
- **Intel**: `dst, src` — Plan 9: `src, dst` — operands are swapped

**Exception**: `CMP` and `TEST` always require the register operand first
in Plan 9, regardless of source syntax:

| Input (AT&T)       | Input (Intel)    | Plan 9 output  |
|--------------------|------------------|----------------|
| `cmpl $0, %eax`    | `cmp eax, 0`     | `CMPL AX, $0`  |
| `testl $1, %eax`   | `test eax, 1`    | `TESTL AX, $1` |

### Opcodes

Most opcodes translate by uppercasing: `movq`→`MOVQ`, `addl`→`ADDL`.

Special cases:

- Sign/zero-extend moves: `movsbl`→`MOVBLSX`, `movzbl`→`MOVBLZX`, etc.
- Width conversions: `cltd`→`CDQ`, `cqto`→`CQO`, `cwtl`→`CWDE`
- Conditional jumps: `je`→`JEQ`, `jne`→`JNE`, `jb`→`JCS`, `ja`→`JHI`, etc.
- `sal*` → `SHL*` (Plan 9 has no `SAL`)
- Prefixes: `rep`→`REP;`, `repne`→`REPN;`, `lock`→`LOCK;`
- FPU: `fldl`→`FMOVD`, `fstpl`→`FMOVDP`, `faddp`→`FADDDP`, etc.
- No-suffix instructions (`ret`, `nop`, `hlt`, `leave`, `syscall`, `int3`,
  `pause`, `cpuid`, `pushf`, `popf`, flag ops, etc.) are never given a size
  suffix regardless of mode.

Intel syntax instructions without explicit size suffixes (`push`, `pop`,
`mov`, `add`, `sub`, `cmp`, etc.) are given `Q` on amd64 or `L` on i386.

### Directives

| GNU directive    | Plan 9 output        | Notes                               |
|------------------|----------------------|-------------------------------------|
| `.text`          | `// .text`           | Section directive dropped           |
| `.data`          | `// .data`           | Enters data-section mode (see below)|
| `.bss`           | `// .bss`            |                                     |
| `.globl sym`     | `// GLOBL sym`       | See data section handling           |
| `.byte N`        | `BYTE $N`            | In text; `DATA sym+off(SB)/1,$N` in data |
| `.word N`        | `WORD $N`            | In text; `DATA sym+off(SB)/2,$N` in data |
| `.long N`        | `LONG $N`            | In text; `DATA sym+off(SB)/4,$N` in data |
| `.quad N`        | `QUAD $N`            | In text; `DATA sym+off(SB)/8,$N` in data |
| `.align N`       | `// ALIGN N`         | Dropped; linker handles alignment   |
| `.cfi_*`         | (dropped)            | No DWARF CFI in Plan 9              |
| `.type`, `.size` | (dropped)            | ELF-specific                        |
| `.intel_syntax`  | `// .intel_syntax`   | Triggers Intel mode for the file    |

### Data section handling

When the translator enters a `.data` (or `.bss`) section:

- Labels (`myvar:`) are suppressed as bare labels — they become the symbol
  name for subsequent `DATA` directives.
- Data directives (`.byte`, `.word`, `.long`, `.quad`) are emitted as
  `DATA sym+offset(SB)/size,$value`, with offsets accumulated across
  multiple directives for the same label.
- A `GLOBL sym(SB),flags,$totalsize` line is emitted automatically once all
  data for a symbol has been accumulated (at the next label or end of file).

Example:
```asm
// Input (AT&T)              // Output (Plan 9)
.data
myvar:
    .quad 0x1234             DATA myvar+0(SB)/8,$0x1234
    .long 0xdead             DATA myvar+8(SB)/4,$0xdead
                             GLOBL myvar(SB),4,$12
```

## Comments

| Syntax         | Handled |
|----------------|---------|
| `# comment`    | ✓ stripped |
| `// comment`   | ✓ stripped |
| `/* comment */`| ✓ stripped (single-line) |
| `/* ... */`    | ✓ stripped (multi-line, across lines) |
| `; comment`    | ✓ stripped (Intel mode) |

## Include paths

The native assembler is always invoked with:

```
-I /$objtype/include -I /sys/include
```

`$objtype` is read from the environment (set automatically by the 9front
shell profile and `mk`). This ensures `#include` directives for standard
Plan 9 headers resolve correctly without needing explicit `-I` flags.

**Note on `textflag.h`**: The Go toolchain ships a `textflag.h` that defines
`NOSPLIT`, `RODATA`, etc. as `#define` macros. 9front's native assemblers do
not have this file and their `#include` handling does not support `#define`.
Native 9front Plan 9 assembly uses numeric flag values directly:

| Symbol       | Value |
|--------------|-------|
| `NOPROF`     | 1     |
| `DUPOK`      | 2     |
| `NOSPLIT`    | 4     |
| `RODATA`     | 8     |
| `NOPTR`      | 16    |
| `WRAPPER`    | 32    |
| `NEEDCTXT`   | 64    |

## Installation

This tool has some library dependencies not present in vanilla Plan 9 and is
maintained as part of the **APExp** project. Build from within that tree:

```
cd /sys/src/ape/cmd/as
mk install
```

This installs `as` to `/$objtype/bin/as`.


## Usage

```
as [options] file.s ...
```

| Option            | Description                                      |
|-------------------|--------------------------------------------------|
| `-o outfile`      | Output file name                                 |
| `-att`            | Force AT&T syntax (default: auto-detect)         |
| `-intel`          | Force Intel syntax                               |
| `-plan9`          | Force Plan 9 pass-through (no translation)       |
| `-march=ARCH`     | Target architecture (see table above)            |
| `-m32` / `--32`   | Alias for `-march=386`                           |
| `-m64` / `--64`   | Alias for `-march=amd64`                         |
| `-marm`           | Alias for `-march=arm`                           |
| `-marm64`         | Alias for `-march=arm64`                         |
| `-mppc64`         | Alias for `-march=ppc64`                         |
| `-mmips`          | Alias for `-march=mips`                          |
| `-msparc`         | Alias for `-march=sparc`                         |
| `-m68k`           | Alias for `-march=68000`                         |
| `-I dir`          | Add include directory (passed to native assembler)|
| `-D sym[=val]`    | Define symbol (passed to native assembler)       |
| `-v`              | Verbose: print translated output to stderr       |

Silently ignored (for GNU `as` compatibility):
`--noexecstack`, `--gdwarf-*`, `-g`, `-W`, `-EL`, `-EB`, `-mfpu=*`

### Syntax auto-detection

If no syntax flag is given, the translator inspects the file:

1. If `.intel_syntax` appears → Intel mode
2. If `%`-prefixed registers appear → AT&T mode
3. If Plan 9 idioms appear (`TEXT`, `GLOBL`, `DATA`, `(SB)`, `(FP)`) → Plan 9 pass-through
4. Otherwise → AT&T mode

## Examples

```sh
# Assemble an AT&T syntax file
as -o foo.6 foo.s

# Assemble an Intel syntax file
as -intel -o foo.6 foo.s

# See the translated Plan 9 output without assembling
as -v foo.s 2>&1 | head -40

# Target i386
as --32 -o foo.8 foo.s

# Target ARM
as -marm -o foo.5 foo.s

# Pass an include directory
as -I /sys/include -o foo.6 foo.s
```

## Writing native 9front Plan 9 assembly

Files in native Plan 9 syntax are passed through unmodified. Note that
native 9front assembly differs from Go assembly (which superficially
resembles it):

| Feature           | 9front Plan 9          | Go assembly             |
|-------------------|------------------------|-------------------------|
| Symbol prefix     | `myfunc(SB)`           | `·myfunc(SB)`           |
| TEXT frame spec   | `TEXT f(SB),4,$16`     | `TEXT f(SB),NOSPLIT,$16-8` |
| Flag names        | Raw numbers (`4`)      | Macros (`NOSPLIT`) via `textflag.h` |
| `#define`         | Not supported by `6a`  | Preprocessed by Go toolchain |

Example of correct 9front Plan 9 assembly:

```asm
// myfunc adds two 64-bit integers
TEXT myfunc(SB),4,$0
    MOVQ    a+0(FP), AX
    MOVQ    b+8(FP), BX
    ADDQ    BX, AX
    MOVQ    AX, ret+16(FP)
    RET

// Read-only global: flags = RODATA(8)|NOPTR(16) = 24
GLOBL mydata(SB),24,$8
DATA mydata+0(SB)/8,$0x1234567890abcdef
```

## Limitations

1. **Byte-register size inference (Intel mode)**: Intel `mov al, 0xff`
   produces `MOVQ $0xff, AL` instead of `MOVB`. The translator adds a size
   suffix based on the architecture default (Q for amd64), not the actual
   register width. This affects code using 8-bit or 16-bit registers in
   Intel syntax; AT&T syntax is unaffected since the suffix is explicit.

2. **GLOBL for text symbols**: `.globl funcname` on a function is commented
   out — Plan 9 exports functions via the `TEXT` directive itself, and the
   translator cannot know the function size needed for a standalone `GLOBL`.

3. **`.string` / `.ascii`**: String literal directives are commented out.
   Plan 9 string data is typically in C source, not assembly.

4. **Gas macro system**: `.macro` / `.endm` are not supported. Macros should
   be expanded by `cpp` before passing to `as`.

5. **DWARF debug info**: All `.cfi_*`, `.loc`, `.file` directives are dropped.
   This is correct for Plan 9, which uses its own debug format.

6. **RISC opcode translation**: For non-x86 targets, opcodes are translated
   by uppercasing only. There are no arch-specific opcode exception tables for
   ARM, MIPS, SPARC, etc. Most RISC opcodes happen to have the same name in
   GNU as and Plan 9, but edge cases will need manual review.

7. **Intel syntax for non-x86**: Intel operand order swapping is only
   implemented for x86/amd64. RISC targets in Intel syntax should use
   `-att` or `-plan9`.

8. **Multi-line macro expressions**: Complex constant expressions in
   operands are passed through as-is and resolved by the Plan 9 assembler's
   own expression evaluator.

## Source layout

```
/sys/src/ape/cmd/as/
    as.c      main translator and driver (~2100 lines)
    mkfile    Plan 9 build file
```

## Integration with mk-based builds

```
# mkfile fragment
AS=as

%.6: %.s
    $AS -o $target $prereq
```

Or set `AS=as` in the environment so third-party `mk` files using `$AS`
work automatically.
