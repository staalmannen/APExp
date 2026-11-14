/*
 * edg-wat-impl.c -- the body of EDG's allocation record, kept here so
 * the patcher has ONE copy to insert and this file is the thing to
 * read and edit.  It is prepended verbatim to
 * `sys/src/external/edg/src/mem_manage.c'; it is not compiled on its
 * own and is in no mkfile.
 *
 * ---- THE QUESTION ----------------------------------------------------
 *
 * `get_token_from_reusable_cache_stack' faults on `token', which comes
 * from `cache->tokens.elems[0]'.  Measured: `off=0', `n=23',
 * `cache == endcache', elements 1..22 all plausible control blocks,
 * `elems[0] = 0x3f4b1', and the four words BELOW `elems' are
 * `{pointer, 9, pointer, 0x4d1b}' -- the same tail recorded for `prev'
 * when the first crash put the same value on a region link.  One
 * write, one word past something, two different victims.
 *
 * What is left is WHICH object owns the bytes below `elems'.
 *
 * ---- TWO WAYS OF ASKING THAT FAILED, AND WHY ------------------------
 *
 * ***AN ADDRESS WATCH MOVES THE THING IT WATCHES.***  `elems' was
 * byte-identical in two runs, which read as a handle.  It is not: FE
 * addresses track the HEAP BASE and the heap base sits above BSS, so
 * each build moved it by exactly the BSS that build added -- 1808
 * bytes one way, then 496 back.  *Apparatus inside the quantity
 * measured*, confirmed twice.
 *
 * ***AND "THE PREVIOUS ALLOCATION" IS NOT THE NEIGHBOUR.***  Watching
 * the victim's SIZE (248 bytes) and recording the allocation before it
 * answered **adj=0 on 31 of 32 rows** -- the two were consecutive
 * CALLS and nowhere near each other in memory.  The reason was already
 * in the source and I did not carry it over: `alloc_fe_var_size' serves
 * anything under 2096 bytes off `reusable_fe_list', so bump order and
 * address order have almost nothing to do with each other.  The same
 * `ptr' comes back fifteen times in 32 rows.
 *
 * ---- SO IT AIMS ITSELF ----------------------------------------------
 *
 * Every allocation is appended to a flat table, and the table is
 * searched ONCE, from inside `edg_tok_note', at the first lookup whose
 * token is not a plausible address -- which is the faulting lookup,
 * reached *before* the dereference.  Nothing is hardcoded: no address,
 * no size, no ring depth.  The search asks two questions of the real
 * `elems':
 *
 *	which allocation ENDS at it	-> the object that overran
 *	which allocation STARTS at it	-> the victim buffer
 *
 * **The COUNTS are reported, not just the last match**, because these
 * blocks are recycled: an address can be handed out many times, so
 * "one entry ends here" and "nine do" are different findings and the
 * most recent is only a guess at which one was live.
 *
 * ***THE TABLE DOES NOT WRAP, IT STOPS.***  The victim sits at
 * 0x03c1.... in the LOW heap, i.e. it was allocated early, so a ring
 * would evict exactly the entry wanted -- the mistake the link ring
 * already made once, when it held the last 4096 of 7459 and every one
 * was at a higher address than the victim.  `edg_wat_over' counts what
 * did not fit; a nonzero value with no match means the table was too
 * small, which is a different answer from "no allocation ends there".
 */

#define EDG_WAT_MAX (1 << 20)

void *edg_wat_all_ptr[EDG_WAT_MAX];
unsigned int edg_wat_all_size[EDG_WAT_MAX];
unsigned char edg_wat_all_kind[EDG_WAT_MAX];	/* 1 alloc_fe, 2 var_size */
long edg_wat_all_n;
long edg_wat_over;
long edg_wat_calls;

/* filled in once, by edg_wat_find */
long edg_wat_found;
void *edg_wat_target;
long edg_wat_nbr_cnt;
long edg_wat_vic_cnt;

/*
 * ***EVERY MATCH, NOT THE LAST ONE.***  `nbr_cnt' came back 2 and
 * `vic_cnt' 5, so both ranges are handed out repeatedly -- these
 * blocks live on `reusable_fe_list' and come back.  Reporting only the
 * most recent match is reporting a guess about which allocation was
 * live, and the whole history is eight slots and costs nothing.
 *
 * `kind' is the datum this round exists for.  **No 32-byte EDG struct
 * has the shape the neighbour actually holds** -- `{ptr, 9, ptr,
 * 19739}', with the two numbers identical across runs and across
 * inputs while the pointers move -- which was checked against every
 * aggregate the host `6c -a' emits for seven TUs, none matching.  So
 * `kind == 1' (a fixed `alloc_fe(32)') would mean a struct outside
 * that set, while `kind == 2' means an `alloc_fe_var_size' buffer,
 * i.e. a Dyn_array of two 16-byte elements -- which is what two
 * `{pointer, number}' pairs look like.
 */
#define EDG_WAT_HIST 8
void *edg_wat_nbr_ptr[EDG_WAT_HIST];
unsigned long long edg_wat_nbr_size[EDG_WAT_HIST];
long edg_wat_nbr_kind[EDG_WAT_HIST];
long edg_wat_nbr_idx[EDG_WAT_HIST];
void *edg_wat_vic_ptr[EDG_WAT_HIST];
unsigned long long edg_wat_vic_size[EDG_WAT_HIST];
long edg_wat_vic_kind[EDG_WAT_HIST];
long edg_wat_vic_idx[EDG_WAT_HIST];

void
edg_wat_note(void *p, unsigned long long sz, long kind)
{
  edg_wat_calls = edg_wat_calls + 1;
  if (p == (void *)0)
    return;
  if (edg_wat_all_n >= EDG_WAT_MAX) {
    edg_wat_over = edg_wat_over + 1;
    return;
  }
  edg_wat_all_ptr[edg_wat_all_n] = p;
  edg_wat_all_size[edg_wat_all_n] = (unsigned int)sz;
  edg_wat_all_kind[edg_wat_all_n] = (unsigned char)kind;
  edg_wat_all_n = edg_wat_all_n + 1;
}

/*
 * Called once, from the faulting lookup, before the dereference that
 * kills the process.  A linear scan of ~600k entries costs nothing at
 * that point and is exact, where every clever indexing scheme tried so
 * far has answered about the wrong object.
 */
void
edg_wat_find(void *target)
{
  long i;
  unsigned long long t, a, s;

  if (edg_wat_found)
    return;
  edg_wat_found = 1;
  edg_wat_target = target;
  t = (unsigned long long)target;
  for (i = 0; i < edg_wat_all_n; i++) {
    a = (unsigned long long)edg_wat_all_ptr[i];
    s = (unsigned long long)edg_wat_all_size[i];
    if (a + s == t) {
      if (edg_wat_nbr_cnt < EDG_WAT_HIST) {
        edg_wat_nbr_ptr[edg_wat_nbr_cnt] = edg_wat_all_ptr[i];
        edg_wat_nbr_size[edg_wat_nbr_cnt] = s;
        edg_wat_nbr_kind[edg_wat_nbr_cnt] = (long)edg_wat_all_kind[i];
        edg_wat_nbr_idx[edg_wat_nbr_cnt] = i;
      }
      edg_wat_nbr_cnt = edg_wat_nbr_cnt + 1;
    }
    if (a == t) {
      if (edg_wat_vic_cnt < EDG_WAT_HIST) {
        edg_wat_vic_ptr[edg_wat_vic_cnt] = edg_wat_all_ptr[i];
        edg_wat_vic_size[edg_wat_vic_cnt] = s;
        edg_wat_vic_kind[edg_wat_vic_cnt] = (long)edg_wat_all_kind[i];
        edg_wat_vic_idx[edg_wat_vic_cnt] = i;
      }
      edg_wat_vic_cnt = edg_wat_vic_cnt + 1;
    }
  }
}

