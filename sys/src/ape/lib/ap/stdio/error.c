#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* These mirror glibc globals; programs may set them from argv[0]. */
const char *program_invocation_name = "";
const char *program_invocation_short_name = "";

unsigned int error_message_count = 0;
int error_one_per_line = 0;
void (*error_print_progname)(void) = NULL;

static void
print_progname(void)
{
	if(error_print_progname){
		(*error_print_progname)();
		return;
	}
	if(program_invocation_name && *program_invocation_name)
		fprintf(stderr, "%s: ", program_invocation_name);
}

void
error(int status, int errnum, const char *fmt, ...)
{
	va_list ap;
	fflush(stdout);
	print_progname();
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	if(errnum)
		fprintf(stderr, ": %s", strerror(errnum));
	fputc('\n', stderr);
	error_message_count++;
	if(status)
		exit(status);
}

void
error_at_line(int status, int errnum, const char *filename,
              unsigned int lineno, const char *fmt, ...)
{
	va_list ap;
	fflush(stdout);
	print_progname();
	fprintf(stderr, "%s:%u: ", filename ? filename : "", lineno);
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	if(errnum)
		fprintf(stderr, ": %s", strerror(errnum));
	fputc('\n', stderr);
	error_message_count++;
	if(status)
		exit(status);
}
