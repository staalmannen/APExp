#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/syscall.h"

//#define __mmap mmap
//#define __fstat fstat

const char unsigned *__map_file(const char *pathname, size_t *size)
{
	struct stat st;
	const unsigned char *map = MAP_FAILED;
	int fd = sys_open(pathname, O_RDONLY|O_CLOEXEC|O_NONBLOCK);
	if (fd < 0) return 0;
	if (!__fstat(fd, &st)) {
		map = (const unsigned char *) __mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
		*size = st.st_size;
	}
	__syscall(1004, fd);
	return map == MAP_FAILED ? 0 : map;
}
