#include "lib.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
 * scandir - scan a directory, collecting entries into a sorted array
 *
 * Opens the directory at 'path', calls filter(entry) on each entry
 * (skipping those where filter returns 0, or all if filter is NULL),
 * then sorts the collected entries with compar (or leaves unsorted if
 * compar is NULL), storing the result in *namelist.
 *
 * Returns the number of entries collected, or -1 on error.
 * Caller must free each entry and the array itself:
 *   for(i = 0; i < n; i++) free(namelist[i]);
 *   free(namelist);
 */
int
scandir(const char *path,
        struct dirent ***namelist,
        int (*filter)(const struct dirent *),
        int (*compar)(const struct dirent **, const struct dirent **))
{
	DIR *d;
	struct dirent *de, *copy;
	struct dirent **list;
	int n, alloc;

	d = opendir(path);
	if(d == NULL)
		return -1;

	alloc = 32;
	n = 0;
	list = malloc(alloc * sizeof *list);
	if(list == NULL){
		closedir(d);
		errno = ENOMEM;
		return -1;
	}

	while((de = readdir(d)) != NULL){
		/* apply filter if provided */
		if(filter != NULL && filter(de) == 0)
			continue;

		/* copy the entry — caller owns the memory */
		copy = malloc(sizeof(struct dirent));
		if(copy == NULL){
			int i;
			for(i = 0; i < n; i++) free(list[i]);
			free(list);
			closedir(d);
			errno = ENOMEM;
			return -1;
		}
		memcpy(copy, de, sizeof(struct dirent));

		/* grow list if needed */
		if(n >= alloc){
			struct dirent **newlist;
			alloc *= 2;
			newlist = realloc(list, alloc * sizeof *list);
			if(newlist == NULL){
				int i;
				free(copy);
				for(i = 0; i < n; i++) free(list[i]);
				free(list);
				closedir(d);
				errno = ENOMEM;
				return -1;
			}
			list = newlist;
		}

		list[n++] = copy;
	}

	closedir(d);

	/* sort if comparator provided */
	if(compar != NULL && n > 1)
		qsort(list, n, sizeof *list,
		      (int (*)(const void *, const void *))compar);

	*namelist = list;
	return n;
}

/*
 * alphasort - qsort/scandir comparator: alphabetical by d_name
 *
 * This is the most commonly used scandir comparator.
 * Uses strcoll() for locale-aware ordering per POSIX.
 */
int
alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll((*a)->d_name, (*b)->d_name);
}

/*
 * versionsort - qsort/scandir comparator: version-aware ordering
 *
 * Sorts names containing embedded numbers numerically rather than
 * lexicographically (e.g. file9 < file10). Uses strverscmp().
 * This is a GNU extension, widely available and often probed for.
 */
int
versionsort(const struct dirent **a, const struct dirent **b)
{
	return strverscmp((*a)->d_name, (*b)->d_name);
}
