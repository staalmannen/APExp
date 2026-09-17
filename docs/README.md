# APExp documentation

| | |
|---|---|
| `posix-coverage.md` | what of POSIX/musl is present, missing or stubbed, compared file by file against musl's `src/` |
| `compiler-improvements.md` | what has been done to the Plan 9 C compilers and what is still open |
| `releases/` | release notes, one file per release |
| `notes/` | working notes: the bugs found in this tree, what each cost, and how it was found. One file per area -- `kencc`, `libap`, `invariants`, `tk-plan9`, `tcl-suite` |

`notes/` is the project's memory. It is written as the work happens, so
it records refuted hypotheses and wrong turns as well as fixes -- that is
deliberate, and it is most of its value. `CLAUDE.md` in the repository
root is the short version: the build system, the method rules distilled
to one line each, and what is currently open.
