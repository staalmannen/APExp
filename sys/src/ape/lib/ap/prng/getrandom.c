#include <u.h>
#include <sys/types.h>
#include <sys/random.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libsec.h>
#include <limits.h>

ssize_t
getrandom(void *buf, size_t buflen, unsigned int flags)
{
	int fd;
	int oflags;
	ssize_t n;

	if (flags & ~(GRND_NONBLOCK | GRND_RANDOM | GRND_INSECURE)) {
		errno = EINVAL;
		return -1;
	}

	if (flags & GRND_RANDOM) {
		oflags = O_RDONLY;
		if (flags & GRND_NONBLOCK)
			oflags |= O_NONBLOCK;

		fd = open("/dev/random", oflags);
		if (fd < 0) {
			if (errno == ENOENT)
				errno = ENOSYS;
			return -1;
		}
		n = read(fd, buf, buflen);
		close(fd);
		return n;
	}

	/*
	 * Default case (equivalent to /dev/urandom).
	 * We use genrandom() from libsec, which is a CSPRNG (ChaCha)
	 * seeded from /dev/random.
	 */
	if (buflen > INT_MAX)
		buflen = INT_MAX;
	genrandom(buf, (int)buflen);
	return (ssize_t)buflen;
}
