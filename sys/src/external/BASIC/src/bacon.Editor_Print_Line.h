/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Editor_Print_Line( char *__b2c_text__b2c__string_var, long vpos, long linenr, long inverse, int digits, long do_print) {
 char*text__b2c__string_var = NULL; text__b2c__string_var = __b2c_Copy_String(NULL, __b2c_text__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 6922 "bacon.bac"
long x = 0;
long in_line_comment = 0;
long in_escaped = 0;
long pos = 0;
long len = 0;
long display_columns = 0;
long newcol = 0;
long lastcol = 0;
char *term__b2c__string_var = NULL;
char *c1__b2c__string_var = NULL;
char *c2__b2c__string_var = NULL;
char *color__b2c__string_var = NULL;
#line 6923 "bacon.bac"
static int in_block_comment = 0;
static int in_string = 0;
#line 6925 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) REPLACE__b2c__string_var(text__b2c__string_var, CHR__b2c__string_var(9), SPC__b2c__string_var(4)));
#line 6926 "bacon.bac"
len=(
long)( LEN(text__b2c__string_var));
#line 6928 "bacon.bac"
for(x=0; x <= len-1; x+=1){
#line 6929 "bacon.bac"
c1__b2c__string_var = F_MID__b2c__string_var(c1__b2c__string_var,text__b2c__string_var, x+1, 1);
#line 6930 "bacon.bac"
c2__b2c__string_var = F_MID__b2c__string_var(c2__b2c__string_var,text__b2c__string_var, x+1, 2);
#line 6933 "bacon.bac"
if( __b2c__STRCMP(c1__b2c__string_var ,  "\\") == 0  AND  NOT(in_line_comment)  AND  NOT(in_block_comment) ){
#line 6934 "bacon.bac"
if( in_escaped ){
#line 6935 "bacon.bac"
in_escaped=(
long)( 0);
#line 6936 "bacon.bac"
} else {
#line 6937 "bacon.bac"
in_escaped=(
long)( 1);
#line 6938 "bacon.bac"
}
#line 6940 "bacon.bac"
} else if( __b2c__STRCMP(c1__b2c__string_var ,  "\"") == 0  AND  NOT(in_escaped)  AND  NOT(in_line_comment)  AND  NOT(in_block_comment) ){
#line 6941 "bacon.bac"
in_string=(
 int)( 1 - in_string);
#line 6943 "bacon.bac"
} else if( __b2c__STRCMP(c2__b2c__string_var ,  "/*") == 0  AND  NOT(in_string)  AND  NOT(in_line_comment) ){
#line 6944 "bacon.bac"
in_block_comment=(
 int)( TRUE);
#line 6945 "bacon.bac"
in_escaped=(
long)( FALSE);
#line 6947 "bacon.bac"
} else if( __b2c__STRCMP(c1__b2c__string_var ,  "'") == 0  OR  REGEX(MID__b2c__string_var(text__b2c__string_var, x+1, 4), "REM[[:space:]]+")  OR  (__b2c__STRCMP(MID__b2c__string_var(text__b2c__string_var, x+1, 3) ,  "REM") == 0  AND  x == LEN(text__b2c__string_var)-3) ){
#line 6948 "bacon.bac"
if( NOT(in_string)  AND  NOT(in_block_comment) ){
#line 6949 "bacon.bac"
in_line_comment=(
long)( TRUE);
#line 6950 "bacon.bac"
in_escaped=(
long)( FALSE);
#line 6951 "bacon.bac"
}
#line 6953 "bacon.bac"
} else if( __b2c__STRCMP(c1__b2c__string_var ,  NL__b2c__string_var) == 0  AND  NOT(in_string)  AND  NOT(in_block_comment) ){
#line 6954 "bacon.bac"
in_line_comment=(
long)( FALSE);
#line 6955 "bacon.bac"
in_escaped=(
long)( FALSE);
#line 6956 "bacon.bac"
} else {
#line 6957 "bacon.bac"
in_escaped=(
long)( FALSE);
#line 6958 "bacon.bac"
}
#line 6961 "bacon.bac"
if( in_string ){
#line 6962 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Quot_Col)) ;
#line 6964 "bacon.bac"
} else if( in_block_comment ){
#line 6965 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(text__b2c__string_var, x+1, 2) ,  "*/") == 0 ){
#line 6966 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Comm_Col) , STR__b2c__string_var(Comm_Col)) ;
#line 6967 "bacon.bac"
in_block_comment=(
 int)( FALSE);
#line 6968 "bacon.bac"
x = x + (1);
#line 6969 "bacon.bac"
} else {
#line 6970 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Comm_Col)) ;
#line 6971 "bacon.bac"
}
#line 6972 "bacon.bac"
} else if( in_line_comment ){
#line 6973 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Comm_Col)) ;
#line 6974 "bacon.bac"
} else if( (__b2c__STRCMP(MID__b2c__string_var(text__b2c__string_var, x+1, 1) , __b2c__min_str( CHR__b2c__string_var(48) , CHR__b2c__string_var(57))) >= 0 && __b2c__STRCMP(MID__b2c__string_var(text__b2c__string_var, x+1, 1) , __b2c__max_str( CHR__b2c__string_var(48) , CHR__b2c__string_var(57))) <= 0 ? 1 : 0) ){
#line 6975 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Num_Col)) ;
#line 6976 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(text__b2c__string_var, x+1, 1) ,  CHR__b2c__string_var(34)) == 0 ){
#line 6977 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Quot_Col)) ;
#line 6978 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(text__b2c__string_var, x+1, 1) ,  CHR__b2c__string_var(38)) == 0 ){
#line 6979 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Func_Col)) ;
#line 6980 "bacon.bac"
} else {
#line 6981 "bacon.bac"
pos=(
long)( REGEX(MID__b2c__string_var(text__b2c__string_var, x+1), "[[:space:]]|[=,?;:+-/\\(\\)\\*]|\\||\\[|\\]")-1);
#line 6982 "bacon.bac"
if( (pos )< 0 ){
pos=(
long)( len-x);
}
#line 6984 "bacon.bac"
term__b2c__string_var = F_CONCAT__b2c__string_var(term__b2c__string_var, "|" , MID__b2c__string_var(text__b2c__string_var, x+1, pos) , "|") ;
#line 6986 "bacon.bac"
if( TALLY(Stat__b2c__string_var, term__b2c__string_var) ){
#line 6987 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , FILL__b2c__string_var(pos, ASC(STR__b2c__string_var(Stat_Col)))) ;
#line 6988 "bacon.bac"
} else if( TALLY(EXTRACT__b2c__string_var(Func__b2c__string_var, "\\"), term__b2c__string_var) ){
#line 6989 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , FILL__b2c__string_var(pos, ASC(STR__b2c__string_var(Func_Col)))) ;
#line 6990 "bacon.bac"
} else if( TALLY(EXTRACT__b2c__string_var(Var__b2c__string_var, "\\"), term__b2c__string_var) ){
#line 6991 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , FILL__b2c__string_var(pos, ASC(STR__b2c__string_var(Var_Col)))) ;
#line 6992 "bacon.bac"
} else if( TALLY(Type__b2c__string_var, term__b2c__string_var) ){
#line 6993 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , FILL__b2c__string_var(pos, ASC(STR__b2c__string_var(Type_Col)))) ;
#line 6994 "bacon.bac"
} else {
#line 6995 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , FILL__b2c__string_var(pos, ASC(STR__b2c__string_var(Def_Col)))) ;
#line 6996 "bacon.bac"
}
#line 6997 "bacon.bac"
color__b2c__string_var = F_CONCAT__b2c__string_var(color__b2c__string_var, color__b2c__string_var , STR__b2c__string_var(Def_Col)) ;
#line 6998 "bacon.bac"
x = x + ( pos);
#line 6999 "bacon.bac"
}
#line 7000 "bacon.bac"
}
#line 7003 "bacon.bac"
if( do_print ){
#line 7004 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7005 "bacon.bac"
if( inverse ){
fputs("\033[7m", stdout); fflush(stdout);
}
#line 7006 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7007 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7009 "bacon.bac"
if( Line_Number_Active ){
#line 7010 "bacon.bac"
display_columns=(
long)( COLUMNS-digits-1);
#line 7011 "bacon.bac"
fprintf(stdout,"\033[%ld%ldm", (long)3, (long)3); fflush(stdout);
#line 7012 "bacon.bac"
fprintf(stdout, "%*ld ", digits, linenr);
#line 7013 "bacon.bac"
} else {
#line 7014 "bacon.bac"
display_columns=(
long)( COLUMNS);
#line 7015 "bacon.bac"
}
#line 7017 "bacon.bac"
for(x=vpos; x <= len; x+=1){
#line 7018 "bacon.bac"
if( x-vpos+1 <= display_columns ){
#line 7019 "bacon.bac"
newcol=(
long)( VAL(MID__b2c__string_var(color__b2c__string_var, x, 1)));
#line 7020 "bacon.bac"
if( newcol == Comm_Col ){
#line 7021 "bacon.bac"
fputs("\033[3m", stdout); fflush(stdout);
#line 7022 "bacon.bac"
} else {
#line 7023 "bacon.bac"
fputs("\033[23m", stdout); fflush(stdout);
#line 7024 "bacon.bac"
}
#line 7025 "bacon.bac"
if( lastcol != newcol ){
fprintf(stdout,"\033[%ld%ldm", (long)3, (long)newcol); fflush(stdout);
}
#line 7026 "bacon.bac"
__b2c__assign = (char*)MID__b2c__string_var(text__b2c__string_var, x, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7027 "bacon.bac"
lastcol=(
long)( newcol);
#line 7028 "bacon.bac"
}
#line 7029 "bacon.bac"
}
#line 7030 "bacon.bac"
}
#line 7033 "bacon.bac"
if( in_string  AND  __b2c__STRCMP(RIGHT__b2c__string_var(text__b2c__string_var, 2) ,  CONCAT__b2c__string_var( CHR__b2c__string_var(32) , CHR__b2c__string_var(92) )) != 0 ){
in_string=(
 int)( 0);
}
#line 7035 "bacon.bac"

__b2c__STRFREE(text__b2c__string_var);
__b2c__STRFREE(term__b2c__string_var);
__b2c__STRFREE(c1__b2c__string_var);
__b2c__STRFREE(c2__b2c__string_var);
__b2c__STRFREE(color__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
