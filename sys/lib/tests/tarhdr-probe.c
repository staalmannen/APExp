/*
 * tarhdr-probe -- say what is actually in a tar file, block by block.
 *
 * THIS IS A PROBE, NOT A TEST. It asserts nothing and has no pass or
 * fail; it prints what the bytes are and leaves the reading to you.
 * Anything it could assert would be an assertion about GNU tar's
 * format rather than about this tree.
 *
 *	pcc -o tarhdr-probe tarhdr-probe.c
 *	./tarhdr-probe /tmp/t.tar
 *
 * It is correct on gcc too -- check it against an archive made by a
 * working tar first, which is how you find out whether the probe or
 * the tree is wrong:
 *
 *	echo hello > /tmp/h && tar cf /tmp/ref.tar /tmp/h
 *	gcc -o tarhdr-probe tarhdr-probe.c && ./tarhdr-probe /tmp/ref.tar
 *
 * ------------------------------------------------------------------
 * WHY IT EXISTS. With gnulib's self-recursive strerror out of the way,
 * `tar cf /tmp/t.tar /tmp/h' completes, and `tar tf' on the archive it
 * just wrote says:
 *
 *	tmp/h
 *	tar: Skipping to next header
 *	tar: Exiting with failure status due to previous errors
 *
 * The first member is read CORRECTLY -- the name is right, so the
 * header parsed and its checksum verified. Then the next read_header()
 * returned HEADER_FAILURE: a block that is neither a valid header nor
 * all zeros (list.c:294 prints that message only when the PREVIOUS
 * status was HEADER_STILL_OK).
 *
 * For a one-file archive there should be nothing between the member
 * and the end-of-archive zero blocks, so exactly one of two things is
 * true, and they need completely different fixes:
 *
 *   (a) THE ARCHIVE IS MALFORMED -- tar's WRITE path is broken, and
 *       the read is correctly refusing garbage.
 *   (b) THE ARCHIVE IS FINE -- tar's READ path is broken, most likely
 *       in how far it advances past the member's data, since landing
 *       one block short would make it read the file's own contents as
 *       a header and get exactly this.
 *
 * A probe that prints the bytes separates those in one run, where
 * reading tar's source could argue either way. The same question is
 * open for the archive that started all this, and this program answers
 * it for any file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 512

/* POSIX ustar header, field by field, at the offsets the format fixes. */
struct hdr {
	char name[100];
	char mode[8];
	char uid[8];
	char gid[8];
	char size[12];
	char mtime[12];
	char chksum[8];
	char typeflag;
	char linkname[100];
	char magic[6];
	char version[2];
	char uname[32];
	char gname[32];
	char devmajor[8];
	char devminor[8];
	char prefix[155];
	char pad[12];
};

static unsigned char *buf;
static long len;

/*
 * Print a fixed-width field the way the format stores it: it is not
 * NUL-terminated when it fills the space, and trailing NULs and blanks
 * are both legal, so show the bytes rather than %s.
 */
static void
showfield(char *label, char *p, int n)
{
	int i, printable;

	printf("  %-10s [", label);
	printable = 1;
	for(i = 0; i < n; i++){
		if(p[i] == '\0'){
			printf("\\0");
			printable = 0;
		}else if(p[i] == ' ')
			printf(" ");
		else if(p[i] < 32 || p[i] > 126){
			printf("\\x%02x", (unsigned char)p[i]);
			printable = 0;
		}else
			printf("%c", p[i]);
	}
	printf("]");
	if(!printable)
		printf("   (escapes shown; the field is not all printable)");
	printf("\n");
}

/*
 * Decode an octal field independently of tar. Deliberately simple and
 * deliberately NOT tar's from_header(): a probe that reuses the code
 * under suspicion cannot clear it.
 */
static long
octal(char *p, int n)
{
	long v;
	int i;

	v = 0;
	for(i = 0; i < n; i++){
		if(p[i] == ' ' || p[i] == '\0')
			continue;
		if(p[i] < '0' || p[i] > '7')
			return -1;
		v = v * 8 + (p[i] - '0');
	}
	return v;
}

/* The checksum is computed with the chksum field itself read as blanks. */
static long
checksum(unsigned char *b)
{
	long sum;
	int i;

	sum = 0;
	for(i = 0; i < BLOCKSIZE; i++)
		sum += (i >= 148 && i < 156) ? ' ' : b[i];
	return sum;
}

static int
iszero(unsigned char *b)
{
	int i;

	for(i = 0; i < BLOCKSIZE; i++)
		if(b[i] != 0)
			return 0;
	return 1;
}

static int
isustar(unsigned char *b)
{
	return memcmp(b + 257, "ustar", 5) == 0;
}

static void
dumpblock(unsigned char *b, int n)
{
	int i;

	printf("      first %d bytes:", n);
	for(i = 0; i < n; i++)
		printf(" %02x", b[i]);
	printf("\n      as text:      \"");
	for(i = 0; i < n; i++)
		printf("%c", (b[i] >= 32 && b[i] < 127) ? b[i] : '.');
	printf("\"\n");
}

int
main(int argc, char **argv)
{
	FILE *f;
	struct hdr *h;
	long blk, nblk, sz, datablks, want, got;
	long firstnonzero;
	int member;

	if(argc != 2){
		fprintf(stderr, "usage: tarhdr-probe file.tar\n");
		return 2;
	}
	f = fopen(argv[1], "rb");
	if(f == NULL){
		perror(argv[1]);
		return 2;
	}
	if(fseek(f, 0, SEEK_END) != 0){
		perror("fseek");
		return 2;
	}
	len = ftell(f);
	rewind(f);
	buf = malloc(len ? len : 1);
	if(buf == NULL){
		fprintf(stderr, "out of memory for %ld bytes\n", len);
		return 2;
	}
	if(fread(buf, 1, len, f) != (size_t)len){
		fprintf(stderr, "short read\n");
		return 2;
	}
	fclose(f);

	printf("file   %s\n", argv[1]);
	printf("size   %ld bytes = %ld blocks of 512, remainder %ld\n",
		len, len / BLOCKSIZE, len % BLOCKSIZE);
	printf("       %ld %%%% 10240 = %ld  (a tar written with the default\n",
		len, len % 10240);
	printf("       record size is a whole number of 10240-byte records)\n");
	if(len % BLOCKSIZE != 0)
		printf("NOTE   not a multiple of 512 -- the WRITER truncated it\n");
	printf("\n");

	nblk = len / BLOCKSIZE;
	blk = 0;
	member = 0;

	/*
	 * Walk member by member exactly as a reader must: header, then
	 * ceil(size/512) data blocks, then the next header. If the walk
	 * lands somewhere that is neither a header nor a zero block,
	 * THAT is the block tar is choking on, and this says which one
	 * and what is in it.
	 */
	while(blk < nblk){
		if(iszero(buf + blk * BLOCKSIZE)){
			/*
			 * Collapse the run. An end-of-archive pad is
			 * eighteen of these and printing them one to a
			 * line pushes the part that matters off a
			 * screenshot.
			 */
			long z = blk;
			while(z < nblk && iszero(buf + z * BLOCKSIZE))
				z++;
			printf("blocks %ld..%ld: ALL ZERO (%ld blocks)\n",
				blk, z - 1, z - blk);
			blk = z;
			continue;
		}
		if(!isustar(buf + blk * BLOCKSIZE)){
			printf("block %ld: NOT a ustar header and NOT zero"
				" -- this is what a reader would choke on\n", blk);
			dumpblock(buf + blk * BLOCKSIZE, 32);
			blk++;
			continue;
		}

		member++;
		h = (struct hdr *)(buf + blk * BLOCKSIZE);
		printf("block %ld: member %d, ustar header\n", blk, member);
		showfield("name", h->name, 32);
		showfield("size", h->size, 12);
		showfield("mtime", h->mtime, 12);
		showfield("chksum", h->chksum, 8);
		showfield("magic", h->magic, 6);
		showfield("version", h->version, 2);
		printf("  %-10s '%c' (0x%02x)\n", "typeflag",
			h->typeflag ? h->typeflag : '0',
			(unsigned char)h->typeflag);

		sz = octal(h->size, 12);
		want = octal(h->chksum, 8);
		got = checksum(buf + blk * BLOCKSIZE);
		printf("  decoded size   = %ld\n", sz);
		printf("  decoded chksum = %ld, computed = %ld  -- %s\n",
			want, got, want == got ? "MATCH" : "MISMATCH");
		if(sz < 0){
			printf("  size field does not decode as octal; stopping"
				" the walk here\n");
			break;
		}
		datablks = (sz + BLOCKSIZE - 1) / BLOCKSIZE;
		printf("  %ld data block%s, so the next header belongs"
			" at block %ld\n",
			datablks, datablks == 1 ? "" : "s", blk + 1 + datablks);
		if(datablks > 0){
			printf("    block %ld (the member's data):\n", blk + 1);
			dumpblock(buf + (blk + 1) * BLOCKSIZE, 16);
		}
		blk += 1 + datablks;
	}

	/*
	 * And the one summary line that decides which of (a) and (b) it
	 * is: where the last non-zero byte sits.
	 */
	firstnonzero = -1;
	for(blk = nblk - 1; blk >= 0; blk--)
		if(!iszero(buf + blk * BLOCKSIZE)){
			firstnonzero = blk;
			break;
		}
	printf("\nlast non-zero block is %ld; blocks %ld..%ld are all zero\n",
		firstnonzero, firstnonzero + 1, nblk - 1);
	printf("(an archive ending correctly has at least two zero blocks"
		" after its last member)\n");
	return 0;
}
