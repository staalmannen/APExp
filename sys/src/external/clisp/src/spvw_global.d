/* Memory management data structures, part 3: global data */

/* -------------------------- Specification ---------------------------- */

#ifdef TYPECODES
/* Number of possible typecodes. */
  #define typecount  bit(oint_type_len<=8 ? oint_type_len : 8)
#endif

/* Number of heaps.
 heapcount */
#ifdef SPVW_MIXED
/* Two heaps: One for varobjects, one for two-pointer objects. */
  #define heapcount  2
#endif
#ifdef SPVW_PURE
/* A heap for each possible typecode. */
  #define heapcount  typecount
#endif

#if defined(SPVW_MIXED_BLOCKS) && defined(TYPECODES) && defined(GENERATIONAL_GC)
  #define HAVE_HEAPNR_FROM_TYPE
#endif

/*
  VTZ:
  MT memory heap changes proposal
  GC.
  The GC will be protected with spinlock (possibly more efficient than mutex).
  During GC all thread will be suspended at "safe" points
  (suspension will be through mutex or spinlock - per thread).
  The suspension and GC will be performed in the context of the thread that caused the GC.

  Allocations.
  1. single spinlock protects the whole mem structure (all heaps).
  2. every thread should acqiure it in order to allocate anything
  3. the thread that causes the GC will suspend all others before invoking it.
  4. every thread should define so called "safe" points at which
    it can be suspended with no risk. these places will be:
     4.1. any call to allocate_xxxxxx()
     4.2. begin_system_call (what happens if pointers to LISP heap are passed?)
     4.3. (*) we need some other place in order to be able to suspend
          forms like: (loop). Probably the interrupt() macro is good candidate?

  "safe" points concept is similar to the cancellation points
  (pthread_testcancel()) in pthreads.
*/


/* Global memory management data structures. */
local struct {
  /* Lower limit of big allocated memory block. */
  aint MEMBOT;

  /* now comes the Lisp STACK */
  /* now room for the heaps containing Lisp objects. */
  Heap heaps[heapcount];
#if defined(MULTITHREAD)
  /*VTZ:  we can live with just single lock for allocation and GC.
    The alloc_lock will guard the GC as well.*/
  spinlock_t alloc_lock;
#endif
 #ifdef SPVW_PURE
  sintB heaptype[heapcount];
  /* for every typecode:
     0 for conses
     1 for varobjects containing object pointers
     2 for varobjects containing no pointers (only immediate data)
    -1 for SUBRs (gcinvariant)
    -2 for unused or immediate typecodes */
 #endif
 #ifdef SPVW_MIXED
  #define varobjects  heaps[0] /* objects of various lengths */
  #define conses      heaps[1] /* conses and other two-pointer objects */
 #endif
 #if defined(HAVE_HEAPNR_FROM_TYPE)
  sintB heapnr_from_type[typecount]; /* table type -> heapnr */
 #endif
 #if defined(SPVW_MIXED_BLOCKS_OPPOSITE) && !defined(TRIVIALMAP_MEMORY)
  /* now empty, free for Lisp objects. */
   #define MEMRES  conses.heap_end
  /* now the emergency reserve
     Upper limit of big allocated memory block. */
  aint MEMTOP;
 #endif
  /* Statistical data, used for deciding when to start a GC. */
 #if defined(SPVW_PURE_BLOCKS) || defined(TRIVIALMAP_MEMORY) || defined(GENERATIONAL_GC)
  uintM total_room; /* the space that may be occupied without triggering GC */
  #ifdef GENERATIONAL_GC
  bool last_gc_full;  /* if the last GC was a full one */
  uintM last_gcend_space0; /* how much space was occupied after the last GC */
  uintM last_gcend_space1; /* (from generation 0 resp. generation 1) */
  #endif
 #endif
 #ifdef SPVW_PAGES
  Pages free_pages;     /* a list of free, normal-sized pages */
  uintM total_space; /* how much space do the occupied pages contain at all */
  uintM used_space;  /* how much space is occupied just now */
  uintM last_gcend_space; /* how much space was occupied after the last GC */
  bool last_gc_compacted; /* if the last GC has already compacted */
  uintM gctrigger_space; /* how much space may be occupied, until the next GC becomes necessary */
 #endif
} mem;

#if defined(SPVW_MIXED_BLOCKS_OPPOSITE) && !defined(TRIVIALMAP_MEMORY) && !defined(GENERATIONAL_GC)
  #define RESERVE       0x00800L /* 2 KByte memory as reserve */
#else
  #define RESERVE             0 /* need no preallocated reserve */
#endif
  #define MINIMUM_SPACE 0x10000L /* 64 KByte as minimal memory for LISP-data */
#ifdef TRIVIALMAP_MEMORY
#if defined(MULTITHREAD)
/* in MT we malloc() the lisp stacks - let's have more memory until we find
   a better way to allocate the stacks */
  #define RESERVE_FOR_MALLOC 0x400000L /* leave 4 MByte address space free, for malloc */
#else
  #define RESERVE_FOR_MALLOC 0x100000L /* leave 1 MByte address space free, for malloc */
#endif
#endif

/* Iteration through all heaps.
 for_each_heap(heapvar,statement);

 Iteration through all heaps containing varobjects.
 for_each_varobject_heap(heapvar,statement);

 Iteration through all heaps containing conses.
 for_each_cons_heap(heapvar,statement);

 Iteration through all pages.
 for_each_page(page, statement using 'var Page* page');

 Iteration through all pages containing varobjects.
 for_each_varobject_page(page, statement using 'var Page* page');

 Iteration through all pages containing conses.
 for_each_cons_page(page, statement using 'var Page* page');
 for_each_cons_page_reversed(page, statement using 'var Page* page');

 While iterating through all heaps (0 <= heapnr < heapcount):
 Determine the type of a heap.
 is_heap_containing_objects(heapnr)
 is_varobject_heap(heapnr)
 is_cons_heap(heapnr)
 is_unused_heap(heapnr)

 Test for valid heap address, used only by consistency checks.
 is_valid_varobject_address(address)
 is_valid_cons_address(address)
 is_valid_heap_object_address(address)
 Likewise for stack-allocated objects, such as DYNAMIC_STRING.
 is_valid_stack_address(address)

 Consistency checks.
 CHECK_AVL_CONSISTENCY();
 CHECK_GC_CONSISTENCY();
 CHECK_GC_CONSISTENCY_2();
 CHECK_PACK_CONSISTENCY();

 Initializations. */
#ifdef SPVW_PURE
local inline void init_mem_heaptypes (void);
#endif
#if defined(HAVE_HEAPNR_FROM_TYPE)
local inline void init_mem_heapnr_from_type (void);
#endif

/* -------------------------- Implementation --------------------------- */

/* partitioning of the whole memory (partly out-of-date):
 1. C-program. Memory is allocated by the operating system.
    un-movable after program start.
 2. C-Stack.  Is fetched by the C-program.
    un-movable.
 3. C-Heap. Is unused here.
#ifdef SPVW_MIXED_BLOCKS
 4. LISP-stack and LISP-data.
    4a. LISP-stack. un-movable.
    4b. Objects of variable length. (Un-movable).
    4c. Conses and similar. Movable with move_conses.
    Memory therefore is requested from the operating system (has the
    advantage: On EXECUTE, the whole memory that LISP currently does not
    need can be provided to the foreign program).
    We dispense here with a partitioning into single pages.
    || LISP-      |Objects of      |->  empty   <-|conses     | reserve |
    || stack      |variable length !              !and similar|         |
    |STACK_BOUND  |         objects.end     conses.start      |         |
  MEMBOT   objects.start                                conses.end    MEMTOP
#endif
#ifdef SPVW_PURE_BLOCKS
 4. LISP-stack. Un-movable.
 5. LISP-data. For each type a large block of objects.
#endif
#ifdef SPVW_MIXED_PAGES
 4. LISP-stack. Un-movable.
 5. LISP-data.
    subdivided into pages for objects of variable length and
    pages for conses and similar.
#endif
#ifdef SPVW_PURE_PAGES
 4. LISP-stack. Un-movable.
 5. LISP-data. Subdivided into pages, that contain only objects
    of the same type.
#endif
*/

#ifdef SPVW_MIXED

/* Iteration through heaps. */
#define for_each_heap(heapvar,statement)  \
  do {                                                   \
    var uintL heapnr;                                    \
    for (heapnr=0; heapnr<heapcount; heapnr++) {         \
      var Heap* heapvar = &mem.heaps[heapnr]; statement; \
    }                                                    \
  } while(0)
#define for_each_varobject_heap(heapvar,statement)  \
  do { var Heap* heapvar = &mem.varobjects; statement; } while(0)
#define for_each_cons_heap(heapvar,statement)  \
  do { var Heap* heapvar = &mem.conses; statement; } while(0)

/* Iteration through pages. */
#define for_each_page(pagevar,statement)  \
  do {                                               \
    var uintL heapnr;                                \
    for (heapnr=0; heapnr<heapcount; heapnr++)       \
      map_heap(mem.heaps[heapnr],pagevar,statement); \
  } while(0)
#define for_each_varobject_page(pagevar,statement)  \
  map_heap(mem.varobjects,pagevar,statement)
#define for_each_cons_page(pagevar,statement)  \
  map_heap(mem.conses,pagevar,statement)
#define for_each_cons_page_reversed for_each_cons_page

/* Heap classification. */
  #define is_heap_containing_objects(heapnr)  (true)
  #define is_varobject_heap(heapnr)  ((heapnr)==0)
  #define is_cons_heap(heapnr)  ((heapnr)==1)
  #define is_unused_heap(heapnr)  (false)

#endif

#ifdef SPVW_PURE

/* During iterations, `heapnr' is the number of the heap. */

/* Iteration through heaps. */
#define for_each_heap(heapvar,statement)  \
  do {                                                     \
    var uintL heapnr;                                      \
    for (heapnr=0; heapnr<heapcount; heapnr++)             \
      if (mem.heaptype[heapnr] >= 0) {                     \
        var Heap* heapvar = &mem.heaps[heapnr]; statement; \
      }                                                    \
  } while(0)
#define for_each_varobject_heap(heapvar,statement)  \
  do {                                                     \
    var uintL heapnr;                                      \
    for (heapnr=0; heapnr<heapcount; heapnr++)             \
      if (mem.heaptype[heapnr] > 0) {                      \
        var Heap* heapvar = &mem.heaps[heapnr]; statement; \
      }                                                    \
  } while(0)
#define for_each_cons_heap(heapvar,statement)  \
  do {                                                     \
    var uintL heapnr;                                      \
    for (heapnr=0; heapnr<heapcount; heapnr++)             \
      if (mem.heaptype[heapnr] == 0) {                     \
        var Heap* heapvar = &mem.heaps[heapnr]; statement; \
      }                                                    \
  } while(0)

/* Iteration through pages. */
#define for_each_page(pagevar,statement)  \
  do {                                                     \
    var uintL heapnr;                                  \
    for (heapnr=0; heapnr<heapcount; heapnr++)         \
      if (mem.heaptype[heapnr] >= 0)                   \
        map_heap(mem.heaps[heapnr],pagevar,statement); \
  } while(0)
#define for_each_varobject_page(pagevar,statement)  \
  do {                                                     \
    var uintL heapnr;                                  \
    for (heapnr=0; heapnr<heapcount; heapnr++)         \
      if (mem.heaptype[heapnr] > 0)                    \
        map_heap(mem.heaps[heapnr],pagevar,statement); \
  } while(0)
#define for_each_cons_page(pagevar,statement)  \
  do {                                                     \
    var uintL heapnr;                                  \
    for (heapnr=0; heapnr<heapcount; heapnr++)         \
      if (mem.heaptype[heapnr] == 0)                   \
        map_heap(mem.heaps[heapnr],pagevar,statement); \
  } while(0)
#define for_each_cons_page_reversed(pagevar,statement)  \
  do {                                                 \
    var uintL heapnr;                                  \
    for (heapnr=heapcount; heapnr-- > 0; )             \
      if (mem.heaptype[heapnr] == 0)                   \
        map_heap(mem.heaps[heapnr],pagevar,statement); \
  } while(0)

/* Heap classification. */
  #define is_heap_containing_objects(heapnr)  ((mem.heaptype[heapnr] >= 0) && (mem.heaptype[heapnr] < 2))
  #define is_cons_heap(heapnr)  (mem.heaptype[heapnr] == 0)
  #define is_varobject_heap(heapnr)  (mem.heaptype[heapnr] > 0)
  #define is_unused_heap(heapnr)  (mem.heaptype[heapnr] < 0)

#endif

#if defined(SPVW_BLOCKS) && defined(DEBUG_SPVW)
  #ifdef SPVW_PURE
    #define is_valid_varobject_address(address)  \
      is_varobject_heap(((aint)(address) >> oint_type_shift) & (oint_type_mask >> oint_type_shift))
    #define is_valid_cons_address(address)  \
      is_cons_heap(((aint)(address) >> oint_type_shift) & (oint_type_mask >> oint_type_shift))
    #define is_valid_heap_object_address(address)  \
      is_heap_containing_objects(((aint)(address) >> oint_type_shift) & (oint_type_mask >> oint_type_shift))
  #else  /* SPVW_MIXED */
    #ifdef GENERATIONAL_GC
      #define is_valid_varobject_address(address)  \
        ((aint)(address) >= mem.varobjects.heap_gen0_start \
         && (aint)(address) < mem.varobjects.heap_end)
      #ifdef SPVW_MIXED_BLOCKS_OPPOSITE
        #define is_valid_cons_address(address)  \
          ((aint)(address) >= mem.conses.heap_start \
           && (aint)(address) < mem.conses.heap_gen0_end)
      #else
        #define is_valid_cons_address(address)  \
          ((aint)(address) >= mem.conses.heap_gen0_start \
           && (aint)(address) < mem.conses.heap_end)
      #endif
    #else
      #define is_valid_varobject_address(address)  \
        ((aint)(address) >= mem.varobjects.heap_start \
         && (aint)(address) < mem.varobjects.heap_end)
      #define is_valid_cons_address(address)  \
        ((aint)(address) >= mem.conses.heap_start \
         && (aint)(address) < mem.conses.heap_end)
    #endif
    #define is_valid_heap_object_address(address)  \
      (is_valid_varobject_address(address) || is_valid_cons_address(address))
  #endif
  #if defined(SPVW_PURE) || ((((STACK_ADDRESS_RANGE << addr_shift) >> garcol_bit_o) & 1) != 0)
   /* In case we do not have C stack allocated lisp objects we do not need
      is_valid_stack_address(). Define to false in order to GC to assert
      in case of bad object pointer. */
    #define is_valid_stack_address(address)  false
  #else /* we have C stack allocated objects */
    #ifdef SP_DOWN
      #define is_in_stack_range(address,sp,sp_anchor)               \
        ((aint)(address) >= (aint)sp && (aint)(address) <= (aint)sp_anchor)
    #endif
    #ifdef SP_UP
      #define is_in_stack_range(addresssp,sp,sp_anchor)              \
        ((aint)(address) <= (aint)sp && (aint)(address) >= (aint)sp_anchor)
    #endif
    #ifdef MULTITHREAD
     /* In MT builds there is no fast and portable way to get the current
        stack pointer of suspended threads - so for now it is disabled as
        well (otherwise gc will abort in debug). This makes the assert in
        GC useless. */
      static inline bool is_valid_stack_address_mt(aint address)
      {
        for_all_threads({
          if (is_in_stack_range(address,thread->_SP_before_suspend,
                                thread->_SP_anchor))
            return true;
        });
        return false;
      }
      #define is_valid_stack_address(address) \
        is_valid_stack_address_mt((aint)address)
    #else /* single thread builds */
      #define is_valid_stack_address(address) \
        is_in_stack_range(address,SP(),SP_anchor)
    #endif
  #endif
#else
  #define is_valid_varobject_address(address)  true
  #define is_valid_cons_address(address)  true
  #define is_valid_heap_object_address(address)  true
  #define is_valid_stack_address(address)  true
#endif

/* Set during the core of GC. */
modexp bool inside_gc = false;

/* check of the memory content to be GC-proof: */
#if defined(SPVW_PAGES) && defined(DEBUG_SPVW)
/* check, if the administration of the pages is okay: */
  #define CHECK_AVL_CONSISTENCY()  check_avl_consistency()
local void check_avl_consistency (void)
{
 #ifdef DEBUG_AVL
  var uintL heapnr;
  for (heapnr=0; heapnr<heapcount; heapnr++) {
    AVL(AVLID,check) (mem.heaps[heapnr].inuse);
  }
 #endif
}
/* check, if the boundaries of the pages are okay: */
  #define CHECK_GC_CONSISTENCY()  check_gc_consistency()
local void check_gc_consistency (void)
{
  for_each_page(page, if ((sintM)page->page_room < 0) {
    fprintf(stderr,"\npage overrun at address 0x%lx\n",page); abort();
  }
    if (page->page_start != page_start0(page) + mem.heaps[heapnr].misaligned) {
      fprintf(stderr,"\ninconsistent page at address 0x%lx\n",page);
      abort();
    }
    if (page->page_end + page->page_room
        != round_down(page->m_start + page->m_length,
                      varobject_alignment)) {
      fprintf(stderr,"\ninconsistent page at address 0x%lx\n",page);
      abort();
    }
    );
}
/* check, if the boundaries of the pages are okay during the compacting GC: */
  #define CHECK_GC_CONSISTENCY_2()  check_gc_consistency_2()
local void check_gc_consistency_2 (void)
{
  for_each_page(page, if ((sintM)page->page_room < 0) {
    fprintf(stderr,"\npage overrun at address 0x%lx\n",page); abort();
  }
    if (page->page_end + page->page_room -
        (page->page_start - page_start0(page))
        != round_down(page->m_start + page->m_length,
                      varobject_alignment)) {
      fprintf(stderr,"\ninconsistent page at address 0x%lx\n",page);
      abort();
    }
    );
}
#else
  #define CHECK_AVL_CONSISTENCY()
  #define CHECK_GC_CONSISTENCY()
  #define CHECK_GC_CONSISTENCY_2()
#endif
#ifdef DEBUG_SPVW
/* check, if the tables of the packages are to some extent okay: */
  #define CHECK_PACK_CONSISTENCY()  check_pack_consistency()
local void check_pack_consistency (void)
{
  var object plist = O(all_packages);
  while (consp(plist)) {
    var object pack = Car(plist);
    var object symtabs[2];
    var uintC i;
    symtabs[0] = ThePackage(pack)->pack_external_symbols;
    symtabs[1] = ThePackage(pack)->pack_internal_symbols;
    for (i = 0; i < 2; i++) {
      var object symtab = symtabs[i];
      var object table = TheSvector(symtab)->data[1];
      var uintL index = Svector_length(table);
      while (index!=0) {
        var object entry = TheSvector(table)->data[--index];
        var uintC count = 0;
        while (consp(entry)) {
          if (!symbolp(Car(entry)))
            abort();
          entry = Cdr(entry);
          count++; if (count>=10000) abort();
        }
      }
    }
    plist = Cdr(plist);
  }
}
#else
  #define CHECK_PACK_CONSISTENCY()
#endif

/* Initializations. */
#ifdef SPVW_PURE
local inline void init_mem_heaptypes (void)
{
  var uintL heapnr;
  for (heapnr=0; heapnr<heapcount; heapnr++) {
    switch (heapnr) {
     #ifndef HAVE_SMALL_SSTRING
      case_sstring:
     #endif
      case_sbvector:
      case_sb2vector:
      case_sb4vector:
      case_sb8vector:
      case_sb16vector:
      case_sb32vector:
      case_bignum:
     #ifndef IMMEDIATE_FFLOAT
      case_ffloat:
     #endif
      case_dfloat:
      case_lfloat:
      mem.heaptype[heapnr] = 2; break;
     #ifdef HAVE_SMALL_SSTRING
      case_sstring: /* because of the reallocated simple-strings */
     #endif
      case_ostring:
      case_obvector:
      case_ob2vector:
      case_ob4vector:
      case_ob8vector:
      case_ob16vector:
      case_ob32vector:
      case_vector:
      case_mdarray:
      case_record:
      case_symbol:
      mem.heaptype[heapnr] = 1; break;
      case_pair:
      mem.heaptype[heapnr] = 0; break;
      case_subr:
      mem.heaptype[heapnr] = -1; break;
      default:
        mem.heaptype[heapnr] = -2; break;
    }
  }
}
#endif
#if defined(HAVE_HEAPNR_FROM_TYPE)
local inline void init_mem_heapnr_from_type (void)
{
  var uintL type;
  for (type = 0; type < typecount; type++) {
    switch (type) {
      case_pair: mem.heapnr_from_type[type] = 1; break;
      default:   mem.heapnr_from_type[type] = 0; break;
    }
  }
}
#endif

#if defined(MULTITHREAD)

#define ACQUIRE_HEAP_LOCK() GC_SAFE_SPINLOCK_ACQUIRE(&mem.alloc_lock)
#define RELEASE_HEAP_LOCK() spinlock_release(&mem.alloc_lock)
/* helper macros for locking/unlocking global thread mutex.
 NB: while waiting on it no interrupts are allowed (i.e. we use
 begin_system_call() instead of begin_blocking_system_call())*/
#define lock_threads() do {                     \
  begin_system_call(); /* ! blocking */         \
  xmutex_lock(&allthreads_lock);                \
  end_system_call();                            \
 } while(0)
#define unlock_threads() do {                   \
  begin_system_call();                          \
  xmutex_unlock(&allthreads_lock);              \
  end_system_call();                            \
  } while(0)

/* since the GC may be re-entrant we should keep track how many times
   we have been called. Only the first time we have to really suspend
   other threads.*/
local uintC gc_suspend_count=0;

/* UP: Suspends all running threads /besides the current/ at GC safe
   points/regions.
 > lock_heap: if false - the caller already owns the heap lock
 At the end the heap lock is released since the GC itself may want
 to allocate. locks threads mutex in order to prevent race conditions
 with threads that are exitting (in delete_thread()). the lock will be
 released when all threads are resumed */
global void gc_suspend_all_threads(bool lock_heap)
{
  var clisp_thread_t *me=current_thread();
  /*fprintf(stderr,"VTZ: GC_SUSPEND(): %0x, %d\n",me,gc_suspend_count);*/
  if (lock_heap) ACQUIRE_HEAP_LOCK();
  /* the heap lock should be held always */
  ASSERT(!spinlock_tryacquire(&mem.alloc_lock));
  if (gc_suspend_count == 0) { /* first time here */
    lock_threads();
    var uintC suspended_threads = 0; /* count of suspended threads */
    for_all_threads({
      if (thread == me) { suspended_threads++; continue; } /* skip ourself */
      if (!thread->_suspend_count) {  /* if not already suspended */
        xmutex_raw_lock(&thread->_gc_suspend_lock); /* enable thread waiting */
        spinlock_release(&thread->_gc_suspend_request); /* request */
      } else {
        suspended_threads++; /* count the thread */
        thread->_suspend_count++; /* increase the suspend count */
      }
    });
    /* TODO: this way of waiting for threads to acknowledge the suspend
       request is ugly and cause form of starvation sometimes.
       We need semaphore here */
    while (suspended_threads != allthreads.count) {
      for_all_threads({
        /* skip ourself and all already suspended (ACK acquired) threads */
        if (thread->_suspend_count || (thread == me)) continue;
        if (spinlock_tryacquire(&thread->_gc_suspend_ack)) {
          thread->_suspend_count++; /* increase the suspend count */
          suspended_threads++; /* count the thread */
        } else { xthread_yield(); }
      });
    }
  }
  gc_suspend_count++; /* increase the suspend count */
  /* keep the lock on threads, but release the heap lock.
     no other threads are running now, so no new allocations may
     happen - only the ones from GC. Also no new thread can be created.*/
  RELEASE_HEAP_LOCK();
}

/* UP: Resumed all suspended threads after GC (or world stop)
 > unlock_heap: if true - the heap lock will be released at the end
 should match a call to gc_suspend_all_threads()*/
global void gc_resume_all_threads(bool unlock_heap)
{
  /* thread lock is locked. heap lock is free. */
  var clisp_thread_t *me=current_thread();
  /*fprintf(stderr,"VTZ: GC_RESUME(): %0x, %d\n",me, gc_suspend_count);*/
  /* before resuming let's report if any timeout call has failed. no need
     to acquire any lock - since no other thread LISP is running (and the
     signal handling thread will wait on the heap lock/gc_suspend_count
     anyway). It's important to do this before we get the heap lock since
     WARN may/will cause allocations. */
  var timeout_call *tc=timeout_call_chain;
  while (tc && tc->failed) {
    /* not to warn twice in case of nested GC (CLSTEXT and WARN maygc) */
    timeout_call_chain = tc->next;
    pushSTACK(CLSTEXT("CALL-WITH-TIMEOUT has failed in thread ~S."));
    pushSTACK(tc->thread->_lthread);
    tc = tc->next; /* advance */
    funcall(S(warn),2);
  }
  /* get the heap lock. in case we are called from allocate_xxx
     we should not allow any other thread that will be resumed shortly
     to acquire it. Also it guards the gc_suspend_count when accessed
     from the signal handling thread */
  ACQUIRE_HEAP_LOCK();
  if (--gc_suspend_count) {
    RELEASE_HEAP_LOCK();
    return;
  }
  for_all_threads({
    if (thread == me) continue; /* skip ourself */
    /* currently all ACK locks belong to us as well the mutex lock */
    if (! --thread->_suspend_count) { /* only if suspend count goes to zero */
      spinlock_release(&thread->_gc_suspend_ack); /* release the ACK lock*/
      xmutex_raw_unlock(&thread->_gc_suspend_lock); /* enable thread */
    }
  });
  unlock_threads(); /* locked in gc_suspend_all_threads() */
  if (unlock_heap) RELEASE_HEAP_LOCK();
}

/* UP: Suspends single thread
 > thread: the thread to be suspended
 > have_locks: is the caller holding the heap and threads locks ?
 < returns true of the thread has been suspended. false in case it has exited
   meanwhile
 Called from signal handler thread and THREAD-INTERRUPT
 Upon exit we hold threads lock. It is released in resume_thread(). This prevents
 race condition when several threads try to THREAD-INTERRUPT another thread. */
global maygc bool suspend_thread(object thread, bool have_locks)
{
  if (!have_locks) {
    pushSTACK(thread);
    /* get the locks in this order - GC does the same !!! */
    ACQUIRE_HEAP_LOCK();
    lock_threads();
    thread = popSTACK();
  }
  var clisp_thread_t *thr = TheThread(thread)->xth_globals;
  var bool ret = false;
  if (thr) { /* thread is still alive ?*/
    /* should never be called on ourselves */
    DEBUG_SPVW_ASSERT(thr != current_thread());
    if (!thr->_suspend_count) { /* first suspend ? */
      xmutex_raw_lock(&thr->_gc_suspend_lock); /* enable thread waiting */
      spinlock_release(&thr->_gc_suspend_request); /* request */
      /* wait for the thread to come to safe point. */
      while (!spinlock_tryacquire(&thr->_gc_suspend_ack))
        xthread_yield();
    }
    thr->_suspend_count++;
    ret = true;
  }
  if (!have_locks) {
    RELEASE_HEAP_LOCK(); /* allow other threads to allocate but GC is still
                            blocked due to threads lock */
  }
  return ret;
}

/* UP: Resumes single thread (or just decreases it's _suspend_count).
 > thread: the thread to be suspended
 > release_threads_lock: should we unlock threads lock
 Called from signal handler thread and from THREAD-INTERRUPT
 When called we should be the owner of threads lock and if specified we should
 release it.
 Should match a call to suspend_thread */
global void resume_thread(object thread, bool release_threads_lock)
{
  var clisp_thread_t *thr = TheThread(thread)->xth_globals;
  /* should never be called on ourselves */
  ASSERT(thr != current_thread());
  if (thr) { /* thread was alive when it was suspended ? */
    if (! --thr->_suspend_count) { /* only if suspend count goes to zero */
      spinlock_release(&thr->_gc_suspend_ack); /* release the ACK lock*/
      xmutex_raw_unlock(&thr->_gc_suspend_lock); /* enable thread */
    }
  }
  if (release_threads_lock) {
    xmutex_unlock(&allthreads_lock);
  }
}

/* remove threads locking macros */
#undef lock_threads
#undef unlock_threads

/* UP: add per thread special symbol value - initialized to SYMVALUE_EMPTY
 > symbol: the symbol
 < new index in the _symvalues thread array */
global maygc uintL add_per_thread_special_var(object symbol)
{
  pushSTACK(symbol);
  var gcv_object_t *symbol_ = &STACK_0;
  var uintL symbol_index = SYMBOL_TLS_INDEX_NONE;
  WITH_OS_MUTEX_LOCK(0,&thread_symvalues_lock, {
    /* while we were waiting on the mutex, another thread may have done
     the job*/
    symbol_index = TheSymbol(*symbol_)->tls_index;
    if (symbol_index == SYMBOL_TLS_INDEX_NONE) {
      if (num_symvalues == maxnum_symvalues) {
        /* we have to reallocate the _ptr_symvalues storage in all
           threads in order to have enough space. stop all threads in order to
           perform this (they may access invalid _ptr_symvalues otherwise).
           this should happen very rarely. */
        var uintL nsyms=num_symvalues + SYMVALUES_PER_PAGE;
        WITH_STOPPED_WORLD(true, {
          if (!realloc_threads_symvalues(nsyms)) {
            fprintf(stderr,"*** could not make symbol value per-thread. aborting\n");
            abort();
          }
          maxnum_symvalues = nsyms;
        });
      }
      /* initialize symbol's tls_index. nb: no need to initialize _ptr_symvalue
         to SYMVALUE_EMPTY since we've already done this during allocation. */
      TheSymbol(*symbol_)->tls_index = symbol_index = num_symvalues++;
    }
  });
  if (TheSymbol(*symbol_)->tls_index == SYMBOL_TLS_INDEX_NONE)
    error(control_error,GETTEXT("~S: could not make symbol value per-thread"));
  skipSTACK(1); /* symbol */
  return symbol_index;
}

/* UP: Clears any per thread value for symbol. Also sets tls_index of the
   symbol to invalid (SYMBOL_TLS_INDEX_NONE).
 > symbol: the symbol that should not have per thread bindings anymore
 < symbol: (modified).
 < allthreads: all threads symvalues for this symbol set to
 SYMVALUE_EMPTY
 maygc because of the threads lock */
global maygc void clear_per_thread_symvalues(object symbol)
{
  var uintL idx=TheSymbol(symbol)->tls_index;
  if (idx != SYMBOL_TLS_INDEX_NONE) {
    /* remove all per thread symbols for the index - we do not want
       any memory leaks. threads should be locked. This gets very
       ugly when we are gettting called for every symbol from DELETE-PACKAGE.
       but we cannot hold the threads lock for too long - since the GC will
       be blocked.*/
    pushSTACK(symbol);
    var gcv_object_t *symbol_ = &STACK_0;
    WITH_OS_MUTEX_LOCK(0,&allthreads_lock, {
      TheSymbol(*symbol_)->tls_index = SYMBOL_TLS_INDEX_NONE;
      for_all_threads({ thread->_ptr_symvalues[idx] = SYMVALUE_EMPTY; });
    });
    skipSTACK(1);
  }
}

local void init_heaps_mt()
{
  spinlock_init(&mem.alloc_lock);
  #ifndef SPVW_PAGES /* only in SPVW_BLOCKS we reuse the heap holes */
  for_each_heap(heap, { heap->holes_list = 0; } );
  #endif
}
#endif
