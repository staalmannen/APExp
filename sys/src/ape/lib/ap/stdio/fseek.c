#include "stdio_impl.h"

/*
 * fseek is fseeko with a narrower offset. It used to be a second copy
 * of the same logic, and the two had already drifted; see fseeko.c for
 * what was wrong with both. No locking here -- fseeko takes the lock,
 * and __lockfile is a real mutex, so taking it twice would deadlock.
 */
int fseek(FILE *f, long offs, int type){
	return fseeko(f, (off_t)offs, type);
}
