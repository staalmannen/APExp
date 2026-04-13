/*
 * test-termcap.c - Test termcap functions and terminal raw-mode setup,
 *                  isolating what readline does during initialisation.
 *
 * Readline init sequence (simplified):
 *   1. tgetent(bp, $TERM)        -- load terminal entry
 *   2. tgetstr("cm", &area)      -- cursor-motion string
 *   3. tgetstr("cl", &area)      -- clear-screen
 *   4. tgetnum("co")             -- columns
 *   5. tgetnum("li")             -- lines
 *   6. tcgetattr / cfmakeraw / tcsetattr  -- raw mode
 *   7. TIOCGWINSZ                -- window size
 *
 * If any step crashes, the test prints the last checkpoint it passed.
 *
 * Compile: pcc -o test-termcap test-termcap.c
 * Run:     ./test-termcap
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termcap.h>

int
main(void)
{
    char bp[2048];
    char area_buf[512];
    char *area = area_buf;
    char *term;
    char *s;
    int n, r;
    struct termios orig, raw;
    struct winsize ws;

    term = getenv("TERM");
    if (!term || !*term)
        term = "vt100";
    printf("TERM=%s\n", term);
    fflush(stdout);

    /* Step 1: tgetent */
    printf("=== tgetent\n"); fflush(stdout);
    r = tgetent(bp, term);
    printf("tgetent returned %d\n", r);
    fflush(stdout);
    if (r < 0) {
        printf("SKIP: no termcap file (r=%d)\n", r);
        /* Don't crash — continue to test raw mode */
    } else if (r == 0) {
        printf("SKIP: terminal '%s' not in database\n", term);
    } else {
        printf("PASS tgetent\n");
        fflush(stdout);

        /* Step 2: tgetstr for common capabilities */
        printf("=== tgetstr cm\n"); fflush(stdout);
        area = area_buf;
        s = tgetstr("cm", &area);
        printf("cm = %s\n", s ? "(present)" : "(absent)");

        printf("=== tgetstr cl\n"); fflush(stdout);
        area = area_buf;
        s = tgetstr("cl", &area);
        printf("cl = %s\n", s ? "(present)" : "(absent)");

        printf("=== tgetstr ce\n"); fflush(stdout);
        area = area_buf;
        s = tgetstr("ce", &area);
        printf("ce = %s\n", s ? "(present)" : "(absent)");

        printf("=== tgetstr ku (up arrow)\n"); fflush(stdout);
        area = area_buf;
        s = tgetstr("ku", &area);
        printf("ku = %s\n", s ? "(present)" : "(absent)");

        /* Step 3: tgetnum */
        printf("=== tgetnum co\n"); fflush(stdout);
        n = tgetnum("co");
        printf("co (columns) = %d\n", n);

        printf("=== tgetnum li\n"); fflush(stdout);
        n = tgetnum("li");
        printf("li (lines) = %d\n", n);

        /* Step 4: tgetflag */
        printf("=== tgetflag am\n"); fflush(stdout);
        n = tgetflag("am");
        printf("am (auto-margins) = %d\n", n);

        printf("PASS all tgetstr/tgetnum/tgetflag\n");
        fflush(stdout);
    }

    /* Step 5: tcgetattr */
    printf("=== tcgetattr\n"); fflush(stdout);
    if (tcgetattr(0, &orig) < 0) {
        printf("SKIP tcgetattr (fd 0 not a tty)\n");
    } else {
        printf("PASS tcgetattr\n");
        fflush(stdout);

        /* Step 6: cfmakeraw + tcsetattr */
        printf("=== cfmakeraw + tcsetattr\n"); fflush(stdout);
        raw = orig;
        cfmakeraw(&raw);
        if (tcsetattr(0, TCSANOW, &raw) < 0) {
            printf("FAIL tcsetattr raw\n");
        } else {
            printf("PASS tcsetattr raw\n");
            fflush(stdout);
            /* Restore immediately */
            tcsetattr(0, TCSANOW, &orig);
            printf("PASS tcsetattr restore\n");
            fflush(stdout);
        }
    }

    /* Step 7: TIOCGWINSZ */
    printf("=== TIOCGWINSZ\n"); fflush(stdout);
    memset(&ws, 0, sizeof ws);
    if (ioctl(1, TIOCGWINSZ, &ws) < 0) {
        printf("SKIP TIOCGWINSZ (ioctl failed)\n");
    } else {
        printf("PASS TIOCGWINSZ: rows=%d cols=%d\n", ws.ws_row, ws.ws_col);
    }
    fflush(stdout);

    printf("all termcap tests done\n");
    return 0;
}
