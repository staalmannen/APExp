#include <sys/mman.h>
#include <errno.h>
#include "../include/syscall.h"

/*
 * mmap/munmap wrappers for APExp.
 *
 * The actual emulation (segattach for large allocations, malloc for
 * small ones) lives in __p9_syscall.c as p9_mmap_tracked/p9_munmap.
 * These functions expose them as public symbols that programs can link.
 *
 * Limitations:
 *   - Only anonymous mappings (MAP_ANON) work; file-backed mmap returns ENOSYS.
 *   - mprotect, msync, mlock, madvise are no-ops: Plan9 has no equivalents.
 *   - mremap is not implemented.
 */

void *
mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off)
{
	long r = __p9_syscall(SYS_mmap,
	                      (long)addr, (long)len, (long)prot,
	                      (long)flags, (long)fd, (long)off);
	if(r < 0){
		errno = (int)-r;
		return MAP_FAILED;
	}
	return (void *)(uintptr_t)r;
}

int
munmap(void *addr, size_t len)
{
	long r = __p9_syscall(SYS_munmap, (long)addr, (long)len,
	                      0L, 0L, 0L, 0L);
	if(r < 0){
		errno = (int)-r;
		return -1;
	}
	return 0;
}

int
mprotect(void *addr, size_t len, int prot)
{
	(void)addr; (void)len; (void)prot;
	return 0;
}

int
msync(void *addr, size_t len, int flags)
{
	(void)addr; (void)len; (void)flags;
	return 0;
}

int
mlock(const void *addr, size_t len)
{
	(void)addr; (void)len;
	return 0;
}

int
munlock(const void *addr, size_t len)
{
	(void)addr; (void)len;
	return 0;
}

int
mlockall(int flags)
{
	(void)flags;
	return 0;
}

int
munlockall(void)
{
	return 0;
}

int
posix_madvise(void *addr, size_t len, int advice)
{
	(void)addr; (void)len; (void)advice;
	return 0;
}

int
madvise(void *addr, size_t len, int advice)
{
	(void)addr; (void)len; (void)advice;
	return 0;
}

int
mincore(void *addr, size_t len, unsigned char *vec)
{
	(void)addr; (void)len; (void)vec;
	errno = ENOSYS;
	return -1;
}
