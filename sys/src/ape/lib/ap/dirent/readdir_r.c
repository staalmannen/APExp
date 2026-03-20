#include "lib.h"
#include <dirent.h>
#include <errno.h>
#include <string.h>

/*
 * readdir_r - reentrant readdir
 *
 * Fills caller-supplied *entry and sets *result to entry on success,
 * NULL on end-of-directory. Returns 0 on success, errno value on error.
 *
 * Note: readdir_r is deprecated in POSIX.1-2017 in favour of readdir()
 * with external locking, but is still widely used and probed for.
 *
 * Since APE has no thread support, this is equivalent to readdir()
 * with a copy into the caller's buffer.
 */
int
readdir_r(DIR *restrict d, struct dirent *restrict entry,
          struct dirent **restrict result)
{
	struct dirent *de;

	if(d == NULL){
		*result = NULL;
		return EBADF;
	}

	de = readdir(d);
	if(de == NULL){
		*result = NULL;
		return 0;	/* end of directory, not an error */
	}

	/* copy into caller's buffer */
	memcpy(entry, de, sizeof(struct dirent));
	*result = entry;
	return 0;
}
