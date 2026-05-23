/* config.h for GNU patch on Plan9/APE */

/* Package info */
#define PACKAGE "patch"
#define PACKAGE_NAME "GNU patch"
#define PACKAGE_VERSION "2.7.6"
#define VERSION "2.7.6"

/* Standard POSIX/APE capabilities */
#define HAVE_FORK 1
#define HAVE_WORKING_FORK 1
#define HAVE_SIGACTION 1
#define HAVE_SIGFILLSET 1
#define HAVE_GETEUID 1
#define HAVE_GETUID 1
#undef HAVE_SETMODE_DOS

/* c-stack: no stack overflow recovery on Plan9 */
#undef HAVE_GETRLIMIT
#undef HAVE_SIGALTSTACK
#undef HAVE_SIGSEGV_RECOVERY
#undef HAVE_STACKVMA
#undef HAVE_STACK_OVERFLOW_RECOVERY

/* Enable merge mode (passed via -DENABLE_MERGE in CFLAGS too) */
#define ENABLE_MERGE 1

/* locale */
#define LOCALEDIR "/sys/lib/ape/locale"
