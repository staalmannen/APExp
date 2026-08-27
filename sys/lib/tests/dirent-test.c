/*
 * dirent-test.c -- opendir/readdir/closedir, and what readdir fills in.
 *
 * Written to find out why GNU ls faults on a plain "ls". The acid trace
 * put the fault in gnulib's quotearg_buffer_restyled, scanning arg[i]
 * for a NUL with argsize == SIZE_MAX and never finding one, where arg
 * was dd_buf -- the first d_name that readdir() had just returned:
 *
 *   page fault  quotearg_buffer_restyled+0x162  MOVBZX 0x0(R10)(R13*1),DI
 *   sys: trap: fault read addr=0x44b000
 *   ...
 *   needs_quoting(name=0x440730)          ls.c:3306
 *   gobble_file(name=0x440730, ...)       ls.c:3337
 *   print_dir(... dirp=0x440700, next=0x440730 ...)  ls.c:3042
 *
 * sizeof(DIR) is 0x30 on amd64, so next == dirp + sizeof(DIR) == dd_buf:
 * the very first entry.
 *
 * That should not be possible. readdir() does
 *
 *   strncpy(dr[i].d_name, dir->name, MAXNAMLEN);
 *   dr[i].d_name[MAXNAMLEN] = 0;
 *
 * and d_name is char[MAXNAMLEN + 1], so index MAXNAMLEN is the last
 * byte and the name is terminated whatever the length. This test says
 * whether that is what actually happens.
 *
 * It also covers the rest of what readdir now fills in -- d_ino and
 * d_type became real members rather than macros onto d_stat -- and the
 * buffer refill, which is the part with arithmetic in it: readdir fills
 * DBLOCKSIZE (20) entries at a time and hands them out one at a time
 * with "dd_loc += sizeof(struct dirent)", so a directory of more than
 * 20 entries exercises a second pass through that code.
 *
 * Build and run:  pcc -o dirent-test dirent-test.c
 * Prints "PASS" per case; exit status is the number of failures.
 * Creates and removes a directory in the current directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

static int failures;

static void
check(const char *what, int ok, const char *detail)
{
	if (ok)
		printf("PASS  %s\n", what);
	else {
		printf("FAIL  %s%s%s\n", what, detail ? ": " : "",
		       detail ? detail : "");
		failures++;
	}
}

#define DIRNAME "dirent-test-d"
#define NFILES  47	/* more than DBLOCKSIZE, so readdir refills */

static void
cleanup(void)
{
	char path[256];
	int i;

	for (i = 0; i < NFILES; i++) {
		sprintf(path, "%s/f%02d", DIRNAME, i);
		remove(path);
	}
	remove(DIRNAME "/sub");
	remove(DIRNAME);
}

static int
setup(void)
{
	char path[256];
	int i, fd;

	cleanup();
	if (mkdir(DIRNAME, 0777) < 0) {
		printf("FAIL  setup: mkdir %s: %s\n", DIRNAME, strerror(errno));
		return -1;
	}
	for (i = 0; i < NFILES; i++) {
		sprintf(path, "%s/f%02d", DIRNAME, i);
		fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0666);
		if (fd < 0) {
			printf("FAIL  setup: create %s: %s\n", path,
			       strerror(errno));
			return -1;
		}
		write(fd, "x", 1);
		close(fd);
	}
	if (mkdir(DIRNAME "/sub", 0777) < 0) {
		printf("FAIL  setup: mkdir %s/sub: %s\n", DIRNAME,
		       strerror(errno));
		return -1;
	}
	return 0;
}

/* Is the name plausibly a NUL-terminated string within d_name? This is
   the case ls died on: scan the array itself rather than calling strlen,
   so that an unterminated name is reported instead of walking off. */
static int
terminated(const struct dirent *e, size_t *lenp)
{
	size_t i;

	for (i = 0; i < sizeof e->d_name; i++)
		if (e->d_name[i] == '\0') {
			*lenp = i;
			return 1;
		}
	*lenp = sizeof e->d_name;
	return 0;
}

int
main(void)
{
	DIR *d;
	struct dirent *e;
	char detail[512];
	int seen[NFILES], nsub, ndot, nother, n, i, bad;
	size_t len;

	if (setup() < 0) {
		cleanup();
		return 1;
	}

	printf("sizeof(struct dirent) = %d, MAXNAMLEN = %d\n",
	       (int)sizeof(struct dirent), (int)MAXNAMLEN);

	d = opendir(DIRNAME);
	if (d == NULL) {
		check("opendir", 0, strerror(errno));
		cleanup();
		return ++failures;
	}
	check("opendir", 1, NULL);

	for (i = 0; i < NFILES; i++)
		seen[i] = 0;
	nsub = ndot = nother = n = 0;
	bad = -1;

	while ((e = readdir(d)) != NULL) {
		n++;
		if (!terminated(e, &len)) {
			sprintf(detail, "entry %d at %p has no NUL in its "
			        "%d-byte d_name", n, (void *)e,
			        (int)sizeof e->d_name);
			check("every d_name is NUL-terminated", 0, detail);
			/* Do not touch it further; that is the fault. */
			bad = n;
			break;
		}
		if (len == 0) {
			sprintf(detail, "entry %d has an empty name", n);
			check("no empty names", 0, detail);
			bad = n;
			break;
		}
		if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
			ndot++;
		else if (strcmp(e->d_name, "sub") == 0)
			nsub++;
		else if (e->d_name[0] == 'f' && len == 3) {
			i = atoi(e->d_name + 1);
			if (0 <= i && i < NFILES)
				seen[i]++;
			else
				nother++;
		} else
			nother++;
	}

	if (bad < 0) {
		check("every d_name is NUL-terminated", 1, NULL);
		check("no empty names", 1, NULL);
	}

	if (bad < 0) {
		bad = -1;
		for (i = 0; i < NFILES; i++)
			if (seen[i] != 1) { bad = i; break; }
		if (bad >= 0)
			sprintf(detail, "f%02d seen %d times, expected once "
			        "(%d entries read in all)", bad, seen[bad], n);
		check("all 47 files come back exactly once, across the "
		      "20-entry refill", bad < 0, detail);

		sprintf(detail, "sub seen %d times", nsub);
		check("the subdirectory comes back once", nsub == 1, detail);

		sprintf(detail, "%d unrecognised entries", nother);
		check("no unrecognised entries", nother == 0, detail);
	}

	/* d_type. Plan 9 has no symlinks and cannot tell a socket from a
	   FIFO, but a regular file and a directory must be distinct --
	   this is what ls uses to avoid a stat() per entry. */
	rewinddir(d);
	{
		int type_sub = -1, type_f00 = -1;

		while ((e = readdir(d)) != NULL) {
			if (!terminated(e, &len))
				break;
			if (strcmp(e->d_name, "sub") == 0)
				type_sub = e->d_type;
			else if (strcmp(e->d_name, "f00") == 0)
				type_f00 = e->d_type;
		}
		sprintf(detail, "sub is d_type %d, want DT_DIR (%d)",
		        type_sub, DT_DIR);
		check("d_type says DT_DIR for a directory",
		      type_sub == DT_DIR, detail);
		sprintf(detail, "f00 is d_type %d, want DT_REG (%d)",
		        type_f00, DT_REG);
		check("d_type says DT_REG for a regular file",
		      type_f00 == DT_REG, detail);
	}

	/* d_ino must match what stat() reports for the same file. */
	rewinddir(d);
	{
		struct stat st;
		char path[512];
		int checked = 0;

		bad = 0;
		while ((e = readdir(d)) != NULL) {
			if (!terminated(e, &len))
				break;
			if (strcmp(e->d_name, ".") == 0
			 || strcmp(e->d_name, "..") == 0)
				continue;
			sprintf(path, "%s/%s", DIRNAME, e->d_name);
			if (stat(path, &st) < 0)
				continue;
			checked++;
			if (e->d_ino != st.st_ino) {
				sprintf(detail, "%s: d_ino %llu, stat %llu",
				        e->d_name,
				        (unsigned long long)e->d_ino,
				        (unsigned long long)st.st_ino);
				bad = 1;
				break;
			}
		}
		if (!bad)
			sprintf(detail, "checked %d entries", checked);
		check("d_ino matches stat's st_ino", !bad && checked > 0,
		      detail);
	}

	check("closedir", closedir(d) == 0, strerror(errno));

	/* An empty directory: opendir must succeed and readdir must reach
	   the end without handing back an unfilled entry. Plan 9 has no
	   "." or ".." entries, so this really is empty. */
	{
		DIR *ed;

		cleanup();
		if (mkdir(DIRNAME, 0777) == 0 && (ed = opendir(DIRNAME))) {
			n = 0;
			while ((e = readdir(ed)) != NULL) {
				if (!terminated(e, &len)) {
					n = -1;
					break;
				}
				n++;
			}
			sprintf(detail, n < 0 ? "returned an unterminated entry"
			                      : "%d entries in an empty (or "
			                        "dot-only) directory", n);
			check("an empty directory ends cleanly",
			      n >= 0 && n <= 2, detail);
			closedir(ed);
		} else
			check("an empty directory ends cleanly", 0,
			      "could not create or open it");
	}

	cleanup();

	if (failures)
		printf("\n%d failure(s)\n", failures);
	else
		printf("\nall ok\n");
	return failures;
}
