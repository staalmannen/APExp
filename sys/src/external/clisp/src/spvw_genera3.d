/* Support for GENERATIONAL_GC, part 3. */

/* -------------------------- Specification ---------------------------- */

#ifdef GENERATIONAL_GC

/* Update the pointers inside the old generation.
 This assumes the current meaning of the `update' macro! */
local void update_old_generation (void);

#endif

/* -------------------------- Implementation --------------------------- */

#ifdef GENERATIONAL_GC

local void update_at (gcv_object_t* ptr) {
  update(ptr);
}

local void update_old_generation (void) {
  var uintL heapnr;
  for (heapnr=0; heapnr<heapcount; heapnr++)
    if (is_heap_containing_objects(heapnr)) {
      /* objects that contain no pointers do not need to be traversed. */
      var Heap* heap = &mem.heaps[heapnr];
      var aint gen0_start = heap->heap_gen0_start;
      var aint gen0_end = heap->heap_gen0_end;
      if (gen0_start < gen0_end) {
        if (heap->physpages==NULL) {
          walk_area_(heapnr,gen0_start,gen0_end,update_at); /* fallback */
        } else {
          var physpage_state_t* physpage = heap->physpages;
          gen0_start &= -physpagesize;
          do {
            if ((physpage->protection == PROT_NONE)
                || (physpage->protection == PROT_READ)) {
             #ifdef MULTITHREAD
              /* in single thread following "if" should be removed by compiler
                 but let's ifdef it it anyway */
              if (physpage_pin_marked(physpage)) {
                DEBUG_SPVW_ASSERT(physpage->protection == PROT_READ);
                /* We are not sure whether just the thread that has
                   pinned object accesses this page (or other threads as well).
                   Protection PROT_READ should be kept because of the pinned
                   object but also we have to update all references to other
                   objects because of the uncertainty above.
                   So we change protection to PROT_READ_WRITE.
                   (Another option is to change it to PROT_READ_WRITE, update
                   the page and cache and return to PROT_READ - but this seems
                   more costly) */
                xmprotect(gen0_start,physpagesize,PROT_READ_WRITE);
                physpage->protection = PROT_READ_WRITE;
                goto update_all;
              }
             #endif
              /* take advantage of cache, update cached pointers: */
              var uintL count = physpage->cache_size;
              if (count > 0) {
                var old_new_pointer_t* ptr = physpage->cache;
                do {
                  #if defined(DEBUG_SPVW) && !defined(MORRIS_GC)
                  bool was_cons = consp(ptr->o);
                  #endif
                  update(&ptr->o);
                  #if !defined(MORRIS_GC)
                  DEBUG_SPVW_ASSERT(was_cons
                                    ? consp(ptr->o) && is_valid_cons_address(as_oint(ptr->o))
                                    : !consp(ptr->o) && is_valid_varobject_address(as_oint(ptr->o)));
                  #endif
                  ptr++;
                } while (--count > 0);
                if (!(physpage->protection == PROT_NONE)) {
                  xmprotect(gen0_start,physpagesize,PROT_NONE);
                  physpage->protection = PROT_NONE;
                }
              }
            } else {
            update_all:
              /* update the entire page-content: */
              walk_physpage_(heapnr,physpage,gen0_start+physpagesize,gen0_end,update_at);
            }
            gen0_start += physpagesize;
            physpage++;
          } while (gen0_start < gen0_end);
        }
      }
    }
}

#endif
