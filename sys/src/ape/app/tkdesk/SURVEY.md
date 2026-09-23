# TkDesk on APExp: surveyed, and NOT attempted

**Measured on the build host, before any VM round, and the answer is
that TkDesk is the wrong stress test for this tree.** Nothing here is
a guess: every number below came from a gcc sweep of the vendored
sources against this tree's own Tcl 9 and Tk headers.

## What TkDesk expects

`INSTALL:39` — *"TkDesk now requires Tcl/Tk 8.0 - 8.4"*, with itcl
**3.x** (`INSTALL:50`). This tree has **Tcl 9.0.3 and itcl 4.2.3**,
and itcl 4 is not a compatible successor to itcl 3 — it is a rewrite
on TclOO.

One piece of good news, checked rather than assumed: **no `itk` or
`iwidgets` dependency**, so the `[incr Tk]` widget set is not needed.

## The size of the gap

C, 23 files — **8 compile clean, 15 do not**, ~347 errors:

| idiom | count | why it fails |
|---|---|---|
| `_ANSI_ARGS_` | 295 | Tcl 8's prototype macro, removed in Tcl 9 |
| `interp->result` | 46 | `Tcl_Interp` is opaque in Tcl 9 |
| `Tcl_Value`, `Tcl_CreateMathFunc` | 12 | the old math-function API, removed |

Scripts: **22902 lines** of Tcl/itcl with **35 `itcl::class`
definitions** written against itcl 3.x semantics.

## Why that makes it the wrong test

The point of TkDesk here was *what a large Tcl/Tk application drags
out of libap and the compilers on the way up*. **It cannot reach
them.** The build stops at Tcl-version archaeology in vendored
third-party C — not one of those 347 errors is about Plan 9, kencc,
libap or this port. Fixing them would be a Tcl 8.4→9.0 migration of
somebody else's application, and the 23k lines of itcl-3 script behind
it are very likely the larger half again.

Compare what the same sweep bought on itcl, where the four findings
were all real and all ours-or-configuration: there the host sweep
found bugs, here it found a version gap.

## What is kept

`config.h`, hand-answered for APE the way perl's and Tcl's are, since
APExp does not run configure. It was needed to get past the first
error and measure anything at all, and it is correct work if TkDesk is
ever revisited — the header and function answers are read off this
tree rather than guessed, and `mode_t`/`pid_t`/`size_t` are
deliberately left undefined because APE has real typedefs and
autoconf's substitutes would shadow them.

**If a proof-of-concept application is still wanted, it should be one
written for Tcl 8.6+ and itcl 4**, so that what it exercises is this
port rather than two decades of Tcl API change.
