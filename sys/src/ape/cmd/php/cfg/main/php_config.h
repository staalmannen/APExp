/*
 * php_config.h -- HAND-ANSWERED for APExp.  php 8.5.12.
 *
 * ***THIS IS NOT CONFIGURE OUTPUT AND MUST NOT BE REGENERATED.***  The
 * reason is clisp's, and php gives it twice over: a working configure
 * would get this machine WRONG.  `mprotect' and `mremap' are both
 * present, both link, both return success -- and both must be answered
 * NO here, because what they do is not what the caller is told.  See
 * "The two that lie" below.  A probe that compiles and links cannot
 * tell the difference; a person reading the implementation can.
 *
 * HOW IT WAS DERIVED, which is not the same as generated.  php's own
 * `configure' was run on the build host to get the INVENTORY of
 * questions -- 2239 lines, 217 defines -- and then every answer was
 * given here:
 *
 *   headers    resolved mechanically against `sys/include/ape' and
 *              `amd64/include/ape'.  39 of 91 exist.
 *   functions  from `sys/lib/tests/apfunc-sweep.py', which separates
 *              DEFINED from DECLARED-ONLY -- the middle state is the
 *              one that link-fails far from the claim.
 *   the rest   by hand, with the reasoning beside anything surprising.
 *
 * `docs/notes/php.md' is the long form.
 *
 * ***AND THE MECHANICAL ANSWER IS WRONG AT LEAST ONCE: `HAVE_DLFCN_H'.***
 * APE ships the header and `apfunc-sweep' reports `dlopen' and
 * `dlerror' as declared-only, so the file exists and the capability
 * does not.  It is answered no below.  *Every rule here has an
 * exception and the exceptions are what this file is for.*
 */

#ifndef PHP_CONFIG_H
#define PHP_CONFIG_H

/* ------------------------------------------------------------------ *
 * Type sizes.  **kencc amd64 is LLP64**: `long' is FOUR bytes while
 * pointers and `size_t' are eight.  php survives that because
 * `Zend/zend_long.h' picks `zend_long' from `__x86_64__' and not from
 * SIZEOF_LONG -- see the mkfile, which defines it on the command line.
 * ------------------------------------------------------------------ */
#define SIZEOF_INT 4
#define SIZEOF_LONG 4
#define SIZEOF_LONG_LONG 8
#define SIZEOF_SIZE_T 8
#define SIZEOF_OFF_T 8			/* <sys/types.h>: long long */

#define ZEND_MM_ALIGNMENT (size_t)8
#define ZEND_MM_ALIGNMENT_LOG2 (size_t)3
#define ZEND_MM_NEED_EIGHT_BYTE_REALIGNMENT 0

/* ------------------------------------------------------------------ *
 * Compiler features: kencc has none of them, and that is load-bearing
 * rather than unfortunate.  `HAVE_GCC_GLOBAL_REGS' being absent is
 * what leaves `ZEND_VM_KIND' at `ZEND_VM_KIND_CALL'
 * (`zend_vm_opcodes.h:40'), which is the dispatch the shipped
 * `zend_vm_execute.h' can serve without a bootstrap php to regenerate
 * it.  `HAVE_ASM_GOTO' being absent is what keeps
 * `ZEND_USE_ASM_ARITHMETIC' at 0 (`zend_operators.h:547'), which is
 * what keeps four `__x86_64__' arms in that file from reaching GCC
 * inline assembly.
 * ------------------------------------------------------------------ */
/* #undef HAVE_ASM_GOTO */
/* #undef HAVE_GCC_GLOBAL_REGS */
/* #undef HAVE_MUSTTAIL */
/* #undef HAVE_PRESERVE_NONE */
/* #undef HAVE_ALIGNOF */
/* #undef HAVE_ATTRIBUTE_ALIGNED */
/* #undef HAVE_FUNC_ATTRIBUTE_IFUNC */
/* #undef HAVE_FUNC_ATTRIBUTE_TARGET */
/* #undef HAVE_CPUID_COUNT */
/* #undef HAVE_FPU_INLINE_ASM_X86 */
/* #undef HAVE__FPU_SETCW */
/* #undef PHP_HAVE_AVX512_SUPPORTS */
/* #undef PHP_HAVE_AVX512_VBMI_SUPPORTS */
/* #undef PHP_HAVE_BUILTIN_CLZ */
/* #undef PHP_HAVE_BUILTIN_CLZL */
/* #undef PHP_HAVE_BUILTIN_CLZLL */
/* #undef PHP_HAVE_BUILTIN_CPU_INIT */
/* #undef PHP_HAVE_BUILTIN_CPU_SUPPORTS */
/* #undef PHP_HAVE_BUILTIN_CTZL */
/* #undef PHP_HAVE_BUILTIN_CTZLL */
/* #undef PHP_HAVE_BUILTIN_EXPECT */
/* #undef PHP_HAVE_BUILTIN_FRAME_ADDRESS */
/* #undef PHP_HAVE_BUILTIN_SADDL_OVERFLOW */
/* #undef PHP_HAVE_BUILTIN_SADDLL_OVERFLOW */
/* #undef PHP_HAVE_BUILTIN_SMULL_OVERFLOW */
/* #undef PHP_HAVE_BUILTIN_SMULLL_OVERFLOW */
/* #undef PHP_HAVE_BUILTIN_SSUBL_OVERFLOW */
/* #undef PHP_HAVE_BUILTIN_SSUBLL_OVERFLOW */
/* #undef PHP_HAVE_BUILTIN_UNREACHABLE */
/* #undef PHP_HAVE_BUILTIN_USUB_OVERFLOW */

/* ------------------------------------------------------------------ *
 * Headers.  Mechanical: these are the 39 that exist.
 * ------------------------------------------------------------------ */
#define STDC_HEADERS 1
#define HAVE_ALLOCA_H 1
#define HAVE_ARPA_INET_H 1
#define HAVE_ARPA_NAMESER_H 1
#define HAVE_DIRENT_H 1
#define HAVE_FCNTL_H 1
#define HAVE_GRP_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_LANGINFO_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_NET_IF_H 1
#define HAVE_POLL_H 1
#define HAVE_PWD_H 1
#define HAVE_RESOLV_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_STRING_H 1
#define HAVE_SYSEXITS_H 1
#define HAVE_SYSLOG_H 1
#define HAVE_SYS_FILE_H 1
#define HAVE_SYS_IOCTL_H 1
#define HAVE_SYS_MMAN_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_RESOURCE_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_STATVFS_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_SYSMACROS_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_UIO_H 1
#define HAVE_SYS_UTSNAME_H 1
#define HAVE_SYS_WAIT_H 1
#define HAVE_UNISTD_H 1
#define HAVE_UTIME_H 1
#define HAVE_WCHAR_H 1
#define MAJOR_IN_SYSMACROS 1

/*
 * ***`HAVE_DLFCN_H' IS THE EXCEPTION, AND IT IS ANSWERED NO.***  The
 * header exists; `dlopen' and `dlerror' are DECLARED-ONLY, which is
 * the state `apfunc-sweep' exists to find.  Claiming it would cost a
 * link error a long way from this line.  `HAVE_LIBDL' goes with it,
 * and Plan 9 has no dynamic linking at all -- the same reason perl
 * here has no XS extensions.
 */
/* #undef HAVE_DLFCN_H */
/* #undef HAVE_LIBDL */

/* absent: ODBC (14 names), tidy, linux/*, the SSE intrinsic headers,
 * Windows, crypt.h, sys/ipc.h, sys/mount.h, sys/statfs.h, sys/vfs.h,
 * pty.h, ieeefp.h, cpuid.h, io.h, dns.h, libproc.h, valgrind. */
/* #undef HAVE_CRYPT_H */
/* #undef HAVE_IMMINTRIN_H */
/* #undef HAVE_TMMINTRIN_H */
/* #undef HAVE_NMMINTRIN_H */
/* #undef HAVE_WMMINTRIN_H */
/* #undef HAVE_SYS_IPC_H */
/* #undef HAVE_SYS_MOUNT_H */
/* #undef HAVE_SYS_STATFS_H */
/* #undef HAVE_SYS_VFS_H */
/* #undef HAVE_SYS_POLL_H */
/* #undef HAVE_SYS_LOADAVG_H */
/* #undef HAVE_SYS_ACL_H */
/* #undef HAVE_PTY_H */
/* #undef HAVE_IEEEFP_H */
/* #undef HAVE_CPUID_H */

/* ------------------------------------------------------------------ *
 * The two that LIE, and they are the whole reason this file is
 * hand-written.
 * ------------------------------------------------------------------ */
/*
 * `mprotect' is `return 0' -- `lib/ap/plan9/mman.c:44', a stub
 * answering SUCCESS.  Nothing it is asked to protect is protected.
 * This is the macro that cost clisp a round: there it switches on a
 * generational GC whose write barrier is page protection plus SIGSEGV,
 * so the barrier never fires and the collector frees live objects.
 */
/* #undef HAVE_MPROTECT */

/*
 * ***`mremap' IS WORSE, BECAUSE THE CALLER IS TOLD IT SUCCEEDED AT
 * SOMETHING ELSE.***  APExp's `mremap' allocates new memory and copies
 * -- it MOVES.  `Zend/zend_alloc.c's `zend_mm_chunk_extend' calls
 * `mremap(addr, old, new, 0)' with no MREMAP_MAYMOVE, precisely
 * because it needs the chunk to stay put, and returns 1 on anything
 * that is not MAP_FAILED.  So Zend would record a chunk as extended in
 * place while the memory had moved: *not a failure, a silently wrong
 * heap*.
 */
/* #undef HAVE_MREMAP */

/*
 * `mmap' and `munmap' are real enough for php, and that was measured
 * rather than assumed -- `sys/lib/tests/mmaptrim-probe.c'.  Zend's
 * allocator maps over-sized and trims head and tail to land a
 * 2MB-aligned chunk; both trims survive, and `SEG_THRESHOLD' is 64MB
 * so a 2MB chunk costs no Plan 9 segment slot (there are five).
 */
#define HAVE_MMAP 1

/*
 * opcache is MANDATORY in 8.5 -- there is no `--disable-opcache' --
 * but it only has to COMPILE, since `opcache.enable_cli' is off by
 * default and the accelerator never starts.  All three of its shared
 * memory backends are answered no, and that is deliberate: `shm_open'
 * here is a file in `/tmp' (`plan9/mman.c') over a per-process `mmap',
 * so it would answer a probe YES and share nothing.  The
 * HAVE_WORKING_MPROTECT shape a third time.
 */
/* #undef HAVE_SHM_IPC */
/* #undef HAVE_SHM_MMAP_ANON */
/* #undef HAVE_SHM_MMAP_POSIX */

/* ------------------------------------------------------------------ *
 * Functions: `apfunc-sweep.py' says DEFINED for each of these.
 * ------------------------------------------------------------------ */
#define HAVE_ALLOCA 1
#define HAVE_ALPHASORT 1
#define HAVE_ARC4RANDOM_BUF 1
#define HAVE_ASCTIME_R 1
#define HAVE_ASPRINTF 1
#define HAVE_ATOLL 1
#define HAVE_CHROOT 1
#define HAVE_CTIME_R 1
#define HAVE_DN_EXPAND 1
#define HAVE_DN_SKIPNAME 1
#define HAVE_FLOCK 1
#define HAVE_FNMATCH 1
#define HAVE_FORK 1
#define HAVE_GAI_STRERROR 1
#define HAVE_GETADDRINFO 1
#define HAVE_GETCWD 1
#define HAVE_GETGRNAM_R 1
#define HAVE_GETHOSTBYNAME_R 1
#define HAVE_GETHOSTNAME 1
#define HAVE_GETOPT 1
#define HAVE_GETPID 1
#define HAVE_GETPROTOBYNAME 1
#define HAVE_GETPROTOBYNUMBER 1
#define HAVE_GETPWNAM_R 1
#define HAVE_GETPWUID_R 1
#define HAVE_GETRANDOM 1
#define HAVE_GETRUSAGE 1
#define HAVE_GETSERVBYNAME 1
#define HAVE_GETSERVBYPORT 1
#define HAVE_GETTIMEOFDAY 1
#define HAVE_GLOB 1
#define HAVE_GMTIME_R 1
#define HAVE_KILL 1
#define HAVE_LOCALTIME_R 1
#define HAVE_MEMMEM 1
#define HAVE_MEMPCPY 1
#define HAVE_MEMRCHR 1
#define HAVE_MKSTEMP 1
#define HAVE_NANOSLEEP 1
#define HAVE_NL_LANGINFO 1
#define HAVE_POLL 1
#define HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP 1
#define HAVE_PUTENV 1
#define HAVE_REALLOCARRAY 1
#define HAVE_RES_SEARCH 1
#define HAVE_SCANDIR 1
#define HAVE_SETENV 1
#define HAVE_SETITIMER 1
#define HAVE_SHUTDOWN 1
#define HAVE_SIGACTION 1
#define HAVE_SIGPROCMASK 1
#define HAVE_SOCKETPAIR 1
#define HAVE_STATVFS 1
#define HAVE_STRCASECMP 1
#define HAVE_STRERROR_R 1
#define HAVE_STRLCAT 1
#define HAVE_STRLCPY 1
#define HAVE_STRNLEN 1
#define HAVE_STRPTIME 1
#define HAVE_STRTOK_R 1
#define HAVE_STRTOLL 1
#define HAVE_SYMLINK 1
#define HAVE_TZSET 1
#define HAVE_UNSETENV 1
#define HAVE_USLEEP 1
#define HAVE_UTIME 1
#define HAVE_VASPRINTF 1
#define HAVE_DECL_STRERROR_R 1
#define HAVE_DECL_STRPTIME 1

/*
 * ***`STRERROR_R_CHAR_P' IS THE ONE TO GET RIGHT AND IT IS NOT SET.***
 * glibc's `strerror_r' returns `char *'; APE's is POSIX's, returning
 * `int' (`<string.h>:45', `string/strerror_r.c:4').  Defining it the
 * way the host config does would have php use an `int' as a pointer.
 * *Copying the Linux answer here is not a small error.*
 */
/* #undef STRERROR_R_CHAR_P */

/*
 * Absent, each confirmed by the sweep rather than assumed.
 * `explicit_bzero' is absent and php ships its own
 * (`main/explicit_bzero.c', already in the object list); `fdatasync'
 * falls back to `fsync'.  `copy_file_range' and `memfd_create' are
 * DECLARED-ONLY, which is the state that link-fails, so they are no.
 */
/* #undef HAVE_COPY_FILE_RANGE */
/* #undef HAVE_EXPLICIT_BZERO */
/* #undef HAVE_FDATASYNC */
/* #undef HAVE_FOPENCOOKIE */
/* #undef COOKIE_SEEKER_USES_OFF64_T */
/* #undef HAVE_FTOK */
/* #undef HAVE_FUNC_GETHOSTBYNAME_R_6 */
/* #undef HAVE_GETIFADDRS */
/* #undef HAVE_GETLOADAVG */
/* #undef HAVE_GETTID */
/* #undef HAVE_GETWD */
/* #undef HAVE_LCHOWN */
/* #undef HAVE_MEMFD_CREATE */
/* #undef HAVE_NICE */
/* #undef HAVE_OPENPTY */
/* #undef HAVE_PRCTL */
/* #undef HAVE_PTHREAD_ATTR_GETSTACK */
/* #undef HAVE_PTHREAD_GETATTR_NP */
/* #undef HAVE_RES_NSEARCH */
/* #undef HAVE_STATFS */
/* #undef ENABLE_CHROOT_FUNC */

/* ------------------------------------------------------------------ *
 * Types and struct members, each read out of the APE header.
 * ------------------------------------------------------------------ */
#define HAVE_SOCKLEN_T 1		/* <sys/socket.h>:30 */
#define HAVE_STRUCT_FLOCK 1
#define HAVE_STRUCT_SOCKADDR_STORAGE 1
#define HAVE_STRUCT_STAT_ST_BLKSIZE 1	/* <sys/stat.h>:24 */
#define HAVE_STRUCT_STAT_ST_BLOCKS 1	/* <sys/stat.h>:25 */
#define HAVE_STRUCT_STAT_ST_RDEV 1
#define HAVE_ST_BLOCKS 1
#define HAVE_STRUCT_TM_TM_GMTOFF 1	/* <time.h>:68 */
#define HAVE_STRUCT_TM_TM_ZONE 1	/* <time.h>:69 */
#define HAVE_TM_ZONE 1

/*
 * `AF_INET6' and `struct sockaddr_in6' both exist
 * (`<sys/socket.h>:115', `<netinet/in.h>:193'), so this could be yes.
 * **It is no for the first build and that is a choice, not a finding**:
 * nothing in this tree has ever exercised IPv6 through APE's socket
 * layer, and a port's first build is the wrong place to open a path
 * nobody has measured.  Revisit with a test, not with an edit.
 */
/* #undef HAVE_IPV6 */

/* ------------------------------------------------------------------ *
 * php's own switches.
 * ------------------------------------------------------------------ */
#define PHP_OS "Plan9"
#define PHP_UNAME "Plan9"
#define PHP_BUILD_SYSTEM "Plan9 APExp"
#define PHP_OS_FAMILY "BSD"
#define DEFAULT_SHORT_OPEN_TAG "1"
#define PHP_SIGCHILD 0
#define ZEND_DEBUG 0
#define ZEND_DLIMPORT
#define PHP_WRITE_STDOUT 1
#define PHP_USE_PHP_CRYPT_R 1		/* no crypt.h; php bundles four */
#define HAVE_BUNDLED_PCRE 1
#define PCRE2_CODE_UNIT_WIDTH 8
#define HAVE_LEXBOR 1
#define URI_ENABLE_ANSI 1
#define URI_NO_UNICODE 1
#define PHP_CAN_SUPPORT_PROC_OPEN 1

/*
 * ***THE POINT OF THE LAST ROUND.***  `zend_fibers.c' is unconditional
 * because `Fiber' is a language class, and it needs either
 * boost.context's GAS assembly or this.  libap has `<ucontext.h>' now
 * (`lib/ap/arch/amd64/ucontext.s' and `makecontext.c'), measured by
 * `sys/lib/tests/ucontext-test.c' at 0 failures on the machine.
 */
#define ZEND_FIBER_UCONTEXT 1

/*
 * `zend_call_stack.c' finds the stack bounds through
 * `pthread_getattr_np', `pthread_attr_getstack', `/proc', `sysctl' or
 * a Windows call, and APExp has NONE of them.  Answering yes would
 * leave `zend_call_stack_get' returning false at run time, which is
 * the same outcome by a longer route; answering no says so at compile
 * time.  **The cost is real and is recorded rather than hidden**: deep
 * PHP recursion faults instead of raising an error.
 */
/* #undef ZEND_CHECK_STACK_LIMIT */
/* #undef ZEND_MAX_EXECUTION_TIMERS */
/* #undef HAVE_VALGRIND */
/* #undef HAVE_DTRACE */
/* #undef HAVE_HUGE_CODE_PAGES */

#endif /* PHP_CONFIG_H */
