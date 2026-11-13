/*
 * edgmmap-probe -- reproduce the CALL SEQUENCE EDG's memory manager
 * makes, which is a FILE-BACKED mmap used as a growing backing store.
 *
 *	pcc -o edgmmap-probe edgmmap-probe.c && ./edgmmap-probe
 *	gcc -o edgmmap-probe edgmmap-probe.c && ./edgmmap-probe   (control)
 *
 * ***A PROBE.***  Sections 0-2 assert nothing about Plan 9 and report
 * what they see; sections 3 and 4 DO assert, because they are about
 * POSIX rules rather than about this platform's choices, and they are
 * checked against glibc first.  Read the per-section lines, not only
 * the count.
 *
 * WHERE IT COMES FROM
 * ===================
 *
 * `cxx-vecacid' got a stack out of the twelve-line `<vector>'
 * reproducer, and it is not where five rounds of narrowing expected:
 *
 *	_ZN3edg18free_memory_regionEi(...)+0x21   mem_manage.c:1208
 *	_ZN3edg9fe_wrapupEv()+0x109
 *	cfe_main(...)+0xd1
 *	main+0x13
 *
 * `mem_manage.c:1208' is `next_hdr = hdr->next' inside
 *
 *	for (hdr = mem_region_table[rn]; hdr != 0; ) {
 *	    next_hdr = hdr->next;	<-- faults, hdr == 0x3f4a1
 *	    free_mem_block(hdr);
 *	    hdr = next_hdr;
 *	}
 *
 * ***SO IT IS TEARDOWN, NOT PARSING.***  cpfe finishes the
 * translation and dies freeing its memory regions, and `hdr' is a
 * small garbage value rather than a heap address.  Every narrowing
 * before this had been looking at the front end.
 *
 * AND THE MEMORY MANAGER IS mmap.  `mem_manage.c:524's
 * `alloc_new_mem_block' has no alternative path: it opens a tmp file
 * once and then, for every block,
 *
 *	mmap(NULL, incremental_size, PROT_READ|PROT_WRITE,
 *	     MAP_PRIVATE, fileno(tmpfile), file_offset)
 *
 * with `file_offset' accumulating -- a growing file-backed store.
 * ***THESE NOTES HAD RECORDED mmap AS CLEARED AND THAT WAS TOO
 * STRONG***: what was checked is `open_mapped_input_file', which
 * serves PCH and IFC modules and never a source file.  That verdict
 * about one function was generalised to the whole mechanism, and
 * `map_memory_region_file' is a different function that every
 * allocation goes through.
 *
 * libap does not map files.  `__p9_syscall.c:239' emulates:
 * `malloc' (under `SEG_THRESHOLD', 64MB) or `segattach', then
 * `memset' to zero, then `read(fd, p, len)' to pull the contents in.
 * For `MAP_PRIVATE' that is defensible -- writes are not meant to
 * reach the file -- but it is a COPY, and this release rewrote all
 * of it: the threshold moved from 1MB to 64MB, the malloc arm began
 * page-aligning by hand, and partial `munmap' was rebuilt twice.
 *
 * WHAT EACH SECTION ASKS
 * ======================
 *
 *  0  does a file-backed MAP_PRIVATE mmap succeed at all, for a
 *     sequence of growing offsets, and are the addresses distinct?
 *  1  is each region writable and does it read back what was
 *     written?  **Distinct addresses are not enough**: two regions
 *     that overlap would both be writable and would corrupt each
 *     other, which is what a garbage `hdr' looks like from outside.
 *  2  THE ONE THAT MATTERS: unmap the regions ONE BY ONE, in EDG's
 *     own order, and after each unmap re-read every region still
 *     believed live.  *That is `free_memory_region's loop*, and a
 *     munmap that releases more than it was asked for shows up here
 *     and nowhere else.
 *  3  `off == 0' must still read from offset 0.  `__p9_syscall.c:241'
 *     reads `if(off != 0) lseek(...)' -- and the fd comes from
 *     `fileno()' on a FILE that stdio has just written through, so
 *     its position is NOT 0 and the guard skips the seek that would
 *     have fixed it.  POSIX says the mapping starts at `off'.
 *  4  a mapping must not be disturbed by an unrelated later mmap.
 *
 * Sections are numbered so the output says which code ran, and every
 * one prints before it acts: a fault gives the shell prompt back
 * exactly like a clean exit does.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

/*
 * Version marker: a test built from a fresh pull against a days-old
 * libap measures the old library and says nothing.
 *
 * ***IT IS `_mmapoffmark' AND NOT `_mmapmark', AND THE DIFFERENCE IS
 * THE WHOLE POINT.***  `_mmapmark' already existed, so referencing it
 * would LINK against a libap predating the unconditional `lseek' this
 * probe's section 3 measures -- and the probe would then report the
 * OLD behaviour as this machine's answer.  **A version marker is only
 * a marker for the fix it was added with.**  (The first draft also
 * declared it `extern int' and took its address, where it is a
 * FUNCTION; it linked, because the name is the same, and was simply
 * the wrong declaration.)
 */
#ifndef HOSTCHECK
extern int _mmapoffmark(void);	/* see the note at the top */
#endif

#define NREG   8
#define REGSZ  (64 * 1024)

static int failures;

static void
check(const char *name, int ok)
{
	printf("%s  %s\n", ok ? "PASS" : "FAIL", name);
	if (!ok)
		failures++;
}

/*
 * EDG's own preamble before each map: seek past the end, write a
 * byte, flush.  Copied from `map_memory_region_file' rather than
 * recalled -- a probe that skips a call cannot clear it, and the
 * `fputc' is what makes the file long enough to map.
 */
static void
extend(FILE *f, long to)
{
	fseek(f, to, SEEK_SET);
	fputc(0, f);
	fflush(f);
}

int
main(void)
{
	FILE *f;
	int fd;
	void *reg[NREG];
	long off[NREG];
	long cur;
	int i, j, ok;

	setvbuf(stdout, 0, _IOLBF, 0);
#ifndef HOSTCHECK
	printf("edgmmap-probe: starting, _mmapoffmark = %d\n", _mmapoffmark());
#else
	printf("edgmmap-probe: starting (HOSTCHECK)\n");
#endif

	f = tmpfile();
	if (f == 0) {
		printf("edgmmap-probe: tmpfile() failed; cannot run\n");
		return 1;
	}
	fd = fileno(f);

	/* ---- section 0: can we map at all, growing? ---------------- */
	printf("\n-- 0: %d file-backed MAP_PRIVATE mappings of %d bytes\n",
	       NREG, REGSZ);
	cur = 0;
	ok = 1;
	for (i = 0; i < NREG; i++) {
		extend(f, cur + REGSZ);
		off[i] = cur;
		reg[i] = mmap(0, REGSZ, PROT_READ | PROT_WRITE, MAP_PRIVATE,
		              fd, (off_t)cur);
		/*
		 * gcc reported `off' set and not used, which was true:
		 * the array was recording the offsets and nothing ever
		 * read them.  **An unused array in a probe is a check
		 * somebody meant to write**, so section 2 reports the
		 * offset beside the address -- if a later section ever
		 * disagrees about which region is which, the offset is
		 * what names it.
		 */
		printf("   region %d at offset %ld -> %p\n", i, cur,
		       reg[i] == MAP_FAILED ? (void *)0 : reg[i]);
		if (reg[i] == MAP_FAILED)
			ok = 0;
		cur += REGSZ;
	}
	check("0: every region mapped", ok);

	ok = 1;
	for (i = 0; i < NREG && ok; i++)
		for (j = i + 1; j < NREG; j++)
			if (reg[i] != MAP_FAILED && reg[j] != MAP_FAILED &&
			    reg[i] == reg[j])
				ok = 0;
	check("0: addresses are distinct", ok);

	/* ---- section 1: writable, and no two overlap --------------- */
	printf("\n-- 1: write a per-region pattern, then read every one back\n");
	for (i = 0; i < NREG; i++)
		if (reg[i] != MAP_FAILED)
			memset(reg[i], 'A' + i, REGSZ);
	ok = 1;
	for (i = 0; i < NREG; i++) {
		if (reg[i] == MAP_FAILED)
			continue;
		if (((char *)reg[i])[0] != 'A' + i ||
		    ((char *)reg[i])[REGSZ - 1] != 'A' + i) {
			printf("   region %d holds %d/%d, wanted %d\n", i,
			       ((char *)reg[i])[0],
			       ((char *)reg[i])[REGSZ - 1], 'A' + i);
			ok = 0;
		}
	}
	check("1: regions do not overlap", ok);

	/* ---- section 2: EDG's teardown loop ------------------------ */
	/*
	 * THE SECTION THIS FILE EXISTS FOR.  Unmap one region, then
	 * re-read every region still live.  A munmap that releases
	 * more than it was asked for corrupts a NEIGHBOUR, which is
	 * what `hdr == 0x3f4a1' looks like from the outside.
	 */
	printf("\n-- 2: unmap one at a time, re-reading the survivors\n");
	ok = 1;
	for (i = 0; i < NREG; i++) {
		if (reg[i] == MAP_FAILED)
			continue;
		printf("   unmapping region %d (%p, file offset %ld)\n",
		       i, reg[i], off[i]);
		if (munmap(reg[i], REGSZ) != 0) {
			printf("   munmap of region %d FAILED\n", i);
			ok = 0;
		}
		for (j = i + 1; j < NREG; j++) {
			if (reg[j] == MAP_FAILED)
				continue;
			if (((char *)reg[j])[0] != 'A' + j ||
			    ((char *)reg[j])[REGSZ - 1] != 'A' + j) {
				printf("   after unmapping %d, region %d is "
				       "CORRUPT (%d/%d, wanted %d)\n", i, j,
				       ((char *)reg[j])[0],
				       ((char *)reg[j])[REGSZ - 1], 'A' + j);
				ok = 0;
			}
		}
	}
	check("2: unmapping one region leaves the others intact", ok);

	/* ---- section 3: offset 0 must still start at offset 0 ------ */
	/*
	 * POSIX, not a platform question, so this one ASSERTS.  The
	 * file is filled with 'Z' at offset 0; a mapping at offset 0
	 * must see 'Z'.  libap reads `if(off != 0) lseek(...)' and the
	 * fd's position is wherever stdio left it, which is never 0
	 * after `extend()'.
	 */
	printf("\n-- 3: a mapping at offset 0 must see offset 0\n");
	{
		char buf[256];
		void *p;

		memset(buf, 'Z', sizeof buf);
		fseek(f, 0, SEEK_SET);
		fwrite(buf, 1, sizeof buf, f);
		fflush(f);
		extend(f, 4096);

		p = mmap(0, 256, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd,
		         (off_t)0);
		if (p == MAP_FAILED) {
			check("3: mapping at offset 0 succeeds", 0);
		} else {
			printf("   first byte is %d, wanted %d ('Z')\n",
			       ((char *)p)[0], 'Z');
			check("3: offset 0 reads the start of the file",
			      ((char *)p)[0] == 'Z');
			munmap(p, 256);
		}
	}

	/* ---- section 4: a later mmap must not disturb an earlier --- */
	printf("\n-- 4: a live mapping survives an unrelated later mmap\n");
	{
		void *a, *b;

		extend(f, 8 * 4096);
		a = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd,
		         (off_t)0);
		if (a == MAP_FAILED) {
			check("4: first mapping succeeds", 0);
		} else {
			memset(a, 'Q', 4096);
			b = mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE,
			         fd, (off_t)4096);
			printf("   a=%p b=%p\n", a,
			       b == MAP_FAILED ? (void *)0 : b);
			check("4: earlier mapping still holds its data",
			      ((char *)a)[0] == 'Q' &&
			      ((char *)a)[4095] == 'Q');
			if (b != MAP_FAILED)
				munmap(b, 4096);
			munmap(a, 4096);
		}
	}

	fclose(f);
	printf("\n%d failure%s\n", failures, failures == 1 ? "" : "s");
	return failures;
}
