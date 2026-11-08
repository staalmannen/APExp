#include <fts.h>

FTS *
fts_open(char * const *path, int opt, int (*compar)(const FTSENT **, const FTSENT **))
{
	/* FIXME */
	USED(path, opt, compar);
	fprint(2, "FIXME fts_open not implemented\n");

	return nil;
}
