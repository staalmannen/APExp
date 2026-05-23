/* config.h for diffutils on Plan9/APE */

/* Package info */
#define PACKAGE "diffutils"
#define PACKAGE_NAME "GNU diffutils"
#define PACKAGE_VERSION "3.10"
#define VERSION "3.10"

/* Standard POSIX/APE capabilities */
#define HAVE_FORK 1
#define HAVE_WORKING_FORK 1
#define HAVE_SIGACTION 1
#define HAVE_SIGINTERRUPT 1
#define HAVE_GETEUID 1
#define HAVE_GETUID 1

/* struct stat fields present on Plan9/APE */
#define HAVE_STRUCT_STAT_ST_BLKSIZE 1
#define HAVE_STRUCT_STAT_ST_RDEV 1
#undef HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC
#define HAVE_STRUCT_DIRENT_D_TYPE 1
#define HAVE_TM_GMTOFF 1

/* c-stack / sigsegv: we don't have stack overflow recovery */
#undef HAVE_GETRLIMIT
#undef HAVE_SIGALTSTACK
#undef HAVE_SIGSEGV_RECOVERY
#undef HAVE_STACKVMA
#undef HAVE_STACK_OVERFLOW_RECOVERY

/* locale */
#define LOCALEDIR "/sys/lib/ape/locale"
