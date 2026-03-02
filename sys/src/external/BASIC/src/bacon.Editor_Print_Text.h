/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Editor_Print_Text( char *__b2c_txt__b2c__string_var, long line, long verticalpos) {
 char*txt__b2c__string_var = NULL; txt__b2c__string_var = __b2c_Copy_String(NULL, __b2c_txt__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 7041 "bacon.bac"
long y = 0;
long nr = 0;
long total_lines = 0;
long digits = 0;
char *line__b2c__string_var = NULL;
#line 7043 "bacon.bac"
total_lines=(
long)( AMOUNT(txt__b2c__string_var, NL__b2c__string_var));
#line 7044 "bacon.bac"
if( total_lines == 0 ){
total_lines=(
long)( 1);
}
#line 7045 "bacon.bac"
digits=(
long)( LEN(STR__b2c__string_var(AMOUNT(txt__b2c__string_var, NL__b2c__string_var))));
#line 7047 "bacon.bac"
fprintf(stdout,"\033[?25l"); fflush(stdout);
#line 7050 "bacon.bac"
nr=(
long)( line);
#line 7051 "bacon.bac"
while( __b2c__STRCMP(RIGHT__b2c__string_var(TOKEN__b2c__string_var(txt__b2c__string_var, nr-1, NL__b2c__string_var), 2) ,  CONCAT__b2c__string_var( CHR__b2c__string_var(32) , CHR__b2c__string_var(92))) == 0 ){
#line 7052 "bacon.bac"
nr = nr - (1);
#line 7053 "bacon.bac"
}
#line 7056 "bacon.bac"
if( (nr )< line ){
#line 7057 "bacon.bac"
for(y=nr; y <= line-1; y+=1){
#line 7058 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(txt__b2c__string_var, y, NL__b2c__string_var));
#line 7059 "bacon.bac"
Editor_Print_Line(line__b2c__string_var, 1, y, FALSE, digits, FALSE);
#line 7060 "bacon.bac"
}
#line 7061 "bacon.bac"
}
#line 7063 "bacon.bac"
for(y=1; y <= ROWS; y+=1){
#line 7064 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( y),(long)(1));fflush(stdout);
#line 7065 "bacon.bac"
if( line <= total_lines ){
#line 7066 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(txt__b2c__string_var, line, NL__b2c__string_var));
#line 7067 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, CHR__b2c__string_var(9), SPC__b2c__string_var(4)));
#line 7068 "bacon.bac"
Editor_Print_Line(line__b2c__string_var, verticalpos, line, FALSE, digits, TRUE);
#line 7069 "bacon.bac"
} else {
#line 7070 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7071 "bacon.bac"
}
#line 7072 "bacon.bac"
line = line + (1);
#line 7073 "bacon.bac"
}
#line 7075 "bacon.bac"
Editor_Print_Line("", 1, 1, FALSE, 0, FALSE);
#line 7076 "bacon.bac"
fprintf(stdout,"\033[?25h"); fflush(stdout);
#line 7078 "bacon.bac"

__b2c__STRFREE(txt__b2c__string_var);
__b2c__STRFREE(line__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
