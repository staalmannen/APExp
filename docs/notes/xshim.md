# xshim: merging Tk's Xlib-over-draw layer into one library

## Where things stand

- `sys/src/ape/lib/xshim` is a thin first milestone: one rio window, 34
  functions, GCs, rectangles and lines, and key, button, motion and expose
  events decoded from libdraw's `eread`.  Public header: `sys/include/ape/xshim.h`
  (types in `xshim_types.h`); `X11/Xlib.h` and `X11/X.h` are aliases for them.
- Tk's Plan 9 port already has a fuller version of the same idea:
  `sys/src/external/tk/xlib` (xcolors, xdraw, xgc, ximage, xutil) and
  `sys/src/external/tk/plan9` define 161 X functions.  Its window model is a
  software window tree drawn into one rio window: each `P9Window` has an XID,
  a parent, a rectangle and a stacking position, and drawing goes through
  `dstimage`.  That is the same single-window principle as xshim, with
  children, pixmaps, colormaps, regions and input-method stubs added.

## Overlap (measured, not estimated)

Defined by both (16): XClearWindow, XCreateGC, XCreateSimpleWindow,
XDestroyWindow, XDrawLine, XDrawRectangle, XFillRectangle, XFillRectangles,
XFlush, XMapWindow, XNextEvent, XSelectInput, XSetBackground,
XSetForeground, XSetLineAttributes, XSync, XUnmapWindow.

Defined only by xshim (10): XBlackPixel, XCloseDisplay, XDefaultRootWindow,
XDefaultScreen, XDisplayHeight, XDisplayWidth, XFreeGC, XOpenDisplay,
XPending, XWhitePixel.  Tk does not define these because it opens rio through
`initdraw` directly in `tkPlan9DrawImpl.c`.

Defined only by Tk (144): the rest of the Xlib surface Tk uses, including
XCreateWindow, XReparentWindow, XRaiseWindow, XMoveResizeWindow,
XCreatePixmap, XCopyArea, XPutImage, XAllocColor, XSetInputFocus and the
region and input-method functions.

## Phase 1 finding: the move is not self-contained

Attempted, then stopped before changing any file.  All 13 Tk X-layer files
(`xlib/*.c` and the X-API files of `plan9/`) include Tk-internal headers
(`tk.h`, `tkInt.h`, `tkPlan9Int.h`, `tkPort.h`, Tcl headers), and they call
Tk-internal symbols: `TkRegion`, `TkCreateRegion`, `TkSetRegion`,
`TkDestroyRegion`, `TkpClipMask`, `TkpGetPixel`, `TkpCopyRegion`,
`Tk_GetPixmap`, `Tk_FreePixmap`, `Tk_Uid`, `ckalloc`, `ckfree`.  Moving the
files as they are would make `libxshim` depend on Tk's headers and on Tcl's
allocator, which defeats a thin general library.

Also, `plan9/tkPlan9Init.c`, `tkPlan9Draw.c` and `tkPlan9Wm.c` mix X-API
functions with Tk glue (`Tkp*` hooks, window manager policy), so they cannot
be split into "X" and "Tk" by file.

Revised phase 1, to be approved before any code moves:

1. Give the library its own allocator and region type (`xs_alloc`, `xs_free`,
   and a bounding-box region as in `tkPlan9Stubs.c`).  Replace `ckalloc`,
   `ckfree` and `Tk*Region` in the X-layer files with these.  This is a
   source change, so it is gated by the suite.
2. Replace each Tk hook (`TkpClipMask`, `TkpGetPixel`, `Tk_GetPixmap`,
   `Tk_FreePixmap`, `Tk_Uid`) with a callback the library exposes, which Tk
   registers at startup.  The library then never names a Tk symbol.
3. Only after 1 and 2 build with no Tk include, move the files.  Tk keeps the
   glue (`Tkp*` policy, window manager) in `plan9/`, and calls into the library.

Each of these steps is a behaviour-neutral edit, so it has to pass the same
suite gate as a move would.

## Step 1 inventory (measured, nothing moved yet)

Tk-referencing lines per file: `xlib/xgc.c` 33 of 830, `xlib/xcolors.c` 5 of 599,
`xlib/ximage.c` 4 of 74, `xlib/xutil.c` 4 of 113, `xlib/xdraw.c` 1 of 88,
`plan9/tkPlan9Init.c` 78 of 1515, `plan9/tkPlan9Draw.c` 38 of 1037,
`plan9/tkPlan9Event.c` 40 of 575, `plan9/tkPlan9Font.c` 107 of 693,
`plan9/tkPlan9Color.c` 30 of 182, `plan9/tkPlan9Wm.c` 676 of 4031,
`plan9/tkPlan9Stubs.c` 153 of 943, `plan9/tkPlan9DrawImpl.c` 5 of 801.

Classification:

- **Tk glue, stays in the Tk tree:** `plan9/tkPlan9Wm.c`, `plan9/tkPlan9Font.c`,
  `plan9/tkPlan9Stubs.c`, and the `Tk_*`/`Tcl_*` parts of `tkPlan9Init.c`,
  `tkPlan9Event.c`, `tkPlan9Color.c`.  They use `Tk_Window`, `TkWindow`,
  `Tcl_Obj` and Tk's window-manager policy, so they cannot move.
- **X API that must move, and needs a decision first:**
  - *GC.*  Tk's `struct _XGC` carries a clip mask, dash state and fill and
    stipple settings.  xshim's GC is two images.  Decision: the library owns
    the richer structure.
  - *Clip mask.*  `TkpClipMask` (15 uses) becomes a library type.
  - *Regions.*  `TkRegion`, `TkCreateRegion`, `TkSetRegion`,
    `TkDestroyRegion`, `TkUnionRectWithRegion`, `TkCopyRegion`.  The Tk stub
    already uses a bounding-box `struct _XRegion`, so the library takes that
    and drops the `Tk` names.
  - *Pixmaps.*  `Tk_GetPixmap`/`Tk_FreePixmap` (ximage.c) become library
    pixmaps, which are draw images.  `TkPutImage` is Tk's and needs a library
    equivalent.
  - *Atoms.*  `Tk_Uid` (xutil.c) becomes a library atom table; no Tk uid.
  - *Allocator and errors.*  `ckalloc`/`ckfree` become `malloc`/`free`;
    `Tcl_Panic` becomes an error callback the library exposes.
  - *Colours.*  `TkpGetPixel` (xcolors.c) is a Tk policy hook: the library
    gets the pixel from its own colour code, and Tk does not need the hook.
- **Hooks Tk registers:** none of the above should need a Tk-side hook once
  the library owns its types.  If a Tk policy must run (for example, clipboard
  or the rio label), it is a callback set at `XOpenDisplay`, not a symbol.

## Decisions needed before step 1 can be coded

1. GC: adopt Tk's `struct _XGC` (clip, dash, stipple fields) as the library's
   public GC, or keep xshim's two-image GC and map Tk's fields onto it?
   Recommendation: adopt Tk's fields, since Tk's 33 uses of the GC depend on
   them.
2. Atoms: a library-side table of interned strings, returned as `Atom`
   integers, or direct use of the strings?  Recommendation: integers, to match
   the X API Tk already calls.
3. Error and policy callbacks: one `xs_error` hook set at `XOpenDisplay`, or a
   set of named hooks?  Recommendation: one error hook, and no policy hooks.

## Plan

Every phase has the same gate: Tk builds with `mk install` on 9front, and
the Tk suite (`sys/lib/tests/tk-runall.tcl`) reports the same per-file
failures as before the phase.  Baseline: `tmp/tk-runall-baseline.out` on `main` (matches `CLAUDE.md`):
`Total 10027 Passed 8926 Skipped 924 Failed 177`, 97 files.  The 177 failing
test names are in `docs/notes/tk-baseline-failing.txt`.  A phase that
moves any failing test name is a regression even if the total is unchanged.

1. **Move, do not change.**  Copy Tk's `xlib/*.c` and the X-API files of
   `plan9/` into `sys/src/ape/lib/xshim`.  Keep their names and behaviour.
   Tk links `libxshim.a` instead of its own objects.  Tk keeps its own
   `xlib/X11` headers for its compiles, so no header changes in this phase.
2. **Retire the thin duplicates.**  For the 16 overlapping names, keep Tk's
   version and delete xshim's.  Keep xshim's event decoding only if Tk's
   event path does not already cover it; otherwise delete it too.
3. **One public header.**  Grow `xshim.h` to declare what Tk's layer
   implements (the 161 functions and their types), and point Tk's compiles
   at it.  Remove `xlib/X11` from Tk's include path once the types agree.
   The two copies define some of the same structs, so this step is where
   any mismatch shows up.
4. **Unify the display.**  Tk's display state and xshim's `xs_dpy` become
   one structure, owned by the library, with the 10 xshim-only functions
   added to Tk's side.
5. **Clean up.**  Delete code the suite no longer reaches; decide whether
   the Plan 9 `XNextEvent` and Tk's event loop should share one queue.

## Risks

- Tk's `xlib/X11` and `sys/include/ape/xshim.h` define overlapping structs
  (`XSetWindowAttributes`, `XImage`, `Visual`, `Region`).  Two definitions
  that disagree compile in separate translation units and fail at run time;
  a host `gcc -M` scan does not catch that.  Phase 3 needs a layout check
  (`sizeof` and `offsetof` against a reference compiled from both headers).
- The gate needs 9front.  The host can check headers and link shape but
  cannot run Tk.

## Gate record

- **Step 1a, XInternAtom moved into libxshim** (`tmp/tk-runall-xshim1.out` on
  `main`, run 03:55): Total 10027, Passed 8926, Skipped 924, Failed 177.  The
  177 failing names are identical to `docs/notes/tk-baseline-failing.txt`: no
  new failures, no fixes.  The request-counter deviation did not move any test.

## Step 1b (regions), applied, awaiting the 9front gate

- Moved into `libxshim` (`xs_region.c`): the region struct and the X region
  API from `plan9/tkPlan9Stubs.c`, and the three region stubs that were in
  effect from `plan9/tkPlan9Draw.c` (`XPointInRegion`, `XUnionRegion`,
  `XPolygonRegion`).  Those three are still stubs; moving them unchanged keeps
  behaviour, and implementing them is a separate gated step.
- New library function `XCopyRegion`, which Tk's `TkpCopyRegion` now calls in
  place of a struct copy, so Tk no longer reads region fields.
- Removed from Tk: the moved definitions in `tkPlan9Stubs.c` and
  `tkPlan9Draw.c`, and the dead duplicates in `xlib/xgc.c`.  `TkpBuildRegionFromAlphaData`
  stays in Tk; it only calls `XUnionRectWithRegion`.
- `ckalloc`/`ckfree` in the region code become `malloc`/`free`.  The one
  behaviour difference: `XCreateRegion` returns NULL on allocation failure,
  where `ckalloc` panicked.
- Checks: `xs_region.c` compiles with APE headers only (no libdraw); the three
  edited Tk files pass a `gcc -fsyntax-only` with the Tk include order.
- **Step 1b, regions moved into libxshim** (`tmp/tk-runall-xshim2.out` on
  `main`, run 04:09): Total 10027, Passed 8926, Skipped 924, Failed 177.  The
  177 failing names are identical to the baseline and to the step 1a run.  No
  test touches the region code's out-of-memory path.

## Step 1c (GC and clip mask), applied, awaiting the 9front gate

- The GC is `XGCValues *`, as in Tk's port: the library's `XGCValues` is Tk's
  copied verbatim, with the GC mask and value constants.  A host check
  compares the layout and all 69 constants against Tk's own `Xlib.h`: identical.
- Moved into `libxshim` (`xs_gc.c`): `XCreateGC`, `XChangeGC`, `XFreeGC`, the
  `XSet*` family, `XSetClipMask`, `XSetClipRectangles`, and `XSetRegion`
  (Tk's `TkSetRegion`).  Removed from Tk's `xlib/xgc.c`; the rest of that file
  is `#if 0` code that was already dead.
- The library's thin `gc.c` is retired.  `draw.c` now draws from the GC's
  pixel and makes a 1x1 image per call.
- `Font` is typed `XID` inside the shared header, because libdraw owns the name
  `Font`.  The public header declares `typedef XID Font`.
- Faults carried over unchanged, to fix in their own gated steps:
  - `XSetRegion` stores the caller's region and then overwrites the pointer, so
    the region is not kept.
  - The clip mask is a heap pointer stored in a `Pixmap`, which is an
    `unsigned long`.  On kencc, `long` is 32 bits and pointers are 64, so the
    clip mask pointer is truncated.  The Tk code has the same cast.
  - `draw.c` does not apply the GC's clip mask yet.
- The `XSetDashes` Windows-only `TkWin*` calls are dropped; they were under an
  `#ifdef` that never holds on Plan 9.
- **Step 1c, GC and clip mask moved into libxshim** (`tmp/tk-runall-xshim3.out`
  on `main`, run 05:44): Total 10027, Passed 8926, Skipped 924, Failed 177.
  The 177 failing names are identical to the baseline.  Against run 2 the only
  differences are the two timestamp lines, which is why the byte count is the
  same across runs.
- Build warnings to clear in a later step: `xs_gc.c:56` converts a pointer to a
  shorter integer (the clip-mask truncation above, now visible to the compiler),
  and `xs_region.c` has unused parameters in the three stubs.
