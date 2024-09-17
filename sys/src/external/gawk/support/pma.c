/* "pma", a persistent memory allocator (implementation)
   Copyright (C) 2019, 2022  Terence Kelly
   Contact:  tpkelly @ { acm.org, cs.princeton.edu, eecs.umich.edu }
   Home:     http://web.eecs.umich.edu/~tpkelly/pma/  [or "https"]
   Design:   HTML:  https://queue.acm.org/detail.cfm?id=3534855
             PDF:   https://dl.acm.org/doi/pdf/10.1145/3534855

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Affero General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.

   Code is intended to be (mostly) C99 / POSIX 2017.

   Compile and link with your programs in the obvious way.  If
   assertions are enabled (the default) extensive integrity checks
   are frequently performed; these checks may be slow, depending on
   the size and state of the persistent heap.
*/

#define _DEFAULT_SOURCE  // for MAP_ANONYMOUS
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "pma.h"

// Software version; not the same as backing file format version.
const char pma_version[] = "2022.10Oct.30.1667172241 (Avon 8-g1)";

#define S(s) #s
#define S2(s) S(s)
#define COORDS __FILE__ ":" S2(__LINE__) ": "
#define FP(...) (void)fprintf(stderr, COORDS __VA_ARGS__)
#define ERN " errno => '%s'\n", strerror(errno)
#define ERR(...) do { if (0 < state.vrb) FP("ERROR: "   __VA_ARGS__); } while (0)
#define WRN(...) do { if (1 < state.vrb) FP("Warning: " __VA_ARGS__); } while (0)
#define FYI(...) do { if (2 < state.vrb) FP("FYI: "     __VA_ARGS__); } while (0)

int        pma_errno;
#define SE pma_errno = __LINE__
#define RL return      __LINE__
#define RN return NULL
#define SERL do { SE; RL; } while (0)
#define SERN do { SE; RN; } while (0)

enum {
  VERS = 2,     // backing file format version number
  WDSZ = 8,     // word size (bytes)
  NFL  = 422,   // number of free lists / size classes
  ALGN = 1024 * 1024 * 1024  // alignment of in-memory image of heap file
};

typedef struct ao {  // alloc object
  struct ao *anext,          // header; singly linked list of all aos in addr order
            *fprev, *fnext;  // for doubly linked free list
} ao_t;

// We stash three flags in the least significant bits of a header:
// bit 0:  is this ao in use (i.e., live, as opposed to free)?
// bit 1:  is the previous ao on the state.anext list in use?
// bit 2:  has this ao ever grown via realloc?

static const uintptr_t lomask = 0x7,  // we should really say "himask = ~lomask", but...
                       himask = ~ ((uintptr_t) 0x7);  // for obsolete compilers

// extract bits from header
#define HIBH(ao_t_ptr) ((ao_t *)((uintptr_t)(ao_t_ptr) & himask))
#define LOBH(ao_t_ptr) ((ao_t *)((uintptr_t)(ao_t_ptr) & lomask))

// size of an ao is its memory footprint; capacity of ao is number of bytes
// available to caller; difference is header overhead of live (in-use) ao
#define AOSZ(ao_t_ptr) ((size_t)((uintptr_t)HIBH((ao_t_ptr)->anext) - (uintptr_t)HIBH(ao_t_ptr)))
#define AOCAP(ao_t_ptr) (AOSZ(ao_t_ptr) - WDSZ)

#define Z1(i) assert(0 == (i) || 1 == (i))
static void slobh(ao_t *p, int iu, int piu, int grown) {  // set low bits of header to which p points
  uintptr_t h;
  assert(p);  Z1(iu);  Z1(piu);  Z1(grown);
  h = (uintptr_t)p->anext;
  h &= himask;  // clear low bits
  h |= (uintptr_t)(iu | piu << 1 | grown << 2);
  p->anext = (ao_t *)h;
}

// getters below could be re-written as simpler macros

static void globh(const ao_t *p, int *iu, int *piu, int *grown) {  // get low bits of header to which p points
  uintptr_t h;
  assert(p && iu && piu && grown);
  h = (uintptr_t)p->anext;
  *iu    = !!(h & 0x1);  Z1(*iu);
  *piu   = !!(h & 0x2);  Z1(*piu);
  *grown = !!(h & 0x4);  Z1(*grown);
}

typedef struct {     // header of backing file; contains allocator metadata
  void * mapaddr;    // virtual address where backing file must be mapped
  uint64_t bf_vers,  // version number of backing file format
           nallocs,  // number of allocations
           nfrees,   // number of de-allocations
           res_0;    // reserved for possible future use
  void * root;       // live persistent data must be reachable from root
  ao_t * afirst,     // list of all alloc objects, both live & free, in addr order
       * abound;     // one beyond end of allocatable area
  ao_t free[NFL];    // free lists; each has dummy header
} pma_hdr_t;

static struct {
  int init,           // has persistent heap been initialized?
      vrb;            // verbsity level
  const char * file;  // name of backing file
  pma_hdr_t * hdr;    // addr where backing file is mapped
} state;

// #define ASI assert(1 == state.init || 2 == state.init)  // assert state initialization
#define ASI(...) \
  do { if (! (1 == state.init || 2 == state.init)) { ERR("not initialized\n"); SE; assert(0); return __VA_ARGS__ ; } } while(0)

enum { IU = 0, PIU = 1, GROWN = 2 };

static int getbit(ao_t *p, int bit) {
  int iu, piu, grown;
  globh(p, &iu, &piu, &grown);
  switch (bit) {
    case     IU:  return      iu;
    case    PIU:  return     piu;
    case  GROWN:  return   grown;
    default:
      ERR("bad bit: %d\n", bit);
      SE;
      assert(0);
      return INT_MIN;
  }
}

#define DP(...) (void)fprintf(stderr, __VA_ARGS__)
#define VS      (void *)

// valid ao ptr:
#define VAO(p)  (VS state.hdr->afirst <= VS (p) && VS state.hdr->abound > VS (p))
#ifndef NDEBUG
static int valid_footer(ao_t *p) {
  if (!getbit(p, IU)) {
    ao_t **ftr = (ao_t **)HIBH(p->anext) - 1;
    return *ftr == p;   // footer should point to header
  }
  else
    return 1;
}
#define VAF(p)  (VAO(p) && valid_footer(p))
#endif // NDEBUG

static void pao(ao_t *p) {  // print ao
  int iu, piu, grown;
  ao_t **footer = (ao_t **) ((char *)p + AOSZ(p)) - 1;  // TODO:  squelch alignment warning?
  assert(VAO(p));
  assert(0 == AOSZ(p) % WDSZ);
  assert(0 == LOBH(p));
  globh(p, &iu, &piu, &grown);
  DP("    AO at %p:  size %lu B / %lu w\n"
     "      hdr %p (H 0%lo L 0%lo) iu %d piu %d grown %d\n"
     "      fp  %p%s\n"
     "      fn  %p%s\n"
     "      ft  %p%s\n",
     VS p, AOSZ(p), AOSZ(p) / WDSZ,
     VS p->anext, (uintptr_t)HIBH(p->anext), (uintptr_t)LOBH(p->anext), iu, piu, grown,
     VS p->fprev, iu ? " (ignore)" : "",
     VS p->fnext, iu ? " (ignore)" : "",
     VS *footer,  iu ? " (ignore)" : "");
}

static size_t UB[NFL];  // UB[c] is upper bound of size class c in machine words

#define IC integrity_check(__LINE__)
static int integrity_check(int line) {  // can be slow; intended for debugging small heaps
  pma_hdr_t *h = state.hdr;
  int nadd = 0, naddfree = 0, tiu = 0, tpiu = 0, tf = 0;  // beware overflow if lists are long
  FYI("integrity_check called from line %d\n", line);
#ifdef NDEBUG
  WRN("integrity check relies on assertions, which are disabled (call at line %d)\n", line);
#endif
  assert(h && h == h->mapaddr);
  // check addr-ordered list
  for (ao_t *next, *a = h->afirst; a < h->abound; a = next) {
    next = HIBH(a->anext);
    assert(VAF(a));
    assert(32 <= AOSZ(a));  // TODO: magic number here
    assert(next > a && next <= h->abound);
    if (1000000 < ++nadd) {
      WRN("integrity check discontinued; anext list too long (call at line %d)\n", line);
      SE;        // if persistent heap contains too many aos/blocks,
      return 0;  // integrity check will be too slow; therefore discontinue
    }
    if (0 == getbit(a, IU))
      ++naddfree;
    tiu  += getbit(a,  IU);  // total number of aos with in-use bit set
    tpiu += getbit(a, PIU);  // total number of aos with previous-ao-is-in-use bit set
  }
  assert(tpiu == tiu || 1 + tpiu == tiu);
  FYI("anext list length: %d  tiu %d  tpiu %d  nallocs %" PRIu64 "  nfrees %" PRIu64 "\n",
                          nadd,   tiu,     tpiu,       h->nallocs,         h->nfrees);
  assert(h->nallocs >= h->nfrees);
  assert(h->nallocs - h->nfrees == (uint64_t)tiu);
  // check free lists
  for (int i = 0; i < NFL; i++) {
    ao_t *p, *f = &(h->free[i]);
    if (f->fprev == f)   // empty list
      assert(f->fnext == f);
    else {
      int nfwd = 0, nrev = 0;  // count how many we find going forward and reverse
      for (p = f->fnext; p != f; p = p->fnext) { nfwd++; assert(VAF(p)); assert(0 == getbit(p, IU)); }
      for (p = f->fprev; p != f; p = p->fprev) { nrev++; assert(VAF(p)); assert(0 == getbit(p, IU)); }
      assert(nfwd == nrev);    // count should be the same in both directions
      tf += nfwd;
      // check ao sizes against UB
      for (p = f->fnext; p != f; p = p->fnext) {
        #ifndef NDEBUG
        size_t capwords = AOCAP(p) / WDSZ;
        #endif
        assert(capwords <= UB[i]);
        if (0 < i)
          assert(capwords > UB[i-1]);
      }
    }
  }
  FYI("total free aos: %d  naddfree %d  integrity check line %d\n", tf, naddfree, line);
  assert(tf == naddfree);
  return 0;
}

#define NM " not meaningful in fallback mode\n"

void pma_check_and_dump(void) {
  pma_hdr_t *h = state.hdr;
  ASI();
  if (2 == state.init) { ERR("check_and_dump" NM); SE; assert(0); return; }
  if (IC) ERR("integrity check failed\n");  // proceed with dump anyway (?)
  DP(COORDS "check data structures and dump\n");
  DP("header version:    %s\n", PMA_H_VERSION);
  DP("software version:  %s\n", pma_version);
  DP("sizeof state:  %lu\n", sizeof state);
  DP("sizeof header: %lu\n", sizeof(pma_hdr_t));
  DP("state:\n");
  DP("  init: %d\n", state.init);  assert(0 == state.init || 1 == state.init || 2 == state.init);
  DP("  vrb:  %d\n", state.vrb);   assert(0 <= state.vrb && 3 >= state.vrb);
  DP("  file: %p \"%s\"\n", (const void *)state.file, state.file);
  DP("  hdr:  %p\n", VS h);
  if (NULL != h) {
    DP("header:\n");   // nallocs & nfrees not printed; they'd add noise to initial/final state diff
    DP("  mapaddr: %p\n", h->mapaddr);
    DP("  bf_vers: %" PRIu64 "\n", h->bf_vers);
    DP("  root:   %p\n", h->root);    assert(NULL == h->root || (h->root >= VS h->afirst && h->root < VS h->abound));
    DP("  afirst: %p\n", VS h->afirst);  assert(VS h->afirst > h->mapaddr);
    DP("  abound: %p\n", VS h->abound);  assert(h->abound > h->afirst);
    DP("  all allocated objects in addr order:\n");
    for (ao_t *a = h->afirst; a < h->abound; a = HIBH(a->anext)) {
      assert(HIBH(a->anext) > a);
      pao(a);
    }
    for (int i = 0; i < NFL; i++) {
      ao_t *f = &(h->free[i]);
      if (f->fprev == f)   // empty list
        assert(f->fnext == f);
      else {
        DP("  free list of size class %d UB %lu (prev %lu) list head %p:\n", i, UB[i], i > 0 ? UB[i-1] : 0, VS f);
        for (ao_t *p = f->fnext; p != f; p = p->fnext)
          pao(p);
      }
    }
  }
}
#undef DP

static int sc(size_t nbytes) {  // compute size class; nbytes is malloc() arg
  static int init;
  const size_t maxwords = (size_t)0x1 << 61;  // 2^61 words == 2^64 bytes
  size_t nwords;
  int c;
  if (! init) {
    FYI("initializing UB[]\n");
    UB[0] = 3;  // smallest allocation has size (AOSZ) 4 words and capacity (AOCAP) 3 words
    for (c = 1; ; c++) {
      long double hi = floorl((long double)(1 + UB[c-1]) * 1.1L);
      assert(NFL > c);
      if (hi >= (long double)maxwords) { UB[c] = maxwords; break; }
      else                               UB[c] = (size_t)hi;
    }
    assert(NFL - 1 == c);
    init = 1;
  }
  nwords = (nbytes / WDSZ) + !!(nbytes % WDSZ);
  assert(nwords <= maxwords);
  for (c = 0; NFL > c; c++)
    if (nwords <= UB[c])
      break;
  assert(NFL > c);
  return c;
}

static void fli(ao_t *p) {  // insert given ao at head of appropriate free list
  ao_t *h;
  int fl;
  assert(NULL != p);
  assert(VAO(p));
  fl = sc(AOCAP(p));
  assert(0 <= fl && NFL > fl);
  h = &(state.hdr->free[fl]);  // head of free list
  FYI("fli(%p) h == %p h->fn %p h->fp %p\n", VS p, VS h, VS h->fnext, VS h->fprev);
  p->fprev = h;
  p->fnext = h->fnext;
  h->fnext->fprev = p;
  h->fnext = p;
}

static void flr(ao_t *p) {  // remove ao from free list
  p->fnext->fprev = p->fprev;
  p->fprev->fnext = p->fnext;
  p->fprev = p->fnext = NULL;
}

// MAP_NORESERVE is not available on all systems.  It might be safe to simply remove this
// flag below if your system lacks it, though this expedient has not been tested extensively.

// Here in gawk, we like to live dangerously:
#ifndef MAP_NORESERVE
#define MAP_NORESERVE 0
#endif /* MAP_NORESERVE */

#define MMAP(N) mmap(NULL, (N), PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0)
#define MUNMAP(A, N) do { if (0 != munmap((A), (N))) { ERR("munmap()" ERN); SERN; } } while (0)
static void * addrgap(off_t n) {  // find big gap in address space to map n bytes
  void *A, *Amax = NULL;  size_t L, U, Max = 0, N = (size_t)n;  char *r;
  FYI("addrgap(%jd)\n", (intmax_t)n);  // TODO: better way to handle off_t
  if (N < sizeof(pma_hdr_t) + 40960) { ERR("file size %zu too small\n", N); SERN; }
  // Binary search to find max length of successfull mmap().
  // Invariants:
  //   Larger max might lie in range [L,U] inclusive.
  //   If a previous max has been found, it must lie in [1,L-1].
  //   A larger max cannot lie in [U+1,UINT64_MAX].
  L = 1;  // mmap fails if length == 0 (SUSv3)
  U = UINT64_MAX;
  while (L <= U) {
    size_t M = L + (U - L) / 2;  // avoid overflow
    if (MAP_FAILED != (A = MMAP(M))) { assert(Max < M); Max = M; Amax = A; MUNMAP(A, M); if (UINT64_MAX == M) break; L = M + 1; }
    else                             { assert(0   < M);                                                              U = M - 1; }
  }
  FYI("max gap: %zu bytes at %p\n", Max, Amax);
  if (Max < N + (size_t)ALGN * 2) {  // safety margin
    ERR("max gap %zu too small for required %zu\n", Max, N);
    SERN;
  }
  r = (char *)Amax + (Max - N)/2;
  if ((uintptr_t)r % ALGN)  // align on conservative boundary
    r += (uintptr_t)ALGN - ((uintptr_t)r % ALGN);
  assert(0 == (uintptr_t)r % ALGN);
  FYI("addrgap returns %p == %lu\n", VS r, (uintptr_t)r);
  return r;
}
#undef MMAP
#undef MUNMAP

#define MM(a,s,f) mmap((a), (size_t)(s), PROT_READ | PROT_WRITE, MAP_SHARED, (f), 0)
int pma_init(int verbose, const char *file) {
  int fd, pwr2flag = 0;  long ps, pwr2;  void *a1, *a2;  char *ev;
  size_t as = sizeof(a1);  struct stat s;
  pma_hdr_t *h;
  if (! (0 <= verbose && 3 >= verbose)) { SE; assert(0); RL; }  // ERR macro wouldn't work here
  state.vrb = verbose;
  FYI("pma_init(%d,\"%s\")\n", verbose, file);
  if (NULL != (ev = getenv("PMA_VERBOSITY"))) {
    int newvrb;
    if (1 != sscanf(ev, "%1d", &newvrb)) { ERR("parsing envar verbosity \"%s\"\n", ev); SERL; }
    if (! (0 <= newvrb && 3 >= newvrb))  { ERR("bad envar verbosity %d\n", newvrb);     SERL; }
    state.vrb = newvrb;
    WRN("envar verbosity over-ride %d -> %d\n", verbose, newvrb);
  }
  if (state.init) { ERR("already initialized\n"); SE; assert(0); RL; }
  FYI("software version '%s' expects backing file format version %d\n",
      pma_version, VERS);
  if (strcmp(pma_version, PMA_H_VERSION)) {
    ERR("software version mismatch: '%s' / '%s'\n", pma_version, PMA_H_VERSION);
    SE; assert(0); RL; }
  // check assumptions
  assert((himask & lomask) ==   (uintptr_t)0 );
  assert((himask | lomask) == ~((uintptr_t)0));
  if (! (WDSZ == sizeof(void *) && // in C11 we'd static_assert()
         WDSZ == sizeof(size_t) &&
         WDSZ == sizeof(off_t)  &&
         WDSZ == sizeof(unsigned long))) { ERR("word size not 64 bits\n"); SERL; }
  assert(0 == sizeof(pma_hdr_t) % WDSZ);
  if (NULL == file) {
    WRN("no backing file provided; falling back on standard malloc\n");
    state.init = 2;
    state.file = NULL;
    state.hdr  = NULL;
    return 0;
  }
  if (4096 > (ps = sysconf(_SC_PAGESIZE))) {
    ERR("bad page size %ld, errno '%s'\n", ps, strerror(errno)); SERL; }
  for (pwr2 = 4096; pwr2 <= ALGN; pwr2 *= 2)
    if (pwr2 == ps) { pwr2flag = 1; break; }
  if (0 == pwr2flag) {
    ERR("page size %ld not a reasonable power of two\n", ps); SERL; }
  // map backing file containing persistent heap
  if (0 > (fd = open(file, O_RDWR)))      { ERR("open()"    ERN); SERL; }
  if (0 != fstat(fd, &s))                 { ERR("fstat()"   ERN); SERL; }
  if (!S_ISREG(s.st_mode))  { ERR("%s not regular file\n", file); SERL; }
  if ((ssize_t)as != read(fd, &a1, as))   { ERR("read()"    ERN); SERL; }
  if (NULL == a1) a1 = addrgap(s.st_size);
  if (NULL == a1)                         { ERR("addrgap()" ERN);   RL; }
  FYI("map at %p\n", a1);
  if (a1 != (a2 = MM(a1, s.st_size, fd))) { ERR("mmap()"    ERN); SERL; }
  if (0 != close(fd))                     { ERR("close()"   ERN); SE;   }  // carry on
  state.init = 1;
  state.file = file;
  state.hdr  = h = (pma_hdr_t *)a2;
  if (NULL == h->mapaddr) {
    int i;
    ao_t *w, **ftr;  // initial "wilderness", footer
    FYI("initializing persistent heap\n");
    if (s.st_size % ps) {
      ERR("backing file size %jd not multiple of page size %ld\n", (intmax_t)s.st_size, ps);
      SERL;
    }
    assert(      0 == h->bf_vers
           &&    0 == h->nallocs
           &&    0 == h->nfrees
           &&    0 == h->res_0
           && NULL == h->root
           && NULL == h->afirst
           && NULL == h->abound);
    for (i = 0; i < NFL; i++) {
      assert(   NULL == h->free[i].anext
             && NULL == h->free[i].fprev
             && NULL == h->free[i].fnext);
      // free[i] is dummy node in doubly-linked free list; this simplifies code to splice aos into & out of free list
      h->free[i].fprev = h->free[i].fnext = &(h->free[i]);
    }
    h->mapaddr = h;
    h->bf_vers = VERS;
    h->nallocs = 0;
    h->nfrees  = 0;
    h->res_0   = 0;
    h->afirst = (ao_t *)(1 + h);
    h->abound = (ao_t *)((char *)h + s.st_size);  // TODO: squelch alignment warning?
    // install "wilderness" free ao on all-object list; every free ao has a
    // footer pointing to its header, to facilitate coalescing adjacent frees;
    // header on final ao points beyond allocatable area
    w = h->afirst;
    w->anext = h->abound;
    assert(0 == AOSZ(w) % WDSZ && WDSZ < AOSZ(w));
    ftr = (ao_t **)h->abound - 1;
    *ftr = w;
    fli(w);
  }
  else {
    FYI("persistent heap already initialized\n");
    // Page size may change during life of heap.  We insist that
    // backing file is multiple of page size at time of birth, but
    // for already-initialized heaps we issue warning only.
    if (s.st_size % ps)
      WRN("backing file size %jd not multiple of page size %ld\n", (intmax_t)s.st_size, ps);
    if (VERS != h->bf_vers) {
      ERR("backing file version mismatch: %d vs. %" PRIu64 "\n", VERS, h->bf_vers);
      SERL;
    }
    (void)sc(1);  // to populate UB[]
  }
  assert(!IC);
  return 0;
}
#undef MM

// bite off adequate prefix if ao is too large, return remainder to appropriate
// free list; must handle two cases:  given ao is free, versus given ao is live
// and is being shrunk by realloc
static ao_t * split_ao(ao_t *p, size_t s) {
  size_t c = AOCAP(p), Cw = c / WDSZ, Sw;  int iu, piu, grown;  ao_t *n;
  if (s < 24) s = 24;  // increase request size to minimum allocation size if necessary; TODO: magic number here
  Sw = s / WDSZ + !!(s % WDSZ);
  assert(NULL == LOBH(p));  // lo bits of header (p->anext) might be set, but not lo bits of p
  assert(NULL == p->fprev && NULL == p->fnext);  // *p should already be spliced out of free lists
  assert(c >= s && 0 == c % WDSZ);
  FYI("split_ao(%p,%zu) AOCAP %zu words req %zu words cap %zu\n", VS p, s, c, Sw, Cw);
  globh(p, &iu, &piu, &grown);
  if (4 <= Cw - Sw) {  // split ao if remainder is large enough to be allocatable
    ao_t  *rem = (ao_t *)(&(p->fprev) + Sw),   // remainder
         **rft = (ao_t **)HIBH(p->anext) - 1;  // footer of remainder
    FYI("splitting at %p\n", VS rem);
    rem->anext = HIBH(p->anext);  // set header of remainder
    *rft = rem;                   // set footer of remainder
    fli(rem);
    p->anext = rem;   // set header of *p
  }
  assert(AOCAP(p) >= s);
  slobh(p, 1, piu, grown);  // in-use bit is set; values of prev-in-use and grown bits are preserved
  // set prev-in-use bit of next ao on anext list (if such exists), preserving iu and grown bits
  n = HIBH(p->anext);
  assert(n <= state.hdr->abound);
  if (n < state.hdr->abound) {
    globh(n, &iu, &piu, &grown);
    slobh(n,  iu,    1,  grown);
  }
  return p;
}

// TODO:  add FYIs to consistently report return values of malloc, realloc, calloc

void * pma_malloc(size_t size) {
  ao_t *r = NULL;
  FYI("malloc(%zu)\n", size);
  ASI(NULL);
  if (2 == state.init) return malloc(size);
  assert(!IC);
  if (0 >= size) {
    WRN("malloc(%zu) argument <= zero\n", size);  SERN;  }
  for (int c = sc(size); c < NFL; c++) {
    ao_t *h = &(state.hdr->free[c]);
    // FYI("check size class %d UB %zu\n", c, UB[c]);
    for (ao_t *f = h->fnext; f != h; f = f->fnext) {
      // FYI("free list contains ao with capacity %zu\n", AOCAP(f));
      if (AOCAP(f) >= size) {
        r = f;
        goto end;
      }
    }
  }
  end:
  if (NULL != r) {
    flr(r);
    r = split_ao(r, size);
    FYI("malloc returning %p\n", VS &(r->fprev));
    ++(state.hdr->nallocs);
    assert(!IC);
    return &(r->fprev);
  }
  else {
    WRN("malloc(%zu) cannot satisfy request at this time\n", size);
    SERN;  // conflates ENOMEM / EAGAIN (request might succeed after frees)
  }
}

void * pma_calloc(size_t nmemb, size_t size) {
  void *p;
  FYI("calloc(%zu,%zu)\n", nmemb, size);
  ASI(NULL);
  if (2 == state.init) return calloc(nmemb, size);
  if (0 >= nmemb || 0 >= size) {
    WRN("calloc(%zu,%zu) argument <= zero\n", nmemb, size);  SERN;  }
  // SSIZE_MAX exists but SIZE_MAX apparently doesn't; sheesh
  if (nmemb > UINT64_MAX / size) {
    WRN("calloc(%zu,%zu) arguments overflow\n", nmemb, size);  SERN;  }
  if (NULL != (p = pma_malloc(nmemb * size)))
    (void)memset(p, 0, nmemb * size);
  return p;
}

void * pma_realloc(void *ptr, size_t size) {
  ao_t *p;  void *nu;  // "new" is a C++ keyword
  FYI("realloc(%p,%zu)\n", ptr, size);
  ASI(NULL);
  if (2 == state.init) return realloc(ptr, size);
  if (NULL == ptr) return pma_malloc(size);
  if (0 >= size) { pma_free(ptr); RN; }
  p = (ao_t *)((ao_t **)ptr - 1);
  if (AOCAP(p) >= size)  // no growth needed
    return ptr;
  nu = pma_malloc(size);
  if (NULL == nu)
    SERN;
  (void)memcpy(nu, ptr, AOCAP(p));
  pma_free(ptr);
  return nu;
}

// Merge *p with next ao on anext list; returns 1 if coalesces, 0 otherwise.
// Flag indicates which of the two aos is on the free list and must be removed.
static int coalesce(ao_t *p, int flr_lo_hi) {
  ao_t *n = HIBH(p->anext), **ftr;  int piu;
  assert(n > p && n <= state.hdr->abound);
  FYI("coalesce(%p)\n", VS p);
  if (n >= state.hdr->abound)  // *p is final ao on anext list
    return 0;
  if (0 == getbit(n, IU)) {  // next ao is not in use, therefore coalesce
    flr(flr_lo_hi ? n : p);  // remove appropriate ao from free list
    piu = getbit(p, PIU);
    p->anext = HIBH(n->anext);
    ftr = (ao_t **)p->anext - 1;
    *ftr = p;
    slobh(p, 0, piu, 0);  // preserve prev-in-use bit of header of *p
    return 1;
  }
  else  // next ao is in use, therefore do not coalesce
    return 0;
}

void pma_free(void *ptr) {
  ao_t *p, *n, **ftr;  int r;
  FYI("free(%p)\n", ptr);
  ASI();
  if (2 == state.init) { free(ptr); return; }
  assert(!IC);
  if (NULL == ptr) return;  // allowed by C & POSIX
  if (! (VS state.hdr->afirst <= ptr && VS state.hdr->abound > ptr)) {  // e.g., p=strdup("foo") ... pma_free(p);
    ERR("freed ptr %p outside allocatable area bounds %p %p\n",
        ptr, VS state.hdr->afirst, VS state.hdr->abound);
    SE;
    assert(0);
    return;
  }
  assert(0 == (uintptr_t)ptr % WDSZ);
  p = (ao_t *)((ao_t **)ptr - 1);
  assert(VAO(p));
  n = HIBH(p->anext);
  assert(p < n && n <= state.hdr->abound);
  assert(1 == getbit(p, IU));
  slobh(p, 0, getbit(p, PIU), 0);  // clear iu and grown bits of *p header
  if (n < state.hdr->abound)
    assert(1 == getbit(n, PIU));
  FYI("merge with right/higher ao\n");
  r = coalesce(p, 1);
  FYI("%s\n", r ? "yes" : "no");
  if (0 == getbit(p, PIU) && p > state.hdr->afirst) {  // if ao is not leftmost/lowest and previous/lower ao is not in use, merge
    ao_t *prev = *((ao_t **)p - 1);
    assert(prev < p);
    FYI("merge with left/lower ao\n");
    r = coalesce(prev, 0);
    assert(r);
    p = prev;
  }
#ifndef NDEBUG
  (void)memset(&(p->fprev), 0, AOCAP(p));  // for near-complete "reversibility"
#endif
  n = HIBH(p->anext);
  assert(p < n && n <= state.hdr->abound);
  ftr = (ao_t **)n - 1;
  *ftr = p;
  if (n < state.hdr->abound)
    slobh(n, getbit(n, IU), 0, getbit(n, GROWN));  // clear prev-in-use bit of next
  fli(p);
  ++(state.hdr->nfrees);
  assert(!IC);
 }

void pma_set_root(void *p) {  // TODO:  return success/fail indicator?
  FYI("set_root(%p)\n", p);
  ASI();
  if (2 == state.init)         { ERR("set_root" NM);      SE; assert(0); return; }
  if (! (NULL == p || VAO(p))) { ERR("bad root %p\n", p); SE; assert(0); return; }
  // could also check that p "looks like" pointer returned by pma_malloc,
  // e.g., header's in-use bit should be set and HIBH should be reasonable
  state.hdr->root = p;
}

void * pma_get_root(void) {
  void *p;
  FYI("get_root()\n");
  ASI(NULL);
  if (2 == state.init) { ERR("get_root" NM); SE; assert(0); RN; }
  p = state.hdr->root;
  assert(NULL == p || VAO(p));
  return p;
}

typedef unsigned long ul_t;
void pma_set_avail_mem(const ul_t v) {
  FYI("set_avail_mem(0x%lx)\n", v);
  ASI();
  if (2 == state.init) { ERR("set_avail_mem" NM); SE; assert(0); return; }
  assert(!IC);
  for (int i = 0; i < NFL; i++) {
    ao_t *p, *f = &(state.hdr->free[i]);
    if (f->fprev != f)
      for (p = f->fnext; p != f; p = p->fnext) {
        ul_t *q = (ul_t *)(1 + p),
             *e = (ul_t *)(HIBH(p->anext)) - 1;
        for ( ; q != e; q++)
          if (*q != v)  // avoid over-writing same value; gratuitous modification is a Bad Thing for persistent memory
            *q = v;
        for ( ; q != e; q++)
          assert(*q == v);
      }
  }
  assert(!IC);
}

