# as — GNU assembler syntax front-end for 9front

A drop-in `as` replacement for 9front that translates GNU assembler (GAS)
syntax — both AT&T and Intel — into Plan 9 assembly, then invokes the
native `6a` (amd64) or `8a` (i386) assembler.

This allows third-party `.s` files written for GNU `as` to be assembled
on Plan 9 without modification, fitting naturally into the Plan 9 build
system and tool chain.

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
  6a / 8a  (native Plan 9 assembler)
    │
    ▼
  foo.6 / foo.8  (object file)
```

The translator is a single-pass text transformer. It is intentionally not
a full parser — it handles the 95% case well and comments out directives
it cannot translate, so the output is always valid Plan 9 assembly (though
some features may be elided).

## Syntax differences handled

### Registers

| AT&T / Intel  | Plan 9  |
|---------------|---------|
| %rax / rax    | AX      |
| %eax / eax    | AX      |
| %ax  / ax     | AX      |
| %al  / al     | AL      |
| %xmm0 / xmm0 | X0      |
| %mm0 / mm0    | M0      |
| %st(0) / st   | F0      |
| %cs / cs      | CS      |

### Memory addressing

| AT&T                    | Plan 9                |
|-------------------------|-----------------------|
| `(%rsp)`                | `0(SP)`               |
| `8(%rbp)`               | `8(BP)`               |
| `-4(%rbp)`              | `-4(BP)`              |
| `(%rax,%rbx,4)`         | `0(AX)(BX*4)`         |
| `16(%rax,%rbx,8)`       | `16(AX)(BX*8)`        |
| `symbol(%rip)`          | `symbol(SB)`          |
| `[rax+rbx*4+16]`        | `16(AX)(BX*4)`        |

### Operand order

- AT&T: `src, dst` — Plan 9: `src, dst` — **same order, no change needed**
- Intel: `dst, src` — Plan 9: `src, dst` — **operands are swapped**

### Opcodes

Most opcodes translate by simply uppercasing:
`movq` → `MOVQ`, `addl` → `ADDL`, `syscall` → `SYSCALL`

Special cases handled:
- `movsbl` → `MOVBLSX`, `movzbl` → `MOVBLZX`, etc.
- `cltd` → `CDQ`, `cqto` → `CQO`, `cwtl` → `CWDE`
- AT&T conditional jump aliases: `je`→`JEQ`, `jne`→`JNE`, `jb`→`JCS`, etc.
- AT&T `sal*` → Plan 9 `SHL*`
- Prefixes: `rep`, `repne`, `lock` → `REP;`, `REPN;`, `LOCK;`
- FPU: `fldl`→`FMOVD`, `fstpl`→`FMOVDP`, etc.

### Directives

| GNU / AT&T     | Plan 9          | Notes                        |
|----------------|-----------------|------------------------------|
| `.text`        | (dropped)       | Plan 9 doesn't need sections |
| `.data`        | (dropped)       |                              |
| `.globl sym`   | (commented)     | Use GLOBL in TEXT directive  |
| `.byte N`      | `BYTE $N`       |                              |
| `.word N`      | `WORD $N`       |                              |
| `.long N`      | `LONG $N`       |                              |
| `.quad N`      | `QUAD $N`       |                              |
| `.align N`     | (commented)     | Handled by linker            |
| `.cfi_*`       | (dropped)       | No DWARF CFI needed          |
| `.type`        | (dropped)       |                              |
| `.size`        | (dropped)       |                              |
| `.intel_syntax`| (dropped)       | Triggers Intel mode          |

## Installation

Copy the source to your 9front source tree:

```
cp -r src /sys/src/cmd/as
```

Then build and install:

```
cd /sys/src/cmd/as
mk install
```

This installs `as` to `/$objtype/bin/as`.

## Usage

```
as [options] file.s ...
```

Options:
```
  -o outfile       output file name
  -att             force AT&T syntax (default: auto-detect)
  -intel           force Intel syntax
  -m32 / --32      target i386, use 8a
  -m64 / --64      target amd64, use 6a [default]
  -I dir           add include search directory (passed to 6a/8a)
  -D sym[=val]     define symbol (passed to 6a/8a)
  -v               verbose: show translated output on stderr
```

Auto-detection: if the input file contains `.intel_syntax`, Intel mode is
used. If it contains `%`-prefixed registers, AT&T mode is used. Otherwise
AT&T is assumed.

## Limitations

1. **RIP-relative addressing**: Translated to `symbol(SB)` where possible,
   but complex RIP+offset expressions may need manual adjustment.

2. **GLOBL directive**: `.globl` is commented out. Plan 9 exports symbols
   via the `GLOBL` pseudo-op in the `TEXT` directive, which requires knowing
   the function size. The translator cannot infer this.

3. **`.string` / `.ascii`**: String literals are commented out with a note.
   Plan 9 string data is typically in C source, not assembly.

4. **Gas macro system**: `.macro`/`.endm` are not supported — these should
   be handled by the C preprocessor (`cpp`) before passing to `as`.

5. **DWARF debug info**: All `.cfi_*`, `.loc`, `.file` directives are
   dropped, which is correct for Plan 9 (it uses its own debug format).

6. **x87 FPU operand order**: AT&T reverses the operands for some x87
   instructions (`faddp st(1),st` etc.); this translation handles the
   common cases but obscure x87 operand combinations may need review.

7. **Intel syntax size overrides**: `BYTE PTR`, `WORD PTR`, `DWORD PTR`,
   `QWORD PTR` are stripped. The size information is carried in the Plan 9
   opcode suffix instead (MOVB, MOVW, MOVL, MOVQ).

## Differences from GNU as

- No support for ELF-specific directives (`.section`, `.type`, `.size`)
  beyond commenting them out — Plan 9 uses its own object format.
- No expression evaluation in operands beyond what the C preprocessor
  and Plan 9 assembler already handle.
- GNU `as` long option names (e.g. `--noexecstack`, `--gdwarf-2`) are
  silently ignored where harmless, warned about otherwise.

## Examples

Assembling a file in AT&T syntax:
```
as -o foo.6 foo.s
```

Assembling a file in Intel syntax:
```
as -intel -o foo.6 foo.s
```

Seeing the translated Plan 9 output without assembling:
```
as -v foo.s 2>&1 | head -40
```

Targeting i386:
```
as --32 -o foo.8 foo.s
```

## Source layout

```
/sys/src/cmd/as/
    as.c      - main translator and driver
    mkfile    - Plan 9 build file
```

## Integration with mk-based builds

In a `mkfile`, replace `as` calls:

```
%.6: %.s
    as -o $target $prereq
```

Or set `AS=as` in your build environment and third-party makefiles that
use `$(AS)` will work automatically.
