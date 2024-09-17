/* "pma", a persistent memory allocator (interface)
   Copyright (C) 2022  Terence Kelly
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
*/

#ifndef PMA_H_INCLUDED
#define PMA_H_INCLUDED

// version strings of interface and implementation should match
#define PMA_H_VERSION "2022.10Oct.30.1667172241 (Avon 8-g1)"
extern const char pma_version[];

/* May contain line number in pma.c where something went wrong if one
   of the other interfaces fails.  "Use the Source, Luke." */
extern int pma_errno;

/* Must be called exactly once before any other pma_* function is
   called, otherwise behavior is undefined.  Available verbosity
   levels are: 0 => no diagnostic printouts, 1 => errors only printed
   to stderr, 2 => also warnings, 3 => also very verbose "FYI"
   messages.  Verbosity level 2 is recommended.  Verbosity may be
   over-ridden via environment variable PMA_VERBOSITY.  File argument
   specifies backing file containing persistent heap, which must
   initially be an empty (logically all zeros) file, and ideally also
   a sparse file.  Backing file size must be a multiple of the system
   page size on first use; ideally the backing file should also be a
   multiple of the address alignment enforced in the implementation.
   The backing file does not grow so it must be large enough to hold
   the largest persistent heap that the application might need (if
   the file is sparse, its storage resource footprint is "pay as you
   go," so there's no downside to making it generously large).  If
   file argument is NULL, pma will fall back on standard memory
   allocator: pma_malloc passes the buck to ordinary malloc, pma_free
   calls ordinary free, etc.  In fallback-to-standard-malloc mode,
   only pma_malloc/calloc/realloc/free may be used; other functions
   such as pma_get/set_root must not be used.  The implementation may
   store a copy of the file argument, i.e., the pointer, so both this
   pointer and the memory to which it points (*file) must not change.
   Initialization may perform an integrity check on the heap; this
   check may be slow depending on the complexity of the heap.  Any
   non-zero return value indicates trouble; inspect both the value
   returned and also pma_errno. */
extern int pma_init(int verbose, const char *file);

/* The following four functions may be used like their standard
   counterparts.  See notes on pma_init for fallback to standard
   allocator.  See notes on fork in README. */
extern void * pma_malloc(size_t size);
extern void * pma_calloc(size_t nmemb, size_t size);
extern void * pma_realloc(void *ptr, size_t size);
extern void   pma_free(void *ptr);

/* The following two functions access the persistent heap's root
   pointer, which must either be NULL or must point within a block of
   persistent memory.  If the pointer passed to pma_set_root is not a
   pointer returned by pma_malloc/calloc/realloc, that is likely a
   bug, though the implementation is not obliged to check for such
   bugs. */
extern void   pma_set_root(void *ptr);
extern void * pma_get_root(void);

/* Prints to stderr details of internal data structures, e.g., free
   lists, and performs integrity checks, which may be very slow. */
extern void pma_check_and_dump(void);

/* Set non-metadata words of free blocks to given value.  Useful for
   debugging (v == 0xdeadDEADbeefBEEF) and for preparing backing file
   to be re-sparsified with fallocate (v == 0x0). */
extern void pma_set_avail_mem(const unsigned long v);

#endif // PMA_H_INCLUDED
