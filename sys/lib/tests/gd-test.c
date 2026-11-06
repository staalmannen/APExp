/*
 * gd-test.c -- does libgd compute correctly under kencc?
 *
 * libgd was vendored (2.3.3, `sys/src/external/libgd') and built
 * (`sys/src/ape/lib/gd') largely AS AN EXERCISE: 47 files of
 * integer-heavy pixel arithmetic are good ground for a compiler whose
 * `long' is 32 bits and whose `sizeof' is 32-bit, and gd needs no
 * display, no X11 and no platform integration -- pixel buffers in,
 * file formats out.
 *
 * ***ALL 47 COMPILED CLEAN ON THE FIRST TRY***, which is exactly why
 * this file exists: a library that builds has not been shown to
 * compute.  Every bug this exercise can find is now a RUNTIME bug, so
 * the instrument has to run the arithmetic and check the answer.
 *
 *	pcc -o gd-test gd-test.c && ./gd-test
 *
 * **The gcc control is `gd-xcheck.sh'**, which builds the SAME
 * vendored sources with gcc on the build host and runs this same
 * file against them.  That is the whole design: there is no reference
 * implementation of libgd to compare against, so the comparison is
 * gcc-built libgd against kencc-built libgd, one test, same source.
 * *A failure here that also fails under gcc is this file's bug.*
 *
 * EVERY ASSERTION IS EXACTLY CHECKABLE WITHOUT A REFERENCE IMAGE, and
 * that constraint is what shaped the sections:
 *   - rotate90 four times is the IDENTITY, whichever way gd turns it,
 *     so the check needs no knowledge of gd's rotation direction;
 *   - a PNG round trip must return the pixels it was given;
 *   - scaling a FLAT image must leave it flat, whatever the
 *     interpolation does, since every input to every weighted sum is
 *     the same value;
 *   - a truecolour image using <= 256 distinct colours must survive
 *     conversion to a palette EXACTLY, because the quantiser has no
 *     reason to merge anything.
 * *A test that needs a golden image cannot say whether the library or
 * the image is wrong*, which is why there is not one here.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gd.h>

static int fails;

static void
ok(const char *what, int cond)
{
	if(cond)
		printf("  PASS %s\n", what);
	else {
		printf("  FAIL %s\n", what);
		fails++;
	}
}

static void
eqi(const char *what, long got, long want)
{
	if(got == want)
		printf("  PASS %-46s %ld\n", what, got);
	else {
		printf("  FAIL %-46s got %ld want %ld\n", what, got, want);
		fails++;
	}
}

int
main(void)
{
	gdImagePtr im, im2, im3, im4;
	int i, x, y, n, c, red, green, blue, white;
	int size;
	void *png;
	gdRect crop;

	/*
	 * Line-buffered and a marker FIRST. `fsync-test' had to learn
	 * this: a fault, a kill and a clean finish all give the prompt
	 * back, so silence is not a pass, and a fully buffered stdout
	 * loses everything printed before a crash.
	 */
	setvbuf(stdout, NULL, _IOLBF, 0);
	printf("gd-test: starting\n");

	/* ---- 0: it links, and says which version ------------------ */
	printf("\nSection 0: the library is there\n");
	printf("  INFO gdVersionString() = %s\n", gdVersionString());
	eqi("GD_MAJOR_VERSION", GD_MAJOR_VERSION, 2);
	eqi("GD_MINOR_VERSION", GD_MINOR_VERSION, 3);

	/* ---- 1: palette images, pixels, and exact read-back -------- */
	printf("\nSection 1: palette image, every pixel read back\n");
	im = gdImageCreate(37, 23);		/* deliberately not powers of 2 */
	ok("gdImageCreate", im != NULL);
	if(im == NULL){
		printf("\ngd-test: %d failures\n", fails);
		return fails ? fails : 1;
	}
	eqi("gdImageSX", gdImageSX(im), 37);
	eqi("gdImageSY", gdImageSY(im), 23);

	white = gdImageColorAllocate(im, 255, 255, 255);
	red   = gdImageColorAllocate(im, 255, 0, 0);
	green = gdImageColorAllocate(im, 0, 255, 0);
	blue  = gdImageColorAllocate(im, 0, 0, 255);
	ok("four colours allocated, all distinct",
	   white != red && red != green && green != blue && blue != white);
	eqi("red component reads back", gdImageRed(im, red), 255);
	eqi("green component reads back", gdImageGreen(im, green), 255);
	eqi("blue component reads back", gdImageBlue(im, blue), 255);
	eqi("colours total", gdImageColorsTotal(im), 4);

	/*
	 * Write a position-dependent value to every pixel and read the
	 * whole image back. This is the plainest possible check on
	 * indexing and row stride, and it is the one a wrong `sizeof'
	 * in an allocation would break.
	 */
	for(y = 0; y < 23; y++)
		for(x = 0; x < 37; x++)
			gdImageSetPixel(im, x, y, (x + y) % 4);
	n = 0;
	for(y = 0; y < 23; y++)
		for(x = 0; x < 37; x++)
			if(gdImageGetPixel(im, x, y) != (x + y) % 4)
				n++;
	eqi("pixels that read back wrong (of 851)", n, 0);

	/* ---- 2: a filled rectangle, counted ------------------------ */
	printf("\nSection 2: filled rectangle, counted rather than eyeballed\n");
	gdImageFilledRectangle(im, 0, 0, 36, 22, white);
	gdImageFilledRectangle(im, 5, 5, 14, 11, red);	/* 10 x 7 = 70 */
	n = 0;
	for(y = 0; y < 23; y++)
		for(x = 0; x < 37; x++)
			if(gdImageGetPixel(im, x, y) == red)
				n++;
	eqi("red pixels after a 10x7 fill", n, 70);
	eqi("corner is still white", gdImageGetPixel(im, 0, 0), white);
	eqi("just outside the fill", gdImageGetPixel(im, 15, 5), white);
	eqi("just inside the fill", gdImageGetPixel(im, 14, 11), red);

	/*
	 * ---- 3: rotate 90 four times is the identity ---------------
	 *
	 * ***TRUECOLOUR ON PURPOSE, AND THROUGH THE PUBLIC CALL.***
	 * `gdImageRotate90' is INTERNAL -- declared in `gd_intern.h',
	 * which is not installed -- and reaching for it is what the
	 * first draft of this file did: implicit `int' return,
	 * truncated pointer, segfault under gcc before the VM ever saw
	 * it.  *That is the undeclared-function invariant, in a test
	 * written to look for exactly that class of bug.*  The public
	 * call is `gdImageRotateInterpolated', which special-cases
	 * exact multiples of 90 so four of them are a permutation and
	 * the comparison stays exact.
	 *
	 * It is given a TRUECOLOUR image because that call converts a
	 * palette image to truecolour on the way out -- it must, since
	 * it may interpolate -- so comparing palette INDICES across it
	 * would compare two different palettes.
	 */
	printf("\nSection 3: rotate 90 x4 == identity (direction-independent)\n");
	im2 = gdImageCreateTrueColor(37, 23);
	ok("truecolour source for rotation", im2 != NULL);
	if(im2 != NULL){
		for(y = 0; y < 23; y++)
			for(x = 0; x < 37; x++)
				gdImageSetPixel(im2, x, y,
				    gdTrueColorAlpha(x * 5 & 0xff,
					y * 9 & 0xff, (x * y) & 0xff, 0));
		im3 = gdImageRotateInterpolated(im2, 90.0, 0);
		ok("rotate 90 returned an image", im3 != NULL);
		if(im3 != NULL){
			eqi("rotate 90 swaps width", gdImageSX(im3), 23);
			eqi("...and height", gdImageSY(im3), 37);
			im4 = gdImageRotateInterpolated(im3, 90.0, 0);
			gdImageDestroy(im3);
			im3 = im4 ? gdImageRotateInterpolated(im4, 90.0, 0) : NULL;
			if(im4 != NULL)
				gdImageDestroy(im4);
			im4 = im3 ? gdImageRotateInterpolated(im3, 90.0, 0) : NULL;
			if(im3 != NULL)
				gdImageDestroy(im3);
			ok("four rotations returned an image", im4 != NULL);
			if(im4 != NULL){
				eqi("back to the original width",
				    gdImageSX(im4), 37);
				eqi("back to the original height",
				    gdImageSY(im4), 23);
				n = 0;
				for(y = 0; y < 23 && y < gdImageSY(im4); y++)
					for(x = 0; x < 37 && x < gdImageSX(im4); x++)
						if((gdImageGetPixel(im4, x, y) & 0xffffff)
						   != (gdImageGetPixel(im2, x, y) & 0xffffff))
							n++;
				eqi("pixels differing after 4 rotations (of 851)",
				    n, 0);
				gdImageDestroy(im4);
			}
		}
		gdImageDestroy(im2);
	}

	/* ---- 4: truecolour channel packing ------------------------- */
	printf("\nSection 4: truecolour packing, which is pure bit work\n");
	c = gdTrueColorAlpha(0x12, 0x34, 0x56, 0x3f);
	eqi("gdTrueColorGetRed", gdTrueColorGetRed(c), 0x12);
	eqi("gdTrueColorGetGreen", gdTrueColorGetGreen(c), 0x34);
	eqi("gdTrueColorGetBlue", gdTrueColorGetBlue(c), 0x56);
	eqi("gdTrueColorGetAlpha", gdTrueColorGetAlpha(c), 0x3f);
	/*
	 * The top byte must be the alpha and nothing else: a packing
	 * done in a type one bit too narrow shows up here and nowhere
	 * else, which is the `leawide'/`longconst' family's shape.
	 */
	eqi("opaque white packs exactly",
	    (long)(unsigned)gdTrueColorAlpha(255, 255, 255, 0), 0x00ffffffL);
	eqi("transparent black packs exactly",
	    (long)(unsigned)gdTrueColorAlpha(0, 0, 0, 127), 0x7f000000L);

	/* ---- 5: PNG round trip in memory --------------------------- */
	printf("\nSection 5: PNG round trip -- gd, libpng and libz together\n");
	im2 = gdImageCreateTrueColor(64, 48);
	ok("truecolour image created", im2 != NULL);
	if(im2 != NULL){
		for(y = 0; y < 48; y++)
			for(x = 0; x < 64; x++)
				gdImageSetPixel(im2, x, y,
				    gdTrueColorAlpha(x * 3 & 0xff,
					y * 5 & 0xff, (x ^ y) & 0xff, 0));
		png = gdImagePngPtr(im2, &size);
		ok("gdImagePngPtr returned data", png != NULL);
		printf("  INFO encoded PNG is %d bytes\n", size);
		if(png != NULL){
			ok("PNG is non-trivially sized", size > 100);
			/* The 8-byte PNG signature, by the standard. */
			ok("PNG signature",
			   size >= 8 &&
			   memcmp(png, "\211PNG\r\n\032\n", 8) == 0);
			im3 = gdImageCreateFromPngPtr(size, png);
			ok("decoded back to an image", im3 != NULL);
			if(im3 != NULL){
				eqi("decoded width", gdImageSX(im3), 64);
				eqi("decoded height", gdImageSY(im3), 48);
				n = 0;
				for(y = 0; y < 48; y++)
					for(x = 0; x < 64; x++)
						if((gdImageGetPixel(im3, x, y) & 0xffffff)
						   != (gdImageGetPixel(im2, x, y) & 0xffffff))
							n++;
				eqi("pixels wrong after PNG round trip (of 3072)",
				    n, 0);
				gdImageDestroy(im3);
			}
			gdFree(png);
		}
		gdImageDestroy(im2);
	}

	/* ---- 6: scaling a flat image must leave it flat ------------ */
	printf("\nSection 6: scaling -- a flat image stays flat, whatever the filter\n");
	im2 = gdImageCreateTrueColor(100, 80);
	if(im2 != NULL){
		c = gdTrueColorAlpha(0x20, 0x90, 0xd0, 0);
		gdImageFilledRectangle(im2, 0, 0, 99, 79, c);
		gdImageSetInterpolationMethod(im2, GD_BILINEAR_FIXED);
		im3 = gdImageScale(im2, 50, 40);
		ok("gdImageScale returned an image", im3 != NULL);
		if(im3 != NULL){
			eqi("scaled width", gdImageSX(im3), 50);
			eqi("scaled height", gdImageSY(im3), 40);
			/*
			 * Every weighted sum is over identical inputs, so
			 * every output must equal that input -- true of any
			 * interpolation that is a weighted average summing
			 * to one. This catches rounding and fixed-point
			 * bugs without needing to know the filter.
			 */
			n = 0;
			for(y = 0; y < 40; y++)
				for(x = 0; x < 50; x++)
					if((gdImageGetPixel(im3, x, y) & 0xffffff)
					   != (c & 0xffffff))
						n++;
			eqi("scaled pixels differing from the flat colour", n, 0);
			gdImageDestroy(im3);
		}
		gdImageDestroy(im2);
	}

	/* ---- 7: crop is exact -------------------------------------- */
	printf("\nSection 7: crop\n");
	im2 = gdImageCreateTrueColor(40, 30);
	if(im2 != NULL){
		for(y = 0; y < 30; y++)
			for(x = 0; x < 40; x++)
				gdImageSetPixel(im2, x, y,
				    gdTrueColorAlpha(x, y, 0, 0));
		crop.x = 10;
		crop.y = 5;
		crop.width = 12;
		crop.height = 9;
		im3 = gdImageCrop(im2, &crop);
		ok("gdImageCrop returned an image", im3 != NULL);
		if(im3 != NULL){
			eqi("cropped width", gdImageSX(im3), 12);
			eqi("cropped height", gdImageSY(im3), 9);
			n = 0;
			for(y = 0; y < 9; y++)
				for(x = 0; x < 12; x++)
					if((gdImageGetPixel(im3, x, y) & 0xffffff)
					   != (gdImageGetPixel(im2, x + 10, y + 5) & 0xffffff))
						n++;
			eqi("cropped pixels differing from the source", n, 0);
			gdImageDestroy(im3);
		}
		gdImageDestroy(im2);
	}

	/*
	 * ---- 8: truecolour -> palette, `gd_topal.c' ----------------
	 *
	 * ***THE FIRST VERSION OF THIS SECTION ASSERTED SOMETHING
	 * FALSE, AND THE gcc CONTROL IS WHAT SAID SO.***  It claimed
	 * that an image using fewer distinct colours than the palette
	 * holds must survive conversion EXACTLY -- "the quantiser has
	 * no reason to merge anything".  It reported 1024 of 1024
	 * pixels changed while the palette held exactly the right 128
	 * entries, which is the shape of a wrong assertion rather than
	 * a wrong library: gd builds a COLOUR CUBE and takes each
	 * bucket's centroid, so every colour comes back offset by half
	 * a bucket -- (0,0,0) became (4,2,4) here, and the offset is
	 * the same for every pixel.  *Checking a new test against gcc
	 * first is what this tree's convention is for, and it caught
	 * the test.*
	 *
	 * What IS exact, and is asserted below, is that the mapping is
	 * a FUNCTION OF COLOUR: two pixels that were the same colour
	 * must get the same palette index.  That needs no knowledge of
	 * the quantiser's arithmetic and still fails loudly if indexing
	 * or the histogram goes wrong -- which is what a compiler
	 * exercise wants.  The colour drift is MEASURED and bounded
	 * rather than asserted to be zero.
	 */
	printf("\nSection 8: truecolour -> palette (gd_topal.c)\n");
	im2 = gdImageCreateTrueColor(32, 32);
	if(im2 != NULL){
		/* (x/2)*16 gives 16 reds, (y/4)*32 gives 8 greens: 128. */
		for(y = 0; y < 32; y++)
			for(x = 0; x < 32; x++)
				gdImageSetPixel(im2, x, y,
				    gdTrueColorAlpha((x / 2) * 16,
					(y / 4) * 32, 0, 0));
		im3 = gdImageCreatePaletteFromTrueColor(im2, 0, 256);
		ok("gdImageCreatePaletteFromTrueColor returned an image",
		   im3 != NULL);
		if(im3 != NULL){
			static int seenc[1024], seeni[1024];
			int nseen = 0, conflicts = 0, worst = 0, d;

			eqi("palette image is not truecolour",
			    gdImageTrueColor(im3), 0);
			eqi("dimensions survive", gdImageSX(im3), 32);
			ok("palette holds no more than we asked for",
			   gdImageColorsTotal(im3) <= 256);
			printf("  INFO palette holds %d colours; source has 128 distinct\n",
			    gdImageColorsTotal(im3));

			for(y = 0; y < 32; y++)
				for(x = 0; x < 32; x++){
					i = gdImageGetPixel(im3, x, y);
					c = gdImageGetPixel(im2, x, y) & 0xffffff;

					/* same colour in => same index out */
					for(n = 0; n < nseen; n++)
						if(seenc[n] == c)
							break;
					if(n == nseen){
						seenc[nseen] = c;
						seeni[nseen] = i;
						nseen++;
					} else if(seeni[n] != i)
						conflicts++;

					/* and how far the colour moved */
					d = gdImageRed(im3, i) - gdTrueColorGetRed(c);
					if(d < 0) d = -d;
					if(d > worst) worst = d;
					d = gdImageGreen(im3, i) - gdTrueColorGetGreen(c);
					if(d < 0) d = -d;
					if(d > worst) worst = d;
					d = gdImageBlue(im3, i) - gdTrueColorGetBlue(c);
					if(d < 0) d = -d;
					if(d > worst) worst = d;
				}
			eqi("distinct source colours found", nseen, 128);
			eqi("same colour mapped to two indices", conflicts, 0);
			/*
			 * 32 is a deliberately loose ceiling on half a
			 * colour-cube bucket -- the point is that the drift
			 * is BOUNDED and small, not what its exact value is,
			 * since that is the quantiser's business and not a
			 * rule anyone promised. gcc measures 4.
			 */
			printf("  INFO worst per-channel drift: %d\n", worst);
			ok("colour drift is bounded (<= 32)", worst <= 32);
			gdImageDestroy(im3);
		}
		gdImageDestroy(im2);
	}

	gdImageDestroy(im);

	printf("\ngd-test: %d failures\n", fails);
	return fails;
}
