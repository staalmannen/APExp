#include <string.h>
#include <dirent.h>

/*
 * alphasort - qsort/scandir comparator: alphabetical by d_name
 *
 * This is the most commonly used scandir comparator.
 * Uses strcoll() for locale-aware ordering per POSIX.
 */

int alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll((*a)->d_name, (*b)->d_name);
}
