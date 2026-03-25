/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef b2c_exitval
#define b2c_exitval
void Editor_Show_Help( void) {
    b2c_catch_set_backup = b2c_catch_set; b2c_catch_set = 0;
    long mid = 0;
    mid=(
    long)( (ROWS-24)/2);
    fputs("\033[0m", stdout); fflush(stdout);
    if( Color_Intense ){
        fputs("\033[1m", stdout); fflush(stdout);
    }
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid),(long)(COLUMNS/2-30));fflush(stdout);
fputs("+--------------------------------------------------------+\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+1),(long)(COLUMNS/2-30));fflush(stdout);
fputs("| File         <CTRL>+<n>: new file                      |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+2),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<l>: load file                     |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+3),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<s>: save file                     |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+4),(long)(COLUMNS/2-30));fflush(stdout);
fputs("| Editing      <CTRL>+<x>: cut line of text              |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+5),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<c>: copy line of text             |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+6),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<v>: paste line of text            |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+7),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<w> or <CTRL>+<del>: wipe line     |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+8),(long)(COLUMNS/2-30));fflush(stdout);
fputs("| Navigation   <HOME>: put cursor at start of line       |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+9),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <END>: put cursor at end of line          |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+10),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <PgUp>: move one page upwards             |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+11),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <PgDn>: move page downwards               |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+12),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <cursor keys>: navigate through text      |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+13),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<f>: find term in code             |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+14),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<g>: goto line number              |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+15),(long)(COLUMNS/2-30));fflush(stdout);
fputs("| Other        <CTRL>+<e>: compile and execute program   |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+16),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<a>: apply indentation             |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+17),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<r>: toggle line numbers           |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+18),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<b>: toggle text boldness          |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+19),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<d>: show context info             |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+20),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<h>: show this help                |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+21),(long)(COLUMNS/2-30));fflush(stdout);
fputs("|              <CTRL>+<q>: quit BaCon spartanic editor   |\n", stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( mid+22),(long)(COLUMNS/2-30));fflush(stdout);
fputs("+--------------------------------------------------------+\n", stdout);
    fputs("\033[5m", stdout); fflush(stdout);
    fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(COLUMNS/2-13));fflush(stdout);
fprintf(stdout, "%sPress a key to continue...", CL);
    fflush(stdout);
    fputs("\033[25m", stdout); fflush(stdout);
    b2c_getch();

    b2c_catch_set = b2c_catch_set_backup;
}
