/*
 * config.h for CLISP on APExp/9front -- HAND-ANSWERED.
 *
 * This is the file upstream's `src/configure' would write, written out
 * by hand instead, as `sys/src/external/perl/config.h' and bash's are.
 * Keep it in step with `mkfile.runtime', which no longer runs
 * configure at all.
 *
 * ***WHY IT IS HAND-ANSWERED, AND THE FIRST REASON IS THE WEAKER ONE.***
 *
 * The visible reason is that `configure' cannot run here: it dies with
 * `C compiler cannot create executables' under hundreds of
 * `5: Bad file descriptor', and the fd mechanism itself is CLEARED --
 * `execfd-test.sh', 11 sections, 0 failures on 9front, self-re-exec and
 * 300 forks included.  So that verdict is a configure that could not
 * write its own log, not a statement about `pcc'.
 *
 * **The stronger reason is that a WORKING configure would get this
 * machine wrong**, and in the one place where being wrong is
 * unrecoverable.  `mprotect' in `lib/ap/plan9/mman.c:44' is
 *
 *	mprotect(void *addr, size_t len, int prot) { return 0; }
 *
 * -- a stub that answers SUCCESS.  Plan 9 has no per-page protection,
 * and `p9_mmap_impl' says so outright (`(void)prot').  A configure
 * probe for a working mprotect compiles, links, runs and gets 0, so it
 * would define `HAVE_WORKING_MPROTECT'; `lispbibl.d:3013' reads that to
 * switch on the GENERATIONAL GC, whose write barrier is page
 * protection plus a SIGSEGV handler.  The barrier would never fire and
 * the collector would free live objects.  *A configure that ran
 * successfully here would have produced a Lisp that is silently wrong
 * rather than loudly broken*, which is this tree's oldest bug family --
 * a stub answering "nothing to do" when the truth is "cannot".
 *
 * So: HAVE_WORKING_MPROTECT is 0 BY MEASUREMENT OF THE SOURCE, not by
 * a test, and NO_GENERATIONAL_GC follows from it.
 *
 * ***THE MEMORY MODEL FALLS OUT OF TWO FACTS AND IS NOT A PREFERENCE.***
 *
 *   1. `p9_mmap_impl' refuses `MAP_FIXED' with a non-NULL address
 *      (`errno = EINVAL').  CLISP's SINGLEMAP_MEMORY needs each type
 *      tag mapped AT an address derived from its type code -- that is
 *      the whole mechanism -- so singlemap is not merely unused here,
 *      it is impossible.  NO_SINGLEMAP.
 *   2. TRIVIALMAP_MEMORY assumes an existing mapping can be grown in
 *      place (`lispbibl.d:3005').  `p9_mmap_impl' hands back either a
 *      `malloc' block or a fresh `segattach' segment; neither grows.
 *      NO_TRIVIALMAP.
 *
 * With both off and no `HAVE_MMAP_ANON' claimed for the model's
 * purposes, `lispbibl.d:4259' selects SPVW_BLOCKS/SPVW_MIXED -- the
 * malloc-backed configuration, which is a supported upstream mode and
 * not a degraded one.  **`HAVE_MMAP' itself stays 1 because `mmap' is
 * real** (`p9_mmap_tracked'); it is the ANON and DEVZERO spellings the
 * memory model keys on that are left undefined.
 *
 * ***HOW THE HAVE_* ANSWERS WERE OBTAINED.***  Not from memory:
 * `sys/lib/tests/apfunc-sweep.py' classifies each name as `defined'
 * (an implementation in `lib/ap'), `declared' (a header promise with
 * nothing behind it -- the one that costs a LINK), or `absent'.  Over
 * clisp's 74 function-shaped knobs it answers 40 / 4 / 30.  **The four
 * declared-only names are the point of the sweep**: `dlopen' and
 * `dlerror' are in `<dlfcn.h>' and implemented nowhere, because Plan 9
 * has no dynamic linking, so claiming them would link-fail far from
 * here.  *Its own first two runs were both wrong* -- a bad ROOT, then a
 * missing word boundary that reported `setenv' as living in
 * `fenv/fenv.c' -- and its control caught both; see that file.
 *
 * ***WHAT IS STILL GENERATED AND MUST STAY THAT WAY.***  `intparam.h'
 * and `floatparam.h' are NOT hand-answered.  Upstream builds them by
 * compiling `intparam.c'/`floatparam.c' and RUNNING them, and that is
 * the right thing here too: they measure the real compiler's integer
 * and float behaviour, and *the build host cannot answer for kencc* --
 * kencc is LLP64, so a host run would report a 64-bit `long' where this
 * target has 32.  `mkfile.runtime' builds and runs them with `pcc'.
 * **Hand-answering those two would be guessing at exactly the widths
 * this tree has been bitten by.**
 */

#ifndef APEXP_CLISP_CONFIG_H
#define APEXP_CLISP_CONFIG_H

/* ---- package identification ------------------------------------ */
#define PACKAGE_NAME "clisp"
#define PACKAGE_TARNAME "clisp"
#define PACKAGE_VERSION "2.49"
#define PACKAGE_STRING "clisp 2.49"
#define PACKAGE_BUGREPORT "http://clisp.org/"
#define PACKAGE_URL ""

/* ---- language and compiler ------------------------------------- */
/* kencc under `pcc' takes both; neither needs defining away. */
/* #undef inline */
/* #undef restrict */

/* `char' is SIGNED here.  kencc has no __CHAR_UNSIGNED__ and does not
   predefine it; intparam.c keys on the macro, so leaving it undefined
   is the correct answer rather than an omission. */
/* #undef __CHAR_UNSIGNED__ */

/* `long long' exists under pcc -- <stdint_generic.h> builds int64_t
   out of it.  This is a LANGUAGE knob, which is why the function sweep
   reported it `absent': it has no implementation to find. */
#define HAVE_LONG_LONG_INT 1

/* ---- headers ---------------------------------------------------- */
#define HAVE_UNISTD_H 1
#define HAVE_TIME_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TIMES_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_SYS_UTSNAME_H 1
#define HAVE_SYS_SYSMACROS_H 1
#define HAVE_SYS_UN_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NETINET_TCP_H 1
#define HAVE_ARPA_INET_H 1
#define HAVE_ALLOCA_H 1
#define HAVE_STDBOOL_H 1
#define HAVE_TERMIOS_H 1

/* Present as a header, with nothing behind it.  See HAVE_DLOPEN. */
#define HAVE_DLFCN_H 1

/* Absent, and all four are System V or BSD spellings APE does not use;
   <termios.h> is the one that exists. */
/* #undef HAVE_TERMIO_H */
/* #undef HAVE_SYS_TERMIO_H */
/* #undef HAVE_SGTTY_H */
/* #undef HAVE_VFORK_H */

/* The three `NEED_*' knobs ask whether a declaration has to be chased
   into a second header.  APE's <sys/ioctl.h> is self-contained and
   there is no <sys/filio.h> or <sys/ptem.h>, so all three are no. */
/* #undef NEED_SYS_IOCTL_H */
/* #undef NEED_SYS_FILIO_H */
/* #undef WINSIZE_NEED_SYS_IOCTL_H */
/* #undef WINSIZE_NEED_SYS_PTEM_H */
/* #undef IPV6_NEED_LINUX_IN6_H */

/* ---- declarations ----------------------------------------------- */
/* <unistd.h>:212. */
#define HAVE_DECL_ENVIRON 1

/* readline is present in the tree, but this port is built
   --without-readline (see mkfile.runtime), so neither variable is
   declared for clisp's purposes. */
/* #undef HAVE_DECL_RL_READLINE_NAME */
/* #undef HAVE_DECL_RL_DEPREP_TERM_FUNCTION */
/* #undef HAVE_READLINE */
/* #undef READLINE_CONST */
/* #undef READLINE_FILE_COMPLETE */

/* ---- functions libap DEFINES ------------------------------------ */
/* Every name below was reported `defined' by apfunc-sweep.py, with the
   implementing file named.  Do not add one without running it. */
#define HAVE_FCHMOD 1
#define HAVE_FSYNC 1
#define HAVE_GETCWD 1
#define HAVE_GETDTABLESIZE 1
#define HAVE_GETHOSTBYNAME 1
#define HAVE_GETHOSTNAME 1
#define HAVE_GETPAGESIZE 1
#define HAVE_GETRLIMIT 1
#define HAVE_GETRUSAGE 1
#define HAVE_GETSOCKOPT 1
#define HAVE_ICONV 1
#define HAVE_INET_NTOP 1
#define HAVE_INET_PTON 1
#define HAVE_IOCTL 1
#define HAVE_LSTAT 1
#define HAVE_MMAP 1
#define HAVE_MPROTECT 1
#define HAVE_MSYNC 1
#define HAVE_MUNMAP 1
#define HAVE_POLL 1
#define HAVE_PUTENV 1
#define HAVE_READDIR_R 1
#define HAVE_READLINK 1
#define HAVE_REALPATH 1
#define HAVE_SELECT 1
#define HAVE_SETENV 1
#define HAVE_SETITIMER 1
#define HAVE_SETPGID 1
#define HAVE_SETREGID 1
#define HAVE_SETREUID 1
#define HAVE_SETSID 1
#define HAVE_SHUTDOWN 1
#define HAVE_SIGACTION 1
#define HAVE_STRERROR 1
#define HAVE_SYSCONF 1
#define HAVE_TCGETATTR 1
#define HAVE_UALARM 1
#define HAVE_UNAME 1
#define HAVE_UNSETENV 1
#define HAVE_USLEEP 1

/* POSIX `unsetenv' returns int, which is what lib/ap/env/unsetenv.c
   does; the knob exists for the older void-returning BSD one. */
#define UNSETENV_POSIX 1

/* ---- functions that are DECLARED ONLY, so must NOT be claimed ---- */
/* Plan 9 has no dynamic linking.  <dlfcn.h> declares these and nothing
   implements them, so a package that claims them links and then fails
   to link, a long way from this file.  This is the state apfunc-sweep
   exists to separate from `absent'. */
/* #undef HAVE_DLOPEN */
/* #undef HAVE_DLERROR */
/* #undef HAVE_DLADDR */
/* #undef HAVE_DLVSYM */
/* #undef HAVE_SHM */

/* ---- functions that are absent ---------------------------------- */
/* #undef HAVE_NICE */
/* #undef HAVE_RAND_R */
/* #undef HAVE_SETRESUID */
/* #undef HAVE_SETRESGID */
/* #undef HAVE_GETRESUID */
/* #undef HAVE_GETRESGID */
/* #undef HAVE_SIGINTERRUPT */
/* #undef HAVE_VADVISE */
/* #undef HAVE_FIONREAD */
/* #undef HAVE__JMP */
/* #undef HAVE_LIBSIGSEGV */
/* #undef HAVE_MACH_VM */

/* ---- knobs read by gllib rather than by clisp's own *.d ---------- */
/*
 * ***THESE FOUR WERE MISSING FROM THE FIRST DRAFT, AND THE REASON IS A
 * GAP IN HOW THE INVENTORY WAS TAKEN.***  The 166 knobs this file
 * answers came from `config.h.in' filtered by "is this name read by
 * clisp's own `*.d'".  **gllib's `.c' files read config knobs too**,
 * and they are not `.d' files, so none of their names could ever have
 * appeared in that list.  `localcharset.c:167' then answered
 * `name not declared: HAVE_WORKING_O_NOFOLLOW'.  *A filter is also a
 * blind spot in the shape of the thing it filtered on.*
 *
 * They are swept for now rather than found one per build round: the
 * four `$GLPARTS' sources and their local headers name exactly these.
 */

/* ***MUST BE 0, AND IT IS THE STUB-ANSWERS-SUCCESS FAMILY AGAIN.***
   Note the spelling of the use: `localcharset.c:167' is
   `O_RDONLY | (HAVE_WORKING_O_NOFOLLOW ? O_NOFOLLOW : 0)' -- an
   EXPRESSION, not an `#ifdef', which is why an unanswered knob is a
   hard error here rather than a silently taken branch.
   APE's `<fcntl.h>:35' is `#define O_NOFOLLOW 0', and its own comment
   at `:30' says why: enforcing it would mean an `lstat' before the
   `open'.  So the flag is literally zero and the `open' follows
   symlinks.  **Claiming 1 would tell gnulib it has a protection that
   does nothing** -- gnulib's comment at `:159' explains that the flag
   is there to stop an attacker reading an arbitrary file through a
   planted `charset.alias' symlink. */
#define HAVE_WORKING_O_NOFOLLOW 0

/* <langinfo.h>:86 defines CODESET and libap implements nl_langinfo
   (locale/langinfo.c). */
#define HAVE_LANGINFO_CODESET 1

/* <stdio.h>:158. */
#define HAVE_DECL_GETC_UNLOCKED 1

/* gnulib's relocatable-install machinery is not used; with this unset,
   `relocate(x)' is `(x)' (localcharset.c:72). */
/* #undef ENABLE_RELOCATABLE */

/* ---- the memory model: see the header comment -------------------- */
/* mmap works; the ANON/DEVZERO spellings the memory model keys on are
   deliberately NOT claimed, so lispbibl.d:4259 selects the
   malloc-backed SPVW_BLOCKS/SPVW_MIXED configuration. */
/* #undef HAVE_MMAP_ANON */
/* #undef HAVE_MMAP_ANONYMOUS */
/* #undef HAVE_MMAP_DEVZERO */
/* #undef HAVE_MMAP_DEVZERO_SUN4_29 */

/* mprotect returns 0 and does nothing.  Claiming this would build the
   generational GC on a write barrier that never fires. */
/* #undef HAVE_WORKING_MPROTECT */

/* MAP_FIXED to an address is EINVAL here; singlemap cannot work. */
#define NO_SINGLEMAP 1
/* A mapping cannot be grown in place. */
#define NO_TRIVIALMAP 1
/* Follows from HAVE_WORKING_MPROTECT being false. */
#define NO_GENERATIONAL_GC 1

/* The macro is defined by <sys/mman.h>:27; this knob records that the
   SPELLING exists, which is a different question from whether the
   memory model may use it. */
#define MAP_ANONYMOUS MAP_ANON

/* ---- type widths ------------------------------------------------ */
/* ino_t and dev_t are `unsigned long long' as of this release's second
   ABI change -- they were 16-bit, which made two unrelated files the
   same file to anything keyed on dev+ino.  off_t is `long long'. */
#define SIZEOF_INO_T 8
#define SIZEOF_DEV_T 8
#define SIZEOF_OFF_T 8

/* struct timeval is { long long tv_sec; suseconds_t tv_usec; }.  Under
   `pcc -J' (conforming layout, this release's other ABI change) that
   is 8 + 4 + 4 of tail padding to the struct's own 8-byte alignment.
   **This is the one number here that a change to -J would move**, and
   `apeabi-probe' is what would say so. */
#define SIZEOF_STRUCT_TIMEVAL 16

#define PID_T pid_t
/* <sys/types.h>:57 -- pid_t is a real typedef, so no fallback. */
/* #undef pid_t */

/* <sys/socket.h>:32. */
#define CLISP_SOCKLEN_T socklen_t
#define CADDR_T char *

/* ---- call signatures, read from the APE headers ----------------- */
/* connect(int, void *, int) -- sys/socket.h:204.  No const, and the
   length is plain int rather than socklen_t. */
#define CONNECT_NAME_T void *
#define CONNECT_ADDRLEN_T int
#define CONNECT_CONST /* empty: APE's connect does not take const */

/* setsockopt(int, int, int, void *, int) -- sys/socket.h:208. */
#define SETSOCKOPT_ARG_T void *
#define SETSOCKOPT_OPTLEN_T int
#define SETSOCKOPT_CONST /* empty */

/* select(int, fd_set *, fd_set *, fd_set *, struct timeval *)
   -- sys/select.h:18. */
#define SELECT_WIDTH_T int
#define SELECT_SET_T fd_set
#define SELECT_CONST /* empty */

/* ioctl(int, unsigned long, void *) -- sys/ioctl.h:25.  A fixed third
   argument, not varargs, so IOCTL_DOTS stays undefined. */
#define IOCTL_REQUEST_T unsigned long
#define IOCTL_ARGUMENT_T void *
/* #undef IOCTL_DOTS */

#define RUSAGE_WHO_T int
#define ICONV_CONST const
#define INET_ADDR_CONST const
#define RET_INET_ADDR_TYPE unsigned long
#define INET_ADDR_SUFFIX /* empty */

/* ---- signals ---------------------------------------------------- */
/* libap implements POSIX sigaction with persistent handlers, so none
   of the reinstall/unblock workarounds for pre-POSIX signal() apply.
   **Claiming one that is not needed is not harmless**: a redundant
   reinstall races the handler it reinstalls. */
/* #undef SIGNAL_NEED_REINSTALL */
/* #undef SIGNAL_NEED_UNBLOCK */
/* #undef SIGNAL_NEED_UNBLOCK_OTHERS */
/* #undef SIGACTION_NEED_REINSTALL */
/* #undef SIGACTION_NEED_UNBLOCK */

/* longjmp returns normally here; amd64 setjmp/longjmp is an invariant
   of this tree (see docs/notes/invariants.md). */
#define LONGJMP_RETURNS 1

/* ---- floating point --------------------------------------------- */
/* ***THESE FIVE PAIRS ARE THE ONE GROUP I WOULD NOT TRUST WITHOUT A
   RUN.***  They ask whether an IEEE exception is actually RAISED, and
   **the fenv API is a stub on every architecture in this tree**:
   `grep -c "^TEXT"' over all six `arch/$objtype/fenv.s' is 0, so
   (spelled with the variable on purpose: the glob for it ends a C
   comment, which is how gcc found this paragraph being parsed as code)
   `fetestexcept()' reports nothing ever raised.  Answering "yes" here
   would claim an exception clisp cannot observe.  They are therefore
   all undefined, which makes clisp use its own software checks --
   the correct answer for a platform whose FP exception API does
   nothing, and *the same shape as the mprotect decision above.*
   amd64's startup does load MXCSR 0x1f80 (`main9.s:43'), so underflow
   is gradual; that is about VALUES, not about exception reporting. */
/* #undef FLOAT_DIV0_EXCEPTION */
/* #undef FLOAT_OVERFLOW_EXCEPTION */
/* #undef FLOAT_UNDERFLOW_EXCEPTION */
/* #undef FLOAT_INEXACT_EXCEPTION */
/* #undef DOUBLE_DIV0_EXCEPTION */
/* #undef DOUBLE_OVERFLOW_EXCEPTION */
/* #undef DOUBLE_UNDERFLOW_EXCEPTION */
/* #undef DOUBLE_INEXACT_EXCEPTION */

/* ---- miscellaneous ---------------------------------------------- */
/* No gettext for this port; --disable-nls. */
/* #undef ENABLE_NLS */

/* Plan 9 symbols carry no leading underscore. */
/* #undef ASM_UNDERSCORE */

/* closedir returns int. */
/* #undef VOID_CLOSEDIR */

/* struct dirent has d_name and no d_namlen -- dirent.h:40. */
/* #undef HAVE_STRUCT_DIRENT_D_NAMLEN */
/* #undef HAVE_SOCKADDR_UN_LEN */

/* TCSAFLUSH is a macro in <termios.h>:157, not a function; the sweep
   reports it absent because there is nothing to implement. */
#define HAVE_TCSAFLUSH 1

/* AF_INET is <sys/socket.h>:96 and AF_INET6 is :115, and libap has
   inet_pton/inet_ntop/getaddrinfo for both.  Macro knobs again. */
#define HAVE_IPV4 1
#define HAVE_IPV6 1

/* LC_MESSAGES is <locale.h>:53. */
#define HAVE_LC_MESSAGES 1

/* ***THE THREE `RELIABLE_*' KNOBS ARE LEFT OFF DELIBERATELY AND THIS
   IS NOT CAUTION, IT IS THE RECORD.***  `select()' on a regular file
   and `poll()' were both fixed this release, and `/dev/cons' answers
   `S_ISREG' with FD_ISTTY unset (`devreg-probe'), so what `select'
   reports for a terminal is exactly the ground that moved.  Claiming
   reliability would switch off clisp's own retry paths on the strength
   of a guess about the case least settled here. */
/* #undef HAVE_RELIABLE_SELECT */
/* #undef HAVE_RELIABLE_POLL */
/* #undef HAVE_RELIABLE_FIONREAD */

/*
 * Plan 9 filenames exclude only '/' and NUL.
 *
 * ***THE VARIABLE NAME IS NOT FREE, AND THE FIRST DRAFT CHOSE ITS
 * OWN.*** This is not a value, it is a PREDICATE spliced into a
 * function body -- `pathname.d:825' is
 *
 *	return VALID_FILENAME_CHAR || (ch=='*') || (ch=='?');
 *
 * inside `local inline bool legal_namebyte (uintB ch)'.  So the macro
 * has to be written in terms of `ch', and writing it with `c' gave
 *
 *	pathname.d:825 name not declared: c
 *	warning: pathname.d:823 set and not used: ch
 *
 * -- *and the warning is the tell*, because a parameter reported
 * unused in a one-line function that exists to test it means the test
 * never mentioned it.  **One `grep` for the macro's own name would
 * have shown the expansion site**; there is exactly one, so the
 * coupling is invisible from this file and total.
 *
 * *Everything else in this file is a type name or a constant*, which
 * is what an autoconf `config.h' macro normally is and why the hazard
 * does not recur: a sweep of the file finds this the only `#define'
 * whose body is an expression over a bare identifier.
 *
 * WHY DEFINE IT AT ALL.  Undefined, `pathname.d:828' falls to
 * `PATHNAME_UNIX's `((ch>=' ') && (ch<='~') && !(ch=='/'))' -- printable
 * ASCII -- which would reject every byte of a UTF-8 filename at or
 * above 0x80, and Plan 9 filenames are UTF-8.  `ch' is a `uintB', so
 * the two exclusions below are the whole rule.
 */
#define VALID_FILENAME_CHAR (ch != '/' && ch != '\0')

/* ELOOP exists in APE's errno table. */
#define ELOOP_VALUE ELOOP

/* vfork is not provided; fork is.
 *
 * ***AND THE COMMENT WAS RIGHT WHILE THE LINE SAID THE OPPOSITE.***
 * Autoconf's `AC_FUNC_FORK' emits `#define vfork fork' when vfork is
 * missing or broken and leaves the `#undef' in place when it WORKS, so
 * a commented-out `#undef vfork' is the "vfork exists" answer.  APExp
 * has no POSIX `vfork' -- the only hit in the tree is a syscall-table
 * adaptation in `ap/plan9/__p9_syscall.c:639' -- and `stream.d' calls
 * it three times (12879, 13118, 13272), so the build stopped with
 * `function not declared: vfork'.
 *
 * `fork' for `vfork' is upstream autoconf's own fallback and is the
 * safe direction: vfork shares the address space and requires the
 * child to exec immediately, fork does not, so replacing vfork by fork
 * can cost a copy and cannot break a correct caller.
 *
 * *This is the hand-answered-capability shape a seventh time*, and the
 * tell was the same as clisp's `VALID_FILENAME_CHAR': the prose beside
 * the macro already described the right answer.  `apfunc-sweep.py'
 * exists for exactly this -- a name this file claims that libap does
 * not define. */
#define vfork fork

/* libap has both, and they are not broken re-definitions. */
/* #undef gmtime */
/* #undef localtime */

/* ***THE FOUR ADDRESS-RANGE KNOBS ARE DELIBERATELY UNANSWERED.***
   They tell clisp where the stack, the heap, the code and the shared
   libraries live, so that the GC can recognise a pointer by its top
   bits.  Upstream obtains them by RUNNING a probe.  On Plan 9 the heap
   is partly `malloc' and partly `segattach' segments, which do not
   share a range, so **there is no single correct constant** and a
   guessed one would make the GC misclassify pointers -- the same class
   of silent wrongness as the mprotect stub.  Left undefined, clisp
   falls back to its address-range-agnostic paths. */
/* #undef CODE_ADDRESS_RANGE */
/* #undef MALLOC_ADDRESS_RANGE */
/* #undef SHLIB_ADDRESS_RANGE */
/* #undef STACK_ADDRESS_RANGE */

#endif /* APEXP_CLISP_CONFIG_H */
