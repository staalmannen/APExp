/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Editor_Show_Help( void) {
 __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 7102 "bacon.bac"
long mid = 0;
#line 7104 "bacon.bac"
mid=(
long)( (ROWS-24)/2);
#line 7105 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7106 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7107 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"+--------------------------------------------------------+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7108 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+1),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"| File         <CTRL>+<n>: new file                      |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7109 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+2),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<l>: load file                     |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7110 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+3),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<s>: save file                     |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7111 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+4),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"| Editing      <CTRL>+<x>: cut line of text              |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7112 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+5),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<c>: copy line of text             |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7113 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+6),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<v>: paste line of text            |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7114 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+7),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<w> or <CTRL>+<del>: wipe line     |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7115 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+8),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"| Navigation   <HOME>: put cursor at start of line       |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7116 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+9),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <END>: put cursor at end of line          |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7117 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+10),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <PgUp>: move one page upwards             |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7118 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+11),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <PgDn>: move page downwards               |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7119 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+12),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <cursor keys>: navigate through text      |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7120 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+13),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<f>: find term in code             |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7121 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+14),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<g>: goto line number              |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7122 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+15),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"| Other        <CTRL>+<e>: compile and execute program   |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7123 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+16),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<a>: apply indentation             |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7124 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+17),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<r>: toggle line numbers           |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7125 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+18),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<b>: toggle text boldness          |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7126 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+19),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<d>: show context info             |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7127 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+20),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<h>: show this help                |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7128 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+21),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"|              <CTRL>+<q>: quit BaCon spartanic editor   |"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7129 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( mid+22),(long)(COLUMNS/2-30));fflush(stdout);
__b2c__assign = (char*)"+--------------------------------------------------------+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7130 "bacon.bac"
fputs("\033[5m", stdout); fflush(stdout);
#line 7131 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(COLUMNS/2-13));fflush(stdout);
#line 7132 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Press a key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7133 "bacon.bac"
fputs("\033[25m", stdout); fflush(stdout);
#line 7134 "bacon.bac"
__b2c__getch();
#line 7136 "bacon.bac"

__b2c__catch_set = __b2c__catch_set_backup;
}
