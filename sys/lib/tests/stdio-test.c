#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

/* ------------------------------------------------------------------ */
/* Minimal test harness                                                 */
/* ------------------------------------------------------------------ */

static int pass_count = 0;
static int fail_count = 0;

static void check(const char *name, int ok) {
	if (ok) {
		pass_count++;
		fprintf(stdout, "  PASS  %s\n", name);
	} else {
		fail_count++;
		fprintf(stdout, "  FAIL  %s\n", name);
	}
}

static void section(const char *title) {
	fprintf(stdout, "\n=== %s ===\n", title);
}

/* ------------------------------------------------------------------ */
/* 1. Basic file I/O                                                    */
/* ------------------------------------------------------------------ */

static void test_basic_file_io(void) {
	section("Basic file I/O");

	FILE *f = fopen("/tmp/apexp_test.txt", "w");
	check("fopen for write", f != NULL);
	if (!f) return;

	int n = fprintf(f, "line one\nline two\nline three\n");
	check("fprintf returns positive byte count", n > 0);
	fclose(f);

	f = fopen("/tmp/apexp_test.txt", "r");
	check("fopen for read", f != NULL);
	if (!f) return;

	char buf[64];
	check("fgets first line", fgets(buf, sizeof(buf), f) != NULL);
	check("fgets content matches", strcmp(buf, "line one\n") == 0);
	check("fgets second line", fgets(buf, sizeof(buf), f) != NULL);
	check("fgets content matches", strcmp(buf, "line two\n") == 0);
	check("fgets third line", fgets(buf, sizeof(buf), f) != NULL);
	check("fgets EOF after last line", fgets(buf, sizeof(buf), f) == NULL);
	check("feof set", feof(f));
	fclose(f);

	remove("/tmp/apexp_test.txt");
}

/* ------------------------------------------------------------------ */
/* 2. printf format strings                                             */
/* ------------------------------------------------------------------ */

static void test_printf_formats(void) {
	section("printf format strings");

	char buf[256];

	/* integers */
	snprintf(buf, sizeof(buf), "%d", 42);
	check("%%d basic", strcmp(buf, "42") == 0);

	snprintf(buf, sizeof(buf), "%05d", 42);
	check("%%05d zero-pad", strcmp(buf, "00042") == 0);

	snprintf(buf, sizeof(buf), "%-8d|", 42);
	check("%%-8d left-align", strcmp(buf, "42      |") == 0);

	snprintf(buf, sizeof(buf), "%x", 255);
	check("%%x hex", strcmp(buf, "ff") == 0);

	snprintf(buf, sizeof(buf), "%X", 255);
	check("%%X HEX", strcmp(buf, "FF") == 0);

	snprintf(buf, sizeof(buf), "%o", 8);
	check("%%o octal", strcmp(buf, "10") == 0);

	snprintf(buf, sizeof(buf), "%u", (unsigned)-1);
	check("%%u max uint", strlen(buf) > 0);  /* just check it doesn't crash */

	/* long long */
	snprintf(buf, sizeof(buf), "%lld", (long long)9000000000LL);
	check("%%lld", strcmp(buf, "9000000000") == 0);

	snprintf(buf, sizeof(buf), "%llu", (unsigned long long)18446744073709551615ULL);
	check("%%llu ULLONG_MAX", strcmp(buf, "18446744073709551615") == 0);

	/* strings and chars */
	snprintf(buf, sizeof(buf), "%s", "hello");
	check("%%s basic", strcmp(buf, "hello") == 0);

	snprintf(buf, sizeof(buf), "%.3s", "hello");
	check("%%.3s precision", strcmp(buf, "hel") == 0);

	snprintf(buf, sizeof(buf), "%c", 'A');
	check("%%c", strcmp(buf, "A") == 0);

	/* floats — exercises _dtoa/_fconv */
	snprintf(buf, sizeof(buf), "%f", 3.14159);
	check("%%f pi", strncmp(buf, "3.14159", 7) == 0);

	snprintf(buf, sizeof(buf), "%.2f", 3.14159);
	check("%%.2f rounded", strcmp(buf, "3.14") == 0);

	snprintf(buf, sizeof(buf), "%e", 12345.6789);
	check("%%e scientific", buf[0] != '\0' && strchr(buf, 'e') != NULL);

	/* %g uses scientific notation when exponent < -4 (i.e. <= -5).
	 * 0.000012345 = 1.2345e-5 → exponent -5 < -4 → should produce 'e'. */
	snprintf(buf, sizeof(buf), "%g", 0.000012345);
	check("%%g small number", strchr(buf, 'e') != NULL);

	snprintf(buf, sizeof(buf), "%g", 123456.0);
	check("%%g large number non-empty", strlen(buf) > 0);

	snprintf(buf, sizeof(buf), "%f", 0.0);
	check("%%f zero", strcmp(buf, "0.000000") == 0);

	snprintf(buf, sizeof(buf), "%f", -1.5);
	check("%%f negative", strcmp(buf, "-1.500000") == 0);

	/* %n */
	int pos = 0;
	snprintf(buf, sizeof(buf), "abc%n", &pos);
	check("%%n position", pos == 3);

	/* pointer */
	void *p = (void*)0x1234;
	snprintf(buf, sizeof(buf), "%p", p);
	check("%%p non-empty", strlen(buf) > 0);
}

/* ------------------------------------------------------------------ */
/* 3. scanf / sscanf                                                    */
/* ------------------------------------------------------------------ */

static void test_scanf(void) {
	section("scanf / sscanf");

	int i;
	float f;
	char s[32];

	check("sscanf int", sscanf("42", "%d", &i) == 1 && i == 42);
	check("sscanf negative int", sscanf("-7", "%d", &i) == 1 && i == -7);
	check("sscanf hex", sscanf("ff", "%x", &i) == 1 && i == 255);
	check("sscanf float", sscanf("3.14", "%f", &f) == 1 && fabsf(f - 3.14f) < 0.001f);
	check("sscanf string", sscanf("hello", "%s", s) == 1 && strcmp(s, "hello") == 0);

	int a, b;
	check("sscanf two ints", sscanf("10 20", "%d %d", &a, &b) == 2 && a == 10 && b == 20);

	long long ll;
	check("sscanf lld", sscanf("9000000000", "%lld", &ll) == 1 && ll == 9000000000LL);

	/* partial match returns count */
	check("sscanf partial match", sscanf("abc", "%d", &i) == 0);

	/* field width */
	check("sscanf field width", sscanf("123456", "%3d", &i) == 1 && i == 123);

	/* scanf from file */
	FILE *fp = fopen("/tmp/apexp_scanf.txt", "w");
	if (fp) {
		fprintf(fp, "99 world\n");
		fclose(fp);
		fp = fopen("/tmp/apexp_scanf.txt", "r");
		if (fp) {
			check("fscanf int+string",
				fscanf(fp, "%d %s", &i, s) == 2 && i == 99 && strcmp(s, "world") == 0);
			fclose(fp);
		}
		remove("/tmp/apexp_scanf.txt");
	}
}

/* ------------------------------------------------------------------ */
/* 4. fread / fwrite binary I/O                                         */
/* ------------------------------------------------------------------ */

static void test_binary_io(void) {
	section("Binary fread/fwrite");

	unsigned char data[256];
	for (int k = 0; k < 256; k++) data[k] = (unsigned char)k;

	FILE *f = fopen("/tmp/apexp_bin.dat", "wb");
	check("fopen binary write", f != NULL);
	if (!f) return;

	size_t written = fwrite(data, 1, 256, f);
	check("fwrite 256 bytes", written == 256);
	fclose(f);

	f = fopen("/tmp/apexp_bin.dat", "rb");
	check("fopen binary read", f != NULL);
	if (!f) { remove("/tmp/apexp_bin.dat"); return; }

	unsigned char readback[256];
	size_t got = fread(readback, 1, 256, f);
	check("fread 256 bytes", got == 256);

	int ok = 1;
	for (int k = 0; k < 256; k++)
		if (readback[k] != (unsigned char)k) { ok = 0; break; }
	check("binary round-trip all bytes correct", ok);
	fclose(f);
	remove("/tmp/apexp_bin.dat");
}

/* ------------------------------------------------------------------ */
/* 5. fseek / ftell / rewind                                            */
/* ------------------------------------------------------------------ */

static void test_seek(void) {
	section("fseek / ftell / rewind");

	FILE *f = fopen("/tmp/apexp_seek.txt", "w+");
	check("fopen w+", f != NULL);
	if (!f) return;

	fputs("ABCDEFGHIJ", f);

	check("ftell after write", ftell(f) == 10);

	rewind(f);
	check("ftell after rewind", ftell(f) == 0);

	fseek(f, 5, SEEK_SET);
	check("ftell after SEEK_SET 5", ftell(f) == 5);

	int c = fgetc(f);
	check("fgetc at pos 5 is 'F'", c == 'F');

	fseek(f, -1, SEEK_END);
	check("ftell after SEEK_END -1", ftell(f) == 9);
	c = fgetc(f);
	check("fgetc at last pos is 'J'", c == 'J');

	fseek(f, 3, SEEK_SET);
	fseek(f, 2, SEEK_CUR);
	check("ftell after SEEK_CUR", ftell(f) == 5);

	fclose(f);
	remove("/tmp/apexp_seek.txt");
}

/* ------------------------------------------------------------------ */
/* 6. ungetc                                                            */
/* ------------------------------------------------------------------ */

static void test_ungetc(void) {
	section("ungetc");

	FILE *f = fopen("/tmp/apexp_ungetc.txt", "w+");
	check("fopen for ungetc test", f != NULL);
	if (!f) return;

	fputs("hello", f);
	rewind(f);

	int c = fgetc(f);
	check("fgetc first char 'h'", c == 'h');

	int r = ungetc(c, f);
	check("ungetc returns char", r == 'h');

	c = fgetc(f);
	check("fgetc after ungetc gets same char", c == 'h');

	/* ungetc of a different character */
	c = fgetc(f);  /* 'e' */
	ungetc('X', f);
	c = fgetc(f);
	check("ungetc different char", c == 'X');

	fclose(f);
	remove("/tmp/apexp_ungetc.txt");
}

/* ------------------------------------------------------------------ */
/* 7. getdelim / getline                                                */
/* ------------------------------------------------------------------ */

static void test_getdelim(void) {
	section("getdelim / getline");

	FILE *f = fopen("/tmp/apexp_lines.txt", "w");
	check("fopen for getdelim test", f != NULL);
	if (!f) return;
	fputs("alpha\nbeta\ngamma\n", f);
	fclose(f);

	f = fopen("/tmp/apexp_lines.txt", "r");
	check("fopen for read", f != NULL);
	if (!f) { remove("/tmp/apexp_lines.txt"); return; }

	char *line = NULL;
	size_t cap = 0;
	ssize_t len;

	len = getline(&line, &cap, f);
	check("getline first line length", len == 6);
	check("getline first line content", line && strcmp(line, "alpha\n") == 0);

	len = getline(&line, &cap, f);
	check("getline second line", len == 5 && line && strcmp(line, "beta\n") == 0);

	len = getline(&line, &cap, f);
	check("getline third line", len == 6 && line && strcmp(line, "gamma\n") == 0);

	len = getline(&line, &cap, f);
	check("getline EOF returns -1", len == -1);

	free(line);
	fclose(f);

	/* getdelim with custom delimiter */
	f = fopen("/tmp/apexp_lines.txt", "r");
	if (f) {
		line = NULL; cap = 0;
		len = getdelim(&line, &cap, 'a', f);
		check("getdelim up to 'a'", len > 0 && line && line[len-1] == 'a');
		free(line);
		fclose(f);
	}

	remove("/tmp/apexp_lines.txt");
}

/* ------------------------------------------------------------------ */
/* 8. fmemopen / open_memstream                                         */
/* ------------------------------------------------------------------ */

static void test_memory_streams(void) {
	section("fmemopen / open_memstream");

	/* fmemopen read */
	const char *src = "hello memory";
	FILE *f = fmemopen((void*)src, strlen(src), "r");
	check("fmemopen read open", f != NULL);
	if (f) {
		char buf[32] = {0};
		fread(buf, 1, 5, f);
		check("fmemopen fread", strcmp(buf, "hello") == 0);
		fclose(f);
	}

	/* fmemopen write into buffer */
	char mbuf[64] = {0};
	f = fmemopen(mbuf, sizeof(mbuf), "w");
	check("fmemopen write open", f != NULL);
	if (f) {
		fprintf(f, "val=%d", 99);
		fclose(f);
		check("fmemopen fprintf result", strcmp(mbuf, "val=99") == 0);
	}

	/* open_memstream */
	char *ptr = NULL;
	size_t sz = 0;
	f = open_memstream(&ptr, &sz);
	check("open_memstream open", f != NULL);
	if (f) {
		fprintf(f, "dynamic %d", 42);
		fclose(f);
		check("open_memstream content", ptr && strcmp(ptr, "dynamic 42") == 0);
		check("open_memstream size", sz == strlen("dynamic 42"));
		free(ptr);
	}
}

/* ------------------------------------------------------------------ */
/* 9. setvbuf / setbuf buffering modes                                  */
/* ------------------------------------------------------------------ */

static void test_buffering(void) {
	section("setvbuf buffering modes");

	/* unbuffered */
	FILE *f = fopen("/tmp/apexp_buf.txt", "w");
	check("fopen for setvbuf test", f != NULL);
	if (!f) return;
	check("setvbuf unbuffered ok", setvbuf(f, NULL, _IONBF, 0) == 0);
	fputs("unbuffered\n", f);
	fclose(f);

	/* line buffered */
	f = fopen("/tmp/apexp_buf.txt", "w");
	if (f) {
		setvbuf(f, NULL, _IOLBF, 128);
		fputs("linebuf\n", f);
		fclose(f);
	}

	/* fully buffered with caller-supplied buffer */
	char fbuf[256];
	f = fopen("/tmp/apexp_buf.txt", "w");
	if (f) {
		check("setvbuf full buffered ok", setvbuf(f, fbuf, _IOFBF, sizeof(fbuf)) == 0);
		fputs("fullbuf\n", f);
		fclose(f);
	}

	/* verify last write is readable */
	f = fopen("/tmp/apexp_buf.txt", "r");
	if (f) {
		char rbuf[32];
		check("buffered write flushed on close", fgets(rbuf, sizeof(rbuf), f) != NULL);
		fclose(f);
	}

	remove("/tmp/apexp_buf.txt");
}

/* ------------------------------------------------------------------ */
/* 10. perror / ferror / clearerr                                       */
/* ------------------------------------------------------------------ */

static void test_error_handling(void) {
	section("perror / ferror / clearerr");

	FILE *f = fopen("/tmp/apexp_err.txt", "w");
	check("fopen ok", f != NULL);
	if (!f) return;

	/* write to a write-only file then try to read */
	check("ferror initially clear", ferror(f) == 0);
	fread(NULL, 1, 0, f);  /* noop, should not set error */

	fclose(f);

	/* open read-only and try to write */
	f = fopen("/tmp/apexp_err.txt", "r");
	if (f) {
		fputc('x', f);
		check("ferror set after write to read-only", ferror(f) != 0);
		clearerr(f);
		check("clearerr clears ferror", ferror(f) == 0);
		check("clearerr clears feof", feof(f) == 0);
		fclose(f);
	}

	remove("/tmp/apexp_err.txt");
}

/* ------------------------------------------------------------------ */
/* 11. flockfile / funlockfile / ftrylockfile                           */
/* ------------------------------------------------------------------ */

static void test_flockfile(void) {
	section("flockfile / funlockfile / ftrylockfile");

	/* Basic: lock stdout, write, unlock — must not deadlock */
	flockfile(stdout);
	fputs("  (locked write)\n", stdout);
	funlockfile(stdout);
	check("flockfile/funlockfile did not deadlock", 1);

	/* Recursive lock: second flockfile from same thread must not deadlock
	 * (requires PTHREAD_MUTEX_RECURSIVE in __fdopen) */
	flockfile(stdout);
	flockfile(stdout);
	funlockfile(stdout);
	funlockfile(stdout);
	check("recursive flockfile did not deadlock", 1);

	/* ftrylockfile: first call should succeed (returns 0) */
	int r = ftrylockfile(stdout);
	check("ftrylockfile acquires lock (returns 0)", r == 0);
	if (r == 0) funlockfile(stdout);
}

/* ------------------------------------------------------------------ */
/* 12. popen / pclose                                                   */
/* ------------------------------------------------------------------ */

static void test_popen(void) {
	section("popen / pclose");

	FILE *p = popen("echo popen_works", "r");
	check("popen open", p != NULL);
	if (!p) return;

	char buf[64] = {0};
	fgets(buf, sizeof(buf), p);
	/* trim trailing newline */
	buf[strcspn(buf, "\r\n")] = '\0';
	check("popen read output", strcmp(buf, "popen_works") == 0);

	int rc = pclose(p);
	check("pclose returns 0", rc == 0);
}

/* ------------------------------------------------------------------ */
/* 13. sprintf / snprintf edge cases                                    */
/* ------------------------------------------------------------------ */

static void test_snprintf_edge(void) {
	section("snprintf edge cases");

	char buf[8];

	/* truncation: snprintf must NUL-terminate and return full length */
	int r = snprintf(buf, 8, "123456789");
	check("snprintf truncates", strcmp(buf, "1234567") == 0);
	check("snprintf returns full length", r == 9);

	/* zero-size buffer: must not write, return length */
	r = snprintf(NULL, 0, "hello %d", 5);
	check("snprintf NULL buf returns length", r == 7);

	/* %% literal */
	snprintf(buf, sizeof(buf), "100%%");
	check("snprintf %%", strcmp(buf, "100%") == 0);
}

/* ------------------------------------------------------------------ */
/* main                                                                 */
/* ------------------------------------------------------------------ */

int main(void) {
	fprintf(stdout, "APExp stdio test suite\n");

	test_basic_file_io();
	test_printf_formats();
	test_scanf();
	test_binary_io();
	test_seek();
	test_ungetc();
	test_getdelim();
	test_memory_streams();
	test_buffering();
	test_error_handling();
	test_flockfile();
	test_popen();
	test_snprintf_edge();

	fprintf(stdout, "\nResults: %d passed, %d failed\n", pass_count, fail_count);
	return fail_count ? 1 : 0;
}
