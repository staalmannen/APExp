/* Memory management data structures, part 2: Heap */

/* -------------------------- Specification ---------------------------- */

#ifdef SPVW_PAGES
/* Pages is a collection of pages.
 typedef ... Pages; */
#endif

/* Heap is a collection of pages, together with some management information.
 typedef ... Heap;

 Iteration through all pages of a heap.
 map_heap(heap,pagevar,statement); */

/* -------------------------- Implementation --------------------------- */

#ifdef SPVW_PAGES

typedef Page* Pages;

typedef struct {
  Pages inuse;      /* the currently used pages */
  /* _Page reserve; - a reserve-page ?? */
  /* heap for objects of fixed length: */
  Pages lastused;   /* a cache for the last used page */
  uintM misaligned; /* a misalignment that must be applied to all objects */
} Heap;

#define map_heap(heap,pagevar,statement)                \
  { AVL_map((heap).inuse,pagevar,statement); }

#endif

#ifdef SPVW_BLOCKS

typedef Page Pages;

#ifdef GENERATIONAL_GC
/* For each physical memory page of the old generation we memorize,
 which pointers to objects of the new generation this page contains,
 so that we do not have to access this page.
 So long as we do not access this page for writing, this information stays
 up to date. But after we have written to this page, we must regenerate
 this information at the next GC. Additionally, this should be done
 without accessing the page before it or after it. */
typedef struct {
  gcv_object_t* p;    /* address of the pointer, within an old object */
  gcv_object_t o;     /* o = *p, pointer to a new object */
} old_new_pointer_t;
typedef struct {
  /* traversal of the pointers in the page requires the following:
     continuation of the last object on previous page: */
  gcv_object_t* continued_addr;
  uintC continued_count;
  /* first object, that begins at this page (or later) : */
  aint firstobject;
  /* the cache of pointers to objects of the new generation: */
  int protection; /* PROT_NONE : only the cache is valid.
                     PROT_READ : both page and cache are valid.
                     PROT_READ_WRITE : only the page is valid. */
  uintL cache_size;         /* number of cached pointers */
  old_new_pointer_t* cache; /* cache of all pointers into the new generation */
#if defined(MULTITHREAD)
  /* during fault handling we have to allow a single thread to  change this page cache */
  spinlock_t cache_lock;
#endif
} physpage_state_t;

#if defined(MULTITHREAD)
/* during GC GEN1 the highest bit of cache_size marks whether the
   protection of the page should be preserved (becasue it contains
   pinned objects).
   Used only during GEN1 of GC !!! Never set outside GC. */
 #define physpage_pinned_mask  ((uintL)(bit(intLsize-1)))
 #define physpage_pin_marked(p) ((p)->cache_size & physpage_pinned_mask)
 #define physpage_pin_mark(p) p->cache_size |= physpage_pinned_mask
#endif /* MULTITHREAD & GENERATIONAL_GC */
#endif /* GENERATIONAL_GC */

typedef struct {
  Pages pages;
  #if defined(SPVW_PURE_BLOCKS) || (defined(SPVW_MIXED_BLOCKS) && defined(TRIVIALMAP_MEMORY))
  aint heap_limit;
  #if !defined(SPVW_MIXED_BLOCKS_OPPOSITE) /* SPVW_PURE_BLOCKS || SPVW_MIXED_BLOCKS_STAGGERED */
  aint heap_hardlimit;
  #endif
  #endif
  #ifdef GENERATIONAL_GC
  aint heap_gen0_start;
  aint heap_gen0_end;
  aint heap_gen1_start;
  physpage_state_t* physpages;
  #endif
  #ifdef MULTITHREAD
  /* list of heap holes (simple vectors) is kept here so we can reuse these
     heap areas for regular allocations */
  aint holes_list;
  #endif
} Heap;

#ifdef MULTITHREAD
/* Heap holes are "filled" with dummy simple bit vectors. We reuse larger holes
 (> mmap_pagesize) and we place the structure below in sbvector->data - thus
 making a list of such holes */
typedef struct {
  uintM hh_size; /* size in bytes of the hole */
  aint hh_next; /* pointer to next hole */
} heap_hole;
/* define smallest hole size that we will consider to reuse. holes smaller
   than this will be ignored */
#define MIN_HOLE_SIZE_FOR_REUSE mmap_pagesize
#endif

#define heap_start  pages.page_start
#define heap_end    pages.page_end
#if defined(SPVW_PURE_BLOCKS) || (defined(SPVW_MIXED_BLOCKS) && defined(TRIVIALMAP_MEMORY))
/* always: heap_start <= heap_end <= heap_limit. */
#if defined(SPVW_MIXED_BLOCKS_OPPOSITE)
/* resp. heap_limit <= heap_start <= heap_end. */
#endif
/* the memory between heap_start and heap_end is occupied,
 the memory between heap_end (resp. heap_start) and heap_limit is free.
 heap_limit is enlarged (resp. reduced), if necessary.
 heap_limit is divisible by physpagesize if heap_start < heap_end. If
 heap_start == heap_end, heap_limit may be equal to heap_end and thus
 == varobjects_misaligned mod physpagesize. */
#if !defined(SPVW_MIXED_BLOCKS_OPPOSITE)
/* heap_hardlimit is the biggest resp. smallest admissible value of heap_limit. */
#endif
#else  /* defined(SPVW_MIXED_BLOCKS) && !defined(TRIVIALMAP_MEMORY) */
/* always: heap_start <= heap_end.
 the memory between heap_start and heap_end is occupied, */
#endif
#ifdef GENERATIONAL_GC
#ifndef SPVW_MIXED_BLOCKS_OPPOSITE
/* the generation 0 (older generation) begins at     heap_gen0_start,
                                       reaches until heap_gen0_end.
   the generation 1 (newer generation) begins at     heap_gen1_start,
                                       reaches until heap_end.
 heap_gen0_start and heap_gen1_start are divisible by physpagesize or
 (for mem.varobjects) == varobjects_misaligned mod physpagesize.
 Between heap_gen0_end and heap_gen1_start is a gap of
 less than a page.
 heap_start is either = heap_gen0_start or = heap_gen1_start. */
#else
/* the generation 0 (older generation) begins at     heap_gen0_start,
                                       reaches until heap_gen0_end.
 For mem.varobjects:
   generation 1 (newer generation)   begins at     heap_gen1_start,
                                     reaches until heap_end.
   heap_gen0_start and heap_gen1_start are divisible by physpagesize or
   == varobjects_misaligned mod physpagesize.
   Between heap_gen0_end and heap_gen1_start is a gap of
   less than a page.
   heap_start is either = heap_gen0_start or = heap_gen1_start.
 For mem.conses: */
    #define heap_gen1_end  heap_gen1_start
/*   generation 1 (newer generation) begins at     heap_start,
                                     reaches until heap_gen1_end.
   heap_gen1_end and heap_gen0_end are divisible by physpagesize.
   Between heap_gen1_end and heap_gen0_start is a gap of
   less than a page.
   heap_end is either = heap_gen1_end or = heap_gen0_end. */
#endif
/* the status of address addr (heap_gen0_start <= addr < heap_gen0_end) is
 given by physpages[(addr>>physpageshift)-(heap_gen0_start>>physpageshift)] .
 physpages=NULL is possible, if there was not sufficient space! */
#endif

#define map_heap(heap,pagevar,statement)                \
  { var Page* pagevar = &(heap).pages; statement; }

#endif
