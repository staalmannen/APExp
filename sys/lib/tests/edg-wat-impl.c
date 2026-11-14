/*
 * edg-wat-impl.c -- the body of EDG's allocation watch, kept here so
 * that the patcher has ONE copy to insert and this file is the thing
 * to read and edit.  It is prepended verbatim to
 * `sys/src/external/edg/src/mem_manage.c'; it is not compiled on its
 * own and is not in any mkfile.
 *
 * ---- WHAT IT ANSWERS -------------------------------------------------
 *
 * `get_token_from_reusable_cache_stack' faults on `token', which comes
 * straight out of `cache->tokens.elems[off]'.  Measured: `off=0',
 * `n=23', `cache == endcache', elements 1..22 all plausible control
 * blocks, elems[0] = 0x3f4b1 -- and the four words BELOW `elems' are
 * `{pointer, 9, pointer, 0x4d1b}', the same tail recorded for `prev'
 * when the first crash landed the same value on a region link.  So one
 * write, one word past some object, two different victims.
 *
 * The question left is WHICH object, and the only thing that names it
 * is its SIZE, matched against EDG's structs.
 *
 * ---- WHY SIZE AND NOT ADDRESS ----------------------------------------
 *
 * ***THE FIRST VERSION WATCHED AN ADDRESS AND THE ADDRESS MOVED.***
 * `elems' was byte-identical in two runs (0x03c15290, different pids),
 * so it looked like a handle.  It is not: the next build answered
 * `elems = 0x03c159a0', **0x710 = 1808 bytes higher, which is exactly
 * the BSS that build added** (64 slots of 8+8+4+4+4, plus 16).  The FE
 * layout is deterministic relative to the HEAP BASE, and the heap base
 * sits above BSS -- so any instrument that watches an absolute address
 * moves the thing it is watching, by its own size.  *A measurement
 * whose apparatus is in the quantity being measured.*
 *
 * The victim's SIZE does not move: 31 slots of 8 bytes = 248, from
 * `grow's `new_cap = old_cap + old_cap/2 + 1' rounded up by
 * `alloc_fe_var_size'.  So the watch triggers on a size and records
 * the allocation IMMEDIATELY BEFORE it -- which, since
 * `alloc_in_region' bumps sequentially, is the object the victim sits
 * on top of.  `prev_size' is then the number to match against EDG's
 * structs, and `prev_ptr + prev_size == ptr' is the check that the two
 * really are adjacent rather than merely consecutive calls.
 *
 * ---- WHY EVERY COPY, AND WHY THE COUNT IS LOAD-BEARING ---------------
 *
 * `alloc_fe' has **41** definitions and `alloc_fe_var_size' **34**,
 * one per TU that uses it, and `cmd/edg/mkfile' passes `-C' so `6l'
 * keeps the FIRST and discards the rest.  Patching a subset therefore
 * patches a copy that may not be the live one -- which is what
 * happened: 27 copies were patched, the surviving definition was one
 * of the other 14, and `edg_wat_calls' came back **0**.
 *
 * *Without that counter the run would have read as "the watch address
 * moved"*, which was also true and was not the reason.  Two true
 * statements, one of them irrelevant, and only the count separates
 * them.
 *
 * ***AND THE MISS WAS IN THE VERIFICATION, NOT ONLY IN THE PATCH.***
 * The patcher keyed on EDG's temp names, assuming COMDAT text is
 * identical across TUs; 14 files number their temps differently.  The
 * check that was supposed to catch that counted files matching *the
 * same temp-name anchor*, so it agreed with the patch by construction
 * and reported 27 of 27.  **A check phrased against the thing under
 * test instead of against something independent of it** -- this tree's
 * own rule, and the independent phrasing is "every file that DEFINES
 * the function, found without reference to any temp name, must contain
 * a call".
 */

unsigned long long edg_wat_watch = 248ULL;	/* the victim's size */
void *edg_wat_prev_ptr;
unsigned long long edg_wat_prev_size;

void *edg_wat_ptr[32];
unsigned long long edg_wat_size[32];
void *edg_wat_pptr[32];
unsigned long long edg_wat_psize[32];
long edg_wat_adj[32];
long edg_wat_kind[32];
long edg_wat_n;
long edg_wat_hits;
long edg_wat_calls;

void
edg_wat_note(void *p, unsigned long long sz, long kind)
{
  edg_wat_calls = edg_wat_calls + 1;
  if (p == (void *)0)
    return;
  if (sz == edg_wat_watch) {
    edg_wat_hits = edg_wat_hits + 1;
    if (edg_wat_n < 32) {
      edg_wat_ptr[edg_wat_n] = p;
      edg_wat_size[edg_wat_n] = sz;
      edg_wat_pptr[edg_wat_n] = edg_wat_prev_ptr;
      edg_wat_psize[edg_wat_n] = edg_wat_prev_size;
      edg_wat_adj[edg_wat_n] =
        (((unsigned long long)edg_wat_prev_ptr) + edg_wat_prev_size
          == (unsigned long long)p) ? 1 : 0;
      edg_wat_kind[edg_wat_n] = kind;
      edg_wat_n = edg_wat_n + 1;
    }
  }
  edg_wat_prev_ptr = p;
  edg_wat_prev_size = sz;
}

