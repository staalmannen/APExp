#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/*
 * get_current_dir_name: like getcwd(NULL, 0) on Linux — allocates and returns cwd.
 * GNU extension used by bash and various configure scripts.
 */
char *
get_current_dir_name(void)
{
	char *buf = malloc(PATH_MAX);
	if(!buf)
		return NULL;
	if(getcwd(buf, PATH_MAX) == NULL){
		free(buf);
		return NULL;
	}
	return buf;
}

/*
 * canonicalize_file_name: GNU alias for realpath(path, NULL).
 * Returns malloc'd canonical path, or NULL on error.
 */
char *
canonicalize_file_name(const char *path)
{
	return realpath(path, NULL);
}
