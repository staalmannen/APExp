/*
 * test-printf-float.c - Test float/double printf formats (%f, %g, %e, %a).
 *
 * sbase printf converts argv strings to doubles via strtod() then passes
 * them to printf().  This tests both the strtod path and the vfprintf
 * float-formatting code.
 *
 * Compile: pcc -o test-printf-float test-printf-float.c
 * Run:     ./test-printf-float
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int fails = 0;

/* Check that a printed string contains an expected substring */
static void
check(const char *label, const char *got, const char *want_substr)
{
    if(strstr(got, want_substr) == NULL){
        fprintf(stderr, "FAIL %s: got '%s' want substring '%s'\n",
                label, got, want_substr);
        fails++;
    } else {
        printf("PASS %s\n", label);
    }
}

/* Check prefix equality up to 'n' significant chars */
static void
checkn(const char *label, const char *got, const char *want, int n)
{
    if(strncmp(got, want, n) != 0){
        fprintf(stderr, "FAIL %s: got '%s' want '%s'\n", label, got, want);
        fails++;
    } else {
        printf("PASS %s\n", label);
    }
}

int
main(void)
{
    char buf[256];

    printf("=== strtod\n");
    {
        char *end;
        double v;
        v = strtod("3.14", &end);
        if(v < 3.13 || v > 3.15 || *end != '\0'){
            fprintf(stderr, "FAIL strtod(3.14): got %f end='%s'\n", v, end);
            fails++;
        } else {
            printf("PASS strtod 3.14\n");
        }
        v = strtod("-2.5e2", &end);
        if(v != -250.0 || *end != '\0'){
            fprintf(stderr, "FAIL strtod(-2.5e2): got %f\n", v);
            fails++;
        } else {
            printf("PASS strtod -2.5e2\n");
        }
        v = strtod("0.0", &end);
        if(v != 0.0){
            fprintf(stderr, "FAIL strtod(0.0): got %f\n", v);
            fails++;
        } else {
            printf("PASS strtod 0.0\n");
        }
        v = strtod("  42 rest", &end);
        if(v != 42.0 || strcmp(end, " rest") != 0){
            fprintf(stderr, "FAIL strtod with trailing: got %f end='%s'\n", v, end);
            fails++;
        } else {
            printf("PASS strtod trailing text\n");
        }
    }

    printf("=== %%f\n");
    snprintf(buf, sizeof buf, "%f", 3.14159);
    checkn("%%f 3.14159", buf, "3.14159", 7);

    snprintf(buf, sizeof buf, "%f", 0.0);
    check("%%f 0.0", buf, "0.000000");

    snprintf(buf, sizeof buf, "%f", -1.5);
    check("%%f -1.5", buf, "-1.500000");

    snprintf(buf, sizeof buf, "%.2f", 2.71828);
    check("%%f precision 2", buf, "2.72");

    snprintf(buf, sizeof buf, "%10.3f", 1.0);
    check("%%f width+prec", buf, "1.000");

    printf("=== %%g\n");
    snprintf(buf, sizeof buf, "%g", 1.0);
    check("%%g 1.0", buf, "1");

    snprintf(buf, sizeof buf, "%g", 123456.0);
    /* %g uses %e for large exponents (>= 6 sig digits) */
    check("%%g 123456", buf, "123456");

    snprintf(buf, sizeof buf, "%g", 1234567.0);
    check("%%g 1234567", buf, "1.23457e");

    snprintf(buf, sizeof buf, "%g", 0.0001);
    check("%%g 0.0001", buf, "0.0001");

    snprintf(buf, sizeof buf, "%g", 0.00001);
    check("%%g 0.00001 (switches to exp)", buf, "1e-05");

    snprintf(buf, sizeof buf, "%g", -3.14);
    check("%%g negative", buf, "-3.14");

    snprintf(buf, sizeof buf, "%.2g", 3.14159);
    check("%%g precision 2", buf, "3.1");

    printf("=== %%e\n");
    snprintf(buf, sizeof buf, "%e", 1.0);
    check("%%e 1.0", buf, "1.000000e+00");

    snprintf(buf, sizeof buf, "%e", -2.5e-10);
    check("%%e negative small", buf, "-2.500000e-10");

    snprintf(buf, sizeof buf, "%.2e", 6.022e23);
    check("%%e Avogadro .2", buf, "6.02e+23");

    printf("=== %%f with large/small values\n");
    snprintf(buf, sizeof buf, "%f", 1.0e6);
    check("%%f 1e6", buf, "1000000");

    snprintf(buf, sizeof buf, "%f", 1.0e-6);
    check("%%f 1e-6", buf, "0.000001");

    /* Very small */
    snprintf(buf, sizeof buf, "%.10f", 1.0e-10);
    check("%%f 1e-10 with prec", buf, "0.0000000001");

    printf("=== mixed %%g in one printf\n");
    snprintf(buf, sizeof buf, "%g %g %g", 1.0, 1000.0, 1e-5);
    check("mixed %%g", buf, "1 1000 1e-05");

    printf("=== %%g 0\n");
    snprintf(buf, sizeof buf, "%g", 0.0);
    check("%%g 0.0", buf, "0");

    printf("=== fprintf to stdout (no explicit fflush)\n");
    fprintf(stdout, "PASS fprintf-stdout-nofflush\n");
    /* deliberately no fflush here — relies on exit() cleanup */

    if(fails)
        fprintf(stderr, "%d test(s) FAILED\n", fails);
    else
        printf("all float-printf tests passed\n");

    return fails ? 1 : 0;
    /* exit() must flush stdout here */
}
