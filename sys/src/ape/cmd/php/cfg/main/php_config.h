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

/*
 * ***THE PROLOGUE IS UPSTREAM'S OWN, COPIED VERBATIM FROM
 * `main/php_config.h.in:7-15', AND LEAVING IT OUT BROKE THE BUILD.***
 * These three are NOT autoconf answers -- autoheader copies them
 * through from the template -- so they are invisible to anyone
 * reading the generated file as a list of capabilities, which is how
 * this file was first written.  `Zend/zend_map_ptr.h:82' then
 * answered
 *
 *	not a function
 *	not a parameter: zend_map_ptr_reset
 *	syntax error, last name: ZEND_API
 *
 * because `ZEND_API void zend_map_ptr_reset(void);' had an undefined
 * identifier where a storage class belongs.  *Every `ZEND_API' in php
 * is that shape*, so the first file to declare anything would have
 * failed whichever it was.
 *
 * The guard is upstream's and is already right for kencc, which is
 * not `__GNUC__': all three come out empty, which is what a platform
 * with no visibility attributes and no dynamic linking wants.
 */
#if defined(__GNUC__) && __GNUC__ >= 4
# define ZEND_API __attribute__ ((visibility("default")))
# define ZEND_DLEXPORT __attribute__ ((visibility("default")))
#else
# define ZEND_API
# define ZEND_DLEXPORT
#endif

#define ZEND_DLIMPORT

/* `cfg/build-defs.h' is ours; `main/php.h' includes it unguarded. */
#define HAVE_BUILD_DEFS_H 1

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
/* HAVE_MUSTTAIL and HAVE_PRESERVE_NONE are NOT config.h's: they are
 * set by `Zend/zend_portability.h:342' from `__has_attribute', which
 * answers 0 for kencc.  Saying anything about them here would only
 * suggest this file owns a decision it does not. */
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

/* absent: ODBC (14 names), tidy, the linux/ family, the SSE headers,
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
/*
 * ***THIS HAS TO AGREE WITH `HAVE_GETHOSTBYNAME_R' ABOVE, AND IT DID
 * NOT.***  `main/network.c' defines its `gethostname_re' helper in one
 * of three arms -- `HAVE_FUNC_GETHOSTBYNAME_R_6', `_5' and `_3' -- and
 * calls it whenever `HAVE_GETHOSTBYNAME_R' is set, so saying yes to the
 * capability and no to every arity gave
 *
 *	network.c:1423 function not declared: gethostname_re
 *	network.c:1423 incompatible types: "IND STRUCT hostent" and "INT"
 *
 * the second line being the implicit `int' return, which is the loud
 * half of the undeclared-function rule.  libap's is the glibc six-
 * argument form -- `netdb.h:131', `network/gethostbyname_r.c' -- so
 * this is the arity, and it is 1.
 */
#define HAVE_FUNC_GETHOSTBYNAME_R_6 1

/*
 * ***THE FOUR EXTENSIONS ADDED FOR PHORONIX.***  Each name is the one
 * its own `config.m4' AC_DEFINEs -- `libxml/config0.m4:12',
 * `dom/config.m4:9', `simplexml/config.m4:9', `zlib/config0.m4:8' --
 * read out of the files rather than recalled, since an extension that
 * compiles with its HAVE_ unanswered is an extension whose every
 * `#ifdef'-guarded function quietly vanishes.
 *
 * `HAVE_ZLIB' is what satisfies Phoronix's "MISSING ZIP": its check is
 * `extension_loaded('zip') || extension_loaded('zlib')'.
 */
#define HAVE_LIBXML 1
#define HAVE_DOM 1
#define HAVE_SIMPLEXML 1
#define HAVE_ZLIB 1

/*
 * ***THE EIGHT OPTIONAL EXTENSIONS, AND WHY EVERY ONE OF THESE LINES
 * HAD TO BE WRITTEN BEFORE ANYTHING COULD BE MEASURED.***
 *
 * Phoronix's `system-info' lists nine OPTIONAL extensions once the
 * four required ones are in.  Eight of them have a library in this
 * tree already -- `lib/bz2', `lib/readline'+`lib/history',
 * `lib/libressl', `lib/curl', `lib/sqlite', `lib/zip' -- and two need
 * no library at all.  GD was the ninth and needed a libgd this tree
 * did not have at the time; **it does now** (`lib/gd', 2.3.3), and
 * `ext/gd' is answered further down.
 *
 * ***FIVE OF THE EIGHT "COMPILED CLEAN" BEFORE A SINGLE LINE BELOW
 * EXISTED, AND THAT WAS AN EMPTY TRANSLATION UNIT EACH TIME.***  Every
 * one of these extensions wraps its whole body in `#ifdef HAVE_<X>',
 * so the mirror compiled `ext/posix/posix.c', `ext/bz2/bz2.c',
 * `ext/sockets/sockets.c', `ext/openssl/openssl.c' and
 * `ext/readline/readline.c' to *nothing at all* and reported 0 errors
 * for each.  *A check that cannot fail is not a check*, and this one
 * could only pass.  **The discriminator that works is the module
 * entry**: `6c -S' on the extension's main file either mentions
 * `<ext>_module_entry' or it does not, and that told the five empty
 * ones from the four real ones in a single command.
 * ***AND THE FIRST DISCRIMINATOR TRIED WAS NO BETTER***: counting
 * `TEXT' symbols gave 363-505 for everything, empty units included,
 * because kencc emits the `static inline's out of php's headers that
 * gcc at -O2 discards -- so the floor is ~360 and the signal is lost
 * in it.
 *
 * Every function answer below is `apfunc-sweep.py' with the library's
 * own tree as a `--root', not recall; every macro and struct answer is
 * a compile against the real APE headers.  The two that are neither --
 * `HAVE_ERASE_EMPTY_LINE' and `HAVE_STRUCT_SIGINFO_T' -- say so.
 */

/* ---- ext/posix.  `getsid' and `eaccess' are the only two absent. -- */
#define HAVE_POSIX 1
#define HAVE_CTERMID 1
#define HAVE_FPATHCONF 1
#define HAVE_PATHCONF 1
#define HAVE_GETGROUPS 1
#define HAVE_GETLOGIN 1
#define HAVE_GETPGID 1
#define HAVE_GETRLIMIT 1
#define HAVE_INITGROUPS 1
#define HAVE_MKFIFO 1
#define HAVE_MKNOD 1
#define HAVE_SETEGID 1
#define HAVE_SETEUID 1
#define HAVE_SETRLIMIT 1
#define HAVE_SETSID 1
/* `makedev' comes from musl's <sys/sysmacros.h>; compiled, not grepped. */
#define HAVE_MAKEDEV 1
/* #undef HAVE_EACCESS */
/* #undef HAVE_GETSID */
/* #undef HAVE_TTYNAME_R */

/*
 * ---- ext/pcntl.  `fork', `sigaction', `sigprocmask', `sigwaitinfo',
 * `sigtimedwait', `wait3' and `wait4' are all in libap; `waitid',
 * `getpriority', `setpriority', `sched_getcpu', `unshare', `forkx' and
 * `getcpuid' are not.
 *
 * **`WIFCONTINUED' exists and `WCONTINUED' does not**, which looks
 * like a typo and is not: they are separate `#ifdef's in `pcntl.c' and
 * a compile against `<sys/wait.h>' answers them separately.
 * `HAVE_STRUCT_SIGINFO_T' is a TYPE question, so it is a compile of
 * `siginfo_t si;' rather than anything the sweep can see.
 */
#define HAVE_SIGWAITINFO 1
#define HAVE_STRUCT_SIGINFO_T 1
#define HAVE_WAIT3 1
#define HAVE_WAIT4 1
#define HAVE_WIFCONTINUED 1
/* #undef HAVE_WCONTINUED */
/* #undef HAVE_DECL_WCONTINUED */
/* #undef HAVE_WAITID */
/* #undef HAVE_WAIT6 */
/* #undef HAVE_GETPRIORITY */
/* #undef HAVE_SETPRIORITY */
/* #undef HAVE_SCHED_GETCPU */
/* #undef HAVE_SCHED_SETAFFINITY */
/* #undef HAVE_UNSHARE */
/* #undef HAVE_FORKX */
/* #undef HAVE_GETCPUID */
/* #undef HAVE_RFORK */
/* #undef HAVE_PTHREAD_SET_QOS_CLASS_SELF_NP */
/* #undef HAVE_LINUX_RAW_SYSCALL_WAITID */
/* #undef HAVE_LINUX_RAW_SYSCALL_PIDFD_OPEN */

/* ---- ext/bz2, against `lib/bz2'. ---------------------------------- */
#define HAVE_BZ2 1

/*
 * ---- ext/readline, against `lib/readline' (GNU readline 8.3) and
 * `lib/history'.  **Not libedit**, which this tree also has: the two
 * are mutually exclusive in `readline.c' and GNU readline is the one
 * built.  `rl_erase_empty_line' is a VARIABLE, so the sweep cannot see
 * it -- `readline.c:250' defines it and `readline.h:648' declares it.
 */
#define HAVE_LIBREADLINE 1
#define HAVE_HISTORY_LIST 1
#define HAVE_RL_CALLBACK_READ_CHAR 1
#define HAVE_RL_ON_NEW_LINE 1
#define HAVE_RL_COMPLETION_MATCHES 1
#define HAVE_ERASE_EMPTY_LINE 1
/* #undef HAVE_LIBEDIT */

/*
 * ---- ext/openssl, against `lib/libressl' (LibreSSL 4.3.2).
 *
 * **LibreSSL announces `OPENSSL_VERSION_NUMBER 0x20000000L'**
 * (`opensslv.h:13'), so php takes its *v1* backend; all six files
 * compile.  The TLS feature macros -- `HAVE_TLS13', `HAVE_SEC_LEVEL',
 * `HAVE_EVP_PKEY_EC' and the rest -- are NOT answered here and must
 * not be: `xp_ssl.c:70-146' and `php_openssl_backend.h:136' compute
 * them from the version macros themselves.
 *
 * `RAND_egd' and `OSSL_set_max_threads' are both absent from LibreSSL,
 * which is the sweep's answer and is also what the two `#undef's below
 * mean: no EGD, and no argon2 (that one wants OpenSSL 3.2).
 */
#define HAVE_OPENSSL_EXT 1
/* #undef HAVE_RAND_EGD */
/* #undef HAVE_OPENSSL_ARGON2 */
/* #undef USE_OPENSSL_SYSTEM_CIPHERS */
/* #undef LOAD_OPENSSL_LEGACY_PROVIDER */

/* ---- ext/curl, against `lib/curl'. -------------------------------- */
#define HAVE_CURL 1

/*
 * ---- ext/sqlite3, against `lib/sqlite' (3.53.4).
 *
 * **`SQLITE_OMIT_LOAD_EXTENSION' is the Plan 9 answer and not a
 * preference**: `sqlite3_load_extension' is dlopen, which does not
 * exist here, so the alternative is a link error rather than a
 * missing feature.
 */
#define HAVE_SQLITE3 1
#define HAVE_SQLITE3_ERRSTR 1
#define HAVE_SQLITE3_EXPANDED_SQL 1
#define SQLITE_OMIT_LOAD_EXTENSION 1

/*
 * ---- ext/zip, against `lib/zip' (libzip 1.11.4).  Each of the five
 * feature names is a `PHP_CHECK_LIBRARY' on one libzip function, and
 * 1.11.4 is newer than all five, which the sweep confirms by naming
 * the file each is defined in.
 */
#define HAVE_ZIP 1
#define HAVE_LIBZIP_VERSION 1
#define HAVE_ENCRYPTION 1
#define HAVE_SET_MTIME 1
#define HAVE_PROGRESS_CALLBACK 1
#define HAVE_CANCEL_CALLBACK 1
#define HAVE_METHOD_SUPPORTED 1

/*
 * ---- ext/gd, against the EXTERNAL libgd (`lib/gd', 2.3.3) --------
 *
 * **`HAVE_GD_BUNDLED' is deliberately NOT defined.**  php ships its
 * own copy of libgd under `ext/gd/libgd' and would build 40 objects
 * from it; this tree has a real `libgd.a' now, so php takes the
 * external arm and builds TWO -- `gd.c' and `gd_compat.c'.  That
 * avoids a second, divergent libgd in the tree, and php's bundled
 * copy is the worse one to keep: it announces `GD_VERSION_STRING
 * "2.0.35"' while carrying AVIF, WebP, BMP and the interpolation
 * code, none of which existed in 2.0.35.
 *
 * ***`HAVE_LIBGD' IS THE GATE, NOT `HAVE_GD'.***  `php_gd.h:24' is
 * `#if defined(HAVE_LIBGD) || defined(HAVE_GD_BUNDLED)', so with
 * neither name the file declares `phpext_gd_ptr NULL' and `gd.c'
 * compiles to nothing -- the empty-translation-unit shape that cost
 * a measurement on five extensions already.
 *
 * ***AND THE FORMAT ANSWERS ARE WHERE A WORKING configure WOULD GET
 * THIS WRONG, FOR THE FOURTH TIME.***  php probes the installed
 * libgd by LINKING `gdImageCreateFromJpeg', `...Avif', `...Webp' and
 * `...Xpm'.  **All four link.**  Upstream libgd compiles
 * `gd_jpeg.c', `gd_avif.c', `gd_webp.c' and `gdxpm.c' even with no
 * such library and gives each a stub -- `gd_jpeg.c:1209's
 * `_noJpegError()' calls `gd_error("JPEG image support has been
 * disabled")' and returns.  *So the probe succeeds and the
 * capability is absent*, which is `HAVE_WORKING_MPROTECT' and
 * `fsync' and `statvfs' in their exact shape.
 *
 * They are answered NO, and the difference is visible to scripts
 * rather than academic: with them yes php registers `imagejpeg()'
 * and sets the bit in `imagetypes()', so `function_exists()' and
 * `imagetypes() & IMG_JPG' -- the two documented ways to ask what gd
 * can do -- would both LIE, and the failure would arrive later as a
 * false return from a function that should not exist.
 *
 * The three yes answers are link-level facts, checked with `nm' over
 * the archive this tree builds rather than assumed:
 * `gdImageCreateFromPng', `gdVersionString' and
 * `gdImageGetInterpolationMethod' are all defined.
 * **`HAVE_GD_FREETYPE' is a genuine link-level NO**: php probes
 * `gdFontCacheShutdown', which exists only inside gdft.c's
 * `HAVE_LIBFREETYPE' arm, so it is absent from the archive -- the
 * one format-ish answer where the probe and the truth agree.
 */
#define HAVE_LIBGD 1
#define HAVE_GD_PNG 1
#define HAVE_GD_LIBVERSION 1
#define HAVE_GD_GET_INTERPOLATION 1
/* #undef HAVE_GD_BUNDLED */
/* #undef HAVE_GD_JPG */
/* #undef HAVE_GD_AVIF */
/* #undef HAVE_GD_WEBP */
/* #undef HAVE_GD_XPM */
/* #undef HAVE_GD_FREETYPE */

/*
 * ---- ext/sockets is NOT built, and the reason is in libap rather
 * than in php.  `<sys/socket.h>' has no `struct cmsghdr', no
 * `CMSG_DATA'/`CMSG_LEN'/`CMSG_SPACE', no `MSG_TRUNC'/`MSG_CTRUNC',
 * and `struct msghdr' has no `msg_flags'; `sendmsg' is a stub
 * returning ENOSYS and **`recvmsg' is declared by the header and
 * defined nowhere**, which `apfunc-sweep' reports as `declared' -- the
 * middle state that link-fails far from the claim.
 *
 * Phoronix wants sockets only "when running the Phoromatic Server",
 * so it is the least valuable of the nine and the only one needing a
 * public struct to change.  `docs/notes/php.md' has what it would
 * take.
 */
/* #undef HAVE_SOCKETS */
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
/*
 * ***`PHP_OS_FAMILY' IS NOT OURS TO ANSWER, AND DEFINING IT HERE WAS
 * A COLLISION.***  `main/php.h:38-51' computes it from the platform
 * macros and its chain ends in an unconditional
 * `#else # define PHP_OS_FAMILY "Unknown"', so php.h would have
 * redefined this one with a different string.  `cfghdr-sweep.py'
 * reported it as a name the template never asks about, which is what
 * an invented macro looks like from outside.
 *
 * Plan 9 defines none of `BSD', `__linux__', `__sun__' or the rest,
 * so php answers "Unknown" -- which is simply true.
 */
#define DEFAULT_SHORT_OPEN_TAG "1"
#define PHP_SIGCHILD 0
#define ZEND_DEBUG 0
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

/*
 * ***THE EPILOGUE IS UPSTREAM'S TOO, AND LEAVING IT OUT WAS THE SAME
 * MISTAKE TWICE.***  `main/php_config.h.in:2225-2236' ends with four
 * `#include's, and they are how EVERY translation unit in php comes
 * to see `<string.h>': `Zend/zend_operators.h' does not include it,
 * and neither does anything else `Zend/Optimizer/block_pass.c'
 * reaches -- only `main/php.h:208', which a Zend file never gets to.
 *
 * Without them `zend_operators.h:308' answered
 * `incompatible types: "IND VOID" and "INT" for op "RETURN"' on
 * `return mempcpy(dest, src, n);' -- an undeclared function returning
 * implicit `int' where a `void *' belongs.  **`memcpy', `memcmp' and
 * `strncasecmp' were undeclared in the same translation unit** and
 * said nothing, because `int' converts to `size_t' without
 * complaint: *the pointer was the only one loud enough to notice.*
 *
 * Verbatim, guards included.
 */

#include <stdlib.h>

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif

#ifdef HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif

#include <string.h>

#endif /* PHP_CONFIG_H */
