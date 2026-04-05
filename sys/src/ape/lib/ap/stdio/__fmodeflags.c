#include <fcntl.h>

int __fmodeflags(const char *mode)
{
	int flags = 0;
	int reading = 0, writing = 0, appending = 0, plus = 0;

	if (!mode) return -1;

	switch (*mode) {
	case 'r':
		reading = 1;
		break;
	case 'w':
		writing = 1;
		flags |= O_CREAT | O_TRUNC;
		break;
	case 'a':
		appending = 1;
		flags |= O_CREAT | O_APPEND;
		break;
	default:
		return -1;
	}
	mode++;

	while (*mode) {
		if (*mode == 'b') {
		} else if (*mode == '+') {
			plus = 1;
		} else if (*mode == 'e') {
			flags |= O_CLOEXEC;
		}
		mode++;
	}

	if (plus) {
		flags |= O_RDWR;
	} else if (reading) {
		flags |= O_RDONLY;
	} else if (writing || appending) {
		flags |= O_WRONLY;
	}

	return flags;
}


