/*
 * tarblock-probe -- is `union block' 512 bytes under this compiler?
 *
 * THIS IS A PROBE. It prints sizes beside the host's answers and says
 * which one disagrees; it asserts nothing about the platform.
 *
 * BUILD IT WITH TAR'S OWN FLAGS, because tar.h is reached through
 * tar's include path and its config.h. From sys/src/ape/cmd/tar:
 *
 *	pcc -o /tmp/tarblock-probe -B -p -I. \
 *	    -I../../../external/gnulib \
 *	    -I../../../external/gtar \
 *	    -I../../../external/gtar/src \
 *	    -I../../../external/gtar/lib \
 *	    -DHAVE_CONFIG_H \
 *	    ../../../../lib/tests/tarblock-probe.c
 *	/tmp/tarblock-probe
 *
 * (Those are the CFLAGS from sys/src/ape/cmd/tar/mkfile, minus the two
 * that only matter for compiling tar itself. *Put a test binary in the
 * directory whose flags it shares* -- with a different -I order this
 * would measure a different tar.h and say nothing.)
 *
 * ------------------------------------------------------------------
 * WHERE IT CAME FROM. `tar cf /tmp/t.tar /tmp/h' now completes, and
 * tarhdr-probe on the archive it wrote says the archive is MALFORMED --
 * so this is tar's write path, not its reader:
 *
 *	block 0: member 1, ustar header
 *	  decoded chksum = 4776, computed = 4776  -- MATCH
 *	  1 data block, so the next header belongs at block 2
 *	    block 1 (the member's data):
 *	      first 16 bytes: 00 00 00 00 00 00 00 00 68 65 6c 6c 6f 0a 00 00
 *	block 2: NOT a ustar header and NOT zero
 *	block 3: NOT a ustar header and NOT zero
 *	blocks 4..19: ALL ZERO
 *
 * The header block is perfect. But "hello\n" sits **8 bytes into block
 * 1** instead of at its start, and the host reference for the same
 * archive has it at offset 0.
 *
 * THAT OFFSET IS A MEASUREMENT OF sizeof(union block), and this is the
 * whole reason for the file. create.c's dump_regular_file() does
 *
 *	blk = start_header (st);	// returns record_start
 *	finish_header (...);		// set_next_block_after -> record_start + 1
 *	blk = find_next_block ();	// record_start + 1
 *	count = blocking_read (fd, blk->buffer, bufsize);
 *
 * so the file offset of the member's data is exactly
 * `1 * sizeof(union block)'. It came out 520. Every member of that
 * union is an array of char, and the host makes it 512, so 520 would
 * mean kencc is padding one of them -- which would shift every block
 * after the first and is a compiler question, not a tar one.
 *
 * WHAT EACH ANSWER MEANS, written down before the run:
 *
 *   520 (or anything but 512): CONFIRMED. The union is the bug, the
 *       member this prints as oversized is the one to look at, and
 *       every archive this tar has ever written is malformed the same
 *       way. It would also explain the second symptom, since the
 *       zero-fill in dump_regular_file and write_eot are computed in
 *       BLOCKSIZE units while the pointers step in sizeof(union block).
 *
 *   512: REFUTED, and that is worth as much. The union is innocent,
 *       the 8-byte shift is in the copy loop or in what read() does
 *       with the buffer it is handed, and the next probe belongs
 *       there instead. Do not go on believing the union.
 *
 * The second symptom -- blocks 2 and 3 holding `b6 01 00 00 cd 98 b4
 * 6a' and the like -- is NOT explained yet either way, and is recorded
 * rather than assumed away: 0x1b6 is 0666 and 0x6ab498cd read little
 * endian is a plausible 2026 mtime, so those look like the fields of a
 * struct stat rather than uninitialised heap. A fresh allocation on
 * Plan 9 comes from newly sbrk'd pages, which are zero, so a non-zero
 * byte in there was WRITTEN by something. That is a separate question.
 */

/*
 * tar.h's prerequisites. It uses uintmax_t, bool, struct stat,
 * struct timespec and DIR without including anything for them, which
 * is fine inside tar (system.h has already run) and has to be done by
 * hand here.
 */
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#ifndef __cplusplus
# if !defined(bool) && !defined(__bool_true_false_are_defined)
#  include <stdbool.h>
# endif
#endif

#include "tar.h"

static int disagreements = 0;

static void
sz(char *what, long got, long host)
{
	printf("  %-24s = %4ld   host says %4ld   %s\n",
		what, got, host, got == host ? "same" : "*** DIFFERENT ***");
	if(got != host)
		disagreements++;
}

int
main(void)
{
	long b;

	printf("tarblock-probe\n\n");

	printf("sizes, beside the values gcc gives for the same headers:\n");
	sz("BLOCKSIZE", (long)BLOCKSIZE, 512);
	sz("sizeof(union block)", (long)sizeof(union block), 512);
	sz("sizeof(struct sparse)", (long)sizeof(struct sparse), 24);
	sz("sizeof(posix_header)", (long)sizeof(struct posix_header), 500);
	sz("sizeof(star_header)", (long)sizeof(struct star_header), 500);
	sz("sizeof(oldgnu_header)", (long)sizeof(struct oldgnu_header), 495);
	sz("sizeof(sparse_header)", (long)sizeof(struct sparse_header), 505);
	sz("sizeof(star_in_header)", (long)sizeof(struct star_in_header), 512);
	sz("sizeof(star_ext_header)", (long)sizeof(struct star_ext_header), 505);

	/*
	 * The header's field offsets are fixed by the FORMAT, not by the
	 * compiler, and tarhdr-probe already read them back correctly
	 * from the archive -- so these are expected to agree. They are
	 * here because if they ever do not, every other number above is
	 * beside the point.
	 */
	printf("\nposix_header field offsets (fixed by the tar format):\n");
	sz("offsetof name", (long)offsetof(struct posix_header, name), 0);
	sz("offsetof size", (long)offsetof(struct posix_header, size), 124);
	sz("offsetof chksum", (long)offsetof(struct posix_header, chksum), 148);
	sz("offsetof typeflag", (long)offsetof(struct posix_header, typeflag), 156);
	sz("offsetof magic", (long)offsetof(struct posix_header, magic), 257);
	sz("offsetof prefix", (long)offsetof(struct posix_header, prefix), 345);

	/*
	 * And the line the whole thing is about. tar steps through the
	 * record with `union block *' arithmetic while every length in
	 * the format is a multiple of BLOCKSIZE, so these two agree only
	 * if the union is exactly BLOCKSIZE.
	 */
	b = (long)sizeof(union block);
	printf("\nwhere tar's pointer arithmetic puts each block in the file:\n");
	printf("  block 0 at %5ld   (must be     0)\n", 0L);
	printf("  block 1 at %5ld   (must be   512)  <- the member's data\n", b);
	printf("  block 2 at %5ld   (must be  1024)\n", 2 * b);
	printf("  block 3 at %5ld   (must be  1536)\n", 3 * b);
	printf("  record_end (blocking_factor 20) at %ld   (must be 10240)\n",
		20 * b);

	printf("\n");
	if(b != BLOCKSIZE){
		printf("CONFIRMED: union block is %ld, not %d.\n", b, BLOCKSIZE);
		printf("The member marked DIFFERENT above is the one padded.\n");
		printf("Every block after the first is %ld bytes late, which is\n",
			b - BLOCKSIZE);
		printf("exactly the shift tarhdr-probe measured in the archive.\n");
	}else{
		printf("REFUTED: union block is %d, so it is NOT the cause.\n",
			BLOCKSIZE);
		printf("The 8-byte shift comes from somewhere else -- the copy\n");
		printf("loop in create.c, or what read() does with the buffer\n");
		printf("it is handed. Stop believing the union and probe there.\n");
	}
	printf("\n%d disagreement%s with the host\n",
		disagreements, disagreements == 1 ? "" : "s");
	return disagreements;
}
