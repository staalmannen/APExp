/* runtime.c - Runtime code for compiler generated executables
;
; Copyright (c) 2008-2022, The CHICKEN Team
; Copyright (c) 2000-2007, Felix L. Winkelmann
; All rights reserved.
;
; Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
; conditions are met:
;
;   Redistributions of source code must retain the above copyright notice, this list of conditions and the following
;     disclaimer. 
;   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
;     disclaimer in the documentation and/or other materials provided with the distribution. 
;   Neither the name of the author nor the names of its contributors may be used to endorse or promote
;     products derived from this software without specific prior written permission. 
;
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
; OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
; AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
; CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
; SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
; OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
; POSSIBILITY OF SUCH DAMAGE.
*/


#include "chicken.h"
#include <assert.h>
#include <float.h>
#include <signal.h>
#include <sys/stat.h>
#include <strings.h>

#ifdef HAVE_SYSEXITS_H
# include <sysexits.h>
#endif

#ifdef __ANDROID__
# include <android/log.h>
#endif

#if !defined(PIC)
# define NO_DLOAD2
#endif

#ifndef NO_DLOAD2
# ifdef HAVE_DLFCN_H
#  include <dlfcn.h>
# endif

# ifdef HAVE_DL_H
#  include <dl.h>
# endif
#endif

#ifndef EX_SOFTWARE
# define EX_SOFTWARE  70
#endif

#ifndef EOVERFLOW
# define EOVERFLOW  0
#endif

/* TODO: Include sys/select.h? Windows doesn't seem to have it... */
#ifndef NO_POSIX_POLL
#  include <poll.h>
#endif

#if !defined(C_NONUNIX)

# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>
# include <fcntl.h>

/* ITIMER_PROF is more precise, but Cygwin doesn't support it... */
# ifdef __CYGWIN__
#  define C_PROFILE_SIGNAL SIGALRM
#  define C_PROFILE_TIMER  ITIMER_REAL
# else
#  define C_PROFILE_SIGNAL SIGPROF
#  define C_PROFILE_TIMER  ITIMER_PROF
# endif

#else

# define C_PROFILE_SIGNAL -1          /* Stupid way to avoid error */

#ifdef ECOS
#include <cyg/kernel/kapi.h>
static C_TLS int timezone;
#define NSIG                          32
#endif

#endif

#ifndef RTLD_GLOBAL
# define RTLD_GLOBAL                   0
#endif

#ifndef RTLD_NOW
# define RTLD_NOW                      0
#endif

#ifndef RTLD_LOCAL
# define RTLD_LOCAL                    0
#endif

#ifndef RTLD_LAZY
# define RTLD_LAZY                     0
#endif

#if defined(_WIN32) && !defined(__CYGWIN__)
/* Include winsock2 to get select() for check_fd_ready() */
# include <winsock2.h>
# include <windows.h>
/* Needed for ERROR_OPERATION_ABORTED */
# include <winerror.h>
#endif

/* For image_info retrieval */
#if defined(__HAIKU__)
# include <kernel/image.h>
#endif

/* For _NSGetExecutablePath */
#if defined(C_MACOSX)
# include <mach-o/dyld.h>
#endif

/* Parameters: */

#define RELAX_MULTIVAL_CHECK

#ifdef C_SIXTY_FOUR
# define DEFAULT_STACK_SIZE            (1024 * 1024)
# define DEFAULT_MAXIMAL_HEAP_SIZE     0x7ffffffffffffff0
#else
# define DEFAULT_STACK_SIZE            (256 * 1024)
# define DEFAULT_MAXIMAL_HEAP_SIZE     0x7ffffff0
#endif

#define DEFAULT_SYMBOL_TABLE_SIZE      2999
#define DEFAULT_KEYWORD_TABLE_SIZE      499
#define DEFAULT_HEAP_SIZE              DEFAULT_STACK_SIZE
#define MINIMAL_HEAP_SIZE              DEFAULT_STACK_SIZE
#define DEFAULT_SCRATCH_SPACE_SIZE     256
#define DEFAULT_HEAP_GROWTH            200
#define DEFAULT_HEAP_SHRINKAGE         50
#define DEFAULT_HEAP_SHRINKAGE_USED    25
#define DEFAULT_HEAP_MIN_FREE          (4 * 1024 * 1024)
#define HEAP_SHRINK_COUNTS             10
#define DEFAULT_FORWARDING_TABLE_SIZE  32
#define DEFAULT_COLLECTIBLES_SIZE      1024
#define DEFAULT_TRACE_BUFFER_SIZE      16
#define MIN_TRACE_BUFFER_SIZE          3

#define MAX_HASH_PREFIX                64

#define DEFAULT_TEMPORARY_STACK_SIZE   256
#define STRING_BUFFER_SIZE             4096
#define DEFAULT_MUTATION_STACK_SIZE    1024
#define PROFILE_TABLE_SIZE             1024

#define MAX_PENDING_INTERRUPTS         100

#ifdef C_DOUBLE_IS_32_BITS
# define FLONUM_PRINT_PRECISION         7
#else
# define FLONUM_PRINT_PRECISION         15
#endif

#define WORDS_PER_FLONUM               C_SIZEOF_FLONUM
#define INITIAL_TIMER_INTERRUPT_PERIOD 10000
#define HDUMP_TABLE_SIZE               1001

/* only for relevant for Windows: */

#define MAXIMAL_NUMBER_OF_COMMAND_LINE_ARGUMENTS 256


/* Constants: */

#ifdef C_SIXTY_FOUR
# ifdef C_LLP
#  define ALIGNMENT_HOLE_MARKER         ((C_word)0xfffffffffffffffeLL)
#  define UWORD_FORMAT_STRING           "0x%016llx"
#  define UWORD_COUNT_FORMAT_STRING     "%llu"
# else
#  define ALIGNMENT_HOLE_MARKER         ((C_word)0xfffffffffffffffeL)
#  define UWORD_FORMAT_STRING           "0x%016lx"
#  define UWORD_COUNT_FORMAT_STRING     "%lu"
# endif
#else
# define ALIGNMENT_HOLE_MARKER         ((C_word)0xfffffffe)
# define UWORD_FORMAT_STRING           "0x%08x"
# define UWORD_COUNT_FORMAT_STRING     "%u"
#endif

#ifdef C_LLP
# define LONG_FORMAT_STRING            "%lld"
#else
# define LONG_FORMAT_STRING            "%ld"
#endif

#define GC_MINOR           0
#define GC_MAJOR           1
#define GC_REALLOC         2


/* Macros: */

#define nmax(x, y)                   ((x) > (y) ? (x) : (y))
#define nmin(x, y)                   ((x) < (y) ? (x) : (y))
#define percentage(n, p)             ((C_long)(((double)(n) * (double)p) / 100))

#define clear_buffer_object(buf, obj) C_migrate_buffer_object(NULL, (C_word *)(buf), C_buf_end(buf), (obj))
#define move_buffer_object(ptr, buf, obj) C_migrate_buffer_object(ptr, (C_word *)(buf), C_buf_end(buf), (obj))

/* The bignum digit representation is fullword- little endian, so on
 * LE machines the halfdigits are numbered in the same order.  On BE
 * machines, we must swap the odd and even positions.
 */
#ifdef C_BIG_ENDIAN
#define C_uhword_ref(x, p)           ((C_uhword *)(x))[(p)^1]
#else
#define C_uhword_ref(x, p)           ((C_uhword *)(x))[(p)]
#endif
#define C_uhword_set(x, p, d)        (C_uhword_ref(x,p) = (d))

#define free_tmp_bignum(b)           C_free((void *)(b))

/* Forwarding pointers abuse the fact that objects must be
 * word-aligned, so we can just drop the lowest bit.
 */
#define is_fptr(x)                   (((x) & C_GC_FORWARDING_BIT) != 0)
#define ptr_to_fptr(x)               (((C_uword)(x) >> 1) | C_GC_FORWARDING_BIT)
#define fptr_to_ptr(x)               ((C_uword)(x) << 1)

#define C_check_real(x, w, v)       if(((x) & C_FIXNUM_BIT) != 0) v = C_unfix(x); \
                                     else if(C_immediatep(x) || C_block_header(x) != C_FLONUM_TAG) \
                                       barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, w, x); \
                                     else v = C_flonum_magnitude(x);


#define C_pte(name)                  pt[ i ].id = #name; pt[ i++ ].ptr = (void *)name;

#ifndef SIGBUS
# define SIGBUS                      0
#endif

#define C_thread_id(x)   C_block_item((x), 14)


/* Type definitions: */

typedef C_regparm C_word C_fcall (*integer_plusmin_op) (C_word **ptr, C_word n, C_word x, C_word y);

typedef struct lf_list_struct
{
  C_word *lf;
  int count;
  struct lf_list_struct *next, *prev;
  C_PTABLE_ENTRY *ptable;
  void *module_handle;
  char *module_name;
} LF_LIST;

typedef struct finalizer_node_struct
{
  struct finalizer_node_struct
    *next,
    *previous;
  C_word
    item,
    finalizer;
} FINALIZER_NODE;

typedef struct trace_info_struct
{
  /* Either raw_location is set to a C string or NULL */
  C_char *raw_location;
  /* cooked_location is C_SCHEME_FALSE or a Scheme string (when raw_location is NULL) */
  C_word cooked_location, cooked1, cooked2, thread;
} TRACE_INFO;

typedef struct hdump_bucket_struct
{
  C_word key;
  int count, total;
  struct hdump_bucket_struct *next;
} HDUMP_BUCKET;

typedef struct profile_bucket_struct
{
  C_char *key;
  C_uword sample_count; /* Multiplied by profile freq = time spent */
  C_uword call_count;   /* Distinct calls seen while sampling */
  struct profile_bucket_struct *next;
} PROFILE_BUCKET;


/* Variables: */

C_TLS C_word
  *C_temporary_stack,
  *C_temporary_stack_bottom,
  *C_temporary_stack_limit,
  *C_stack_limit,         /* "Soft" limit, may be reset to force GC */
  *C_stack_hard_limit,    /* Actual stack limit */
  *C_scratchspace_start,
  *C_scratchspace_top,
  *C_scratchspace_limit,
   C_scratch_usage;
C_TLS C_long
  C_timer_interrupt_counter,
  C_initial_timer_interrupt_period;
C_TLS C_byte 
  *C_fromspace_top,
  *C_fromspace_limit;
#ifdef HAVE_SIGSETJMP
C_TLS sigjmp_buf C_restart;
#else
C_TLS jmp_buf C_restart;
#endif
C_TLS void *C_restart_trampoline;
C_TLS C_word C_restart_c;
C_TLS int C_entry_point_status;
C_TLS int (*C_gc_mutation_hook)(C_word *slot, C_word val);
C_TLS void (*C_gc_trace_hook)(C_word *var, int mode);
C_TLS void (*C_panic_hook)(C_char *msg) = NULL;
C_TLS void (*C_pre_gc_hook)(int mode) = NULL;
C_TLS void (*C_post_gc_hook)(int mode, C_long ms) = NULL;
C_TLS C_word (*C_debugger_hook)(C_DEBUG_INFO *cell, C_word c, C_word *av, C_char *cloc) = NULL;

C_TLS int
  C_gui_mode = 0,
  C_abort_on_thread_exceptions,
  C_interrupts_enabled,
  C_disable_overflow_check,
  C_heap_size_is_fixed,
  C_trace_buffer_size = DEFAULT_TRACE_BUFFER_SIZE,
  C_max_pending_finalizers = C_DEFAULT_MAX_PENDING_FINALIZERS,
  C_debugging = 0,
  C_main_argc;
C_TLS C_uword 
  C_heap_growth = DEFAULT_HEAP_GROWTH,
  C_heap_shrinkage = DEFAULT_HEAP_SHRINKAGE,
  C_heap_shrinkage_used = DEFAULT_HEAP_SHRINKAGE_USED,
  C_heap_half_min_free = DEFAULT_HEAP_MIN_FREE,
  C_maximal_heap_size = DEFAULT_MAXIMAL_HEAP_SIZE,
  heap_shrink_counter = 0;
C_TLS time_t
  C_startup_time_sec,
  C_startup_time_msec,
  profile_frequency = 10000;
C_TLS char 
  **C_main_argv,
#ifdef SEARCH_EXE_PATH
  *C_main_exe = NULL,
#endif
  *C_dlerror;

static C_TLS TRACE_INFO
  *trace_buffer,
  *trace_buffer_limit,
  *trace_buffer_top;

static C_TLS C_byte 
  *heapspace1, 
  *heapspace2,
  *fromspace_start,
  *tospace_start,
  *tospace_top,
  *tospace_limit,
  *new_tospace_start,
  *new_tospace_top,
  *new_tospace_limit;
static C_TLS C_uword
  heapspace1_size,
  heapspace2_size,
  heap_size,
  scratchspace_size,
  temporary_stack_size,
  fixed_temporary_stack_size = 0,
  maximum_heap_usage;
static C_TLS C_char
  buffer[ STRING_BUFFER_SIZE ],
  *private_repository = NULL,
  *current_module_name,
  *save_string;
static C_TLS C_SYMBOL_TABLE
  *symbol_table,
  *symbol_table_list,
  *keyword_table;
static C_TLS C_word 
  **collectibles,
  **collectibles_top,
  **collectibles_limit,
  **mutation_stack_bottom,
  **mutation_stack_limit,
  **mutation_stack_top,
  *stack_bottom,
  weak_pair_chain,
  locative_chain,
  error_location,
  interrupt_hook_symbol,
  current_thread_symbol,
  error_hook_symbol,
  pending_finalizers_symbol,
  callback_continuation_stack_symbol,
  core_provided_symbol,
  u8vector_symbol,
  s8vector_symbol,
  u16vector_symbol,
  s16vector_symbol,
  u32vector_symbol,
  s32vector_symbol,
  u64vector_symbol,
  s64vector_symbol,
  f32vector_symbol,
  f64vector_symbol,
  *forwarding_table;
static C_TLS int 
  trace_buffer_full,
  forwarding_table_size,
  return_to_host,
  page_size,
  show_trace,
  fake_tty_flag,
  debug_mode,
  dump_heap_on_exit,
  gc_bell,
  gc_report_flag = 0,
  gc_mode,
  gc_count_1,
  gc_count_1_total,
  gc_count_2,
  stack_size_changed,
  dlopen_flags,
  heap_size_changed,
  random_state_initialized = 0,
  chicken_is_running,
  chicken_ran_once,
  pass_serious_signals = 1,
  callback_continuation_level;
static volatile C_TLS int
  serious_signal_occurred = 0,
  profiling = 0;
static C_TLS unsigned int
  mutation_count,
  tracked_mutation_count,
  stack_check_demand,
  stack_size;
static C_TLS int chicken_is_initialized;
#ifdef HAVE_SIGSETJMP
static C_TLS sigjmp_buf gc_restart;
#else
static C_TLS jmp_buf gc_restart;
#endif
static C_TLS double
  timer_start_ms,
  gc_ms,
  timer_accumulated_gc_ms,
  interrupt_time,
  last_interrupt_latency;
static C_TLS LF_LIST *lf_list;
static C_TLS int signal_mapping_table[ NSIG ];
static C_TLS int
  live_finalizer_count,
  allocated_finalizer_count,
  pending_finalizer_count,
  callback_returned_flag;
static C_TLS C_GC_ROOT *gc_root_list = NULL;
static C_TLS FINALIZER_NODE 
  *finalizer_list,
  *finalizer_free_list,
  **pending_finalizer_indices;
static C_TLS void *current_module_handle;
static C_TLS int flonum_print_precision = FLONUM_PRINT_PRECISION;
static C_TLS HDUMP_BUCKET **hdump_table;
static C_TLS PROFILE_BUCKET
  *next_profile_bucket = NULL,
  **profile_table = NULL;
static C_TLS int 
  pending_interrupts[ MAX_PENDING_INTERRUPTS ],
  pending_interrupts_count,
  handling_interrupts;
static C_TLS C_uword random_state[ C_RANDOM_STATE_SIZE / sizeof(C_uword) ]; 
static C_TLS int random_state_index = 0;


/* Prototypes: */

static void parse_argv(C_char *cmds);
static void initialize_symbol_table(void);
static void global_signal_handler(int signum);
static C_word arg_val(C_char *arg);
static void barf(int code, char *loc, ...) C_noret;
static void try_extended_number(char *ext_proc_name, C_word c, C_word k, ...) C_noret;
static void panic(C_char *msg) C_noret;
static void usual_panic(C_char *msg) C_noret;
static void horror(C_char *msg) C_noret;
static void C_fcall really_mark(C_word *x, C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit) C_regparm;
static C_cpsproc(values_continuation) C_noret;
static C_word add_symbol(C_word **ptr, C_word key, C_word string, C_SYMBOL_TABLE *stable);
static C_regparm int C_fcall C_in_new_heapp(C_word x);
static C_regparm C_word bignum_times_bignum_unsigned(C_word **ptr, C_word x, C_word y, C_word negp);
static C_regparm C_word bignum_extract_digits(C_word **ptr, C_word n, C_word x, C_word start, C_word end);

static C_regparm C_word bignum_times_bignum_karatsuba(C_word **ptr, C_word x, C_word y, C_word negp);
static C_word bignum_plus_unsigned(C_word **ptr, C_word x, C_word y, C_word negp);
static C_word rat_plusmin_integer(C_word **ptr, C_word rat, C_word i, integer_plusmin_op plusmin_op);
static C_word integer_minus_rat(C_word **ptr, C_word i, C_word rat);
static C_word rat_plusmin_rat(C_word **ptr, C_word x, C_word y, integer_plusmin_op plusmin_op);
static C_word rat_times_integer(C_word **ptr, C_word x, C_word y);
static C_word rat_times_rat(C_word **ptr, C_word x, C_word y);
static C_word cplx_times(C_word **ptr, C_word rx, C_word ix, C_word ry, C_word iy);
static C_word bignum_minus_unsigned(C_word **ptr, C_word x, C_word y);
static C_regparm void integer_divrem(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r);
static C_regparm C_word bignum_remainder_unsigned_halfdigit(C_word x, C_word y);
static C_regparm void bignum_divrem(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r);
static C_regparm C_word bignum_divide_burnikel_ziegler(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r);
static C_regparm void burnikel_ziegler_3n_div_2n(C_word **ptr, C_word a12, C_word a3, C_word b, C_word b1, C_word b2, C_word n, C_word *q, C_word *r);
static C_regparm void burnikel_ziegler_2n_div_1n(C_word **ptr, C_word a, C_word b, C_word b1, C_word b2, C_word n, C_word *q, C_word *r);
static C_word rat_cmp(C_word x, C_word y);
static void fabs_frexp_to_digits(C_uword exp, double sign, C_uword *start, C_uword *scan);
static C_word int_flo_cmp(C_word intnum, C_word flonum);
static C_word flo_int_cmp(C_word flonum, C_word intnum);
static C_word rat_flo_cmp(C_word ratnum, C_word flonum);
static C_word flo_rat_cmp(C_word flonum, C_word ratnum);
static C_word basic_cmp(C_word x, C_word y, char *loc, int eqp);
static int bignum_cmp_unsigned(C_word x, C_word y);
static C_word C_fcall hash_string(int len, C_char *str, C_word m, C_word r, int ci) C_regparm;
static C_word C_fcall lookup(C_word key, int len, C_char *str, C_SYMBOL_TABLE *stable) C_regparm;
static C_word C_fcall lookup_bucket(C_word sym, C_SYMBOL_TABLE *stable) C_regparm;
static double compute_symbol_table_load(double *avg_bucket_len, int *total);
static double C_fcall decode_flonum_literal(C_char *str) C_regparm;
static C_regparm C_word str_to_bignum(C_word bignum, char *str, char *str_end, int radix);
static void C_fcall mark_nested_objects(C_byte *heap_scan_top, C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit) C_regparm;
static void C_fcall mark_live_objects(C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit) C_regparm;
static void C_fcall mark_live_heap_only_objects(C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit) C_regparm;
static C_word C_fcall intern0(C_char *name) C_regparm;
static void C_fcall update_weak_pairs(int mode, C_byte *undead_start, C_byte *undead_end) C_regparm;
static void C_fcall update_locatives(int mode, C_byte *undead_start, C_byte *undead_end) C_regparm;
static LF_LIST *find_module_handle(C_char *name);
static void set_profile_timer(C_uword freq);
static void take_profile_sample();

static C_cpsproc(call_cc_wrapper) C_noret;
static C_cpsproc(call_cc_values_wrapper) C_noret;
static C_cpsproc(gc_2) C_noret;
static C_cpsproc(allocate_vector_2) C_noret;
static C_cpsproc(generic_trampoline) C_noret;
static void handle_interrupt(void *trampoline) C_noret;
static C_cpsproc(callback_return_continuation) C_noret;
static C_cpsproc(termination_continuation) C_noret;
static C_cpsproc(become_2) C_noret;
static C_cpsproc(copy_closure_2) C_noret;
static C_cpsproc(dump_heap_state_2) C_noret;
static C_cpsproc(sigsegv_trampoline) C_noret;
static C_cpsproc(sigill_trampoline) C_noret;
static C_cpsproc(sigfpe_trampoline) C_noret;
static C_cpsproc(sigbus_trampoline) C_noret;
static C_cpsproc(bignum_to_str_2) C_noret;

static C_word allocate_tmp_bignum(C_word size, C_word negp, C_word initp);
static C_word allocate_scratch_bignum(C_word **ptr, C_word size, C_word negp, C_word initp);
static void bignum_digits_destructive_negate(C_word bignum);
static C_uword bignum_digits_destructive_scale_up_with_carry(C_uword *start, C_uword *end, C_uword factor, C_uword carry);
static C_uword bignum_digits_destructive_scale_down(C_uword *start, C_uword *end, C_uword denominator);
static C_uword bignum_digits_destructive_shift_right(C_uword *start, C_uword *end, int shift_right, int negp);
static C_uword bignum_digits_destructive_shift_left(C_uword *start, C_uword *end, int shift_left);
static C_regparm void bignum_digits_multiply(C_word x, C_word y, C_word result);
static void bignum_divide_unsigned(C_word **ptr, C_word num, C_word denom, C_word *q, C_word q_negp, C_word *r, C_word r_negp);
static C_regparm void bignum_destructive_divide_unsigned_small(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r);
static C_regparm void bignum_destructive_divide_full(C_word numerator, C_word denominator, C_word quotient, C_word remainder, C_word return_remainder);
static C_regparm void bignum_destructive_divide_normalized(C_word big_u, C_word big_v, C_word big_q);

static C_PTABLE_ENTRY *create_initial_ptable();

#if !defined(NO_DLOAD2) && (defined(HAVE_DLFCN_H) || defined(HAVE_DL_H) || (defined(HAVE_LOADLIBRARY) && defined(HAVE_GETPROCADDRESS)))
static void C_ccall dload_2(C_word, C_word *) C_noret;
#endif

static void
C_dbg(C_char *prefix, C_char *fstr, ...)
{
  va_list va;

  va_start(va, fstr);
#ifdef __ANDROID__
  __android_log_vprint(ANDROID_LOG_DEBUG, prefix, fstr, va);
#else
  C_fflush(C_stdout);
  C_fprintf(C_stderr, "[%s] ", prefix);
  C_vfprintf(C_stderr, fstr, va);
  C_fflush(C_stderr);
#endif
  va_end(va);
}

/* Startup code: */

int CHICKEN_main(int argc, char *argv[], void *toplevel) 
{
  C_word h, s, n;

  if(C_gui_mode) {
#ifdef _WIN32
    parse_argv(GetCommandLine());
    argc = C_main_argc;
    argv = C_main_argv;
#else
    /* ??? */
#endif
  }

  pass_serious_signals = 0;
  CHICKEN_parse_command_line(argc, argv, &h, &s, &n);
  
  if(!CHICKEN_initialize(h, s, n, toplevel))
    panic(C_text("cannot initialize - out of memory"));

  CHICKEN_run(NULL);
  return 0;
}


/* Custom argv parser for Windoze: */

void parse_argv(C_char *cmds)
{
  C_char *ptr = cmds,
         *bptr0, *bptr, *aptr;
  int n = 0;

  C_main_argv = (C_char **)malloc(MAXIMAL_NUMBER_OF_COMMAND_LINE_ARGUMENTS * sizeof(C_char *));

  if(C_main_argv == NULL)
    panic(C_text("cannot allocate argument-list buffer"));

  C_main_argc = 0;

  for(;;) {
    while(isspace((int)(*ptr))) ++ptr;

    if(*ptr == '\0') break;

    for(bptr0 = bptr = buffer; !isspace((int)(*ptr)) && *ptr != '\0'; *(bptr++) = *(ptr++))
      ++n;

    *bptr = '\0';

    aptr = (C_char*) malloc(sizeof(C_char) * (n + 1));
    if (!aptr)
      panic(C_text("cannot allocate argument buffer"));

    C_strlcpy(aptr, bptr0, sizeof(C_char) * (n + 1));

    C_main_argv[ C_main_argc++ ] = aptr;
  }
}


/* Initialize runtime system: */

int CHICKEN_initialize(int heap, int stack, int symbols, void *toplevel)
{
  C_SCHEME_BLOCK *k0;
  int i;
#ifdef HAVE_SIGACTION
  struct sigaction sa;
#endif

  /* FIXME Should have C_tzset in chicken.h? */
#if defined(__MINGW32__)
# if defined(__MINGW64_VERSION_MAJOR)
    ULONGLONG tick_count = GetTickCount64();
# else
    /* mingw32 doesn't yet have GetTickCount64 support */
    ULONGLONG tick_count = GetTickCount();
# endif
  C_startup_time_sec = tick_count / 1000;
  C_startup_time_msec = tick_count % 1000;
  /* Make sure _tzname, _timezone, and _daylight are set */
  _tzset();
#else
  struct timeval tv;
  C_gettimeofday(&tv, NULL);
  C_startup_time_sec = tv.tv_sec;
  C_startup_time_msec = tv.tv_usec / 1000;
  /* Make sure tzname, timezone, and daylight are set */
  tzset();
#endif

  if(chicken_is_initialized) return 1;
  else chicken_is_initialized = 1;

#if defined(__ANDROID__) && defined(DEBUGBUILD)
  debug_mode = 2;
#endif

  if(debug_mode) 
    C_dbg(C_text("debug"), C_text("application startup...\n"));

  C_panic_hook = usual_panic;
  symbol_table_list = NULL;

  symbol_table = C_new_symbol_table(".", symbols ? symbols : DEFAULT_SYMBOL_TABLE_SIZE);

  if(symbol_table == NULL)
    return 0;

  keyword_table = C_new_symbol_table("kw", symbols ? symbols / 4 : DEFAULT_KEYWORD_TABLE_SIZE);

  if(keyword_table == NULL)
    return 0;

  page_size = 0;
  stack_size = stack ? stack : DEFAULT_STACK_SIZE;
  C_set_or_change_heap_size(heap ? heap : DEFAULT_HEAP_SIZE, 0);

  /* Allocate temporary stack: */
  temporary_stack_size = fixed_temporary_stack_size ? fixed_temporary_stack_size : DEFAULT_TEMPORARY_STACK_SIZE;
  if((C_temporary_stack_limit = (C_word *)C_malloc(temporary_stack_size * sizeof(C_word))) == NULL)
    return 0;
  
  C_temporary_stack_bottom = C_temporary_stack_limit + temporary_stack_size;
  C_temporary_stack = C_temporary_stack_bottom;
  
  /* Allocate mutation stack: */
  mutation_stack_bottom = (C_word **)C_malloc(DEFAULT_MUTATION_STACK_SIZE * sizeof(C_word *));

  if(mutation_stack_bottom == NULL) return 0;

  mutation_stack_top = mutation_stack_bottom;
  mutation_stack_limit = mutation_stack_bottom + DEFAULT_MUTATION_STACK_SIZE;
  C_gc_mutation_hook = NULL;
  C_gc_trace_hook = NULL;

  /* Initialize finalizer lists: */
  finalizer_list = NULL;
  finalizer_free_list = NULL;
  pending_finalizer_indices =
      (FINALIZER_NODE **)C_malloc(C_max_pending_finalizers * sizeof(FINALIZER_NODE *));

  if(pending_finalizer_indices == NULL) return 0;

  /* Initialize forwarding table: */
  forwarding_table =
      (C_word *)C_malloc((DEFAULT_FORWARDING_TABLE_SIZE + 1) * 2 * sizeof(C_word));

  if(forwarding_table == NULL) return 0;
  
  *forwarding_table = 0;
  forwarding_table_size = DEFAULT_FORWARDING_TABLE_SIZE;

  /* Setup collectibles: */
  collectibles = (C_word **)C_malloc(sizeof(C_word *) * DEFAULT_COLLECTIBLES_SIZE);

  if(collectibles == NULL) return 0;

  collectibles_top = collectibles;
  collectibles_limit = collectibles + DEFAULT_COLLECTIBLES_SIZE;
  gc_root_list = NULL;
 
#if !defined(NO_DLOAD2) && defined(HAVE_DLFCN_H)
  dlopen_flags = RTLD_LAZY | RTLD_GLOBAL;
#else
  dlopen_flags = 0;
#endif

#ifdef HAVE_SIGACTION
    sa.sa_flags = 0;
    sigfillset(&sa.sa_mask); /* See note in C_establish_signal_handler() */
    sa.sa_handler = global_signal_handler;
#endif

  /* setup signal handlers */
  if(!pass_serious_signals) {
#ifdef HAVE_SIGACTION
    C_sigaction(SIGBUS, &sa, NULL);
    C_sigaction(SIGFPE, &sa, NULL);
    C_sigaction(SIGILL, &sa, NULL);
    C_sigaction(SIGSEGV, &sa, NULL);
#else
    C_signal(SIGBUS, global_signal_handler);
    C_signal(SIGILL, global_signal_handler);
    C_signal(SIGFPE, global_signal_handler);
    C_signal(SIGSEGV, global_signal_handler);
#endif
  }

  tracked_mutation_count = mutation_count = gc_count_1 = gc_count_1_total = gc_count_2 = maximum_heap_usage = 0;
  lf_list = NULL;
  C_register_lf2(NULL, 0, create_initial_ptable());
  C_restart_trampoline = (void *)toplevel;
  trace_buffer = NULL;
  C_clear_trace_buffer();
  chicken_is_running = chicken_ran_once = 0;
  pending_interrupts_count = 0;
  handling_interrupts = 0;
  last_interrupt_latency = 0;
  C_interrupts_enabled = 1;
  C_initial_timer_interrupt_period = INITIAL_TIMER_INTERRUPT_PERIOD;
  C_timer_interrupt_counter = INITIAL_TIMER_INTERRUPT_PERIOD;
  memset(signal_mapping_table, 0, sizeof(int) * NSIG);
  C_dlerror = "cannot load compiled code dynamically - this is a statically linked executable";
  error_location = C_SCHEME_FALSE;
  C_pre_gc_hook = NULL;
  C_post_gc_hook = NULL;
  C_scratchspace_start = NULL;
  C_scratchspace_top = NULL;
  C_scratchspace_limit = NULL;
  C_scratch_usage = 0;
  scratchspace_size = 0;
  live_finalizer_count = 0;
  allocated_finalizer_count = 0;
  current_module_name = NULL;
  current_module_handle = NULL;
  callback_continuation_level = 0;
  weak_pair_chain = (C_word)NULL;
  locative_chain = (C_word)NULL;
  gc_ms = 0;
  if (!random_state_initialized) {
    srand(time(NULL));
    random_state_initialized = 1;
  }

  for(i = 0; i < C_RANDOM_STATE_SIZE / sizeof(C_uword); ++i)
    random_state[ i ] = rand();

  initialize_symbol_table();

  if (profiling) {
#ifndef C_NONUNIX
# ifdef HAVE_SIGACTION
    C_sigaction(C_PROFILE_SIGNAL, &sa, NULL);
# else
    C_signal(C_PROFILE_SIGNAL, global_signal_handler);
# endif
#endif

    profile_table = (PROFILE_BUCKET **)C_malloc(PROFILE_TABLE_SIZE * sizeof(PROFILE_BUCKET *));

    if(profile_table == NULL)
      panic(C_text("out of memory - can not allocate profile table"));

    C_memset(profile_table, 0, sizeof(PROFILE_BUCKET *) * PROFILE_TABLE_SIZE);
  }
  
  /* create k to invoke code for system-startup: */
  k0 = (C_SCHEME_BLOCK *)C_align((C_word)C_fromspace_top);
  C_fromspace_top += C_align(2 * sizeof(C_word));
  k0->header = C_CLOSURE_TYPE | 1;
  C_set_block_item(k0, 0, (C_word)termination_continuation);
  C_save(k0);
  C_save(C_SCHEME_UNDEFINED);
  C_restart_c = 2;
  return 1;
}


void *C_get_statistics(void) {
  static void *stats[ 8 ];

  stats[ 0 ] = fromspace_start;
  stats[ 1 ] = C_fromspace_limit;
  stats[ 2 ] = C_scratchspace_start;
  stats[ 3 ] = C_scratchspace_limit;
  stats[ 4 ] = C_stack_limit;
  stats[ 5 ] = stack_bottom;
  stats[ 6 ] = C_fromspace_top;
  stats[ 7 ] = C_scratchspace_top;
  return stats;
}


static C_PTABLE_ENTRY *create_initial_ptable()
{
  /* IMPORTANT: hardcoded table size -
     this must match the number of C_pte calls + 1 (NULL terminator)! */
  C_PTABLE_ENTRY *pt = (C_PTABLE_ENTRY *)C_malloc(sizeof(C_PTABLE_ENTRY) * 63);
  int i = 0;

  if(pt == NULL)
    panic(C_text("out of memory - cannot create initial ptable"));

  C_pte(termination_continuation);
  C_pte(callback_return_continuation);
  C_pte(values_continuation);
  C_pte(call_cc_values_wrapper);
  C_pte(call_cc_wrapper);
  C_pte(C_gc);
  C_pte(C_allocate_vector);
  C_pte(C_make_structure);
  C_pte(C_ensure_heap_reserve);
  C_pte(C_return_to_host);
  C_pte(C_get_symbol_table_info);
  C_pte(C_get_memory_info);
  C_pte(C_decode_seconds);
  C_pte(C_stop_timer);
  C_pte(C_dload);
  C_pte(C_set_dlopen_flags);
  C_pte(C_become);
  C_pte(C_apply_values);
  C_pte(C_times);
  C_pte(C_minus);
  C_pte(C_plus);
  C_pte(C_nequalp);
  C_pte(C_greaterp);
  /* IMPORTANT: have you read the comments at the start and the end of this function? */
  C_pte(C_lessp);
  C_pte(C_greater_or_equal_p);
  C_pte(C_less_or_equal_p);
  C_pte(C_number_to_string);
  C_pte(C_make_symbol);
  C_pte(C_string_to_symbol);
  C_pte(C_string_to_keyword);
  C_pte(C_apply);
  C_pte(C_call_cc);
  C_pte(C_values);
  C_pte(C_call_with_values);
  C_pte(C_continuation_graft);
  C_pte(C_open_file_port);
  C_pte(C_software_type);
  C_pte(C_machine_type);
  C_pte(C_machine_byte_order);
  C_pte(C_software_version);
  C_pte(C_build_platform);
  C_pte(C_make_pointer);
  /* IMPORTANT: have you read the comments at the start and the end of this function? */
  C_pte(C_make_tagged_pointer);
  C_pte(C_peek_signed_integer);
  C_pte(C_peek_unsigned_integer);
  C_pte(C_peek_int64);
  C_pte(C_peek_uint64);
  C_pte(C_context_switch);
  C_pte(C_register_finalizer);
  C_pte(C_copy_closure);
  C_pte(C_dump_heap_state);
  C_pte(C_filter_heap_objects);
  C_pte(C_fixnum_to_string);
  C_pte(C_integer_to_string);
  C_pte(C_flonum_to_string);
  C_pte(C_signum);
  C_pte(C_quotient_and_remainder);
  C_pte(C_u_integer_quotient_and_remainder);
  C_pte(C_bitwise_and);
  C_pte(C_bitwise_ior);
  C_pte(C_bitwise_xor);

  /* IMPORTANT: did you remember the hardcoded pte table size? */
  pt[ i ].id = NULL;
  return pt;
}


void *CHICKEN_new_gc_root_2(int finalizable)
{
  C_GC_ROOT *r = (C_GC_ROOT *)C_malloc(sizeof(C_GC_ROOT));

  if(r == NULL)
    panic(C_text("out of memory - cannot allocate GC root"));

  r->value = C_SCHEME_UNDEFINED;
  r->next = gc_root_list;
  r->prev = NULL;
  r->finalizable = finalizable;

  if(gc_root_list != NULL) gc_root_list->prev = r;

  gc_root_list = r;
  return (void *)r;
}


void *CHICKEN_new_gc_root()
{
  return CHICKEN_new_gc_root_2(0);
}


void *CHICKEN_new_finalizable_gc_root()
{
  return CHICKEN_new_gc_root_2(1);
}


void CHICKEN_delete_gc_root(void *root)
{
  C_GC_ROOT *r = (C_GC_ROOT *)root;

  if(r->prev == NULL) gc_root_list = r->next;
  else r->prev->next = r->next;

  if(r->next != NULL) r->next->prev = r->prev;

  C_free(root);
}


void *CHICKEN_global_lookup(char *name)
{
  int 
    len = C_strlen(name),
    key = hash_string(len, name, symbol_table->size, symbol_table->rand, 0);
  C_word s;
  void *root = CHICKEN_new_gc_root();

  if(C_truep(s = lookup(key, len, name, symbol_table))) {
    if(C_block_item(s, 0) != C_SCHEME_UNBOUND) {
      CHICKEN_gc_root_set(root, s);
      return root;
    }
  }

  return NULL;
}


int CHICKEN_is_running()
{
  return chicken_is_running;
}


void CHICKEN_interrupt()
{
  C_timer_interrupt_counter = 0;
}


C_regparm C_SYMBOL_TABLE *C_new_symbol_table(char *name, unsigned int size)
{
  C_SYMBOL_TABLE *stp;
  int i;

  if((stp = C_find_symbol_table(name)) != NULL) return stp;

  if((stp = (C_SYMBOL_TABLE *)C_malloc(sizeof(C_SYMBOL_TABLE))) == NULL)
    return NULL;

  stp->name = name;
  stp->size = size;
  stp->next = symbol_table_list;
  stp->rand = rand();

  if((stp->table = (C_word *)C_malloc(size * sizeof(C_word))) == NULL)
    return NULL;

  for(i = 0; i < stp->size; stp->table[ i++ ] = C_SCHEME_END_OF_LIST);

  symbol_table_list = stp;
  return stp;
}  


C_regparm C_SYMBOL_TABLE *C_find_symbol_table(char *name)
{
  C_SYMBOL_TABLE *stp;

  for(stp = symbol_table_list; stp != NULL; stp = stp->next)
    if(!C_strcmp(name, stp->name)) return stp;

  return NULL;
}


C_regparm C_word C_find_symbol(C_word str, C_SYMBOL_TABLE *stable)
{
  C_char *sptr = C_c_string(str);
  int len = C_header_size(str);
  int key;
  C_word s;

  if(stable == NULL) stable = symbol_table;

  key = hash_string(len, sptr, stable->size, stable->rand, 0);

  if(C_truep(s = lookup(key, len, sptr, stable))) return s;
  else return C_SCHEME_FALSE;
}


/* Setup symbol-table with internally used symbols; */

void initialize_symbol_table(void)
{
  int i;

  for(i = 0; i < symbol_table->size; symbol_table->table[ i++ ] = C_SCHEME_END_OF_LIST);

  /* Obtain reference to hooks for later: */
  core_provided_symbol = C_intern2(C_heaptop, C_text("##core#provided"));
  interrupt_hook_symbol = C_intern2(C_heaptop, C_text("##sys#interrupt-hook"));
  error_hook_symbol = C_intern2(C_heaptop, C_text("##sys#error-hook"));
  callback_continuation_stack_symbol = C_intern3(C_heaptop, C_text("##sys#callback-continuation-stack"), C_SCHEME_END_OF_LIST);
  pending_finalizers_symbol = C_intern2(C_heaptop, C_text("##sys#pending-finalizers"));
  current_thread_symbol = C_intern3(C_heaptop, C_text("##sys#current-thread"), C_SCHEME_FALSE);

  /* SRFI-4 tags */
  u8vector_symbol = C_intern2(C_heaptop, C_text("u8vector"));
  s8vector_symbol = C_intern2(C_heaptop, C_text("s8vector"));
  u16vector_symbol = C_intern2(C_heaptop, C_text("u16vector"));
  s16vector_symbol = C_intern2(C_heaptop, C_text("s16vector"));
  u32vector_symbol = C_intern2(C_heaptop, C_text("u32vector"));
  s32vector_symbol = C_intern2(C_heaptop, C_text("s32vector"));
  u64vector_symbol = C_intern2(C_heaptop, C_text("u64vector"));
  s64vector_symbol = C_intern2(C_heaptop, C_text("s64vector"));
  f32vector_symbol = C_intern2(C_heaptop, C_text("f32vector"));
  f64vector_symbol = C_intern2(C_heaptop, C_text("f64vector"));
}


C_regparm C_word C_find_keyword(C_word str, C_SYMBOL_TABLE *kwtable)
{
  C_char *sptr = C_c_string(str);
  int len = C_header_size(str);
  int key;
  C_word s;

  if(kwtable == NULL) kwtable = keyword_table;

  key = hash_string(len, sptr, kwtable->size, kwtable->rand, 0);

  if(C_truep(s = lookup(key, len, sptr, kwtable))) return s;
  else return C_SCHEME_FALSE;
}


void C_ccall sigsegv_trampoline(C_word c, C_word *av)
{
  barf(C_MEMORY_VIOLATION_ERROR, NULL);
}


void C_ccall sigbus_trampoline(C_word c, C_word *av)
{
  barf(C_BUS_ERROR, NULL);
}


void C_ccall sigfpe_trampoline(C_word c, C_word *av)
{
  barf(C_FLOATING_POINT_EXCEPTION_ERROR, NULL);
}


void C_ccall sigill_trampoline(C_word c, C_word *av)
{
  barf(C_ILLEGAL_INSTRUCTION_ERROR, NULL);
}


/* This is called from POSIX signals: */

void global_signal_handler(int signum)
{
#if defined(HAVE_SIGPROCMASK)
  if(signum == SIGSEGV || signum == SIGFPE || signum == SIGILL || signum == SIGBUS) {
    sigset_t sset;
    
    if(serious_signal_occurred || !chicken_is_running) {
      switch(signum) {
      case SIGSEGV: panic(C_text("unrecoverable segmentation violation"));
      case SIGFPE: panic(C_text("unrecoverable floating-point exception"));
      case SIGILL: panic(C_text("unrecoverable illegal instruction error"));
      case SIGBUS: panic(C_text("unrecoverable bus error"));
      default: panic(C_text("unrecoverable serious condition"));
      }
    }
    else serious_signal_occurred = 1;

    /* unblock signal to avoid nested invocation of the handler */
    sigemptyset(&sset);
    sigaddset(&sset, signum);
    C_sigprocmask(SIG_UNBLOCK, &sset, NULL);

    switch(signum) {
    case SIGSEGV: C_reclaim(sigsegv_trampoline, 0);
    case SIGFPE: C_reclaim(sigfpe_trampoline, 0);
    case SIGILL: C_reclaim(sigill_trampoline, 0);
    case SIGBUS: C_reclaim(sigbus_trampoline, 0);
    default: panic(C_text("invalid serious signal"));
    }
  }
#endif

  /* TODO: Make full use of sigaction: check that /our/ timer expired */
  if (signum == C_PROFILE_SIGNAL && profiling) take_profile_sample();
  else C_raise_interrupt(signal_mapping_table[ signum ]);

#ifndef HAVE_SIGACTION
  /* not necessarily needed, but older UNIXen may not leave the handler installed: */
  C_signal(signum, global_signal_handler);
#endif
}


/* Align memory to page boundary */

static void *align_to_page(void *mem)
{
  return (void *)C_align((C_uword)mem);
}


static C_byte *
heap_alloc (size_t size, C_byte **page_aligned)
{
  C_byte *p;
  p = (C_byte *)C_malloc (size + page_size);

  if (p != NULL && page_aligned) *page_aligned = align_to_page (p);

  return p;
}


static void
heap_free (C_byte *ptr, size_t size)
{
  C_free (ptr);
}


static C_byte *
heap_realloc (C_byte *ptr, size_t old_size,
	      size_t new_size, C_byte **page_aligned)
{
  C_byte *p;
  p = (C_byte *)C_realloc (ptr, new_size + page_size);

  if (p != NULL && page_aligned) *page_aligned = align_to_page (p);

  return p;
}


/* Modify heap size at runtime: */

void C_set_or_change_heap_size(C_word heap, int reintern)
{
  C_byte *ptr1, *ptr2, *ptr1a, *ptr2a;
  C_word size = heap / 2;

  if(heap_size_changed && fromspace_start) return;

  if(fromspace_start && heap_size >= heap) return;

  if(debug_mode)
    C_dbg(C_text("debug"), C_text("heap resized to " UWORD_COUNT_FORMAT_STRING " bytes\n"), heap);

  heap_size = heap;

  if((ptr1 = heap_realloc (fromspace_start,
			   C_fromspace_limit - fromspace_start,
			   size, &ptr1a)) == NULL ||
     (ptr2 = heap_realloc (tospace_start,
			   tospace_limit - tospace_start,
			   size, &ptr2a)) == NULL)
    panic(C_text("out of memory - cannot allocate heap"));

  heapspace1 = ptr1;
  heapspace1_size = size;
  heapspace2 = ptr2;
  heapspace2_size = size;
  fromspace_start = ptr1a;
  C_fromspace_top = fromspace_start;
  C_fromspace_limit = fromspace_start + size;
  tospace_start = ptr2a;
  tospace_top = tospace_start;
  tospace_limit = tospace_start + size;
  mutation_stack_top = mutation_stack_bottom;

  if(reintern) initialize_symbol_table();
}
 

/* Modify stack-size at runtime: */

void C_do_resize_stack(C_word stack)
{
  C_uword old = stack_size,
          diff = stack - old;

  if(diff != 0 && !stack_size_changed) {
    if(debug_mode) 
      C_dbg(C_text("debug"), C_text("stack resized to " UWORD_COUNT_FORMAT_STRING " bytes\n"), stack);

    stack_size = stack;

#if C_STACK_GROWS_DOWNWARD
    C_stack_hard_limit = (C_word *)((C_byte *)C_stack_hard_limit - diff);
#else
    C_stack_hard_limit = (C_word *)((C_byte *)C_stack_hard_limit + diff);
#endif
    C_stack_limit = C_stack_hard_limit;
  }
}


/* Check whether nursery is sufficiently big: */

void C_check_nursery_minimum(C_word words)
{
  if(words >= C_bytestowords(stack_size))
    panic(C_text("nursery is too small - try higher setting using the `-:s' option"));
}

C_word C_resize_pending_finalizers(C_word size) {
  int sz = C_num_to_int(size);

  FINALIZER_NODE **newmem = 
    (FINALIZER_NODE **)C_realloc(pending_finalizer_indices, sz * sizeof(FINALIZER_NODE *));
  
  if (newmem == NULL)
    return C_SCHEME_FALSE;

  pending_finalizer_indices = newmem;
  C_max_pending_finalizers = sz;
  return C_SCHEME_TRUE;
}


/* Parse runtime options from command-line: */

void CHICKEN_parse_command_line(int argc, char *argv[], C_word *heap, C_word *stack, C_word *symbols)
{
  int i;
  char *ptr;
  C_word x;

  C_main_argc = argc;
  C_main_argv = argv;

  *heap = DEFAULT_HEAP_SIZE;
  *stack = DEFAULT_STACK_SIZE;
  *symbols = DEFAULT_SYMBOL_TABLE_SIZE;

  for(i = 1; i < C_main_argc; ++i) {
    if (strncmp(C_main_argv[ i ], C_text("-:"), 2))
      break; /* Stop parsing on first non-runtime option */

    ptr = &C_main_argv[ i ][ 2 ];
    if (*ptr == '\0')
      break; /* Also stop parsing on first "empty" option (i.e. "-:") */

    do {
      switch(*(ptr++)) {
      case '?':
        C_dbg("Runtime options", "\n\n"
              " -:?              display this text\n"
              " -:c              always treat stdin as console\n"
              " -:d              enable debug output\n"
              " -:D              enable more debug output\n"
              " -:g              show GC information\n"
              " -:o              disable stack overflow checks\n"
              " -:hiSIZE         set initial heap size\n"
              " -:hmSIZE         set maximal heap size\n"
              " -:hfSIZE         set minimum unused heap size\n"
              " -:hgPERCENTAGE   set heap growth percentage\n"
              " -:hsPERCENTAGE   set heap shrink percentage\n"
              " -:huPERCENTAGE   set percentage of memory used at which heap will be shrunk\n"
              " -:hSIZE          set fixed heap size\n"
              " -:r              write trace output to stderr\n"
              " -:RSEED          initialize rand() seed with SEED (helpful for benchmark stability)\n"
              " -:p              collect statistical profile and write to file at exit\n"
              " -:PFREQUENCY     like -:p, specifying sampling frequency in us (default: 10000)\n"
              " -:sSIZE          set nursery (stack) size\n"
              " -:tSIZE          set symbol-table size\n"
              " -:fSIZE          set maximal number of pending finalizers\n"
              " -:x              deliver uncaught exceptions of other threads to primordial one\n"
              " -:B              sound bell on major GC\n"
              " -:G              force GUI mode\n"
              " -:aSIZE          set trace-buffer/call-chain size\n"
              " -:ASIZE          set fixed temporary stack size\n"
              " -:H              dump heap state on exit\n"
              " -:S              do not handle segfaults or other serious conditions\n"
              "\n  SIZE may have a `k' (`K'), `m' (`M') or `g' (`G') suffix, meaning size\n"
              "  times 1024, 1048576, and 1073741824, respectively.\n\n");
        C_exit_runtime(C_fix(0));

      case 'h':
        switch(*ptr) {
        case 'i':
          *heap = arg_val(ptr + 1); 
          heap_size_changed = 1;
          goto next;
        case 'f':
          C_heap_half_min_free = arg_val(ptr + 1);
          goto next;
        case 'g':
          C_heap_growth = arg_val(ptr + 1);
          goto next;
        case 'm':
          C_maximal_heap_size = arg_val(ptr + 1);
          goto next;
        case 's':
          C_heap_shrinkage = arg_val(ptr + 1);
          goto next;
        case 'u':
          C_heap_shrinkage_used = arg_val(ptr + 1);
          goto next;
        default:
          *heap = arg_val(ptr); 
          heap_size_changed = 1;
          C_heap_size_is_fixed = 1;
          goto next;
        }

      case 'o':
        C_disable_overflow_check = 1;
        break;

      case 'B':
        gc_bell = 1;
        break;

      case 'G':
        C_gui_mode = 1;
        break;

      case 'H':
        dump_heap_on_exit = 1;
        break;

      case 'S':
        pass_serious_signals = 1;
        break;

      case 's':
        *stack = arg_val(ptr);
        stack_size_changed = 1;
        goto next;

      case 'f':
        C_max_pending_finalizers = arg_val(ptr);
        goto next;

      case 'a':
        C_trace_buffer_size = arg_val(ptr);
        goto next;

      case 'A':
        fixed_temporary_stack_size = arg_val(ptr);
        goto next;

      case 't':
        *symbols = arg_val(ptr);
        goto next;

      case 'c':
        fake_tty_flag = 1;
        break;

      case 'd':
        debug_mode = 1;
        break;

      case 'D':
        debug_mode = 2;
        break;

      case 'g':
        gc_report_flag = 2;
        break;

      case 'P':
        profiling = 1;
        profile_frequency = arg_val(ptr);
        goto next;

      case 'p':
        profiling = 1;
        break;

      case 'r':
        show_trace = 1;
        break;

      case 'R':
        srand((unsigned int)arg_val(ptr));
        random_state_initialized = 1;
        goto next;

      case 'x':
        C_abort_on_thread_exceptions = 1;
        break;

      default: panic(C_text("illegal runtime option"));
      }
    } while(*ptr != '\0');

    next:;
    }
}


C_word arg_val(C_char *arg)
{
  int len;
  C_char *end;
  C_long val, mul = 1;

  if (arg == NULL) panic(C_text("illegal runtime-option argument"));
      
  len = C_strlen(arg);
      
  if(len < 1) panic(C_text("illegal runtime-option argument"));
      
  switch(arg[ len - 1 ]) {
  case 'k':
  case 'K': mul = 1024; break;
 	  
  case 'm':
  case 'M': mul = 1024 * 1024; break;
 	  
  case 'g':
  case 'G': mul = 1024 * 1024 * 1024; break;

  default: mul = 1;
  }

  val = C_strtow(arg, &end, 10);

  if((mul != 1 ? end[ 1 ] != '\0' : end[ 0 ] != '\0')) 
    panic(C_text("invalid runtime-option argument suffix"));

  return val * mul;
}


/* Run embedded code with arguments: */

C_word CHICKEN_run(void *toplevel)
{
  if(!chicken_is_initialized && !CHICKEN_initialize(0, 0, 0, toplevel))
    panic(C_text("could not initialize"));

  if(chicken_is_running)
    panic(C_text("re-invocation of Scheme world while process is already running"));

  chicken_is_running = chicken_ran_once = 1;
  return_to_host = 0;

  if(profiling) set_profile_timer(profile_frequency);

#if C_STACK_GROWS_DOWNWARD
  C_stack_hard_limit = (C_word *)((C_byte *)C_stack_pointer - stack_size);
#else
  C_stack_hard_limit = (C_word *)((C_byte *)C_stack_pointer + stack_size);
#endif
  C_stack_limit = C_stack_hard_limit;

  stack_bottom = C_stack_pointer;

  if(debug_mode)
    C_dbg(C_text("debug"), C_text("stack bottom is 0x%lx\n"), (C_word)stack_bottom);

  /* The point of (usually) no return... */
#ifdef HAVE_SIGSETJMP
  C_sigsetjmp(C_restart, 0);
#else
  C_setjmp(C_restart);
#endif

  serious_signal_occurred = 0;

  if(!return_to_host) {
    /* We must copy the argvector onto the stack, because
     * any subsequent save() will otherwise clobber it.
     */
    C_word *p = C_alloc(C_restart_c);
    assert(C_restart_c == (C_temporary_stack_bottom - C_temporary_stack));
    C_memcpy(p, C_temporary_stack, C_restart_c * sizeof(C_word));
    C_temporary_stack = C_temporary_stack_bottom;
    ((C_proc)C_restart_trampoline)(C_restart_c, p);
  }

  if(profiling) set_profile_timer(0);

  chicken_is_running = 0;
  return C_restore;
}


C_word CHICKEN_continue(C_word k)
{
  if(C_temporary_stack_bottom != C_temporary_stack)
    panic(C_text("invalid temporary stack level"));

  if(!chicken_is_initialized)
    panic(C_text("runtime system has not been initialized - `CHICKEN_run' has probably not been called"));

  C_save(k);
  return CHICKEN_run(NULL);
}


/* The final continuation: */

void C_ccall termination_continuation(C_word c, C_word *av)
{
  if(debug_mode) {
    C_dbg(C_text("debug"), C_text("application terminated normally\n"));
  }

  C_exit_runtime(C_fix(0));
}


/* Signal unrecoverable runtime error: */

void panic(C_char *msg)
{
  if(C_panic_hook != NULL) C_panic_hook(msg);

  usual_panic(msg);
}


void usual_panic(C_char *msg)
{
  C_char *dmp = C_dump_trace(0);

  C_dbg_hook(C_SCHEME_UNDEFINED);

  if(C_gui_mode) {
    C_snprintf(buffer, sizeof(buffer), C_text("%s\n\n%s"), msg, dmp);
#if defined(_WIN32) && !defined(__CYGWIN__)
    MessageBox(NULL, buffer, C_text("CHICKEN runtime"), MB_OK | MB_ICONERROR);
    ExitProcess(1);
#endif
  } /* fall through if not WIN32 GUI app */

  C_dbg("panic", C_text("%s - execution terminated\n\n%s"), msg, dmp);
  C_exit_runtime(C_fix(1));
}


void horror(C_char *msg)
{
  C_dbg_hook(C_SCHEME_UNDEFINED);

  if(C_gui_mode) {
    C_snprintf(buffer, sizeof(buffer), C_text("%s"), msg);
#if defined(_WIN32) && !defined(__CYGWIN__)
    MessageBox(NULL, buffer, C_text("CHICKEN runtime"), MB_OK | MB_ICONERROR);
    ExitProcess(1);
#endif
  } /* fall through */

  C_dbg("horror", C_text("\n%s - execution terminated"), msg);  
  C_exit_runtime(C_fix(1));
}


/* Error-hook, called from C-level runtime routines: */

void barf(int code, char *loc, ...)
{
  C_char *msg;
  C_word err = error_hook_symbol;
  int c, i;
  va_list v;
  C_word *av; 

  C_dbg_hook(C_SCHEME_UNDEFINED);

  C_temporary_stack = C_temporary_stack_bottom;
  err = C_block_item(err, 0);

  switch(code) {
  case C_BAD_ARGUMENT_COUNT_ERROR:
    msg = C_text("bad argument count");
    c = 3;
    break;

  case C_BAD_MINIMUM_ARGUMENT_COUNT_ERROR:
    msg = C_text("too few arguments");
    c = 3;
    break;
  
  case C_BAD_ARGUMENT_TYPE_ERROR:
    msg = C_text("bad argument type");
    c = 1;
    break;

  case C_UNBOUND_VARIABLE_ERROR:
    msg = C_text("unbound variable");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_KEYWORD_ERROR:
    msg = C_text("bad argument type - not a keyword");
    c = 1;
    break;

  case C_OUT_OF_MEMORY_ERROR:
    msg = C_text("not enough memory");
    c = 0;
    break;

  case C_DIVISION_BY_ZERO_ERROR:
    msg = C_text("division by zero");
    c = 0;
    break;

  case C_OUT_OF_RANGE_ERROR:
    msg = C_text("out of range");
    c = 2;
    break;

  case C_NOT_A_CLOSURE_ERROR:
    msg = C_text("call of non-procedure");
    c = 1;
    break;

  case C_CONTINUATION_CANT_RECEIVE_VALUES_ERROR:
    msg = C_text("continuation cannot receive multiple values");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_CYCLIC_LIST_ERROR:
    msg = C_text("bad argument type - not a non-cyclic list");
    c = 1;
    break;

  case C_TOO_DEEP_RECURSION_ERROR:
    msg = C_text("recursion too deep");
    c = 0;
    break;

  case C_CANT_REPRESENT_INEXACT_ERROR:
    msg = C_text("inexact number cannot be represented as an exact number");
    c = 1;
    break;

  case C_NOT_A_PROPER_LIST_ERROR:
    msg = C_text("bad argument type - not a proper list");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_FIXNUM_ERROR:
    msg = C_text("bad argument type - not a fixnum");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_STRING_ERROR:
    msg = C_text("bad argument type - not a string");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_PAIR_ERROR:
    msg = C_text("bad argument type - not a pair");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_BOOLEAN_ERROR:
    msg = C_text("bad argument type - not a boolean");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_LOCATIVE_ERROR:
    msg = C_text("bad argument type - not a locative");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_LIST_ERROR:
    msg = C_text("bad argument type - not a list");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR:
    msg = C_text("bad argument type - not a number");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_SYMBOL_ERROR:
    msg = C_text("bad argument type - not a symbol");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_VECTOR_ERROR:
    msg = C_text("bad argument type - not a vector");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_CHAR_ERROR:
    msg = C_text("bad argument type - not a character");
    c = 1;
    break;

  case C_STACK_OVERFLOW_ERROR:
    msg = C_text("stack overflow");
    c = 0;
    break;

  case C_BAD_ARGUMENT_TYPE_BAD_STRUCT_ERROR:
    msg = C_text("bad argument type - not a structure of the required type");
    c = 2;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_BYTEVECTOR_ERROR:
    msg = C_text("bad argument type - not a blob");
    c = 1;
    break;

  case C_LOST_LOCATIVE_ERROR:
    msg = C_text("locative refers to reclaimed object");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_BLOCK_ERROR:
    msg = C_text("bad argument type - not a object");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_NUMBER_VECTOR_ERROR:
    msg = C_text("bad argument type - not a number vector");
    c = 2;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR:
    msg = C_text("bad argument type - not an integer");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR:
    msg = C_text("bad argument type - not an unsigned integer");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR:
    msg = C_text("bad argument type - not a pointer");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_TAGGED_POINTER_ERROR:
    msg = C_text("bad argument type - not a tagged pointer");
    c = 2;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR:
    msg = C_text("bad argument type - not a flonum");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_CLOSURE_ERROR:
    msg = C_text("bad argument type - not a procedure");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR:
    msg = C_text("bad argument type - invalid base");
    c = 1;
    break;

  case C_CIRCULAR_DATA_ERROR:
    msg = C_text("recursion too deep or circular data encountered");
    c = 0;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_PORT_ERROR:
    msg = C_text("bad argument type - not a port");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_PORT_DIRECTION_ERROR:
    msg = C_text("bad argument type - not a port of the correct type");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_PORT_NO_INPUT_ERROR:
    msg = C_text("bad argument type - not an input-port");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_PORT_NO_OUTPUT_ERROR:
    msg = C_text("bad argument type - not an output-port");
    c = 1;
    break;

  case C_PORT_CLOSED_ERROR:
    msg = C_text("port already closed");
    c = 1;
    break;
 
  case C_ASCIIZ_REPRESENTATION_ERROR:
    msg = C_text("cannot represent string with NUL bytes as C string");
    c = 1;
    break;

  case C_MEMORY_VIOLATION_ERROR:
    msg = C_text("segmentation violation");
    c = 0;
    break;

  case C_FLOATING_POINT_EXCEPTION_ERROR:
    msg = C_text("floating point exception");
    c = 0;
    break;

  case C_ILLEGAL_INSTRUCTION_ERROR:
    msg = C_text("illegal instruction");
    c = 0;
    break;

  case C_BUS_ERROR:
    msg = C_text("bus error");
    c = 0;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_EXACT_ERROR:
    msg = C_text("bad argument type - not an exact number");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_INEXACT_ERROR:
    msg = C_text("bad argument type - not an inexact number");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_REAL_ERROR:
    msg = C_text("bad argument type - not an real");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR:
    msg = C_text("bad argument type - complex number has no ordering");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR:
    msg = C_text("bad argument type - not an exact integer");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_FOREIGN_LIMITATION:
    msg = C_text("number does not fit in foreign type");
    c = 1;
    break;

  case C_BAD_ARGUMENT_TYPE_COMPLEX_ABS:
    msg = C_text("cannot compute absolute value of complex number");
    c = 1;
    break;

  case C_REST_ARG_OUT_OF_BOUNDS_ERROR:
    msg = C_text("attempted rest argument access beyond end of list");
    c = 3;
    break;

  default: panic(C_text("illegal internal error code"));
  }

  if(C_immediatep(err)) {
    C_dbg(C_text("error"), C_text("%s\n"), msg);
    panic(C_text("`##sys#error-hook' is not defined - the `library' unit was probably not linked with this executable"));
  } else {
    av = C_alloc(c + 4);
    va_start(v, loc);
    av[ 0 ] = err;
    /* No continuation is passed: '##sys#error-hook' may not return: */
    av[ 1 ] = C_SCHEME_UNDEFINED;
    av[ 2 ] = C_fix(code);
    
    if(loc != NULL)
      av[ 3 ] = intern0(loc);
    else {
      av[ 3 ] = error_location;
      error_location = C_SCHEME_FALSE;
    }

    for(i = 0; i < c; ++i)
      av[ i + 4 ] = va_arg(v, C_word);

    va_end(v);
    C_do_apply(c + 4, av);
  }
}


/* Never use extended number hook procedure names longer than this! */
/* Current longest name: ##sys#integer->string/recursive */
#define MAX_EXTNUM_HOOK_NAME 32

/* This exists so that we don't have to create any extra closures */
static void try_extended_number(char *ext_proc_name, C_word c, C_word k, ...)
{
  static C_word ab[C_SIZEOF_STRING(MAX_EXTNUM_HOOK_NAME)];
  int i;
  va_list v;
  C_word ext_proc_sym, ext_proc = C_SCHEME_FALSE, *a = ab;

  ext_proc_sym = C_lookup_symbol(C_intern2(&a, ext_proc_name));

  if(!C_immediatep(ext_proc_sym))
    ext_proc = C_block_item(ext_proc_sym, 0);

  if (!C_immediatep(ext_proc) && C_closurep(ext_proc)) {
    C_word *av = C_alloc(c + 1);
    av[ 0 ] = ext_proc;
    av[ 1 ] = k;
    va_start(v, k);

    for(i = 0; i < c - 1; ++i)
      av[ i + 2 ] = va_arg(v, C_word);

    va_end(v);
    C_do_apply(c + 1, av);
  } else {
    barf(C_UNBOUND_VARIABLE_ERROR, NULL, ext_proc_sym);
  }
}


/* Hook for setting breakpoints */

C_word C_dbg_hook(C_word dummy)
{
  return dummy;
}


/* Timing routines: */

/* DEPRECATED */
C_regparm C_u64 C_fcall C_milliseconds(void)
{
  return C_current_process_milliseconds();
}

C_regparm C_u64 C_fcall C_current_process_milliseconds(void)
{
#if defined(__MINGW32__)
# if defined(__MINGW64_VERSION_MAJOR)
    ULONGLONG tick_count = GetTickCount64();
# else
    ULONGLONG tick_count = GetTickCount();
# endif
    return tick_count - (C_startup_time_sec * 1000) - C_startup_time_msec;
#else
    struct timeval tv;

    if(C_gettimeofday(&tv, NULL) == -1) return 0;
    else return (tv.tv_sec - C_startup_time_sec) * 1000 + tv.tv_usec / 1000 - C_startup_time_msec;
#endif
}


C_regparm time_t C_fcall C_seconds(C_long *ms)
{
#ifdef C_NONUNIX
  if(ms != NULL) *ms = 0;

  return (time_t)(clock() / CLOCKS_PER_SEC);
#else
  struct timeval tv;

  if(C_gettimeofday(&tv, NULL) == -1) {
    if(ms != NULL) *ms = 0;

    return (time_t)0;
  }
  else {
    if(ms != NULL) *ms = tv.tv_usec / 1000;

    return tv.tv_sec;
  }
#endif
}


C_regparm C_u64 C_fcall C_cpu_milliseconds(void)
{
#if defined(C_NONUNIX) || defined(__CYGWIN__)
    if(CLOCKS_PER_SEC == 1000) return clock();
    else return ((C_u64)clock() / CLOCKS_PER_SEC) * 1000;
#else
    struct rusage ru;

    if(C_getrusage(RUSAGE_SELF, &ru) == -1) return 0;
    else return (((C_u64)ru.ru_utime.tv_sec + ru.ru_stime.tv_sec) * 1000
                 + ((C_u64)ru.ru_utime.tv_usec + ru.ru_stime.tv_usec) / 1000);
#endif
}


/* Support code for callbacks: */

int C_fcall C_save_callback_continuation(C_word **ptr, C_word k)
{
  C_word p = C_a_pair(ptr, k, C_block_item(callback_continuation_stack_symbol, 0));
  
  C_mutate_slot(&C_block_item(callback_continuation_stack_symbol, 0), p);
  return ++callback_continuation_level;
}


C_word C_fcall C_restore_callback_continuation(void) 
{
  /* obsolete, but retained for keeping old code working */
  C_word p = C_block_item(callback_continuation_stack_symbol, 0),
         k;

  assert(!C_immediatep(p) && C_header_type(p) == C_PAIR_TYPE);
  k = C_u_i_car(p);

  C_mutate(&C_block_item(callback_continuation_stack_symbol, 0), C_u_i_cdr(p));
  --callback_continuation_level;
  return k;
}


C_word C_fcall C_restore_callback_continuation2(int level) 
{
  C_word p = C_block_item(callback_continuation_stack_symbol, 0),
         k;

  if(level != callback_continuation_level || C_immediatep(p) || C_header_type(p) != C_PAIR_TYPE)
    panic(C_text("unbalanced callback continuation stack"));

  k = C_u_i_car(p);

  C_mutate(&C_block_item(callback_continuation_stack_symbol, 0), C_u_i_cdr(p));
  --callback_continuation_level;
  return k;
}


C_word C_fcall C_callback(C_word closure, int argc)
{
#ifdef HAVE_SIGSETJMP
  sigjmp_buf prev;
#else
  jmp_buf prev;
#endif
  C_word 
    *a = C_alloc(C_SIZEOF_CLOSURE(2)),
    k = C_closure(&a, 2, (C_word)callback_return_continuation, C_SCHEME_FALSE),
    *av;
  int old = chicken_is_running;

  if(old && C_block_item(callback_continuation_stack_symbol, 0) == C_SCHEME_END_OF_LIST)
    panic(C_text("callback invoked in non-safe context"));

  C_memcpy(&prev, &C_restart, sizeof(C_restart));
  callback_returned_flag = 0;       
  chicken_is_running = 1;
  av = C_alloc(argc + 2);
  av[ 0 ] = closure;
  av[ 1 ] = k;
  /*XXX is the order of arguments an issue? */
  C_memcpy(av + 2, C_temporary_stack, argc * sizeof(C_word));
  C_temporary_stack = C_temporary_stack_bottom;
  
#ifdef HAVE_SIGSETJMP
  if(!C_sigsetjmp(C_restart, 0)) C_do_apply(argc + 2, av);
#else
  if(!C_setjmp(C_restart)) C_do_apply(argc + 2, av);
#endif

  serious_signal_occurred = 0;

  if(!callback_returned_flag) {
    /* We must copy the argvector onto the stack, because
     * any subsequent save() will otherwise clobber it.
     */
    C_word *p = C_alloc(C_restart_c);
    assert(C_restart_c == (C_temporary_stack_bottom - C_temporary_stack));
    C_memcpy(p, C_temporary_stack, C_restart_c * sizeof(C_word));
    C_temporary_stack = C_temporary_stack_bottom;
    ((C_proc)C_restart_trampoline)(C_restart_c, p);
  }
  else {
    C_memcpy(&C_restart, &prev, sizeof(C_restart));
    callback_returned_flag = 0;
  }
 
  chicken_is_running = old;
  return C_restore;
}


void C_fcall C_callback_adjust_stack(C_word *a, int size)
{
  if(!chicken_is_running && !C_in_stackp((C_word)a)) {
    if(debug_mode)
      C_dbg(C_text("debug"), 
	    C_text("callback invoked in lower stack region - adjusting limits:\n"
		   "[debug]   current:  \t%p\n"
		   "[debug]   previous: \t%p (bottom) - %p (limit)\n"),
	    a, stack_bottom, C_stack_limit);

#if C_STACK_GROWS_DOWNWARD
    C_stack_hard_limit = (C_word *)((C_byte *)a - stack_size);
    stack_bottom = a + size;
#else
    C_stack_hard_limit = (C_word *)((C_byte *)a + stack_size);
    stack_bottom = a;
#endif
    C_stack_limit = C_stack_hard_limit;

    if(debug_mode)
      C_dbg(C_text("debug"), C_text("new:      \t%p (bottom) - %p (limit)\n"),
	    stack_bottom, C_stack_limit);
  }
}


C_word C_fcall C_callback_wrapper(void *proc, int argc)
{
  C_word
    *a = C_alloc(C_SIZEOF_CLOSURE(1)),
    closure = C_closure(&a, 1, (C_word)proc),
    result;

  result = C_callback(closure, argc);
  assert(C_temporary_stack == C_temporary_stack_bottom);
  return result;
}


void C_ccall callback_return_continuation(C_word c, C_word *av)
{
  C_word self = av[0];
  C_word r = av[1];

  if(C_block_item(self, 1) == C_SCHEME_TRUE)
    panic(C_text("callback returned twice"));

  assert(callback_returned_flag == 0);
  callback_returned_flag = 1;
  C_set_block_item(self, 1, C_SCHEME_TRUE);
  C_save(r);
  C_reclaim(NULL, 0);
}


/* Register/unregister literal frame: */

void C_initialize_lf(C_word *lf, int count)
{
  while(count-- > 0)
    *(lf++) = C_SCHEME_UNBOUND;
}


void *C_register_lf(C_word *lf, int count)
{
  return C_register_lf2(lf, count, NULL);
}


void *C_register_lf2(C_word *lf, int count, C_PTABLE_ENTRY *ptable)
{
  LF_LIST *node = (LF_LIST *)C_malloc(sizeof(LF_LIST));
  LF_LIST *np;
  int status = 0;

  node->lf = lf;
  node->count = count;
  node->ptable = ptable;
  node->module_name = current_module_name;
  node->module_handle = current_module_handle;
  current_module_handle = NULL;

  if(lf_list) lf_list->prev = node;

  node->next = lf_list;
  node->prev = NULL;
  lf_list = node;
  return (void *)node;
}


LF_LIST *find_module_handle(char *name)
{
  LF_LIST *np;

  for(np = lf_list; np != NULL; np = np->next) {
    if(np->module_name != NULL && !C_strcmp(np->module_name, name)) 
      return np;
  }

  return NULL;
}


void C_unregister_lf(void *handle)
{
  LF_LIST *node = (LF_LIST *) handle;

  if (node->next) node->next->prev = node->prev;

  if (node->prev) node->prev->next = node->next;

  if (lf_list == node) lf_list = node->next;

  C_free(node->module_name);
  C_free(node);
}


/* Intern symbol into symbol-table: */

C_regparm C_word C_fcall C_intern(C_word **ptr, int len, C_char *str) 
{
  return C_intern_in(ptr, len, str, symbol_table);
}


C_regparm C_word C_fcall C_h_intern(C_word *slot, int len, C_char *str)
{
  return C_h_intern_in(slot, len, str, symbol_table);
}


C_regparm C_word C_fcall C_intern_kw(C_word **ptr, int len, C_char *str) 
{
  C_word kw = C_intern_in(ptr, len, str, keyword_table);
  C_set_block_item(kw, 0, kw); /* Keywords evaluate to themselves */
  C_set_block_item(kw, 2, C_SCHEME_FALSE); /* Keywords have no plists */
  return kw;
}


C_regparm C_word C_fcall C_h_intern_kw(C_word *slot, int len, C_char *str)
{
  C_word kw = C_h_intern_in(slot, len, str, keyword_table);
  C_set_block_item(kw, 0, kw); /* Keywords evaluate to themselves */
  C_set_block_item(kw, 2, C_SCHEME_FALSE); /* Keywords have no plists */
  return kw;
}

C_regparm C_word C_fcall C_intern_in(C_word **ptr, int len, C_char *str, C_SYMBOL_TABLE *stable)
{
  int key;
  C_word s;

  if(stable == NULL) stable = symbol_table;

  key = hash_string(len, str, stable->size, stable->rand, 0);

  if(C_truep(s = lookup(key, len, str, stable))) return s;

  s = C_string(ptr, len, str);
  return add_symbol(ptr, key, s, stable);
}


C_regparm C_word C_fcall C_h_intern_in(C_word *slot, int len, C_char *str, C_SYMBOL_TABLE *stable)
{
  /* Intern as usual, but remember slot, and allocate in static
   * memory.  If symbol already exists, replace its string by a fresh
   * statically allocated string to ensure it never gets collected, as
   * lf[] entries are not tracked by the GC.
   */
  int key;
  C_word s;

  if(stable == NULL) stable = symbol_table;

  key = hash_string(len, str, stable->size, stable->rand, 0);

  if(C_truep(s = lookup(key, len, str, stable))) {
    if(C_in_stackp(s)) C_mutate_slot(slot, s);
    
    if(!C_truep(C_permanentp(C_symbol_name(s)))) {
      /* Replace by statically allocated string, and persist it */
      C_set_block_item(s, 1, C_static_string(C_heaptop, len, str));
      C_i_persist_symbol(s);
    }
    return s;
  }

  s = C_static_string(C_heaptop, len, str);
  return add_symbol(C_heaptop, key, s, stable);
}


C_regparm C_word C_fcall intern0(C_char *str)
{
  int len = C_strlen(str);
  int key = hash_string(len, str, symbol_table->size, symbol_table->rand, 0);
  C_word s;

  if(C_truep(s = lookup(key, len, str, symbol_table))) return s;
  else return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_lookup_symbol(C_word sym)
{
  int key;
  C_word str = C_block_item(sym, 1);
  int len = C_header_size(str);

  key = hash_string(len, C_c_string(str), symbol_table->size, symbol_table->rand, 0);

  return lookup(key, len, C_c_string(str), symbol_table);
}


C_regparm C_word C_fcall C_intern2(C_word **ptr, C_char *str)
{
  return C_intern_in(ptr, C_strlen(str), str, symbol_table);
}


C_regparm C_word C_fcall C_intern3(C_word **ptr, C_char *str, C_word value)
{
  C_word s = C_intern_in(ptr, C_strlen(str), str, symbol_table);
  
  C_mutate(&C_block_item(s,0), value);
  C_i_persist_symbol(s); /* Symbol has a value now; persist it */
  return s;
}


C_regparm C_word C_fcall hash_string(int len, C_char *str, C_word m, C_word r, int ci)
{
  C_uword key = r;

  if (ci)
    while(len--) key ^= (key << 6) + (key >> 2) + C_tolower((int)(*str++));
  else
    while(len--) key ^= (key << 6) + (key >> 2) + *(str++);

  return (C_word)(key % (C_uword)m);
}


C_regparm C_word C_fcall lookup(C_word key, int len, C_char *str, C_SYMBOL_TABLE *stable)
{
  C_word bucket, last = 0, sym, s;

  for(bucket = stable->table[ key ]; bucket != C_SCHEME_END_OF_LIST; 
      bucket = C_block_item(bucket,1)) {
    sym = C_block_item(bucket,0);

    /* If the symbol is unreferenced, drop it: */
    if (sym == C_SCHEME_BROKEN_WEAK_PTR) {
       if (last) C_set_block_item(last, 1, C_block_item(bucket, 1));
       else stable->table[ key ] = C_block_item(bucket,1);
    } else {
      last = bucket;
      s = C_block_item(sym, 1);

      if(C_header_size(s) == (C_word)len
         && !C_memcmp(str, (C_char *)C_data_pointer(s), len))
        return sym;
    }
  }

  return C_SCHEME_FALSE;
}

/* Mark a symbol as "persistent", to prevent it from being GC'ed */
C_regparm C_word C_fcall C_i_persist_symbol(C_word sym)
{
  C_word bucket;
  C_SYMBOL_TABLE *stp;

  /* Normally, this will get called with a symbol, but in
   * C_h_intern_kw we may call it with keywords too.
   */
  if(!C_truep(C_i_symbolp(sym)) && !C_truep(C_i_keywordp(sym))) {
    error_location = C_SCHEME_FALSE;
    barf(C_BAD_ARGUMENT_TYPE_NO_SYMBOL_ERROR, NULL, sym);
  }

  for(stp = symbol_table_list; stp != NULL; stp = stp->next) {
    bucket = lookup_bucket(sym, stp);

    if (C_truep(bucket)) {
      /* Change weak to strong ref to ensure long-term survival */
      C_block_header(bucket) = C_block_header(bucket) & ~C_SPECIALBLOCK_BIT;
      /* Ensure survival on next minor GC */
      if (C_in_stackp(sym)) C_mutate_slot(&C_block_item(bucket, 0), sym);
    }
  }
  return C_SCHEME_UNDEFINED;
}

/* Possibly remove "persistence" of symbol, to allowed it to be GC'ed.
 * This is only done if the symbol is unbound, has an empty plist and
 * is allocated in managed memory.
 */
C_regparm C_word C_fcall C_i_unpersist_symbol(C_word sym)
{
  C_word bucket;
  C_SYMBOL_TABLE *stp;

  C_i_check_symbol(sym);

  if (C_persistable_symbol(sym) ||
      C_truep(C_permanentp(C_symbol_name(sym)))) {
    return C_SCHEME_FALSE;
  }

  for(stp = symbol_table_list; stp != NULL; stp = stp->next) {
    bucket = lookup_bucket(sym, NULL);

    if (C_truep(bucket)) {
      /* Turn it into a weak ref */
      C_block_header(bucket) = C_block_header(bucket) | C_SPECIALBLOCK_BIT;
      return C_SCHEME_TRUE;
    }
  }
  return C_SCHEME_FALSE;
}

C_regparm C_word C_fcall lookup_bucket(C_word sym, C_SYMBOL_TABLE *stable)
{
  C_word bucket, str = C_block_item(sym, 1);
  int key, len = C_header_size(str);

  if (stable == NULL) stable = symbol_table;

  key = hash_string(len, C_c_string(str), stable->size, stable->rand, 0);

  for(bucket = stable->table[ key ]; bucket != C_SCHEME_END_OF_LIST;
      bucket = C_block_item(bucket,1)) {
    if (C_block_item(bucket,0) == sym) return bucket;
  }
  return C_SCHEME_FALSE;
}


double compute_symbol_table_load(double *avg_bucket_len, int *total_n)
{
  C_word bucket, last;
  int i, j, alen = 0, bcount = 0, total = 0;

  for(i = 0; i < symbol_table->size; ++i) {
    last = 0;
    j = 0;
    for(bucket = symbol_table->table[ i ]; bucket != C_SCHEME_END_OF_LIST; 
        bucket = C_block_item(bucket,1)) {
      /* If the symbol is unreferenced, drop it: */
      if (C_block_item(bucket,0) == C_SCHEME_BROKEN_WEAK_PTR) {
         if (last) C_set_block_item(last, 1, C_block_item(bucket, 1));
         else symbol_table->table[ i ] = C_block_item(bucket,1);
      } else {
        last = bucket;
        ++j;
      }
    }

    if(j > 0) {
      alen += j;
      ++bcount;
    }

    total += j;
  }

  if(avg_bucket_len != NULL)
    *avg_bucket_len = (double)alen / (double)bcount;

  *total_n = total;

  /* return load: */
  return (double)total / (double)symbol_table->size;
}


C_word add_symbol(C_word **ptr, C_word key, C_word string, C_SYMBOL_TABLE *stable)
{
  C_word bucket, sym, b2, *p;

  p = *ptr;
  sym = (C_word)p;
  p += C_SIZEOF_SYMBOL;
  C_block_header_init(sym, C_SYMBOL_TYPE | (C_SIZEOF_SYMBOL - 1));
  C_set_block_item(sym, 0, C_SCHEME_UNBOUND);
  C_set_block_item(sym, 1, string);
  C_set_block_item(sym, 2, C_SCHEME_END_OF_LIST);
  *ptr = p;
  b2 = stable->table[ key ];	/* previous bucket */

  /* Create new weak or strong bucket depending on persistability */
  if (C_truep(C_permanentp(string))) {
    bucket = C_a_pair(ptr, sym, b2);
  } else {
    bucket = C_a_weak_pair(ptr, sym, b2);
  }

  if(ptr != C_heaptop) C_mutate_slot(&stable->table[ key ], bucket);
  else {
    /* If a stack-allocated bucket was here, and we allocate from 
       heap-top (say, in a toplevel literal frame allocation) then we have
       to inform the memory manager that a 2nd gen. block points to a 
       1st gen. block, hence the mutation: */
    C_mutate(&C_block_item(bucket,1), b2);
    stable->table[ key ] = bucket;
  }

  return sym;
}


C_regparm int C_in_stackp(C_word x)
{
  C_word *ptr = (C_word *)(C_uword)x;

#if C_STACK_GROWS_DOWNWARD
  return ptr >= C_stack_pointer_test && ptr <= stack_bottom;
#else
  return ptr < C_stack_pointer_test && ptr >= stack_bottom;
#endif
}


C_regparm int C_fcall C_in_heapp(C_word x)
{
  C_byte *ptr = (C_byte *)(C_uword)x;
  return (ptr >= fromspace_start && ptr < C_fromspace_limit) ||
         (ptr >= tospace_start && ptr < tospace_limit);
}

/* Only used during major GC (heap realloc) */
static C_regparm int C_fcall C_in_new_heapp(C_word x)
{
  C_byte *ptr = (C_byte *)(C_uword)x;
  return (ptr >= new_tospace_start && ptr < new_tospace_limit);
}

C_regparm int C_fcall C_in_fromspacep(C_word x)
{
  C_byte *ptr = (C_byte *)(C_uword)x;
  return (ptr >= fromspace_start && ptr < C_fromspace_limit);
}

C_regparm int C_fcall C_in_scratchspacep(C_word x)
{
  C_word *ptr = (C_word *)(C_uword)x;
  return (ptr >= C_scratchspace_start && ptr < C_scratchspace_limit);
}

/* Cons the rest-aguments together: */

C_regparm C_word C_fcall C_build_rest(C_word **ptr, C_word c, C_word n, C_word *av)
{
  C_word
    x = C_SCHEME_END_OF_LIST,
    *p = *ptr;
  C_SCHEME_BLOCK *node;

  av += c;

  while(--c >= n) {
    node = (C_SCHEME_BLOCK *)p;
    p += 3;
    node->header = C_PAIR_TYPE | (C_SIZEOF_PAIR - 1);
    node->data[ 0 ] = *(--av);
    node->data[ 1 ] = x;
    x = (C_word)node;
  }

  *ptr = p;
  return x;
}


/* Print error messages and exit: */

void C_bad_memory(void)
{
  panic(C_text("there is not enough stack-space to run this executable"));
}


void C_bad_memory_2(void)
{
  panic(C_text("there is not enough heap-space to run this executable - try using the '-:h...' option"));
}


/* The following two can be thrown out in the next release... */

void C_bad_argc(int c, int n)
{
  C_bad_argc_2(c, n, C_SCHEME_FALSE);
}


void C_bad_min_argc(int c, int n)
{
  C_bad_min_argc_2(c, n, C_SCHEME_FALSE);
}


void C_bad_argc_2(int c, int n, C_word closure)
{
  barf(C_BAD_ARGUMENT_COUNT_ERROR, NULL, C_fix(n - 2), C_fix(c - 2), closure);
}


void C_bad_min_argc_2(int c, int n, C_word closure)
{
  barf(C_BAD_MINIMUM_ARGUMENT_COUNT_ERROR, NULL, C_fix(n - 2), C_fix(c - 2), closure);
}


void C_stack_overflow(C_char *loc)
{
  barf(C_STACK_OVERFLOW_ERROR, loc);
}


void C_unbound_error(C_word sym)
{
  barf(C_UNBOUND_VARIABLE_ERROR, NULL, sym);
}


void C_no_closure_error(C_word x)
{
  barf(C_NOT_A_CLOSURE_ERROR, NULL, x);
}


void C_div_by_zero_error(char *loc)
{
  barf(C_DIVISION_BY_ZERO_ERROR, loc);
}

void C_not_an_integer_error(char *loc, C_word x)
{
  barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, loc, x);
}

void C_not_an_uinteger_error(char *loc, C_word x)
{
  barf(C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR, loc, x);
}

void C_rest_arg_out_of_bounds_error(C_word c, C_word n, C_word ka)
{
  C_rest_arg_out_of_bounds_error_2(c, n, ka, C_SCHEME_FALSE);
}

void C_rest_arg_out_of_bounds_error_2(C_word c, C_word n, C_word ka, C_word closure)
{
  barf(C_REST_ARG_OUT_OF_BOUNDS_ERROR, NULL, C_u_fixnum_difference(c, ka), C_u_fixnum_difference(n, ka), closure);
}

/* Allocate and initialize record: */

C_regparm C_word C_fcall C_string(C_word **ptr, int len, C_char *str)
{
  C_word strblock = (C_word)(*ptr);

  *ptr = (C_word *)((C_word)(*ptr) + sizeof(C_header) + C_align(len));
  C_block_header_init(strblock, C_STRING_TYPE | len);
  C_memcpy(C_data_pointer(strblock), str, len);
  return strblock;
}


C_regparm C_word C_fcall C_static_string(C_word **ptr, int len, C_char *str)
{
  C_word *dptr = (C_word *)C_malloc(sizeof(C_header) + C_align(len));
  C_word strblock;

  if(dptr == NULL)
    panic(C_text("out of memory - cannot allocate static string"));
    
  strblock = (C_word)dptr;
  C_block_header_init(strblock, C_STRING_TYPE | len);
  C_memcpy(C_data_pointer(strblock), str, len);
  return strblock;
}

C_regparm C_word C_fcall C_static_bignum(C_word **ptr, int len, C_char *str)
{
  C_word *dptr, bignum, bigvec, retval, size, negp = 0;

  if (*str == '+' || *str == '-') {
    negp = ((*str++) == '-') ? 1 : 0;
    --len;
  }
  size = C_BIGNUM_BITS_TO_DIGITS((unsigned int)len << 2);

  dptr = (C_word *)C_malloc(C_wordstobytes(C_SIZEOF_INTERNAL_BIGNUM_VECTOR(size)));
  if(dptr == NULL)
    panic(C_text("out of memory - cannot allocate static bignum"));

  bigvec = (C_word)dptr;
  C_block_header_init(bigvec, C_STRING_TYPE | C_wordstobytes(size + 1));
  C_set_block_item(bigvec, 0, negp);
  /* This needs to be allocated at ptr, not dptr, because GC moves type tag */
  bignum = C_a_i_bignum_wrapper(ptr, bigvec);

  retval = str_to_bignum(bignum, str, str + len, 16);
  if (retval & C_FIXNUM_BIT)
    C_free(dptr); /* Might have been simplified */
  return retval;
}

C_regparm C_word C_fcall C_static_lambda_info(C_word **ptr, int len, C_char *str)
{
  int dlen = sizeof(C_header) + C_align(len);
  void *dptr = C_malloc(dlen);
  C_word strblock;

  if(dptr == NULL)
    panic(C_text("out of memory - cannot allocate static lambda info"));

  strblock = (C_word)dptr;
  C_block_header_init(strblock, C_LAMBDA_INFO_TYPE | len);
  C_memcpy(C_data_pointer(strblock), str, len);
  return strblock;
}


C_regparm C_word C_fcall C_bytevector(C_word **ptr, int len, C_char *str)
{
  C_word strblock = C_string(ptr, len, str);

  (void)C_string_to_bytevector(strblock);
  return strblock;
}


C_regparm C_word C_fcall C_static_bytevector(C_word **ptr, int len, C_char *str)
{
  C_word strblock = C_static_string(ptr, len, str);

  C_block_header_init(strblock, C_BYTEVECTOR_TYPE | len);
  return strblock;
}


C_regparm C_word C_fcall C_pbytevector(int len, C_char *str)
{
  C_SCHEME_BLOCK *pbv = C_malloc(len + sizeof(C_header));

  if(pbv == NULL) panic(C_text("out of memory - cannot allocate permanent blob"));

  pbv->header = C_BYTEVECTOR_TYPE | len;
  C_memcpy(pbv->data, str, len);
  return (C_word)pbv;
}


C_regparm C_word C_fcall C_string_aligned8(C_word **ptr, int len, C_char *str)
{
  C_word *p = *ptr,
         *p0;

#ifndef C_SIXTY_FOUR
  /* Align on 8-byte boundary: */
  if(C_aligned8(p)) ++p;
#endif

  p0 = p;
  *ptr = p + 1 + C_bytestowords(len);
  *(p++) = C_STRING_TYPE | C_8ALIGN_BIT | len;
  C_memcpy(p, str, len);
  return (C_word)p0;
}


C_regparm C_word C_fcall C_string2(C_word **ptr, C_char *str)
{
  C_word strblock = (C_word)(*ptr);
  int len;

  if(str == NULL) return C_SCHEME_FALSE;

  len = C_strlen(str);
  *ptr = (C_word *)((C_word)(*ptr) + sizeof(C_header) + C_align(len));
  C_block_header_init(strblock, C_STRING_TYPE | len);
  C_memcpy(C_data_pointer(strblock), str, len);
  return strblock;
}


C_regparm C_word C_fcall C_string2_safe(C_word **ptr, int max, C_char *str)
{
  C_word strblock = (C_word)(*ptr);
  int len;

  if(str == NULL) return C_SCHEME_FALSE;

  len = C_strlen(str);

  if(len >= max) {
    C_snprintf(buffer, sizeof(buffer), C_text("foreign string result exceeded maximum of %d bytes"), max);
    panic(buffer);
  }

  *ptr = (C_word *)((C_word)(*ptr) + sizeof(C_header) + C_align(len));
  C_block_header_init(strblock, C_STRING_TYPE | len);
  C_memcpy(C_data_pointer(strblock), str, len);
  return strblock;
}


C_word C_fcall C_closure(C_word **ptr, int cells, C_word proc, ...)
{
  va_list va;
  C_word *p = *ptr,
         *p0 = p;

  *p = C_CLOSURE_TYPE | cells;
  *(++p) = proc;

  for(va_start(va, proc); --cells; *(++p) = va_arg(va, C_word));

  va_end(va);
  *ptr = p + 1;
  return (C_word)p0;
}


/* obsolete: replaced by C_a_pair in chicken.h */
C_regparm C_word C_fcall C_pair(C_word **ptr, C_word car, C_word cdr)
{
  C_word *p = *ptr,
         *p0 = p;
 
  *(p++) = C_PAIR_TYPE | (C_SIZEOF_PAIR - 1);
  *(p++) = car;
  *(p++) = cdr;
  *ptr = p;
  return (C_word)p0;
}


C_regparm C_word C_fcall C_number(C_word **ptr, double n)
{
  C_word 
    *p = *ptr,
    *p0;
  double m;

  if(n <= (double)C_MOST_POSITIVE_FIXNUM
     && n >= (double)C_MOST_NEGATIVE_FIXNUM && modf(n, &m) == 0.0) {
    return C_fix(n);
  }

#ifndef C_SIXTY_FOUR
#ifndef C_DOUBLE_IS_32_BITS
  /* Align double on 8-byte boundary: */
  if(C_aligned8(p)) ++p;
#endif
#endif

  p0 = p;
  *(p++) = C_FLONUM_TAG;
  *((double *)p) = n;
  *ptr = p + sizeof(double) / sizeof(C_word);
  return (C_word)p0;
}


C_regparm C_word C_fcall C_mpointer(C_word **ptr, void *mp)
{
  C_word 
    *p = *ptr,
    *p0 = p;

  *(p++) = C_POINTER_TYPE | 1;
  *((void **)p) = mp;
  *ptr = p + 1;
  return (C_word)p0;
}


C_regparm C_word C_fcall C_mpointer_or_false(C_word **ptr, void *mp)
{
  C_word 
    *p = *ptr,
    *p0 = p;

  if(mp == NULL) return C_SCHEME_FALSE;

  *(p++) = C_POINTER_TYPE | 1;
  *((void **)p) = mp;
  *ptr = p + 1;
  return (C_word)p0;
}


C_regparm C_word C_fcall C_taggedmpointer(C_word **ptr, C_word tag, void *mp)
{
  C_word 
    *p = *ptr,
    *p0 = p;

  *(p++) = C_TAGGED_POINTER_TAG;
  *((void **)p) = mp;
  *(++p) = tag;
  *ptr = p + 1;
  return (C_word)p0;
}


C_regparm C_word C_fcall C_taggedmpointer_or_false(C_word **ptr, C_word tag, void *mp)
{
  C_word 
    *p = *ptr,
    *p0 = p;

  if(mp == NULL) return C_SCHEME_FALSE;
 
  *(p++) = C_TAGGED_POINTER_TAG;
  *((void **)p) = mp;
  *(++p) = tag;
  *ptr = p + 1;
  return (C_word)p0;
}


C_word C_vector(C_word **ptr, int n, ...)
{
  va_list v;
  C_word 
    *p = *ptr,
    *p0 = p; 

  *(p++) = C_VECTOR_TYPE | n;
  va_start(v, n);

  while(n--)
    *(p++) = va_arg(v, C_word);

  *ptr = p;
  va_end(v);
  return (C_word)p0;
}


C_word C_structure(C_word **ptr, int n, ...)
{
  va_list v;
  C_word *p = *ptr,
         *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | n;
  va_start(v, n);

  while(n--)
    *(p++) = va_arg(v, C_word);

  *ptr = p;
  va_end(v);
  return (C_word)p0;
}


C_regparm C_word C_fcall
C_mutate_slot(C_word *slot, C_word val)
{
  unsigned int mssize, newmssize, bytes;

  ++mutation_count;
  /* Mutation stack exists to track mutations pointing from elsewhere
   * into nursery.  Stuff pointing anywhere else can be skipped, as
   * well as mutations on nursery objects.
   */
  if(!C_in_stackp(val) || C_in_stackp((C_word)slot))
    return *slot = val;

#ifdef C_GC_HOOKS
  if(C_gc_mutation_hook != NULL && C_gc_mutation_hook(slot, val)) return val;
#endif

  if(mutation_stack_top >= mutation_stack_limit) {
    assert(mutation_stack_top == mutation_stack_limit);
    mssize = mutation_stack_top - mutation_stack_bottom;
    newmssize = mssize * 2;
    bytes = newmssize * sizeof(C_word *);

    if(debug_mode) 
      C_dbg(C_text("debug"), C_text("resizing mutation stack from %uk to %uk ...\n"),
	    (mssize * sizeof(C_word *)) / 1024, bytes / 1024);

    mutation_stack_bottom = (C_word **)realloc(mutation_stack_bottom, bytes);

    if(mutation_stack_bottom == NULL)
      panic(C_text("out of memory - cannot re-allocate mutation stack"));

    mutation_stack_limit = mutation_stack_bottom + newmssize;
    mutation_stack_top = mutation_stack_bottom + mssize;
  }

  *(mutation_stack_top++) = slot;
  ++tracked_mutation_count;
  return *slot = val;
}

/* Allocate memory in scratch space, "size" is in words, like C_alloc.
 * The memory in the scratch space is laid out as follows: First,
 * there's a count that indicates how big the object originally was,
 * followed by a pointer to the slot in the object which points to the
 * object in scratch space, finally followed by the object itself.
 * The reason we store the slot pointer is so that we can figure out
 * whether the object is still "live" when reallocating; that's
 * because we don't have a saved continuation from where we can trace
 * the live data.  The reason we store the total length of the object
 * is because we may be mutating in-place the lengths of the stored
 * objects, and we need to know how much to skip over while scanning.
 *
 * If the allocating function returns, it *must* first mark all the
 * values in scratch space as reclaimable.  This is needed because
 * there is no way to distinguish between a stale pointer into scratch
 * space that's still somewhere on the stack in "uninitialized" memory
 * versus a word that's been recycled by the next called function,
 * which now holds a value that happens to have the same bit pattern
 * but represents another thing entirely.
 */
C_regparm C_word C_fcall C_scratch_alloc(C_uword size)
{
  C_word result;
  
  if (C_scratchspace_top + size + 2 >= C_scratchspace_limit) {
    C_word *new_scratch_start, *new_scratch_top, *new_scratch_limit;
    C_uword needed = C_scratch_usage + size + 2,
            new_size = nmax(scratchspace_size << 1, 2UL << C_ilen(needed));

    /* Shrink if the needed size is much smaller, but not below minimum */
    if (needed < (new_size >> 4)) new_size >>= 1;
    new_size = nmax(new_size, DEFAULT_SCRATCH_SPACE_SIZE);
    
    /* TODO: Maybe we should work with two semispaces to reduce mallocs? */
    new_scratch_start = (C_word *)C_malloc(C_wordstobytes(new_size));
    if (new_scratch_start == NULL)
      panic(C_text("out of memory - cannot (re-)allocate scratch space"));
    new_scratch_top = new_scratch_start;
    new_scratch_limit = new_scratch_start + new_size;

    if(debug_mode) {
      C_dbg(C_text("debug"), C_text("resizing scratchspace dynamically from "
				    UWORD_COUNT_FORMAT_STRING "k to "
				    UWORD_COUNT_FORMAT_STRING "k ...\n"),
	    C_wordstobytes(scratchspace_size) / 1024,
            C_wordstobytes(new_size) / 1024);
    }

    if(gc_report_flag) {
      C_dbg(C_text("GC"), C_text("(old) scratchspace: \tstart=" UWORD_FORMAT_STRING 
				 ", \tlimit=" UWORD_FORMAT_STRING "\n"),
            (C_word)C_scratchspace_start, (C_word)C_scratchspace_limit);
      C_dbg(C_text("GC"), C_text("(new) scratchspace:   \tstart=" UWORD_FORMAT_STRING
                                 ", \tlimit=" UWORD_FORMAT_STRING "\n"),
            (C_word)new_scratch_start, (C_word)new_scratch_limit);
    }
    
    /* Move scratch data into new space and mutate slots pointing there.
     * This is basically a much-simplified version of really_mark.
     */
    if (C_scratchspace_start != NULL) {
      C_word val, *sscan, *slot;
      C_uword n, words;
      C_header h;
      C_SCHEME_BLOCK *p, *p2;

      sscan = C_scratchspace_start;

      while (sscan < C_scratchspace_top) {
        words = *sscan;
        slot = (C_word *)*(sscan+1);

        if (*(sscan+2) == ALIGNMENT_HOLE_MARKER) val = (C_word)(sscan+3);
        else val = (C_word)(sscan+2);

        sscan += words + 2;
        
        p = (C_SCHEME_BLOCK *)val;
        h = p->header;
        if (is_fptr(h)) /* TODO: Support scratch->scratch pointers? */
          panic(C_text("Unexpected forwarding pointer in scratch space"));

        p2 = (C_SCHEME_BLOCK *)(new_scratch_top+2);

#ifndef C_SIXTY_FOUR
        if ((h & C_8ALIGN_BIT) && C_aligned8(p2) &&
            (C_word *)p2 < new_scratch_limit) {
          *((C_word *)p2) = ALIGNMENT_HOLE_MARKER;
          p2 = (C_SCHEME_BLOCK *)((C_word *)p2 + 1);
        }
#endif

        /* If orig slot still points here, copy data and update it */
        if (slot != NULL) {
          assert(C_in_stackp((C_word)slot) && *slot == val);
          n = C_header_size(p);
          n = (h & C_BYTEBLOCK_BIT) ? C_bytestowords(n) : n;
          
          *slot = (C_word)p2;
          /* size = header plus block size plus optional alignment hole */
          *new_scratch_top = ((C_word *)p2-(C_word *)new_scratch_top-2) + n + 1;
          *(new_scratch_top+1) = (C_word)slot;
          
          new_scratch_top = (C_word *)p2 + n + 1;
          if(new_scratch_top > new_scratch_limit)
            panic(C_text("out of memory - scratch space full while resizing"));

          p2->header = h;
          p->header = ptr_to_fptr((C_uword)p2);
          C_memcpy(p2->data, p->data, C_wordstobytes(n));
        }
      }
      free(C_scratchspace_start);
    }
    C_scratchspace_start = new_scratch_start;
    C_scratchspace_top = new_scratch_top;
    C_scratchspace_limit = new_scratch_limit;
    /* Scratch space is now tightly packed */
    C_scratch_usage = (new_scratch_top - new_scratch_start);
    scratchspace_size = new_size;
  }
  assert(C_scratchspace_top + size + 2 <= C_scratchspace_limit);

  *C_scratchspace_top = size;
  *(C_scratchspace_top+1) = (C_word)NULL; /* Nothing points here 'til mutated */
  result = (C_word)(C_scratchspace_top+2);
  C_scratchspace_top += size + 2;
  /* This will only be marked as "used" when it's claimed by a pointer */
  /* C_scratch_usage += size + 2; */
  return result;
}

/* Given a root object, scan its slots recursively (the objects
 * themselves should be shallow and non-recursive), and migrate every
 * object stored between the memory boundaries to the supplied
 * pointer.  Scratch data pointed to by objects between the memory
 * boundaries is updated to point to the new memory region.  If the
 * supplied pointer is NULL, the scratch memory is marked reclaimable.
 */
C_regparm C_word C_fcall
C_migrate_buffer_object(C_word **ptr, C_word *start, C_word *end, C_word obj)
{
  C_word size, header, *data, *p = NULL, obj_in_buffer;

  if (C_immediatep(obj)) return obj;

  size = C_header_size(obj);
  header = C_block_header(obj);
  data = C_data_pointer(obj);
  obj_in_buffer = (obj >= (C_word)start && obj < (C_word)end);

  /* Only copy object if we have a target pointer and it's in the buffer */
  if (ptr != NULL && obj_in_buffer) {
    p = *ptr;
    obj = (C_word)p; /* Return the object's new location at the end */
  }

  if (p != NULL) *p++ = header;
  
  if (header & C_BYTEBLOCK_BIT) {
    if (p != NULL) {
      *ptr = (C_word *)((C_byte *)(*ptr) + sizeof(C_header) + C_align(size));
      C_memcpy(p, data, size);
    }
  } else {
    if (p != NULL) *ptr += size + 1;
    
    if(header & C_SPECIALBLOCK_BIT) {
      if (p != NULL) *(p++) = *data;
      size--;
      data++;
    }

    /* TODO: See if we can somehow make this use Cheney's algorithm */
    while(size--) {
      C_word slot = *data;

      if(!C_immediatep(slot)) {
        if (C_in_scratchspacep(slot)) {
          if (obj_in_buffer) { /* Otherwise, don't touch scratch backpointer */
            /* TODO: Support recursing into objects in scratch space? */
            C_word *sp = (C_word *)slot;

            if (*(sp-1) == ALIGNMENT_HOLE_MARKER) --sp;
            if (*(sp-1) != (C_word)NULL && p == NULL)
              C_scratch_usage -= *(sp-2) + 2;
            *(sp-1) = (C_word)p; /* This is why we traverse even if p = NULL */

            *data = C_SCHEME_UNBOUND; /* Ensure old reference is killed dead */
          }
        } else { /* Slot is not a scratchspace object: check sub-objects */
          slot = C_migrate_buffer_object(ptr, start, end, slot);
        }
      }
      if (p != NULL) *(p++) = slot;
      else *data = slot; /* Sub-object may have moved! */
      data++;
    }
  }
  return obj; /* Should be NULL if ptr was NULL */
}

/* Register an object's slot as holding data to scratch space.  Only
 * one slot can point to a scratch space object; the object in scratch
 * space is preceded by a pointer that points to this slot (or NULL).
 */
C_regparm C_word C_fcall C_mutate_scratch_slot(C_word *slot, C_word val)
{
  C_word *ptr = (C_word *)val;
  assert(C_in_scratchspacep(val));
  assert(slot == NULL || C_in_stackp((C_word)slot));
  if (*(ptr-1) == ALIGNMENT_HOLE_MARKER) --ptr;
  if (*(ptr-1) == (C_word)NULL && slot != NULL)
    C_scratch_usage += *(ptr-2) + 2;
  if (*(ptr-1) != (C_word)NULL && slot == NULL)
    C_scratch_usage -= *(ptr-2) + 2;
  *(ptr-1) = (C_word)slot; /* Remember the slot pointing here, for realloc */
  if (slot != NULL) *slot = val;
  return val; 
}

/* Initiate garbage collection: */


void C_save_and_reclaim(void *trampoline, int n, C_word *av)
{
  C_word new_size = nmax((C_word)1 << C_ilen(n), DEFAULT_TEMPORARY_STACK_SIZE);

  assert(av > C_temporary_stack_bottom || av < C_temporary_stack_limit);
  assert(C_temporary_stack == C_temporary_stack_bottom);

  /* Don't *immediately* slam back to default size */
  if (new_size < temporary_stack_size / 4)
    new_size = temporary_stack_size >> 1;

  if (new_size != temporary_stack_size) {

    if(fixed_temporary_stack_size)
      panic(C_text("fixed temporary stack overflow (\"apply\" called with too many arguments?)"));

    if(gc_report_flag) {
      C_dbg(C_text("GC"), C_text("resizing temporary stack dynamically from " UWORD_COUNT_FORMAT_STRING "k to " UWORD_COUNT_FORMAT_STRING "k ...\n"),
            C_wordstobytes(temporary_stack_size) / 1024,
            C_wordstobytes(new_size) / 1024);
    }

    C_free(C_temporary_stack_limit);

    if((C_temporary_stack_limit = (C_word *)C_malloc(new_size * sizeof(C_word))) == NULL)
      panic(C_text("out of memory - could not resize temporary stack"));

    C_temporary_stack_bottom = C_temporary_stack_limit + new_size;
    C_temporary_stack = C_temporary_stack_bottom;
    temporary_stack_size = new_size;
  }

  C_temporary_stack = C_temporary_stack_bottom - n;

  assert(C_temporary_stack >= C_temporary_stack_limit);

  C_memmove(C_temporary_stack, av, n * sizeof(C_word));
  C_reclaim(trampoline, n);
}


void C_save_and_reclaim_args(void *trampoline, int n, ...)
{
  va_list v;
  int i;
  
  va_start(v, n);

  for(i = 0; i < n; ++i)
    C_save(va_arg(v, C_word));

  va_end(v);
  C_reclaim(trampoline, n);
}


#ifdef __SUNPRO_C
static void _mark(C_word *x, C_byte *s, C_byte **t, C_byte *l) {   \
  C_word *_x = (x), _val = *_x;                                   \
  if(!C_immediatep(_val)) really_mark(_x,s,t,l);                  \
}
#else
# define _mark(x,s,t,l)                                  \
  C_cblock						\
  C_word *_x = (x), _val = *_x;				\
  if(!C_immediatep(_val)) really_mark(_x,s,t,l);	\
  C_cblockend
#endif

/* NOTE: This macro is particularly unhygienic! */
#define mark(x) _mark(x, tgt_space_start, tgt_space_top, tgt_space_limit)

C_regparm void C_fcall C_reclaim(void *trampoline, C_word c)
{
  int i, j, fcount;
  C_uword count;
  C_word **msp, last;
  C_byte *tmp, *start;
  C_GC_ROOT *gcrp;
  double tgc = 0;
  volatile int finalizers_checked;
  FINALIZER_NODE *flist;
  C_DEBUG_INFO cell;
  C_byte *tgt_space_start, **tgt_space_top, *tgt_space_limit;
  
  /* assert(C_timer_interrupt_counter >= 0); */

  if(pending_interrupts_count > 0 && C_interrupts_enabled) {
    stack_check_demand = 0; /* forget demand: we're not going to gc yet */
    handle_interrupt(trampoline);
  }

  cell.enabled = 0;
  cell.event = C_DEBUG_GC;
  cell.loc = "<runtime>";
  cell.val = "GC_MINOR";
  C_debugger(&cell, 0, NULL);

  /* Note: the mode argument will always be GC_MINOR or GC_REALLOC. */
  if(C_pre_gc_hook != NULL) C_pre_gc_hook(GC_MINOR);

  finalizers_checked = 0;
  C_restart_trampoline = trampoline;
  C_restart_c = c;
  gc_mode = GC_MINOR;
  tgt_space_start = fromspace_start;
  tgt_space_top = &C_fromspace_top;
  tgt_space_limit = C_fromspace_limit;
  weak_pair_chain = (C_word)NULL;
  locative_chain = (C_word)NULL;

  start = C_fromspace_top;

  /* Entry point for second-level GC (on explicit request or because of full fromspace): */
#ifdef HAVE_SIGSETJMP
  if(C_sigsetjmp(gc_restart, 0) || start >= C_fromspace_limit) {
#else
  if(C_setjmp(gc_restart) || start >= C_fromspace_limit) {
#endif
    if(gc_bell) {
      C_putchar(7);
      C_fflush(stdout);
    }

    tgc = C_cpu_milliseconds();

    if(gc_mode == GC_REALLOC) {
      cell.val = "GC_REALLOC";
      C_debugger(&cell, 0, NULL);
      C_rereclaim2(percentage(heap_size, C_heap_growth), 0);
      gc_mode = GC_MAJOR;

      tgt_space_start = tospace_start;
      tgt_space_top = &tospace_top;
      tgt_space_limit= tospace_limit;

      count = (C_uword)tospace_top - (C_uword)tospace_start;
      goto never_mind_edsger;
    }

    start = (C_byte *)C_align((C_uword)tospace_top);    
    gc_mode = GC_MAJOR;
    tgt_space_start = tospace_start;
    tgt_space_top = &tospace_top;
    tgt_space_limit= tospace_limit;
    weak_pair_chain = (C_word)NULL; /* only chain up weak pairs forwarded into tospace */
    locative_chain = (C_word)NULL;  /* same for locatives */

    cell.val = "GC_MAJOR";
    C_debugger(&cell, 0, NULL);

    mark_live_heap_only_objects(tgt_space_start, tgt_space_top, tgt_space_limit);

    /* mark normal GC roots (see below for finalizer handling): */
    for(gcrp = gc_root_list; gcrp != NULL; gcrp = gcrp->next) {
      if(!gcrp->finalizable) mark(&gcrp->value);
    }
  }
  else {
    /* Mark mutated slots: */
    for(msp = mutation_stack_bottom; msp < mutation_stack_top; ++msp)
      mark(*msp);
  }

  mark_live_objects(tgt_space_start, tgt_space_top, tgt_space_limit);

  mark_nested_objects(start, tgt_space_start, tgt_space_top, tgt_space_limit);
  start = *tgt_space_top;

  if(gc_mode == GC_MINOR) {
    count = (C_uword)C_fromspace_top - (C_uword)start;
    ++gc_count_1;
    ++gc_count_1_total;
    update_locatives(GC_MINOR, start, *tgt_space_top);
    update_weak_pairs(GC_MINOR, start, *tgt_space_top);
  }
  else {
    /* Mark finalizer list and remember pointers to non-forwarded items: */
    last = C_block_item(pending_finalizers_symbol, 0);

    if(!C_immediatep(last) && (j = C_unfix(C_block_item(last, 0))) != 0) { 
      /* still finalizers pending: just mark table items... */
      if(gc_report_flag)
        C_dbg(C_text("GC"), C_text("%d finalized item(s) still pending\n"), j);

      j = fcount = 0;

      for(flist = finalizer_list; flist != NULL; flist = flist->next) {
        mark(&flist->item);
        mark(&flist->finalizer);
        ++fcount;
      }

      /* mark finalizable GC roots: */
      for(gcrp = gc_root_list; gcrp != NULL; gcrp = gcrp->next) {
        if(gcrp->finalizable) mark(&gcrp->value);
      }

      if(gc_report_flag && fcount > 0)
        C_dbg(C_text("GC"), C_text("%d finalizer value(s) marked\n"), fcount);
    }
    else {
      j = fcount = 0;

      /* move into pending */
      for(flist = finalizer_list; flist != NULL; flist = flist->next) {
        if(j < C_max_pending_finalizers) {
          if(!is_fptr(C_block_header(flist->item))) 
            pending_finalizer_indices[ j++ ] = flist;
        }
      }

      /* mark */
      for(flist = finalizer_list; flist != NULL; flist = flist->next) {
        mark(&flist->item);
        mark(&flist->finalizer);
      }

      /* mark finalizable GC roots: */
      for(gcrp = gc_root_list; gcrp != NULL; gcrp = gcrp->next) {
        if(gcrp->finalizable) mark(&gcrp->value);
      }
    }

    pending_finalizer_count = j;
    finalizers_checked = 1;

    if(pending_finalizer_count > 0 && gc_report_flag)
      C_dbg(C_text("GC"), C_text("%d finalizer(s) pending (%d live)\n"), 
            pending_finalizer_count, live_finalizer_count);

    /* Once more mark nested objects after (maybe) copying finalizer objects: */
    mark_nested_objects(start, tgt_space_start, tgt_space_top, tgt_space_limit);

    /* Copy finalized items with remembered indices into `##sys#pending-finalizers' 
       (and release finalizer node): */
    if(pending_finalizer_count > 0) {
      if(gc_report_flag)
        C_dbg(C_text("GC"), C_text("queueing %d finalizer(s)\n"), pending_finalizer_count);

      last = C_block_item(pending_finalizers_symbol, 0);
      assert(C_block_item(last, 0) == C_fix(0));
      C_set_block_item(last, 0, C_fix(pending_finalizer_count));

      for(i = 0; i < pending_finalizer_count; ++i) {
        flist = pending_finalizer_indices[ i ];
        C_set_block_item(last, 1 + i * 2, flist->item);
        C_set_block_item(last, 2 + i * 2, flist->finalizer);
	  
        if(flist->previous != NULL) flist->previous->next = flist->next;
        else finalizer_list = flist->next;

        if(flist->next != NULL) flist->next->previous = flist->previous;

        flist->next = finalizer_free_list;
        flist->previous = NULL;
        finalizer_free_list = flist;
        --live_finalizer_count;
      }
    }

    update_locatives(gc_mode, start, *tgt_space_top);
    update_weak_pairs(gc_mode, start, *tgt_space_top);

    count = (C_uword)tospace_top - (C_uword)tospace_start; // Actual used, < heap_size/2

    {
      C_uword min_half = count + C_heap_half_min_free;
      C_uword low_half = percentage(heap_size/2, C_heap_shrinkage_used);
      C_uword grown    = percentage(heap_size, C_heap_growth);
      C_uword shrunk   = percentage(heap_size, C_heap_shrinkage);

      if (count < low_half) {
        heap_shrink_counter++;
      } else {
        heap_shrink_counter = 0;
      }

      /*** isn't gc_mode always GC_MAJOR here? */
      if(gc_mode == GC_MAJOR && !C_heap_size_is_fixed &&
         C_heap_shrinkage > 0 &&
         // This prevents grow, shrink, grow, shrink... spam
         HEAP_SHRINK_COUNTS < heap_shrink_counter &&
         (min_half * 2) <= shrunk && // Min. size trumps shrinkage
         heap_size > MINIMAL_HEAP_SIZE) {
        if(gc_report_flag) {
          C_dbg(C_text("GC"), C_text("Heap low water mark hit (%d%%), shrinking...\n"),
                C_heap_shrinkage_used);
        }
        heap_shrink_counter = 0;
        C_rereclaim2(shrunk, 0);
      } else if (gc_mode == GC_MAJOR && !C_heap_size_is_fixed &&
                 (heap_size / 2) < min_half) {
        if(gc_report_flag) {
          C_dbg(C_text("GC"), C_text("Heap high water mark hit, growing...\n"));
        }
        heap_shrink_counter = 0;
        C_rereclaim2(grown, 0);
      } else {
        C_fromspace_top = tospace_top;
        tmp = fromspace_start;
        fromspace_start = tospace_start;
        tospace_start = tospace_top = tmp;
        tmp = C_fromspace_limit;
        C_fromspace_limit = tospace_limit;
        tospace_limit = tmp;
      }
    }

  never_mind_edsger:
    ++gc_count_2;
  }

  if(gc_mode == GC_MAJOR) {
    tgc = C_cpu_milliseconds() - tgc;
    gc_ms += tgc;
    timer_accumulated_gc_ms += tgc;
  }

  /* Display GC report: 
     Note: stubbornly writes to stderr - there is no provision for other output-ports */
  if(gc_report_flag == 1 || (gc_report_flag && gc_mode == GC_MAJOR)) {
    C_dbg(C_text("GC"), C_text("level  %d\tgcs(minor)  %d\tgcs(major)  %d\n"),
	  gc_mode, gc_count_1, gc_count_2);
    i = (C_uword)C_stack_pointer;

#if C_STACK_GROWS_DOWNWARD
    C_dbg("GC", C_text("stack\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING), 
	  (C_uword)C_stack_limit, (C_uword)i, (C_uword)C_stack_limit + stack_size);
#else
    C_dbg("GC", C_text("stack\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING), 
	  (C_uword)C_stack_limit - stack_size, (C_uword)i, (C_uword)C_stack_limit);
#endif

    if(gc_mode == GC_MINOR) 
      C_fprintf(C_stderr, C_text("\t" UWORD_FORMAT_STRING), (C_uword)count);

    C_fputc('\n', C_stderr);
    C_dbg("GC", C_text(" from\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING),
	  (C_uword)fromspace_start, (C_uword)C_fromspace_top, (C_uword)C_fromspace_limit);

    if(gc_mode == GC_MAJOR) 
      C_fprintf(C_stderr, C_text("\t" UWORD_FORMAT_STRING), (C_uword)count);

    C_fputc('\n', C_stderr);
    C_dbg("GC", C_text("   to\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING "\t" UWORD_FORMAT_STRING" \n"), 
	  (C_uword)tospace_start, (C_uword)tospace_top, 
	  (C_uword)tospace_limit);
  }

  /* GC will have copied any live objects out of scratch space: clear it */
  if (C_scratchspace_start != C_scratchspace_top) {
    /* And drop the scratchspace in case of a major or reallocating collection */
    if (gc_mode != GC_MINOR) {
      C_free(C_scratchspace_start);
      C_scratchspace_start = NULL;
      C_scratchspace_limit = NULL;
      scratchspace_size = 0;
    }
    C_scratchspace_top = C_scratchspace_start;
    C_scratch_usage = 0;
  }

  if(gc_mode == GC_MAJOR) {
    gc_count_1 = 0;
    maximum_heap_usage = count > maximum_heap_usage ? count : maximum_heap_usage;
  }

  if(C_post_gc_hook != NULL) C_post_gc_hook(gc_mode, (C_long)tgc);

  /* Unwind stack completely */
#ifdef HAVE_SIGSETJMP
  C_siglongjmp(C_restart, 1);
#else
  C_longjmp(C_restart, 1);
#endif
}


/* Mark live objects which can exist in the nursery and/or the heap */
static C_regparm void C_fcall mark_live_objects(C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit)
{
  C_word *p;
  TRACE_INFO *tinfo;

  assert(C_temporary_stack >= C_temporary_stack_limit);

  /* Mark live values from the currently running closure: */
  for(p = C_temporary_stack; p < C_temporary_stack_bottom; ++p)
    mark(p);

  /* Clear the mutated slot stack: */
  mutation_stack_top = mutation_stack_bottom;

  /* Mark trace-buffer: */
  for(tinfo = trace_buffer; tinfo < trace_buffer_limit; ++tinfo) {
    mark(&tinfo->cooked_location);
    mark(&tinfo->cooked1);
    mark(&tinfo->cooked2);
    mark(&tinfo->thread);
  }
}


/*
 * Mark all live *heap* objects that don't need GC mode-specific
 * treatment.  Thus, no finalizers or other GC roots.
 *
 * Finalizers are excluded because these need special handling:
 * finalizers referring to dead objects must be marked and queued.
 * However, *pending* finalizers (for objects previously determined
 * to be collectable) are marked so that these objects stick around
 * until after the finalizer has been run.
 *
 * This function does not need to be called on a minor GC, since these
 * objects won't ever exist in the nursery.
 */
static C_regparm void C_fcall mark_live_heap_only_objects(C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit)
{
  LF_LIST *lfn;
  C_word *p, **msp, last;
  unsigned int i;
  C_SYMBOL_TABLE *stp;
  
  /* Mark items in forwarding table: */
  for(p = forwarding_table; *p != 0; p += 2) {
    last = p[ 1 ];
    mark(&p[ 1 ]);
    C_block_header(p[ 0 ]) = C_block_header(last);
  }

  /* Mark literal frames: */
  for(lfn = lf_list; lfn != NULL; lfn = lfn->next)
    for(i = 0; i < (unsigned int)lfn->count; ++i)
      mark(&lfn->lf[i]);

  /* Mark symbol tables: */
  for(stp = symbol_table_list; stp != NULL; stp = stp->next)
    for(i = 0; i < stp->size; ++i)
      mark(&stp->table[i]);

  /* Mark collectibles: */
  for(msp = collectibles; msp < collectibles_top; ++msp)
    if(*msp != NULL) mark(*msp);

  /* Mark system globals */
  mark(&core_provided_symbol);
  mark(&interrupt_hook_symbol);
  mark(&error_hook_symbol);
  mark(&callback_continuation_stack_symbol);
  mark(&pending_finalizers_symbol);
  mark(&current_thread_symbol);

  mark(&u8vector_symbol);
  mark(&s8vector_symbol);
  mark(&u16vector_symbol);
  mark(&s16vector_symbol);
  mark(&u32vector_symbol);
  mark(&s32vector_symbol);
  mark(&u64vector_symbol);
  mark(&s64vector_symbol);
  mark(&f32vector_symbol);
  mark(&f64vector_symbol);
}


/*
 * Mark nested values in already moved (i.e., marked) blocks in
 * breadth-first manner (Cheney's algorithm).
 */
static C_regparm void C_fcall mark_nested_objects(C_byte *heap_scan_top, C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit)
{
  int n;
  C_word bytes;
  C_word *p;
  C_header h;
  C_SCHEME_BLOCK *bp;

  while(heap_scan_top < *tgt_space_top) {
    bp = (C_SCHEME_BLOCK *)heap_scan_top;

    if(*((C_word *)bp) == ALIGNMENT_HOLE_MARKER) 
      bp = (C_SCHEME_BLOCK *)((C_word *)bp + 1);

    n = C_header_size(bp);
    h = bp->header;
    bytes = (h & C_BYTEBLOCK_BIT) ? n : n * sizeof(C_word);
    p = bp->data;

    if(n > 0 && (h & C_BYTEBLOCK_BIT) == 0) {
      if(h & C_SPECIALBLOCK_BIT) {
	--n;
	++p;
      }

      while(n--) mark(p++);
    }

    heap_scan_top = (C_byte *)bp + C_align(bytes) + sizeof(C_word);
  }
}


static C_regparm void C_fcall really_mark(C_word *x, C_byte *tgt_space_start, C_byte **tgt_space_top, C_byte *tgt_space_limit)
{
  C_word val;
  C_uword n, bytes;
  C_header h;
  C_SCHEME_BLOCK *p, *p2;

  val = *x;

  if (!C_in_stackp(val) && !C_in_heapp(val) && !C_in_scratchspacep(val)) {
#ifdef C_GC_HOOKS
    if(C_gc_trace_hook != NULL) 
      C_gc_trace_hook(x, gc_mode);
#endif
    return;
  }

  p = (C_SCHEME_BLOCK *)val;
  h = p->header;

  while(is_fptr(h)) { /* TODO: Pass in fptr chain limit? */
    val = fptr_to_ptr(h);
    p = (C_SCHEME_BLOCK *)val;
    h = p->header;
  }

  /* Already in target space, probably as result of chasing fptrs */
  if ((C_uword)val >= (C_uword)tgt_space_start && (C_uword)val < (C_uword)*tgt_space_top) {
    *x = val;
    return;
  }

  p2 = (C_SCHEME_BLOCK *)C_align((C_uword)*tgt_space_top);

#ifndef C_SIXTY_FOUR
  if((h & C_8ALIGN_BIT) && C_aligned8(p2) && (C_byte *)p2 < tgt_space_limit) {
    *((C_word *)p2) = ALIGNMENT_HOLE_MARKER;
    p2 = (C_SCHEME_BLOCK *)((C_word *)p2 + 1);
  }
#endif

  n = C_header_size(p);
  bytes = (h & C_BYTEBLOCK_BIT) ? n : n * sizeof(C_word);

  if(C_unlikely(((C_byte *)p2 + bytes + sizeof(C_word)) > tgt_space_limit)) {
    if (gc_mode == GC_MAJOR) {
      /* Detect impossibilities before GC_REALLOC to preserve state: */
      if (C_in_stackp((C_word)p) && bytes > stack_size)
        panic(C_text("Detected corrupted data in stack"));
      if (C_in_heapp((C_word)p) && bytes > (heap_size / 2))
        panic(C_text("Detected corrupted data in heap"));
      if(C_heap_size_is_fixed)
        panic(C_text("out of memory - heap full"));
      
      gc_mode = GC_REALLOC;
    } else if (gc_mode == GC_REALLOC) {
      if (new_tospace_top > new_tospace_limit) {
        panic(C_text("out of memory - heap full while resizing"));
      }
    }
#ifdef HAVE_SIGSETJMP
    C_siglongjmp(gc_restart, 1);
#else
    C_longjmp(gc_restart, 1);
#endif
  }

  *tgt_space_top = (C_byte *)p2 + C_align(bytes) + sizeof(C_word);

  *x = (C_word)p2;
  p2->header = h;
  p->header = ptr_to_fptr((C_uword)p2);
  C_memcpy(p2->data, p->data, bytes);
  if (h == C_WEAK_PAIR_TAG && !C_immediatep(p2->data[0])) {
    p->data[0] = weak_pair_chain; /* "Recycle" the weak pair's CAR to point to prev head */
    weak_pair_chain = (C_word)p;  /* Make this fwd ptr the new head of the weak pair chain */
  } else if (h == C_LOCATIVE_TAG) {
    p->data[0] = locative_chain; /* "Recycle" the locative pointer field to point to prev head */
    locative_chain = (C_word)p;  /* Make this fwd ptr the new head of the locative chain */
  }
}


/* Do a major GC into a freshly allocated heap: */

#define remark(x)  _mark(x, new_tospace_start, &new_tospace_top, new_tospace_limit)

C_regparm void C_fcall C_rereclaim2(C_uword size, int relative_resize)
{
  int i;
  C_GC_ROOT *gcrp;
  FINALIZER_NODE *flist;
  C_byte *new_heapspace, *start;
  size_t  new_heapspace_size;

  if(C_pre_gc_hook != NULL) C_pre_gc_hook(GC_REALLOC);

  /*
   * Normally, size is "absolute": it indicates the desired size of
   * the entire new heap.  With relative_resize, size is a demanded
   * increase of the heap, so we'll have to add it.  This calculation
   * doubles the current heap size because heap_size is already both
   * halves.  We add size*2 because we'll eventually divide the size
   * by 2 for both halves.  We also add stack_size*2 because all the
   * nursery data is also copied to the heap on GC, and the requested
   * memory "size" must be available after the GC.
   */
  if(relative_resize) size = (heap_size + size + stack_size) * 2;

  if(size < MINIMAL_HEAP_SIZE) size = MINIMAL_HEAP_SIZE;

  /*
   * When heap grows, ensure it's enough to accommodate first
   * generation (nursery).  Because we're calculating the total heap
   * size here (fromspace *AND* tospace), we have to double the stack
   * size, otherwise we'd accommodate only half the stack in the tospace.
   */
  if(size > heap_size && size - heap_size < stack_size * 2)
    size = heap_size + stack_size * 2;

  /*
   * The heap has grown but we've already hit the maximal size with the current
   * heap, we can't do anything else but panic.
   */
  if(size > heap_size && heap_size >= C_maximal_heap_size)
    panic(C_text("out of memory - heap has reached its maximum size"));

  if(size > C_maximal_heap_size) size = C_maximal_heap_size;

  if(debug_mode) {
    C_dbg(C_text("debug"), C_text("resizing heap dynamically from "
                                  UWORD_COUNT_FORMAT_STRING "k to "
                                  UWORD_COUNT_FORMAT_STRING "k ...\n"),
	  heap_size / 1024, size / 1024);
  }

  if(gc_report_flag) {
    C_dbg(C_text("GC"), C_text("(old) fromspace: \tstart=" UWORD_FORMAT_STRING 
			       ", \tlimit=" UWORD_FORMAT_STRING "\n"),
	  (C_word)fromspace_start, (C_word)C_fromspace_limit);
    C_dbg(C_text("GC"), C_text("(old) tospace:   \tstart=" UWORD_FORMAT_STRING
			       ", \tlimit=" UWORD_FORMAT_STRING "\n"),
	  (C_word)tospace_start, (C_word)tospace_limit);
  }

  heap_size = size;         /* Total heap size of the two halves... */
  size /= 2;                /* ...each half is this big */
  
  /*
   * Start by allocating the new heap's fromspace.  After remarking,
   * allocate the other half of the new heap (its tospace).
   *
   * To clarify: what we call "new_space" here is what will eventually
   * be cycled over to "fromspace" when re-reclamation has finished
   * (that is, after the old one has been freed).
   */
  if ((new_heapspace = heap_alloc (size, &new_tospace_start)) == NULL)
    panic(C_text("out of memory - cannot allocate heap segment"));
  new_heapspace_size = size;

  new_tospace_top = new_tospace_start;
  new_tospace_limit = new_tospace_start + size;
  start = new_tospace_top;
  weak_pair_chain = (C_word)NULL; /* only chain up weak pairs forwarded into new heap */
  locative_chain = (C_word)NULL;  /* same for locatives */

  /* Mark standard live objects in nursery and heap */
  mark_live_objects(new_tospace_start, &new_tospace_top, new_tospace_limit);
  mark_live_heap_only_objects(new_tospace_start, &new_tospace_top, new_tospace_limit);

  /* Mark finalizer table: */
  for(flist = finalizer_list; flist != NULL; flist = flist->next) {
    remark(&flist->item);
    remark(&flist->finalizer);
  }

  /* Mark *all* GC roots */
  for(gcrp = gc_root_list; gcrp != NULL; gcrp = gcrp->next) {
    remark(&gcrp->value);
  }

  /* Mark nested values in already moved (marked) blocks in breadth-first manner: */
  mark_nested_objects(start, new_tospace_start, &new_tospace_top, new_tospace_limit);
  update_locatives(GC_REALLOC, new_tospace_top, new_tospace_top);
  update_weak_pairs(GC_REALLOC, new_tospace_top, new_tospace_top);

  heap_free (heapspace1, heapspace1_size);
  heap_free (heapspace2, heapspace2_size);
  
  if ((heapspace2 = heap_alloc (size, &tospace_start)) == NULL)
    panic(C_text("out of memory - cannot allocate next heap segment"));
  heapspace2_size = size;

  heapspace1 = new_heapspace;
  heapspace1_size = new_heapspace_size;
  tospace_limit = tospace_start + size;
  tospace_top = tospace_start;
  fromspace_start = new_tospace_start;
  C_fromspace_top = new_tospace_top;
  C_fromspace_limit = new_tospace_limit;

  if(gc_report_flag) {
    C_dbg(C_text("GC"), C_text("resized heap to %d bytes\n"), heap_size);
    C_dbg(C_text("GC"), C_text("(new) fromspace: \tstart=" UWORD_FORMAT_STRING 
			       ", \tlimit=" UWORD_FORMAT_STRING "\n"),
	  (C_word)fromspace_start, (C_word)C_fromspace_limit);
    C_dbg(C_text("GC"), C_text("(new) tospace:   \tstart=" UWORD_FORMAT_STRING
			       ", \tlimit=" UWORD_FORMAT_STRING "\n"),
	  (C_word)tospace_start, (C_word)tospace_limit);
  }

  if(C_post_gc_hook != NULL) C_post_gc_hook(GC_REALLOC, 0);
}


/* When a weak pair is encountered by GC, it turns it into a
 * forwarding reference as usual, but then it re-uses the now-defunct
 * pair's CAR field.  It clobbers that field with a plain C pointer to
 * the current "weak pair chain".  Then, the weak pair chain is
 * updated to point to this new forwarding pointer, creating a crude
 * linked list of sorts.
 *
 * We can get away with this because the slots of an object are
 * unused/dead when it is turned into a forwarding pointer - the
 * forwarding pointer itself is just a header, but those data fields
 * remain allocated.  Since the weak pair chain is a linked list that
 * can *only* contain weak-pairs-turned-forwarding-pointer, we may
 * freely access the first slot of such forwarding pointers.
 */
static C_regparm void C_fcall update_weak_pairs(int mode, C_byte *undead_start, C_byte *undead_end)
{
  int weakn = 0;
  C_word p, pair, car, h;
  C_byte *car_ptr;

  /* NOTE: Don't use C_block_item() because it asserts the block is
   * big enough in DEBUGBUILD, but forwarding pointers have size 0.
   */
  for (p = weak_pair_chain; p != (C_word)NULL; p = *((C_word *)C_data_pointer(p))) {
    /* NOTE: We only chain up the weak pairs' forwarding pointers into
     * the new space.  This is safe because already forwarded weak
     * pairs in nursery/fromspace will be forwarded *again* into
     * tospace/new heap.  That forwarding pointer is chained up.
     * Still-unforwarded weak pairs will be forwarded straight to the
     * new space, and also chained up.
     */
    h = C_block_header(p);
    assert(is_fptr(h));
    pair = fptr_to_ptr(h);
    assert(!is_fptr(C_block_header(pair)));

    /* The pair itself should be live */
    assert((mode == GC_MINOR && !C_in_stackp(pair)) ||
           (mode == GC_MAJOR && !C_in_stackp(pair) && !C_in_fromspacep(pair)) ||
           (mode == GC_REALLOC && !C_in_stackp(pair) && !C_in_heapp(pair))); /* NB: *old* heap! */

    car = C_block_item(pair, 0);
    assert(!C_immediatep(car)); /* should be ensured when adding it to the chain */
    h = C_block_header(car);
    while (is_fptr(h)) {
      car = fptr_to_ptr(h);
      h = C_block_header(car);
    }

    car_ptr = (C_byte *)(C_uword)car;
    /* If the car is unreferenced by anyone else, it wasn't moved by GC.  Or, if it's in the "undead" portion of
       the new heap, it was moved because it was only referenced by a revived finalizable object.  In either case, drop it: */
    if((mode == GC_MINOR && C_in_stackp(car)) ||
       (mode == GC_MAJOR && (C_in_stackp(car) || C_in_fromspacep(car) || (car_ptr >= undead_start && car_ptr < undead_end))) ||
       (mode == GC_REALLOC && (C_in_stackp(car) || C_in_heapp(car) || (car_ptr >= undead_start && car_ptr < undead_end)))) { /* NB: *old* heap! */

      C_set_block_item(pair, 0, C_SCHEME_BROKEN_WEAK_PTR);
      ++weakn;
    } else {
      /* Might have moved, re-set the car to the target value */
      C_set_block_item(pair, 0, car);
    }
  }
  weak_pair_chain = (C_word)NULL;
  if(gc_report_flag && weakn)
    C_dbg("GC", C_text("%d recoverable weak pairs found\n"), weakn);
}

/* Same as weak pairs (see above), but for locatives.  Note that this
 * also includes non-weak locatives, as these point *into* an object,
 * so the updating of that pointer is not handled by the GC proper
 * (which only deals with full objects).
 */
static C_regparm void C_fcall update_locatives(int mode, C_byte *undead_start, C_byte *undead_end)
{
  int weakn = 0;
  C_word p, loc, ptr, obj, h, offset;
  C_byte *obj_ptr;

  for (p = locative_chain; p != (C_word)NULL; p = *((C_word *)C_data_pointer(p))) {
    h = C_block_header(p);
    assert(is_fptr(h));
    loc = fptr_to_ptr(h);
    assert(!is_fptr(C_block_header(loc)));

    /* The locative object itself should be live */
    assert((mode == GC_MINOR && !C_in_stackp(loc)) ||
           (mode == GC_MAJOR && !C_in_stackp(loc) && !C_in_fromspacep(loc)) ||
           (mode == GC_REALLOC && !C_in_stackp(loc) && !C_in_heapp(loc))); /* NB: *old* heap! */

    ptr = C_block_item(loc, 0); /* fix up ptr */
    if (ptr == 0) continue; /* Skip already dropped weak locatives */
    offset = C_unfix(C_block_item(loc, 1));
    obj = ptr - offset;

    h = C_block_header(obj);
    while (is_fptr(h)) {
      obj = fptr_to_ptr(h);
      h = C_block_header(obj);
    }

    obj_ptr = (C_byte *)(C_uword)obj;
    /* If the object is unreferenced by anyone else, it wasn't moved by GC.  Or, if it's in the "undead" portion of
       the new heap, it was moved because it was only referenced by a revived finalizable object.  In either case, drop it: */
    if((mode == GC_MINOR && C_in_stackp(obj)) ||
       (mode == GC_MAJOR && (C_in_stackp(obj) || C_in_fromspacep(obj) || (obj_ptr >= undead_start && obj_ptr < undead_end))) ||
       (mode == GC_REALLOC && (C_in_stackp(obj) || C_in_heapp(obj) || (obj_ptr >= undead_start && obj_ptr < undead_end)))) { /* NB: *old* heap! */

      /* NOTE: This does *not* use BROKEN_WEAK_POINTER.  This slot
       * holds an unaligned raw C pointer, not a Scheme object */
      C_set_block_item(loc, 0, 0);
      ++weakn;
    } else {
      /* Might have moved, re-set the object to the target value */
      C_set_block_item(loc, 0, obj + offset);
    }
  }
  locative_chain = (C_word)NULL;
  if(gc_report_flag && weakn)
    C_dbg("GC", C_text("%d recoverable weak locatives found\n"), weakn);
}


void handle_interrupt(void *trampoline)
{
  C_word *p, h, reason, state, proc, n;
  double c;
  C_word av[ 4 ]; 

  /* Build vector with context information: */
  n = C_temporary_stack_bottom - C_temporary_stack;
  p = C_alloc(C_SIZEOF_VECTOR(2) + C_SIZEOF_VECTOR(n));
  proc = (C_word)p;
  *(p++) = C_VECTOR_TYPE | C_BYTEBLOCK_BIT | sizeof(C_word);
  *(p++) = (C_word)trampoline;
  state = (C_word)p;
  *(p++) = C_VECTOR_TYPE | (n + 1);
  *(p++) = proc;
  C_memcpy(p, C_temporary_stack, n * sizeof(C_word));

  /* Restore state to the one at the time of the interrupt: */
  C_temporary_stack = C_temporary_stack_bottom;
  C_stack_limit = C_stack_hard_limit;
  
  /* Invoke high-level interrupt handler: */
  reason = C_fix(pending_interrupts[ --pending_interrupts_count ]);
  proc = C_block_item(interrupt_hook_symbol, 0);

  if(C_immediatep(proc))
    panic(C_text("`##sys#interrupt-hook' is not defined"));

  c = C_cpu_milliseconds() - interrupt_time;
  last_interrupt_latency = c;
  C_timer_interrupt_counter = C_initial_timer_interrupt_period;
  /* <- no continuation is passed: "##sys#interrupt-hook" may not return! */
  av[ 0 ] = proc;
  av[ 1 ] = C_SCHEME_UNDEFINED;
  av[ 2 ] = reason;
  av[ 3 ] = state;
  C_do_apply(4, av);
}


void 
C_unbound_variable(C_word sym)
{
  barf(C_UNBOUND_VARIABLE_ERROR, NULL, sym);
}


/* XXX: This needs to be given a better name.
   C_retrieve used to exist but it just called C_fast_retrieve */
C_regparm C_word C_fcall C_retrieve2(C_word val, char *name)
{
  C_word *p;
  int len;

  if(val == C_SCHEME_UNBOUND) {
    len = C_strlen(name);
    /* this is ok: we won't return from `C_retrieve2'
     * (or the value isn't needed). */
    p = C_alloc(C_SIZEOF_STRING(len));
    C_unbound_variable(C_string2(&p, name));
  }

  return val;
}


void C_ccall C_invalid_procedure(C_word c, C_word *av)
{
  C_word self = av[0];
  barf(C_NOT_A_CLOSURE_ERROR, NULL, self);  
}


C_regparm void *C_fcall C_retrieve2_symbol_proc(C_word val, char *name)
{
  C_word *p;
  int len;

  if(val == C_SCHEME_UNBOUND) {
    len = C_strlen(name);
    /* this is ok: we won't return from `C_retrieve2' (or the value isn't needed). */
    p = C_alloc(C_SIZEOF_STRING(len));
    barf(C_UNBOUND_VARIABLE_ERROR, NULL, C_string2(&p, name));
  }

  return C_fast_retrieve_proc(val);
}

#ifdef C_NONUNIX
VOID CALLBACK win_timer(PVOID data_ignored, BOOLEAN wait_or_fired)
{
  if (profiling) take_profile_sample();
}
#endif

static void set_profile_timer(C_uword freq)
{
#ifdef C_NONUNIX
  static HANDLE timer = NULL;

  if (freq == 0) {
    assert(timer != NULL);
    if (!DeleteTimerQueueTimer(NULL, timer, NULL)) goto error;
    timer = NULL;
  } else if (freq < 1000) {
    panic(C_text("On Windows, sampling can only be done in milliseconds"));
  } else {
    if (!CreateTimerQueueTimer(&timer, NULL, win_timer, NULL, 0, freq/1000, 0))
      goto error;
  }
#else
  struct itimerval itv;

  itv.it_value.tv_sec = freq / 1000000;
  itv.it_value.tv_usec = freq % 1000000;
  itv.it_interval.tv_sec = itv.it_value.tv_sec;
  itv.it_interval.tv_usec = itv.it_value.tv_usec;

  if (setitimer(C_PROFILE_TIMER, &itv, NULL) == -1) goto error;
#endif

  return;

error:
  if (freq == 0) panic(C_text("error clearing timer for profiling"));
  else panic(C_text("error setting timer for profiling"));
}

/* Bump profile count for current top of trace buffer */
static void take_profile_sample()
{
  PROFILE_BUCKET **bp, *b;
  C_char *key;
  TRACE_INFO *tb;
  /* To count distinct calls of a procedure, remember last call */
  static C_char *prev_key = NULL;
  static TRACE_INFO *prev_tb = NULL;

  /* trace_buffer_top points *beyond* the topmost entry: Go back one */
  if (trace_buffer_top == trace_buffer) {
    if (!trace_buffer_full) return; /* No data yet */
    tb = trace_buffer_limit - 1;
  } else {
    tb = trace_buffer_top - 1;
  }

  if (tb->raw_location != NULL) {
    key = tb->raw_location;
  } else {
    key = "<eval>"; /* Location string is GCable, can't use it */
  }

  /* We could also just hash the pointer but that's a bit trickier */
  bp = profile_table + hash_string(C_strlen(key), key, PROFILE_TABLE_SIZE, 0, 0);
  b = *bp;

  /* First try to find pre-existing item in hash table */
  while(b != NULL) {
    if(b->key == key) {
      b->sample_count++;
      if (prev_key != key && prev_tb != tb)
        b->call_count++;
      goto done;
    }
    else b = b->next;
  }

  /* Not found, allocate a new item and use it as bucket's new head */
  b = next_profile_bucket;
  next_profile_bucket = NULL;

  assert(b != NULL);

  b->next = *bp;
  b->key = key;
  *bp = b;
  b->sample_count = 1;
  b->call_count = 1;

done:
  prev_tb = tb;
  prev_key = key;
}


C_regparm void C_fcall C_trace(C_char *name)
{
  C_word thread;

  if(show_trace) {
    C_fputs(name, C_stderr);
    C_fputc('\n', C_stderr);
  }

  /*
   * When profiling, pre-allocate profile bucket if necessary.  This
   * is used in the signal handler, because it may not malloc.
   */
  if(profiling && next_profile_bucket == NULL) {
    next_profile_bucket = (PROFILE_BUCKET *)C_malloc(sizeof(PROFILE_BUCKET));
    if (next_profile_bucket == NULL) {
      panic(C_text("out of memory - cannot allocate profile table-bucket"));
    }
  }

  if(trace_buffer_top >= trace_buffer_limit) {
    trace_buffer_top = trace_buffer;
    trace_buffer_full = 1;
  }

  trace_buffer_top->raw_location = name;
  trace_buffer_top->cooked_location = C_SCHEME_FALSE;
  trace_buffer_top->cooked1 = C_SCHEME_FALSE;
  trace_buffer_top->cooked2 = C_SCHEME_FALSE;
  thread = C_block_item(current_thread_symbol, 0);
  trace_buffer_top->thread = C_and(C_blockp(thread), C_thread_id(thread));
  ++trace_buffer_top;
}


C_regparm C_word C_fcall C_emit_trace_info2(char *raw, C_word l, C_word x, C_word y, C_word t)
{
  /* See above */
  if(profiling && next_profile_bucket == NULL) {
    next_profile_bucket = (PROFILE_BUCKET *)C_malloc(sizeof(PROFILE_BUCKET));
    if (next_profile_bucket == NULL) {
      panic(C_text("out of memory - cannot allocate profile table-bucket"));
    }
  }

  if(trace_buffer_top >= trace_buffer_limit) {
    trace_buffer_top = trace_buffer;
    trace_buffer_full = 1;
  }

  trace_buffer_top->raw_location = raw;
  trace_buffer_top->cooked_location = l;
  trace_buffer_top->cooked1 = x;
  trace_buffer_top->cooked2 = y;
  trace_buffer_top->thread = t;
  ++trace_buffer_top;
  return x;
}


C_char *C_dump_trace(int start)
{
  TRACE_INFO *ptr;
  C_char *result;
  int i, result_len;

  result_len = STRING_BUFFER_SIZE;
  if((result = (char *)C_malloc(result_len)) == NULL)
    horror(C_text("out of memory - cannot allocate trace-dump buffer"));

  *result = '\0';

  if(trace_buffer_top > trace_buffer || trace_buffer_full) {
    if(trace_buffer_full) {
      i = C_trace_buffer_size;
      C_strlcat(result, C_text("...more...\n"), result_len);
    }
    else i = trace_buffer_top - trace_buffer;

    ptr = trace_buffer_full ? trace_buffer_top : trace_buffer;
    ptr += start;
    i -= start;

    for(;i--; ++ptr) {
      if(ptr >= trace_buffer_limit) ptr = trace_buffer;

      if(C_strlen(result) > STRING_BUFFER_SIZE - 32) {
        result_len = C_strlen(result) * 2;
        result = C_realloc(result, result_len);
	if(result == NULL)
	  horror(C_text("out of memory - cannot reallocate trace-dump buffer"));
      }

      if (ptr->raw_location != NULL) {
        C_strlcat(result, ptr->raw_location, result_len);
      } else if (ptr->cooked_location != C_SCHEME_FALSE) {
        C_strlcat(result, C_c_string(ptr->cooked_location), nmin(C_header_size(ptr->cooked_location), result_len));
      } else {
        C_strlcat(result, "<unknown>", result_len);
      }

      if(i > 0) C_strlcat(result, "\n", result_len);
      else C_strlcat(result, " \t<--\n", result_len);
    }
  }

  return result;
}


C_regparm void C_fcall C_clear_trace_buffer(void)
{
  int i, old_profiling = profiling;

  profiling = 0;

  if(trace_buffer == NULL) {
    if(C_trace_buffer_size < MIN_TRACE_BUFFER_SIZE)
      C_trace_buffer_size = MIN_TRACE_BUFFER_SIZE;

    trace_buffer = (TRACE_INFO *)C_malloc(sizeof(TRACE_INFO) * C_trace_buffer_size);

    if(trace_buffer == NULL)
      panic(C_text("out of memory - cannot allocate trace-buffer"));
  }

  trace_buffer_top = trace_buffer;
  trace_buffer_limit = trace_buffer + C_trace_buffer_size;
  trace_buffer_full = 0;

  for(i = 0; i < C_trace_buffer_size; ++i) {
    trace_buffer[ i ].raw_location = NULL;
    trace_buffer[ i ].cooked_location = C_SCHEME_FALSE;
    trace_buffer[ i ].cooked1 = C_SCHEME_FALSE;
    trace_buffer[ i ].cooked2 = C_SCHEME_FALSE;
    trace_buffer[ i ].thread = C_SCHEME_FALSE;
  }

  profiling = old_profiling;
}

C_word C_resize_trace_buffer(C_word size) {
  int old_size = C_trace_buffer_size, old_profiling = profiling;
  assert(trace_buffer);
  profiling = 0;
  free(trace_buffer);
  trace_buffer = NULL;
  C_trace_buffer_size = C_unfix(size);
  C_clear_trace_buffer();
  profiling = old_profiling;
  return(C_fix(old_size));
}

C_word C_fetch_trace(C_word starti, C_word buffer)
{
  TRACE_INFO *ptr;
  int i, p = 0, start = C_unfix(starti);

  if(trace_buffer_top > trace_buffer || trace_buffer_full) {
    if(trace_buffer_full) i = C_trace_buffer_size;
    else i = trace_buffer_top - trace_buffer;

    ptr = trace_buffer_full ? trace_buffer_top : trace_buffer;
    ptr += start;
    i -= start;

    if(C_header_size(buffer) < i * 5)
      panic(C_text("destination buffer too small for call-chain"));

    for(;i--; ++ptr) {
      if(ptr >= trace_buffer_limit) ptr = trace_buffer;

      /* outside-pointer, will be ignored by GC */
      C_mutate(&C_block_item(buffer, p++), (C_word)ptr->raw_location);

      /* subject to GC */
      C_mutate(&C_block_item(buffer, p++), ptr->cooked_location);
      C_mutate(&C_block_item(buffer, p++), ptr->cooked1);
      C_mutate(&C_block_item(buffer, p++), ptr->cooked2);
      C_mutate(&C_block_item(buffer, p++), ptr->thread);
    }
  }

  return C_fix(p);
}

C_regparm C_word C_fcall C_u_i_string_hash(C_word str, C_word rnd)
{
  int len = C_header_size(str);
  C_char *ptr = C_data_pointer(str);
  return C_fix(hash_string(len, ptr, C_MOST_POSITIVE_FIXNUM, C_unfix(rnd), 0));
}

C_regparm C_word C_fcall C_u_i_string_ci_hash(C_word str, C_word rnd)
{
  int len = C_header_size(str);
  C_char *ptr = C_data_pointer(str);
  return C_fix(hash_string(len, ptr, C_MOST_POSITIVE_FIXNUM, C_unfix(rnd), 1));
}

C_regparm void C_fcall C_toplevel_entry(C_char *name)
{
  if(debug_mode)
    C_dbg(C_text("debug"), C_text("entering %s...\n"), name);
}

C_regparm C_word C_fcall C_a_i_provide(C_word **a, int c, C_word id)
{
  if (debug_mode == 2) {
    C_word str = C_block_item(id, 1);
    C_snprintf(buffer, C_header_size(str) + 1, C_text("%s"), (C_char *) C_data_pointer(str));
    C_dbg(C_text("debug"), C_text("providing %s...\n"), buffer);
  }
  return C_a_i_putprop(a, 3, core_provided_symbol, id, C_SCHEME_TRUE);
}

C_regparm C_word C_fcall C_i_providedp(C_word id)
{
  return C_i_getprop(core_provided_symbol, id, C_SCHEME_FALSE);
}

C_word C_halt(C_word msg)
{
  C_char *dmp = msg != C_SCHEME_FALSE ? C_dump_trace(0) : NULL;

  if(C_gui_mode) {
    if(msg != C_SCHEME_FALSE) {
      int n = C_header_size(msg);

      if (n >= sizeof(buffer))
	n = sizeof(buffer) - 1;
      C_strlcpy(buffer, (C_char *)C_data_pointer(msg), n);
      /* XXX msg isn't checked for NUL bytes, but we can't barf here either! */
    }
    else C_strlcpy(buffer, C_text("(aborted)"), sizeof(buffer));

    C_strlcat(buffer, C_text("\n\n"), sizeof(buffer));

    if(dmp != NULL) C_strlcat(buffer, dmp, sizeof(buffer));

#if defined(_WIN32) && !defined(__CYGWIN__) 
    MessageBox(NULL, buffer, C_text("CHICKEN runtime"), MB_OK | MB_ICONERROR);
    ExitProcess(1);
#endif
  } /* otherwise fall through */

  if(msg != C_SCHEME_FALSE) {
    C_fwrite(C_data_pointer(msg), C_header_size(msg), sizeof(C_char), C_stderr);
    C_fputc('\n', C_stderr);
  }

  if(dmp != NULL) 
    C_dbg("", C_text("\n%s"), dmp);
  
  C_exit_runtime(C_fix(EX_SOFTWARE));
  return 0;
}


C_word C_message(C_word msg)
{
  unsigned int n = C_header_size(msg);
  /*
   * Strictly speaking this isn't necessary for the non-gui-mode,
   * but let's try and keep this consistent across modes.
   */
  if (C_memchr(C_c_string(msg), '\0', n) != NULL)
    barf(C_ASCIIZ_REPRESENTATION_ERROR, "##sys#message", msg);

  if(C_gui_mode) {
    if (n >= sizeof(buffer))
      n = sizeof(buffer) - 1;
    C_strncpy(buffer, C_c_string(msg), n);
    buffer[ n ] = '\0';
#if defined(_WIN32) && !defined(__CYGWIN__)
    MessageBox(NULL, buffer, C_text("CHICKEN runtime"), MB_OK | MB_ICONEXCLAMATION);
    return C_SCHEME_UNDEFINED;
#endif
  } /* fall through */

  C_fwrite(C_c_string(msg), n, sizeof(C_char), stdout);
  C_putchar('\n');
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_equalp(C_word x, C_word y)
{
  C_header header;
  C_word bits, n, i;

  C_stack_check1(barf(C_CIRCULAR_DATA_ERROR, "equal?"));

 loop:
  if(x == y) return 1;

  if(C_immediatep(x) || C_immediatep(y)) return 0;

  /* NOTE: Extra check at the end is special consideration for pairs being equal to weak pairs */
  if((header = C_block_header(x)) != C_block_header(y) && !(C_header_type(x) == C_PAIR_TYPE && C_header_type(y) == C_PAIR_TYPE)) return 0;
  else if((bits = header & C_HEADER_BITS_MASK) & C_BYTEBLOCK_BIT) {
    if(header == C_FLONUM_TAG && C_block_header(y) == C_FLONUM_TAG)
      return C_ub_i_flonum_eqvp(C_flonum_magnitude(x),
                                C_flonum_magnitude(y));
    else return !C_memcmp(C_data_pointer(x), C_data_pointer(y), header & C_HEADER_SIZE_MASK);
  }
  else if(header == C_SYMBOL_TAG) return 0;
  else {
    i = 0;
    n = header & C_HEADER_SIZE_MASK;

    if(bits & C_SPECIALBLOCK_BIT) {
      /* do not recurse into closures */
      if(C_header_bits(x) == C_CLOSURE_TYPE)
	return !C_memcmp(C_data_pointer(x), C_data_pointer(y), n * sizeof(C_word));
      else if(C_block_item(x, 0) != C_block_item(y, 0)) return 0;
      else ++i;

      if(n == 1) return 1;
    }

    if(--n < 0) return 1;

    while(i < n)
      if(!C_equalp(C_block_item(x, i), C_block_item(y, i))) return 0;
      else ++i;

    x = C_block_item(x, i);
    y = C_block_item(y, i);
    goto loop;
  }
}


C_regparm C_word C_fcall C_set_gc_report(C_word flag)
{
  if(flag == C_SCHEME_FALSE) gc_report_flag = 0;
  else if(flag == C_SCHEME_TRUE) gc_report_flag = 2;
  else gc_report_flag = 1;

  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_accumulated_gc_time(void)
{
  double tgc;

  tgc = timer_accumulated_gc_ms;
  timer_accumulated_gc_ms = 0;
  return C_fix(tgc);
}

C_regparm C_word C_fcall C_start_timer(void)
{
  tracked_mutation_count = 0;
  mutation_count = 0;
  gc_count_1_total = 0;
  gc_count_2 = 0;
  timer_start_ms = C_cpu_milliseconds();
  gc_ms = 0;
  maximum_heap_usage = 0;
  return C_SCHEME_UNDEFINED;
}


void C_ccall C_stop_timer(C_word c, C_word *av)
{
  C_word 
    closure = av[ 0 ],
    k = av[ 1 ];
  double t0 = C_cpu_milliseconds() - timer_start_ms;
  C_word 
    ab[ WORDS_PER_FLONUM * 2 + C_SIZEOF_BIGNUM(1) + C_SIZEOF_VECTOR(7) ],
    *a = ab,
    elapsed = C_flonum(&a, t0 / 1000.0),
    gc_time = C_flonum(&a, gc_ms / 1000.0),
    heap_usage = C_unsigned_int_to_num(&a, maximum_heap_usage),
    info;
  
  info = C_vector(&a, 7, elapsed, gc_time, C_fix(mutation_count),
                  C_fix(tracked_mutation_count), C_fix(gc_count_1_total),
		  C_fix(gc_count_2), heap_usage);
  C_kontinue(k, info);
}


C_word C_exit_runtime(C_word code)
{
  C_fflush(NULL);
  C__exit(C_unfix(code));
}


C_regparm C_word C_fcall C_set_print_precision(C_word n)
{
  flonum_print_precision = C_unfix(n);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_get_print_precision(void)
{
  return C_fix(flonum_print_precision);
}


C_regparm C_word C_fcall C_read_char(C_word port)
{
  C_FILEPTR fp = C_port_file(port);
  int c = C_getc(fp);

  if(c == EOF) {
    if(ferror(fp)) {
      clearerr(fp);
      return C_fix(-1);
    }
    /* Found here:
       http://mail.python.org/pipermail/python-bugs-list/2002-July/012579.html */
#if defined(_WIN32) && !defined(__CYGWIN__)
    else if(GetLastError() == ERROR_OPERATION_ABORTED) return C_fix(-1);
#endif
    else return C_SCHEME_END_OF_FILE;
  }

  return C_make_character(c);
}


C_regparm C_word C_fcall C_peek_char(C_word port)
{
  C_FILEPTR fp = C_port_file(port);
  int c = C_getc(fp);

  if(c == EOF) {
    if(ferror(fp)) {
      clearerr(fp);
      return C_fix(-1);
    }
    /* see above */
#if defined(_WIN32) && !defined(__CYGWIN__)
    else if(GetLastError() == ERROR_OPERATION_ABORTED) return C_fix(-1);
#endif
    else return C_SCHEME_END_OF_FILE;
  }

  C_ungetc(c, fp);
  return C_make_character(c);
}


C_regparm C_word C_fcall C_execute_shell_command(C_word string)
{
  int n = C_header_size(string);
  char *buf = buffer;

  /* Windows doc says to flush all output streams before calling system.
     Probably a good idea for all platforms. */
  (void)fflush(NULL);

  if(n >= STRING_BUFFER_SIZE) {
    if((buf = (char *)C_malloc(n + 1)) == NULL)
      barf(C_OUT_OF_MEMORY_ERROR, "system");
  }

  C_memcpy(buf, C_data_pointer(string), n);
  buf[ n ] = '\0';
  if (n != strlen(buf))
    barf(C_ASCIIZ_REPRESENTATION_ERROR, "system", string);

  n = C_system(buf);

  if(buf != buffer) C_free(buf);

  return C_fix(n);
}

/*
 * TODO: Implement something for Windows that supports selecting on
 * arbitrary fds (there, select() only works on network sockets and
 * poll() is not available at all).
 */
C_regparm int C_fcall C_check_fd_ready(int fd)
{
#ifdef NO_POSIX_POLL
  fd_set in;
  struct timeval tm;
  int rv;
  FD_ZERO(&in);
  FD_SET(fd, &in);
  tm.tv_sec = tm.tv_usec = 0;
  rv = select(fd + 1, &in, NULL, NULL, &tm);
  if(rv > 0) { rv = FD_ISSET(fd, &in) ? 1 : 0; }
  return rv;
#else
  struct pollfd ps;
  ps.fd = fd;
  ps.events = POLLIN;
  return poll(&ps, 1, 0);
#endif
}

C_regparm C_word C_fcall C_char_ready_p(C_word port)
{
#if defined(C_NONUNIX)
  /* The best we can currently do on Windows... */
  return C_SCHEME_TRUE;
#else
  int fd = C_fileno(C_port_file(port));
  return C_mk_bool(C_check_fd_ready(fd) == 1);
#endif
}

C_regparm C_word C_fcall C_i_tty_forcedp(void)
{
  return C_mk_bool(fake_tty_flag);
}

C_regparm C_word C_fcall C_i_debug_modep(void)
{
  return C_mk_bool(debug_mode);
}

C_regparm C_word C_fcall C_i_dump_heap_on_exitp(void)
{
  return C_mk_bool(dump_heap_on_exit);
}

C_regparm C_word C_fcall C_i_profilingp(void)
{
  return C_mk_bool(profiling);
}

C_regparm C_word C_fcall C_i_live_finalizer_count(void)
{
  return C_fix(live_finalizer_count);
}

C_regparm C_word C_fcall C_i_allocated_finalizer_count(void)
{
  return C_fix(allocated_finalizer_count);
}


C_regparm void C_fcall C_raise_interrupt(int reason)
{
  if(C_interrupts_enabled) {
    if(pending_interrupts_count == 0 && !handling_interrupts) {
      pending_interrupts[ pending_interrupts_count++ ] = reason;
      /*
       * Force the next "soft" stack check to fail by faking a "full"
       * stack.  This causes save_and_reclaim() to be called, which
       * invokes handle_interrupt(), which restores the stack limit.
       */
      C_stack_limit = stack_bottom;
      interrupt_time = C_cpu_milliseconds();
    } else if(pending_interrupts_count < MAX_PENDING_INTERRUPTS) {
      int i;
      /*
       * Drop signals if too many, but don't queue up multiple entries
       * for the same signal.
       */
      for (i = 0; i < pending_interrupts_count; ++i) {
        if (pending_interrupts[i] == reason)
          return;
      }
      pending_interrupts[ pending_interrupts_count++ ] = reason;
    }
  }
}


C_regparm C_word C_fcall C_enable_interrupts(void)
{
  C_timer_interrupt_counter = C_initial_timer_interrupt_period;
  /* assert(C_timer_interrupt_counter > 0); */
  C_interrupts_enabled = 1;
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_disable_interrupts(void)
{
  C_interrupts_enabled = 0;
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_establish_signal_handler(C_word signum, C_word reason)
{
  int sig = C_unfix(signum);
#if defined(HAVE_SIGACTION)
  struct sigaction newsig;
#endif

  if(reason == C_SCHEME_FALSE) C_signal(sig, SIG_IGN);
  else if(reason == C_SCHEME_TRUE) C_signal(sig, SIG_DFL);
  else {
    signal_mapping_table[ sig ] = C_unfix(reason);
#if defined(HAVE_SIGACTION)
    newsig.sa_flags = 0;
    /* The global signal handler is used for all signals, and
       manipulates a single queue.  Don't allow other signals to
       concurrently arrive while it's doing this, to avoid races. */
    sigfillset(&newsig.sa_mask);
    newsig.sa_handler = global_signal_handler;
    C_sigaction(sig, &newsig, NULL);
#else
    C_signal(sig, global_signal_handler);
#endif
  }

  return C_SCHEME_UNDEFINED;
}


/* Copy blocks into collected or static memory: */

C_regparm C_word C_fcall C_copy_block(C_word from, C_word to)
{
  int n = C_header_size(from);
  C_long bytes;

  if(C_header_bits(from) & C_BYTEBLOCK_BIT) {
    bytes = n;
    C_memcpy((C_SCHEME_BLOCK *)to, (C_SCHEME_BLOCK *)from, bytes + sizeof(C_header));
  }
  else {
    bytes = C_wordstobytes(n);
    C_memcpy((C_SCHEME_BLOCK *)to, (C_SCHEME_BLOCK *)from, bytes + sizeof(C_header));
  }

  return to;
}


C_regparm C_word C_fcall C_evict_block(C_word from, C_word ptr)
{
  int n = C_header_size(from);
  C_long bytes;
  C_word *p = (C_word *)C_pointer_address(ptr);

  if(C_header_bits(from) & C_BYTEBLOCK_BIT) bytes = n;
  else bytes = C_wordstobytes(n);

  C_memcpy(p, (C_SCHEME_BLOCK *)from, bytes + sizeof(C_header));
  return (C_word)p;
}


/* Inline versions of some standard procedures: */

C_regparm C_word C_fcall C_i_listp(C_word x)
{
  C_word fast = x, slow = x;

  while(fast != C_SCHEME_END_OF_LIST)
    if(!C_immediatep(fast) && C_header_type(fast) == C_PAIR_TYPE) {
      fast = C_u_i_cdr(fast);
      
      if(fast == C_SCHEME_END_OF_LIST) return C_SCHEME_TRUE;
      else if(!C_immediatep(fast) && C_header_type(fast) == C_PAIR_TYPE) {
	fast = C_u_i_cdr(fast);
	slow = C_u_i_cdr(slow);

	if(fast == slow) return C_SCHEME_FALSE;
      }
      else return C_SCHEME_FALSE;
    }
    else return C_SCHEME_FALSE;

  return C_SCHEME_TRUE;
}

C_regparm C_word C_fcall C_i_u8vectorp(C_word x)
{
  return C_i_structurep(x, u8vector_symbol);
}

C_regparm C_word C_fcall C_i_s8vectorp(C_word x)
{
  return C_i_structurep(x, s8vector_symbol);
}

C_regparm C_word C_fcall C_i_u16vectorp(C_word x)
{
  return C_i_structurep(x, u16vector_symbol);
}

C_regparm C_word C_fcall C_i_s16vectorp(C_word x)
{
  return C_i_structurep(x, s16vector_symbol);
}

C_regparm C_word C_fcall C_i_u32vectorp(C_word x)
{
  return C_i_structurep(x, u32vector_symbol);
}

C_regparm C_word C_fcall C_i_s32vectorp(C_word x)
{
  return C_i_structurep(x, s32vector_symbol);
}

C_regparm C_word C_fcall C_i_u64vectorp(C_word x)
{
  return C_i_structurep(x, u64vector_symbol);
}

C_regparm C_word C_fcall C_i_s64vectorp(C_word x)
{
  return C_i_structurep(x, s64vector_symbol);
}

C_regparm C_word C_fcall C_i_f32vectorp(C_word x)
{
  return C_i_structurep(x, f32vector_symbol);
}

C_regparm C_word C_fcall C_i_f64vectorp(C_word x)
{
  return C_i_structurep(x, f64vector_symbol);
}


C_regparm C_word C_fcall C_i_string_equal_p(C_word x, C_word y)
{
  C_word n;

  if(C_immediatep(x) || C_header_bits(x) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string=?", x);

  if(C_immediatep(y) || C_header_bits(y) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string=?", y);

  n = C_header_size(x);

  return C_mk_bool(n == C_header_size(y)
                   && !C_memcmp((char *)C_data_pointer(x), (char *)C_data_pointer(y), n));
}


C_regparm C_word C_fcall C_i_string_ci_equal_p(C_word x, C_word y)
{
  C_word n;
  char *p1, *p2;

  if(C_immediatep(x) || C_header_bits(x) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-ci=?", x);

  if(C_immediatep(y) || C_header_bits(y) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-ci=?", y);

  n = C_header_size(x);

  if(n != C_header_size(y)) return C_SCHEME_FALSE;

  p1 = (char *)C_data_pointer(x);
  p2 = (char *)C_data_pointer(y);

  while(n--) {
    if(C_tolower((int)(*(p1++))) != C_tolower((int)(*(p2++))))
      return C_SCHEME_FALSE;
  }

  return C_SCHEME_TRUE;
}


C_word C_a_i_list(C_word **a, int c, ...)
{
  va_list v;
  C_word x, last, current,
         first = C_SCHEME_END_OF_LIST;

  va_start(v, c);

  for(last = C_SCHEME_UNDEFINED; c--; last = current) {
    x = va_arg(v, C_word);
    current = C_a_pair(a, x, C_SCHEME_END_OF_LIST);

    if(last != C_SCHEME_UNDEFINED)
      C_set_block_item(last, 1, current);
    else first = current;
  }

  va_end(v);
  return first;
}


C_word C_a_i_string(C_word **a, int c, ...)
{
  va_list v;
  C_word x, s = (C_word)(*a);
  char *p;

  *a = (C_word *)((C_word)(*a) + sizeof(C_header) + C_align(c));
  C_block_header_init(s, C_STRING_TYPE | c);
  p = (char *)C_data_pointer(s);
  va_start(v, c);

  for(; c; c--) {
    x = va_arg(v, C_word);

    if((x & C_IMMEDIATE_TYPE_BITS) == C_CHARACTER_BITS)
      *(p++) = C_character_code(x);
    else break;
  }

  va_end(v);
  if (c) barf(C_BAD_ARGUMENT_TYPE_ERROR, "string", x);
  return s;
}


C_word C_a_i_record(C_word **ptr, int n, ...)
{
  va_list v;
  C_word *p = *ptr,
         *p0 = p; 

  *(p++) = C_STRUCTURE_TYPE | n;
  va_start(v, n);

  while(n--)
    *(p++) = va_arg(v, C_word);

  *ptr = p;
  va_end(v);
  return (C_word)p0;
}


C_word C_a_i_port(C_word **ptr, int n)
{
  C_word 
    *p = *ptr,
    *p0 = p; 
  int i;

  *(p++) = C_PORT_TYPE | (C_SIZEOF_PORT - 1);
  *(p++) = (C_word)NULL;
  
  for(i = 0; i < C_SIZEOF_PORT - 2; ++i)
    *(p++) = C_SCHEME_FALSE;

  *ptr = p;
  return (C_word)p0;
}


C_regparm C_word C_fcall C_a_i_bytevector(C_word **ptr, int c, C_word num)
{
  C_word *p = *ptr,
         *p0;
  int n = C_unfix(num);

#ifndef C_SIXTY_FOUR
  /* Align on 8-byte boundary: */
  if(C_aligned8(p)) ++p;
#endif

  p0 = p;
  *(p++) = C_BYTEVECTOR_TYPE | C_wordstobytes(n);
  *ptr = p + n;
  return (C_word)p0;
}


C_word C_fcall C_a_i_smart_mpointer(C_word **ptr, int c, C_word x)
{
  C_word 
    *p = *ptr,
    *p0 = p;
  void *mp;

  if(C_immediatep(x)) mp = NULL;
  else if((C_header_bits(x) & C_SPECIALBLOCK_BIT) != 0) mp = C_pointer_address(x);
  else mp = C_data_pointer(x);

  *(p++) = C_POINTER_TYPE | 1;
  *((void **)p) = mp;
  *ptr = p + 1;
  return (C_word)p0;
}

C_regparm C_word C_fcall C_i_nanp(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_SCHEME_FALSE;
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "nan?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_u_i_flonum_nanp(x);
  } else if (C_truep(C_bignump(x))) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    return C_mk_bool(C_truep(C_i_nanp(C_u_i_cplxnum_real(x))) ||
		     C_truep(C_i_nanp(C_u_i_cplxnum_imag(x))));
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "nan?", x);
  }
}

C_regparm C_word C_fcall C_i_finitep(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_SCHEME_TRUE;
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "finite?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_u_i_flonum_finitep(x);
  } else if (C_truep(C_bignump(x))) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    return C_and(C_i_finitep(C_u_i_cplxnum_real(x)),
		 C_i_finitep(C_u_i_cplxnum_imag(x)));
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "finite?", x);
  }
}

C_regparm C_word C_fcall C_i_infinitep(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_SCHEME_FALSE;
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "infinite?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_u_i_flonum_infinitep(x);
  } else if (C_truep(C_bignump(x))) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    return C_mk_bool(C_truep(C_i_infinitep(C_u_i_cplxnum_real(x))) ||
                     C_truep(C_i_infinitep(C_u_i_cplxnum_imag(x))));
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "infinite?", x);
  }
}

C_regparm C_word C_fcall C_i_exactp(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_SCHEME_TRUE;
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "exact?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_SCHEME_FALSE;
  } else if (C_truep(C_bignump(x))) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_SCHEME_TRUE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    return C_i_exactp(C_u_i_cplxnum_real(x)); /* Exactness of i and r matches */
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "exact?", x);
  }
}


C_regparm C_word C_fcall C_i_inexactp(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_SCHEME_FALSE;
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "inexact?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_SCHEME_TRUE;
  } else if (C_truep(C_bignump(x))) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_SCHEME_FALSE;
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    return C_i_inexactp(C_u_i_cplxnum_real(x)); /* Exactness of i and r matches */
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "inexact?", x);
  }
}


C_regparm C_word C_fcall C_i_zerop(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_mk_bool(x == C_fix(0));
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "zero?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_mk_bool(C_flonum_magnitude(x) == 0.0);
  } else if (C_block_header(x) == C_BIGNUM_TAG ||
             C_block_header(x) == C_RATNUM_TAG ||
             C_block_header(x) == C_CPLXNUM_TAG) {
    return C_SCHEME_FALSE;
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "zero?", x);
  }
}

/* DEPRECATED */
C_regparm C_word C_fcall C_u_i_zerop(C_word x)
{
  return C_mk_bool(x == C_fix(0) ||
                   (!C_immediatep(x) &&
                    C_block_header(x) == C_FLONUM_TAG &&
                    C_flonum_magnitude(x) == 0.0));
}


C_regparm C_word C_fcall C_i_positivep(C_word x)
{
  if (x & C_FIXNUM_BIT)
    return C_i_fixnum_positivep(x);
  else if (C_immediatep(x))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "positive?", x);
  else if (C_block_header(x) == C_FLONUM_TAG)
    return C_mk_bool(C_flonum_magnitude(x) > 0.0);
  else if (C_truep(C_bignump(x)))
    return C_mk_nbool(C_bignum_negativep(x));
  else if (C_block_header(x) == C_RATNUM_TAG)
    return C_i_integer_positivep(C_u_i_ratnum_num(x));
  else if (C_block_header(x) == C_CPLXNUM_TAG)
    barf(C_BAD_ARGUMENT_TYPE_NO_REAL_ERROR, "positive?", x);
  else
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "positive?", x);
}

C_regparm C_word C_fcall C_i_integer_positivep(C_word x)
{
  if (x & C_FIXNUM_BIT) return C_i_fixnum_positivep(x);
  else return C_mk_nbool(C_bignum_negativep(x));
}

C_regparm C_word C_fcall C_i_negativep(C_word x)
{
  if (x & C_FIXNUM_BIT)
    return C_i_fixnum_negativep(x);
  else if (C_immediatep(x))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "negative?", x);
  else if (C_block_header(x) == C_FLONUM_TAG)
    return C_mk_bool(C_flonum_magnitude(x) < 0.0);
  else if (C_truep(C_bignump(x)))
    return C_mk_bool(C_bignum_negativep(x));
  else if (C_block_header(x) == C_RATNUM_TAG)
    return C_i_integer_negativep(C_u_i_ratnum_num(x));
  else if (C_block_header(x) == C_CPLXNUM_TAG)
    barf(C_BAD_ARGUMENT_TYPE_NO_REAL_ERROR, "negative?", x);
  else
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "negative?", x);
}


C_regparm C_word C_fcall C_i_integer_negativep(C_word x)
{
  if (x & C_FIXNUM_BIT) return C_i_fixnum_negativep(x);
  else return C_mk_bool(C_bignum_negativep(x));
}


C_regparm C_word C_fcall C_i_evenp(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return C_i_fixnumevenp(x);
  } else if(C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "even?", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    double val, dummy;
    val = C_flonum_magnitude(x);
    if(C_isnan(val) || C_isinf(val) || C_modf(val, &dummy) != 0.0)
      barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "even?", x);
    else
      return C_mk_bool(fmod(val, 2.0) == 0.0);
  } else if (C_truep(C_bignump(x))) {
    return C_mk_nbool(C_bignum_digits(x)[0] & 1);
  } else { /* No need to try extended number */
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "even?", x);
  }
}

C_regparm C_word C_fcall C_i_integer_evenp(C_word x)
{
  if (x & C_FIXNUM_BIT) return C_i_fixnumevenp(x);
  return C_mk_nbool(C_bignum_digits(x)[0] & 1);
}


C_regparm C_word C_fcall C_i_oddp(C_word x)
{
  if(x & C_FIXNUM_BIT) {
    return C_i_fixnumoddp(x);
  } else if(C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "odd?", x);
  } else if(C_block_header(x) == C_FLONUM_TAG) {
    double val, dummy;
    val = C_flonum_magnitude(x);
    if(C_isnan(val) || C_isinf(val) || C_modf(val, &dummy) != 0.0)
      barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "odd?", x);
    else
      return C_mk_bool(fmod(val, 2.0) != 0.0);
  } else if (C_truep(C_bignump(x))) {
    return C_mk_bool(C_bignum_digits(x)[0] & 1);
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "odd?", x);
  }
}


C_regparm C_word C_fcall C_i_integer_oddp(C_word x)
{
  if (x & C_FIXNUM_BIT) return C_i_fixnumoddp(x);
  return C_mk_bool(C_bignum_digits(x)[0] & 1);
}


C_regparm C_word C_fcall C_i_car(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "car", x);

  return C_u_i_car(x);
}


C_regparm C_word C_fcall C_i_cdr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cdr", x);

  return C_u_i_cdr(x);
}


C_regparm C_word C_fcall C_i_caar(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "caar", x);
  }

  x = C_u_i_car(x);

  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_car(x);
}


C_regparm C_word C_fcall C_i_cadr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cadr", x);
  }

  x = C_u_i_cdr(x);

  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_car(x);
}


C_regparm C_word C_fcall C_i_cdar(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cdar", x);
  }

  x = C_u_i_car(x);

  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_cdr(x);
}


C_regparm C_word C_fcall C_i_cddr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cddr", x);
  }

  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_cdr(x);
}


C_regparm C_word C_fcall C_i_caddr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "caddr", x);
  }

  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;
  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_car(x);
}


C_regparm C_word C_fcall C_i_cdddr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cdddr", x);
  }

  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;
  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_cdr(x);
}


C_regparm C_word C_fcall C_i_cadddr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cadddr", x);
  }

  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;
  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;
  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_car(x);
}


C_regparm C_word C_fcall C_i_cddddr(C_word x)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
  bad:
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "cddddr", x);
  }

  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;
  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;
  x = C_u_i_cdr(x);
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) goto bad;

  return C_u_i_cdr(x);
}


C_regparm C_word C_fcall C_i_list_tail(C_word lst, C_word i)
{
  C_word lst0 = lst;
  int n;

  if(lst != C_SCHEME_END_OF_LIST && 
     (C_immediatep(lst) || C_header_type(lst) != C_PAIR_TYPE))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "list-tail", lst);

  if(i & C_FIXNUM_BIT) n = C_unfix(i);
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "list-tail", i);

  while(n--) {
    if(C_immediatep(lst) || C_header_type(lst) != C_PAIR_TYPE)
      barf(C_OUT_OF_RANGE_ERROR, "list-tail", lst0, i);
    
    lst = C_u_i_cdr(lst);
  }

  return lst;
}


C_regparm C_word C_fcall C_i_vector_ref(C_word v, C_word i)
{
  int j;

  if(C_immediatep(v) || C_header_bits(v) != C_VECTOR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(v)) barf(C_OUT_OF_RANGE_ERROR, "vector-ref", v, i);

    return C_block_item(v, j);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "vector-ref", i);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_u8vector_ref(C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_u8vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u8vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(C_block_item(v, 1))) barf(C_OUT_OF_RANGE_ERROR, "u8vector-ref", v, i);

    return C_fix(((unsigned char *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "u8vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_s8vector_ref(C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_s8vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(C_block_item(v, 1))) barf(C_OUT_OF_RANGE_ERROR, "s8vector-ref", v, i);

    return C_fix(((signed char *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_u16vector_ref(C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_u16vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u16vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 1)) barf(C_OUT_OF_RANGE_ERROR, "u16vector-ref", v, i);

    return C_fix(((unsigned short *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "u16vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_s16vector_ref(C_word v, C_word i)
{
  C_word size;
  int j;

  if(C_immediatep(v) || C_header_bits(v) != C_STRUCTURE_TYPE ||
     C_header_size(v) != 2 || C_block_item(v, 0) != s16vector_symbol)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s16vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 1)) barf(C_OUT_OF_RANGE_ERROR, "u16vector-ref", v, i);

    return C_fix(((signed short *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "s16vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_a_i_u32vector_ref(C_word **ptr, C_word c, C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_u32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u32vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 2)) barf(C_OUT_OF_RANGE_ERROR, "u32vector-ref", v, i);

    return C_unsigned_int_to_num(ptr, ((C_u32 *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "u32vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_a_i_s32vector_ref(C_word **ptr, C_word c, C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_s32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s32vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 2)) barf(C_OUT_OF_RANGE_ERROR, "s32vector-ref", v, i);

    return C_int_to_num(ptr, ((C_s32 *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "s32vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_a_i_u64vector_ref(C_word **ptr, C_word c, C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_u64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u64vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 3)) barf(C_OUT_OF_RANGE_ERROR, "u64vector-ref", v, i);

    return C_uint64_to_num(ptr, ((C_u64 *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "u64vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_a_i_s64vector_ref(C_word **ptr, C_word c, C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_s64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s64vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 3)) barf(C_OUT_OF_RANGE_ERROR, "s64vector-ref", v, i);

    return C_int64_to_num(ptr, ((C_s64 *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "s64vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_a_i_f32vector_ref(C_word **ptr, C_word c, C_word v, C_word i)
{
  int j;

  if(!C_truep(C_i_f32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "f32vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 2)) barf(C_OUT_OF_RANGE_ERROR, "f32vector-ref", v, i);

    return C_flonum(ptr, ((float *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "f32vector-ref", i);
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_a_i_f64vector_ref(C_word **ptr, C_word c, C_word v, C_word i)
{
  C_word size;
  int j;

  if(!C_truep(C_i_f64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "f64vector-ref", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 3)) barf(C_OUT_OF_RANGE_ERROR, "f64vector-ref", v, i);

    return C_flonum(ptr, ((double *)C_data_pointer(C_block_item(v, 1)))[j]);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "f64vector-ref", i);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_block_ref(C_word x, C_word i)
{
  int j;

  if(C_immediatep(x) || (C_header_bits(x) & C_BYTEBLOCK_BIT) != 0)
    barf(C_BAD_ARGUMENT_TYPE_NO_BLOCK_ERROR, "##sys#block-ref", x);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(x)) barf(C_OUT_OF_RANGE_ERROR, "##sys#block-ref", x, i);

    return C_block_item(x, j);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "##sys#block-ref", i);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_string_set(C_word s, C_word i, C_word c)
{
  int j;

  if(C_immediatep(s) || C_header_bits(s) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-set!", s);

  if(!C_immediatep(c) || (c & C_IMMEDIATE_TYPE_BITS) != C_CHARACTER_BITS)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-set!", c);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(s)) barf(C_OUT_OF_RANGE_ERROR, "string-set!", s, i);

    return C_setsubchar(s, i, c);
  }

  barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-set!", i);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_string_ref(C_word s, C_word i)
{
  int j;

  if(C_immediatep(s) || C_header_bits(s) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-ref", s);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(s)) barf(C_OUT_OF_RANGE_ERROR, "string-ref", s, i);

    return C_subchar(s, i);
  }
  
  barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-ref", i);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_vector_length(C_word v)
{
  if(C_immediatep(v) || C_header_bits(v) != C_VECTOR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "vector-length", v);

  return C_fix(C_header_size(v));
}

C_regparm C_word C_fcall C_i_u8vector_length(C_word v)
{
  if(!C_truep(C_i_u8vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u8vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)));
}

C_regparm C_word C_fcall C_i_s8vector_length(C_word v)
{
  if(!C_truep(C_i_s8vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)));
}

C_regparm C_word C_fcall C_i_u16vector_length(C_word v)
{
  if(!C_truep(C_i_u16vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u16vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 1);
}

C_regparm C_word C_fcall C_i_s16vector_length(C_word v)
{
  if(!C_truep(C_i_s16vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s16vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 1);
}

C_regparm C_word C_fcall C_i_u32vector_length(C_word v)
{
  if(!C_truep(C_i_u32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u32vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 2);
}

C_regparm C_word C_fcall C_i_s32vector_length(C_word v)
{
  if(!C_truep(C_i_s32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s32vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 2);
}

C_regparm C_word C_fcall C_i_u64vector_length(C_word v)
{
  if(!C_truep(C_i_u64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u64vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 3);
}

C_regparm C_word C_fcall C_i_s64vector_length(C_word v)
{
  if(!C_truep(C_i_s64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s64vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 3);
}


C_regparm C_word C_fcall C_i_f32vector_length(C_word v)
{
  if(!C_truep(C_i_f32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "f32vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 2);
}

C_regparm C_word C_fcall C_i_f64vector_length(C_word v)
{
  if(!C_truep(C_i_f64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "f64vector-length", v);

  return C_fix(C_header_size(C_block_item(v, 1)) >> 3);
}


C_regparm C_word C_fcall C_i_string_length(C_word s)
{
  if(C_immediatep(s) || C_header_bits(s) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string-length", s);

  return C_fix(C_header_size(s));
}


C_regparm C_word C_fcall C_i_length(C_word lst)
{
  C_word fast = lst, slow = lst;
  int n = 0;

  while(slow != C_SCHEME_END_OF_LIST) {
    if(fast != C_SCHEME_END_OF_LIST) {
      if(!C_immediatep(fast) && C_header_type(fast) == C_PAIR_TYPE) {
	fast = C_u_i_cdr(fast);
      
	if(fast != C_SCHEME_END_OF_LIST) {
	  if(!C_immediatep(fast) && C_header_type(fast) == C_PAIR_TYPE) {
	    fast = C_u_i_cdr(fast);
	  }
	  else barf(C_NOT_A_PROPER_LIST_ERROR, "length", lst);
	}

	if(fast == slow) 
	  barf(C_BAD_ARGUMENT_TYPE_CYCLIC_LIST_ERROR, "length", lst);
      }
    }

    if(C_immediatep(slow) || C_header_type(slow) != C_PAIR_TYPE)
      barf(C_NOT_A_PROPER_LIST_ERROR, "length", lst);

    slow = C_u_i_cdr(slow);
    ++n;
  }

  return C_fix(n);
}


C_regparm C_word C_fcall C_u_i_length(C_word lst)
{
  int n = 0;

  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    lst = C_u_i_cdr(lst);
    ++n;
  }

  return C_fix(n);
}

C_regparm C_word C_fcall C_i_set_car(C_word x, C_word val)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "set-car!", x);

  C_mutate(&C_u_i_car(x), val);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_set_cdr(C_word x, C_word val)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "set-cdr!", x);

  C_mutate(&C_u_i_cdr(x), val);
  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_vector_set(C_word v, C_word i, C_word x)
{
  int j;

  if(C_immediatep(v) || C_header_bits(v) != C_VECTOR_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(v)) barf(C_OUT_OF_RANGE_ERROR, "vector-set!", v, i);

    C_mutate(&C_block_item(v, j), x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "vector-set!", i);

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_u8vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_word n;

  if(!C_truep(C_i_u8vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u8vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(C_block_item(v, 1))) barf(C_OUT_OF_RANGE_ERROR, "u8vector-set!", v, i);

    if(x & C_FIXNUM_BIT) {
      if (!(x & C_INT_SIGN_BIT) && C_ilen(C_unfix(x)) <= 8) n = C_unfix(x);
      else barf(C_OUT_OF_RANGE_ERROR, "u8vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u8vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u8vector-set!", i);

  ((unsigned char *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_s8vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_word n;

  if(!C_truep(C_i_s8vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= C_header_size(C_block_item(v, 1))) barf(C_OUT_OF_RANGE_ERROR, "s8vector-set!", v, i);

    if(x & C_FIXNUM_BIT) {
      if (C_unfix(C_i_fixnum_length(x)) <= 8) n = C_unfix(x);
      else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s8vector-set!", i);

  ((signed char *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_u16vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_word n;

  if(!C_truep(C_i_u16vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u16vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 1)) barf(C_OUT_OF_RANGE_ERROR, "u16vector-set!", v, i);

    if(x & C_FIXNUM_BIT) {
      if (!(x & C_INT_SIGN_BIT) && C_ilen(C_unfix(x)) <= 16) n = C_unfix(x);
      else barf(C_OUT_OF_RANGE_ERROR, "u16vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u16vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u16vector-set!", i);

  ((unsigned short *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_s16vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_word n;

  if(!C_truep(C_i_s16vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s16vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 1)) barf(C_OUT_OF_RANGE_ERROR, "u16vector-set!", v, i);

    if(x & C_FIXNUM_BIT) {
      if (C_unfix(C_i_fixnum_length(x)) <= 16) n = C_unfix(x);
      else barf(C_OUT_OF_RANGE_ERROR, "s16vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s16vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s16vector-set!", i);

  ((short *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_u32vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_u32 n;

  if(!C_truep(C_i_u32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u32vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 2)) barf(C_OUT_OF_RANGE_ERROR, "u32vector-set!", v, i);

    if(C_truep(C_i_exact_integerp(x))) {
      if (C_unfix(C_i_integer_length(x)) <= 32) n = C_num_to_unsigned_int(x);
      else barf(C_OUT_OF_RANGE_ERROR, "u32vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u32vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u32vector-set!", i);

  ((C_u32 *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_s32vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_s32 n;

  if(!C_truep(C_i_s32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s32vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 2)) barf(C_OUT_OF_RANGE_ERROR, "s32vector-set!", v, i);

    if(C_truep(C_i_exact_integerp(x))) {
      if (C_unfix(C_i_integer_length(x)) <= 32) n = C_num_to_int(x);
      else barf(C_OUT_OF_RANGE_ERROR, "s32vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s32vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s32vector-set!", i);

  ((C_s32 *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_u64vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_u64 n;

  if(!C_truep(C_i_u64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "u64vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 3)) barf(C_OUT_OF_RANGE_ERROR, "u64vector-set!", v, i);

    if(C_truep(C_i_exact_integerp(x))) {
      if (C_unfix(C_i_integer_length(x)) <= 64) n = C_num_to_uint64(x);
      else barf(C_OUT_OF_RANGE_ERROR, "u64vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u64vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "u64vector-set!", i);

  ((C_u64 *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_s64vector_set(C_word v, C_word i, C_word x)
{
  int j;
  C_s64 n;

  if(!C_truep(C_i_s64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "s64vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 3)) barf(C_OUT_OF_RANGE_ERROR, "s64vector-set!", v, i);

    if(C_truep(C_i_exact_integerp(x))) {
      if (C_unfix(C_i_integer_length(x)) <= 64) n = C_num_to_int64(x);
      else barf(C_OUT_OF_RANGE_ERROR, "s64vector-set!", x);
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s64vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "s64vector-set!", i);

  ((C_s64 *)C_data_pointer(C_block_item(v, 1)))[j] = n;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_f32vector_set(C_word v, C_word i, C_word x)
{
  int j;
  double f;

  if(!C_truep(C_i_f32vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "f32vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 2)) barf(C_OUT_OF_RANGE_ERROR, "f32vector-set!", v, i);

    if(C_truep(C_i_flonump(x))) f = C_flonum_magnitude(x);
    else if(x & C_FIXNUM_BIT) f = C_unfix(x);
    else if (C_truep(C_i_bignump(x))) f = C_bignum_to_double(x);
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "f32vector-set!", x);
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "f32vector-set!", i);

  ((float *)C_data_pointer(C_block_item(v, 1)))[j] = (float)f;
  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_f64vector_set(C_word v, C_word i, C_word x)
{
  int j;
  double f;

  if(!C_truep(C_i_f64vectorp(v)))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "f64vector-set!", v);

  if(i & C_FIXNUM_BIT) {
    j = C_unfix(i);

    if(j < 0 || j >= (C_header_size(C_block_item(v, 1)) >> 3)) barf(C_OUT_OF_RANGE_ERROR, "f64vector-set!", v, i);

    if(C_truep(C_i_flonump(x))) f = C_flonum_magnitude(x);
    else if(x & C_FIXNUM_BIT) f = C_unfix(x);
    else if (C_truep(C_i_bignump(x))) f = C_bignum_to_double(x);
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "f64vector-set!", x);

  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "f64vector-set!", i);

  ((double *)C_data_pointer(C_block_item(v, 1)))[j] = f;
  return C_SCHEME_UNDEFINED;
}


/* This needs at most C_SIZEOF_FIX_BIGNUM + max(C_SIZEOF_RATNUM, C_SIZEOF_CPLXNUM) so 7 words */
C_regparm C_word C_fcall
C_s_a_i_abs(C_word **ptr, C_word n, C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_a_i_fixnum_abs(ptr, 1, x);
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "abs", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_a_i_flonum_abs(ptr, 1, x);
  } else if (C_truep(C_bignump(x))) {
    return C_s_a_u_i_integer_abs(ptr, 1, x);
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_ratnum(ptr, C_s_a_u_i_integer_abs(ptr, 1, C_u_i_ratnum_num(x)),
                    C_u_i_ratnum_denom(x));
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    barf(C_BAD_ARGUMENT_TYPE_COMPLEX_ABS, "abs", x);
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "abs", x);
  }
}

void C_ccall C_signum(C_word c, C_word *av)
{
  C_word k = av[ 1 ], x, y;

  if (c != 3) C_bad_argc_2(c, 3, av[ 0 ]);

  x = av[ 2 ];
  y = av[ 3 ];

  if (x & C_FIXNUM_BIT) {
    C_kontinue(k, C_i_fixnum_signum(x));
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "signum", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    C_word *a = C_alloc(C_SIZEOF_FLONUM);
    C_kontinue(k, C_a_u_i_flonum_signum(&a, 1, x));
  } else if (C_truep(C_bignump(x))) {
    C_kontinue(k, C_bignum_negativep(x) ? C_fix(-1) : C_fix(1));
  } else {
    try_extended_number("##sys#extended-signum", 2, k, x);
  }
}


/* The maximum this can allocate is a cplxnum which consists of two
 * ratnums that consist of 2 fix bignums each.  So that's
 * C_SIZEOF_CPLXNUM + C_SIZEOF_RATNUM * 2 + C_SIZEOF_FIX_BIGNUM * 4 = 29 words!
 */
C_regparm C_word C_fcall
C_s_a_i_negate(C_word **ptr, C_word n, C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_a_i_fixnum_negate(ptr, 1, x);
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    return C_a_i_flonum_negate(ptr, 1, x);
  } else if (C_truep(C_bignump(x))) {
    return C_s_a_u_i_integer_negate(ptr, 1, x);
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    return C_ratnum(ptr, C_s_a_u_i_integer_negate(ptr, 1, C_u_i_ratnum_num(x)),
                    C_u_i_ratnum_denom(x));
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    return C_cplxnum(ptr, C_s_a_i_negate(ptr, 1, C_u_i_cplxnum_real(x)),
                     C_s_a_i_negate(ptr, 1, C_u_i_cplxnum_imag(x)));
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", x);
  }
}

/* Copy all the digits from source to target, obliterating what was
 * there.  If target is larger than source, the most significant
 * digits will remain untouched.
 */
inline static void bignum_digits_destructive_copy(C_word target, C_word source)
{
  C_memcpy(C_bignum_digits(target), C_bignum_digits(source),
           C_wordstobytes(C_bignum_size(source)));
}

C_regparm C_word C_fcall
C_s_a_u_i_integer_negate(C_word **ptr, C_word n, C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_a_i_fixnum_negate(ptr, 1, x);
  } else {
    if (C_bignum_negated_fitsinfixnump(x)) {
      return C_fix(C_MOST_NEGATIVE_FIXNUM);
    } else {
      C_word res, negp = C_mk_nbool(C_bignum_negativep(x)),
             size = C_fix(C_bignum_size(x));
      res = C_allocate_scratch_bignum(ptr, size, negp, C_SCHEME_FALSE);
      bignum_digits_destructive_copy(res, x);
      return C_bignum_simplify(res);
    }
  }
}


/* Faster version that ignores sign */
inline static int integer_length_abs(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_ilen(C_wabs(C_unfix(x)));
  } else {
    C_uword result = (C_bignum_size(x) - 1) * C_BIGNUM_DIGIT_LENGTH,
            *last_digit = C_bignum_digits(x) + C_bignum_size(x) - 1,
            last_digit_length = C_ilen(*last_digit);
    return result + last_digit_length;
  }
}

C_regparm C_word C_fcall C_i_integer_length(C_word x)
{
  if (x & C_FIXNUM_BIT) {
    return C_i_fixnum_length(x);
  } else if (C_truep(C_i_bignump(x))) {
    C_uword result = (C_bignum_size(x) - 1) * C_BIGNUM_DIGIT_LENGTH,
            *last_digit = C_bignum_digits(x) + C_bignum_size(x) - 1,
            last_digit_length = C_ilen(*last_digit);

    /* If *only* the highest bit is set, negating will give one less bit */
    if (C_bignum_negativep(x) &&
        *last_digit == ((C_uword)1 << (last_digit_length-1))) {
      C_uword *startx = C_bignum_digits(x);
      while (startx < last_digit && *startx == 0) ++startx;
      if (startx == last_digit) result--;
    }
    return C_fix(result + last_digit_length);
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "integer-length", x);
  }
}

/* This is currently only used by Karatsuba multiplication and
 * Burnikel-Ziegler division. */
static C_regparm C_word
bignum_extract_digits(C_word **ptr, C_word n, C_word x, C_word start, C_word end)
{
  if (x & C_FIXNUM_BIT) { /* Needed? */
    if (C_unfix(start) == 0 && (end == C_SCHEME_FALSE || C_unfix(end) > 0))
      return x;
    else
      return C_fix(0);
  } else {
    C_word negp, size;

    negp = C_mk_bool(C_bignum_negativep(x)); /* Always false */

    start = C_unfix(start);
    /* We might get passed larger values than actually fits; pad w/ zeroes */
    if (end == C_SCHEME_FALSE) end = C_bignum_size(x);
    else end = nmin(C_unfix(end), C_bignum_size(x));
    assert(start >= 0);

    size = end - start;

    if (size == 0 || start >= C_bignum_size(x)) {
      return C_fix(0);
    } else {
      C_uword res, *res_digits, *x_digits;
      res = C_allocate_scratch_bignum(ptr, C_fix(size), negp, C_SCHEME_FALSE);
      res_digits = C_bignum_digits(res);
      x_digits = C_bignum_digits(x);
      /* Can't use bignum_digits_destructive_copy because that assumes
       * target is at least as big as source.
       */
      C_memcpy(res_digits, x_digits + start, C_wordstobytes(end - start));
      return C_bignum_simplify(res);
    }
  }
}

/* This returns a tmp bignum negated copy of X (must be freed!) when
 * the number is negative, or #f if it doesn't need to be negated.
 * The size can be larger or smaller than X (it may be 1-padded).
 */
inline static C_word maybe_negate_bignum_for_bitwise_op(C_word x, C_word size)
{
  C_word nx = C_SCHEME_FALSE, xsize;
  if (C_bignum_negativep(x)) {
    nx = allocate_tmp_bignum(C_fix(size), C_SCHEME_FALSE, C_SCHEME_FALSE);
    xsize = C_bignum_size(x);
    /* Copy up until requested size, and init any remaining upper digits */
    C_memcpy(C_bignum_digits(nx), C_bignum_digits(x),
             C_wordstobytes(nmin(size, xsize)));
    if (size > xsize)
      C_memset(C_bignum_digits(nx)+xsize, 0, C_wordstobytes(size-xsize));
    bignum_digits_destructive_negate(nx);
  }
  return nx;
}

/* DEPRECATED */
C_regparm C_word C_fcall C_i_bit_to_bool(C_word n, C_word i)
{
  if (!C_truep(C_i_exact_integerp(n))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bit->boolean", n);
  } else if (!(i & C_FIXNUM_BIT)) {
    if (!C_immediatep(i) && C_truep(C_bignump(i)) && !C_bignum_negativep(i)) {
      return C_i_integer_negativep(n); /* A bit silly, but strictly correct */
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR, "bit->boolean", i);
    }
  } else if (i & C_INT_SIGN_BIT) {
    barf(C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR, "bit->boolean", i);
  } else {
    i = C_unfix(i);
    if (n & C_FIXNUM_BIT) {
      if (i >= C_WORD_SIZE) return C_mk_bool(n & C_INT_SIGN_BIT);
      else return C_mk_bool((C_unfix(n) & ((C_word)1 << i)) != 0);
    } else {
      C_word nn, d;
      d = i / C_BIGNUM_DIGIT_LENGTH;
      if (d >= C_bignum_size(n)) return C_mk_bool(C_bignum_negativep(n));

      /* TODO: this isn't necessary, is it? */
      if (C_truep(nn = maybe_negate_bignum_for_bitwise_op(n, d))) n = nn;

      i %= C_BIGNUM_DIGIT_LENGTH;
      d = C_mk_bool((C_bignum_digits(n)[d] & (C_uword)1 << i) != 0);
      if (C_truep(nn)) free_tmp_bignum(nn);
      return d;
    }
  }
}

C_regparm C_word C_fcall
C_s_a_i_bitwise_and(C_word **ptr, C_word n, C_word x, C_word y)
{
  if ((x & y) & C_FIXNUM_BIT) {
    return C_u_fixnum_and(x, y);
  } else if (!C_truep(C_i_exact_integerp(x))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-and", x);
  } else if (!C_truep(C_i_exact_integerp(y))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-and", y);
  } else {
    C_word ab[C_SIZEOF_FIX_BIGNUM*2], *a = ab, negp, size, res, nx, ny;
    C_uword *scanr, *endr, *scans1, *ends1, *scans2;

    if (x & C_FIXNUM_BIT) x = C_a_u_i_fix_to_big(&a, x);
    if (y & C_FIXNUM_BIT) y = C_a_u_i_fix_to_big(&a, y);

    negp = C_mk_bool(C_bignum_negativep(x) && C_bignum_negativep(y));
    /* Allow negative 1-bits to propagate */
    if (C_bignum_negativep(x) || C_bignum_negativep(y))
      size = nmax(C_bignum_size(x), C_bignum_size(y)) + 1;
    else
      size = nmin(C_bignum_size(x), C_bignum_size(y));

    res = C_allocate_scratch_bignum(ptr, C_fix(size), negp, C_SCHEME_FALSE);
    scanr = C_bignum_digits(res);
    endr = scanr + C_bignum_size(res);
    
    if (C_truep(nx = maybe_negate_bignum_for_bitwise_op(x, size))) x = nx;
    if (C_truep(ny = maybe_negate_bignum_for_bitwise_op(y, size))) y = ny;

    if (C_bignum_size(x) < C_bignum_size(y)) {
      scans1 = C_bignum_digits(x); ends1 = scans1 + C_bignum_size(x);
      scans2 = C_bignum_digits(y);
    } else {
      scans1 = C_bignum_digits(y); ends1 = scans1 + C_bignum_size(y);
      scans2 = C_bignum_digits(x);
    }

    while (scans1 < ends1) *scanr++ = *scans1++ & *scans2++;
    C_memset(scanr, 0, C_wordstobytes(endr - scanr));

    if (C_truep(nx)) free_tmp_bignum(nx);
    if (C_truep(ny)) free_tmp_bignum(ny);
    if (C_bignum_negativep(res)) bignum_digits_destructive_negate(res);
    
    return C_bignum_simplify(res);
  }
}

void C_ccall C_bitwise_and(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word next_val, result, prev_result;
  C_word ab[2][C_SIZEOF_BIGNUM_WRAPPER], *a;

  c -= 2; 
  av += 2;

  if (c == 0) C_kontinue(k, C_fix(-1));

  prev_result = result = *(av++);

  if (c-- == 1 && !C_truep(C_i_exact_integerp(result)))
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-and", result);

  while (c--) {
    next_val = *(av++);
    a = ab[c&1]; /* One may hold last iteration result, the other is unused */
    result = C_s_a_i_bitwise_and(&a, 2, result, next_val);
    result = move_buffer_object(&a, ab[(c+1)&1], result);
    clear_buffer_object(ab[(c+1)&1], prev_result);
    prev_result = result;
  }

  C_kontinue(k, result);
}

C_regparm C_word C_fcall
C_s_a_i_bitwise_ior(C_word **ptr, C_word n, C_word x, C_word y)
{
  if ((x & y) & C_FIXNUM_BIT) {
    return C_u_fixnum_or(x, y);
  } else if (!C_truep(C_i_exact_integerp(x))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-ior", x);
  } else if (!C_truep(C_i_exact_integerp(y))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-ior", y);
  } else {
    C_word ab[C_SIZEOF_FIX_BIGNUM*2], *a = ab, negp, size, res, nx, ny;
    C_uword *scanr, *endr, *scans1, *ends1, *scans2, *ends2;

    if (x & C_FIXNUM_BIT) x = C_a_u_i_fix_to_big(&a, x);
    if (y & C_FIXNUM_BIT) y = C_a_u_i_fix_to_big(&a, y);

    negp = C_mk_bool(C_bignum_negativep(x) || C_bignum_negativep(y));
    size = nmax(C_bignum_size(x), C_bignum_size(y)) + 1;
    res = C_allocate_scratch_bignum(ptr, C_fix(size), negp, C_SCHEME_FALSE);
    scanr = C_bignum_digits(res);
    endr = scanr + C_bignum_size(res);
    
    if (C_truep(nx = maybe_negate_bignum_for_bitwise_op(x, size))) x = nx;
    if (C_truep(ny = maybe_negate_bignum_for_bitwise_op(y, size))) y = ny;

    if (C_bignum_size(x) < C_bignum_size(y)) {
      scans1 = C_bignum_digits(x); ends1 = scans1 + C_bignum_size(x);
      scans2 = C_bignum_digits(y); ends2 = scans2 + C_bignum_size(y);
    } else {
      scans1 = C_bignum_digits(y); ends1 = scans1 + C_bignum_size(y);
      scans2 = C_bignum_digits(x); ends2 = scans2 + C_bignum_size(x);
    }

    while (scans1 < ends1) *scanr++ = *scans1++ | *scans2++;
    while (scans2 < ends2) *scanr++ = *scans2++;
    if (scanr < endr) *scanr++ = 0; /* Only done when result is positive */
    assert(scanr == endr);

    if (C_truep(nx)) free_tmp_bignum(nx);
    if (C_truep(ny)) free_tmp_bignum(ny);
    if (C_bignum_negativep(res)) bignum_digits_destructive_negate(res);

    return C_bignum_simplify(res);
  }
}

void C_ccall C_bitwise_ior(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word next_val, result, prev_result;
  C_word ab[2][C_SIZEOF_BIGNUM_WRAPPER], *a;

  c -= 2; 
  av += 2;

  if (c == 0) C_kontinue(k, C_fix(0));

  prev_result = result = *(av++);

  if (c-- == 1 && !C_truep(C_i_exact_integerp(result)))
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-ior", result);

  while (c--) {
    next_val = *(av++);
    a = ab[c&1]; /* One may hold prev iteration result, the other is unused */
    result = C_s_a_i_bitwise_ior(&a, 2, result, next_val);
    result = move_buffer_object(&a, ab[(c+1)&1], result);
    clear_buffer_object(ab[(c+1)&1], prev_result);
    prev_result = result;
  }

  C_kontinue(k, result);
}

C_regparm C_word C_fcall
C_s_a_i_bitwise_xor(C_word **ptr, C_word n, C_word x, C_word y)
{
  if ((x & y) & C_FIXNUM_BIT) {
    return C_fixnum_xor(x, y);
  } else if (!C_truep(C_i_exact_integerp(x))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-xor", x);
  } else if (!C_truep(C_i_exact_integerp(y))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-xor", y);
  } else {
    C_word ab[C_SIZEOF_FIX_BIGNUM*2], *a = ab, negp, size, res, nx, ny;
    C_uword *scanr, *endr, *scans1, *ends1, *scans2, *ends2;

    if (x & C_FIXNUM_BIT) x = C_a_u_i_fix_to_big(&a, x);
    if (y & C_FIXNUM_BIT) y = C_a_u_i_fix_to_big(&a, y);

    size = nmax(C_bignum_size(x), C_bignum_size(y)) + 1;
    negp = C_mk_bool(C_bignum_negativep(x) != C_bignum_negativep(y));
    res = C_allocate_scratch_bignum(ptr, C_fix(size), negp, C_SCHEME_FALSE);
    scanr = C_bignum_digits(res);
    endr = scanr + C_bignum_size(res);

    if (C_truep(nx = maybe_negate_bignum_for_bitwise_op(x, size))) x = nx;
    if (C_truep(ny = maybe_negate_bignum_for_bitwise_op(y, size))) y = ny;

    if (C_bignum_size(x) < C_bignum_size(y)) {
      scans1 = C_bignum_digits(x); ends1 = scans1 + C_bignum_size(x);
      scans2 = C_bignum_digits(y); ends2 = scans2 + C_bignum_size(y);
    } else {
      scans1 = C_bignum_digits(y); ends1 = scans1 + C_bignum_size(y);
      scans2 = C_bignum_digits(x); ends2 = scans2 + C_bignum_size(x);
    }

    while (scans1 < ends1) *scanr++ = *scans1++ ^ *scans2++;
    while (scans2 < ends2) *scanr++ = *scans2++;
    if (scanr < endr) *scanr++ = 0; /* Only done when result is positive */
    assert(scanr == endr);

    if (C_truep(nx)) free_tmp_bignum(nx);
    if (C_truep(ny)) free_tmp_bignum(ny);
    if (C_bignum_negativep(res)) bignum_digits_destructive_negate(res);

    return C_bignum_simplify(res);
  }
}

void C_ccall C_bitwise_xor(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word next_val, result, prev_result;
  C_word ab[2][C_SIZEOF_BIGNUM_WRAPPER], *a;

  c -= 2; 
  av += 2;

  if (c == 0) C_kontinue(k, C_fix(0));

  prev_result = result = *(av++);

  if (c-- == 1 && !C_truep(C_i_exact_integerp(result)))
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-xor", result);

  while (c--) {
    next_val = *(av++);
    a = ab[c&1]; /* One may hold prev iteration result, the other is unused */
    result = C_s_a_i_bitwise_xor(&a, 2, result, next_val);
    result = move_buffer_object(&a, ab[(c+1)&1], result);
    clear_buffer_object(ab[(c+1)&1], prev_result);
    prev_result = result;
  }

  C_kontinue(k, result);
}

C_regparm C_word C_fcall
C_s_a_i_bitwise_not(C_word **ptr, C_word n, C_word x)
{
  if (!C_truep(C_i_exact_integerp(x))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "bitwise-not", x);
  } else {
    return C_s_a_u_i_integer_minus(ptr, 2, C_fix(-1), x);
  }
}

C_regparm C_word C_fcall
C_s_a_i_arithmetic_shift(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab, size, negp, res,
         digit_offset, bit_offset;

  if (!(y & C_FIXNUM_BIT))
    barf(C_BAD_ARGUMENT_TYPE_NO_FIXNUM_ERROR, "arithmetic-shift", y);

  y = C_unfix(y);
  if (y == 0 || x == C_fix(0)) { /* Done (no shift) */
    return x;
  } else if (x & C_FIXNUM_BIT) {
    if (y < 0) {
      /* Don't shift more than a word's length (that's undefined in C!) */
      if (-y < C_WORD_SIZE) {
        return C_fix(C_unfix(x) >> -y);
      } else {
        return (x < 0) ? C_fix(-1) : C_fix(0);
      }
    } else if (y > 0 && y < C_WORD_SIZE-2 &&
               /* After shifting, the length still fits a fixnum */
               (C_ilen(C_unfix(x)) + y) < C_WORD_SIZE-2) {
      return C_fix((C_uword)C_unfix(x) << y);
    } else {
      x = C_a_u_i_fix_to_big(&a, x);
    }
  } else if (!C_truep(C_i_bignump(x))) {
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_INTEGER_ERROR, "arithmetic-shift", x);
  }

  negp = C_mk_bool(C_bignum_negativep(x));
  
  if (y > 0) {                  /* Shift left */
    C_uword *startr, *startx, *endx, *endr;

    digit_offset = y / C_BIGNUM_DIGIT_LENGTH;
    bit_offset =   y % C_BIGNUM_DIGIT_LENGTH;

    size = C_fix(C_bignum_size(x) + digit_offset + 1);
    res = C_allocate_scratch_bignum(ptr, size, negp, C_SCHEME_FALSE);

    startr = C_bignum_digits(res);
    endr = startr + C_bignum_size(res);

    startx = C_bignum_digits(x);
    endx = startx + C_bignum_size(x);

    /* Initialize only the lower digits we're skipping and the MSD */
    C_memset(startr, 0, C_wordstobytes(digit_offset));
    *(endr-1) = 0;
    startr += digit_offset;
    /* Can't use bignum_digits_destructive_copy because it assumes
     * we want to copy from the start.
     */
    C_memcpy(startr, startx, C_wordstobytes(endx-startx));
    if(bit_offset > 0)
      bignum_digits_destructive_shift_left(startr, endr, bit_offset);

    return C_bignum_simplify(res);
  } else if (-y >= C_bignum_size(x) * (C_word)C_BIGNUM_DIGIT_LENGTH) {
    /* All bits are shifted out, just return 0 or -1 */
    return C_truep(negp) ? C_fix(-1) : C_fix(0);
  } else {                      /* Shift right */
    C_uword *startr, *startx, *endr;
    C_word nx;

    digit_offset = -y / C_BIGNUM_DIGIT_LENGTH;
    bit_offset =   -y % C_BIGNUM_DIGIT_LENGTH;

    size = C_fix(C_bignum_size(x) - digit_offset);
    res = C_allocate_scratch_bignum(ptr, size, negp, C_SCHEME_FALSE);

    startr = C_bignum_digits(res);
    endr = startr + C_bignum_size(res);

    size = C_bignum_size(x) + 1;
    if (C_truep(nx = maybe_negate_bignum_for_bitwise_op(x, size))) {
      startx = C_bignum_digits(nx) + digit_offset;
    } else {
      startx = C_bignum_digits(x) + digit_offset;
    }
    /* Can't use bignum_digits_destructive_copy because that assumes
     * target is at least as big as source.
     */
    C_memcpy(startr, startx, C_wordstobytes(endr-startr));
    if(bit_offset > 0)
      bignum_digits_destructive_shift_right(startr,endr,bit_offset,C_truep(nx));

    if (C_truep(nx)) {
      free_tmp_bignum(nx);
      bignum_digits_destructive_negate(res);
    }
    return C_bignum_simplify(res);
  }
}


C_regparm C_word C_fcall C_a_i_exp(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "exp", f);
  return C_flonum(a, C_exp(f));
}


C_regparm C_word C_fcall C_a_i_log(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "log", f);
  return C_flonum(a, C_log(f));
}


C_regparm C_word C_fcall C_a_i_sin(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "sin", f);
  return C_flonum(a, C_sin(f));
}


C_regparm C_word C_fcall C_a_i_cos(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "cos", f);
  return C_flonum(a, C_cos(f));
}


C_regparm C_word C_fcall C_a_i_tan(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "tan", f);
  return C_flonum(a, C_tan(f));
}


C_regparm C_word C_fcall C_a_i_asin(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "asin", f);
  return C_flonum(a, C_asin(f));
}


C_regparm C_word C_fcall C_a_i_acos(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "acos", f);
  return C_flonum(a, C_acos(f));
}


C_regparm C_word C_fcall C_a_i_atan(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "atan", f);
  return C_flonum(a, C_atan(f));
}


C_regparm C_word C_fcall C_a_i_atan2(C_word **a, int c, C_word n1, C_word n2)
{
  double f1, f2;

  C_check_real(n1, "atan", f1);
  C_check_real(n2, "atan", f2);
  return C_flonum(a, C_atan2(f1, f2));
}


C_regparm C_word C_fcall C_a_i_sinh(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "sinh", f);
  return C_flonum(a, C_sinh(f));
}


C_regparm C_word C_fcall C_a_i_cosh(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "cosh", f);
  return C_flonum(a, C_cosh(f));
}


C_regparm C_word C_fcall C_a_i_tanh(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "tanh", f);
  return C_flonum(a, C_tanh(f));
}


C_regparm C_word C_fcall C_a_i_asinh(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "asinh", f);
  return C_flonum(a, C_asinh(f));
}


C_regparm C_word C_fcall C_a_i_acosh(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "acosh", f);
  return C_flonum(a, C_acosh(f));
}


C_regparm C_word C_fcall C_a_i_atanh(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "atanh", f);
  return C_flonum(a, C_atanh(f));
}


C_regparm C_word C_fcall C_a_i_sqrt(C_word **a, int c, C_word n)
{
  double f;

  C_check_real(n, "sqrt", f);
  return C_flonum(a, C_sqrt(f));
}


C_regparm C_word C_fcall C_i_assq(C_word x, C_word lst)
{
  C_word a;

  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    a = C_u_i_car(lst);

    if(!C_immediatep(a) && C_header_type(a) == C_PAIR_TYPE) {
      if(C_u_i_car(a) == x) return a;
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "assq", a);
  
    lst = C_u_i_cdr(lst);
  }

  if(lst!=C_SCHEME_END_OF_LIST)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "assq", lst);

  return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_assv(C_word x, C_word lst)
{
  C_word a;

  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    a = C_u_i_car(lst);

    if(!C_immediatep(a) && C_header_type(a) == C_PAIR_TYPE) {
      if(C_truep(C_i_eqvp(C_u_i_car(a), x))) return a;
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "assv", a);
  
    lst = C_u_i_cdr(lst);
  }

  if(lst!=C_SCHEME_END_OF_LIST)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "assv", lst);

  return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_assoc(C_word x, C_word lst)
{
  C_word a;

  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    a = C_u_i_car(lst);

    if(!C_immediatep(a) && C_header_type(a) == C_PAIR_TYPE) {
      if(C_equalp(C_u_i_car(a), x)) return a;
    }
    else barf(C_BAD_ARGUMENT_TYPE_ERROR, "assoc", a);
  
    lst = C_u_i_cdr(lst);
  }

  if(lst!=C_SCHEME_END_OF_LIST)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "assoc", lst);

  return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_memq(C_word x, C_word lst)
{
  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    if(C_u_i_car(lst) == x) return lst;
    else lst = C_u_i_cdr(lst);
  }

  if(lst!=C_SCHEME_END_OF_LIST)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "memq", lst);

  return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_u_i_memq(C_word x, C_word lst)
{
  while(!C_immediatep(lst)) {
    if(C_u_i_car(lst) == x) return lst;
    else lst = C_u_i_cdr(lst);
  }

  return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_memv(C_word x, C_word lst)
{
  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    if(C_truep(C_i_eqvp(C_u_i_car(lst), x))) return lst;
    else lst = C_u_i_cdr(lst);
  }

  if(lst!=C_SCHEME_END_OF_LIST)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "memv", lst);
  
  return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_member(C_word x, C_word lst)
{
  while(!C_immediatep(lst) && C_header_type(lst) == C_PAIR_TYPE) {
    if(C_equalp(C_u_i_car(lst), x)) return lst;
    else lst = C_u_i_cdr(lst);
  }

  if(lst!=C_SCHEME_END_OF_LIST)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "member", lst);
  
  return C_SCHEME_FALSE;
}


/* Inline routines for extended bindings: */

C_regparm C_word C_fcall C_i_check_closure_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || (C_header_bits(x) != C_CLOSURE_TYPE)) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_CLOSURE_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_check_fixnum_2(C_word x, C_word loc)
{
  if(!(x & C_FIXNUM_BIT)) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_FIXNUM_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}

/* DEPRECATED */
C_regparm C_word C_fcall C_i_check_exact_2(C_word x, C_word loc)
{
  if(C_u_i_exactp(x) == C_SCHEME_FALSE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_EXACT_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_inexact_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || C_block_header(x) != C_FLONUM_TAG) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_INEXACT_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_char_2(C_word x, C_word loc)
{
  if((x & C_IMMEDIATE_TYPE_BITS) != C_CHARACTER_BITS) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_CHAR_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_number_2(C_word x, C_word loc)
{
  if (C_i_numberp(x) == C_SCHEME_FALSE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_string_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || C_header_bits(x) != C_STRING_TYPE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_STRING_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_bytevector_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || C_header_bits(x) != C_BYTEVECTOR_TYPE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_BYTEVECTOR_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_vector_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || C_header_bits(x) != C_VECTOR_TYPE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_VECTOR_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_structure_2(C_word x, C_word st, C_word loc)
{
  if(C_immediatep(x) || C_header_bits(x) != C_STRUCTURE_TYPE || C_block_item(x,0) != st) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_BAD_STRUCT_ERROR, NULL, x, st);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_pair_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_PAIR_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_boolean_2(C_word x, C_word loc)
{
  if((x & C_IMMEDIATE_TYPE_BITS) != C_BOOLEAN_BITS) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_BOOLEAN_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_locative_2(C_word x, C_word loc)
{
  if(C_immediatep(x) || C_block_header(x) != C_LOCATIVE_TAG) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_LOCATIVE_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_symbol_2(C_word x, C_word loc)
{
  if(!C_truep(C_i_symbolp(x))) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_SYMBOL_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_keyword_2(C_word x, C_word loc)
{
  if(!C_truep(C_i_keywordp(x))) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_KEYWORD_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_fcall C_i_check_list_2(C_word x, C_word loc)
{
  if(x != C_SCHEME_END_OF_LIST && (C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE)) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_LIST_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_check_port_2(C_word x, C_word dir, C_word open, C_word loc)
{

  if(C_immediatep(x) || C_header_bits(x) != C_PORT_TYPE) {
    error_location = loc;
    barf(C_BAD_ARGUMENT_TYPE_NO_PORT_ERROR, NULL, x);
  }

  if((C_block_item(x, 1) & dir) != dir) {	/* slot #1: I/O direction mask */
    error_location = loc;
    switch (dir) {
    case C_fix(1):
      barf(C_BAD_ARGUMENT_TYPE_PORT_NO_INPUT_ERROR, NULL, x);
    case C_fix(2):
      barf(C_BAD_ARGUMENT_TYPE_PORT_NO_OUTPUT_ERROR, NULL, x);
    default:
      barf(C_BAD_ARGUMENT_TYPE_PORT_DIRECTION_ERROR, NULL, x);
    }
  }

  if(open == C_SCHEME_TRUE) {
    if(C_block_item(x, 8) == C_FIXNUM_BIT) {	/* slot #8: closed mask */
      error_location = loc;
      barf(C_PORT_CLOSED_ERROR, NULL, x);
    }
  }

  return C_SCHEME_UNDEFINED;
}


/*XXX these are not correctly named */
C_regparm C_word C_fcall C_i_foreign_char_argumentp(C_word x)
{
  if((x & C_IMMEDIATE_TYPE_BITS) != C_CHARACTER_BITS)
    barf(C_BAD_ARGUMENT_TYPE_NO_CHAR_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_fixnum_argumentp(C_word x)
{
  if((x & C_FIXNUM_BIT) == 0)
    barf(C_BAD_ARGUMENT_TYPE_NO_FIXNUM_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_flonum_argumentp(C_word x)
{
  if((x & C_FIXNUM_BIT) != 0) return x;

  if(C_immediatep(x) || C_block_header(x) != C_FLONUM_TAG)
    barf(C_BAD_ARGUMENT_TYPE_NO_FLONUM_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_block_argumentp(C_word x)
{
  if(C_immediatep(x))
    barf(C_BAD_ARGUMENT_TYPE_NO_BLOCK_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_struct_wrapper_argumentp(C_word t, C_word x)
{
  if(C_immediatep(x) || C_header_bits(x) != C_STRUCTURE_TYPE || C_block_item(x, 0) != t)
    barf(C_BAD_ARGUMENT_TYPE_BAD_STRUCT_ERROR, NULL, t, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_string_argumentp(C_word x)
{
  if(C_immediatep(x) || C_header_bits(x) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_NO_STRING_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_symbol_argumentp(C_word x)
{
  if(C_immediatep(x) || C_header_bits(x) != C_SYMBOL_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_NO_SYMBOL_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_pointer_argumentp(C_word x)
{
  if(C_immediatep(x) || (C_header_bits(x) & C_SPECIALBLOCK_BIT) == 0)
    barf(C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR, NULL, x);

  return x;
}


/* TODO: Is this used? */
C_regparm C_word C_fcall C_i_foreign_scheme_or_c_pointer_argumentp(C_word x)
{
  if(C_immediatep(x) || (C_header_bits(x) & C_SPECIALBLOCK_BIT) == 0)
    barf(C_BAD_ARGUMENT_TYPE_NO_POINTER_ERROR, NULL, x);

  return x;
}


C_regparm C_word C_fcall C_i_foreign_tagged_pointer_argumentp(C_word x, C_word t)
{
  if(C_immediatep(x) || (C_header_bits(x) & C_SPECIALBLOCK_BIT) == 0
     || (t != C_SCHEME_FALSE && !C_equalp(C_block_item(x, 1), t)))
    barf(C_BAD_ARGUMENT_TYPE_NO_TAGGED_POINTER_ERROR, NULL, x, t);

  return x;
}

C_regparm C_word C_fcall C_i_foreign_ranged_integer_argumentp(C_word x, C_word bits)
{
  if((x & C_FIXNUM_BIT) != 0) {
    if (C_truep(C_fixnum_lessp(C_i_fixnum_length(x), bits))) return x;
    else barf(C_BAD_ARGUMENT_TYPE_FOREIGN_LIMITATION, NULL, x);
  } else if (C_truep(C_i_bignump(x))) {
    if (C_truep(C_fixnum_lessp(C_i_integer_length(x), bits))) return x;
    else barf(C_BAD_ARGUMENT_TYPE_FOREIGN_LIMITATION, NULL, x);
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, NULL, x);
  }
}

C_regparm C_word C_fcall C_i_foreign_unsigned_ranged_integer_argumentp(C_word x, C_word bits)
{
  if((x & C_FIXNUM_BIT) != 0) {
    if(x & C_INT_SIGN_BIT) barf(C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR, NULL, x);
    else if(C_ilen(C_unfix(x)) <= C_unfix(bits)) return x;
    else barf(C_BAD_ARGUMENT_TYPE_FOREIGN_LIMITATION, NULL, x);
  } else if(C_truep(C_i_bignump(x))) {
    if(C_bignum_negativep(x)) barf(C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR, NULL, x);
    else if(integer_length_abs(x) <= C_unfix(bits)) return x;
    else barf(C_BAD_ARGUMENT_TYPE_FOREIGN_LIMITATION, NULL, x);
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_UINTEGER_ERROR, NULL, x);
  }
}

/* I */
C_regparm C_word C_fcall C_i_not_pair_p_2(C_word x)
{
  return C_mk_bool(C_immediatep(x) || C_header_type(x) != C_PAIR_TYPE);
}


C_regparm C_word C_fcall C_i_null_list_p(C_word x)
{
  if(x == C_SCHEME_END_OF_LIST) return C_SCHEME_TRUE;
  else if(!C_immediatep(x) && C_header_type(x) == C_PAIR_TYPE) return C_SCHEME_FALSE;
  else {
    barf(C_BAD_ARGUMENT_TYPE_NO_LIST_ERROR, "null-list?", x);
    return C_SCHEME_FALSE;
  }
}


C_regparm C_word C_fcall C_i_string_null_p(C_word x)
{
  if(!C_immediatep(x) && C_header_bits(x) == C_STRING_TYPE)
    return C_zero_length_p(x);
  else {
    barf(C_BAD_ARGUMENT_TYPE_NO_STRING_ERROR, "string-null?", x);
    return C_SCHEME_FALSE;
  }
}


C_regparm C_word C_fcall C_i_null_pointerp(C_word x)
{
  if(!C_immediatep(x) && (C_header_bits(x) & C_SPECIALBLOCK_BIT) != 0)
    return C_null_pointerp(x);

  barf(C_BAD_ARGUMENT_TYPE_ERROR, "null-pointer?", x);
  return C_SCHEME_FALSE;
}

/* only used here for char comparators below: */
static C_word C_fcall check_char_internal(C_word x, C_char *loc)
{
  if((x & C_IMMEDIATE_TYPE_BITS) != C_CHARACTER_BITS) {
    error_location = intern0(loc);
    barf(C_BAD_ARGUMENT_TYPE_NO_CHAR_ERROR, NULL, x);
  }

  return C_SCHEME_UNDEFINED;
}

C_regparm C_word C_i_char_equalp(C_word x, C_word y)
{
  check_char_internal(x, "char=?");
  check_char_internal(y, "char=?");
  return C_u_i_char_equalp(x, y);
}

C_regparm C_word C_i_char_greaterp(C_word x, C_word y)
{
  check_char_internal(x, "char>?");
  check_char_internal(y, "char>?");
  return C_u_i_char_greaterp(x, y);
}

C_regparm C_word C_i_char_lessp(C_word x, C_word y)
{
  check_char_internal(x, "char<?");
  check_char_internal(y, "char<?");
  return C_u_i_char_lessp(x, y);
}

C_regparm C_word C_i_char_greater_or_equal_p(C_word x, C_word y)
{
  check_char_internal(x, "char>=?");
  check_char_internal(y, "char>=?");
  return C_u_i_char_greater_or_equal_p(x, y);
}

C_regparm C_word C_i_char_less_or_equal_p(C_word x, C_word y)
{
  check_char_internal(x, "char<=?");
  check_char_internal(y, "char<=?");
  return C_u_i_char_less_or_equal_p(x, y);
}


/* Primitives: */

void C_ccall C_apply(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    fn = av[ 2 ];
  int av2_size, i, n = c - 3;
  int non_list_args = n - 1;
  C_word lst, len, *ptr, *av2;

  if(c < 4) C_bad_min_argc(c, 4);

  if(C_immediatep(fn) || C_header_bits(fn) != C_CLOSURE_TYPE)
    barf(C_NOT_A_CLOSURE_ERROR, "apply", fn);

  lst = av[ c - 1 ];
  if(lst != C_SCHEME_END_OF_LIST && (C_immediatep(lst) || C_header_type(lst) != C_PAIR_TYPE))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "apply", lst);

  len = C_unfix(C_u_i_length(lst));
  av2_size = 2 + non_list_args + len;

  if(C_demand(av2_size))
    stack_check_demand = 0;
  else if(stack_check_demand)
    C_stack_overflow("apply");
  else {
    stack_check_demand = av2_size;
    C_save_and_reclaim((void *)C_apply, c, av);
  }

  av2 = ptr = C_alloc(av2_size);
  *(ptr++) = fn;
  *(ptr++) = k;

  if(non_list_args > 0) {
    C_memcpy(ptr, av + 3, non_list_args * sizeof(C_word));
    ptr += non_list_args;
  }

  while(len--) {
    *(ptr++) = C_u_i_car(lst);
    lst = C_u_i_cdr(lst);
  }

  assert((ptr - av2) == av2_size);

  ((C_proc)(void *)C_block_item(fn, 0))(av2_size, av2);
}


void C_ccall C_call_cc(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    cont = av[ 2 ],
    *a = C_alloc(C_SIZEOF_CLOSURE(2)),
    wrapper;
  void *pr = (void *)C_block_item(cont,0);
  C_word av2[ 3 ];
  
  if(C_immediatep(cont) || C_header_bits(cont) != C_CLOSURE_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "call-with-current-continuation", cont);
  
  /* Check for values-continuation: */
  if(C_block_item(k, 0) == (C_word)values_continuation)
    wrapper = C_closure(&a, 2, (C_word)call_cc_values_wrapper, k);
  else wrapper = C_closure(&a, 2, (C_word)call_cc_wrapper, k);
  
  av2[ 0 ] = cont;
  av2[ 1 ] = k;
  av2[ 2 ] = wrapper;
  ((C_proc)pr)(3, av2);
}


void C_ccall call_cc_wrapper(C_word c, C_word *av)
{
  C_word
    closure = av[ 0 ],
    /* av[ 1 ] is current k and ignored */
    result,
    k = C_block_item(closure, 1);

  if(c != 3) C_bad_argc(c, 3);

  result = av[ 2 ];
  C_kontinue(k, result);
}


void C_ccall call_cc_values_wrapper(C_word c, C_word *av)
{
  C_word
    closure = av[ 0 ],
    /* av[ 1 ] is current k and ignored */
    k = C_block_item(closure, 1),
    x1,
    n = c;
  
  av[ 0 ] = k;               /* reuse av */
  C_memmove(av + 1, av + 2, (n - 1) * sizeof(C_word));
  C_do_apply(n - 1, av);
}


void C_ccall C_continuation_graft(C_word c, C_word *av)
{
  C_word
    /* self = av[ 0 ] */
    /* k = av[ 1 ] */
    kk = av[ 2 ],
    proc = av[ 3 ];

  av[ 0 ] = proc;               /* reuse av */
  av[ 1 ] = C_block_item(kk, 1);
  ((C_proc)C_fast_retrieve_proc(proc))(2, av);
}


void C_ccall C_values(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    n = c;

  if(c < 2) C_bad_min_argc(c, 2);

  /* Check continuation whether it receives multiple values: */
  if(C_block_item(k, 0) == (C_word)values_continuation) {
    av[ 0 ] = k;                /* reuse av */
    C_memmove(av + 1, av + 2, (c - 2) * sizeof(C_word));
    C_do_apply(c - 1, av);
  }
  
  if(c != 3) {
#ifdef RELAX_MULTIVAL_CHECK
    if(c == 2) n = C_SCHEME_UNDEFINED;
    else n = av[ 2 ];
#else
    barf(C_CONTINUATION_CANT_RECEIVE_VALUES_ERROR, "values", k);
#endif
  }
  else n = av[ 2 ];

  C_kontinue(k, n);
}


void C_ccall C_apply_values(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    lst, len, n;

  if(c != 3) C_bad_argc(c, 3);

  lst = av[ 2 ];

  if(lst != C_SCHEME_END_OF_LIST && (C_immediatep(lst) || C_header_type(lst) != C_PAIR_TYPE))
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "apply", lst);

  /* Check whether continuation receives multiple values: */
  if(C_block_item(k, 0) == (C_word)values_continuation) {
    C_word *av2, *ptr;

    len = C_unfix(C_u_i_length(lst));
    n = len + 1;

    if(C_demand(n))
      stack_check_demand = 0;
    else if(stack_check_demand)
      C_stack_overflow("apply");
    else {
      stack_check_demand = n;
      C_save_and_reclaim((void *)C_apply_values, c, av);
    }

    av2 = C_alloc(n);
    av2[ 0 ] = k;
    ptr = av2 + 1;
    while(len--) {
      *(ptr++) = C_u_i_car(lst);
      lst = C_u_i_cdr(lst);
    }

    C_do_apply(n, av2);
  }
  
  if(C_immediatep(lst)) {
#ifdef RELAX_MULTIVAL_CHECK
    n = C_SCHEME_UNDEFINED;
#else
    barf(C_CONTINUATION_CANT_RECEIVE_VALUES_ERROR, "values", k);
#endif
  }
  else if(C_header_type(lst) == C_PAIR_TYPE) {
    if(C_u_i_cdr(lst) == C_SCHEME_END_OF_LIST)
      n = C_u_i_car(lst);
    else {
#ifdef RELAX_MULTIVAL_CHECK
      n = C_u_i_car(lst);
#else
      barf(C_CONTINUATION_CANT_RECEIVE_VALUES_ERROR, "values", k);
#endif
    }
  }
  else barf(C_BAD_ARGUMENT_TYPE_ERROR, "apply", lst);
  
  C_kontinue(k, n);
}


void C_ccall C_call_with_values(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    thunk,
    kont,
    *a = C_alloc(C_SIZEOF_CLOSURE(3)),
    kk;

  if(c != 4) C_bad_argc(c, 4);

  thunk = av[ 2 ];
  kont = av[ 3 ];

  if(C_immediatep(thunk) || C_header_bits(thunk) != C_CLOSURE_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "call-with-values", thunk);

  if(C_immediatep(kont) || C_header_bits(kont) != C_CLOSURE_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "call-with-values", kont);

  kk = C_closure(&a, 3, (C_word)values_continuation, kont, k);
  av[ 0 ] = thunk;              /* reuse av */
  av[ 1 ] = kk;
  C_do_apply(2, av);
}


void C_ccall C_u_call_with_values(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    thunk = av[ 2 ],
    kont = av[ 3 ],
    *a = C_alloc(C_SIZEOF_CLOSURE(3)),
    kk;

  kk = C_closure(&a, 3, (C_word)values_continuation, kont, k);
  av[ 0 ] = thunk;              /* reuse av */
  av[ 1 ] = kk;
  C_do_apply(2, av);
}


void C_ccall values_continuation(C_word c, C_word *av)
{
  C_word
    closure = av[ 0 ],
    kont = C_block_item(closure, 1),
    k = C_block_item(closure, 2),
    *av2 = C_alloc(c + 1);

  av2[ 0 ] = kont;
  av2[ 1 ] = k;
  C_memcpy(av2 + 2, av + 1, (c - 1) * sizeof(C_word));
  C_do_apply(c + 1, av2);
}

static C_word rat_times_integer(C_word **ptr, C_word rat, C_word i)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM * 2], *a = ab, num, denom, gcd, a_div_g;

  switch (i) {
  case C_fix(0): return C_fix(0);
  case C_fix(1): return rat;
  case C_fix(-1):
    num = C_s_a_u_i_integer_negate(ptr, 1, C_u_i_ratnum_num(rat));
    return C_ratnum(ptr, num , C_u_i_ratnum_denom(rat));
  /* default: CONTINUE BELOW */
  }

  num = C_u_i_ratnum_num(rat);
  denom = C_u_i_ratnum_denom(rat);

  /* a/b * c/d = a*c / b*d  [with b = 1] */
  /*  =  ((a / g) * c) / (d / g) */
  /* With   g = gcd(a, d)   and  a = x   [Knuth, 4.5.1] */
  gcd = C_s_a_u_i_integer_gcd(&a, 2, i, denom);

  /* Calculate a/g  (= i/gcd), which will later be multiplied by y */
  a_div_g = C_s_a_u_i_integer_quotient(&a, 2, i, gcd);
  if (a_div_g == C_fix(0)) {
    clear_buffer_object(ab, gcd);
    return C_fix(0); /* Save some work */
  }

  /* Final numerator = a/g * c  (= a_div_g * num) */
  num = C_s_a_u_i_integer_times(ptr, 2, a_div_g, num);

  /* Final denominator = d/g  (= denom/gcd) */
  denom = C_s_a_u_i_integer_quotient(ptr, 2, denom, gcd);

  num = move_buffer_object(ptr, ab, num);
  denom = move_buffer_object(ptr, ab, denom);
  
  clear_buffer_object(ab, gcd);
  clear_buffer_object(ab, a_div_g);

  if (denom == C_fix(1)) return num;
  else return C_ratnum(ptr, num, denom);
}

static C_word rat_times_rat(C_word **ptr, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM * 6], *a = ab,
         num, denom, xnum, xdenom, ynum, ydenom,
         g1, g2, a_div_g1, b_div_g2, c_div_g2, d_div_g1;

  xnum = C_u_i_ratnum_num(x);
  xdenom = C_u_i_ratnum_denom(x);
  ynum = C_u_i_ratnum_num(y);
  ydenom = C_u_i_ratnum_denom(y);

  /* a/b * c/d = a*c / b*d  [generic] */
  /*   = ((a / g1) * (c / g2)) / ((b / g2) * (d / g1)) */
  /* With  g1 = gcd(a, d)  and   g2 = gcd(b, c) [Knuth, 4.5.1] */
  g1 = C_s_a_u_i_integer_gcd(&a, 2, xnum, ydenom);
  g2 = C_s_a_u_i_integer_gcd(&a, 2, ynum, xdenom);

  /* Calculate a/g1  (= xnum/g1), which will later be multiplied by c/g2 */
  a_div_g1 = C_s_a_u_i_integer_quotient(&a, 2, xnum, g1);

  /* Calculate c/g2  (= ynum/g2), which will later be multiplied by a/g1 */
  c_div_g2 = C_s_a_u_i_integer_quotient(&a, 2, ynum, g2);

  /* Final numerator = a/g1 * c/g2 */
  num = C_s_a_u_i_integer_times(ptr, 2, a_div_g1, c_div_g2);

  /* Now, do the same for the denominator.... */

  /* Calculate b/g2  (= xdenom/g2), which will later be multiplied by d/g1 */
  b_div_g2 = C_s_a_u_i_integer_quotient(&a, 2, xdenom, g2);

  /* Calculate d/g1  (= ydenom/g1), which will later be multiplied by b/g2 */
  d_div_g1 = C_s_a_u_i_integer_quotient(&a, 2, ydenom, g1);

  /* Final denominator = b/g2 * d/g1 */
  denom = C_s_a_u_i_integer_times(ptr, 2, b_div_g2, d_div_g1);

  num = move_buffer_object(ptr, ab, num);
  denom = move_buffer_object(ptr, ab, denom);

  clear_buffer_object(ab, g1);
  clear_buffer_object(ab, g2);
  clear_buffer_object(ab, a_div_g1);
  clear_buffer_object(ab, b_div_g2);
  clear_buffer_object(ab, c_div_g2);
  clear_buffer_object(ab, d_div_g1);

  if (denom == C_fix(1)) return num;
  else return C_ratnum(ptr, num, denom);
}

static C_word
cplx_times(C_word **ptr, C_word rx, C_word ix, C_word ry, C_word iy)
{
  /* Allocation here is kind of tricky: Each intermediate result can
   * be at most a ratnum consisting of two bignums (2 digits), so
   * C_SIZEOF_RATNUM + C_SIZEOF_BIGNUM(2) = 9 words
   */
  C_word ab[(C_SIZEOF_RATNUM + C_SIZEOF_BIGNUM(2))*6], *a = ab,
         r1, r2, i1, i2, r, i;

  /* a+bi * c+di = (a*c - b*d) + (a*d + b*c)i */
  /* We call these:  r1 = a*c, r2 = b*d, i1 = a*d, i2 = b*c */
  r1 = C_s_a_i_times(&a, 2, rx, ry);
  r2 = C_s_a_i_times(&a, 2, ix, iy);
  i1 = C_s_a_i_times(&a, 2, rx, iy);
  i2 = C_s_a_i_times(&a, 2, ix, ry);
  
  r = C_s_a_i_minus(ptr, 2, r1, r2);
  i = C_s_a_i_plus(ptr, 2, i1, i2);

  r = move_buffer_object(ptr, ab, r);
  i = move_buffer_object(ptr, ab, i);

  clear_buffer_object(ab, r1);
  clear_buffer_object(ab, r2);
  clear_buffer_object(ab, i1);
  clear_buffer_object(ab, i2);

  if (C_truep(C_u_i_zerop2(i))) return r;
  else return C_cplxnum(ptr, r, i);
}

/* The maximum size this needs is that required to store a complex
 * number result, where both real and imag parts consist of ratnums.
 * The maximum size of those ratnums is if they consist of two bignums
 * from a fixnum multiplication (2 digits each), so we're looking at
 * C_SIZEOF_RATNUM * 3 + C_SIZEOF_BIGNUM(2) * 4 = 33 words!
 */
C_regparm C_word C_fcall
C_s_a_i_times(C_word **ptr, C_word n, C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_a_i_fixnum_times(ptr, 2, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_flonum(ptr, (double)C_unfix(x) * C_flonum_magnitude(y));
    } else if (C_truep(C_bignump(y))) {
      return C_s_a_u_i_integer_times(ptr, 2, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return rat_times_integer(ptr, y, x);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      return cplx_times(ptr, x, C_fix(0),
                        C_u_i_cplxnum_real(y), C_u_i_cplxnum_imag(y));
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    }
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return C_flonum(ptr, C_flonum_magnitude(x) * (double)C_unfix(y));
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_a_i_flonum_times(ptr, 2, x, y);
    } else if (C_truep(C_bignump(y))) {
      return C_flonum(ptr, C_flonum_magnitude(x) * C_bignum_to_double(y));
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return C_s_a_i_times(ptr, 2, x, C_a_i_exact_to_inexact(ptr, 1, y));
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word ab[C_SIZEOF_FLONUM], *a = ab;
      return cplx_times(ptr, x, C_flonum(&a, 0.0),
                        C_u_i_cplxnum_real(y), C_u_i_cplxnum_imag(y));
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    }
  } else if (C_truep(C_bignump(x))) {
    if (y & C_FIXNUM_BIT) {
      return C_s_a_u_i_integer_times(ptr, 2, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", x);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_flonum(ptr, C_bignum_to_double(x) * C_flonum_magnitude(y));
    } else if (C_truep(C_bignump(y))) {
      return C_s_a_u_i_integer_times(ptr, 2, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return rat_times_integer(ptr, y, x);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      return cplx_times(ptr, x, C_fix(0),
                        C_u_i_cplxnum_real(y), C_u_i_cplxnum_imag(y));
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    }
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return rat_times_integer(ptr, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_s_a_i_times(ptr, 2, C_a_i_exact_to_inexact(ptr, 1, x), y);
    } else if (C_truep(C_bignump(y))) {
      return rat_times_integer(ptr, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
        return rat_times_rat(ptr, x, y);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      return cplx_times(ptr, x, C_fix(0),
                        C_u_i_cplxnum_real(y), C_u_i_cplxnum_imag(y));
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", y);
    }
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    if (!C_immediatep(y) && C_block_header(y) == C_CPLXNUM_TAG) {
      return cplx_times(ptr, C_u_i_cplxnum_real(x), C_u_i_cplxnum_imag(x),
                        C_u_i_cplxnum_real(y), C_u_i_cplxnum_imag(y));
    } else {
      C_word ab[C_SIZEOF_FLONUM], *a = ab, yi;
      yi = C_truep(C_i_flonump(y)) ? C_flonum(&a,0) : C_fix(0);
      return cplx_times(ptr, C_u_i_ratnum_num(x), C_u_i_ratnum_denom(x), y, yi);
    }
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "*", x);
  }
}


C_regparm C_word C_fcall
C_s_a_u_i_integer_times(C_word **ptr, C_word n, C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_a_i_fixnum_times(ptr, 2, x, y);
    } else {
      C_word tmp = x; /* swap to ensure x is a bignum and y a fixnum */
      x = y;
      y = tmp;
    }
  }
  /* Here, we know for sure that X is a bignum */
  if (y == C_fix(0)) {
    return C_fix(0);
  } else if (y == C_fix(1)) {
    return x;
  } else if (y == C_fix(-1)) {
    return C_s_a_u_i_integer_negate(ptr, 1, x);
  } else if (y & C_FIXNUM_BIT) { /* Any other fixnum */
    C_word absy = (y & C_INT_SIGN_BIT) ? -C_unfix(y) : C_unfix(y),
           negp = C_mk_bool((y & C_INT_SIGN_BIT) ?
                            !C_bignum_negativep(x) :
                            C_bignum_negativep(x));
  
    if (C_fitsinbignumhalfdigitp(absy) ||
        (((C_uword)1 << (C_ilen(absy)-1)) == absy && C_fitsinfixnump(absy))) {
      C_word size, res;
      C_uword *startr, *endr;
      int shift;
      size = C_bignum_size(x) + 1; /* Needs _at most_ one more digit */
      res = C_allocate_scratch_bignum(ptr, C_fix(size), negp, C_SCHEME_FALSE);

      bignum_digits_destructive_copy(res, x);

      startr = C_bignum_digits(res);
      endr = startr + size - 1;
      /* Scale up, and sanitise the result. */
      shift = C_ilen(absy) - 1;
      if (((C_uword)1 << shift) == absy) { /* Power of two? */
        *endr = bignum_digits_destructive_shift_left(startr, endr, shift);
      } else {
        *endr = bignum_digits_destructive_scale_up_with_carry(startr, endr,
                                                              absy, 0);
      }
      return C_bignum_simplify(res);
    } else {
      C_word *a = C_alloc(C_SIZEOF_FIX_BIGNUM);
      y = C_a_u_i_fix_to_big(&a, y);
      return bignum_times_bignum_unsigned(ptr, x, y, negp);
    }
  } else {
    C_word negp = C_bignum_negativep(x) ?
                  !C_bignum_negativep(y) :
                  C_bignum_negativep(y);
    return bignum_times_bignum_unsigned(ptr, x, y, C_mk_bool(negp));
  }
}

static C_regparm C_word
bignum_times_bignum_unsigned(C_word **ptr, C_word x, C_word y, C_word negp)
{
  C_word size, res = C_SCHEME_FALSE;
  if (C_bignum_size(y) < C_bignum_size(x)) { /* Ensure size(x) <= size(y) */
    C_word z = x;
    x = y;
    y = z;
  }

  if (C_bignum_size(x) >= C_KARATSUBA_THRESHOLD)
    res = bignum_times_bignum_karatsuba(ptr, x, y, negp);

  if (!C_truep(res)) {
    size = C_bignum_size(x) + C_bignum_size(y);
    res = C_allocate_scratch_bignum(ptr, C_fix(size), negp, C_SCHEME_TRUE);
    bignum_digits_multiply(x, y, res);
    res = C_bignum_simplify(res);
  }
  return res;
}

/* Karatsuba multiplication: invoked when the two numbers are large
 * enough to make it worthwhile, and we still have enough stack left.
 * Complexity is O(n^log2(3)), where n is max(len(x), len(y)).  The
 * description in [Knuth, 4.3.3] leaves a lot to be desired.  [MCA,
 * 1.3.2] and [MpNT, 3.2] are a bit easier to understand.  We assume
 * that length(x) <= length(y).
 */
static C_regparm C_word
bignum_times_bignum_karatsuba(C_word **ptr, C_word x, C_word y, C_word negp)
{
   C_word kab[C_SIZEOF_FIX_BIGNUM*15+C_SIZEOF_BIGNUM(2)*3], *ka = kab, o[18],
          xhi, xlo, xmid, yhi, ylo, ymid, a, b, c, n, bits;
   int i = 0;

   /* Ran out of stack?  Fall back to non-recursive multiplication */
   C_stack_check1(return C_SCHEME_FALSE);
   
   /* Split |x| in half: <xhi,xlo> and |y|: <yhi,ylo> with len(ylo)=len(xlo) */
   x = o[i++] = C_s_a_u_i_integer_abs(&ka, 1, x);
   y = o[i++] = C_s_a_u_i_integer_abs(&ka, 1, y);
   n = C_fix(C_bignum_size(y) >> 1);
   xhi = o[i++] = bignum_extract_digits(&ka, 3, x, n, C_SCHEME_FALSE);
   xlo = o[i++] = bignum_extract_digits(&ka, 3, x, C_fix(0), n);
   yhi = o[i++] = bignum_extract_digits(&ka, 3, y, n, C_SCHEME_FALSE);
   ylo = o[i++] = bignum_extract_digits(&ka, 3, y, C_fix(0), n);

   /* a = xhi * yhi, b = xlo * ylo, c = (xhi - xlo) * (yhi - ylo) */
   a = o[i++] = C_s_a_u_i_integer_times(&ka, 2, xhi, yhi);
   b = o[i++] = C_s_a_u_i_integer_times(&ka, 2, xlo, ylo);
   xmid = o[i++] = C_s_a_u_i_integer_minus(&ka, 2, xhi, xlo);
   ymid = o[i++] = C_s_a_u_i_integer_minus(&ka, 2, yhi, ylo);
   c = o[i++] = C_s_a_u_i_integer_times(&ka, 2, xmid, ymid);

   /* top(x) = a << (bits - 1)  and  bottom(y) = ((b + (a - c)) << bits) + b */
   bits = C_unfix(n) * C_BIGNUM_DIGIT_LENGTH;
   x = o[i++] = C_s_a_i_arithmetic_shift(&ka, 2, a, C_fix((C_uword)bits << 1));
   c = o[i++] = C_s_a_u_i_integer_minus(&ka, 2, a, c);
   c = o[i++] = C_s_a_u_i_integer_plus(&ka, 2, b, c);
   c = o[i++] = C_s_a_i_arithmetic_shift(&ka, 2, c, C_fix(bits));
   y = o[i++] = C_s_a_u_i_integer_plus(&ka, 2, c, b);
   /* Finally, return top + bottom, and correct for negative */
   n = o[i++] = C_s_a_u_i_integer_plus(&ka, 2, x, y);
   if (C_truep(negp)) n = o[i++] = C_s_a_u_i_integer_negate(&ka, 1, n);

   n = move_buffer_object(ptr, kab, n);
   while(i--) clear_buffer_object(kab, o[i]);
   return n;
}

void C_ccall C_times(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word next_val,
    result = C_fix(1),
    prev_result = result;
  C_word ab[2][C_SIZEOF_CPLXNUM + C_SIZEOF_RATNUM*2 + C_SIZEOF_BIGNUM(2) * 4], *a;

  c -= 2; 
  av += 2;

  while (c--) {
    next_val = *(av++);
    a = ab[c&1]; /* One may hold prev iteration result, the other is unused */
    result = C_s_a_i_times(&a, 2, result, next_val);
    result = move_buffer_object(&a, ab[(c+1)&1], result);
    clear_buffer_object(ab[(c+1)&1], prev_result);
    prev_result = result;
  }

  C_kontinue(k, result);
}


static C_word bignum_plus_unsigned(C_word **ptr, C_word x, C_word y, C_word negp)
{
  C_word size, result;
  C_uword sum, digit, *scan_y, *end_y, *scan_r, *end_r;
  int carry = 0;

  if (C_bignum_size(y) > C_bignum_size(x)) {  /* Ensure size(y) <= size(x) */
    C_word z = x;
    x = y;
    y = z;
  }

  size = C_fix(C_bignum_size(x) + 1); /* One more digit, for possible carry. */
  result = C_allocate_scratch_bignum(ptr, size, negp, C_SCHEME_FALSE);

  scan_y = C_bignum_digits(y);
  end_y = scan_y + C_bignum_size(y);
  scan_r = C_bignum_digits(result);
  end_r = scan_r + C_bignum_size(result);

  /* Copy x into r so we can operate on two pointers, which is faster
   * than three, and we can stop earlier after adding y.  It's slower
   * if x and y have equal length.  On average it's slightly faster.
   */
  bignum_digits_destructive_copy(result, x);
  *(end_r-1) = 0; /* Ensure most significant digit is initialised */

  /* Move over x and y simultaneously, destructively adding digits w/ carry. */
  while (scan_y < end_y) {
    digit = *scan_r;
    if (carry) {
      sum = digit + *scan_y++ + 1;
      carry = sum <= digit;
    } else {
      sum = digit + *scan_y++;
      carry = sum < digit;
    }
    (*scan_r++) = sum;
  }
  
  /* The end of y, the smaller number.  Propagate carry into the rest of x. */
  while (carry) {
    sum = (*scan_r) + 1;
    carry = (sum == 0);
    (*scan_r++) = sum;
  }
  assert(scan_r <= end_r);

  return C_bignum_simplify(result);
}

static C_word rat_plusmin_integer(C_word **ptr, C_word rat, C_word i, integer_plusmin_op plusmin_op)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM+C_SIZEOF_BIGNUM(2)], *a = ab,
         num, denom, tmp, res;

  if (i == C_fix(0)) return rat;

  num = C_u_i_ratnum_num(rat);
  denom = C_u_i_ratnum_denom(rat);

  /* a/b [+-] c/d = (a*d [+-] b*c)/(b*d) | d = 1: (num + denom * i) / denom */
  tmp = C_s_a_u_i_integer_times(&a, 2, denom, i);
  res = plusmin_op(&a, 2, num, tmp);
  res = move_buffer_object(ptr, ab, res);
  clear_buffer_object(ab, tmp);
  return C_ratnum(ptr, res, denom);
}

/* This is needed only for minus: plus is commutative but minus isn't. */
static C_word integer_minus_rat(C_word **ptr, C_word i, C_word rat)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM+C_SIZEOF_BIGNUM(2)], *a = ab,
         num, denom, tmp, res;

  num = C_u_i_ratnum_num(rat);
  denom = C_u_i_ratnum_denom(rat);

  if (i == C_fix(0))
    return C_ratnum(ptr, C_s_a_u_i_integer_negate(ptr, 1, num), denom);

  /* a/b - c/d = (a*d - b*c)/(b*d) | b = 1: (denom * i - num) / denom */
  tmp = C_s_a_u_i_integer_times(&a, 2, denom, i);
  res = C_s_a_u_i_integer_minus(&a, 2, tmp, num);
  res = move_buffer_object(ptr, ab, res);
  clear_buffer_object(ab, tmp);
  return C_ratnum(ptr, res, denom);
}

/* This is pretty braindead and ugly */
static C_word rat_plusmin_rat(C_word **ptr, C_word x, C_word y, integer_plusmin_op plusmin_op)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*6 + C_SIZEOF_BIGNUM(2)*2], *a = ab,
         xnum = C_u_i_ratnum_num(x), ynum = C_u_i_ratnum_num(y),
         xdenom = C_u_i_ratnum_denom(x), ydenom = C_u_i_ratnum_denom(y),
         xnorm, ynorm, tmp_r, g1, ydenom_g1, xdenom_g1, norm_sum, g2, len,
         res_num, res_denom;

  /* Knuth, 4.5.1.  Start with g1 = gcd(xdenom, ydenom) */
  g1 = C_s_a_u_i_integer_gcd(&a, 2, xdenom, ydenom);

  /* xnorm = xnum * (ydenom/g1) */
  ydenom_g1 = C_s_a_u_i_integer_quotient(&a, 2, ydenom, g1);
  xnorm = C_s_a_u_i_integer_times(&a, 2, xnum, ydenom_g1);

  /* ynorm = ynum * (xdenom/g1) */
  xdenom_g1 = C_s_a_u_i_integer_quotient(&a, 2, xdenom, g1);
  ynorm = C_s_a_u_i_integer_times(&a, 2, ynum, xdenom_g1);

  /* norm_sum = xnorm [+-] ynorm */
  norm_sum = plusmin_op(&a, 2, xnorm, ynorm);

  /* g2 = gcd(norm_sum, g1) */
  g2 = C_s_a_u_i_integer_gcd(&a, 2, norm_sum, g1);

  /* res_num = norm_sum / g2 */
  res_num = C_s_a_u_i_integer_quotient(ptr, 2, norm_sum, g2);
  if (res_num == C_fix(0)) {
    res_denom = C_fix(0); /* No need to calculate denom: we'll return 0 */
  } else {
    /* res_denom = xdenom_g1 * (ydenom / g2) */
    C_word res_tmp_denom = C_s_a_u_i_integer_quotient(&a, 2, ydenom, g2);
    res_denom = C_s_a_u_i_integer_times(ptr, 2, xdenom_g1, res_tmp_denom);

    /* Ensure they're allocated in the correct place */
    res_num = move_buffer_object(ptr, ab, res_num);
    res_denom = move_buffer_object(ptr, ab, res_denom);
    clear_buffer_object(ab, res_tmp_denom);
  }

  clear_buffer_object(ab, xdenom_g1);
  clear_buffer_object(ab, ydenom_g1);
  clear_buffer_object(ab, xnorm);
  clear_buffer_object(ab, ynorm);
  clear_buffer_object(ab, norm_sum);
  clear_buffer_object(ab, g1);
  clear_buffer_object(ab, g2);

  switch (res_denom) {
  case C_fix(0): return C_fix(0);
  case C_fix(1): return res_num;
  default: return C_ratnum(ptr, res_num, res_denom);
  }
}

/* The maximum size this needs is that required to store a complex
 * number result, where both real and imag parts consist of ratnums.
 * The maximum size of those ratnums is if they consist of two "fix
 * bignums", so we're looking at C_SIZEOF_CPLXNUM + C_SIZEOF_RATNUM *
 * 2 + C_SIZEOF_FIX_BIGNUM * 4 = 29 words!
 */
C_regparm C_word C_fcall
C_s_a_i_plus(C_word **ptr, C_word n, C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_a_i_fixnum_plus(ptr, 2, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_flonum(ptr, (double)C_unfix(x) + C_flonum_magnitude(y));
    } else if (C_truep(C_bignump(y))) {
      return C_s_a_u_i_integer_plus(ptr, 2, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return rat_plusmin_integer(ptr, y, x, C_s_a_u_i_integer_plus);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_sum = C_s_a_i_plus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_u_i_cplxnum_imag(y);
      if (C_truep(C_u_i_inexactp(real_sum)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_sum, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    }
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return C_flonum(ptr, C_flonum_magnitude(x) + (double)C_unfix(y));
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_a_i_flonum_plus(ptr, 2, x, y);
    } else if (C_truep(C_bignump(y))) {
      return C_flonum(ptr, C_flonum_magnitude(x)+C_bignum_to_double(y));
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return C_s_a_i_plus(ptr, 2, x, C_a_i_exact_to_inexact(ptr, 1, y));
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_sum = C_s_a_i_plus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_u_i_cplxnum_imag(y);
      if (C_truep(C_u_i_inexactp(real_sum)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_sum, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    }
  } else if (C_truep(C_bignump(x))) {
    if (y & C_FIXNUM_BIT) {
      return C_s_a_u_i_integer_plus(ptr, 2, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_flonum(ptr, C_bignum_to_double(x)+C_flonum_magnitude(y));
    } else if (C_truep(C_bignump(y))) {
      return C_s_a_u_i_integer_plus(ptr, 2, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return rat_plusmin_integer(ptr, y, x, C_s_a_u_i_integer_plus);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_sum = C_s_a_i_plus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_u_i_cplxnum_imag(y);
      if (C_truep(C_u_i_inexactp(real_sum)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_sum, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    }
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return rat_plusmin_integer(ptr, x, y, C_s_a_u_i_integer_plus);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_s_a_i_plus(ptr, 2, C_a_i_exact_to_inexact(ptr, 1, x), y);
    } else if (C_truep(C_bignump(y))) {
      return rat_plusmin_integer(ptr, x, y, C_s_a_u_i_integer_plus);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return rat_plusmin_rat(ptr, x, y, C_s_a_u_i_integer_plus);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_sum = C_s_a_i_plus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_u_i_cplxnum_imag(y);
      if (C_truep(C_u_i_inexactp(real_sum)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_sum, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", y);
    }
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    if (!C_immediatep(y) && C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_sum, imag_sum;
      real_sum = C_s_a_i_plus(ptr, 2, C_u_i_cplxnum_real(x), C_u_i_cplxnum_real(y));
      imag_sum = C_s_a_i_plus(ptr, 2, C_u_i_cplxnum_imag(x), C_u_i_cplxnum_imag(y));
      if (C_truep(C_u_i_zerop2(imag_sum))) return real_sum;
      else return C_cplxnum(ptr, real_sum, imag_sum);
    } else {
      C_word real_sum = C_s_a_i_plus(ptr, 2, C_u_i_cplxnum_real(x), y),
             imag = C_u_i_cplxnum_imag(x);
      if (C_truep(C_u_i_inexactp(real_sum)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_sum, imag);
    }
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "+", x);
  }
}

C_regparm C_word C_fcall
C_s_a_u_i_integer_plus(C_word **ptr, C_word n, C_word x, C_word y)
{
  if ((x & y) & C_FIXNUM_BIT) {
    return C_a_i_fixnum_plus(ptr, 2, x, y);
  } else {
    C_word ab[C_SIZEOF_FIX_BIGNUM * 2 + C_SIZEOF_BIGNUM_WRAPPER], *a = ab;
    if (x & C_FIXNUM_BIT) x = C_a_u_i_fix_to_big(&a, x);
    if (y & C_FIXNUM_BIT) y = C_a_u_i_fix_to_big(&a, y);

    if (C_bignum_negativep(x)) {
      if (C_bignum_negativep(y)) {
        return bignum_plus_unsigned(ptr, x, y, C_SCHEME_TRUE);
      } else {
        return bignum_minus_unsigned(ptr, y, x);
      }
    } else {
      if (C_bignum_negativep(y)) {
        return bignum_minus_unsigned(ptr, x, y);
      } else {
        return bignum_plus_unsigned(ptr, x, y, C_SCHEME_FALSE);
      }
    }
  }
}

void C_ccall C_plus(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word next_val,
    result = C_fix(0),
    prev_result = result;
  C_word ab[2][C_SIZEOF_CPLXNUM + C_SIZEOF_RATNUM*2 + C_SIZEOF_FIX_BIGNUM * 4], *a;

  c -= 2; 
  av += 2;

  while (c--) {
    next_val = *(av++);
    a = ab[c&1]; /* One may hold last iteration result, the other is unused */
    result = C_s_a_i_plus(&a, 2, result, next_val);
    result = move_buffer_object(&a, ab[(c+1)&1], result);
    clear_buffer_object(ab[(c+1)&1], prev_result);
    prev_result = result;
  }

  C_kontinue(k, result);
}

static C_word bignum_minus_unsigned(C_word **ptr, C_word x, C_word y)
{
  C_word res, size;
  C_uword *scan_r, *end_r, *scan_y, *end_y, difference, digit;
  int borrow = 0;

  switch(bignum_cmp_unsigned(x, y)) {
  case 0:	      /* x = y, return 0 */
    return C_fix(0);
  case -1:	      /* abs(x) < abs(y), return -(abs(y) - abs(x)) */
    size = C_fix(C_bignum_size(y)); /* Maximum size of result is length of y. */
    res = C_allocate_scratch_bignum(ptr, size, C_SCHEME_TRUE, C_SCHEME_FALSE);
    size = y;
    y = x;
    x = size;
    break;
  case 1:	      /* abs(x) > abs(y), return abs(x) - abs(y) */
  default:
    size = C_fix(C_bignum_size(x)); /* Maximum size of result is length of x. */
    res = C_allocate_scratch_bignum(ptr, size, C_SCHEME_FALSE, C_SCHEME_FALSE);
    break;
  }

  scan_r = C_bignum_digits(res);
  end_r = scan_r + C_bignum_size(res);
  scan_y = C_bignum_digits(y);
  end_y = scan_y + C_bignum_size(y);

  bignum_digits_destructive_copy(res, x); /* See bignum_plus_unsigned */

  /* Destructively subtract y's digits w/ borrow from and back into r. */
  while (scan_y < end_y) {
    digit = *scan_r;
    if (borrow) {
      difference = digit - *scan_y++ - 1;
      borrow = difference >= digit;
    } else {
      difference = digit - *scan_y++;
      borrow = difference > digit;
    }
    (*scan_r++) = difference;
  }

  /* The end of y, the smaller number.  Propagate borrow into the rest of x. */
  while (borrow) {
    digit = *scan_r;
    difference = digit - borrow;
    borrow = difference >= digit;
    (*scan_r++) = difference;
  }

  assert(scan_r <= end_r);

  return C_bignum_simplify(res);
}

/* Like C_s_a_i_plus, this needs at most 29 words */
C_regparm C_word C_fcall
C_s_a_i_minus(C_word **ptr, C_word n, C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_a_i_fixnum_difference(ptr, 2, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_flonum(ptr, (double)C_unfix(x) - C_flonum_magnitude(y));
    } else if (C_truep(C_bignump(y))) {
      return C_s_a_u_i_integer_minus(ptr, 2, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return integer_minus_rat(ptr, x, y);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_diff = C_s_a_i_minus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_s_a_i_negate(ptr, 1, C_u_i_cplxnum_imag(y));
      if (C_truep(C_u_i_inexactp(real_diff)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_diff, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    }
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return C_flonum(ptr, C_flonum_magnitude(x) - (double)C_unfix(y));
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_a_i_flonum_difference(ptr, 2, x, y);
    } else if (C_truep(C_bignump(y))) {
      return C_flonum(ptr, C_flonum_magnitude(x)-C_bignum_to_double(y));
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return C_s_a_i_minus(ptr, 2, x, C_a_i_exact_to_inexact(ptr, 1, y));
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_diff = C_s_a_i_minus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_s_a_i_negate(ptr, 1, C_u_i_cplxnum_imag(y));
      if (C_truep(C_u_i_inexactp(real_diff)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_diff, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    }
  } else if (C_truep(C_bignump(x))) {
    if (y & C_FIXNUM_BIT) {
      return C_s_a_u_i_integer_minus(ptr, 2, x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_flonum(ptr, C_bignum_to_double(x)-C_flonum_magnitude(y));
    } else if (C_truep(C_bignump(y))) {
      return C_s_a_u_i_integer_minus(ptr, 2, x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return integer_minus_rat(ptr, x, y);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_diff = C_s_a_i_minus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_s_a_i_negate(ptr, 1, C_u_i_cplxnum_imag(y));
      if (C_truep(C_u_i_inexactp(real_diff)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_diff, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    }
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return rat_plusmin_integer(ptr, x, y, C_s_a_u_i_integer_minus);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return C_s_a_i_minus(ptr, 2, C_a_i_exact_to_inexact(ptr, 1, x), y);
    } else if (C_truep(C_bignump(y))) {
      return rat_plusmin_integer(ptr, x, y, C_s_a_u_i_integer_minus);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return rat_plusmin_rat(ptr, x, y, C_s_a_u_i_integer_minus);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_diff = C_s_a_i_minus(ptr, 2, x, C_u_i_cplxnum_real(y)),
             imag = C_s_a_i_negate(ptr, 1, C_u_i_cplxnum_imag(y));
      if (C_truep(C_u_i_inexactp(real_diff)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_diff, imag);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", y);
    }
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    if (!C_immediatep(y) && C_block_header(y) == C_CPLXNUM_TAG) {
      C_word real_diff, imag_diff;
      real_diff = C_s_a_i_minus(ptr,2,C_u_i_cplxnum_real(x),C_u_i_cplxnum_real(y));
      imag_diff = C_s_a_i_minus(ptr,2,C_u_i_cplxnum_imag(x),C_u_i_cplxnum_imag(y));
      if (C_truep(C_u_i_zerop2(imag_diff))) return real_diff;
      else return C_cplxnum(ptr, real_diff, imag_diff);
    } else {
      C_word real_diff = C_s_a_i_minus(ptr, 2, C_u_i_cplxnum_real(x), y),
             imag = C_u_i_cplxnum_imag(x);
      if (C_truep(C_u_i_inexactp(real_diff)))
        imag = C_a_i_exact_to_inexact(ptr, 1, imag);
      return C_cplxnum(ptr, real_diff, imag);
    }
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "-", x);
  }
}

C_regparm C_word C_fcall
C_s_a_u_i_integer_minus(C_word **ptr, C_word n, C_word x, C_word y)
{
  if ((x & y) & C_FIXNUM_BIT) {
    return C_a_i_fixnum_difference(ptr, 2, x, y);
  } else {
    C_word ab[C_SIZEOF_FIX_BIGNUM * 2 + C_SIZEOF_BIGNUM_WRAPPER], *a = ab;
    if (x & C_FIXNUM_BIT) x = C_a_u_i_fix_to_big(&a, x);
    if (y & C_FIXNUM_BIT) y = C_a_u_i_fix_to_big(&a, y);

    if (C_bignum_negativep(x)) {
      if (C_bignum_negativep(y)) {
        return bignum_minus_unsigned(ptr, y, x);
      } else {
        return bignum_plus_unsigned(ptr, x, y, C_SCHEME_TRUE);
      }
    } else {
      if (C_bignum_negativep(y)) {
        return bignum_plus_unsigned(ptr, x, y, C_SCHEME_FALSE);
      } else {
        return bignum_minus_unsigned(ptr, x, y);
      }
    }
  }
}

void C_ccall C_minus(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word next_val, result, prev_result;
  C_word ab[2][C_SIZEOF_CPLXNUM + C_SIZEOF_RATNUM*2 + C_SIZEOF_FIX_BIGNUM * 4], *a;

  if (c < 3) {
    C_bad_min_argc(c, 3);
  } else if (c == 3) {
    a = ab[0];
    C_kontinue(k, C_s_a_i_negate(&a, 1, av[ 2 ]));
  } else {
    prev_result = result = av[ 2 ];
    c -= 3;
    av += 3;

    while (c--) {
      next_val = *(av++);
      a = ab[c&1]; /* One may hold last iteration result, the other is unused */
      result = C_s_a_i_minus(&a, 2, result, next_val);
      result = move_buffer_object(&a, ab[(c+1)&1], result);
      clear_buffer_object(ab[(c+1)&1], prev_result);
      prev_result = result;
    }

    C_kontinue(k, result);
  }
}


static C_regparm void
integer_divrem(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r)
{
  if (!(y & C_FIXNUM_BIT)) { /* y is bignum. */
    if (x & C_FIXNUM_BIT) {
      /* abs(x) < abs(y), so it will always be [0, x] except for this case: */
      if (x == C_fix(C_MOST_NEGATIVE_FIXNUM) &&
          C_bignum_negated_fitsinfixnump(y)) {
        if (q != NULL) *q = C_fix(-1);
        if (r != NULL) *r = C_fix(0);
      } else {
        if (q != NULL) *q = C_fix(0);
        if (r != NULL) *r = x;
      }
    } else {
      bignum_divrem(ptr, x, y, q, r);
    }
  } else if (x & C_FIXNUM_BIT) { /* both x and y are fixnum. */
    if (q != NULL) *q = C_a_i_fixnum_quotient_checked(ptr, 2, x, y);
    if (r != NULL) *r = C_i_fixnum_remainder_checked(x, y);
  } else { /* x is bignum, y is fixnum. */
    C_word absy = (y & C_INT_SIGN_BIT) ? -C_unfix(y) : C_unfix(y);

    if (y == C_fix(1)) {
      if (q != NULL) *q = x;
      if (r != NULL) *r = C_fix(0);
    } else if (y == C_fix(-1)) {
      if (q != NULL) *q = C_s_a_u_i_integer_negate(ptr, 1, x);
      if (r != NULL) *r = C_fix(0);
    } else if (C_fitsinbignumhalfdigitp(absy) ||
               ((((C_uword)1 << (C_ilen(absy)-1)) == absy) &&
                C_fitsinfixnump(absy))) {
      assert(y != C_fix(0)); /* _must_ be checked by caller */
      if (q != NULL) {
        bignum_destructive_divide_unsigned_small(ptr, x, y, q, r);
      } else { /* We assume r isn't NULL here (that makes no sense) */
        C_word rem;
	C_uword next_power = (C_uword)1 << (C_ilen(absy)-1);

	if (next_power == absy) { /* Is absy a power of two? */
          rem = *(C_bignum_digits(x)) & (next_power - 1);
        } else { /* Too bad, we have to do some real work */
          rem = bignum_remainder_unsigned_halfdigit(x, absy);
	}
        *r = C_bignum_negativep(x) ? C_fix(-rem) : C_fix(rem);
      }
    } else {			/* Just divide it as two bignums */
      C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab;
      bignum_divrem(ptr, x, C_a_u_i_fix_to_big(&a, y), q, r);
      if (q != NULL) *q = move_buffer_object(ptr, ab, *q);
      if (r != NULL) *r = move_buffer_object(ptr, ab, *r);
    }
  }
}

/* This _always_ needs two bignum wrappers in ptr! */
static C_regparm void
bignum_divrem(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r)
{
  C_word q_negp = C_mk_bool(C_bignum_negativep(y) != C_bignum_negativep(x)),
         r_negp = C_mk_bool(C_bignum_negativep(x)), res, size;

  switch(bignum_cmp_unsigned(x, y)) {
  case 0:
    if (q != NULL) *q = C_truep(q_negp) ? C_fix(-1) : C_fix(1);
    if (r != NULL) *r = C_fix(0);
    break;
  case -1:
    if (q != NULL) *q = C_fix(0);
    if (r != NULL) *r = x;
    break;
  case 1:
  default:
    res = C_SCHEME_FALSE;
    size = C_bignum_size(x) - C_bignum_size(y);
    if (C_bignum_size(y) > C_BURNIKEL_ZIEGLER_THRESHOLD &&
        size > C_BURNIKEL_ZIEGLER_THRESHOLD) {
      res = bignum_divide_burnikel_ziegler(ptr, x, y, q, r);
    }

    if (!C_truep(res)) {
      bignum_divide_unsigned(ptr, x, y, q, q_negp, r, r_negp);
      if (q != NULL) *q = C_bignum_simplify(*q);
      if (r != NULL) *r = C_bignum_simplify(*r);
    }
    break;
  }
}

/* Burnikel-Ziegler recursive division: Split high number (x) in three
 * or four parts and divide by the lowest number (y), split in two
 * parts.  There are descriptions in [MpNT, 4.2], [MCA, 1.4.3] and the
 * paper "Fast Recursive Division" by Christoph Burnikel & Joachim
 * Ziegler is freely available.  There is also a description in Karl
 * Hasselstrom's thesis "Fast Division of Integers".
 *
 * The complexity of this is supposedly O(r*s^{log(3)-1} + r*log(s)),
 * where s is the length of x, and r is the length of y (in digits).
 *
 * TODO: See if it's worthwhile to implement "division without remainder"
 * from the Burnikel-Ziegler paper.
 */
static C_regparm C_word
bignum_divide_burnikel_ziegler(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*9], *a = ab,
         lab[2][C_SIZEOF_FIX_BIGNUM*10], *la,
         q_negp = (C_bignum_negativep(y) ? C_mk_nbool(C_bignum_negativep(x)) :
                   C_mk_bool(C_bignum_negativep(x))),
         r_negp = C_mk_bool(C_bignum_negativep(x)), s, m, n, i, j, l, shift,
         yhi, ylo, zi, zi_orig, newx, newy, quot, qi, ri;

  /* Ran out of stack?  Fall back to non-recursive division */
  C_stack_check1(return C_SCHEME_FALSE);

  x = C_s_a_u_i_integer_abs(&a, 1, x);
  y = C_s_a_u_i_integer_abs(&a, 1, y);

  /* Define m as min{2^k|(2^k)*BURNIKEL_ZIEGLER_DIFF_THRESHOLD > s}
   * This ensures we shift as little as possible (less pressure
   * on the GC) while maintaining a power of two until we drop
   * below the threshold, so we can always split N in half.
   */
  s = C_bignum_size(y);
  m = 1 << C_ilen(s / C_BURNIKEL_ZIEGLER_THRESHOLD);
  j = (s+m-1) / m;              /* j = s/m, rounded up */
  n = j * m;

  shift = (C_BIGNUM_DIGIT_LENGTH * n) - integer_length_abs(y);
  newx = C_s_a_i_arithmetic_shift(&a, 2, x, C_fix(shift));
  newy = C_s_a_i_arithmetic_shift(&a, 2, y, C_fix(shift));
  if (shift != 0) {
    clear_buffer_object(ab, x);
    clear_buffer_object(ab, y);
  }
  x = newx;
  y = newy;

  /* l needs to be the smallest value so that a < base^{l*n}/2 */
  l = (C_bignum_size(x) + n) / n;
  if ((C_BIGNUM_DIGIT_LENGTH * l) == integer_length_abs(x)) l++;
  l = nmax(l, 2);

  yhi = bignum_extract_digits(&a, 3, y, C_fix(n >> 1), C_SCHEME_FALSE);
  ylo = bignum_extract_digits(&a, 3, y, C_fix(0), C_fix(n >> 1));

  s = (l - 2) * n * C_BIGNUM_DIGIT_LENGTH;
  zi_orig = zi = C_s_a_i_arithmetic_shift(&a, 2, x, C_fix(-s));
  quot = C_fix(0);

  for(i = l - 2; i >= 0; --i) {
    la = lab[i&1];

    burnikel_ziegler_2n_div_1n(&la, zi, y, yhi, ylo, C_fix(n), &qi, &ri);

    newx = C_s_a_i_arithmetic_shift(&la, 2, quot, C_fix(n*C_BIGNUM_DIGIT_LENGTH));
    clear_buffer_object(lab, quot);
    quot = C_s_a_u_i_integer_plus(&la, 2, newx, qi);
    move_buffer_object(&la, lab[(i+1)&1], quot);
    clear_buffer_object(lab, newx);
    clear_buffer_object(lab, qi);

    if (i > 0) {  /* Set z_{i-1} = [r{i}, x{i-1}] */
      newx = bignum_extract_digits(&la, 3, x, C_fix(n * (i-1)), C_fix(n * i));
      newy = C_s_a_i_arithmetic_shift(&la, 2, ri, C_fix(n*C_BIGNUM_DIGIT_LENGTH));
      clear_buffer_object(lab, zi);
      zi = C_s_a_u_i_integer_plus(&la, 2, newx, newy);
      move_buffer_object(&la, lab[(i+1)&1], zi);
      move_buffer_object(&la, lab[(i+1)&1], quot);
      clear_buffer_object(lab, newx);
      clear_buffer_object(lab, newy);
      clear_buffer_object(lab, ri);
    }
  }
  clear_buffer_object(ab, x);
  clear_buffer_object(ab, y);
  clear_buffer_object(ab, yhi);
  clear_buffer_object(ab, ylo);
  clear_buffer_object(ab, zi_orig);
  clear_buffer_object(lab, zi);

  if (q != NULL) {
    if (C_truep(q_negp)) {
      newx = C_s_a_u_i_integer_negate(&la, 1, quot);
      clear_buffer_object(lab, quot);
      quot = newx;
    }
    *q = move_buffer_object(ptr, lab, quot);
  }
  clear_buffer_object(lab, quot);

  if (r != NULL) {
    newx = C_s_a_i_arithmetic_shift(&la, 2, ri, C_fix(-shift));
    if (C_truep(r_negp)) {
      newy = C_s_a_u_i_integer_negate(ptr, 1, newx);
      clear_buffer_object(lab, newx);
      newx = newy;
    }
    *r = move_buffer_object(ptr, lab, newx);
  }
  clear_buffer_object(lab, ri);

  return C_SCHEME_TRUE;
}

static C_regparm void
burnikel_ziegler_3n_div_2n(C_word **ptr, C_word a12, C_word a3, C_word b, C_word b1, C_word b2, C_word n, C_word *q, C_word *r)
{
  C_word kab[C_SIZEOF_FIX_BIGNUM*6 + C_SIZEOF_BIGNUM(2)], *ka = kab,
         lab[2][C_SIZEOF_FIX_BIGNUM*4], *la,
         size, tmp, less, qhat, rhat, r1, r1a3, i = 0;

  size = C_unfix(n) * C_BIGNUM_DIGIT_LENGTH;
  tmp = C_s_a_i_arithmetic_shift(&ka, 2, a12, C_fix(-size));
  less = C_i_integer_lessp(tmp, b1); /* a1 < b1 ? */
  clear_buffer_object(kab, tmp);

  if (C_truep(less)) {
    C_word atmpb[C_SIZEOF_FIX_BIGNUM*2], *atmp = atmpb, b11, b12, halfn;

    halfn = C_fix(C_unfix(n) >> 1);
    b11 = bignum_extract_digits(&atmp, 3, b1, halfn, C_SCHEME_FALSE);
    b12 = bignum_extract_digits(&atmp, 3, b1, C_fix(0), halfn);

    burnikel_ziegler_2n_div_1n(&ka, a12, b1, b11, b12, n, &qhat, &r1);
    qhat = move_buffer_object(&ka, atmpb, qhat);
    r1 = move_buffer_object(&ka, atmpb, r1);

    clear_buffer_object(atmpb, b11);
    clear_buffer_object(atmpb, b12);
  } else {
    C_word atmpb[C_SIZEOF_FIX_BIGNUM*5], *atmp = atmpb, tmp2;

    tmp = C_s_a_i_arithmetic_shift(&atmp, 2, C_fix(1), C_fix(size));
    qhat = C_s_a_u_i_integer_minus(&ka, 2, tmp, C_fix(1));  /* B^n - 1 */
    qhat = move_buffer_object(&ka, atmpb, qhat);
    clear_buffer_object(atmpb, tmp);

    /* r1 = (a12 - b1*B^n) + b1 */
    tmp = C_s_a_i_arithmetic_shift(&atmp, 2, b1, C_fix(size));
    tmp2 = C_s_a_u_i_integer_minus(&atmp, 2, a12, tmp);
    r1 = C_s_a_u_i_integer_plus(&ka, 2, tmp2, b1);
    r1 = move_buffer_object(&ka, atmpb, r1);
    clear_buffer_object(atmpb, tmp);
    clear_buffer_object(atmpb, tmp2);
  }

  tmp = C_s_a_i_arithmetic_shift(&ka, 2, r1, C_fix(size));
  clear_buffer_object(kab, r1);
  r1a3 = C_s_a_u_i_integer_plus(&ka, 2, tmp, a3);
  b2 = C_s_a_u_i_integer_times(&ka, 2, qhat, b2);

  la = lab[0];
  rhat = C_s_a_u_i_integer_minus(&la, 2, r1a3, b2);
  rhat = move_buffer_object(&la, kab, rhat);
  qhat = move_buffer_object(&la, kab, qhat);

  clear_buffer_object(kab, tmp);
  clear_buffer_object(kab, r1a3);
  clear_buffer_object(kab, b2);

  while(C_truep(C_i_negativep(rhat))) {
    la = lab[(++i)&1];
    /* rhat += b */
    r1 = C_s_a_u_i_integer_plus(&la, 2, rhat, b);
    tmp = move_buffer_object(&la, lab[(i-1)&1], r1);
    clear_buffer_object(lab[(i-1)&1], r1);
    clear_buffer_object(lab[(i-1)&1], rhat);
    clear_buffer_object(kab, rhat);
    rhat = tmp;

    /* qhat -= 1 */
    r1 = C_s_a_u_i_integer_minus(&la, 2, qhat, C_fix(1));
    tmp = move_buffer_object(&la, lab[(i-1)&1], r1);
    clear_buffer_object(lab[(i-1)&1], r1);
    clear_buffer_object(lab[(i-1)&1], qhat);
    clear_buffer_object(kab, qhat);
    qhat = tmp;
  }

  if (q != NULL) *q = move_buffer_object(ptr, lab, qhat);
  if (r != NULL) *r = move_buffer_object(ptr, lab, rhat);
  clear_buffer_object(lab, qhat);
  clear_buffer_object(lab, rhat);
}

static C_regparm void
burnikel_ziegler_2n_div_1n(C_word **ptr, C_word a, C_word b, C_word b1, C_word b2, C_word n, C_word *q, C_word *r)
{
  C_word kab[2][C_SIZEOF_FIX_BIGNUM*7], *ka, a12, a3, a4,
         q1 = C_fix(0), r1, q2 = C_fix(0), r2, *qp;
  int stack_full = 0;

  C_stack_check1(stack_full = 1);

  n = C_unfix(n);
  if (stack_full || (n & 1) || (n < C_BURNIKEL_ZIEGLER_THRESHOLD)) {
    integer_divrem(ptr, a, b, q, r);
  } else {
    ka = kab[0];
    a12 = bignum_extract_digits(&ka, 3, a, C_fix(n), C_SCHEME_FALSE);
    a3 = bignum_extract_digits(&ka, 3, a, C_fix(n >> 1), C_fix(n));

    qp = (q == NULL) ? NULL : &q1;
    ka = kab[1];
    burnikel_ziegler_3n_div_2n(&ka, a12, a3, b, b1, b2, C_fix(n >> 1), qp, &r1);
    q1 = move_buffer_object(&ka, kab[0], q1);
    r1 = move_buffer_object(&ka, kab[0], r1);
    clear_buffer_object(kab[0], a12);
    clear_buffer_object(kab[0], a3);

    a4 = bignum_extract_digits(&ka, 3, a, C_fix(0), C_fix(n >> 1));

    qp = (q == NULL) ? NULL : &q2;
    ka = kab[0];
    burnikel_ziegler_3n_div_2n(&ka, r1, a4, b, b1, b2, C_fix(n >> 1), qp, r);
    if (r != NULL) *r = move_buffer_object(ptr, kab[0], *r);
    clear_buffer_object(kab[1], r1);

    if (q != NULL) {
      C_word halfn_bits = (n >> 1) * C_BIGNUM_DIGIT_LENGTH;
      r1 = C_s_a_i_arithmetic_shift(&ka, 2, q1, C_fix(halfn_bits));
      *q = C_s_a_i_plus(ptr, 2, r1, q2); /* q = [q1, q2] */
      *q = move_buffer_object(ptr, kab[0], *q);
      clear_buffer_object(kab[0], r1);
      clear_buffer_object(kab[1], q1);
      clear_buffer_object(kab[0], q2);
    }
    clear_buffer_object(kab[1], a4);
  }
}


static C_regparm C_word bignum_remainder_unsigned_halfdigit(C_word x, C_word y)
{
  C_uword *start = C_bignum_digits(x),
          *scan = start + C_bignum_size(x),
          rem = 0, two_digits;

  assert((y > 1) && (C_fitsinbignumhalfdigitp(y)));
  while (start < scan) {
    two_digits = (*--scan);
    rem = C_BIGNUM_DIGIT_COMBINE(rem, C_BIGNUM_DIGIT_HI_HALF(two_digits)) % y;
    rem = C_BIGNUM_DIGIT_COMBINE(rem, C_BIGNUM_DIGIT_LO_HALF(two_digits)) % y;
  }
  return rem;
}

/* There doesn't seem to be a way to return two values from inline functions */
void C_ccall C_quotient_and_remainder(C_word c, C_word *av)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*4+C_SIZEOF_FLONUM*2], *a = ab,
    nx = C_SCHEME_FALSE, ny = C_SCHEME_FALSE,
    q, r, k, x, y;

  if (c != 4) C_bad_argc_2(c, 4, av[ 0 ]);

  k = av[ 1 ];
  x = av[ 2 ];
  y = av[ 3 ];

  if (!C_truep(C_i_integerp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "quotient&remainder", x);
  if (!C_truep(C_i_integerp(y)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "quotient&remainder", y);
  if (C_truep(C_i_zerop(y))) C_div_by_zero_error("quotient&remainder");

  if (C_truep(C_i_flonump(x))) {
    if C_truep(C_i_flonump(y)) {
      double dx = C_flonum_magnitude(x), dy = C_flonum_magnitude(y), tmp;

      C_modf(dx / dy, &tmp);
      q = C_flonum(&a, tmp);
      r = C_flonum(&a, dx - tmp * dy);
      /* reuse av */
      av[ 0 ] = C_SCHEME_UNDEFINED;
      /* av[ 1 ] = k; */ /* stays the same */
      av[ 2 ] = q;
      av[ 3 ] = r;
      C_values(4, av);
    }
    x = nx = C_s_a_u_i_flo_to_int(&a, 1, x);
  }
  if (C_truep(C_i_flonump(y))) {
    y = ny = C_s_a_u_i_flo_to_int(&a, 1, y);
  }

  integer_divrem(&a, x, y, &q, &r);

  if (C_truep(nx) || C_truep(ny)) {
    C_word newq, newr;
    newq = C_a_i_exact_to_inexact(&a, 1, q);
    newr = C_a_i_exact_to_inexact(&a, 1, r);
    clear_buffer_object(ab, q);
    clear_buffer_object(ab, r);
    q = newq;
    r = newr;

    clear_buffer_object(ab, nx);
    clear_buffer_object(ab, ny);
  }
  /* reuse av */
  av[ 0 ] = C_SCHEME_UNDEFINED;
  /* av[ 1 ] = k; */ /* stays the same */
  av[ 2 ] = q;
  av[ 3 ] = r;
  C_values(4, av);
}

void C_ccall C_u_integer_quotient_and_remainder(C_word c, C_word *av)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*2], *a = ab, q, r;

  if (av[ 3 ] == C_fix(0)) C_div_by_zero_error("quotient&remainder");

  integer_divrem(&a, av[ 2 ], av[ 3 ], &q, &r);

  /* reuse av */
  av[ 0 ] = C_SCHEME_UNDEFINED;
  /* av[ 1 ] = k; */ /* stays the same */
  av[ 2 ] = q;
  av[ 3 ] = r;
  C_values(4, av);
}

C_regparm C_word C_fcall
C_s_a_i_remainder(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*4+C_SIZEOF_FLONUM*2], *a = ab, r,
         nx = C_SCHEME_FALSE, ny = C_SCHEME_FALSE;

  if (!C_truep(C_i_integerp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "remainder", x);
  if (!C_truep(C_i_integerp(y)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "remainder", y);
  if (C_truep(C_i_zerop(y))) C_div_by_zero_error("remainder");

  if (C_truep(C_i_flonump(x))) {
    if C_truep(C_i_flonump(y)) {
      double dx = C_flonum_magnitude(x), dy = C_flonum_magnitude(y), tmp;

      C_modf(dx / dy, &tmp);
      return C_flonum(ptr, dx - tmp * dy);
    }
    x = nx = C_s_a_u_i_flo_to_int(&a, 1, x);
  }
  if (C_truep(C_i_flonump(y))) {
    y = ny = C_s_a_u_i_flo_to_int(&a, 1, y);
  }

  integer_divrem(&a, x, y, NULL, &r);

  if (C_truep(nx) || C_truep(ny)) {
    C_word newr = C_a_i_exact_to_inexact(ptr, 1, r);
    clear_buffer_object(ab, r);
    r = newr;

    clear_buffer_object(ab, nx);
    clear_buffer_object(ab, ny);
  }
  return move_buffer_object(ptr, ab, r);
}

C_regparm C_word C_fcall
C_s_a_u_i_integer_remainder(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*2], *a = ab, r;
  if (y == C_fix(0)) C_div_by_zero_error("remainder");
  integer_divrem(&a, x, y, NULL, &r);
  return move_buffer_object(ptr, ab, r);
}

/* Modulo's sign follows y (whereas remainder's sign follows x) */
C_regparm C_word C_fcall
C_s_a_i_modulo(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab, r,
         nx = C_SCHEME_FALSE, ny = C_SCHEME_FALSE;

  if (!C_truep(C_i_integerp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "modulo", x);
  if (!C_truep(C_i_integerp(y)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "modulo", y);
  if (C_truep(C_i_zerop(y))) C_div_by_zero_error("modulo");

  if (C_truep(C_i_flonump(x))) {
    if C_truep(C_i_flonump(y)) {
      double dx = C_flonum_magnitude(x), dy = C_flonum_magnitude(y), tmp;

      C_modf(dx / dy, &tmp);
      tmp = dx - tmp * dy;
      if ((dx > 0.0) != (dy > 0.0) && tmp != 0.0) {
        return C_flonum(ptr, tmp + dy);
      } else {
        return C_flonum(ptr, tmp);
      }
    }
    x = nx = C_s_a_u_i_flo_to_int(&a, 1, x);
  }
  if (C_truep(C_i_flonump(y))) {
    y = ny = C_s_a_u_i_flo_to_int(&a, 1, y);
  }

  integer_divrem(&a, x, y, NULL, &r);
  if (C_i_positivep(y) != C_i_positivep(r) && r != C_fix(0)) {
    C_word m = C_s_a_i_plus(ptr, 2, r, y);
    m = move_buffer_object(ptr, ab, m);
    clear_buffer_object(ab, r);
    r = m;
  }

  if (C_truep(nx) || C_truep(ny)) {
    C_word newr = C_a_i_exact_to_inexact(ptr, 1, r);
    clear_buffer_object(ab, r);
    r = newr;

    clear_buffer_object(ab, nx);
    clear_buffer_object(ab, ny);
  }

  return move_buffer_object(ptr, ab, r);
}

C_regparm C_word C_fcall
C_s_a_u_i_integer_modulo(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab, r;
  if (y == C_fix(0)) C_div_by_zero_error("modulo");

  integer_divrem(&a, x, y, NULL, &r);
  if (C_i_positivep(y) != C_i_positivep(r) && r != C_fix(0)) {
    C_word m = C_s_a_u_i_integer_plus(ptr, 2, r, y);
    m = move_buffer_object(ptr, ab, m);
    clear_buffer_object(ab, r);
    r = m;
  }
  return move_buffer_object(ptr, ab, r);
}

C_regparm C_word C_fcall
C_s_a_i_quotient(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*4+C_SIZEOF_FLONUM*2], *a = ab, q,
         nx = C_SCHEME_FALSE, ny = C_SCHEME_FALSE;

  if (!C_truep(C_i_integerp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "quotient", x);
  if (!C_truep(C_i_integerp(y)))
    barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "quotient", y);
  if (C_truep(C_i_zerop(y))) C_div_by_zero_error("quotient");

  if (C_truep(C_i_flonump(x))) {
    if C_truep(C_i_flonump(y)) {
      double dx = C_flonum_magnitude(x), dy = C_flonum_magnitude(y), tmp;

      C_modf(dx / dy, &tmp);
      return C_flonum(ptr, tmp);
    }
    x = nx = C_s_a_u_i_flo_to_int(&a, 1, x);
  }
  if (C_truep(C_i_flonump(y))) {
    y = ny = C_s_a_u_i_flo_to_int(&a, 1, y);
  }

  integer_divrem(&a, x, y, &q, NULL);

  if (C_truep(nx) || C_truep(ny)) {
    C_word newq = C_a_i_exact_to_inexact(ptr, 1, q);
    clear_buffer_object(ab, q);
    q = newq;

    clear_buffer_object(ab, nx);
    clear_buffer_object(ab, ny);
  }
  return move_buffer_object(ptr, ab, q);
}

C_regparm C_word C_fcall
C_s_a_u_i_integer_quotient(C_word **ptr, C_word n, C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*2], *a = ab, q;
  if (y == C_fix(0)) C_div_by_zero_error("quotient");
  integer_divrem(&a, x, y, &q, NULL);
  return move_buffer_object(ptr, ab, q);
}


/* For help understanding this algorithm, see:
   Knuth, Donald E., "The Art of Computer Programming",
   volume 2, "Seminumerical Algorithms"
   section 4.3.1, "Multiple-Precision Arithmetic".

   [Yeah, that's a nice book but that particular section is not
   helpful at all, which is also pointed out by P. Brinch Hansen's
   "Multiple-Length Division Revisited: A Tour Of The Minefield".
   That's a more down-to-earth step-by-step explanation of the
   algorithm.  Add to this the C implementation in Hacker's Delight
   (section 9-2, p141--142) and you may be able to grok this...
   ...barely, if you're as math-challenged as I am -- sjamaan]

   This assumes that numerator >= denominator!
*/
static void
bignum_divide_unsigned(C_word **ptr, C_word num, C_word denom, C_word *q, C_word q_negp, C_word *r, C_word r_negp)
{
  C_word quotient = C_SCHEME_UNDEFINED, remainder = C_SCHEME_UNDEFINED,
         return_rem = C_mk_nbool(r == NULL), size;

  if (q != NULL) {
    size = C_fix(C_bignum_size(num) + 1 - C_bignum_size(denom));
    quotient = C_allocate_scratch_bignum(ptr, size, q_negp, C_SCHEME_FALSE);
  }

  /* An object is always required to receive the remainder */
  size = C_fix(C_bignum_size(num) + 1);
  remainder = C_allocate_scratch_bignum(ptr, size, r_negp, C_SCHEME_FALSE);
  bignum_destructive_divide_full(num, denom, quotient, remainder, return_rem);

  /* Simplification must be done by the caller, for consistency */
  if (q != NULL) *q = quotient;
  if (r == NULL) {
    C_mutate_scratch_slot(NULL, C_internal_bignum_vector(remainder));
  } else {
    *r = remainder;
  }
}

/* Compare two numbers as ratnums.  Either may be rat-, fix- or bignums */
static C_word rat_cmp(C_word x, C_word y)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM*4], *a = ab, x1, x2, y1, y2,
         s, t, ssize, tsize, result, negp;
  C_uword *scan;

  /* Check for 1 or 0; if x or y is this, the other must be the ratnum */
  if (x == C_fix(0)) {	      /* Only the sign of y1 matters */
    return basic_cmp(x, C_u_i_ratnum_num(y), "ratcmp", 0);
  } else if (x == C_fix(1)) { /* x1*y1 <> x2*y2 --> y2 <> y1 | x1/x2 = 1/1 */
    return basic_cmp(C_u_i_ratnum_denom(y), C_u_i_ratnum_num(y), "ratcmp", 0);
  } else if (y == C_fix(0)) { /* Only the sign of x1 matters */
    return basic_cmp(C_u_i_ratnum_num(x), y, "ratcmp", 0);
  } else if (y == C_fix(1)) { /* x1*y1 <> x2*y2 --> x1 <> x2 | y1/y2 = 1/1 */
    return basic_cmp(C_u_i_ratnum_num(x), C_u_i_ratnum_denom(x), "ratcmp", 0);
  }

  /* Extract components x=x1/x2 and y=y1/y2 */
  if (x & C_FIXNUM_BIT || C_truep(C_bignump(x))) {
    x1 = x;
    x2 = C_fix(1);
  } else {
    x1 = C_u_i_ratnum_num(x);
    x2 = C_u_i_ratnum_denom(x);
  }

  if (y & C_FIXNUM_BIT || C_truep(C_bignump(y))) {
    y1 = y;
    y2 = C_fix(1);
  } else {
    y1 = C_u_i_ratnum_num(y);
    y2 = C_u_i_ratnum_denom(y);
  }

  /* We only want to deal with bignums (this is tricky enough) */
  if (x1 & C_FIXNUM_BIT) x1 = C_a_u_i_fix_to_big(&a, x1);
  if (x2 & C_FIXNUM_BIT) x2 = C_a_u_i_fix_to_big(&a, x2);
  if (y1 & C_FIXNUM_BIT) y1 = C_a_u_i_fix_to_big(&a, y1);
  if (y2 & C_FIXNUM_BIT) y2 = C_a_u_i_fix_to_big(&a, y2);

  /* We multiply using schoolbook method, so this will be very slow in
   * extreme cases.  This is a tradeoff we make so that comparisons
   * are inlineable, which makes a big difference for the common case.
   */
  ssize = C_bignum_size(x1) + C_bignum_size(y2);
  negp = C_mk_bool(C_bignum_negativep(x1));
  s = allocate_tmp_bignum(C_fix(ssize), negp, C_SCHEME_TRUE);
  bignum_digits_multiply(x1, y2, s); /* Swap args if x1 < y2? */

  tsize = C_bignum_size(y1) + C_bignum_size(x2);
  negp = C_mk_bool(C_bignum_negativep(y1));
  t = allocate_tmp_bignum(C_fix(tsize), negp, C_SCHEME_TRUE);
  bignum_digits_multiply(y1, x2, t); /* Swap args if y1 < x2? */

  /* Shorten the numbers if needed */
  for (scan = C_bignum_digits(s)+ssize-1; *scan == 0; scan--) ssize--;
  C_bignum_mutate_size(s, ssize);
  for (scan = C_bignum_digits(t)+tsize-1; *scan == 0; scan--) tsize--;
  C_bignum_mutate_size(t, tsize);

  result = C_i_bignum_cmp(s, t);

  free_tmp_bignum(t);
  free_tmp_bignum(s);
  return result;
}

C_regparm double C_fcall C_bignum_to_double(C_word bignum)
{
  double accumulator = 0;
  C_uword *start = C_bignum_digits(bignum),
          *scan = start + C_bignum_size(bignum);
  while (start < scan) {
    accumulator *= (C_uword)1 << C_BIGNUM_HALF_DIGIT_LENGTH;
    accumulator *= (C_uword)1 << C_BIGNUM_HALF_DIGIT_LENGTH;
    accumulator += (*--scan);
  }
  return(C_bignum_negativep(bignum) ? -accumulator : accumulator);
}

C_regparm C_word C_fcall
C_s_a_u_i_flo_to_int(C_word **ptr, C_word n, C_word x)
{
  int exponent;
  double significand = frexp(C_flonum_magnitude(x), &exponent);

  assert(C_truep(C_u_i_fpintegerp(x)));

  if (exponent <= 0) {
    return C_fix(0);
  } else if (exponent == 1) { /* TODO: check significand * 2^exp fits fixnum? */
    return significand < 0.0 ? C_fix(-1) : C_fix(1);
  } else {
    C_word size, negp = C_mk_bool(C_flonum_magnitude(x) < 0.0), result;
    C_uword *start, *end;

    size = C_fix(C_BIGNUM_BITS_TO_DIGITS(exponent));
    result = C_allocate_scratch_bignum(ptr, size, negp, C_SCHEME_FALSE);

    start = C_bignum_digits(result);
    end = start + C_bignum_size(result);

    fabs_frexp_to_digits(exponent, fabs(significand), start, end);
    return C_bignum_simplify(result);
  }
}

static void
fabs_frexp_to_digits(C_uword exp, double sign, C_uword *start, C_uword *scan)
{
  C_uword digit, odd_bits = exp % C_BIGNUM_DIGIT_LENGTH;

  assert(C_isfinite(sign));
  assert(0.5 <= sign && sign < 1); /* Guaranteed by frexp() and fabs() */
  assert((scan - start) == C_BIGNUM_BITS_TO_DIGITS(exp));
  
  if (odd_bits > 0) { /* Handle most significant digit first */
    sign *= (C_uword)1 << odd_bits;
    digit = (C_uword)sign;
    (*--scan) = digit;
    sign -= (double)digit;
  }

  while (start < scan && sign > 0) {
    sign *= pow(2.0, C_BIGNUM_DIGIT_LENGTH);
    digit = (C_uword)sign;
    (*--scan) = digit;
    sign -= (double)digit;
  }

  /* Finish up by clearing any remaining, lower, digits */
  while (start < scan)
    (*--scan) = 0;
}

/* This is a bit weird: We have to compare flonums as bignums due to
 * precision loss on 64-bit platforms.  For simplicity, we convert
 * fixnums to bignums here.
 */
static C_word int_flo_cmp(C_word intnum, C_word flonum)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM + C_SIZEOF_FLONUM], *a = ab, flo_int, res;
  double i, f;

  f = C_flonum_magnitude(flonum);

  if (C_isnan(f)) {
    return C_SCHEME_FALSE; /* "mu" */
  } else if (C_isinf(f)) {
    return C_fix((f > 0.0) ? -1 : 1); /* x is smaller if f is +inf.0 */
  } else {
    f = modf(f, &i);

    flo_int = C_s_a_u_i_flo_to_int(&a, 1, C_flonum(&a, i));

    res = basic_cmp(intnum, flo_int, "int_flo_cmp", 0);
    clear_buffer_object(ab, flo_int);

    if (res == C_fix(0)) /* Use fraction to break tie. If f > 0, x is smaller */
      return C_fix((f > 0.0) ? -1 : ((f < 0.0) ? 1 : 0));
    else
      return res;
  }
}

/* For convenience (ie, to reduce the degree of mindfuck) */
static C_word flo_int_cmp(C_word flonum, C_word intnum)
{
  C_word res = int_flo_cmp(intnum, flonum);
  switch(res) {
  case C_fix(1): return C_fix(-1);
  case C_fix(-1): return C_fix(1);
  default: return res; /* Can be either C_fix(0) or C_SCHEME_FALSE(!) */
  }
}

/* This code is a bit tedious, but it makes inline comparisons possible! */
static C_word rat_flo_cmp(C_word ratnum, C_word flonum)
{
  C_word ab[C_SIZEOF_FIX_BIGNUM * 4 + C_SIZEOF_FLONUM], *a = ab,
         num, denom, i_int, res, nscaled, iscaled, negp, shift_amount;
  C_uword *scan;
  double i, f;

  f = C_flonum_magnitude(flonum);

  if (C_isnan(f)) {
    return C_SCHEME_FALSE; /* "mu" */
  } else if (C_isinf(f)) {
    return C_fix((f > 0.0) ? -1 : 1); /* x is smaller if f is +inf.0 */
  } else {
    /* Scale up the floating-point number to become a whole integer,
     * and remember power of two (# of bits) to shift the numerator.
     */
    shift_amount = 0;

    /* TODO: This doesn't work for denormalized flonums! */
    while (modf(f, &i) != 0.0) {
      f = ldexp(f, 1);
      shift_amount++;
    }

    i = f; /* TODO: split i and f so it'll work for denormalized flonums */

    num = C_u_i_ratnum_num(ratnum);
    negp = C_i_negativep(num);

    if (C_truep(negp) && i >= 0.0) { /* Save some time if signs differ */
      return C_fix(-1);
    } else if (!C_truep(negp) && i <= 0.0) { /* num is never 0 */
      return C_fix(1);
    } else {
      denom = C_u_i_ratnum_denom(ratnum);
      i_int = C_s_a_u_i_flo_to_int(&a, 1, C_flonum(&a, i));

      /* Multiply the scaled flonum integer by the denominator, and
       * shift the numerator so that they may be directly compared. */
      iscaled = C_s_a_u_i_integer_times(&a, 2, i_int, denom);
      nscaled = C_s_a_i_arithmetic_shift(&a, 2, num, C_fix(shift_amount));

      /* Finally, we're ready to compare them! */
      res = basic_cmp(nscaled, iscaled, "rat_flo_cmp", 0);
      clear_buffer_object(ab, nscaled);
      clear_buffer_object(ab, iscaled);
      clear_buffer_object(ab, i_int);

      return res;
    }
  }
}

static C_word flo_rat_cmp(C_word flonum, C_word ratnum)
{
  C_word res = rat_flo_cmp(ratnum, flonum);
  switch(res) {
  case C_fix(1): return C_fix(-1);
  case C_fix(-1): return C_fix(1);
  default: return res; /* Can be either C_fix(0) or C_SCHEME_FALSE(!) */
  }
}

/* The primitive comparison operator.  eqp should be 1 if we're only
 * interested in equality testing (can speed things up and in case of
 * compnums, equality checking is the only available operation).  This
 * may return #f, in case there is no answer (for NaNs) or as a quick
 * and dirty non-zero answer when eqp is true.  Ugly but effective :)
 */
static C_word basic_cmp(C_word x, C_word y, char *loc, int eqp)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_fix((x < y) ? -1 : ((x > y) ? 1 : 0));
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return int_flo_cmp(x, y);
    } else if (C_truep(C_bignump(y))) {
      C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab;
      return C_i_bignum_cmp(C_a_u_i_fix_to_big(&a, x), y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      if (eqp) return C_SCHEME_FALSE;
      else return rat_cmp(x, y);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      if (eqp) return C_SCHEME_FALSE;
      else barf(C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR, loc, y);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    }
  } else if (C_immediatep(x)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, x);
  } else if (C_block_header(x) == C_FLONUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      return flo_int_cmp(x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      double a = C_flonum_magnitude(x), b = C_flonum_magnitude(y);
      if (C_isnan(a) || C_isnan(b)) return C_SCHEME_FALSE; /* "mu" */
      else return C_fix((a < b) ? -1 : ((a > b) ? 1 : 0));
    } else if (C_truep(C_bignump(y))) {
      return flo_int_cmp(x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      return flo_rat_cmp(x, y);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      if (eqp) return C_SCHEME_FALSE;
      else barf(C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR, loc, y);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    }
  } else if (C_truep(C_bignump(x))) {
    if (y & C_FIXNUM_BIT) {
      C_word ab[C_SIZEOF_FIX_BIGNUM], *a = ab;
      return C_i_bignum_cmp(x, C_a_u_i_fix_to_big(&a, y));
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return int_flo_cmp(x, y);
    } else if (C_truep(C_bignump(y))) {
      return C_i_bignum_cmp(x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      if (eqp) return C_SCHEME_FALSE;
      else return rat_cmp(x, y);
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      if (eqp) return C_SCHEME_FALSE;
      else barf(C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR, loc, y);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    }
  } else if (C_block_header(x) == C_RATNUM_TAG) {
    if (y & C_FIXNUM_BIT) {
      if (eqp) return C_SCHEME_FALSE;
      else return rat_cmp(x, y);
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    } else if (C_block_header(y) == C_FLONUM_TAG) {
      return rat_flo_cmp(x, y);
    } else if (C_truep(C_bignump(y))) {
      if (eqp) return C_SCHEME_FALSE;
      else return rat_cmp(x, y);
    } else if (C_block_header(y) == C_RATNUM_TAG) {
      if (eqp) {
        return C_and(C_and(C_i_integer_equalp(C_u_i_ratnum_num(x),
                                              C_u_i_ratnum_num(y)),
                           C_i_integer_equalp(C_u_i_ratnum_denom(x),
                                              C_u_i_ratnum_denom(y))),
                     C_fix(0));
      } else {
        return rat_cmp(x, y);
      }
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      if (eqp) return C_SCHEME_FALSE;
      else barf(C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR, loc, y);
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    }
  } else if (C_block_header(x) == C_CPLXNUM_TAG) {
    if (!eqp) {
      barf(C_BAD_ARGUMENT_TYPE_COMPLEX_NO_ORDERING_ERROR, loc, x);
    } else if (y & C_FIXNUM_BIT) {
      return C_SCHEME_FALSE;
    } else if (C_immediatep(y)) {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    } else if (C_block_header(y) == C_FLONUM_TAG ||
               C_truep(C_bignump(x)) ||
               C_block_header(y) == C_RATNUM_TAG) {
      return C_SCHEME_FALSE;
    } else if (C_block_header(y) == C_CPLXNUM_TAG) {
      return C_and(C_and(C_i_nequalp(C_u_i_cplxnum_real(x), C_u_i_cplxnum_real(y)),
                         C_i_nequalp(C_u_i_cplxnum_imag(x), C_u_i_cplxnum_imag(y))),
                   C_fix(0));
    } else {
      barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, y);
    }
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, loc, x);
  }
}

static int bignum_cmp_unsigned(C_word x, C_word y)
{
  C_word xlen = C_bignum_size(x), ylen = C_bignum_size(y);

  if (xlen < ylen) {
    return -1;
  } else if (xlen > ylen) {
    return 1;
  } else if (x == y) {
    return 0;
  } else {
    C_uword *startx = C_bignum_digits(x),
            *scanx = startx + xlen,
            *scany = C_bignum_digits(y) + ylen;

    while (startx < scanx) {
      C_uword xdigit = (*--scanx), ydigit = (*--scany);
      if (xdigit < ydigit)
        return -1;
      if (xdigit > ydigit)
        return 1;
    }
    return 0;
  }
}

C_regparm C_word C_fcall C_i_bignum_cmp(C_word x, C_word y)
{
  if (C_bignum_negativep(x)) {
    if (C_bignum_negativep(y)) { /* Largest negative number is smallest */
      return C_fix(bignum_cmp_unsigned(y, x));
    } else {
      return C_fix(-1);
    }
  } else {
    if (C_bignum_negativep(y)) {
      return C_fix(1);
    } else {
      return C_fix(bignum_cmp_unsigned(x, y));
    }
  }
}

void C_ccall C_nequalp(C_word c, C_word *av)
{
  /* C_word closure = av[ 0 ]; */
  C_word k = av[ 1 ];
  C_word x, y, result = C_SCHEME_TRUE;

  c -= 2;
  av += 2;
  if (c == 0) C_kontinue(k, result);
  x = *(av++);

  if (c == 1 && !C_truep(C_i_numberp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "=", x);

  while(--c) {
    y = *(av++);
    result = C_i_nequalp(x, y);
    if (result == C_SCHEME_FALSE) break;
  }

  C_kontinue(k, result);
}

C_regparm C_word C_fcall C_i_nequalp(C_word x, C_word y)
{
   return C_mk_bool(basic_cmp(x, y, "=", 1) == C_fix(0));
}

C_regparm C_word C_fcall C_i_integer_equalp(C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT)
    return C_mk_bool(x == y);
  else if (y & C_FIXNUM_BIT)
    return C_SCHEME_FALSE;
  else
    return C_mk_bool(C_i_bignum_cmp(x, y) == C_fix(0));
}


void C_ccall C_greaterp(C_word c, C_word *av)
{
  C_word x, y,
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    result = C_SCHEME_TRUE;

  c -= 2; 
  av += 2;
  if (c == 0) C_kontinue(k, result);

  x = *(av++);

  if (c == 1 && !C_truep(C_i_numberp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, ">", x);

  while(--c) {
    y = *(av++);
    result = C_i_greaterp(x, y);
    if (result == C_SCHEME_FALSE) break;
    x = y;
  }

  C_kontinue(k, result);
}


C_regparm C_word C_fcall C_i_greaterp(C_word x, C_word y)
{
   return C_mk_bool(basic_cmp(x, y, ">", 0) == C_fix(1));
}

C_regparm C_word C_fcall C_i_integer_greaterp(C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_mk_bool(C_unfix(x) > C_unfix(y));
    } else {
      return C_mk_bool(C_bignum_negativep(y));
    }
  } else if (y & C_FIXNUM_BIT) {
    return C_mk_nbool(C_bignum_negativep(x));
  } else {
    return C_mk_bool(C_i_bignum_cmp(x, y) == C_fix(1));
  }
}

void C_ccall C_lessp(C_word c, C_word *av)
{
  C_word x, y,
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    result = C_SCHEME_TRUE;

  c -= 2; 
  av += 2;
  if (c == 0) C_kontinue(k, result);

  x = *(av++);

  if (c == 1 && !C_truep(C_i_numberp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "<", x);

  while(--c) {
    y = *(av++);
    result = C_i_lessp(x, y);
    if (result == C_SCHEME_FALSE) break;
    x = y;
  }

  C_kontinue(k, result);
}


C_regparm C_word C_fcall C_i_lessp(C_word x, C_word y)
{
   return C_mk_bool(basic_cmp(x, y, "<", 0) == C_fix(-1));
}

C_regparm C_word C_fcall C_i_integer_lessp(C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_mk_bool(C_unfix(x) < C_unfix(y));
    } else {
      return C_mk_nbool(C_bignum_negativep(y));
    }
  } else if (y & C_FIXNUM_BIT) {
    return C_mk_bool(C_bignum_negativep(x));
  } else {
    return C_mk_bool(C_i_bignum_cmp(x, y) == C_fix(-1));
  }
}

void C_ccall C_greater_or_equal_p(C_word c, C_word *av)
{
  C_word x, y,
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    result = C_SCHEME_TRUE;

  c -= 2; 
  av += 2;
  if (c == 0) C_kontinue(k, result);

  x = *(av++);

  if (c == 1 && !C_truep(C_i_numberp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, ">=", x);

  while(--c) {
    y = *(av++);
    result = C_i_greater_or_equalp(x, y);
    if (result == C_SCHEME_FALSE) break;
    x = y;
  }

  C_kontinue(k, result);
}


C_regparm C_word C_fcall C_i_greater_or_equalp(C_word x, C_word y)
{
   C_word res = basic_cmp(x, y, ">=", 0);
   return C_mk_bool(res == C_fix(0) || res == C_fix(1));
}

C_regparm C_word C_fcall C_i_integer_greater_or_equalp(C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_mk_bool(C_unfix(x) >= C_unfix(y));
    } else {
      return C_mk_bool(C_bignum_negativep(y));
    }
  } else if (y & C_FIXNUM_BIT) {
    return C_mk_nbool(C_bignum_negativep(x));
  } else {
    C_word res = C_i_bignum_cmp(x, y);
    return C_mk_bool(res == C_fix(0) || res == C_fix(1));
  }
}

void C_ccall C_less_or_equal_p(C_word c, C_word *av)
{
  C_word x, y,
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    result = C_SCHEME_TRUE;

  c -= 2; 
  av += 2;
  if (c == 0) C_kontinue(k, result);

  x = *(av++);

  if (c == 1 && !C_truep(C_i_numberp(x)))
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "<=", x);

  while(--c) {
    y = *(av++);
    result = C_i_less_or_equalp(x, y);
    if (result == C_SCHEME_FALSE) break;
    x = y;
  }

  C_kontinue(k, result);
}


C_regparm C_word C_fcall C_i_less_or_equalp(C_word x, C_word y)
{
   C_word res = basic_cmp(x, y, "<=", 0);
   return C_mk_bool(res == C_fix(0) || res == C_fix(-1));
}


C_regparm C_word C_fcall C_i_integer_less_or_equalp(C_word x, C_word y)
{
  if (x & C_FIXNUM_BIT) {
    if (y & C_FIXNUM_BIT) {
      return C_mk_bool(C_unfix(x) <= C_unfix(y));
    } else {
      return C_mk_nbool(C_bignum_negativep(y));
    }
  } else if (y & C_FIXNUM_BIT) {
    return C_mk_bool(C_bignum_negativep(x));
  } else {
    C_word res = C_i_bignum_cmp(x, y);
    return C_mk_bool(res == C_fix(0) || res == C_fix(-1));
  }
}


void C_ccall C_gc(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ];
  int f;
  C_word 
    arg, *p,
    size = 0;

  if(c == 3) {
    arg = av[ 2 ];
    f = C_truep(arg);
  }
  else if(c != 2) C_bad_min_argc(c, 2);
  else f = 1;

  C_save(k);
  p = C_temporary_stack;

  if(c == 3) {
    if((arg & C_FIXNUM_BIT) != 0) size = C_unfix(arg);
    else if(arg == C_SCHEME_END_OF_LIST) size = percentage(heap_size, C_heap_growth);
  }

  if(size && !C_heap_size_is_fixed) {
    C_rereclaim2(size, 0);
    C_temporary_stack = C_temporary_stack_bottom;
    gc_2(0, p);
  }
  else if(f) C_fromspace_top = C_fromspace_limit;

  C_reclaim((void *)gc_2, 1);
}


void C_ccall gc_2(C_word c, C_word *av)
{
  C_word k = av[ 0 ];
  C_kontinue(k, C_fix((C_uword)C_fromspace_limit - (C_uword)C_fromspace_top));
}


void C_ccall C_open_file_port(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ], 
    port = av[ 2 ],
    channel = av[ 3 ],
    mode = av[ 4 ];
  C_FILEPTR fp = (C_FILEPTR)NULL;
  C_char fmode[ 4 ];
  C_word n;
  char *buf;

  switch(channel) {
  case C_fix(0): fp = C_stdin; break;
  case C_fix(1): fp = C_stdout; break;
  case C_fix(2): fp = C_stderr; break;
  default:
    n = C_header_size(channel);
    buf = buffer;

    if(n >= STRING_BUFFER_SIZE) {
      if((buf = (char *)C_malloc(n + 1)) == NULL)
	barf(C_OUT_OF_MEMORY_ERROR, "open");
    }

    C_strncpy(buf, C_c_string(channel), n);
    buf[ n ] = '\0';
    if (n != strlen(buf))
      barf(C_ASCIIZ_REPRESENTATION_ERROR, "open", channel);
    n = C_header_size(mode);
    if (n >= sizeof(fmode)) n = sizeof(fmode) - 1;
    C_strncpy(fmode, C_c_string(mode), n);
    fmode[ n ] = '\0';
    if (n != strlen(fmode)) /* Shouldn't happen, but never hurts */
      barf(C_ASCIIZ_REPRESENTATION_ERROR, "open", mode);
    fp = C_fopen(buf, fmode);

    if(buf != buffer) C_free(buf);
  }
  
  C_set_block_item(port, 0, (C_word)fp);
  C_kontinue(k, C_mk_bool(fp != NULL));
}


void C_ccall C_allocate_vector(C_word c, C_word *av)
{
  C_word 
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    size, bvecf, init, align8,
    bytes,
    n, *p;

  if(c != 6) C_bad_argc(c, 6);

  size = av[ 2 ];
  bvecf = av[ 3 ];
  init = av[ 4 ];
  align8 = av[ 5 ];
  n = C_unfix(size);

  if(n > C_HEADER_SIZE_MASK || n < 0)
    barf(C_OUT_OF_RANGE_ERROR, NULL, size, C_fix(C_HEADER_SIZE_MASK));

  if(!C_truep(bvecf)) bytes = C_wordstobytes(n) + sizeof(C_word);
  else bytes = n + sizeof(C_word);

  if(C_truep(align8)) bytes += sizeof(C_word);

  C_save(k);
  C_save(size);
  C_save(init);
  C_save(bvecf);
  C_save(align8);
  C_save(C_fix(bytes));

  if(!C_demand(C_bytestowords(bytes))) {
    /* Allocate on heap: */
    if((C_uword)(C_fromspace_limit - C_fromspace_top) < (bytes + stack_size * 2))
      C_fromspace_top = C_fromspace_limit; /* trigger major GC */
  
    C_save(C_SCHEME_TRUE);
    /* We explicitly pass 7 here, that's the number of things saved.
     * That's the arguments, plus one additional thing: the mode.
     */
    C_reclaim((void *)allocate_vector_2, 7);
  }

  C_save(C_SCHEME_FALSE);
  p = C_temporary_stack;
  C_temporary_stack = C_temporary_stack_bottom;
  allocate_vector_2(0, p);
}


void C_ccall allocate_vector_2(C_word c, C_word *av)
{
  C_word 
    mode = av[ 0 ],
    bytes = C_unfix(av[ 1 ]),
    align8 = av[ 2 ],
    bvecf = av[ 3 ],
    init = av[ 4 ],
    size = C_unfix(av[ 5 ]),
    k = av[ 6 ],
    *v0, v;

  if(C_truep(mode)) {
    while((C_uword)(C_fromspace_limit - C_fromspace_top) < (bytes + stack_size)) {
      if(C_heap_size_is_fixed)
	panic(C_text("out of memory - cannot allocate vector (heap resizing disabled)"));

      C_save(init);
      C_save(k);
      C_rereclaim2(percentage(heap_size, C_heap_growth) + (C_uword)bytes, 0);
      k = C_restore;
      init = C_restore;
    }

    v0 = (C_word *)C_align((C_word)C_fromspace_top);
    C_fromspace_top += C_align(bytes);
  }
  else v0 = C_alloc(C_bytestowords(bytes));

#ifndef C_SIXTY_FOUR
  if(C_truep(align8) && C_aligned8(v0)) ++v0;
#endif

  v = (C_word)v0;

  if(!C_truep(bvecf)) {
    *(v0++) = C_VECTOR_TYPE | size | (C_truep(align8) ? C_8ALIGN_BIT : 0);
  
    while(size--) *(v0++) = init;
  }
  else {
    *(v0++) = C_STRING_TYPE | size;

    if(C_truep(init))
      C_memset(v0, C_character_code(init), size);
  }

  C_kontinue(k, v);
}

static C_word allocate_tmp_bignum(C_word size, C_word negp, C_word initp)
{
  C_word *mem = C_malloc(C_wordstobytes(C_SIZEOF_BIGNUM(C_unfix(size)))),
          bigvec = (C_word)(mem + C_SIZEOF_BIGNUM_WRAPPER);
  if (mem == NULL) abort();     /* TODO: panic */
  
  C_block_header_init(bigvec, C_STRING_TYPE | C_wordstobytes(C_unfix(size)+1));
  C_set_block_item(bigvec, 0, C_truep(negp));

  if (C_truep(initp)) {
    C_memset(((C_uword *)C_data_pointer(bigvec))+1,
             0, C_wordstobytes(C_unfix(size)));
  }

  return C_a_i_bignum_wrapper(&mem, bigvec);
}

C_regparm C_word C_fcall
C_allocate_scratch_bignum(C_word **ptr, C_word size, C_word negp, C_word initp)
{
  C_word big, bigvec = C_scratch_alloc(C_SIZEOF_INTERNAL_BIGNUM_VECTOR(C_unfix(size)));
  
  C_block_header_init(bigvec, C_STRING_TYPE | C_wordstobytes(C_unfix(size)+1));
  C_set_block_item(bigvec, 0, C_truep(negp));

  if (C_truep(initp)) {
    C_memset(((C_uword *)C_data_pointer(bigvec))+1,
             0, C_wordstobytes(C_unfix(size)));
  }

  big = C_a_i_bignum_wrapper(ptr, bigvec);
  C_mutate_scratch_slot(&C_internal_bignum_vector(big), bigvec);
  return big;
}

/* Simplification: scan trailing zeroes, then return a fixnum if the
 * value fits, or trim the bignum's length.  If the bignum was stored
 * in scratch space, we mark it as reclaimable.  This means any
 * references to the original bignum are invalid after simplification!
 */
C_regparm C_word C_fcall C_bignum_simplify(C_word big)
{
  C_uword *start = C_bignum_digits(big),
          *last_digit = start + C_bignum_size(big) - 1,
          *scan = last_digit, tmp;
  int length;

  while (scan >= start && *scan == 0)
    scan--;
  length = scan - start + 1;

  switch(length) {
  case 0:
    if (C_in_scratchspacep(C_internal_bignum_vector(big)))
      C_mutate_scratch_slot(NULL, C_internal_bignum_vector(big));
    return C_fix(0);
  case 1:
    tmp = *start;
    if (C_bignum_negativep(big) ?
        !(tmp & C_INT_SIGN_BIT) && C_fitsinfixnump(-(C_word)tmp) :
        C_ufitsinfixnump(tmp)) {
      if (C_in_scratchspacep(C_internal_bignum_vector(big)))
        C_mutate_scratch_slot(NULL, C_internal_bignum_vector(big));
      return C_bignum_negativep(big) ? C_fix(-(C_word)tmp) : C_fix(tmp);
    }
    /* FALLTHROUGH */
  default:
    if (scan < last_digit) C_bignum_mutate_size(big, length);
    return big;
  }
}

static void bignum_digits_destructive_negate(C_word result)
{
  C_uword *scan, *end, digit, sum;

  scan = C_bignum_digits(result);
  end = scan + C_bignum_size(result);

  do {
    digit = ~*scan;
    sum = digit + 1;
    *scan++ = sum;
  } while (sum == 0 && scan < end);

  for (; scan < end; scan++) {
    *scan = ~*scan;
  }
}

static C_uword
bignum_digits_destructive_scale_up_with_carry(C_uword *start, C_uword *end, C_uword factor, C_uword carry)
{
  C_uword digit, p;

  assert(C_fitsinbignumhalfdigitp(carry));
  assert(C_fitsinbignumhalfdigitp(factor));

  /* See fixnum_times.  Substitute xlo = factor, xhi = 0, y = digit
   * and simplify the result to reduce variable usage.
   */
  while (start < end) {
    digit = (*start);

    p = factor * C_BIGNUM_DIGIT_LO_HALF(digit) + carry;
    carry = C_BIGNUM_DIGIT_LO_HALF(p);

    p = factor * C_BIGNUM_DIGIT_HI_HALF(digit) + C_BIGNUM_DIGIT_HI_HALF(p);
    (*start++) = C_BIGNUM_DIGIT_COMBINE(C_BIGNUM_DIGIT_LO_HALF(p), carry);
    carry = C_BIGNUM_DIGIT_HI_HALF(p);
  }
  return carry;
}

static C_uword
bignum_digits_destructive_scale_down(C_uword *start, C_uword *end, C_uword denominator)
{
  C_uword digit, k = 0;
  C_uhword q_j_hi, q_j_lo;

  /* Single digit divisor case from Hacker's Delight, Figure 9-1,
   * adapted to modify u[] in-place instead of writing to q[].
   */
  while (start < end) {
    digit = (*--end);

    k = C_BIGNUM_DIGIT_COMBINE(k, C_BIGNUM_DIGIT_HI_HALF(digit)); /* j */
    q_j_hi = k / denominator;
    k -= q_j_hi * denominator;

    k = C_BIGNUM_DIGIT_COMBINE(k, C_BIGNUM_DIGIT_LO_HALF(digit)); /* j-1 */
    q_j_lo = k / denominator;
    k -= q_j_lo * denominator;
    
    *end = C_BIGNUM_DIGIT_COMBINE(q_j_hi, q_j_lo);
  }
  return k;
}

static C_uword
bignum_digits_destructive_shift_right(C_uword *start, C_uword *end, int shift_right, int negp)
{
  int shift_left = C_BIGNUM_DIGIT_LENGTH - shift_right;
  C_uword digit, carry = negp ? ((~(C_uword)0) << shift_left) : 0;

  assert(shift_right < C_BIGNUM_DIGIT_LENGTH);

  while (start < end) {
    digit = *(--end);
    *end = (digit >> shift_right) | carry;
    carry = digit << shift_left;
  }
  return carry >> shift_left; /* The bits that were shifted out to the right */
}

static C_uword
bignum_digits_destructive_shift_left(C_uword *start, C_uword *end, int shift_left)
{
  C_uword carry = 0, digit;
  int shift_right = C_BIGNUM_DIGIT_LENGTH - shift_left;

  assert(shift_left < C_BIGNUM_DIGIT_LENGTH);

  while (start < end) {
    digit = *start;
    (*start++) = (digit << shift_left) | carry;
    carry = digit >> shift_right;
  }
  return carry;	 /* This would end up as most significant digit if it fit */
}

static C_regparm void
bignum_digits_multiply(C_word x, C_word y, C_word result)
{
  C_uword product,
          *xd = C_bignum_digits(x),
          *yd = C_bignum_digits(y),
          *rd = C_bignum_digits(result);
  C_uhword carry, yj;
  /* Lengths in halfwords */
  int i, j, length_x = C_bignum_size(x) * 2, length_y = C_bignum_size(y) * 2;

  /* From Hacker's Delight, Figure 8-1 (top part) */
  for (j = 0; j < length_y; ++j) {
    yj = C_uhword_ref(yd, j);
    if (yj == 0) continue;
    carry = 0;
    for (i = 0; i < length_x; ++i) {
      product = (C_uword)C_uhword_ref(xd, i) * yj +
                (C_uword)C_uhword_ref(rd, i + j) + carry;
      C_uhword_set(rd, i + j, product);
      carry = C_BIGNUM_DIGIT_HI_HALF(product);
    }
    C_uhword_set(rd, j + length_x, carry);
  }
}


/* "small" is either a number that fits a halfdigit, or a power of two */
static C_regparm void
bignum_destructive_divide_unsigned_small(C_word **ptr, C_word x, C_word y, C_word *q, C_word *r)
{
  C_word size, quotient, q_negp = C_mk_bool((y & C_INT_SIGN_BIT) ?
                                            !(C_bignum_negativep(x)) :
                                            C_bignum_negativep(x)),
         r_negp = C_mk_bool(C_bignum_negativep(x));
  C_uword *start, *end, remainder;
  int shift_amount;

  size = C_fix(C_bignum_size(x));
  quotient = C_allocate_scratch_bignum(ptr, size, q_negp, C_SCHEME_FALSE);
  bignum_digits_destructive_copy(quotient, x);

  start = C_bignum_digits(quotient);
  end = start + C_bignum_size(quotient);
  
  y = (y & C_INT_SIGN_BIT) ? -C_unfix(y) : C_unfix(y);

  shift_amount = C_ilen(y) - 1;
  if (((C_uword)1 << shift_amount) == y) { /* Power of two?  Shift! */
    remainder = bignum_digits_destructive_shift_right(start,end,shift_amount,0);
    assert(C_ufitsinfixnump(remainder));
  } else {
    remainder = bignum_digits_destructive_scale_down(start, end, y);
    assert(C_fitsinbignumhalfdigitp(remainder));
  }

  if (r != NULL) *r = C_truep(r_negp) ? C_fix(-remainder) : C_fix(remainder);
  /* Calling this function only makes sense if quotient is needed */
  *q = C_bignum_simplify(quotient);
}

static C_regparm void
bignum_destructive_divide_full(C_word numerator, C_word denominator, C_word quotient, C_word remainder, C_word return_remainder)
{
  C_word length = C_bignum_size(denominator);
  C_uword d1 = *(C_bignum_digits(denominator) + length - 1),
          *startr = C_bignum_digits(remainder),
          *endr = startr + C_bignum_size(remainder);
  int shift;

  shift = C_BIGNUM_DIGIT_LENGTH - C_ilen(d1); /* nlz */

  /* We have to work on halfdigits, so we shift out only the necessary
   * amount in order fill out that halfdigit (base is halved).
   * This trick is shamelessly stolen from Gauche :)
   * See below for part 2 of the trick.
   */
  if (shift >= C_BIGNUM_HALF_DIGIT_LENGTH)
    shift -= C_BIGNUM_HALF_DIGIT_LENGTH;

  /* Code below won't always set high halfdigit of quotient, so do it here. */
  if (quotient != C_SCHEME_UNDEFINED)
    C_bignum_digits(quotient)[C_bignum_size(quotient)-1] = 0;

  bignum_digits_destructive_copy(remainder, numerator);
  *(endr-1) = 0;    /* Ensure most significant digit is initialised */
  if (shift == 0) { /* Already normalized */
    bignum_destructive_divide_normalized(remainder, denominator, quotient);
  } else { /* Requires normalisation; allocate scratch denominator for this */
    C_uword *startnd;
    C_word ndenom;

    bignum_digits_destructive_shift_left(startr, endr, shift);

    ndenom = allocate_tmp_bignum(C_fix(length), C_SCHEME_FALSE, C_SCHEME_FALSE);
    startnd = C_bignum_digits(ndenom);
    bignum_digits_destructive_copy(ndenom, denominator);
    bignum_digits_destructive_shift_left(startnd, startnd+length, shift);

    bignum_destructive_divide_normalized(remainder, ndenom, quotient);
    if (C_truep(return_remainder)) /* Otherwise, don't bother shifting back */
      bignum_digits_destructive_shift_right(startr, endr, shift, 0);

    free_tmp_bignum(ndenom);
  }
}

static C_regparm void
bignum_destructive_divide_normalized(C_word big_u, C_word big_v, C_word big_q)
{
  C_uword *v = C_bignum_digits(big_v),
          *u = C_bignum_digits(big_u),
          *q = big_q == C_SCHEME_UNDEFINED ? NULL : C_bignum_digits(big_q),
           p,               /* product of estimated quotient & "denominator" */
           hat, qhat, rhat, /* estimated quotient and remainder digit */
           vn_1, vn_2;      /* "cached" values v[n-1], v[n-2] */
  C_word t, k;              /* Two helpers: temp/final remainder and "borrow" */
  /* We use plain ints here, which theoretically may not be enough on
   * 64-bit for an insanely huge number, but it is a _lot_ faster.
   */
  int n = C_bignum_size(big_v) * 2,       /* in halfwords */
      m = (C_bignum_size(big_u) * 2) - 2; /* Correct for extra digit */
  int i, j;		   /* loop  vars */

  /* Part 2 of Gauche's aforementioned trick: */
  if (C_uhword_ref(v, n-1) == 0) n--;

  /* These won't change during the loop, but are used in every step. */
  vn_1 = C_uhword_ref(v, n-1);
  vn_2 = C_uhword_ref(v, n-2);

  /* See also Hacker's Delight, Figure 9-1.  This is almost exactly that. */
  for (j = m - n; j >= 0; j--) {
    hat = C_BIGNUM_DIGIT_COMBINE(C_uhword_ref(u, j+n), C_uhword_ref(u, j+n-1));
    if (hat == 0) {
      if (q != NULL) C_uhword_set(q, j, 0);
      continue;
    }
    qhat = hat / vn_1;
    rhat = hat % vn_1;

    /* Two whiles is faster than one big check with an OR.  Thanks, Gauche! */
    while(qhat >= ((C_uword)1 << C_BIGNUM_HALF_DIGIT_LENGTH)) { qhat--; rhat += vn_1; }
    while(qhat * vn_2 > C_BIGNUM_DIGIT_COMBINE(rhat, C_uhword_ref(u, j+n-2))
	  && rhat < ((C_uword)1 << C_BIGNUM_HALF_DIGIT_LENGTH)) {
      qhat--;
      rhat += vn_1;
    }

    /* Multiply and subtract */
    k = 0;
    for (i = 0; i < n; i++) {
      p = qhat * C_uhword_ref(v, i);
      t = C_uhword_ref(u, i+j) - k - C_BIGNUM_DIGIT_LO_HALF(p);
      C_uhword_set(u, i+j, t);
      k = C_BIGNUM_DIGIT_HI_HALF(p) - (t >> C_BIGNUM_HALF_DIGIT_LENGTH);
    }
    t = C_uhword_ref(u,j+n) - k;
    C_uhword_set(u, j+n, t);

    if (t < 0) {		/* Subtracted too much? */
      qhat--;
      k = 0;
      for (i = 0; i < n; i++) {
        t = (C_uword)C_uhword_ref(u, i+j) + C_uhword_ref(v, i) + k;
        C_uhword_set(u, i+j, t);
	k = t >> C_BIGNUM_HALF_DIGIT_LENGTH;
      }
      C_uhword_set(u, j+n, (C_uhword_ref(u, j+n) + k));
    }
    if (q != NULL) C_uhword_set(q, j, qhat);
  } /* end j */
}


void C_ccall C_string_to_symbol(C_word c, C_word *av) 
{ 
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    string;
  int len, key;
  C_word s, *a = C_alloc(C_SIZEOF_SYMBOL + C_SIZEOF_PAIR);
  C_char *name;

  if(c != 3) C_bad_argc(c, 3);

  string = av[ 2 ];

  if(C_immediatep(string) || C_header_bits(string) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string->symbol", string);
    
  len = C_header_size(string);
  name = (C_char *)C_data_pointer(string);

  key = hash_string(len, name, symbol_table->size, symbol_table->rand, 0);
  if(!C_truep(s = lookup(key, len, name, symbol_table)))
    s = add_symbol(&a, key, string, symbol_table);

  C_kontinue(k, s);
}

void C_ccall C_string_to_keyword(C_word c, C_word *av) 
{ 
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    string;
  int len, key;
  C_word s, *a = C_alloc(C_SIZEOF_SYMBOL + C_SIZEOF_PAIR);
  C_char *name;

  if(c != 3) C_bad_argc(c, 3);

  string = av[ 2 ];

  if(C_immediatep(string) || C_header_bits(string) != C_STRING_TYPE)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "string->keyword", string);
    
  len = C_header_size(string);
  name = (C_char *)C_data_pointer(string);
  key = hash_string(len, name, keyword_table->size, keyword_table->rand, 0);

  if(!C_truep(s = lookup(key, len, name, keyword_table))) {
    s = add_symbol(&a, key, string, keyword_table);
    C_set_block_item(s, 0, s); /* Keywords evaluate to themselves */
    C_set_block_item(s, 2, C_SCHEME_FALSE); /* Keywords have no plists */
  }
  C_kontinue(k, s);
}

/* This will usually return a flonum, but it may also return a cplxnum
 * consisting of two flonums, making for a total of 11 words.
 */
C_regparm C_word C_fcall 
C_a_i_exact_to_inexact(C_word **ptr, int c, C_word n)
{
  if (n & C_FIXNUM_BIT) {
    return C_flonum(ptr, (double)C_unfix(n));
  } else if (C_immediatep(n)) {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "exact->inexact", n);
  } else if (C_block_header(n) == C_FLONUM_TAG) {
    return n;
  } else if (C_truep(C_bignump(n))) {
    return C_a_u_i_big_to_flo(ptr, c, n);
  } else if (C_block_header(n) == C_CPLXNUM_TAG) {
    return C_cplxnum(ptr, C_a_i_exact_to_inexact(ptr, 1, C_u_i_cplxnum_real(n)),
                     C_a_i_exact_to_inexact(ptr, 1, C_u_i_cplxnum_imag(n)));
  /* The horribly painful case: ratnums */
  } else if (C_block_header(n) == C_RATNUM_TAG) {
    /* This tries to keep the numbers within representable ranges and
     * tries to drop as few significant digits as possible by bringing
     * the two numbers to within the same powers of two.  See
     * algorithms M & N in Knuth, 4.2.1.
     */
     C_word num = C_u_i_ratnum_num(n), denom = C_u_i_ratnum_denom(n),
             /* e = approx. distance between the numbers in powers of 2.
              * ie, 2^e-1 < n/d < 2^e+1 (e is the *un*biased value of
              * e_w in M2.  TODO: What if b!=2 (ie, flonum-radix isn't 2)?
              */
             e = integer_length_abs(num) - integer_length_abs(denom),
             ab[C_SIZEOF_FIX_BIGNUM*5+C_SIZEOF_FLONUM], *a = ab, tmp, q, r, len,
             shift_amount, negp = C_i_integer_negativep(num);
     C_uword *d;
     double res, fraction;

     /* Align by shifting the smaller to the size of the larger */
     if (e < 0)      num = C_s_a_i_arithmetic_shift(&a, 2, num, C_fix(-e));
     else if (e > 0) denom = C_s_a_i_arithmetic_shift(&a, 2, denom, C_fix(e));

     /* Here, 1/2 <= n/d < 2 [N3] */
     if (C_truep(C_i_integer_lessp(num, denom))) { /* n/d < 1? */
       tmp = C_s_a_i_arithmetic_shift(&a, 2, num, C_fix(1));
       clear_buffer_object(ab, num); /* "knows" shift creates fresh numbers */
       num = tmp;
       e--;
     }

     /* Here, 1 <= n/d < 2 (normalized) [N5] */
     shift_amount = nmin(DBL_MANT_DIG-1, e - (DBL_MIN_EXP - DBL_MANT_DIG));

     tmp = C_s_a_i_arithmetic_shift(&a, 2, num, C_fix(shift_amount));
     clear_buffer_object(ab, num); /* "knows" shift creates fresh numbers */
     num = tmp;

     /* Now, calculate round(num/denom).  We start with a quotient&remainder */
     integer_divrem(&a, num, denom, &q, &r);

     /* We multiply the remainder by two to simulate adding 1/2 for
      * round.  However, we don't do it if num = denom (q=1,r=0) */
     if (!((q == C_fix(1) || q == C_fix(-1)) && r == C_fix(0))) {
       tmp = C_s_a_i_arithmetic_shift(&a, 2, r, C_fix(1));
       clear_buffer_object(ab, r); /* "knows" shift creates fresh numbers */
       r = tmp;
     }

     /* Now q is the quotient, but to "round" result we need to
      * adjust.  This follows the semantics of the "round" procedure:
      * Round away from zero on positive numbers (ignoring sign).  In
      * case of exactly halfway, we round up if odd.
      */
     tmp = C_a_i_exact_to_inexact(&a, 1, q);
     fraction = fabs(C_flonum_magnitude(tmp));
     switch (basic_cmp(r, denom, "", 0)) {
     case C_fix(0):
       if (C_truep(C_i_oddp(q))) fraction += 1.0;
       break;
     case C_fix(1):
       fraction += 1.0;
       break;
     default: /* if r <= denom, we're done */ break;
     }

     clear_buffer_object(ab, num);
     clear_buffer_object(ab, denom);
     clear_buffer_object(ab, q);
     clear_buffer_object(ab, r);

     shift_amount = nmin(DBL_MANT_DIG-1, e - (DBL_MIN_EXP - DBL_MANT_DIG));
     res = ldexp(fraction, e - shift_amount);
     return C_flonum(ptr, C_truep(negp) ? -res : res);
  } else {
    barf(C_BAD_ARGUMENT_TYPE_NO_NUMBER_ERROR, "exact->inexact", n);
  }
}


/* this is different from C_a_i_flonum_round, for R5RS compatibility */
C_regparm C_word C_fcall C_a_i_flonum_round_proper(C_word **ptr, int c, C_word n)
{
  double fn, i, f, i2, r;

  fn = C_flonum_magnitude(n);
  if(fn < 0.0) {
    f = modf(-fn, &i);
    if(f < 0.5 || (f == 0.5 && modf(i * 0.5, &i2) == 0.0))
      r = -i;
    else
      r = -(i + 1.0);
  }
  else if(fn == 0.0/* || fn == -0.0*/)
    r = fn;
  else {
    f = modf(fn, &i);
    if(f < 0.5 || (f == 0.5 && modf(i * 0.5, &i2) == 0.0))
      r = i;
    else
      r = i + 1.0;
  }

  return C_flonum(ptr, r);
}

C_regparm C_word C_fcall
C_a_i_flonum_gcd(C_word **p, C_word n, C_word x, C_word y)
{
   double xub, yub, r;

   if (!C_truep(C_u_i_fpintegerp(x)))
     barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "gcd", x);
   if (!C_truep(C_u_i_fpintegerp(y)))
     barf(C_BAD_ARGUMENT_TYPE_NO_INTEGER_ERROR, "gcd", y);

   xub = C_flonum_magnitude(x);
   yub = C_flonum_magnitude(y);

   if (xub < 0.0) xub = -xub;
   if (yub < 0.0) yub = -yub;
   
   while(yub != 0.0) {
     r = fmod(xub, yub);
     xub = yub;
     yub = r;
   }
   return C_flonum(p, xub);
}

/* This is Lehmer's GCD algorithm with Jebelean's quotient test, as
 * it is presented in the paper "An Analysis of Lehmer’s Euclidean
 * GCD Algorithm", by J. Sorenson.  Fuck the ACM and their goddamn
 * paywall; you can currently find the paper here:
 * http://www.csie.nuk.edu.tw/~cychen/gcd/An%20analysis%20of%20Lehmer%27s%20Euclidean%20GCD%20algorithm.pdf
 * If that URI fails, it's also explained in [MpNT, 5.2]
 *
 * The basic idea is to avoid divisions which yield only small
 * quotients, in which the remainder won't reduce the numbers by
 * much.  This can be detected by dividing only the leading k bits.
 * In our case, k = C_WORD_SIZE - 2.
 */
inline static void lehmer_gcd(C_word **ptr, C_word u, C_word v, C_word *x, C_word *y)
{
  int i_even = 1, done = 0;
  C_word shift_amount = integer_length_abs(u) - (C_WORD_SIZE - 2),
         ab[C_SIZEOF_BIGNUM(2)*2+C_SIZEOF_FIX_BIGNUM*2], *a = ab,
         uhat, vhat, qhat, xnext, ynext,
         xprev = 1, yprev = 0, xcurr = 0, ycurr = 1;

  uhat = C_s_a_i_arithmetic_shift(&a, 2, u, C_fix(-shift_amount));
  vhat = C_s_a_i_arithmetic_shift(&a, 2, v, C_fix(-shift_amount));
  assert(uhat & C_FIXNUM_BIT); uhat = C_unfix(uhat);
  assert(vhat & C_FIXNUM_BIT); vhat = C_unfix(vhat);

  do {
    qhat = uhat / vhat;         /* Estimated quotient for this step */
    xnext = xprev - qhat * xcurr;
    ynext = yprev - qhat * ycurr;

    /* Euclidean GCD swap on uhat and vhat (shift_amount is not needed): */
    shift_amount = vhat;
    vhat = uhat - qhat * vhat;
    uhat = shift_amount;

    i_even = !i_even;
    if (i_even)
      done = (vhat < -xnext) || ((uhat - vhat) < (ynext - ycurr));
    else
      done = (vhat < -ynext) || ((uhat - vhat) < (xnext - xcurr));

    if (!done) {
      xprev = xcurr; yprev = ycurr;
      xcurr = xnext; ycurr = ynext;
    }
  } while (!done);

  /* x = xprev * u + yprev * v */
  uhat = C_s_a_u_i_integer_times(&a, 2, C_fix(xprev), u);
  vhat = C_s_a_u_i_integer_times(&a, 2, C_fix(yprev), v);
  *x = C_s_a_u_i_integer_plus(ptr, 2, uhat, vhat);
  *x = move_buffer_object(ptr, ab, *x);
  clear_buffer_object(ab, uhat);
  clear_buffer_object(ab, vhat);

  /* y = xcurr * u + ycurr * v */
  uhat = C_s_a_u_i_integer_times(&a, 2, C_fix(xcurr), u);
  vhat = C_s_a_u_i_integer_times(&a, 2, C_fix(ycurr), v);
  *y = C_s_a_u_i_integer_plus(ptr, 2, uhat, vhat);
  *y = move_buffer_object(ptr, ab, *y);
  clear_buffer_object(ab, uhat);
  clear_buffer_object(ab, vhat);
}

/* Because this must be inlineable (due to + and - using this for
 * ratnums), we can't use burnikel-ziegler division here, until we
 * have a C implementation that doesn't consume stack.  However,
 * we *can* use Lehmer's GCD.
 */
C_regparm C_word C_fcall
C_s_a_u_i_integer_gcd(C_word **ptr, C_word n, C_word x, C_word y)
{
   C_word ab[2][C_SIZEOF_BIGNUM(2) * 2], *a, newx, newy, size, i = 0;

   if (x & C_FIXNUM_BIT && y & C_FIXNUM_BIT) return C_i_fixnum_gcd(x, y);

   a = ab[i++];
   x = C_s_a_u_i_integer_abs(&a, 1, x);
   y = C_s_a_u_i_integer_abs(&a, 1, y);

   if (!C_truep(C_i_integer_greaterp(x, y))) {
     newx = y; y = x; x = newx; /* Ensure loop invariant: abs(x) >= abs(y) */
   }

   while(y != C_fix(0)) {
     assert(integer_length_abs(x) >= integer_length_abs(y));
     /* x and y are stored in the same buffer, as well as a result */
     a = ab[i++];
     if (i == 2) i = 0;

     if (x & C_FIXNUM_BIT) return C_i_fixnum_gcd(x, y);

     /* First, see if we should run a Lehmer step */
     if ((integer_length_abs(x) - integer_length_abs(y)) < C_HALF_WORD_SIZE) {
       lehmer_gcd(&a, x, y, &newx, &newy);
       newx = move_buffer_object(&a, ab[i], newx);
       newy = move_buffer_object(&a, ab[i], newy);
       clear_buffer_object(ab[i], x);
       clear_buffer_object(ab[i], y);
       x = newx;
       y = newy;
       a = ab[i++]; /* Ensure x and y get cleared correctly below */
       if (i == 2) i = 0;
     }

     newy = C_s_a_u_i_integer_remainder(&a, 2, x, y);
     newy = move_buffer_object(&a, ab[i], newy);
     newx = move_buffer_object(&a, ab[i], y);
     clear_buffer_object(ab[i], x);
     clear_buffer_object(ab[i], y);
     x = newx;
     y = newy;
   }

   newx = C_s_a_u_i_integer_abs(ptr, 1, x);
   newx = move_buffer_object(ptr, ab, newx);
   clear_buffer_object(ab, x);
   clear_buffer_object(ab, y);
   return newx;
}


C_regparm C_word C_fcall
C_s_a_i_digits_to_integer(C_word **ptr, C_word n, C_word str, C_word start, C_word end, C_word radix, C_word negp)
{
  if (start == end) {
    return C_SCHEME_FALSE;
  } else {
    size_t nbits;
    char *s = C_c_string(str);
    C_word result, size;
    end = C_unfix(end);
    start = C_unfix(start);
    radix = C_unfix(radix);

    assert((radix > 1) && C_fitsinbignumhalfdigitp(radix));

    nbits = (end - start) * C_ilen(radix - 1);
    size = C_BIGNUM_BITS_TO_DIGITS(nbits);
    if (size == 1) {
      result = C_bignum1(ptr, C_truep(negp), 0);
    } else if (size == 2) {
      result = C_bignum2(ptr, C_truep(negp), 0, 0);
    } else {
      size = C_fix(size);
      result = C_allocate_scratch_bignum(ptr, size, negp, C_SCHEME_FALSE);
    }

    return str_to_bignum(result, s + start, s + end, radix);
  }
}

inline static int hex_char_to_digit(int ch)
{
  if (ch == (int)'#') return 0; /* Hash characters in numbers are mapped to 0 */
  else if (ch >= (int)'a') return ch - (int)'a' + 10; /* lower hex */
  else if (ch >= (int)'A') return ch - (int)'A' + 10; /* upper hex */
  else return ch - (int)'0'; /* decimal (OR INVALID; handled elsewhere) */
}

/* Write from digit character stream to bignum.  Bignum does not need
 * to be initialised.  Returns the bignum, or a fixnum.  Assumes the
 * string contains only digits that fit within radix (checked by
 * string->number).
 */
static C_regparm C_word
str_to_bignum(C_word bignum, char *str, char *str_end, int radix)
{
  int radix_shift, str_digit;
  C_uword *digits = C_bignum_digits(bignum),
          *end_digits = digits + C_bignum_size(bignum), big_digit = 0;

  /* Below, we try to save up as much as possible in big_digit, and
   * only when it exceeds what we would be able to multiply easily, we
   * scale up the bignum and add what we saved up.
   */
  radix_shift = C_ilen(radix) - 1;
  if (((C_uword)1 << radix_shift) == radix) { /* Power of two? */
    int n = 0; /* Number of bits read so far into current big digit */

    /* Read from least to most significant digit to avoid shifting or scaling */
    while (str_end > str) {
      str_digit = hex_char_to_digit((int)*--str_end);

      big_digit |= (C_uword)str_digit << n;
      n += radix_shift;

      if (n >= C_BIGNUM_DIGIT_LENGTH) {
	n -= C_BIGNUM_DIGIT_LENGTH;
	*digits++ = big_digit;
	big_digit = str_digit >> (radix_shift - n);
      }
    }
    assert(n < C_BIGNUM_DIGIT_LENGTH);
    /* If radix isn't an exact divisor of digit length, write final digit */
    if (n > 0) *digits++ = big_digit;
    assert(digits == end_digits);
  } else {			  /* Not a power of two */
    C_uword *last_digit = digits, factor;  /* bignum starts as zero */

    do {
      factor = radix;
      while (str < str_end && C_fitsinbignumhalfdigitp(factor)) {
        str_digit = hex_char_to_digit((int)*str++);
	factor *= radix;
	big_digit = radix * big_digit + str_digit;
      }

      big_digit = bignum_digits_destructive_scale_up_with_carry(
                   digits, last_digit, factor / radix, big_digit);

      if (big_digit) {
	(*last_digit++) = big_digit; /* Move end */
        big_digit = 0;
      }
    } while (str < str_end);

    /* Set remaining digits to zero so bignum_simplify can do its work */
    assert(last_digit <= end_digits);
    while (last_digit < end_digits) *last_digit++ = 0;
  }

  return C_bignum_simplify(bignum);
}


static C_regparm double C_fcall decode_flonum_literal(C_char *str)
{
  C_char *eptr;
  double flo;
  int len = C_strlen(str);

  /* We only need to be able to parse what C_flonum_to_string() emits,
   * so we avoid too much error checking.
   */
  if (len == 6) { /* Only perform comparisons when necessary */
    if (!C_strcmp(str, "-inf.0")) return -1.0 / 0.0;
    if (!C_strcmp(str, "+inf.0")) return 1.0 / 0.0;
    if (!C_strcmp(str, "+nan.0")) return 0.0 / 0.0;
  }

  errno = 0;
  flo = C_strtod(str, &eptr);

  if((flo == HUGE_VAL && errno != 0) ||
     (flo == -HUGE_VAL && errno != 0) ||
     (*eptr != '\0' && C_strcmp(eptr, ".0") != 0)) {
    panic(C_text("could not decode flonum literal"));
  }

  return flo;
}


static char *to_n_nary(C_uword num, C_uword base, int negp, int as_flonum)
{
  static char *digits = "0123456789abcdef";
  char *p;
  C_uword shift = C_ilen(base) - 1;
  int mask = (1 << shift) - 1;
  if (as_flonum) {
    buffer[68] = '\0';
    buffer[67] = '0';
    buffer[66] = '.';
  } else {
    buffer[66] = '\0';
  }
  p = buffer + 66;
  if (mask == base - 1) {
    do {
      *(--p) = digits [ num & mask ];
      num >>= shift;
    } while (num);
  } else {
    do {
      *(--p) = digits [ num % base ];
      num /= base;
    } while (num);
  }
  if (negp) *(--p) = '-';
  return p;
}


void C_ccall C_number_to_string(C_word c, C_word *av)
{
  C_word radix, num;

  if(c == 3) {
    radix = C_fix(10);
  } else if(c == 4) {
    radix = av[ 3 ];
    if(!(radix & C_FIXNUM_BIT))
      barf(C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR, "number->string", radix);
  } else {
    C_bad_argc(c, 3);
  }

  num = av[ 2 ];

  if(num & C_FIXNUM_BIT) {
    C_fixnum_to_string(c, av); /* reuse av */
  } else if (C_immediatep(num)) {
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "number->string", num);
  } else if(C_block_header(num) == C_FLONUM_TAG) {
    C_flonum_to_string(c, av); /* reuse av */
  } else if (C_truep(C_bignump(num))) {
    C_integer_to_string(c, av); /* reuse av */
  } else {
    C_word k = av[ 1 ];
    try_extended_number("##sys#extended-number->string", 3, k, num, radix);
  }
}

void C_ccall C_fixnum_to_string(C_word c, C_word *av)
{
  C_char *p;
  C_word *a,
    /* self = av[ 0 ] */
    k = av[ 1 ],
    num = av[ 2 ],
    radix = ((c == 3) ? 10 : C_unfix(av[ 3 ])),
    neg = ((num & C_INT_SIGN_BIT) ? 1 : 0);

  if (radix < 2 || radix > 16) {
    barf(C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR, "number->string", C_fix(radix));
  }

  num = neg ? -C_unfix(num) : C_unfix(num);
  p = to_n_nary(num, radix, neg, 0);

  num = C_strlen(p);
  a = C_alloc((C_bytestowords(num) + 1));
  C_kontinue(k, C_string(&a, num, p));
}

void C_ccall C_flonum_to_string(C_word c, C_word *av)
{
  C_char *p;
  double f, fa, m;
  C_word *a,
    /* self = av[ 0 ] */
    k = av[ 1 ],
    num = av[ 2 ],
    radix = ((c == 3) ? 10 : C_unfix(av[ 3 ]));

  f = C_flonum_magnitude(num);
  fa = fabs(f);

  /* XXX TODO: Should inexacts be printable in other bases than 10?
   * Perhaps output a string starting with #i?
   * Right now something like (number->string 1e40 16) results in
   * a string that can't be read back using string->number.
   */
  if((radix < 2) || (radix > 16)){
    barf(C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR, "number->string", C_fix(radix));
  }

  if(f == 0.0 || (C_modf(f, &m) == 0.0 && log2(fa) < C_WORD_SIZE)) { /* Use fast int code */
    if(signbit(f)) {
      p = to_n_nary((C_uword)-f, radix, 1, 1);
    } else {
      p = to_n_nary((C_uword)f, radix, 0, 1);
    }
  } else if(C_isnan(f)) {
    p = "+nan.0";
  } else if(C_isinf(f)) {
    p = f > 0 ? "+inf.0" : "-inf.0";
  } else { /* Doesn't fit an unsigned int and not "special"; use system libc */
    C_snprintf(buffer, STRING_BUFFER_SIZE, C_text("%.*g"),
               /* XXX: flonum_print_precision */
               (int)C_unfix(C_get_print_precision()), f);
    buffer[STRING_BUFFER_SIZE-1] = '\0';

    if((p = C_strpbrk(buffer, C_text(".eE"))) == NULL) {
      /* Already checked for these, so shouldn't happen */
      assert(*buffer != 'i'); /* "inf" */
      assert(*buffer != 'n'); /* "nan" */
      /* Ensure integral flonums w/o expt are always terminated by .0 */
#if defined(HAVE_STRLCAT) || !defined(C_strcat)
      C_strlcat(buffer, C_text(".0"), sizeof(buffer));
#else
      C_strcat(buffer, C_text(".0"));
#endif
    }
    p = buffer;
  }

  radix = C_strlen(p);
  a = C_alloc((C_bytestowords(radix) + 1));
  radix = C_string(&a, radix, p);
  C_kontinue(k, radix);
}

void C_ccall C_integer_to_string(C_word c, C_word *av)
{
  C_word
    /* self = av[ 0 ] */
    k = av[ 1 ],
    num = av[ 2 ],
    radix = ((c == 3) ? 10 : C_unfix(av[ 3 ]));

  if (num & C_FIXNUM_BIT) {
    C_fixnum_to_string(4, av); /* reuse av */
  } else {
    int len, radix_shift;
    size_t nbits;

    if ((radix < 2) || (radix > 16)) {
      barf(C_BAD_ARGUMENT_TYPE_BAD_BASE_ERROR, "number->string", C_fix(radix));
    }

    /* Approximation of the number of radix digits we'll need.  We try
     * to be as precise as possible to avoid memmove overhead at the end
     * of the non-powers of two part of the conversion procedure, which
     * we may need to do because we write strings back-to-front, and
     * pointers must be aligned (even for byte blocks).
     */
    len = C_bignum_size(num)-1;

    nbits  = (size_t)len * C_BIGNUM_DIGIT_LENGTH;
    nbits += C_ilen(C_bignum_digits(num)[len]);

    len = C_ilen(radix)-1;
    len = (nbits + len - 1) / len;
    len += C_bignum_negativep(num) ? 1 : 0; /* Add space for negative sign */
    
    radix_shift = C_ilen(radix) - 1;
    if (len > C_RECURSIVE_TO_STRING_THRESHOLD &&
        /* The power of two fast path is much faster than recursion */
        ((C_uword)1 << radix_shift) != radix) {
      try_extended_number("##sys#integer->string/recursive",
                          4, k, num, C_fix(radix), C_fix(len));
    } else {
      C_word kab[C_SIZEOF_CLOSURE(4)], *ka = kab, kav[6];

      kav[ 0 ] = (C_word)NULL;   /* No "self" closure */
      kav[ 1 ] = C_closure(&ka, 4, (C_word)bignum_to_str_2,
                           k, num, C_fix(radix));
      kav[ 2 ] = C_fix(len);
      kav[ 3 ] = C_SCHEME_TRUE; /* Byte vector */
      kav[ 4 ] = C_SCHEME_FALSE; /* No initialization */
      kav[ 5 ] = C_SCHEME_FALSE; /* Don't align at 8 bytes */
      C_allocate_vector(6, kav);
    }
  }
}

static void bignum_to_str_2(C_word c, C_word *av)
{
  static char *characters = "0123456789abcdef";
  C_word
    self = av[ 0 ],
    string = av[ 1 ],
    k = C_block_item(self, 1),
    bignum = C_block_item(self, 2),
    radix = C_unfix(C_block_item(self, 3));
  char
    *buf = C_c_string(string),
    *index = buf + C_header_size(string) - 1;
  int radix_shift,
    negp = (C_bignum_negativep(bignum) ? 1 : 0);

  radix_shift = C_ilen(radix) - 1;
  if (((C_uword)1 << radix_shift) == radix) { /* Power of two? */
    int radix_mask = radix - 1, big_digit_len = 0, radix_digit;
    C_uword *scan, *end, big_digit = 0;

    scan = C_bignum_digits(bignum);
    end = scan + C_bignum_size(bignum);

    while (scan < end) {
      /* If radix isn't an exact divisor of digit length, handle overlap */
      if (big_digit_len == 0) {
        big_digit = *scan++;
        big_digit_len = C_BIGNUM_DIGIT_LENGTH;
      } else {
        assert(index >= buf);
	radix_digit = big_digit;
        big_digit = *scan++;
	radix_digit |= ((unsigned int)big_digit << big_digit_len) & radix_mask;
        *index-- = characters[radix_digit];
	big_digit >>= (radix_shift - big_digit_len);
        big_digit_len = C_BIGNUM_DIGIT_LENGTH - (radix_shift - big_digit_len);
      }

      while(big_digit_len >= radix_shift && index >= buf) {
	radix_digit = big_digit & radix_mask;
        *index-- = characters[radix_digit];
	big_digit >>= radix_shift;
	big_digit_len -= radix_shift;
      }
    }

    assert(big_digit < radix);

    /* Final digit (like overlap at start of while loop) */
    if (big_digit) *index-- = characters[big_digit];

    if (negp) {
      /* Loop above might've overwritten sign position with a zero */
      if (*(index+1) == '0') *(index+1) = '-';
      else *index-- = '-';
    }

    /* Length calculation is always precise for radix powers of two. */
    assert(index == buf-1);
  } else {
    C_uword base, *start, *scan, big_digit;
    C_word working_copy;
    int steps, i;

    working_copy = allocate_tmp_bignum(C_fix(C_bignum_size(bignum)),
                                       C_mk_bool(negp), C_SCHEME_FALSE);
    bignum_digits_destructive_copy(working_copy, bignum);

    start = C_bignum_digits(working_copy);

    scan = start + C_bignum_size(bignum);
    /* Calculate the largest power of radix that fits a halfdigit:
     * steps = log10(2^halfdigit_bits), base = 10^steps
     */
    for(steps = 0, base = radix; C_fitsinbignumhalfdigitp(base); base *= radix)
      steps++;

    base /= radix; /* Back down: we overshot in the loop */

    while (scan > start) {
      big_digit = bignum_digits_destructive_scale_down(start, scan, base);

      if (*(scan-1) == 0) scan--; /* Adjust if we exhausted the highest digit */

      for(i = 0; i < steps && index >= buf; ++i) {
	C_word tmp = big_digit / radix;
        *index-- = characters[big_digit - (tmp*radix)]; /* big_digit % radix */
        big_digit = tmp;
      }
    }
    assert(index >= buf-1);
    free_tmp_bignum(working_copy);

    /* Move index onto first nonzero digit.  We're writing a bignum
       here: it can't consist of only zeroes. */
    while(*++index == '0');
  
    if (negp) *--index = '-';
  
    /* Shorten with distance between start and index. */
    if (buf != index) {
      i = C_header_size(string) - (index - buf);
      C_memmove(buf, index, i); /* Move start of number to beginning. */
      C_block_header(string) = C_STRING_TYPE | i; /* Mutate strlength. */
    }
  }

  C_kontinue(k, string);
}


void C_ccall C_make_structure(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    type = av[ 2 ],
    size = c - 3,
    *s, s0;

  if(!C_demand(size + 2))
    C_save_and_reclaim((void *)C_make_structure, c, av);

  s = C_alloc(C_SIZEOF_STRUCTURE(size + 1)),
  s0 = (C_word)s;
  *(s++) = C_STRUCTURE_TYPE | (size + 1);
  *(s++) = type;
  av += 3;

  while(size--)
    *(s++) = *(av++);

  C_kontinue(k, s0);
}


void C_ccall C_make_symbol(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    name = av[ 2 ],
    ab[ C_SIZEOF_SYMBOL ], 
    *a = ab,
    s0 = (C_word)a;

  *(a++) = C_SYMBOL_TYPE | (C_SIZEOF_SYMBOL - 1);
  *(a++) = C_SCHEME_UNBOUND;
  *(a++) = name;
  *a = C_SCHEME_END_OF_LIST;
  C_kontinue(k, s0);
}


void C_ccall C_make_pointer(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    ab[ 2 ], 
    *a = ab,
    p;

  p = C_mpointer(&a, NULL);
  C_kontinue(k, p);
}


void C_ccall C_make_tagged_pointer(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    tag = av[ 2 ],
    ab[ 3 ],
    *a = ab,
    p;

  p = C_taggedmpointer(&a, tag, NULL);
  C_kontinue(k, p);
}


void C_ccall C_ensure_heap_reserve(C_word c, C_word *av) 
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    n = av[ 2 ],
    *p;
  
  C_save(k);

  if(!C_demand(C_bytestowords(C_unfix(n))))
    C_reclaim((void *)generic_trampoline, 1);

  p = C_temporary_stack;
  C_temporary_stack = C_temporary_stack_bottom;
  generic_trampoline(0, p);
}


void C_ccall generic_trampoline(C_word c, C_word *av)
{
  C_word k = av[ 0 ];

  C_kontinue(k, C_SCHEME_UNDEFINED);
}


void C_ccall C_return_to_host(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ];

  return_to_host = 1;
  C_save(k);
  C_reclaim((void *)generic_trampoline, 1);
}


void C_ccall C_get_symbol_table_info(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ];
  double d1, d2;
  int n = 0, total;
  C_SYMBOL_TABLE *stp;
  C_word
    x, y,
    ab[ WORDS_PER_FLONUM * 2 + C_SIZEOF_VECTOR(4) ],
    *a = ab;

  for(stp = symbol_table_list; stp != NULL; stp = stp->next)
    ++n;
  
  d1 = compute_symbol_table_load(&d2, &total);
  x = C_flonum(&a, d1);		/* load */
  y = C_flonum(&a, d2);		/* avg bucket length */
  C_kontinue(k, C_vector(&a, 4, x, y, C_fix(total), C_fix(n)));
}


void C_ccall C_get_memory_info(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    ab[ C_SIZEOF_VECTOR(2) ],
    *a = ab;

  C_kontinue(k, C_vector(&a, 2, C_fix(heap_size), C_fix(stack_size)));
}


void C_ccall C_context_switch(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    state = av[ 2 ],
    n = C_header_size(state) - 1,
    adrs = C_block_item(state, 0),
    *av2;
  C_proc tp = (C_proc)C_block_item(adrs,0);

  /* Copy argvector because it may be mutated in-place.  The state
   * vector should not be re-invoked(?), but it can be kept alive
   * during GC, so the mutated argvector/state slots may turn stale.
   */
  av2 = C_alloc(n);
  C_memcpy(av2, (C_word *)state + 2, n * sizeof(C_word));
  tp(n, av2);
}


void C_ccall C_peek_signed_integer(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    v = av[ 2 ],
    index = av[ 3 ],
    x = C_block_item(v, C_unfix(index)),
    ab[C_SIZEOF_BIGNUM(1)], *a = ab;

  C_uword num = ((C_word *)C_data_pointer(v))[ C_unfix(index) ];

  C_kontinue(k, C_int_to_num(&a, num));
}


void C_ccall C_peek_unsigned_integer(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    v = av[ 2 ],
    index = av[ 3 ],
    x = C_block_item(v, C_unfix(index)),
    ab[C_SIZEOF_BIGNUM(1)], *a = ab;

  C_uword num = ((C_word *)C_data_pointer(v))[ C_unfix(index) ];

  C_kontinue(k, C_unsigned_int_to_num(&a, num));
}

void C_ccall C_peek_int64(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    v = av[ 2 ],
    index = av[ 3 ],
    x = C_block_item(v, C_unfix(index)),
    ab[C_SIZEOF_BIGNUM(2)], *a = ab;

  C_s64 num = ((C_s64 *)C_data_pointer(v))[ C_unfix(index) ];

  C_kontinue(k, C_int64_to_num(&a, num));
}


void C_ccall C_peek_uint64(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    v = av[ 2 ],
    index = av[ 3 ],
    x = C_block_item(v, C_unfix(index)),
    ab[C_SIZEOF_BIGNUM(2)], *a = ab;

  C_u64 num = ((C_u64 *)C_data_pointer(v))[ C_unfix(index) ];

  C_kontinue(k, C_uint64_to_num(&a, num));
}


void C_ccall C_decode_seconds(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    secs = av[ 2 ],
    mode = av[ 3 ];
  time_t tsecs;
  struct tm *tmt;
  C_word
    ab[ C_SIZEOF_VECTOR(10) ], 
    *a = ab,
    info;

  tsecs = (time_t)C_num_to_int64(secs);
  
  if(mode == C_SCHEME_FALSE) tmt = C_localtime(&tsecs);
  else tmt = C_gmtime(&tsecs);

  if(tmt  == NULL)
    C_kontinue(k, C_SCHEME_FALSE);
  
  info = C_vector(&a, 10, C_fix(tmt->tm_sec), C_fix(tmt->tm_min), C_fix(tmt->tm_hour),
		  C_fix(tmt->tm_mday), C_fix(tmt->tm_mon), C_fix(tmt->tm_year),
		  C_fix(tmt->tm_wday), C_fix(tmt->tm_yday),
		  tmt->tm_isdst > 0 ? C_SCHEME_TRUE : C_SCHEME_FALSE,
#ifdef C_GNU_ENV
                  /* negative for west of UTC, but we want positive */
		  C_fix(-tmt->tm_gmtoff)
#elif defined(__CYGWIN__) || defined(__MINGW32__) || defined(_WIN32) || defined(__WINNT__)
                  C_fix(mode == C_SCHEME_FALSE ? _timezone : 0) /* does not account for DST */
#else
                  C_fix(mode == C_SCHEME_FALSE ? timezone : 0)  /* does not account for DST */
#endif
		  );
  C_kontinue(k, info);
}


void C_ccall C_machine_byte_order(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ];
  char *str;
  C_word *a, s;

  if(c != 2) C_bad_argc(c, 2);

#if defined(C_MACHINE_BYTE_ORDER)
  str = C_MACHINE_BYTE_ORDER;
#else
  C_cblock
    static C_word one_two_three = 123;
    str = (*((C_char *)&one_two_three) != 123) ? "big-endian" : "little-endian";
  C_cblockend;
#endif

  a = C_alloc(2 + C_bytestowords(strlen(str)));
  s = C_string2(&a, str);

  C_kontinue(k, s);
}


void C_ccall C_machine_type(C_word c, C_word *av)
{
  C_word 
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    *a, s;

  if(c != 2) C_bad_argc(c, 2);

  a = C_alloc(2 + C_bytestowords(strlen(C_MACHINE_TYPE)));
  s = C_string2(&a, C_MACHINE_TYPE);
  
  C_kontinue(k, s);
}


void C_ccall C_software_type(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    *a, s;

  if(c != 2) C_bad_argc(c, 2);

  a = C_alloc(2 + C_bytestowords(strlen(C_SOFTWARE_TYPE)));
  s = C_string2(&a, C_SOFTWARE_TYPE);

 C_kontinue(k, s);
}


void C_ccall C_build_platform(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    *a, s;

  if(c != 2) C_bad_argc(c, 2);

  a = C_alloc(2 + C_bytestowords(strlen(C_BUILD_PLATFORM)));
  s = C_string2(&a, C_BUILD_PLATFORM);

 C_kontinue(k, s);
}


void C_ccall C_software_version(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    *a, s;

  if(c != 2) C_bad_argc(c, 2);

  a = C_alloc(2 + C_bytestowords(strlen(C_SOFTWARE_VERSION)));
  s = C_string2(&a, C_SOFTWARE_VERSION);

 C_kontinue(k, s);
}


/* Register finalizer: */

void C_ccall C_register_finalizer(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ]) */
    k = av[ 1 ],
    x = av[ 2 ],
    proc = av[ 3 ];

  if(C_immediatep(x) ||
     (!C_in_stackp(x) && !C_in_heapp(x) && !C_in_scratchspacep(x)))
    C_kontinue(k, x); /* not GCable */

  C_do_register_finalizer(x, proc);
  C_kontinue(k, x);
}


/*XXX could this be made static? is it used in eggs somewhere? 
  if not, declare as fcall/regparm (and static, remove from chicken.h)
 */
void C_ccall C_do_register_finalizer(C_word x, C_word proc)
{
  C_word *ptr;
  int n, i;
  FINALIZER_NODE *flist;

  if(finalizer_free_list == NULL) {
    if((flist = (FINALIZER_NODE *)C_malloc(sizeof(FINALIZER_NODE))) == NULL)
      panic(C_text("out of memory - cannot allocate finalizer node"));

    ++allocated_finalizer_count;
  }
  else {
    flist = finalizer_free_list;
    finalizer_free_list = flist->next;
  }

  if(finalizer_list != NULL) finalizer_list->previous = flist;

  flist->previous = NULL;
  flist->next = finalizer_list;
  finalizer_list = flist;

  if(C_in_stackp(x)) C_mutate_slot(&flist->item, x);
  else flist->item = x;

  if(C_in_stackp(proc)) C_mutate_slot(&flist->finalizer, proc);
  else flist->finalizer = proc;

  ++live_finalizer_count;
}


/*XXX same here */
int C_do_unregister_finalizer(C_word x)
{
  int n;
  FINALIZER_NODE *flist;

  for(flist = finalizer_list; flist != NULL; flist = flist->next) {
    if(flist->item == x) {
      if(flist->previous == NULL) finalizer_list = flist->next;
      else flist->previous->next = flist->next;

      return 1;
    }
  }

  return 0;
}


/* Dynamic loading of shared objects: */

void C_ccall C_set_dlopen_flags(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    now = av[ 2 ],
    global = av[ 3 ];

#if !defined(NO_DLOAD2) && defined(HAVE_DLFCN_H)
  dlopen_flags = (C_truep(now) ? RTLD_NOW : RTLD_LAZY) | (C_truep(global) ? RTLD_GLOBAL : RTLD_LOCAL);
#endif
  C_kontinue(k, C_SCHEME_UNDEFINED);
}


void C_ccall C_dload(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    name = av[ 2 ],
    entry = av[ 3 ];

#if !defined(NO_DLOAD2) && (defined(HAVE_DLFCN_H) || defined(HAVE_DL_H) || (defined(HAVE_LOADLIBRARY) && defined(HAVE_GETPROCADDRESS)))
  /* Force minor GC: otherwise the lf may contain pointers to stack-data
     (stack allocated interned symbols, for example) */
  C_save_and_reclaim_args((void *)dload_2, 3, k, name, entry);
#endif

  C_kontinue(k, C_SCHEME_FALSE);
}


#ifdef DLOAD_2_DEFINED
# undef DLOAD_2_DEFINED
#endif

#if !defined(NO_DLOAD2) && defined(HAVE_DL_H) && !defined(DLOAD_2_DEFINED)
# ifdef __hpux__
#  define DLOAD_2_DEFINED
void C_ccall dload_2(C_word c, C_word *av0)
{
  void *handle, *p;
  C_word
    entry = av0[ 0 ],
    name = av0[ 1 ],
    k = av0[ 2 ],,
    av[ 2 ];
  C_char *mname = (C_char *)C_data_pointer(name);

  /*
   * C_fprintf(C_stderr,
   *   "shl_loading %s : %s\n",
   *   (char *) C_data_pointer(name),
   *   (char *) C_data_pointer(entry));
   */

  if ((handle = (void *) shl_load(mname,
				  BIND_IMMEDIATE | DYNAMIC_PATH,
				  0L)) != NULL) {
    shl_t shl_handle = (shl_t) handle;

    /*** This version does not check for C_dynamic_and_unsafe. Fix it. */
    if (shl_findsym(&shl_handle, (char *) C_data_pointer(entry), TYPE_PROCEDURE, &p) == 0) {
      current_module_name = C_strdup(mname);
      current_module_handle = handle;

      if(debug_mode) {
	C_dbg(C_text("debug"), C_text("loading compiled library %s (" UWORD_FORMAT_STRING ")\n"),
	      current_module_name, (C_uword)current_module_handle);
      }

      av[ 0 ] = C_SCHEME_UNDEFINED;
      av[ 1 ] = k;
      ((C_proc)p)(2, av);       /* doesn't return */
    } else {
      C_dlerror = (char *) C_strerror(errno);
      shl_unload(shl_handle);
    }
  } else {
    C_dlerror = (char *) C_strerror(errno);
  }

  C_kontinue(k, C_SCHEME_FALSE);
}
# endif
#endif


#if !defined(NO_DLOAD2) && defined(HAVE_DLFCN_H) && !defined(DLOAD_2_DEFINED)
# ifndef __hpux__
#  define DLOAD_2_DEFINED
void C_ccall dload_2(C_word c, C_word *av0)
{
  void *handle, *p, *p2;
  C_word 
    entry = av0[ 0 ],
    name = av0[ 1 ],
    k = av0[ 2 ],
    av[ 2 ];
  C_char *topname = (C_char *)C_data_pointer(entry);
  C_char *mname = (C_char *)C_data_pointer(name);
  C_char *tmp;
  int tmp_len = 0;

  if((handle = C_dlopen(mname, dlopen_flags)) != NULL) {
    if((p = C_dlsym(handle, topname)) == NULL) {
      tmp_len = C_strlen(topname) + 2;
      tmp = (C_char *)C_malloc(tmp_len);

      if(tmp == NULL)
	panic(C_text("out of memory - cannot allocate toplevel name string"));

      C_strlcpy(tmp, C_text("_"), tmp_len);
      C_strlcat(tmp, topname, tmp_len);
      p = C_dlsym(handle, tmp);
      C_free(tmp);
    }

    if(p != NULL) {
      current_module_name = C_strdup(mname);
      current_module_handle = handle;

      if(debug_mode) {
	C_dbg(C_text("debug"), C_text("loading compiled library %s (" UWORD_FORMAT_STRING ")\n"),
	      current_module_name, (C_uword)current_module_handle);
      }

      av[ 0 ] = C_SCHEME_UNDEFINED;
      av[ 1 ] = k;
      ((C_proc)p)(2, av); /* doesn't return */
    }

    C_dlclose(handle);
  }
  
  C_dlerror = (char *)dlerror();
  C_kontinue(k, C_SCHEME_FALSE);
}
# endif
#endif


#if !defined(NO_DLOAD2) && (defined(HAVE_LOADLIBRARY) && defined(HAVE_GETPROCADDRESS)) && !defined(DLOAD_2_DEFINED)
# define DLOAD_2_DEFINED
void C_ccall dload_2(C_word c, C_word *av0)
{
  HINSTANCE handle;
  FARPROC p = NULL, p2;
  C_word
    entry = av0[ 0 ],
    name = av0[ 1 ],
    k = av0[ 2 ],
    av[ 2 ];
  C_char *topname = (C_char *)C_data_pointer(entry);
  C_char *mname = (C_char *)C_data_pointer(name);

  /* cannot use LoadLibrary on non-DLLs, so we use extension checking */
  if (C_header_size(name) >= 5) {
    char *n = (char*) C_data_pointer(name);
    int l = C_header_size(name);
    if (C_strncasecmp(".dll", n+l-5, 4) && 
	C_strncasecmp(".so", n+l-4, 3))
      C_kontinue(k, C_SCHEME_FALSE);
  }

  if((handle = LoadLibrary(mname)) != NULL) {
    if ((p = GetProcAddress(handle, topname)) != NULL) {
      current_module_name = C_strdup(mname);
      current_module_handle = handle;

      if(debug_mode) {
	C_dbg(C_text("debug"), C_text("loading compiled library %s (" UWORD_FORMAT_STRING ")\n"),
	      current_module_name, (C_uword)current_module_handle);
      }

      av[ 0 ] = C_SCHEME_UNDEFINED;
      av[ 1 ] = k;
      ((C_proc)p)(2, av);       /* doesn't return */
    }
    else FreeLibrary(handle);
  }

  C_dlerror = (char *) C_strerror(errno);
  C_kontinue(k, C_SCHEME_FALSE);
}
#endif


void C_ccall C_become(C_word c, C_word *av) 
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    table = av[ 2 ],
    tp, x, old, neu, i, *p;

  i = forwarding_table_size;
  p = forwarding_table;

  for(tp = table; tp != C_SCHEME_END_OF_LIST; tp = C_u_i_cdr(tp)) {
    x = C_u_i_car(tp);
    old = C_u_i_car(x);
    neu = C_u_i_cdr(x);

    if(i == 0) {
      if((forwarding_table = (C_word *)realloc(forwarding_table, (forwarding_table_size + 1) * 4 * sizeof(C_word))) == NULL)
	panic(C_text("out of memory - cannot re-allocate forwarding table"));
	
      i = forwarding_table_size;
      p = forwarding_table + forwarding_table_size * 2;
      forwarding_table_size *= 2;
    }

    *(p++) = old;
    *(p++) = neu;
    --i;
  }

  *p = 0;
  C_fromspace_top = C_fromspace_limit;
  C_save_and_reclaim_args((void *)become_2, 1, k);
}


void C_ccall become_2(C_word c, C_word *av)
{
  C_word k = av[ 0 ];

  *forwarding_table = 0;
  C_kontinue(k, C_SCHEME_UNDEFINED);
}


C_regparm C_word C_fcall
C_a_i_cpu_time(C_word **a, int c, C_word buf)
{
  C_word u, s = C_fix(0);

#if defined(C_NONUNIX) || defined(__CYGWIN__)
  if(CLOCKS_PER_SEC == 1000) u = clock();
  else u = C_uint64_to_num(a, ((C_u64)clock() / CLOCKS_PER_SEC) * 1000);
#else
  struct rusage ru;

  if(C_getrusage(RUSAGE_SELF, &ru) == -1) u = 0;
  else {
    u = C_uint64_to_num(a, (C_u64)ru.ru_utime.tv_sec * 1000 + ru.ru_utime.tv_usec / 1000);
    s = C_uint64_to_num(a, (C_u64)ru.ru_stime.tv_sec * 1000 + ru.ru_stime.tv_usec / 1000);
  }
#endif

  /* buf must not be in nursery */
  C_set_block_item(buf, 0, u);
  C_set_block_item(buf, 1, s);
  return buf;
}


C_regparm C_word C_fcall C_a_i_make_locative(C_word **a, int c, C_word type, C_word object, C_word index, C_word weak)
{
  C_word *loc = *a;
  int offset, i, in = C_unfix(index);
  *a = loc + C_SIZEOF_LOCATIVE;

  loc[ 0 ] = C_LOCATIVE_TAG;

  switch(C_unfix(type)) {
  case C_SLOT_LOCATIVE: in *= sizeof(C_word); break;
  case C_U16_LOCATIVE:
  case C_S16_LOCATIVE: in *= 2; break;
  case C_U32_LOCATIVE:
  case C_F32_LOCATIVE:
  case C_S32_LOCATIVE: in *= 4; break;
  case C_U64_LOCATIVE:
  case C_S64_LOCATIVE:
  case C_F64_LOCATIVE: in *= 8; break;
  }

  offset = in + sizeof(C_header);
  loc[ 1 ] = object + offset;
  loc[ 2 ] = C_fix(offset);
  loc[ 3 ] = type;
  loc[ 4 ] = C_truep(weak) ? C_SCHEME_FALSE : object;

  return (C_word)loc;
}

C_regparm C_word C_fcall C_a_i_locative_ref(C_word **a, int c, C_word loc)
{
  C_word *ptr;

  if(C_immediatep(loc) || C_block_header(loc) != C_LOCATIVE_TAG)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-ref", loc);

  ptr = (C_word *)C_block_item(loc, 0);

  if(ptr == NULL) barf(C_LOST_LOCATIVE_ERROR, "locative-ref", loc);

  switch(C_unfix(C_block_item(loc, 2))) {
  case C_SLOT_LOCATIVE: return *ptr;
  case C_CHAR_LOCATIVE: return C_make_character(*((char *)ptr));
  case C_U8_LOCATIVE: return C_fix(*((unsigned char *)ptr));
  case C_S8_LOCATIVE: return C_fix(*((char *)ptr));
  case C_U16_LOCATIVE: return C_fix(*((unsigned short *)ptr));
  case C_S16_LOCATIVE: return C_fix(*((short *)ptr));
  case C_U32_LOCATIVE: return C_unsigned_int_to_num(a, *((C_u32 *)ptr));
  case C_S32_LOCATIVE: return C_int_to_num(a, *((C_s32 *)ptr));
  case C_U64_LOCATIVE: return C_uint64_to_num(a, *((C_u64 *)ptr));
  case C_S64_LOCATIVE: return C_int64_to_num(a, *((C_s64 *)ptr));
  case C_F32_LOCATIVE: return C_flonum(a, *((float *)ptr));
  case C_F64_LOCATIVE: return C_flonum(a, *((double *)ptr));
  default: panic(C_text("bad locative type"));
  }
}

C_regparm C_word C_fcall C_i_locative_set(C_word loc, C_word x)
{
  C_word *ptr, val;

  if(C_immediatep(loc) || C_block_header(loc) != C_LOCATIVE_TAG)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", loc);

  ptr = (C_word *)C_block_item(loc, 0);

  if(ptr == NULL)
    barf(C_LOST_LOCATIVE_ERROR, "locative-set!", loc);

  switch(C_unfix(C_block_item(loc, 2))) {
  case C_SLOT_LOCATIVE: C_mutate(ptr, x); break;

  case C_CHAR_LOCATIVE:
    if((x & C_IMMEDIATE_TYPE_BITS) != C_CHARACTER_BITS)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);
      
    *((char *)ptr) = C_character_code(x); 
    break;

  case C_U8_LOCATIVE: 
    if((x & C_FIXNUM_BIT) == 0)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);

    *((unsigned char *)ptr) = C_unfix(x); 
    break;

  case C_S8_LOCATIVE: 
    if((x & C_FIXNUM_BIT) == 0)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);
    
    *((char *)ptr) = C_unfix(x); 
    break;

  case C_U16_LOCATIVE: 
    if((x & C_FIXNUM_BIT) == 0)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);

    *((unsigned short *)ptr) = C_unfix(x); 
    break;

  case C_S16_LOCATIVE: 
    if((x & C_FIXNUM_BIT) == 0)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);

    *((short *)ptr) = C_unfix(x); 
    break;

  case C_U32_LOCATIVE: 
    if(!C_truep(C_i_exact_integerp(x)))
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);

    *((C_u32 *)ptr) = C_num_to_unsigned_int(x); 
    break;

  case C_S32_LOCATIVE: 
    if(!C_truep(C_i_exact_integerp(x)))
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);
    
    *((C_s32 *)ptr) = C_num_to_int(x); 
    break;

  case C_U64_LOCATIVE: 
    if(!C_truep(C_i_exact_integerp(x)))
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);

    *((C_u64 *)ptr) = C_num_to_uint64(x); 
    break;

  case C_S64_LOCATIVE: 
    if(!C_truep(C_i_exact_integerp(x)))
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);
    
    *((C_s64 *)ptr) = C_num_to_int64(x); 
    break;

  case C_F32_LOCATIVE: 
    if(C_immediatep(x) || C_block_header(x) != C_FLONUM_TAG)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);
    
    *((float *)ptr) = C_flonum_magnitude(x); 
    break;

  case C_F64_LOCATIVE: 
    if(C_immediatep(x) || C_block_header(x) != C_FLONUM_TAG)
      barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-set!", x);
    
    *((double *)ptr) = C_flonum_magnitude(x); 
    break;

  default: panic(C_text("bad locative type"));
  }

  return C_SCHEME_UNDEFINED;
}


C_regparm C_word C_fcall C_i_locative_to_object(C_word loc)
{
  C_word *ptr;

  if(C_immediatep(loc) || C_block_header(loc) != C_LOCATIVE_TAG)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative->object", loc);

  ptr = (C_word *)C_block_item(loc, 0);

  if(ptr == NULL) return C_SCHEME_FALSE;
  else return (C_word)ptr - C_unfix(C_block_item(loc, 1));
}


C_regparm C_word C_fcall C_i_locative_index(C_word loc)
{
  int bytes;

  if(C_immediatep(loc) || C_block_header(loc) != C_LOCATIVE_TAG)
    barf(C_BAD_ARGUMENT_TYPE_ERROR, "locative-index", loc);

  bytes = C_unfix(C_block_item(loc, 1)) - sizeof(C_header);

  switch(C_unfix(C_block_item(loc, 2))) {
  case C_SLOT_LOCATIVE: return C_fix(bytes/sizeof(C_word)); break;

  case C_CHAR_LOCATIVE:
  case C_U8_LOCATIVE:
  case C_S8_LOCATIVE: return C_fix(bytes); break;

  case C_U16_LOCATIVE:
  case C_S16_LOCATIVE: return C_fix(bytes/2); break;

  case C_U32_LOCATIVE:
  case C_S32_LOCATIVE:
  case C_F32_LOCATIVE: return C_fix(bytes/4); break;

  case C_U64_LOCATIVE:
  case C_S64_LOCATIVE:
  case C_F64_LOCATIVE: return C_fix(bytes/8); break;

  default: panic(C_text("bad locative type"));
  }
}


/* GC protection of user-variables: */

C_regparm void C_fcall C_gc_protect(C_word **addr, int n)
{
  int k;

  if(collectibles_top + n >= collectibles_limit) {
    k = collectibles_limit - collectibles;
    collectibles = (C_word **)C_realloc(collectibles, sizeof(C_word *) * k * 2);

    if(collectibles == NULL)
      panic(C_text("out of memory - cannot allocate GC protection vector"));
    
    collectibles_top = collectibles + k;
    collectibles_limit = collectibles + k * 2;
  }

  C_memcpy(collectibles_top, addr, n * sizeof(C_word *));
  collectibles_top += n;
}


C_regparm void C_fcall C_gc_unprotect(int n)
{
  collectibles_top -= n;
}


/* Map procedure-ptr to id or id to ptr: */

C_char *C_lookup_procedure_id(void *ptr)
{
  LF_LIST *lfl;
  C_PTABLE_ENTRY *pt;

  for(lfl = lf_list; lfl != NULL; lfl = lfl->next) {
    pt = lfl->ptable;

    if(pt != NULL) {
      while(pt->id != NULL) {
	if(pt->ptr == ptr) return pt->id;
	else ++pt;
      }
    }
  }

  return NULL;
}


void *C_lookup_procedure_ptr(C_char *id)
{
  LF_LIST *lfl;
  C_PTABLE_ENTRY *pt;

  for(lfl = lf_list; lfl != NULL; lfl = lfl->next) {
    pt = lfl->ptable;

    if(pt != NULL) {
      while(pt->id != NULL) {
	if(!C_strcmp(id, pt->id)) return pt->ptr;
	else ++pt;
      }
    }
  }

  return NULL;
}


void C_ccall C_copy_closure(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    proc = av[ 2 ],
    *p;
  int n = C_header_size(proc);

  if(!C_demand(n + 1)) 
    C_save_and_reclaim_args((void *)copy_closure_2, 2, proc, k);
  else {
    C_save(proc);
    C_save(k);
    p = C_temporary_stack;
    C_temporary_stack = C_temporary_stack_bottom;
    copy_closure_2(0, p);
  }
}


static void C_ccall copy_closure_2(C_word c, C_word *av)
{
  C_word 
    k = av[ 0 ],
    proc = av[ 1 ];
  int cells = C_header_size(proc);
  C_word
    *ptr = C_alloc(C_SIZEOF_CLOSURE(cells)),
    *p = ptr;

  *(p++) = C_CLOSURE_TYPE | cells;
  /* this is only allowed because the storage is freshly allocated: */
  C_memcpy_slots(p, C_data_pointer(proc), cells);
  C_kontinue(k, (C_word)ptr);
}


/* Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn */

void C_ccall C_call_with_cthulhu(C_word c, C_word *av)
{
  C_word
    proc = av[ 2 ],
    *a = C_alloc(C_SIZEOF_CLOSURE(1)),
    av2[ 2 ];

  av2[ 0 ] = proc;
  av2[ 1 ] = C_closure(&a, 1, (C_word)termination_continuation); /* k */
  C_do_apply(2, av2);
}


/* fixnum arithmetic with overflow detection (from "Hacker's Delight" by Hank Warren) 
   These routines return #f if the operation failed due to overflow. 
 */

C_regparm C_word C_fcall C_i_o_fixnum_plus(C_word n1, C_word n2)
{
  C_word x1, x2, s;
  
  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);
  s = x1 + x2;

#ifdef C_SIXTY_FOUR
  if((((s ^ x1) & (s ^ x2)) >> 62) != 0) return C_SCHEME_FALSE;
#else
  if((((s ^ x1) & (s ^ x2)) >> 30) != 0) return C_SCHEME_FALSE;
#endif
  else return C_fix(s);
}


C_regparm C_word C_fcall C_i_o_fixnum_difference(C_word n1, C_word n2)
{
  C_word x1, x2, s;

  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);
  s = x1 - x2;
  
#ifdef C_SIXTY_FOUR
  if((((s ^ x1) & ~(s ^ x2)) >> 62) != 0) return C_SCHEME_FALSE;
#else
  if((((s ^ x1) & ~(s ^ x2)) >> 30) != 0) return C_SCHEME_FALSE;
#endif
  else return C_fix(s);
}


C_regparm C_word C_fcall C_i_o_fixnum_times(C_word n1, C_word n2)
{
  C_word x1, x2;
  C_uword x1u, x2u;
#ifdef C_SIXTY_FOUR
# ifdef C_LLP
  C_uword c = 1ULL<<63ULL;
# else
  C_uword c = 1UL<<63UL;
# endif
#else
  C_uword c = 1UL<<31UL;
#endif

  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  if((n1 & C_INT_SIGN_BIT) == (n2 & C_INT_SIGN_BIT)) --c;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);
  x1u = x1 < 0 ? -x1 : x1;
  x2u = x2 < 0 ? -x2 : x2;

  if(x2u != 0 && x1u > (c / x2u)) return C_SCHEME_FALSE;
  
  x1 = x1 * x2;

  if(C_fitsinfixnump(x1)) return C_fix(x1);
  else return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_o_fixnum_quotient(C_word n1, C_word n2)
{
  C_word x1, x2;

  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);

  if(x2 == 0)
    barf(C_DIVISION_BY_ZERO_ERROR, "fx/?");

#ifdef C_SIXTY_FOUR
  if(x1 == 0x8000000000000000L && x2 == -1) return C_SCHEME_FALSE;
#else
  if(x1 == 0x80000000L && x2 == -1) return C_SCHEME_FALSE;
#endif

  x1 = x1 / x2;

  if(C_fitsinfixnump(x1)) return C_fix(x1);
  else return C_SCHEME_FALSE;
}


C_regparm C_word C_fcall C_i_o_fixnum_and(C_word n1, C_word n2)
{
  C_uword x1, x2, r;

  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);
  r = x1 & x2;
  
  if(((r & C_INT_SIGN_BIT) >> 1) != (r & C_INT_TOP_BIT)) return C_SCHEME_FALSE;
  else return C_fix(r);
}


C_regparm C_word C_fcall C_i_o_fixnum_ior(C_word n1, C_word n2)
{
  C_uword x1, x2, r;

  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);
  r = x1 | x2;
  
  if(((r & C_INT_SIGN_BIT) >> 1) != (r & C_INT_TOP_BIT)) return C_SCHEME_FALSE;
  else return C_fix(r);
}


C_regparm C_word C_fcall C_i_o_fixnum_xor(C_word n1, C_word n2)
{
  C_uword x1, x2, r;

  if((n1 & C_FIXNUM_BIT) == 0 || (n2 & C_FIXNUM_BIT) == 0) return C_SCHEME_FALSE;

  x1 = C_unfix(n1);
  x2 = C_unfix(n2);
  r = x1 ^ x2;
  
  if(((r & C_INT_SIGN_BIT) >> 1) != (r & C_INT_TOP_BIT)) return C_SCHEME_FALSE;
  else return C_fix(r);
}


/* decoding of literals in compressed format */

static C_regparm C_uword C_fcall decode_size(C_char **str)
{
  C_uchar **ustr = (C_uchar **)str;
  C_uword size = (*((*ustr)++) & 0xff) << 16; /* always big endian */

  size |= (*((*ustr)++) & 0xff) << 8;
  size |= (*((*ustr)++) & 0xff);
  return size;
}


static C_regparm C_word C_fcall decode_literal2(C_word **ptr, C_char **str,
						C_word *dest)
{
  C_ulong bits = *((*str)++) & 0xff;
  C_word *data, *dptr, val;
  C_uword size;

  /* vvv this can be taken out at a later stage (once it works reliably) vvv */
  if(bits != 0xfe)
    panic(C_text("invalid encoded literal format"));

  bits = *((*str)++) & 0xff;
  /* ^^^ */

#ifdef C_SIXTY_FOUR
  bits <<= 24 + 32;
#else
  bits <<= 24;
#endif

  if(bits == C_HEADER_BITS_MASK) {		/* special/immediate */
    switch(0xff & *((*str)++)) {
    case C_BOOLEAN_BITS: 
      return C_mk_bool(*((*str)++));

    case C_CHARACTER_BITS: 
      return C_make_character(decode_size(str));

    case C_SCHEME_END_OF_LIST:
    case C_SCHEME_UNDEFINED:
    case C_SCHEME_END_OF_FILE:
    case C_SCHEME_BROKEN_WEAK_PTR:
      return (C_word)(*(*str - 1));

    case C_FIXNUM_BIT:
      val = (C_uword)(signed char)*((*str)++) << 24; /* always big endian */
      val |= ((C_uword)*((*str)++) & 0xff) << 16;
      val |= ((C_uword)*((*str)++) & 0xff) << 8;
      val |= ((C_uword)*((*str)++) & 0xff);
      return C_fix(val); 

#ifdef C_SIXTY_FOUR
    case ((C_STRING_TYPE | C_GC_FORWARDING_BIT) >> (24 + 32)) & 0xff:
#else
    case ((C_STRING_TYPE | C_GC_FORWARDING_BIT) >> 24) & 0xff:
#endif
      bits = (C_STRING_TYPE | C_GC_FORWARDING_BIT);
      break;

    default: 
      panic(C_text("invalid encoded special literal"));
    }
  }

#ifndef C_SIXTY_FOUR
  if((bits & C_8ALIGN_BIT) != 0) {
    /* Align _data_ on 8-byte boundary: */
    if(C_aligned8(*ptr)) ++(*ptr);
  }
#endif

  val = (C_word)(*ptr);

  if((bits & C_SPECIALBLOCK_BIT) != 0)
    panic(C_text("literals with special bit cannot be decoded"));

  if(bits == C_FLONUM_TYPE) {
    val = C_flonum(ptr, decode_flonum_literal(*str));
    while(*((*str)++) != '\0');      /* skip terminating '\0' */
    return val;
  }

  size = decode_size(str);

  switch(bits) {
  /* This cannot be encoded as a blob due to endianness differences */
  case (C_STRING_TYPE | C_GC_FORWARDING_BIT): /* This represents "exact int" */
    /* bignums are also allocated statically */
    val = C_static_bignum(ptr, size, *str);
    *str += size;
    break;

  case C_STRING_TYPE:
    /* strings are always allocated statically */
    val = C_static_string(ptr, size, *str);
    *str += size;
    break;
    
  case C_BYTEVECTOR_TYPE:
    /* ... as are bytevectors (blobs) */
    val = C_static_bytevector(ptr, size, *str);
    *str += size;
    break;
    
  case C_SYMBOL_TYPE:
    if(dest == NULL) 
      panic(C_text("invalid literal symbol destination"));

    if (**str == '\1') {
      val = C_h_intern(dest, size, ++*str);
    } else if (**str == '\2') {
      val = C_h_intern_kw(dest, size, ++*str);
    } else {
      C_snprintf(buffer, sizeof(buffer), C_text("Unknown symbol subtype: %d"), (int)**str);
      panic(buffer);
    }
    *str += size;
    break;

  case C_LAMBDA_INFO_TYPE:
    /* lambda infos are always allocated statically */
    val = C_static_lambda_info(ptr, size, *str);
    *str += size;
    break;

  default:
    *((*ptr)++) = C_make_header(bits, size);
    data = *ptr;

    if((bits & C_BYTEBLOCK_BIT) != 0) {
      C_memcpy(data, *str, size);
      size = C_align(size);
      *str += size;
      *ptr = (C_word *)C_align((C_word)(*ptr) + size);
    }
    else {
      C_word *dptr = *ptr;
      *ptr += size;

      while(size--) {
	*dptr = decode_literal2(ptr, str, dptr);
	++dptr;
      }
    }
  }

  return val;
}


C_regparm C_word C_fcall
C_decode_literal(C_word **ptr, C_char *str)
{
  return decode_literal2(ptr, &str, NULL);
}


void
C_use_private_repository(C_char *path)
{
  private_repository = path;
}


C_char *
C_private_repository_path()
{
  return private_repository;
}

C_char *
C_executable_pathname() {
#ifdef SEARCH_EXE_PATH
  return C_main_exe == NULL ? NULL : C_strdup(C_main_exe);
#else
  return C_resolve_executable_pathname(NULL);
#endif
}

C_char *
C_executable_dirname() {
  int len;
  C_char *path;

  if((path = C_executable_pathname()) == NULL)
    return NULL;

#if defined(_WIN32) && !defined(__CYGWIN__)
  for(len = C_strlen(path); len >= 0 && path[len] != '\\'; len--);
#else
  for(len = C_strlen(path); len >= 0 && path[len] != '/'; len--);
#endif

  path[len] = '\0';
  return path;
}

C_char *
C_resolve_executable_pathname(C_char *fname)
{
  int n;
  C_char *buffer = (C_char *) C_malloc(C_MAX_PATH);

  if(buffer == NULL) return NULL;

#if defined(__linux__) || defined(__sun)
  C_char linkname[64]; /* /proc/<pid>/exe */
  pid_t pid = C_getpid();

# ifdef __linux__
  C_snprintf(linkname, sizeof(linkname), "/proc/%i/exe", pid);
# else
  C_snprintf(linkname, sizeof(linkname), "/proc/%i/path/a.out", pid); /* SunOS / Solaris */
# endif

  n = C_readlink(linkname, buffer, C_MAX_PATH);
  if(n < 0 || n >= C_MAX_PATH)
    goto error;

  buffer[n] = '\0';
  return buffer;
#elif defined(_WIN32) && !defined(__CYGWIN__)
  n = GetModuleFileName(NULL, buffer, C_MAX_PATH);
  if(n == 0 || n >= C_MAX_PATH)
    goto error;

  return buffer;
#elif defined(C_MACOSX)
  C_char buf[C_MAX_PATH];
  C_u32 size = C_MAX_PATH;

  if(_NSGetExecutablePath(buf, &size) != 0)
    goto error;

  if(C_realpath(buf, buffer) == NULL)
    goto error;

  return buffer;
#elif defined(__HAIKU__)
{
  image_info info;
  int32 cookie = 0;

  while (get_next_image_info(0, &cookie, &info) == B_OK) {
    if (info.type == B_APP_IMAGE) {
      C_strlcpy(buffer, info.name, C_MAX_PATH);
      return buffer;
    }
  }
}
#elif defined(SEARCH_EXE_PATH)
  int len;
  C_char *path, buf[C_MAX_PATH];

  /* no name given (execve) */
  if(fname == NULL)
    goto error;

  /* absolute pathname */
  if(fname[0] == '/') {
    if(C_realpath(fname, buffer) == NULL)
      goto error;
    else
      return buffer;
  }

  /* current directory */
  if(C_strchr(fname, '/') != NULL) {
    if(C_getcwd(buffer, C_MAX_PATH) == NULL)
      goto error;

    n = C_snprintf(buf, C_MAX_PATH, "%s/%s", buffer, fname);
    if(n < 0 || n >= C_MAX_PATH)
      goto error;

    if(C_access(buf, X_OK) == 0) {
      if(C_realpath(buf, buffer) == NULL)
        goto error;
      else
        return buffer;
    }
  }

  /* walk PATH */
  if((path = C_getenv("PATH")) == NULL)
    goto error;

  do {
    /* check PATH entry length */
    len = C_strcspn(path, ":");
    if(len == 0 || len >= C_MAX_PATH)
      continue;

    /* "<path>/<fname>" to buf */
    C_strncpy(buf, path, len);
    n = C_snprintf(buf + len, C_MAX_PATH - len, "/%s", fname);
    if(n < 0 || n + len >= C_MAX_PATH)
      continue;

    if(C_access(buf, X_OK) != 0)
      continue;

    /* fname found, resolve links */
    if(C_realpath(buf, buffer) != NULL)
      return buffer;

  /* seek next entry, skip colon */
  } while (path += len, *path++);
#else
# error "Please either define SEARCH_EXE_PATH in Makefile.<platform> or implement C_resolve_executable_pathname for your platform!"
#endif

error:
  C_free(buffer);
  return NULL;
}

C_regparm C_word C_fcall
C_i_getprop(C_word sym, C_word prop, C_word def)
{
  C_word pl = C_symbol_plist(sym);

  while(pl != C_SCHEME_END_OF_LIST) {
    if(C_block_item(pl, 0) == prop)
      return C_u_i_car(C_u_i_cdr(pl));
    else pl = C_u_i_cdr(C_u_i_cdr(pl));
  }

  return def;
}


C_regparm C_word C_fcall
C_putprop(C_word **ptr, C_word sym, C_word prop, C_word val)
{
  C_word pl = C_symbol_plist(sym);

  /* Newly added plist?  Ensure the symbol stays! */
  if (pl == C_SCHEME_END_OF_LIST) C_i_persist_symbol(sym);

  while(pl != C_SCHEME_END_OF_LIST) {
    if(C_block_item(pl, 0) == prop) {
      C_mutate(&C_u_i_car(C_u_i_cdr(pl)), val);
      return val;
    }
    else pl = C_u_i_cdr(C_u_i_cdr(pl));
  }

  pl = C_a_pair(ptr, val, C_symbol_plist(sym));
  pl = C_a_pair(ptr, prop, pl);
  C_mutate_slot(&C_symbol_plist(sym), pl);
  return val;
}


C_regparm C_word C_fcall
C_i_get_keyword(C_word kw, C_word args, C_word def)
{
  while(!C_immediatep(args)) {
    if(C_header_type(args) == C_PAIR_TYPE) {
      if(kw == C_u_i_car(args)) {
	args = C_u_i_cdr(args);

	if(C_immediatep(args) || C_header_type(args) != C_PAIR_TYPE)
	  return def;
	else return C_u_i_car(args);
      }
      else {
	args = C_u_i_cdr(args);

	if(C_immediatep(args) || C_header_type(args) != C_PAIR_TYPE)
	  return def;
	else args = C_u_i_cdr(args);
      }
    }
  }

  return def;
}

C_word C_i_dump_statistical_profile()
{
  PROFILE_BUCKET *b, *b2, **bp;
  FILE *fp;
  C_char *k1, *k2 = NULL;
  int n;
  double ms;

  assert(profiling);
  assert(profile_table != NULL);

  set_profile_timer(0);

  profiling = 0; /* In case a SIGPROF is delivered late */
  bp = profile_table;

  C_snprintf(buffer, STRING_BUFFER_SIZE, C_text("PROFILE.%d"), C_getpid());

  if(debug_mode)
    C_dbg(C_text("debug"), C_text("dumping statistical profile to `%s'...\n"), buffer);

  fp = C_fopen(buffer, "w");
  if (fp == NULL)
    panic(C_text("could not write profile!"));

  C_fputs(C_text("statistical\n"), fp);
  for(n = 0; n < PROFILE_TABLE_SIZE; ++n) {
    for(b = bp[ n ]; b != NULL; b = b2) {
      b2 = b->next;

      k1 = b->key;
      C_fputs(C_text("(|"), fp);
      /* Dump raw C string as if it were a symbol */
      while((k2 = C_strpbrk(k1, C_text("\\|"))) != NULL) {
        C_fwrite(k1, 1, k2-k1, fp);
        C_fputc('\\', fp);
        C_fputc(*k2, fp);
        k1 = k2+1;
      }
      C_fputs(k1, fp);
      ms = (double)b->sample_count * (double)profile_frequency / 1000.0;
      C_fprintf(fp, C_text("| " UWORD_COUNT_FORMAT_STRING " %lf)\n"),
                b->call_count, ms);
      C_free(b);
    }
  }

  C_fclose(fp);
  C_free(profile_table);
  profile_table = NULL;

  return C_SCHEME_UNDEFINED;
}

void C_ccall C_dump_heap_state(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ];

  /* make sure heap is compacted */
  C_save(k);
  C_fromspace_top = C_fromspace_limit; /* force major GC */
  C_reclaim((void *)dump_heap_state_2, 1);
}


static C_ulong
hdump_hash(C_word key)
{
  return (C_ulong)key % HDUMP_TABLE_SIZE;
}


static void
hdump_count(C_word key, int n, int t)
{
  HDUMP_BUCKET **bp = hdump_table + hdump_hash(key);
  HDUMP_BUCKET *b = *bp;

  while(b != NULL) {
    if(b->key == key) {
      b->count += n;
      b->total += t;
      return;
    }
    else b = b->next;
  }

  b = (HDUMP_BUCKET *)C_malloc(sizeof(HDUMP_BUCKET));
  
  if(b == 0)
    panic(C_text("out of memory - can not allocate heap-dump table-bucket"));

  b->next = *bp;
  b->key = key;
  *bp = b;
  b->count = n;
  b->total = t;
}


static void C_ccall dump_heap_state_2(C_word c, C_word *av)
{
  C_word k = av[ 0 ];
  HDUMP_BUCKET *b, *b2, **bp;
  int n, bytes;
  C_byte *scan;
  C_SCHEME_BLOCK *sbp;
  C_header h;
  C_word x, key, *p;
  int imm = 0, blk = 0;
  
  hdump_table = (HDUMP_BUCKET **)C_malloc(HDUMP_TABLE_SIZE * sizeof(HDUMP_BUCKET *));

  if(hdump_table == NULL)
    panic(C_text("out of memory - can not allocate heap-dump table"));

  C_memset(hdump_table, 0, sizeof(HDUMP_BUCKET *) * HDUMP_TABLE_SIZE);

  scan = fromspace_start;

  while(scan < C_fromspace_top) {
    ++blk;
    sbp = (C_SCHEME_BLOCK *)scan;

    if(*((C_word *)sbp) == ALIGNMENT_HOLE_MARKER) 
      sbp = (C_SCHEME_BLOCK *)((C_word *)sbp + 1);

    n = C_header_size(sbp);
    h = sbp->header;
    bytes = (h & C_BYTEBLOCK_BIT) ? n : n * sizeof(C_word);
    key = (C_word)(h & C_HEADER_BITS_MASK);
    p = sbp->data;

    if(key == C_STRUCTURE_TYPE) key = *p;

    hdump_count(key, 1, bytes);

    if(n > 0 && (h & C_BYTEBLOCK_BIT) == 0) {
      if((h & C_SPECIALBLOCK_BIT) != 0) {
	--n;
	++p;
      }

      while(n--) {
	x = *(p++);

	if(C_immediatep(x)) {
	  ++imm;

	  if((x & C_FIXNUM_BIT) != 0) key = C_fix(1);
	  else {
	    switch(x & C_IMMEDIATE_TYPE_BITS) {
	    case C_BOOLEAN_BITS: key = C_SCHEME_TRUE; break;
	    case C_CHARACTER_BITS: key = C_make_character('A'); break;
	    default: key = x;
	    }
	  }

	  hdump_count(key, 1, 0);
	}
      }
    }

    scan = (C_byte *)sbp + C_align(bytes) + sizeof(C_word);
  }

  bp = hdump_table;
  /* HACK */
#define C_WEAK_PAIR_TYPE (C_PAIR_TYPE | C_SPECIALBLOCK_BIT)
  
  for(n = 0; n < HDUMP_TABLE_SIZE; ++n) {
    for(b = bp[ n ]; b != NULL; b = b2) {
      b2 = b->next;

      switch(b->key) {
      case C_fix(1): C_fprintf(C_stderr,                 C_text("fixnum         ")); break;
      case C_SCHEME_TRUE: C_fprintf(C_stderr,            C_text("boolean        ")); break;
      case C_SCHEME_END_OF_LIST: C_fprintf(C_stderr,     C_text("null           ")); break;
      case C_SCHEME_UNDEFINED  : C_fprintf(C_stderr,     C_text("void           ")); break;
      case C_SCHEME_BROKEN_WEAK_PTR: C_fprintf(C_stderr, C_text("broken weak ptr")); break;
      case C_make_character('A'): C_fprintf(C_stderr,    C_text("character      ")); break;
      case C_SCHEME_END_OF_FILE: C_fprintf(C_stderr,     C_text("eof            ")); break;
      case C_SCHEME_UNBOUND: C_fprintf(C_stderr,         C_text("unbound        ")); break;
      case C_SYMBOL_TYPE: C_fprintf(C_stderr,            C_text("symbol         ")); break;
      case C_STRING_TYPE: C_fprintf(C_stderr,            C_text("string         ")); break;
      case C_PAIR_TYPE: C_fprintf(C_stderr,              C_text("pair           ")); break;
      case C_CLOSURE_TYPE: C_fprintf(C_stderr,           C_text("closure        ")); break;
      case C_FLONUM_TYPE: C_fprintf(C_stderr,            C_text("flonum         ")); break;
      case C_PORT_TYPE: C_fprintf(C_stderr,              C_text("port           ")); break;
      case C_POINTER_TYPE: C_fprintf(C_stderr,           C_text("pointer        ")); break;
      case C_LOCATIVE_TYPE: C_fprintf(C_stderr,          C_text("locative       ")); break;
      case C_TAGGED_POINTER_TYPE: C_fprintf(C_stderr,    C_text("tagged pointer ")); break;
      case C_LAMBDA_INFO_TYPE: C_fprintf(C_stderr,       C_text("lambda info    ")); break;
      case C_WEAK_PAIR_TYPE: C_fprintf(C_stderr,         C_text("weak pair      ")); break;
      case C_VECTOR_TYPE: C_fprintf(C_stderr,            C_text("vector         ")); break;
      case C_BYTEVECTOR_TYPE: C_fprintf(C_stderr,        C_text("bytevector     ")); break;
      case C_BIGNUM_TYPE: C_fprintf(C_stderr,            C_text("bignum         ")); break;
      case C_CPLXNUM_TYPE: C_fprintf(C_stderr,           C_text("cplxnum        ")); break;
      case C_RATNUM_TYPE: C_fprintf(C_stderr,            C_text("ratnum         ")); break;
	/* XXX this is sort of funny: */
      case C_BYTEBLOCK_BIT: C_fprintf(C_stderr,          C_text("blob           ")); break;
      default:
	x = b->key;

	if(!C_immediatep(x) && C_header_bits(x) == C_SYMBOL_TYPE) {
	  x = C_block_item(x, 1);
	  C_fprintf(C_stderr, C_text("`%.*s'"), (int)C_header_size(x), C_c_string(x));
	}
	else C_fprintf(C_stderr, C_text("unknown key " UWORD_FORMAT_STRING), (C_uword)b->key);
      }

      C_fprintf(C_stderr, C_text("\t%d"), b->count);

      if(b->total > 0) 
	C_fprintf(C_stderr, C_text("\t%d bytes"), b->total);

      C_fputc('\n', C_stderr);
      C_free(b);
    }
  }

  C_fprintf(C_stderr, C_text("\ntotal number of blocks: %d, immediates: %d\n"),
	    blk, imm);
  C_free(hdump_table);
  C_kontinue(k, C_SCHEME_UNDEFINED);
}


static void C_ccall filter_heap_objects_2(C_word c, C_word *av)
{
  void *func = C_pointer_address(av[ 0 ]);
  C_word 
    userarg = av[ 1 ],
    vector = av[ 2 ],
    k = av[ 3 ];
  int n, bytes;
  C_byte *scan;
  C_SCHEME_BLOCK *sbp;
  C_header h;
  C_word *p;
  int vecsize = C_header_size(vector);
  typedef int (*filterfunc)(C_word x, C_word userarg);
  filterfunc ff = (filterfunc)func;
  int vcount = 0;

  scan = fromspace_start;

  while(scan < C_fromspace_top) {
    sbp = (C_SCHEME_BLOCK *)scan;

    if(*((C_word *)sbp) == ALIGNMENT_HOLE_MARKER) 
      sbp = (C_SCHEME_BLOCK *)((C_word *)sbp + 1);

    n = C_header_size(sbp);
    h = sbp->header;
    bytes = (h & C_BYTEBLOCK_BIT) ? n : n * sizeof(C_word);
    p = sbp->data;

    if(ff((C_word)sbp, userarg)) {
      if(vcount < vecsize) {
	C_set_block_item(vector, vcount, (C_word)sbp);
	++vcount;
      }
      else {
	C_kontinue(k, C_fix(-1));
      }
    }

    scan = (C_byte *)sbp + C_align(bytes) + sizeof(C_word);
  }

  C_kontinue(k, C_fix(vcount));
}


void C_ccall C_filter_heap_objects(C_word c, C_word *av)
{
  C_word
    /* closure = av[ 0 ] */
    k = av[ 1 ],
    func = av[ 2 ],
    vector = av[ 3 ],
    userarg = av[ 4 ];

  /* make sure heap is compacted */
  C_save(k);
  C_save(vector);
  C_save(userarg);
  C_save(func);
  C_fromspace_top = C_fromspace_limit; /* force major GC */
  C_reclaim((void *)filter_heap_objects_2, 4);
}

C_regparm C_word C_fcall C_i_process_sleep(C_word n)
{
#if defined(_WIN32) && !defined(__CYGWIN__)
  Sleep(C_unfix(n) * 1000);
  return C_fix(0);
#else
  return C_fix(sleep(C_unfix(n)));
#endif
}

C_regparm C_word C_fcall 
C_i_file_exists_p(C_word name, C_word file, C_word dir)
{
  struct stat buf;
  int res;

  res = C_stat(C_c_string(name), &buf);

  if(res != 0) {
    switch(errno) {
    case ENOENT: return C_SCHEME_FALSE;
    case EOVERFLOW: return C_truep(dir) ? C_SCHEME_FALSE : C_SCHEME_TRUE;
    case ENOTDIR: return C_SCHEME_FALSE;
    default: return C_fix(res);
    }
  }

  switch(buf.st_mode & S_IFMT) {
  case S_IFDIR: return C_truep(file) ? C_SCHEME_FALSE : C_SCHEME_TRUE;
  default: return C_truep(dir) ? C_SCHEME_FALSE : C_SCHEME_TRUE;
  }
}


C_regparm C_word C_fcall
C_i_pending_interrupt(C_word dummy)
{
  if(pending_interrupts_count > 0) {
    handling_interrupts = 1; /* Lock out further forced GCs until we're done */
    return C_fix(pending_interrupts[ --pending_interrupts_count ]);
  } else {
    handling_interrupts = 0; /* OK, can go on */
    return C_SCHEME_FALSE;
  }
}


/* random numbers, mostly lifted from 
  https://github.com/jedisct1/libsodium/blob/master/src/libsodium/randombytes/sysrandom/randombytes_sysrandom.c
*/

#ifdef __linux__
# include <sys/syscall.h>
#endif


#if !defined(_WIN32) 
static C_word random_urandom(C_word buf, int count)
{
  static int fd = -1;
  int off = 0, r;

  if(fd == -1) {
    fd = open("/dev/urandom", O_RDONLY);

    if(fd == -1) return C_SCHEME_FALSE;
  }

  while(count > 0) {
    r = read(fd, C_data_pointer(buf) + off, count);

    if(r == -1) {
      if(errno != EINTR && errno != EAGAIN) return C_SCHEME_FALSE;
      else r = 0;
    }

    count -= r;
    off += r;
   }

  return C_SCHEME_TRUE;
}
#endif


C_word C_random_bytes(C_word buf, C_word size)
{
  int count = C_unfix(size);
  int r = 0;
  int off = 0;

#if defined(__OpenBSD__) || defined(__FreeBSD__)
  arc4random_buf(C_data_pointer(buf), count);
#elif defined(SYS_getrandom) && defined(__NR_getrandom)
  static int use_urandom = 0;

  if(use_urandom) return random_urandom(buf, count);

  while(count > 0) {
    /* GRND_NONBLOCK = 0x0001 */
    r = syscall(SYS_getrandom, C_data_pointer(buf) + off, count, 1);

    if(r == -1) {
      if(errno == ENOSYS) {
        use_urandom = 1;
        return random_urandom(buf, count);
      }
      else if(errno != EINTR) return C_SCHEME_FALSE;
      else r = 0;
    }

    count -= r;
    off += r;
  }
#elif defined(_WIN32) && !defined(__CYGWIN__)
  typedef BOOLEAN (*func)(PVOID, ULONG);
  static func RtlGenRandom = NULL;
  
  if(RtlGenRandom == NULL) {
     HMODULE mod = LoadLibrary("advapi32.dll");
	 
     if(mod == NULL) return C_SCHEME_FALSE;
	 
     if((RtlGenRandom = (func)GetProcAddress(mod, "SystemFunction036")) == NULL)
       return C_SCHEME_FALSE;
  }
  
  if(!RtlGenRandom((PVOID)C_data_pointer(buf), (LONG)count)) 
    return C_SCHEME_FALSE;
#else 
  return random_urandom(buf, count);
#endif

  return C_SCHEME_TRUE;
}


/* WELL512 pseudo random number generator, see also:
   https://en.wikipedia.org/wiki/Well_equidistributed_long-period_linear
   http://lomont.org/Math/Papers/2008/Lomont_PRNG_2008.pdf
*/

static C_uword random_word(void)
{ 
  C_uword a, b, c, d, r; 
  a  = random_state[random_state_index]; 
  c  = random_state[(random_state_index+13)&15]; 
  b  = a^c^(a<<16)^(c<<15); 
  c  = random_state[(random_state_index+9)&15]; 
  c ^= (c>>11); 
  a  = random_state[random_state_index] = b^c;  
  d  = a^((a<<5)&0xDA442D24UL);  
  random_state_index = (random_state_index + 15)&15; 
  a  = random_state[random_state_index]; 
  random_state[random_state_index] = a^b^d^(a<<2)^(b<<18)^(c<<28); 
  r = random_state[random_state_index];
  return r;
} 


static C_uword random_uniform(C_uword bound)
{
  C_uword r, min;

  if (bound < 2) return 0;

  min = (1U + ~bound) % bound; /* = 2**<wordsize> mod bound */

  do r = random_word(); while (r < min);

  /* r is now clamped to a set whose size mod upper_bound == 0
   * the worst case (2**<wordsize-1>+1) requires ~ 2 attempts */

  return r % bound;
}
                 

C_regparm C_word C_random_fixnum(C_word n)
{ 
  C_word nf;

  if (!(n & C_FIXNUM_BIT))
    barf(C_BAD_ARGUMENT_TYPE_NO_FIXNUM_ERROR, "pseudo-random-integer", n);

  nf = C_unfix(n);

  if(nf < 0)
    barf(C_OUT_OF_RANGE_ERROR, "pseudo-random-integer", n, C_fix(0));

  return C_fix(random_uniform(nf));
} 


C_regparm C_word C_fcall
C_s_a_u_i_random_int(C_word **ptr, C_word n, C_word rn)
{
  C_uword *start, *end;

  if(C_bignum_negativep(rn))
    barf(C_OUT_OF_RANGE_ERROR, "pseudo-random-integer", rn, C_fix(0));

  int len = integer_length_abs(rn);
  C_word size = C_fix(C_BIGNUM_BITS_TO_DIGITS(len));
  C_word result = C_allocate_scratch_bignum(ptr, size, C_SCHEME_FALSE, C_SCHEME_FALSE);
  C_uword *p;
  C_uword highest_word = C_bignum_digits(rn)[C_bignum_size(rn)-1];
  start = C_bignum_digits(result);
  end = start + C_bignum_size(result);

  for(p = start; p < (end - 1); ++p) {
    *p = random_word();
    len -= sizeof(C_uword);
  }

  *p = random_uniform(highest_word);
  return C_bignum_simplify(result);
}

/*
 * C_a_i_random_real: Generate a stream of bits uniformly at random and
 * interpret it as the fractional part of the binary expansion of a
 * number in [0, 1], 0.00001010011111010100...; then round it.
 * More information on https://mumble.net/~campbell/2014/04/28/uniform-random-float
 */

static inline C_u64 random64() {
#ifdef C_SIXTY_FOUR
    return random_word();
#else
    C_u64 v = 0;
    v |= ((C_u64) random_word()) << 32;
    v |= (C_u64) random_word();
    return v;
#endif
}

#if defined(__GNUC__) && !defined(__TINYC__)
# define	clz64	__builtin_clzll		
#else
/* https://en.wikipedia.org/wiki/Find_first_set#CLZ */
static const C_uchar clz_table_4bit[16] = { 4, 3, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

int clz32(C_u32 x)
{
  int n;
  if ((x & 0xFFFF0000) == 0) {n  = 16; x <<= 16;} else {n = 0;}
  if ((x & 0xFF000000) == 0) {n +=  8; x <<=  8;}
  if ((x & 0xF0000000) == 0) {n +=  4; x <<=  4;}
  n += (int)clz_table_4bit[x >> (32-4)];
  return n;
}

int clz64(C_u64 x) 
{
    int y = clz32(x >> 32);

    if(y == 32) return y + clz32(x);

    return y;
}
#endif

C_regparm C_word C_fcall
C_a_i_random_real(C_word **ptr, C_word n) {
  int exponent = -64;
  uint64_t significand;
  unsigned shift;

  while (C_unlikely((significand = random64()) == 0)) {
    exponent -= 64;
    if (C_unlikely(exponent < -1074))
      return 0;
  }

  shift = clz64(significand);
  if (shift != 0) {
    exponent -= shift;
    significand <<= shift;
    significand |= (random64() >> (64 - shift));
  }

  significand |= 1;
  return C_flonum(ptr, ldexp((double)significand, exponent));
}

C_word C_set_random_seed(C_word buf, C_word n)
{
  int i, nsu = C_unfix(n) / sizeof(C_uword);
  int off = 0;

  for(i = 0; i < (C_RANDOM_STATE_SIZE / sizeof(C_uword)); ++i) {
    if(off >= nsu) off = 0;

    random_state[ i ] = *((C_uword *)C_data_pointer(buf) + off);
    ++off;
  }

  random_state_index = 0;
  return C_SCHEME_FALSE;
}
