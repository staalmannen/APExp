#define _GNU_SOURCE
#include <string.h>
#include <dirent.h>

/*
 * versionsort - qsort/scandir comparator: version-aware ordering
 *
 * Sorts names containing embedded numbers numerically rather than
 * lexicographically (e.g. file9 < file10). Uses strverscmp().
 * This is a GNU extension, widely available and often probed for.
 */

int versionsort(const struct dirent **a, const struct dirent **b)
{
	return strverscmp((*a)->d_name, (*b)->d_name);
}
