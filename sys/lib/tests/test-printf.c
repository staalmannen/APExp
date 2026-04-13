/*
 * test-printf.c - Test printf format specifiers one at a time.
 *
 * Each test is isolated so that a crash pinpoints exactly which specifier
 * (or which combination of width/precision/*) is the culprit.
 *
 * Compile: pcc -o test-printf test-printf.c
 * Run:     ./test-printf 2>&1 | head -40
 *
 * If the process crashes mid-run, the last "=== testing" line printed
 * before the crash identifies the failing case.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int fails = 0;

static void
check_str(const char *label, const char *got, const char *want)
{
    if (strcmp(got, want) != 0) {
        fprintf(stderr, "FAIL %-30s got=[%s] want=[%s]\n", label, got, want);
        fails++;
    } else {
        printf("PASS %s\n", label);
    }
}

int
main(void)
{
    char buf[256];

    /* ---- basic types ---- */
    printf("=== testing %%d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%d", 42);
    check_str("%d", buf, "42");

    printf("=== testing %%d negative\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%d", -1);
    check_str("%d neg", buf, "-1");

    printf("=== testing %%i\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%i", 100);
    check_str("%i", buf, "100");

    printf("=== testing %%u\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%u", 0xffffffffU);
    check_str("%u", buf, "4294967295");

    printf("=== testing %%o\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%o", 8);
    check_str("%o", buf, "10");

    printf("=== testing %%x\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%x", 255);
    check_str("%x", buf, "ff");

    printf("=== testing %%X\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%X", 255);
    check_str("%X", buf, "FF");

    printf("=== testing %%s\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%s", "hello");
    check_str("%s", buf, "hello");

    printf("=== testing %%c\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%c", 'A');
    check_str("%c", buf, "A");

    printf("=== testing %%p\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%p", (void *)0);
    /* just check it doesn't crash; content varies */
    printf("PASS %%p (value=%s)\n", buf);

    printf("=== testing %%f\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%.2f", 3.14);
    check_str("%f", buf, "3.14");

    printf("=== testing %%e\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%.2e", 31400.0);
    check_str("%e", buf, "3.14e+04");

    printf("=== testing %%g\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%.3g", 3.14);
    check_str("%g", buf, "3.14");

    /* ---- long / long long ---- */
    printf("=== testing %%ld\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%ld", 0x7fffffffL);
    check_str("%ld", buf, "2147483647");

    printf("=== testing %%lld\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%lld", 9000000000LL);
    check_str("%lld", buf, "9000000000");

    printf("=== testing %%lld negative\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%lld", -9000000000LL);
    check_str("%lld neg", buf, "-9000000000");

    /* ---- width and precision with literal numbers ---- */
    printf("=== testing %%8d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%8d", 42);
    check_str("%8d", buf, "      42");

    printf("=== testing %%-8d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%-8d", 42);
    check_str("%-8d", buf, "42      ");

    printf("=== testing %%08d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%08d", 42);
    check_str("%08d", buf, "00000042");

    printf("=== testing %%.5d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%.5d", 42);
    check_str("%.5d", buf, "00042");

    printf("=== testing %%8.5d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%8.5d", 42);
    check_str("%8.5d", buf, "   00042");

    /* ---- width and precision via * (the sbase printf pattern) ---- */
    printf("=== testing %%*d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%*d", 6, 42);
    check_str("%*d", buf, "    42");

    printf("=== testing %%.*d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%.*d", 5, 42);
    check_str("%.*d", buf, "00042");

    printf("=== testing %%*.*d\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%*.*d", 8, 5, 42);
    check_str("%*.*d", buf, "   00042");

    /* This exact call is what sbase printf emits for integer formats */
    printf("=== testing %%*.*lld (sbase printf pattern)\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%*.*lld", 8, 3, 42LL);
    check_str("%*.*lld", buf, "     042");

    printf("=== testing %%*.*lld negative\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%*.*lld", 0, -1, -99LL);
    check_str("%*.*lld neg", buf, "-99");

    printf("=== testing %%*.*s (sbase printf pattern)\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%*.*s", 8, 3, "hello");
    check_str("%*.*s", buf, "     hel");

    /* ---- multiple args in one call ---- */
    printf("=== testing multiple args\n"); fflush(stdout);
    snprintf(buf, sizeof buf, "%d %s %lld", 1, "two", 3LL);
    check_str("multi", buf, "1 two 3");

    /* ---- actual printf to stdout (not just snprintf) ---- */
    printf("=== testing printf to stdout with %%d\n"); fflush(stdout);
    printf("stdout %%d: %d\n", 12345);

    printf("=== testing printf to stdout with %%lld\n"); fflush(stdout);
    printf("stdout %%lld: %lld\n", 9876543210LL);

    printf("=== testing printf to stdout with %%*.*lld\n"); fflush(stdout);
    printf("stdout %%*.*lld: [%*.*lld]\n", 10, 4, 42LL);

    printf("=== done\n");
    fflush(stdout);

    if (fails)
        fprintf(stderr, "%d test(s) FAILED\n", fails);
    else
        printf("all printf tests passed\n");

    return fails ? 1 : 0;
}
