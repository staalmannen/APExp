#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

/*
 * __map_file: load a file into memory for read-only access.
 *
 * On Linux/musl this uses mmap(MAP_SHARED). On Plan9/APExp,
 * file-backed mmap is not available, so we read the whole file
 * into a malloc'd buffer. The returned pointer behaves like a
 * read-only mapping; the caller should pass it to munmap() when
 * done, which will free() it (our munmap emulation does this for
 * malloc-based regions tracked in mmap_table).
 *
 * Returns NULL on error, sets *size to file length on success.
 */
const unsigned char *
__map_file(const char *pathname, size_t *size)
{
	struct stat st;
	unsigned char *buf;
	ssize_t n;
	int fd;

	fd = open(pathname, O_RDONLY);
	if(fd < 0)
		return NULL;
	if(fstat(fd, &st) < 0){
		close(fd);
		return NULL;
	}
	buf = malloc((size_t)st.st_size);
	if(!buf){
		close(fd);
		return NULL;
	}
	n = read(fd, buf, (size_t)st.st_size);
	close(fd);
	if(n != (ssize_t)st.st_size){
		free(buf);
		return NULL;
	}
	*size = (size_t)st.st_size;
	return buf;
}
