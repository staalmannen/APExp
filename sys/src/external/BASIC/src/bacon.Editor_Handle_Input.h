/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Editor_Handle_Input( char *__b2c_file__b2c__string_var, char *__b2c_text__b2c__string_var) {
 char*file__b2c__string_var = NULL; file__b2c__string_var = __b2c_Copy_String(NULL, __b2c_file__b2c__string_var); char*text__b2c__string_var = NULL; text__b2c__string_var = __b2c_Copy_String(NULL, __b2c_text__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_line_input__b2c__string_var_ptr = 0; char* __b2c__forin_line_input__b2c__string_var_string = NULL; char* __b2c__forin_line_input__b2c__string_var_string_org = NULL; char* __b2c__forin_line_input__b2c__string_var_step = NULL; char *__b2c__select_7896__b2c__string_var = NULL;
#line 7142 "bacon.bac"
long visual_xpos = 1;
long real_xpos = 1;
long ypos = 1;
long start = 1;
long visual_begin_pos = 1;
long display_columns = 0;
long do_print = 0;
#line 7143 "bacon.bac"
long key = 0;
long special = 0;
long cursor = 0;
long delkey = 0;
long page = 0;
long total = 0;
long line = 0;
long next = 0;
long x = 0;
long myposition = 0;
long nextposition = 0;
long label_active = 0;
long wrap_active = 0;
long digits = 0;
long copy_flag = 0;
long cksum = 0;
#line 7144 "bacon.bac"
char *line__b2c__string_var = NULL;
char *prog__b2c__string_var = NULL;
char *answer__b2c__string_var = NULL;
char *option__b2c__string_var = NULL;
char *man__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *result__b2c__string_var = NULL;
char *copy_line__b2c__string_var = NULL;
char *word__b2c__string_var = NULL;
char *arg__b2c__string_var = NULL;
char *line_input__b2c__string_var = NULL;
#line 7147 "bacon.bac"
__b2c__option_dq = 1&255;
#line 7148 "bacon.bac"
__b2c__collapse = FALSE;
#line 7151 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, ~IXON, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7151, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7152 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7152, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7153 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  17, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7153, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7156 "bacon.bac"
__b2c__signal((void*)(uintptr_t)(&Editor_Restore_Normal),  SIGINT);
#line 7159 "bacon.bac"
g_CURSOR_X=(long)( GETX);
#line 7160 "bacon.bac"
g_CURSOR_Y=(long)( GETY);
#line 7163 "bacon.bac"
fprintf(stdout,"\033[?47h"); fflush(stdout);
#line 7164 "bacon.bac"
fprintf(stdout,"\033[2J"); fprintf(stdout,"\033[0;0f"); fflush(stdout);
#line 7165 "bacon.bac"
Editor_Print_Text(text__b2c__string_var, 1, 1);
#line 7166 "bacon.bac"
cksum=(
long)( HASH(text__b2c__string_var));
#line 7168 "bacon.bac"
while( TRUE ){
#line 7169 "bacon.bac"
do{
#line 7171 "bacon.bac"
if( Line_Number_Active ){
#line 7172 "bacon.bac"
digits=(
long)( LEN(STR__b2c__string_var(AMOUNT(text__b2c__string_var, NL__b2c__string_var))));
#line 7173 "bacon.bac"
display_columns=(
long)( COLUMNS-digits-1);
#line 7174 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(visual_xpos+digits+1));fflush(stdout);
#line 7175 "bacon.bac"
} else {
#line 7176 "bacon.bac"
display_columns=(
long)( COLUMNS);
#line 7177 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(visual_xpos));fflush(stdout);
#line 7178 "bacon.bac"
}
#line 7180 "bacon.bac"
key=(
long)( WAIT(STDIN_FILENO, 100));
#line 7182 "bacon.bac"
__b2c__select_7182 = (double)key;
#line 7184 "bacon.bac"
 if ( (__b2c__select_7182) == (0)){
#line 7185 "bacon.bac"
continue;
#line 7188 "bacon.bac"
} else  if ( (__b2c__select_7182) == (3)){
#line 7189 "bacon.bac"
copy_line__b2c__string_var = __b2c_Copy_String(copy_line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7190 "bacon.bac"
copy_flag=(
long)( 1);
#line 7193 "bacon.bac"
} else  if ( (__b2c__select_7182) == (24)){
#line 7194 "bacon.bac"
copy_line__b2c__string_var = __b2c_Copy_String(copy_line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7195 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) DEL__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7196 "bacon.bac"
do_print=(
long)( TRUE);
#line 7197 "bacon.bac"
copy_flag=(
long)( 1);
#line 7200 "bacon.bac"
} else  if ( (__b2c__select_7182) == (22)){
#line 7201 "bacon.bac"
if( (ypos )< ROWS  AND  LEN(copy_line__b2c__string_var) ){
#line 7202 "bacon.bac"
text__b2c__string_var = F_APPEND__b2c__string_var(text__b2c__string_var,text__b2c__string_var, start+ypos-1, copy_line__b2c__string_var, NL__b2c__string_var);
#line 7203 "bacon.bac"
do_print=(
long)( TRUE);
#line 7204 "bacon.bac"
}
#line 7206 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7207 "bacon.bac"
x=(
long)( 1);
#line 7208 "bacon.bac"
real_xpos=(
long)( 1);
#line 7209 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7210 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7211 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7212 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7213 "bacon.bac"
copy_flag=(
long)( 0);
#line 7216 "bacon.bac"
} else  if ( (__b2c__select_7182) == (4)){
#line 7217 "bacon.bac"
myposition=(
long)( real_xpos);
#line 7218 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7219 "bacon.bac"
while( NOT(REGEX(MID__b2c__string_var(line__b2c__string_var, myposition, 1), "[[:space:]]|[=,?;:+-/\\(\\)\\*]")) ){
#line 7220 "bacon.bac"
myposition = myposition - (1);
#line 7221 "bacon.bac"
if( myposition == 0 ){
break;
}
#line 7222 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7223 "bacon.bac"
myposition = myposition + (1);
#line 7224 "bacon.bac"
total=(
long)( 1);
#line 7225 "bacon.bac"
while( NOT(REGEX(MID__b2c__string_var(line__b2c__string_var, myposition+total, 1), "[[:space:]]|[=,?;:+-/\\(\\)\\*]")) ){
#line 7226 "bacon.bac"
total = total + (1);
#line 7227 "bacon.bac"
if( (myposition+total )> LEN(line__b2c__string_var) ){
break;
}
#line 7228 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7229 "bacon.bac"
word__b2c__string_var = F_MID__b2c__string_var(word__b2c__string_var,line__b2c__string_var, myposition, total);
#line 7230 "bacon.bac"
fprintf(stdout,"\033[2J"); fprintf(stdout,"\033[0;0f"); fflush(stdout);
#line 7231 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7232 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( 1),(long)(1));fflush(stdout);
#line 7233 "bacon.bac"
if( ISTRUE(LEN(EXEC__b2c__string_var("command -v less 2>/dev/null"))) ){
#line 7234 "bacon.bac"
fprintf(stdout,"\033[?47l"); fflush(stdout);
#line 7235 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "man bacon | less -P\"[Press space to continue, 'q' to quit.]\" -p '^     " , REPLACE__b2c__string_var(word__b2c__string_var, "$", "\\$") , "'") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 7236 "bacon.bac"
fprintf(stdout,"\033[?47h"); fflush(stdout);
#line 7237 "bacon.bac"
} else {
#line 7238 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "man bacon | more -d -p +/'^     " , REPLACE__b2c__string_var(word__b2c__string_var, "$", "\\$") , "'") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 7239 "bacon.bac"
}
#line 7240 "bacon.bac"
do_print=(
long)( TRUE);
#line 7243 "bacon.bac"
} else  if ( (__b2c__select_7182) == (18)){
#line 7244 "bacon.bac"
Line_Number_Active=(long)( 1 - Line_Number_Active);
#line 7245 "bacon.bac"
if( FILEEXISTS( CONCAT__b2c__string_var(GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg" ) ) ){
#line 7246 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) COLLAPSE__b2c__string_var(LOAD__b2c__string_var( CONCAT__b2c__string_var(GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg") ), NL__b2c__string_var));
#line 7247 "bacon.bac"
for(x=1; x <= AMOUNT(arg__b2c__string_var, NL__b2c__string_var); x+=1){
#line 7248 "bacon.bac"
if( REGEX(TOKEN__b2c__string_var(arg__b2c__string_var, x, NL__b2c__string_var), "^linenr") ){
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, x, NL__b2c__string_var));
}
#line 7249 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7250 "bacon.bac"
ERROR = __b2c__save(0, 0, CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg"), APPEND__b2c__string_var(arg__b2c__string_var, 0, CONCAT__b2c__string_var( "linenr " , STR__b2c__string_var(Line_Number_Active)) , NL__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7250, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7251 "bacon.bac"
} else {
#line 7252 "bacon.bac"
ERROR = __b2c__save(0, 0, CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg"), CONCAT__b2c__string_var( "linenr " , STR__b2c__string_var(Line_Number_Active) ), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7252, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7253 "bacon.bac"
}
#line 7254 "bacon.bac"
do_print=(
long)( TRUE);
#line 7257 "bacon.bac"
} else  if ( (__b2c__select_7182) == (7)){
#line 7258 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7259 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7260 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7261 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7261, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7262 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Enter line number... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
key = atol(__b2c__assign);
free(__b2c__assign); __b2c__assign = NULL;
#line 7263 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7263, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7264 "bacon.bac"
if( (key )> AMOUNT(text__b2c__string_var, NL__b2c__string_var) ){
key=(
long)( AMOUNT(text__b2c__string_var, NL__b2c__string_var));
}
#line 7265 "bacon.bac"
if( (key )< ROWS ){
#line 7266 "bacon.bac"
start=(
long)( 1);
#line 7267 "bacon.bac"
ypos=(
long)( key);
#line 7268 "bacon.bac"
} else if( (key )> AMOUNT(text__b2c__string_var, NL__b2c__string_var)-(ROWS/2) ){
#line 7269 "bacon.bac"
start=(
long)( AMOUNT(text__b2c__string_var, NL__b2c__string_var)-ROWS);
#line 7270 "bacon.bac"
ypos=(
long)( ROWS - (AMOUNT(text__b2c__string_var, NL__b2c__string_var)-key));
#line 7271 "bacon.bac"
} else {
#line 7272 "bacon.bac"
start=(
long)( key-(ROWS/2));
#line 7273 "bacon.bac"
ypos=(
long)( key-start+1);
#line 7274 "bacon.bac"
}
#line 7275 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(visual_xpos));fflush(stdout);
#line 7276 "bacon.bac"
do_print=(
long)( TRUE);
#line 7279 "bacon.bac"
} else  if ( (__b2c__select_7182) == (1)){
#line 7280 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7281 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7282 "bacon.bac"
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) "");
#line 7283 "bacon.bac"
myposition = nextposition = label_active = wrap_active = 0;
#line 7284 "bacon.bac"
__b2c__forin_line_input__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_line_input__b2c__string_var_string, text__b2c__string_var); __b2c__forin_line_input__b2c__string_var_string_org = __b2c__forin_line_input__b2c__string_var_string;
__b2c__forin_line_input__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_line_input__b2c__string_var_step, NL__b2c__string_var);
__b2c__forin_line_input__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_line_input__b2c__string_var_string, __b2c__forin_line_input__b2c__string_var_step);
for(; __b2c__forin_line_input__b2c__string_var_ptr > 0; __b2c__forin_line_input__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_line_input__b2c__string_var_string_org, __b2c__forin_line_input__b2c__string_var_step, &line_input__b2c__string_var);
#line 7285 "bacon.bac"
myposition=(
long)( nextposition);
#line 7286 "bacon.bac"
line_input__b2c__string_var = F_CHOP__b2c__string_var(line_input__b2c__string_var,line_input__b2c__string_var);
#line 7287 "bacon.bac"
if( LEN(line_input__b2c__string_var) == 0  AND  label_active ){
#line 7288 "bacon.bac"
label_active=(
long)( FALSE);
#line 7289 "bacon.bac"
myposition = myposition - (1);
#line 7290 "bacon.bac"
nextposition=(
long)( myposition);
#line 7291 "bacon.bac"
}
#line 7292 "bacon.bac"
if( REGEX(line_input__b2c__string_var, "^(CASE|UNTIL)[ \\t]|^(DEFAULT|FI|NEXT|WEND|DONE)|^ELSE$|^ELIF.+THEN$|^END.+") ){
#line 7293 "bacon.bac"
if( NOT(REGEX(line_input__b2c__string_var, "^END.+[0-9]+|^ENDFORK")) ){
myposition = myposition - (1);
}
#line 7294 "bacon.bac"
if( REGEX(line_input__b2c__string_var, "SELECT$") ){
myposition = myposition - (1);
}
#line 7295 "bacon.bac"
if( (myposition )< 0 ){
myposition=(
long)( 0);
}
#line 7296 "bacon.bac"
nextposition=(
long)( myposition);
#line 7297 "bacon.bac"
}
#line 7298 "bacon.bac"
if( REGEX(line_input__b2c__string_var, "^(CASE|ENUM|FOR|FUNCTION|FUNC|GLOBAL RECORD|LABEL|RECORD|SELECT|SUB|WHILE|DOTIMES|WITH)[ \\t]|^(DEFAULT|REPEAT|USEC|USEH|DO$)|^IF.+THEN$|^ELIF.+THEN$|^ELSE$") ){
#line 7299 "bacon.bac"
nextposition = nextposition + (1);
#line 7300 "bacon.bac"
if( REGEX(line_input__b2c__string_var, "^SELECT") ){
nextposition = nextposition + (1);
}
#line 7301 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(line_input__b2c__string_var, 5) ,  "LABEL") == 0 ){
label_active=(
long)( TRUE);
}
#line 7302 "bacon.bac"
}
#line 7303 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(line_input__b2c__string_var, 2) ,  CONCAT__b2c__string_var( CHR__b2c__string_var(32) , CHR__b2c__string_var(92) )) == 0  AND  NOT(REGEX(line_input__b2c__string_var, "^(REM|')")) ){
#line 7304 "bacon.bac"
if( NOT(wrap_active) ){
nextposition = nextposition + (1);
}
#line 7305 "bacon.bac"
wrap_active=(
long)( TRUE);
#line 7306 "bacon.bac"
} else {
#line 7307 "bacon.bac"
if( wrap_active ){
nextposition = nextposition - (1);
}
#line 7308 "bacon.bac"
wrap_active=(
long)( FALSE);
#line 7309 "bacon.bac"
}
#line 7310 "bacon.bac"
if( REGEX(previous__b2c__string_var, "^(REM|')") ){
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) CHANGE__b2c__string_var(result__b2c__string_var, AMOUNT(result__b2c__string_var, NL__b2c__string_var)-1, CONCAT__b2c__string_var( TAB__b2c__string_var(myposition) , previous__b2c__string_var) , NL__b2c__string_var));
}
#line 7311 "bacon.bac"
if( LEN(line_input__b2c__string_var) ){
#line 7312 "bacon.bac"
result__b2c__string_var = F_CONCAT__b2c__string_var(result__b2c__string_var, result__b2c__string_var , TAB__b2c__string_var(myposition) , line_input__b2c__string_var , NL__b2c__string_var) ;
#line 7313 "bacon.bac"
} else {
#line 7314 "bacon.bac"
result__b2c__string_var = F_CONCAT__b2c__string_var(result__b2c__string_var, result__b2c__string_var , NL__b2c__string_var) ;
#line 7315 "bacon.bac"
}
#line 7316 "bacon.bac"
previous__b2c__string_var = __b2c_Copy_String(previous__b2c__string_var, (char*) line_input__b2c__string_var);
#line 7317 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7318 "bacon.bac"
text__b2c__string_var = F_CHOP__b2c__string_var(text__b2c__string_var,result__b2c__string_var);
#line 7319 "bacon.bac"
Editor_Print_Text(text__b2c__string_var, start, visual_begin_pos);
#line 7320 "bacon.bac"
fprintf(stdout,"\033[?25l"); fflush(stdout);
#line 7321 "bacon.bac"
fputs("\033[5m", stdout); fflush(stdout);
#line 7322 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7323 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7324 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7325 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Indentation done, press a key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7326 "bacon.bac"
key=(
long)( GETKEY);
#line 7327 "bacon.bac"
fputs("\033[25m", stdout); fflush(stdout);
#line 7328 "bacon.bac"
fprintf(stdout,"\033[?25h"); fflush(stdout);
#line 7329 "bacon.bac"
do_print=(
long)( TRUE);
#line 7332 "bacon.bac"
} else  if ( (__b2c__select_7182) == (5)){
#line 7333 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7334 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7335 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7336 "bacon.bac"
prog__b2c__string_var = F_CONCAT__b2c__string_var(prog__b2c__string_var, DIRNAME__b2c__string_var(file__b2c__string_var) , "/" , BASENAME__b2c__string_var(file__b2c__string_var, 1)) ;
#line 7337 "bacon.bac"
if( FILEEXISTS(prog__b2c__string_var) ){
if(unlink(prog__b2c__string_var)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 7337, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
}
#line 7338 "bacon.bac"
ERROR = __b2c__save(0, 0, file__b2c__string_var, CHOP__b2c__string_var(text__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7338, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7339 "bacon.bac"
__b2c__assign = (char*)"Current BaCon command line options: "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) IIF__b2c__string_var(LEN(option__b2c__string_var)==0, "<none set>", option__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7340 "bacon.bac"
__b2c__assign = (char*)"Do you want to set new options (y/[n]) ? "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7341 "bacon.bac"
if( GETKEY == ASC("y") ){
#line 7342 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7342, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7343 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Enter new options: "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
option__b2c__string_var = __b2c_Copy_String(option__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 7344 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7344, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7345 "bacon.bac"
}
#line 7346 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) CONCAT__b2c__string_var( "Executing 'bacon " , option__b2c__string_var , " -d " , DIRNAME__b2c__string_var(file__b2c__string_var) , " " , file__b2c__string_var , "'...") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7347 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "bacon " , option__b2c__string_var , " -d " , DIRNAME__b2c__string_var(file__b2c__string_var) , " " , file__b2c__string_var) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 7348 "bacon.bac"
if( FILEEXISTS(prog__b2c__string_var) ){
#line 7349 "bacon.bac"
__b2c__assign = (char*)"Execute ([y]/n) ? "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7350 "bacon.bac"
key=(
long)( GETKEY);
#line 7351 "bacon.bac"
fputs("\n", stdout);
#line 7352 "bacon.bac"
if( key == ASC("y")  OR  key == 10 ){
#line 7353 "bacon.bac"
__b2c__assign = (char*)"Current program arguments: "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) IIF__b2c__string_var(LEN(arg__b2c__string_var)==0, "<none set>", arg__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7354 "bacon.bac"
__b2c__assign = (char*)"Do you want to set new program arguments (y/[n]) ? "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7355 "bacon.bac"
if( GETKEY == ASC("y") ){
#line 7356 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7356, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7357 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Enter new arguments (<enter> means none)... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 7358 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7358, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7359 "bacon.bac"
}
#line 7360 "bacon.bac"
fprintf(stdout,"\033[?47l"); fflush(stdout);
#line 7361 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( GETY),(long)(1));fflush(stdout);
#line 7362 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, IXON, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7362, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7363 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  3, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7363, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7364 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7364, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7365 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( prog__b2c__string_var , " " , arg__b2c__string_var) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 7366 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 0, 0, ~IXON, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7366, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7367 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 4, VINTR ,  17, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7367, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7368 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7368, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7369 "bacon.bac"
}
#line 7370 "bacon.bac"
}
#line 7371 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7372 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7373 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Press a key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7374 "bacon.bac"
key=(
long)( GETKEY);
#line 7375 "bacon.bac"
fputs("\n", stdout);
#line 7376 "bacon.bac"
fprintf(stdout,"\033[?47h"); fflush(stdout);
#line 7377 "bacon.bac"
do_print=(
long)( TRUE);
#line 7380 "bacon.bac"
} else  if ( (__b2c__select_7182) == (6)){
#line 7381 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7382 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7383 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7384 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7384, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7385 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Enter term... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
word__b2c__string_var = __b2c_Copy_String(word__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 7386 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7386, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7387 "bacon.bac"
__b2c__assign = (char*)"Searching..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7388 "bacon.bac"
total=(
long)( WHERE(text__b2c__string_var, start+ypos-1, NL__b2c__string_var)+visual_xpos-1);
#line 7389 "bacon.bac"
next=(
long)( INSTR(MID__b2c__string_var(text__b2c__string_var, total), word__b2c__string_var));
#line 7390 "bacon.bac"
while( (next )> 0 ){
#line 7391 "bacon.bac"
line=(
long)( AMOUNT(MID__b2c__string_var(text__b2c__string_var, 1, total+next), NL__b2c__string_var));
#line 7392 "bacon.bac"
start=(
long)( IIF((line-ROWS/2 )< 1, 1, line-ROWS/2));
#line 7393 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7394 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7395 "bacon.bac"
Editor_Print_Text(text__b2c__string_var, start, visual_begin_pos);
#line 7396 "bacon.bac"
ypos=(
long)( ROWS/2+1);
#line 7397 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( IIF(start == 1, line, ypos)),(long)(1));fflush(stdout);
#line 7398 "bacon.bac"
Editor_Print_Line(TOKEN__b2c__string_var(text__b2c__string_var, IIF(start == 1, start+line-1, start+ypos-1), NL__b2c__string_var), 1, IIF(start == 1, start+line-1, start+ypos-1), TRUE, digits, TRUE);
#line 7399 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7400 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7401 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7402 "bacon.bac"
fputs("\033[7m", stdout); fflush(stdout);
#line 7403 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Press [n] for next item, any other key to quit..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7404 "bacon.bac"
if( GETKEY != ASC("n") ){
#line 7405 "bacon.bac"
key=(
long)( 255);
#line 7406 "bacon.bac"
break;
#line 7407 "bacon.bac"
}
#line 7408 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7409 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Searching..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7410 "bacon.bac"
total = total + ( next);
#line 7411 "bacon.bac"
next=(
long)( INSTR(MID__b2c__string_var(text__b2c__string_var, total+1), word__b2c__string_var));
#line 7412 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7413 "bacon.bac"
if( key != 255 ){
#line 7414 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7415 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Search ended. Press a key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7416 "bacon.bac"
key=(
long)( GETKEY);
#line 7417 "bacon.bac"
}
#line 7418 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7419 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7420 "bacon.bac"
do_print=(
long)( TRUE);
#line 7423 "bacon.bac"
} else  if ( (__b2c__select_7182) == (14)){
#line 7424 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7425 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7426 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7427 "bacon.bac"
if( HASH(text__b2c__string_var) != cksum ){
#line 7428 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Code has changed! Save current to file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) file__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "' first (y/n)?"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7429 "bacon.bac"
if( GETKEY == ASC("y") ){
#line 7430 "bacon.bac"
ERROR = __b2c__save(0, 0, file__b2c__string_var, CHOP__b2c__string_var(text__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7430, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7431 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( " File '" , BASENAME__b2c__string_var(file__b2c__string_var) , "' saved! Press a key to continue...") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7432 "bacon.bac"
key=(
long)( GETKEY);
#line 7433 "bacon.bac"
}
#line 7434 "bacon.bac"
}
#line 7435 "bacon.bac"
start=(
long)( 1);
#line 7436 "bacon.bac"
visual_begin_pos=(
long)( 1);
#line 7437 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7438 "bacon.bac"
ypos=(
long)( 1);
#line 7439 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) "");
#line 7440 "bacon.bac"
file__b2c__string_var = __b2c_Copy_String(file__b2c__string_var, (char*) "");
#line 7441 "bacon.bac"
do_print=(
long)( TRUE);
#line 7444 "bacon.bac"
} else  if ( (__b2c__select_7182) == (12)){
#line 7445 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7446 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7447 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7448 "bacon.bac"
if( HASH(text__b2c__string_var) != cksum ){
#line 7449 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Code has changed! Save current to file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) file__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "' first (y/n)?"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7450 "bacon.bac"
if( GETKEY == ASC("y") ){
#line 7451 "bacon.bac"
ERROR = __b2c__save(0, 0, file__b2c__string_var, CHOP__b2c__string_var(text__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7451, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7452 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( " File '" , BASENAME__b2c__string_var(file__b2c__string_var) , "' saved! Press a key to continue...") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7453 "bacon.bac"
key=(
long)( GETKEY);
#line 7454 "bacon.bac"
}
#line 7455 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7456 "bacon.bac"
}
#line 7457 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7457, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7458 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Enter file name to load... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
answer__b2c__string_var = __b2c_Copy_String(answer__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 7459 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7459, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7460 "bacon.bac"
if( NOT(FILEEXISTS(answer__b2c__string_var)) ){
#line 7461 "bacon.bac"
fprintf(stdout,"\033[%ld%ldm", (long)3, (long)1); fflush(stdout);
#line 7462 "bacon.bac"
__b2c__assign = (char*)"WARNING: File does not exist!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 7463 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7464 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7465 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Press a key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7466 "bacon.bac"
key=(
long)( GETKEY);
#line 7467 "bacon.bac"
} else {
#line 7468 "bacon.bac"
file__b2c__string_var = __b2c_Copy_String(file__b2c__string_var, (char*) answer__b2c__string_var);
#line 7469 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) LOAD__b2c__string_var(file__b2c__string_var));
#line 7470 "bacon.bac"
start=(
long)( 1);
#line 7471 "bacon.bac"
visual_begin_pos=(
long)( 1);
#line 7472 "bacon.bac"
}
#line 7473 "bacon.bac"
do_print=(
long)( TRUE);
#line 7476 "bacon.bac"
} else  if ( (__b2c__select_7182) == (19)){
#line 7477 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7478 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7479 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7480 "bacon.bac"
if( LEN(file__b2c__string_var) ){
#line 7481 "bacon.bac"
ERROR = __b2c__save(0, 0, file__b2c__string_var, CHOP__b2c__string_var(text__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7481, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7482 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7483 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) CONCAT__b2c__string_var( "File '" , BASENAME__b2c__string_var(file__b2c__string_var) , "' saved!") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7484 "bacon.bac"
cksum=(
long)( HASH(text__b2c__string_var));
#line 7485 "bacon.bac"
} else {
#line 7486 "bacon.bac"
answer__b2c__string_var = __b2c_Copy_String(answer__b2c__string_var, (char*) "y");
#line 7487 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ECHO, 0);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7487, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7488 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Enter file name... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
file__b2c__string_var = __b2c_Copy_String(file__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 7489 "bacon.bac"
ERROR = __b2c_setserial(STDIN_FILENO, 3, 0, ~ECHO, 1);
if(ERROR){ RUNTIMEERROR("SETSERIAL", 7489, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7490 "bacon.bac"
if( FILEEXISTS(file__b2c__string_var) ){
__b2c__assign = (char*)"File '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) file__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "' exists! Overwrite (y/n)?"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
}
#line 7491 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7492 "bacon.bac"
if( GETKEY == ASC("y") ){
#line 7493 "bacon.bac"
ERROR = __b2c__save(0, 0, file__b2c__string_var, CHOP__b2c__string_var(text__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7493, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7494 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "File '" , BASENAME__b2c__string_var(file__b2c__string_var) , "' saved!") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7495 "bacon.bac"
cksum=(
long)( HASH(text__b2c__string_var));
#line 7496 "bacon.bac"
} else {
#line 7497 "bacon.bac"
__b2c__assign = (char*)"File NOT saved."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7498 "bacon.bac"
}
#line 7499 "bacon.bac"
}
#line 7500 "bacon.bac"
__b2c__assign = (char*)" Press a key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7501 "bacon.bac"
key=(
long)( GETKEY);
#line 7502 "bacon.bac"
do_print=(
long)( TRUE);
#line 7505 "bacon.bac"
} else  if ( (__b2c__select_7182) == (2)){
#line 7506 "bacon.bac"
Color_Intense=(long)( NOT(Color_Intense));
#line 7507 "bacon.bac"
if( FILEEXISTS( CONCAT__b2c__string_var(GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg" ) ) ){
#line 7508 "bacon.bac"
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) COLLAPSE__b2c__string_var(LOAD__b2c__string_var( CONCAT__b2c__string_var(GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg") ), NL__b2c__string_var));
#line 7509 "bacon.bac"
for(x=1; x <= AMOUNT(result__b2c__string_var, NL__b2c__string_var); x+=1){
#line 7510 "bacon.bac"
if( REGEX(TOKEN__b2c__string_var(result__b2c__string_var, x, NL__b2c__string_var), "^intense") ){
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) DEL__b2c__string_var(result__b2c__string_var, x, NL__b2c__string_var));
}
#line 7511 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7512 "bacon.bac"
ERROR = __b2c__save(0, 0, CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg"), APPEND__b2c__string_var(result__b2c__string_var, 0, CONCAT__b2c__string_var( "intense " , STR__b2c__string_var(Color_Intense)) , NL__b2c__string_var), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7512, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7513 "bacon.bac"
} else {
#line 7514 "bacon.bac"
ERROR = __b2c__save(0, 0, CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg"), CONCAT__b2c__string_var( "intense " , STR__b2c__string_var(Color_Intense) ), NULL);
if(ERROR) { RUNTIMEERROR("SAVE/BSAVE/APPEND/BAPPEND", 7514, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 7515 "bacon.bac"
}
#line 7516 "bacon.bac"
do_print=(
long)( TRUE);
#line 7519 "bacon.bac"
} else  if ( (__b2c__select_7182) == (23)){
#line 7520 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) DEL__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7521 "bacon.bac"
if( (ypos )> AMOUNT(text__b2c__string_var, NL__b2c__string_var)-start+1  AND  (ypos )> 1 ){
ypos = ypos - (1);
}
#line 7522 "bacon.bac"
do_print=(
long)( TRUE);
#line 7525 "bacon.bac"
} else  if ( (__b2c__select_7182) == (8)){
#line 7526 "bacon.bac"
fprintf(stdout,"\033[?25l"); fflush(stdout);
#line 7527 "bacon.bac"
Editor_Show_Help();
#line 7528 "bacon.bac"
fprintf(stdout,"\033[?25h"); fflush(stdout);
#line 7529 "bacon.bac"
do_print=(
long)( TRUE);
#line 7532 "bacon.bac"
} else  if ( (__b2c__select_7182) == (27)){
#line 7533 "bacon.bac"
special=(
long)( WAIT(STDIN_FILENO, 100));
#line 7534 "bacon.bac"
__b2c__select_7534 = (double)special;
#line 7536 "bacon.bac"
 if ( (__b2c__select_7534) == (79) || (__b2c__select_7534) == ( 91)){
#line 7537 "bacon.bac"
cursor=(
long)( WAIT(STDIN_FILENO, 100));
#line 7538 "bacon.bac"
__b2c__select_7538 = (double)cursor;
#line 7540 "bacon.bac"
 if ( (__b2c__select_7538) == (66)){
#line 7541 "bacon.bac"
if( start+ypos-1 == AMOUNT(text__b2c__string_var, NL__b2c__string_var)  AND  (LEN(TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var)) )> 0 ){
#line 7542 "bacon.bac"
text__b2c__string_var = F_APPEND__b2c__string_var(text__b2c__string_var,text__b2c__string_var, 0, "", NL__b2c__string_var);
#line 7543 "bacon.bac"
ypos=(
long)( AMOUNT(text__b2c__string_var, NL__b2c__string_var));
#line 7544 "bacon.bac"
if( (ypos )> ROWS ){
start=(
long)( AMOUNT(text__b2c__string_var, NL__b2c__string_var) - ROWS + 1);
}
#line 7545 "bacon.bac"
do_print=(
long)( TRUE);
#line 7546 "bacon.bac"
} else if( (start+ypos-1 )< AMOUNT(text__b2c__string_var, NL__b2c__string_var) ){
#line 7547 "bacon.bac"
ypos = ypos + (1);
#line 7548 "bacon.bac"
}
#line 7550 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7551 "bacon.bac"
x=(
long)( 1);
#line 7552 "bacon.bac"
real_xpos=(
long)( 1);
#line 7553 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7554 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7555 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7556 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7558 "bacon.bac"
x=(
long)( 1);
#line 7559 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7560 "bacon.bac"
while( (x )< real_xpos ){
#line 7561 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, x, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7562 "bacon.bac"
x = x + (1);
#line 7563 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7564 "bacon.bac"
visual_xpos = visual_xpos - ( visual_begin_pos-1);
#line 7566 "bacon.bac"
} else  if ( (__b2c__select_7538) == (65)){
#line 7567 "bacon.bac"
ypos = ypos - (1);
#line 7569 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7570 "bacon.bac"
x=(
long)( 1);
#line 7571 "bacon.bac"
real_xpos=(
long)( 1);
#line 7572 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7573 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7574 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7575 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7577 "bacon.bac"
x=(
long)( 1);
#line 7578 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7579 "bacon.bac"
while( (x )< real_xpos ){
#line 7580 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, x, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7581 "bacon.bac"
x = x + (1);
#line 7582 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7583 "bacon.bac"
visual_xpos = visual_xpos - ( visual_begin_pos-1);
#line 7585 "bacon.bac"
} else  if ( (__b2c__select_7538) == (67)){
#line 7586 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7587 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7588 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7590 "bacon.bac"
} else  if ( (__b2c__select_7538) == (68)){
#line 7591 "bacon.bac"
real_xpos = real_xpos - (1);
#line 7592 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7593 "bacon.bac"
visual_xpos = visual_xpos - ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7595 "bacon.bac"
} else  if ( (__b2c__select_7538) == (51)){
#line 7597 "bacon.bac"
delkey=(
long)( WAIT(STDIN_FILENO, 100));
#line 7598 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7599 "bacon.bac"
if( delkey == 126 ){
#line 7600 "bacon.bac"
if( (real_xpos )> LEN(line__b2c__string_var) ){
#line 7601 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) CHANGE__b2c__string_var(text__b2c__string_var, start+ypos-1, CONCAT__b2c__string_var( line__b2c__string_var , SPC__b2c__string_var(real_xpos-LEN(line__b2c__string_var)-1) , TOKEN__b2c__string_var(text__b2c__string_var, start+ypos, NL__b2c__string_var)) , NL__b2c__string_var));
#line 7602 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) DEL__b2c__string_var(text__b2c__string_var, start+ypos, NL__b2c__string_var));
#line 7603 "bacon.bac"
do_print=(
long)( TRUE);
#line 7604 "bacon.bac"
} else {
#line 7605 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) RIP__b2c__string_var(line__b2c__string_var, real_xpos, 1));
#line 7606 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) CHANGE__b2c__string_var(text__b2c__string_var, start+ypos-1, line__b2c__string_var, NL__b2c__string_var));
#line 7607 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7608 "bacon.bac"
if( real_xpos == LEN(line__b2c__string_var)+1  AND  (real_xpos )> 1 ){
real_xpos = real_xpos - (1);
}
#line 7610 "bacon.bac"
x=(
long)( 1);
#line 7611 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7612 "bacon.bac"
while( (x )< real_xpos ){
#line 7613 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, x, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7614 "bacon.bac"
x = x + (1);
#line 7615 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7616 "bacon.bac"
visual_xpos = visual_xpos - ( visual_begin_pos-1);
#line 7617 "bacon.bac"
do_print=(
long)( TRUE);
#line 7618 "bacon.bac"
}
#line 7620 "bacon.bac"
} else if( delkey == 59 ){
#line 7622 "bacon.bac"
delkey=(
long)( WAIT(STDIN_FILENO, 100));
#line 7623 "bacon.bac"
delkey=(
long)( WAIT(STDIN_FILENO, 100));
#line 7624 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) DEL__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7625 "bacon.bac"
if( (ypos )> AMOUNT(text__b2c__string_var, NL__b2c__string_var)-start+1  AND  (ypos )> 1 ){
ypos = ypos - (1);
}
#line 7626 "bacon.bac"
do_print=(
long)( TRUE);
#line 7627 "bacon.bac"
}
#line 7629 "bacon.bac"
} else  if ( (__b2c__select_7538) == (72) || (__b2c__select_7538) == ( 49)){
#line 7631 "bacon.bac"
if( cursor == 49 ){
delkey=(
long)( WAIT(STDIN_FILENO, 100));
}
#line 7632 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7633 "bacon.bac"
real_xpos=(
long)( 1);
#line 7634 "bacon.bac"
visual_begin_pos=(
long)( 1);
#line 7635 "bacon.bac"
do_print=(
long)( TRUE);
#line 7637 "bacon.bac"
} else  if ( (__b2c__select_7538) == (70) || (__b2c__select_7538) == ( 52)){
#line 7639 "bacon.bac"
if( cursor == 52 ){
delkey=(
long)( WAIT(STDIN_FILENO, 100));
}
#line 7640 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7641 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, CHR__b2c__string_var(9), SPC__b2c__string_var(4)));
#line 7642 "bacon.bac"
visual_xpos=(
long)( LEN(line__b2c__string_var) - visual_begin_pos + 1);
#line 7643 "bacon.bac"
if( (visual_xpos )> display_columns ){
#line 7644 "bacon.bac"
visual_begin_pos=(
long)( LEN(line__b2c__string_var) - display_columns + 1);
#line 7645 "bacon.bac"
visual_xpos=(
long)( display_columns);
#line 7646 "bacon.bac"
do_print=(
long)( TRUE);
#line 7647 "bacon.bac"
}
#line 7649 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7650 "bacon.bac"
x=(
long)( 1);
#line 7651 "bacon.bac"
real_xpos=(
long)( 1);
#line 7652 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7653 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7654 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7655 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7657 "bacon.bac"
} else  if ( (__b2c__select_7538) == (53)){
#line 7658 "bacon.bac"
page=(
long)( WAIT(STDIN_FILENO, 100));
#line 7659 "bacon.bac"
if( page == 126 ){
#line 7660 "bacon.bac"
if( (start )> ROWS ){
#line 7661 "bacon.bac"
start = start - ( ROWS);
#line 7662 "bacon.bac"
} else {
#line 7663 "bacon.bac"
start=(
long)( 1);
#line 7664 "bacon.bac"
}
#line 7665 "bacon.bac"
do_print=(
long)( TRUE);
#line 7666 "bacon.bac"
}
#line 7668 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7669 "bacon.bac"
x=(
long)( 1);
#line 7670 "bacon.bac"
real_xpos=(
long)( 1);
#line 7671 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7672 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7673 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7674 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7676 "bacon.bac"
x=(
long)( 1);
#line 7677 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7678 "bacon.bac"
while( (x )< real_xpos ){
#line 7679 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, x, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7680 "bacon.bac"
x = x + (1);
#line 7681 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7682 "bacon.bac"
visual_xpos = visual_xpos - ( visual_begin_pos-1);
#line 7684 "bacon.bac"
} else  if ( (__b2c__select_7538) == (54)){
#line 7685 "bacon.bac"
page=(
long)( WAIT(STDIN_FILENO, 100));
#line 7686 "bacon.bac"
if( page == 126 ){
#line 7687 "bacon.bac"
if( (start + 2*ROWS - 1 )< AMOUNT(text__b2c__string_var, NL__b2c__string_var) ){
#line 7688 "bacon.bac"
start = start + ( ROWS);
#line 7689 "bacon.bac"
} else {
#line 7690 "bacon.bac"
start=(
long)( AMOUNT(text__b2c__string_var, NL__b2c__string_var)-ROWS+1);
#line 7691 "bacon.bac"
if( (start )< 1 ){
start=(
long)( 1);
}
#line 7692 "bacon.bac"
}
#line 7693 "bacon.bac"
do_print=(
long)( TRUE);
#line 7694 "bacon.bac"
}
#line 7696 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7697 "bacon.bac"
x=(
long)( 1);
#line 7698 "bacon.bac"
real_xpos=(
long)( 1);
#line 7699 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7700 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7701 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7702 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7704 "bacon.bac"
x=(
long)( 1);
#line 7705 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7706 "bacon.bac"
while( (x )< real_xpos ){
#line 7707 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, x, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7708 "bacon.bac"
x = x + (1);
#line 7709 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7710 "bacon.bac"
visual_xpos = visual_xpos - ( visual_begin_pos-1);
#line 7711 "bacon.bac"
}
#line 7713 "bacon.bac"
if( (ypos )< 1 ){
#line 7714 "bacon.bac"
start = start - (1);
#line 7715 "bacon.bac"
ypos=(
long)( 1);
#line 7716 "bacon.bac"
if( (start )< 1 ){
#line 7717 "bacon.bac"
start=(
long)( 1);
#line 7718 "bacon.bac"
} else {
#line 7719 "bacon.bac"
fprintf(stdout,"\033[%ldT", (long)1); fflush(stdout);
#line 7720 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start, NL__b2c__string_var));
#line 7721 "bacon.bac"
do_print=(
long)( TRUE);
#line 7722 "bacon.bac"
}
#line 7723 "bacon.bac"
}
#line 7724 "bacon.bac"
if( (ypos )> ROWS ){
#line 7725 "bacon.bac"
start = start + (1);
#line 7726 "bacon.bac"
ypos=(
long)( ROWS);
#line 7727 "bacon.bac"
if( (start+ROWS-1 )> AMOUNT(text__b2c__string_var, NL__b2c__string_var) ){
#line 7728 "bacon.bac"
start=(
long)( AMOUNT(text__b2c__string_var, NL__b2c__string_var) - ROWS + 1);
#line 7729 "bacon.bac"
} else {
#line 7730 "bacon.bac"
fprintf(stdout,"\033[%ldS", (long)1); fflush(stdout);
#line 7731 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ROWS-1, NL__b2c__string_var));
#line 7732 "bacon.bac"
do_print=(
long)( TRUE);
#line 7733 "bacon.bac"
}
#line 7734 "bacon.bac"
}
#line 7736 "bacon.bac"
if( (visual_xpos )< 1 ){
#line 7737 "bacon.bac"
while( (visual_begin_pos )> 1  AND  (visual_xpos )< 1 ){
#line 7738 "bacon.bac"
visual_begin_pos = visual_begin_pos - (1);
#line 7739 "bacon.bac"
visual_xpos = visual_xpos + (1);
#line 7740 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7741 "bacon.bac"
if( (visual_begin_pos )< 1 ){
visual_begin_pos=(
long)( 1);
}
#line 7742 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7744 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7745 "bacon.bac"
x=(
long)( 1);
#line 7746 "bacon.bac"
real_xpos=(
long)( 1);
#line 7747 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7748 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7749 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7750 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7751 "bacon.bac"
do_print=(
long)( TRUE);
#line 7752 "bacon.bac"
}
#line 7754 "bacon.bac"
if( (visual_xpos )> display_columns ){
#line 7755 "bacon.bac"
visual_begin_pos = visual_begin_pos + (1);
#line 7756 "bacon.bac"
visual_xpos=(
long)( display_columns);
#line 7758 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7759 "bacon.bac"
x=(
long)( 1);
#line 7760 "bacon.bac"
real_xpos=(
long)( 1);
#line 7761 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7762 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7763 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7764 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7766 "bacon.bac"
if( (visual_begin_pos - 1 + visual_xpos )> display_columns  AND  __b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos-1, 1) ,  CHR__b2c__string_var(9)) == 0 ){
visual_begin_pos = visual_begin_pos + ( 3);
}
#line 7767 "bacon.bac"
do_print=(
long)( TRUE);
#line 7768 "bacon.bac"
}
#line 7769 "bacon.bac"
}
#line 7771 "bacon.bac"
} else  if ( (__b2c__select_7182) == (127)){
#line 7772 "bacon.bac"
if( (real_xpos )> 1 ){
#line 7773 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7774 "bacon.bac"
if( real_xpos <= LEN(line__b2c__string_var)+1 ){
#line 7775 "bacon.bac"
line__b2c__string_var = F_CONCAT__b2c__string_var(line__b2c__string_var, LEFT__b2c__string_var(line__b2c__string_var, real_xpos-2) , MID__b2c__string_var(line__b2c__string_var, real_xpos)) ;
#line 7776 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) CHANGE__b2c__string_var(text__b2c__string_var, start+ypos-1, line__b2c__string_var, NL__b2c__string_var));
#line 7777 "bacon.bac"
}
#line 7778 "bacon.bac"
real_xpos = real_xpos - (1);
#line 7780 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7781 "bacon.bac"
x=(
long)( 1);
#line 7782 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7783 "bacon.bac"
while( (x )< real_xpos ){
#line 7784 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, x, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7785 "bacon.bac"
x = x + (1);
#line 7786 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7787 "bacon.bac"
visual_xpos = visual_xpos - ( visual_begin_pos-1);
#line 7789 "bacon.bac"
if( (visual_xpos )< 1 ){
#line 7790 "bacon.bac"
while( (visual_begin_pos )> 1 ){
#line 7791 "bacon.bac"
visual_begin_pos = visual_begin_pos - (1);
#line 7792 "bacon.bac"
visual_xpos = visual_xpos + (1);
#line 7793 "bacon.bac"
if( visual_xpos == 1 ){
break;
}
#line 7794 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7795 "bacon.bac"
}
#line 7796 "bacon.bac"
do_print=(
long)( TRUE);
#line 7797 "bacon.bac"
} else if( NOT(ypos == 1  AND  start == 1) ){
#line 7799 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-2, NL__b2c__string_var));
#line 7800 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, CHR__b2c__string_var(9), SPC__b2c__string_var(4)));
#line 7801 "bacon.bac"
visual_xpos=(
long)( LEN(line__b2c__string_var) - visual_begin_pos + 2);
#line 7803 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7804 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) CHANGE__b2c__string_var(text__b2c__string_var, start+ypos-2, CONCAT__b2c__string_var( TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-2, NL__b2c__string_var) , line__b2c__string_var) , NL__b2c__string_var));
#line 7805 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) DEL__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7806 "bacon.bac"
if( AMOUNT(text__b2c__string_var, NL__b2c__string_var) <= ROWS ){
#line 7807 "bacon.bac"
ypos = ypos + ( start-1);
#line 7808 "bacon.bac"
start=(
long)( 1);
#line 7809 "bacon.bac"
}
#line 7810 "bacon.bac"
if( (ypos )> 1 ){
#line 7811 "bacon.bac"
ypos = ypos - (1);
#line 7812 "bacon.bac"
} else {
#line 7813 "bacon.bac"
start = start - ( IIF((start )> 1, 1, 0));
#line 7814 "bacon.bac"
}
#line 7816 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7817 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, CHR__b2c__string_var(9), SPC__b2c__string_var(4)));
#line 7818 "bacon.bac"
if( (visual_xpos )> display_columns ){
#line 7819 "bacon.bac"
visual_begin_pos=(
long)( visual_xpos - display_columns + 1);
#line 7820 "bacon.bac"
visual_xpos=(
long)( display_columns);
#line 7821 "bacon.bac"
}
#line 7823 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7824 "bacon.bac"
x=(
long)( 1);
#line 7825 "bacon.bac"
real_xpos=(
long)( 1);
#line 7826 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7827 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7828 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7829 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7830 "bacon.bac"
do_print=(
long)( TRUE);
#line 7831 "bacon.bac"
}
#line 7833 "bacon.bac"
} else  if ( (__b2c__select_7182) == (10)){
#line 7834 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7835 "bacon.bac"
if( (visual_xpos )> LEN(REPLACE__b2c__string_var(line__b2c__string_var, CHR__b2c__string_var(9), SPC__b2c__string_var(4))) ){
#line 7836 "bacon.bac"
text__b2c__string_var = F_APPEND__b2c__string_var(text__b2c__string_var,text__b2c__string_var, start+ypos, "", NL__b2c__string_var);
#line 7837 "bacon.bac"
} else {
#line 7838 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) CHANGE__b2c__string_var(text__b2c__string_var, start+ypos-1, LEFT__b2c__string_var(line__b2c__string_var, real_xpos-1), NL__b2c__string_var));
#line 7839 "bacon.bac"
text__b2c__string_var = F_APPEND__b2c__string_var(text__b2c__string_var,text__b2c__string_var, start+ypos, MID__b2c__string_var(line__b2c__string_var, real_xpos), NL__b2c__string_var);
#line 7840 "bacon.bac"
}
#line 7841 "bacon.bac"
if( ypos == ROWS ){
start = start + (1);
}
#line 7842 "bacon.bac"
if( (ypos )< ROWS ){
ypos = ypos + (1);
}
#line 7843 "bacon.bac"
visual_xpos=(
long)( 1);
#line 7844 "bacon.bac"
real_xpos=(
long)( 1);
#line 7845 "bacon.bac"
visual_begin_pos=(
long)( 1);
#line 7846 "bacon.bac"
do_print=(
long)( TRUE);
#line 7848 "bacon.bac"
} else {
#line 7849 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7850 "bacon.bac"
if( (key )< 32  AND  key != 9 ){
key=(
long)( 32);
}
#line 7851 "bacon.bac"
if( (real_xpos )> LEN(line__b2c__string_var) ){
#line 7852 "bacon.bac"
line__b2c__string_var = F_CONCAT__b2c__string_var(line__b2c__string_var, line__b2c__string_var , SPC__b2c__string_var(real_xpos-LEN(line__b2c__string_var)-1) , CHR__b2c__string_var(key)) ;
#line 7853 "bacon.bac"
} else {
#line 7854 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) INSERT__b2c__string_var(line__b2c__string_var, real_xpos, CHR__b2c__string_var(key)));
#line 7855 "bacon.bac"
}
#line 7856 "bacon.bac"
text__b2c__string_var = __b2c_Copy_String(text__b2c__string_var, (char*) CHANGE__b2c__string_var(text__b2c__string_var, start+ypos-1, line__b2c__string_var, NL__b2c__string_var));
#line 7858 "bacon.bac"
if( (visual_xpos )< display_columns ){
#line 7859 "bacon.bac"
visual_xpos = visual_xpos + ( IIF(key == 9, 4, 1));
#line 7860 "bacon.bac"
} else {
#line 7861 "bacon.bac"
visual_begin_pos = visual_begin_pos + ( IIF(key == 9, 4, 1));
#line 7862 "bacon.bac"
}
#line 7864 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-1, NL__b2c__string_var));
#line 7865 "bacon.bac"
x=(
long)( 1);
#line 7866 "bacon.bac"
real_xpos=(
long)( 1);
#line 7867 "bacon.bac"
while( (x )< visual_begin_pos - 1 + visual_xpos ){
#line 7868 "bacon.bac"
x = x + ( IIF(__b2c__STRCMP(MID__b2c__string_var(line__b2c__string_var, real_xpos, 1) ,  CHR__b2c__string_var(9)) == 0, 4, 1));
#line 7869 "bacon.bac"
real_xpos = real_xpos + (1);
#line 7870 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7871 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ypos),(long)(1));fflush(stdout);
#line 7872 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(TOKEN__b2c__string_var(text__b2c__string_var, start+ypos-2, NL__b2c__string_var), 2) ,  CONCAT__b2c__string_var( CHR__b2c__string_var(32) , CHR__b2c__string_var(92) )) == 0 ){
#line 7873 "bacon.bac"
do_print=(
long)( TRUE);
#line 7874 "bacon.bac"
} else {
#line 7875 "bacon.bac"
Editor_Print_Line(line__b2c__string_var, visual_begin_pos, start+ypos-1, FALSE, digits, TRUE);
#line 7876 "bacon.bac"
}
#line 7877 "bacon.bac"
}
#line 7878 "bacon.bac"
if( do_print ){
Editor_Print_Text(text__b2c__string_var, start, visual_begin_pos);
}
#line 7879 "bacon.bac"
do_print=(
long)( FALSE);
#line 7881 "bacon.bac"
if( copy_flag ){
#line 7882 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(COLUMNS/2-15));fflush(stdout);
#line 7883 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7884 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7885 "bacon.bac"
fputs("\033[5m", stdout); fflush(stdout);
#line 7886 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "---=== line copied to clipboard ===---"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7887 "bacon.bac"
fputs("\033[25m", stdout); fflush(stdout);
#line 7888 "bacon.bac"
}
#line 7889 "bacon.bac"
} while(!( special == 0  AND  key == 27 ));
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 7891 "bacon.bac"
fprintf(stdout, "\033[%ld;%ldH",(long)( ROWS),(long)(1));fflush(stdout);
#line 7892 "bacon.bac"
fputs("\033[0m", stdout); fflush(stdout);
#line 7893 "bacon.bac"
if( Color_Intense ){
fputs("\033[1m", stdout); fflush(stdout);
}
#line 7894 "bacon.bac"
__b2c__assign = (char*)CL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Press (H) for Help, (Q) to quit, any other key to continue..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 7895 "bacon.bac"
key=(
long)( GETKEY);
#line 7896 "bacon.bac"
__b2c__select_7896__b2c__string_var = __b2c_Copy_String(__b2c__select_7896__b2c__string_var, LCASE__b2c__string_var(CHR__b2c__string_var(key)));
#line 7897 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_7896__b2c__string_var, "h")){
#line 7898 "bacon.bac"
Editor_Show_Help();
#line 7899 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_7896__b2c__string_var, "q")){
#line 7900 "bacon.bac"
break;
#line 7901 "bacon.bac"
}
#line 7902 "bacon.bac"
Editor_Print_Text(text__b2c__string_var, start, visual_begin_pos);
#line 7903 "bacon.bac"
}
#line 7905 "bacon.bac"
Editor_Restore_Normal();
#line 7907 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_line_input__b2c__string_var_string); __b2c__forin_line_input__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_line_input__b2c__string_var_step); __b2c__forin_line_input__b2c__string_var_step = NULL;
__b2c__STRFREE(file__b2c__string_var);
__b2c__STRFREE(text__b2c__string_var);
__b2c__STRFREE(line__b2c__string_var);
__b2c__STRFREE(prog__b2c__string_var);
__b2c__STRFREE(answer__b2c__string_var);
__b2c__STRFREE(option__b2c__string_var);
__b2c__STRFREE(man__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(result__b2c__string_var);
__b2c__STRFREE(copy_line__b2c__string_var);
__b2c__STRFREE(word__b2c__string_var);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(line_input__b2c__string_var);
__b2c__STRFREE(__b2c__select_7896__b2c__string_var);
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
