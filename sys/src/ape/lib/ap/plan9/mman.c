#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "../include/syscall.h"

/*
 * mmap/munmap and related wrappers for APExp.
 *
 * The actual emulation (segattach for large allocations, malloc for
 * small ones, read() for file-backed) lives in __p9_syscall.c.
 * These functions expose them as public symbols that programs can link.
 *
 * Limitations:
 *   - MAP_SHARED write-back not supported; writes stay private.
 *   - mprotect, msync, mlock, madvise are no-ops.
 *   - mremap allocates new memory and copies (no in-place resize).
 *   - shm_open is backed by files in /tmp.
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

/*
 * mremap: resize a mapping. Plan9 has no native resize; we allocate
 * new memory, copy, and unmap the old region.
 */
void *
mremap(void *old_addr, size_t old_len, size_t new_len, int flags, ...)
{
	void *p;
	(void)flags;
	p = mmap(NULL, new_len, PROT_READ|PROT_WRITE,
	         MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if(p == MAP_FAILED)
		return MAP_FAILED;
	memcpy(p, old_addr, old_len < new_len ? old_len : new_len);
	munmap(old_addr, old_len);
	return p;
}

/*
 * shm_open / shm_unlink: POSIX shared memory backed by /tmp files.
 * Plan9 has no true shared memory; this lets programs compile and run
 * single-process use cases (e.g. allocators that use shm as a heap).
 */
int
shm_open(const char *name, int oflag, mode_t mode)
{
	char path[256];
	const char *n = name;
	if(n[0] == '/') n++;
	snprintf(path, sizeof path, "/tmp/shm.%s", n);
	return open(path, oflag | O_CREAT, mode);
}

int
shm_unlink(const char *name)
{
	char path[256];
	const char *n = name;
	if(n[0] == '/') n++;
	snprintf(path, sizeof path, "/tmp/shm.%s", n);
	return unlink(path);
}
