/*
 * test-curses.c - Minimal PDCurses smoke test.
 *
 * Tests initscr/endwin in isolation to confirm whether PDC_scr_open
 * itself is the crash site, or whether the crash occurs only after
 * subsequent curses calls (window allocation, drawing, etc.).
 *
 * Compile: pcc -o test-curses test-curses.c -lcurses
 * Run in a terminal (not redirected): ./test-curses
 */
#include <curses.h>
#include <stdio.h>

int
main(void)
{
    WINDOW *w;
    int r, c;

    fprintf(stderr, "=== calling initscr\n");
    fflush(stderr);

    w = initscr();
    if (w == NULL) {
        fprintf(stderr, "FAIL initscr returned NULL\n");
        return 1;
    }
    fprintf(stderr, "PASS initscr returned %p\n", (void *)w);

    getmaxyx(stdscr, r, c);
    fprintf(stderr, "PASS getmaxyx: rows=%d cols=%d\n", r, c);

    fprintf(stderr, "=== calling clear\n");
    fflush(stderr);
    clear();
    fprintf(stderr, "PASS clear\n");

    fprintf(stderr, "=== calling mvprintw\n");
    fflush(stderr);
    mvprintw(0, 0, "test-curses OK");
    fprintf(stderr, "PASS mvprintw\n");

    fprintf(stderr, "=== calling refresh\n");
    fflush(stderr);
    refresh();
    fprintf(stderr, "PASS refresh\n");

    fprintf(stderr, "=== calling endwin\n");
    fflush(stderr);
    endwin();
    fprintf(stderr, "PASS endwin\n");

    fprintf(stderr, "=== calling initscr a second time\n");
    fflush(stderr);
    w = initscr();
    if (w == NULL) {
        fprintf(stderr, "FAIL second initscr returned NULL\n");
        return 1;
    }
    endwin();
    fprintf(stderr, "PASS second initscr+endwin\n");

    fprintf(stderr, "all curses tests passed\n");
    return 0;
}
