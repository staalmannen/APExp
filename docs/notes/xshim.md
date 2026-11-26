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
