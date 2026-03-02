/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Parse_Line( char *__b2c_statement__b2c__string_var) {
 char*statement__b2c__string_var = NULL; statement__b2c__string_var = __b2c_Copy_String(NULL, __b2c_statement__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **element__b2c__string_var = NULL; long element__b2c__string_var__b2c_array = 0; char *__b2c__select_4250__b2c__string_var = NULL; char *__b2c__select_4459__b2c__string_var = NULL; char *__b2c__select_4580__b2c__string_var = NULL; int __b2c__forin_str__b2c__string_var_ptr = 0; char* __b2c__forin_str__b2c__string_var_string = NULL; char* __b2c__forin_str__b2c__string_var_string_org = NULL; char* __b2c__forin_str__b2c__string_var_step = NULL; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; int __b2c__forin_sym__b2c__string_var_ptr = 0; char* __b2c__forin_sym__b2c__string_var_string = NULL; char* __b2c__forin_sym__b2c__string_var_string_org = NULL; char* __b2c__forin_sym__b2c__string_var_step = NULL; char *__b2c__select_5433__b2c__string_var = NULL; char **symbol__b2c__string_var = NULL; long symbol__b2c__string_var__b2c_array = 0; int __b2c__forin_exp__b2c__string_var_ptr = 0; char* __b2c__forin_exp__b2c__string_var_string = NULL; char* __b2c__forin_exp__b2c__string_var_string_org = NULL; char* __b2c__forin_exp__b2c__string_var_step = NULL;
#line 4207 "bacon.bac"
char *inc__b2c__string_var = NULL;
char *copy_curfile__b2c__string_var = NULL;
char *total__b2c__string_var = NULL;
char *txt__b2c__string_var = NULL;
char *sym__b2c__string_var = NULL;
char *exp__b2c__string_var = NULL;
char *then__b2c__string_var = NULL;
char *lft__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *newfeed__b2c__string_var = NULL;
char *token__b2c__string_var = NULL;
char *rel__b2c__string_var = NULL;
char *uniq__b2c__string_var = NULL;
#line 4208 "bacon.bac"
long dim = 0;
long i = 0;
long found = 0;
long copy_counter = 0;
long to_parse = 0;
long size = 0;
long trc_backup = 0;
#line 4209 "bacon.bac"
FILE* newfile = NULL;
FILE* src_tmp = NULL;
FILE* src_in = NULL;
FILE* src_out = NULL;
#line 4211 "bacon.bac"
__b2c__split_by(&element__b2c__string_var, 1, &element__b2c__string_var__b2c_array, statement__b2c__string_var, __b2c__option_delim);
dim = element__b2c__string_var__b2c_array;
#line 4213 "bacon.bac"
if( (dim )> 0 ){
#line 4216 "bacon.bac"
if( ISTRUE(g_USE_C) ){
#line 4217 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(statement__b2c__string_var, 8) ,  "END USEC") == 0  OR  __b2c__STRCMP(element__b2c__string_var[(uint64_t)1] ,  "ENDUSEC") == 0 ){
#line 4218 "bacon.bac"
g_USE_C=(long)( 0);
#line 4219 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(statement__b2c__string_var, 8) ,  "END ENUM") == 0  OR  __b2c__STRCMP(element__b2c__string_var[(uint64_t)1] ,  "ENDENUM") == 0 ){
#line 4220 "bacon.bac"
g_USE_C=(long)( 0);
#line 4221 "bacon.bac"
__b2c__assign = (char*)"};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4222 "bacon.bac"
} else {
#line 4223 "bacon.bac"
__b2c__assign = (char*)statement__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4224 "bacon.bac"
}
#line 4226 "bacon.bac"
} else if( ISTRUE(g_USE_H) ){
#line 4227 "bacon.bac"
if( REGEX(statement__b2c__string_var, "END.*USEH") ){
#line 4228 "bacon.bac"
g_USE_H=(long)( 0);
#line 4229 "bacon.bac"
} else if( REGEX(statement__b2c__string_var, "END.*ENUM")  OR  REGEX(statement__b2c__string_var, "END.*CLASS") ){
#line 4230 "bacon.bac"
g_USE_H=(long)( 0);
#line 4231 "bacon.bac"
__b2c__assign = (char*)"};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4232 "bacon.bac"
} else {
#line 4233 "bacon.bac"
__b2c__assign = (char*)statement__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4234 "bacon.bac"
}
#line 4236 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)1], 2) ,  "#!") == 0 ){
#line 4239 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)1], 1) ,  "'") == 0 ){
#line 4242 "bacon.bac"
} else if( __b2c__STRCMP(RIGHT__b2c__string_var(element__b2c__string_var[(uint64_t)dim], 2) ,  "*/") == 0 ){
#line 4243 "bacon.bac"
g_COMMENT=(long)( FALSE);
#line 4245 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)1], 2) ,  "/*") == 0 ){
#line 4246 "bacon.bac"
g_COMMENT=(long)( TRUE);
#line 4248 "bacon.bac"
} else if( g_COMMENT == FALSE ){
#line 4250 "bacon.bac"
__b2c__select_4250__b2c__string_var = __b2c_Copy_String(__b2c__select_4250__b2c__string_var, element__b2c__string_var[(uint64_t)1]);
#line 4251 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "USEC")){
#line 4252 "bacon.bac"
g_USE_C=(long)( 1);
#line 4254 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "USEH")){
#line 4255 "bacon.bac"
g_USE_H=(long)( 1);
#line 4257 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CLASS")){
#line 4258 "bacon.bac"
g_USE_H=(long)( 1);
#line 4259 "bacon.bac"
__b2c__assign = (char*)"class "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(statement__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "{"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4261 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PRINT")){
#line 4262 "bacon.bac"
Handle_Print(statement__b2c__string_var, "stdout");
#line 4264 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "EPRINT")){
#line 4265 "bacon.bac"
Handle_Print(MID__b2c__string_var(statement__b2c__string_var, 2), "stderr");
#line 4267 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "INPUT")){
#line 4268 "bacon.bac"
Handle_Input(statement__b2c__string_var);
#line 4270 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "FOR")){
#line 4271 "bacon.bac"
g_LOOPCTR = g_LOOPCTR + (1);
#line 4272 "bacon.bac"
Handle_For(statement__b2c__string_var);
#line 4274 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "NEXT")){
#line 4275 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4276 "bacon.bac"
if( (g_LOOPCTR )> 0  AND  g_OPTION_BREAK ){
#line 4277 "bacon.bac"
g_LOOPCTR = g_LOOPCTR - (1);
#line 4278 "bacon.bac"
if( (g_LOOPCTR )> 0 ){
#line 4279 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4280 "bacon.bac"
}
#line 4281 "bacon.bac"
}
#line 4283 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "IF")){
#line 4285 "bacon.bac"
if( NOT(ISTOKEN(statement__b2c__string_var, "THEN")) ){
#line 4286 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing THEN in IF statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4287 "bacon.bac"
exit(1);
#line 4288 "bacon.bac"
} else {
#line 4290 "bacon.bac"
then__b2c__string_var = F_CHOP__b2c__string_var(then__b2c__string_var,LAST__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "THEN")));
#line 4291 "bacon.bac"
sym__b2c__string_var = __b2c_Copy_String(sym__b2c__string_var, (char*) HEAD__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "THEN")-1));
#line 4292 "bacon.bac"
exp__b2c__string_var = F_CHOP__b2c__string_var(exp__b2c__string_var,LAST__b2c__string_var(sym__b2c__string_var, ISTOKEN(sym__b2c__string_var, "IF")));
#line 4293 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) Parse_Equation__b2c__string_var(exp__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4294 "bacon.bac"
if( (LEN(then__b2c__string_var) )> 0 ){
#line 4295 "bacon.bac"
trc_backup=(
long)( g_TRACE);
#line 4296 "bacon.bac"
g_TRACE=(long)( 0);
#line 4297 "bacon.bac"
Tokenize(then__b2c__string_var);
#line 4298 "bacon.bac"
g_TRACE=(long)( trc_backup);
#line 4299 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4300 "bacon.bac"
}
#line 4301 "bacon.bac"
}
#line 4303 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ELIF")){
#line 4305 "bacon.bac"
if( NOT(ISTOKEN(statement__b2c__string_var, "THEN")) ){
#line 4306 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing THEN in ELIF statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4307 "bacon.bac"
exit(1);
#line 4308 "bacon.bac"
} else {
#line 4310 "bacon.bac"
then__b2c__string_var = F_CHOP__b2c__string_var(then__b2c__string_var,LAST__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "THEN")));
#line 4311 "bacon.bac"
sym__b2c__string_var = __b2c_Copy_String(sym__b2c__string_var, (char*) HEAD__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "THEN")-1));
#line 4312 "bacon.bac"
exp__b2c__string_var = F_CHOP__b2c__string_var(exp__b2c__string_var,LAST__b2c__string_var(sym__b2c__string_var, ISTOKEN(sym__b2c__string_var, "ELIF")));
#line 4313 "bacon.bac"
if( (LEN(then__b2c__string_var) )> 0 ){
#line 4314 "bacon.bac"
if( g_TRACE == 1 ){
#line 4315 "bacon.bac"
g_TRACE_PREFIX__b2c__string_var = F_CONCAT__b2c__string_var(g_TRACE_PREFIX__b2c__string_var, "RUNTIMEDEBUG(" , g_CURFILE__b2c__string_var , ", " , STR__b2c__string_var(g_COUNTER) , ", \"" , REPLACE__b2c__string_var(statement__b2c__string_var, CONCAT__b2c__string_var( CHR__b2c__string_var(34) , CHR__b2c__string_var(92)) , CONCAT__b2c__string_var( CHR__b2c__string_var(39) , CHR__b2c__string_var(47)) , 2) , "\")") ;
#line 4316 "bacon.bac"
__b2c__assign = (char*)"else if(!("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_TRACE_PREFIX__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")){ ; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4317 "bacon.bac"
}
#line 4318 "bacon.bac"
__b2c__assign = (char*)"else if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) Parse_Equation__b2c__string_var(exp__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4319 "bacon.bac"
Tokenize(then__b2c__string_var);
#line 4320 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4321 "bacon.bac"
} else {
#line 4322 "bacon.bac"
if( g_TRACE == 1 ){
#line 4323 "bacon.bac"
g_TRACE_PREFIX__b2c__string_var = F_CONCAT__b2c__string_var(g_TRACE_PREFIX__b2c__string_var, "RUNTIMEDEBUG(" , g_CURFILE__b2c__string_var , ", " , STR__b2c__string_var(g_COUNTER) , ", \"ELIF " , REPLACE__b2c__string_var(exp__b2c__string_var, CONCAT__b2c__string_var( CHR__b2c__string_var(34) , CHR__b2c__string_var(92)) , CONCAT__b2c__string_var( CHR__b2c__string_var(39) , CHR__b2c__string_var(47)) , 2) , "\")") ;
#line 4324 "bacon.bac"
__b2c__assign = (char*)"} else if(!("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_TRACE_PREFIX__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")){ ;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4325 "bacon.bac"
}
#line 4326 "bacon.bac"
__b2c__assign = (char*)"} else if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) Parse_Equation__b2c__string_var(exp__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4327 "bacon.bac"
if( g_TRACE == 1 ){
g_TRACE_PREFIX__b2c__string_var = __b2c_Copy_String(g_TRACE_PREFIX__b2c__string_var, (char*) "");
}
#line 4328 "bacon.bac"
}
#line 4329 "bacon.bac"
}
#line 4331 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ELSE")){
#line 4333 "bacon.bac"
exp__b2c__string_var = F_CHOP__b2c__string_var(exp__b2c__string_var,LAST__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "ELSE")));
#line 4334 "bacon.bac"
if( (LEN(exp__b2c__string_var) )> 0 ){
#line 4335 "bacon.bac"
if( g_TRACE == 1 ){
#line 4336 "bacon.bac"
g_TRACE_PREFIX__b2c__string_var = F_CONCAT__b2c__string_var(g_TRACE_PREFIX__b2c__string_var, "RUNTIMEDEBUG(" , g_CURFILE__b2c__string_var , ", " , STR__b2c__string_var(g_COUNTER) , ", \"" , REPLACE__b2c__string_var(statement__b2c__string_var, CONCAT__b2c__string_var( CHR__b2c__string_var(34) , CHR__b2c__string_var(92)) , CONCAT__b2c__string_var( CHR__b2c__string_var(39) , CHR__b2c__string_var(47)) , 2) , "\")") ;
#line 4337 "bacon.bac"
__b2c__assign = (char*)"else if(!("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_TRACE_PREFIX__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")){ ; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4338 "bacon.bac"
}
#line 4339 "bacon.bac"
__b2c__assign = (char*)"else {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4340 "bacon.bac"
Tokenize(exp__b2c__string_var);
#line 4341 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4342 "bacon.bac"
} else {
#line 4343 "bacon.bac"
if( g_TRACE == 1 ){
#line 4344 "bacon.bac"
g_TRACE_PREFIX__b2c__string_var = F_CONCAT__b2c__string_var(g_TRACE_PREFIX__b2c__string_var, "RUNTIMEDEBUG(" , g_CURFILE__b2c__string_var , ", " , STR__b2c__string_var(g_COUNTER) , ", \"ELSE\")") ;
#line 4345 "bacon.bac"
__b2c__assign = (char*)"} else if(!("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_TRACE_PREFIX__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")){ ;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4346 "bacon.bac"
}
#line 4347 "bacon.bac"
__b2c__assign = (char*)"} else {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4348 "bacon.bac"
if( g_TRACE == 1 ){
g_TRACE_PREFIX__b2c__string_var = __b2c_Copy_String(g_TRACE_PREFIX__b2c__string_var, (char*) "");
}
#line 4349 "bacon.bac"
}
#line 4351 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "FI")){
#line 4352 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4354 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DOTIMES")){
#line 4356 "bacon.bac"
if( dim == 1 ){
#line 4357 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty DOTIMES at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4358 "bacon.bac"
exit(1);
#line 4359 "bacon.bac"
} else {
#line 4360 "bacon.bac"
__b2c__assign = (char*)"long __do_times_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_DOTIMES), g_HFILE);
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4361 "bacon.bac"
__b2c__assign = (char*)"for(__do_times_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_DOTIMES), g_CFILE);
__b2c__assign = (char*) " = 0; __do_times_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_DOTIMES), g_CFILE);
__b2c__assign = (char*) "<"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "DOTIMES") + 7); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __do_times_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_DOTIMES), g_CFILE);
__b2c__assign = (char*) "++) { _ = __do_times_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_DOTIMES), g_CFILE);
__b2c__assign = (char*) "+1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4362 "bacon.bac"
g_DOTIMES = g_DOTIMES + (1);
#line 4363 "bacon.bac"
}
#line 4365 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DO")){
#line 4366 "bacon.bac"
__b2c__assign = (char*)"{"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4368 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DONE")){
#line 4369 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4371 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "WHILE")){
#line 4372 "bacon.bac"
g_LOOPCTR = g_LOOPCTR + (1);
#line 4373 "bacon.bac"
Handle_While(statement__b2c__string_var);
#line 4375 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "WEND")){
#line 4376 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4377 "bacon.bac"
if( (g_LOOPCTR )> 0  AND  g_OPTION_BREAK ){
#line 4378 "bacon.bac"
g_LOOPCTR = g_LOOPCTR - (1);
#line 4379 "bacon.bac"
if( (g_LOOPCTR )> 0 ){
#line 4380 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4381 "bacon.bac"
}
#line 4382 "bacon.bac"
}
#line 4384 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "BREAK")){
#line 4386 "bacon.bac"
if( g_OPTION_BREAK ){
#line 4387 "bacon.bac"
if( (dim )> 1  AND  VAL(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "BREAK") + 5)) != 0 ){
#line 4388 "bacon.bac"
__b2c__assign = (char*)"__b2c__break_ctr = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "BREAK") + 5); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "-1; __b2c__break_flag = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4389 "bacon.bac"
}
#line 4390 "bacon.bac"
__b2c__assign = (char*)"break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4391 "bacon.bac"
} else {
#line 4392 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: use of BREAK at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was disbaled!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4393 "bacon.bac"
exit(1);
#line 4394 "bacon.bac"
}
#line 4396 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CONTINUE")){
#line 4398 "bacon.bac"
if( (dim )> 1  AND  VAL(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "CONTINUE") + 8)) != 0 ){
#line 4399 "bacon.bac"
__b2c__assign = (char*)"__b2c__break_ctr = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "CONTINUE") + 8); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "-1; __b2c__break_flag = 2;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4400 "bacon.bac"
}
#line 4401 "bacon.bac"
if( (VAL(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "CONTINUE") + 8)) )> 1 ){
#line 4402 "bacon.bac"
__b2c__assign = (char*)"break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4403 "bacon.bac"
} else {
#line 4404 "bacon.bac"
__b2c__assign = (char*)"continue;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4405 "bacon.bac"
}
#line 4407 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "REPEAT")){
#line 4408 "bacon.bac"
g_LOOPCTR = g_LOOPCTR + (1);
#line 4409 "bacon.bac"
__b2c__assign = (char*)"do{"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4411 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var,  "UNTIL")){
#line 4413 "bacon.bac"
if( dim == 1 ){
#line 4414 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty UNTIL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4415 "bacon.bac"
exit(1);
#line 4416 "bacon.bac"
} else {
#line 4418 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) Parse_Equation__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "UNTIL") + 5) ));
#line 4419 "bacon.bac"
__b2c__assign = (char*)"} while(!("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4420 "bacon.bac"
if( (g_LOOPCTR )> 0  AND  g_OPTION_BREAK ){
#line 4421 "bacon.bac"
g_LOOPCTR = g_LOOPCTR - (1);
#line 4422 "bacon.bac"
if( (g_LOOPCTR )> 0 ){
#line 4423 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4424 "bacon.bac"
}
#line 4425 "bacon.bac"
}
#line 4426 "bacon.bac"
}
#line 4428 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "LET")){
#line 4429 "bacon.bac"
Handle_Let(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "LET") + 3));
#line 4431 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SYSTEM")){
#line 4433 "bacon.bac"
if( dim == 1 ){
#line 4434 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SYSTEM at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4435 "bacon.bac"
exit(1);
#line 4436 "bacon.bac"
} else {
#line 4437 "bacon.bac"
__b2c__assign = (char*)"RETVAL = system("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(statement__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4438 "bacon.bac"
}
#line 4440 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SLEEP")){
#line 4442 "bacon.bac"
if( dim == 1 ){
#line 4443 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SLEEP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4444 "bacon.bac"
exit(1);
#line 4445 "bacon.bac"
} else {
#line 4446 "bacon.bac"
__b2c__assign = (char*)"usleep("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SLEEP") + 5); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*1000);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4447 "bacon.bac"
}
#line 4449 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "OPEN")){
#line 4450 "bacon.bac"
Handle_Open(statement__b2c__string_var);
#line 4452 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CLOSE")){
#line 4454 "bacon.bac"
if( (dim )< 3 ){
#line 4455 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CLOSE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4456 "bacon.bac"
exit(1);
#line 4457 "bacon.bac"
} else {
#line 4458 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(statement__b2c__string_var));
#line 4459 "bacon.bac"
__b2c__select_4459__b2c__string_var = __b2c_Copy_String(__b2c__select_4459__b2c__string_var, element__b2c__string_var[(uint64_t)2]);
#line 4460 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "FILE")){
#line 4461 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(exp__b2c__string_var));
#line 4462 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 4463 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4464 "bacon.bac"
__b2c__assign = (char*)"fclose("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4465 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4466 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,token__b2c__string_var);
#line 4467 "bacon.bac"
__b2c__hash_del(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var, token__b2c__string_var);
#line 4468 "bacon.bac"
}
#line 4469 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "DIRECTORY")){
#line 4470 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(exp__b2c__string_var));
#line 4471 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 4472 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4473 "bacon.bac"
__b2c__assign = (char*)"closedir("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4474 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4475 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,token__b2c__string_var);
#line 4476 "bacon.bac"
__b2c__hash_del(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var, token__b2c__string_var);
#line 4477 "bacon.bac"
}
#line 4478 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "MEMORY")){
#line 4479 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(exp__b2c__string_var));
#line 4480 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 4481 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4482 "bacon.bac"
__b2c__assign = (char*)token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4483 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4484 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,token__b2c__string_var);
#line 4485 "bacon.bac"
__b2c__hash_del(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var, token__b2c__string_var);
#line 4486 "bacon.bac"
}
#line 4487 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "LIBRARY")){
#line 4488 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(exp__b2c__string_var));
#line 4489 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 4490 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4491 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) EXTRACT__b2c__string_var(token__b2c__string_var, "[[:punct:]]", TRUE); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " != NULL) {dlclose(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) EXTRACT__b2c__string_var(token__b2c__string_var, "[[:punct:]]", TRUE); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) EXTRACT__b2c__string_var(token__b2c__string_var, "[[:punct:]]", TRUE); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4492 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4493 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,token__b2c__string_var);
#line 4494 "bacon.bac"
}
#line 4495 "bacon.bac"
#line 4496 "bacon.bac"
#line 4497 "bacon.bac"
#line 4498 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "NETWORK") || !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "SERVER") || !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "UDP") || !__b2c__strcmp(__b2c__select_4459__b2c__string_var, "DEVICE")){
#line 4499 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(exp__b2c__string_var));
#line 4500 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 4501 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4503 "bacon.bac"
if( g_OPTION_TLS ){
#line 4504 "bacon.bac"
if( NOT(TALLY(g_LIB_TLS__b2c__string_var, "gnutls")) ){
#line 4505 "bacon.bac"
__b2c__assign = (char*)"if(fcntl((uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ",F_GETFL,0) == -1 && errno == EBADF) { close(SSL_get_fd((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4506 "bacon.bac"
__b2c__assign = (char*)"SSL_CTX_free(SSL_get_SSL_CTX((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")); SSL_shutdown((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4507 "bacon.bac"
__b2c__assign = (char*)"SSL_free((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); } else { close((uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4508 "bacon.bac"
} else {
#line 4509 "bacon.bac"
__b2c__assign = (char*)"if(fcntl((uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ",F_GETFL,0) == -1 && errno == EBADF) { BIO_get_fd( ((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")->gnutls_state, &__b2c__counter);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4510 "bacon.bac"
__b2c__assign = (char*)"close(__b2c__counter); free(((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")->ctx->certfile); free(((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")->ctx->keyfile);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4511 "bacon.bac"
__b2c__assign = (char*)"SSL_CTX_free(((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")->ctx); SSL_shutdown((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); SSL_free((SSL*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); gnutls_global_deinit(); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4512 "bacon.bac"
__b2c__assign = (char*)"else { close((uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4513 "bacon.bac"
}
#line 4514 "bacon.bac"
} else {
#line 4515 "bacon.bac"
__b2c__assign = (char*)"shutdown((uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", SHUT_RDWR);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4516 "bacon.bac"
__b2c__assign = (char*)"close((uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4517 "bacon.bac"
}
#line 4518 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4519 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,token__b2c__string_var);
#line 4520 "bacon.bac"
__b2c__hash_del(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var, token__b2c__string_var);
#line 4521 "bacon.bac"
}
#line 4522 "bacon.bac"
} else {
#line 4523 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: erroneous CLOSE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4524 "bacon.bac"
exit(1);
#line 4525 "bacon.bac"
}
#line 4526 "bacon.bac"
}
#line 4528 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "REWIND")){
#line 4530 "bacon.bac"
if( dim == 1 ){
#line 4531 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty REWIND at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4532 "bacon.bac"
exit(1);
#line 4533 "bacon.bac"
} else {
#line 4534 "bacon.bac"
__b2c__assign = (char*)"rewind("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4535 "bacon.bac"
}
#line 4537 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "MEMREWIND")){
#line 4539 "bacon.bac"
if( dim == 1 ){
#line 4540 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty MEMREWIND at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4541 "bacon.bac"
exit(1);
#line 4542 "bacon.bac"
} else {
#line 4543 "bacon.bac"
__b2c__assign = (char*)element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (char*)__b2c_mem_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4544 "bacon.bac"
}
#line 4546 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SEEK")){
#line 4547 "bacon.bac"
Handle_Seek(statement__b2c__string_var);
#line 4549 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "READLN")){
#line 4550 "bacon.bac"
Handle_Readln(statement__b2c__string_var);
#line 4552 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "WRITELN")){
#line 4553 "bacon.bac"
Handle_Writeln(statement__b2c__string_var);
#line 4555 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GETBYTE")){
#line 4556 "bacon.bac"
Handle_Getbyte(statement__b2c__string_var);
#line 4558 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PUTBYTE")){
#line 4559 "bacon.bac"
Handle_Putbyte(statement__b2c__string_var);
#line 4561 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GETFILE")){
#line 4562 "bacon.bac"
Handle_Getfile(statement__b2c__string_var);
#line 4564 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GETLINE")){
#line 4565 "bacon.bac"
Handle_Getline(statement__b2c__string_var);
#line 4567 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PUTLINE")){
#line 4568 "bacon.bac"
Handle_Putline(statement__b2c__string_var);
#line 4570 "bacon.bac"
#line 4571 "bacon.bac"
#line 4572 "bacon.bac"
#line 4573 "bacon.bac"
#line 4574 "bacon.bac"
#line 4575 "bacon.bac"
#line 4576 "bacon.bac"
#line 4577 "bacon.bac"
#line 4578 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "END") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDIF") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDSUB") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDFUNC") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDWITH") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDFORK") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDRECORD") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDSELECT") || !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENDFUNCTION")){
#line 4579 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) IIF__b2c__string_var((dim )> 1, element__b2c__string_var[(uint64_t)2], MID__b2c__string_var(element__b2c__string_var[(uint64_t)1], 4)));
#line 4580 "bacon.bac"
__b2c__select_4580__b2c__string_var = __b2c_Copy_String(__b2c__select_4580__b2c__string_var, exp__b2c__string_var);
#line 4581 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "IF")){
#line 4582 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4583 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "RECORD")){
#line 4584 "bacon.bac"
if( (LEN(g_FUNCNAME__b2c__string_var) )> 0 ){
#line 4585 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4586 "bacon.bac"
__b2c__assign = (char*)"typedef "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) EXTRACT__b2c__string_var(g_RECORDNAME__b2c__string_var, "_TYPE"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_type;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4587 "bacon.bac"
if( LEN(g_RECORDARRAY__b2c__string_var) ){
#line 4588 "bacon.bac"
__b2c__assign = (char*)g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDARRAY__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4589 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1)) ;
#line 4590 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDEND_BODY__b2c__string_var, " long __b2c_record_" , EXTRACT__b2c__string_var(g_RECORDNAME__b2c__string_var, "_TYPE") , " = " , g_RECORDARRAY__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , ";" , g_RECORDEND_BODY__b2c__string_var) ;
#line 4591 "bacon.bac"
} else {
#line 4592 "bacon.bac"
__b2c__assign = (char*)g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(g_RECORDVAR__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = { 0 } ;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4593 "bacon.bac"
}
#line 4594 "bacon.bac"
} else {
#line 4595 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4596 "bacon.bac"
__b2c__assign = (char*)"typedef "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) EXTRACT__b2c__string_var(g_RECORDNAME__b2c__string_var, "_TYPE") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_type;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4597 "bacon.bac"
if( LEN(g_RECORDARRAY__b2c__string_var) ){
#line 4598 "bacon.bac"
__b2c__assign = (char*)g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4599 "bacon.bac"
__b2c__assign = (char*)LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDARRAY__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4600 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , "free(" , LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1) , ");") ;
#line 4601 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "long __b2c_record_" , EXTRACT__b2c__string_var(g_RECORDNAME__b2c__string_var, "_TYPE") , ";" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4602 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDEND_BODY__b2c__string_var, g_RECORDEND_BODY__b2c__string_var , " __b2c_record_" , EXTRACT__b2c__string_var(g_RECORDNAME__b2c__string_var, "_TYPE") , " = " , g_RECORDARRAY__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , ";") ;
#line 4603 "bacon.bac"
} else {
#line 4604 "bacon.bac"
__b2c__assign = (char*)g_RECORDNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(g_RECORDVAR__b2c__string_var, "]", CONCAT__b2c__string_var( "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { 0 } ;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4605 "bacon.bac"
}
#line 4606 "bacon.bac"
__b2c__assign = (char*)g_RECORDEND_HEADER__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4607 "bacon.bac"
}
#line 4608 "bacon.bac"
__b2c__assign = (char*)g_RECORDEND_BODY__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4609 "bacon.bac"
g_RECORDNAME__b2c__string_var = __b2c_Copy_String(g_RECORDNAME__b2c__string_var, (char*) "");
#line 4610 "bacon.bac"
g_RECORDVAR__b2c__string_var = __b2c_Copy_String(g_RECORDVAR__b2c__string_var, (char*) "");
#line 4611 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = __b2c_Copy_String(g_RECORDEND_BODY__b2c__string_var, (char*) "");
#line 4612 "bacon.bac"
g_RECORDEND_HEADER__b2c__string_var = __b2c_Copy_String(g_RECORDEND_HEADER__b2c__string_var, (char*) "");
#line 4613 "bacon.bac"
g_RECORDARRAY__b2c__string_var = __b2c_Copy_String(g_RECORDARRAY__b2c__string_var, (char*) "");
#line 4615 "bacon.bac"
if( (LEN(g_RECORDCACHE__b2c__string_var) )> 0 ){
#line 4616 "bacon.bac"
g_FUNCNAME__b2c__string_var = __b2c_Copy_String(g_FUNCNAME__b2c__string_var, (char*) g_RECORDCACHE__b2c__string_var);
#line 4617 "bacon.bac"
g_RECORDCACHE__b2c__string_var = __b2c_Copy_String(g_RECORDCACHE__b2c__string_var, (char*) "");
#line 4618 "bacon.bac"
}
#line 4619 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "FUNC") || !__b2c__strcmp(__b2c__select_4580__b2c__string_var,  "FUNCTION")){
#line 4620 "bacon.bac"
Handle_Endfunction();
#line 4621 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "SUB")){
#line 4622 "bacon.bac"
Handle_Endsub();
#line 4623 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "WITH")){
#line 4624 "bacon.bac"
g_WITHVAR__b2c__string_var = __b2c_Copy_String(g_WITHVAR__b2c__string_var, (char*) "");
#line 4625 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "SELECT")){
#line 4626 "bacon.bac"
if( g_SELECTVAR_CTR == 0 ){
#line 4627 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid END SELECT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4628 "bacon.bac"
exit(1);
#line 4629 "bacon.bac"
} else {
#line 4630 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4631 "bacon.bac"
g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR] = __b2c_Copy_String(g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR], (char*) "");
#line 4632 "bacon.bac"
g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 0;
#line 4633 "bacon.bac"
g_CASE_FALL__b2c__string_var = __b2c_Copy_String(g_CASE_FALL__b2c__string_var, (char*) "");
#line 4634 "bacon.bac"
g_CASE_CONT__b2c__string_var = __b2c_Copy_String(g_CASE_CONT__b2c__string_var, (char*) "");
#line 4635 "bacon.bac"
g_SELECTVAR_CTR = g_SELECTVAR_CTR - (1);
#line 4636 "bacon.bac"
}
#line 4637 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4580__b2c__string_var, "FORK")){
#line 4638 "bacon.bac"
if( g_DEBUG == 1 ){
#line 4639 "bacon.bac"
__b2c__assign = (char*)"__b2c_str_realloc_debug_string();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4640 "bacon.bac"
__b2c__assign = (char*)"__b2c_mempool_realloc_debug();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4641 "bacon.bac"
}
#line 4642 "bacon.bac"
__b2c__assign = (char*)"__b2c_str_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4643 "bacon.bac"
if( (dim )> 2 ){
#line 4644 "bacon.bac"
__b2c__assign = (char*)"_exit("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "FORK")+4); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4645 "bacon.bac"
} else {
#line 4646 "bacon.bac"
__b2c__assign = (char*)"_exit(EXIT_SUCCESS);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4647 "bacon.bac"
}
#line 4648 "bacon.bac"
} else {
#line 4649 "bacon.bac"
if( g_DEBUG == 1 ){
#line 4650 "bacon.bac"
__b2c__assign = (char*)"__b2c_str_realloc_debug_string();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4651 "bacon.bac"
__b2c__assign = (char*)"__b2c_mempool_realloc_debug();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4652 "bacon.bac"
}
#line 4653 "bacon.bac"
__b2c__assign = (char*)"exit("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) IIF__b2c__string_var((dim )> 1, MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "END")+3), "EXIT_SUCCESS"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4654 "bacon.bac"
}
#line 4656 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SUB")){
#line 4657 "bacon.bac"
Handle_SubFunc(statement__b2c__string_var);
#line 4659 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CALL")){
#line 4660 "bacon.bac"
Handle_Call(statement__b2c__string_var);
#line 4662 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "FUNCTION")){
#line 4663 "bacon.bac"
Handle_SubFunc(statement__b2c__string_var);
#line 4665 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "FUNC")){
#line 4666 "bacon.bac"
Handle_SubFunc(statement__b2c__string_var);
#line 4668 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RETURN")){
#line 4669 "bacon.bac"
Handle_Return(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "RETURN") + 6));
#line 4671 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "IMPORT")){
#line 4672 "bacon.bac"
Handle_Import(statement__b2c__string_var);
#line 4674 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DECLARE")){
#line 4675 "bacon.bac"
Handle_Declare(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "DECLARE") + 7));
#line 4677 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GLOBAL")){
#line 4678 "bacon.bac"
Handle_Declare(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "GLOBAL") + 6));
#line 4680 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "LOCAL")){
#line 4681 "bacon.bac"
Handle_Local(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "LOCAL") + 5));
#line 4683 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DATA")){
#line 4684 "bacon.bac"
Handle_Data(statement__b2c__string_var);
#line 4686 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RESTORE")){
#line 4687 "bacon.bac"
if( dim == 1 ){
#line 4688 "bacon.bac"
__b2c__assign = (char*)"__b2c__floatarray_ptr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4689 "bacon.bac"
__b2c__assign = (char*)"__b2c__stringarray_ptr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4690 "bacon.bac"
} else {
#line 4691 "bacon.bac"
__b2c__assign = (char*)"__b2c__floatarray_ptr = __b2c__label_floatarray_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4692 "bacon.bac"
__b2c__assign = (char*)"__b2c__stringarray_ptr = __b2c__label_stringarray_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4693 "bacon.bac"
}
#line 4695 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "READ")){
#line 4696 "bacon.bac"
Handle_Read(statement__b2c__string_var);
#line 4698 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PUSH")){
#line 4699 "bacon.bac"
Handle_Push(statement__b2c__string_var);
#line 4701 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PULL")){
#line 4702 "bacon.bac"
Handle_Pull(statement__b2c__string_var);
#line 4704 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SEED")){
#line 4706 "bacon.bac"
if( dim == 1 ){
#line 4707 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SEED at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4708 "bacon.bac"
exit(1);
#line 4709 "bacon.bac"
} else {
#line 4710 "bacon.bac"
__b2c__assign = (char*)"srandom((unsigned int)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, " ")+1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4711 "bacon.bac"
}
#line 4713 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DEF")){
#line 4714 "bacon.bac"
Handle_Deffn(statement__b2c__string_var);
#line 4716 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CONST")){
#line 4717 "bacon.bac"
Handle_Const(statement__b2c__string_var);
#line 4719 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "INCLUDE")){
#line 4721 "bacon.bac"
inc__b2c__string_var = __b2c_Copy_String(inc__b2c__string_var, (char*) EXTRACT__b2c__string_var((CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, " ") + 1))), CHR__b2c__string_var(34)));
#line 4723 "bacon.bac"
if( INSTR(inc__b2c__string_var, ",") ){
#line 4724 "bacon.bac"
__b2c__split_by(&element__b2c__string_var, 1, &element__b2c__string_var__b2c_array, MID__b2c__string_var(inc__b2c__string_var, INSTR(inc__b2c__string_var, ",")+1), ",");
size = element__b2c__string_var__b2c_array;
#line 4725 "bacon.bac"
for(i=1; i <= size; i+=1){
#line 4726 "bacon.bac"
element__b2c__string_var[(uint64_t)i] = __b2c_Copy_String(element__b2c__string_var[(uint64_t)i], (char*) EXTRACT__b2c__string_var(element__b2c__string_var[(uint64_t)i], g_STRINGSIGN__b2c__string_var));
#line 4727 "bacon.bac"
}
#line 4728 "bacon.bac"
inc__b2c__string_var = F_MID__b2c__string_var(inc__b2c__string_var,inc__b2c__string_var, 1, INSTR(inc__b2c__string_var, ",")-1);
#line 4729 "bacon.bac"
} else {
#line 4730 "bacon.bac"
to_parse=(
long)( 2);
#line 4731 "bacon.bac"
}
#line 4733 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(inc__b2c__string_var, 4) ,  ".bac") != 0 ){
inc__b2c__string_var = F_CONCAT__b2c__string_var(inc__b2c__string_var, inc__b2c__string_var , ".bac");
}
#line 4736 "bacon.bac"
if( NOT(FILEEXISTS(inc__b2c__string_var))  OR  dim == 1  OR  (FILETYPE(inc__b2c__string_var) != 1  AND  FILETYPE(inc__b2c__string_var) != 6) ){
#line 4737 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "System error: missing file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) inc__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' for INCLUDE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4738 "bacon.bac"
exit(1);
#line 4739 "bacon.bac"
} else {
#line 4741 "bacon.bac"
__b2c__assign = (char*)CR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) EL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 4743 "bacon.bac"
if( ISTRUE(g_CPP) ){
#line 4744 "bacon.bac"
if( ISTRUE(LEN(EXEC__b2c__string_var("command -v cpp 2>/dev/null"))) ){
#line 4745 "bacon.bac"
__b2c__assign = (char*)"Preprocessing '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) inc__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 4747 "bacon.bac"
src_tmp = fopen((const char*)CONCAT__b2c__string_var( inc__b2c__string_var , ".tmp" ), "w");
if(src_tmp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 4747, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 4748 "bacon.bac"
src_in = fopen((const char*)inc__b2c__string_var, "r");
if(src_in == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 4748, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 4749 "bacon.bac"
while( NOT(ENDFILE(src_in)) ){
#line 4750 "bacon.bac"
__b2c__readln(&__b2c__assign, src_in);
txt__b2c__string_var = __b2c_Copy_String(txt__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 4751 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(txt__b2c__string_var, 1) ,  "#") == 0 ){
#line 4752 "bacon.bac"
__b2c__assign = (char*)txt__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, src_tmp); }
fputs("\n", src_tmp);
#line 4753 "bacon.bac"
} else {
#line 4754 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "@" , txt__b2c__string_var , "@" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, src_tmp); }
fputs("\n", src_tmp);
#line 4755 "bacon.bac"
}
#line 4756 "bacon.bac"
}
#line 4757 "bacon.bac"
fclose(src_in);
fclose( src_tmp);
#line 4758 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "cpp -P -w " , inc__b2c__string_var , ".tmp " , inc__b2c__string_var , ".cpp") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 4760 "bacon.bac"
src_cpp = fopen((const char*)CONCAT__b2c__string_var( inc__b2c__string_var , ".cpp" ), "r");
if(src_cpp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 4760, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 4761 "bacon.bac"
src_out = fopen((const char*)CONCAT__b2c__string_var( inc__b2c__string_var , ".bac2" ), "w");
if(src_out == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 4761, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 4762 "bacon.bac"
while( NOT(ENDFILE(src_cpp)) ){
#line 4763 "bacon.bac"
__b2c__readln(&__b2c__assign, src_cpp);
txt__b2c__string_var = __b2c_Copy_String(txt__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 4764 "bacon.bac"
__b2c__assign = (char*)MID__b2c__string_var(txt__b2c__string_var, 2, LEN(txt__b2c__string_var)-2); if(__b2c__assign != NULL) { fputs(__b2c__assign, src_out); }
fputs("\n", src_out);
#line 4765 "bacon.bac"
}
#line 4766 "bacon.bac"
fclose(src_out);
fclose( src_cpp);
#line 4767 "bacon.bac"
newfeed__b2c__string_var = F_CONCAT__b2c__string_var(newfeed__b2c__string_var, inc__b2c__string_var , ".bac2") ;
#line 4768 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , inc__b2c__string_var , ".cpp" , " " , inc__b2c__string_var , ".tmp" , " " , inc__b2c__string_var , ".bac2") ;
#line 4769 "bacon.bac"
__b2c__assign = (char*)"done."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 4770 "bacon.bac"
} else {
#line 4771 "bacon.bac"
__b2c__assign = (char*)"System error: the C Preprocessor 'cpp' not found on this system! Exiting..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4772 "bacon.bac"
exit(1);
#line 4773 "bacon.bac"
}
#line 4774 "bacon.bac"
} else {
#line 4775 "bacon.bac"
newfeed__b2c__string_var = __b2c_Copy_String(newfeed__b2c__string_var, (char*) inc__b2c__string_var);
#line 4776 "bacon.bac"
}
#line 4777 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , inc__b2c__string_var) ;
#line 4779 "bacon.bac"
copy_counter=(
long)( g_COUNTER);
#line 4780 "bacon.bac"
g_COUNTER=(long)( 1);
#line 4782 "bacon.bac"
copy_curfile__b2c__string_var = __b2c_Copy_String(copy_curfile__b2c__string_var, (char*) g_CURFILE__b2c__string_var);
#line 4784 "bacon.bac"
g_CURFILE__b2c__string_var = __b2c_Copy_String(g_CURFILE__b2c__string_var, (char*) newfeed__b2c__string_var);
#line 4786 "bacon.bac"
newfile = fopen((const char*)newfeed__b2c__string_var, "r");
if(newfile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 4786, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 4787 "bacon.bac"
do{
#line 4788 "bacon.bac"
__b2c__readln(&__b2c__assign, newfile);
txt__b2c__string_var = __b2c_Copy_String(txt__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 4789 "bacon.bac"
txt__b2c__string_var = F_CHOP__b2c__string_var(txt__b2c__string_var,txt__b2c__string_var);
#line 4791 "bacon.bac"
if( (size )> 0 ){
#line 4792 "bacon.bac"
for(i=1; i <= size; i+=1){
#line 4793 "bacon.bac"
if( ( to_parse == 0  AND  REGEX(CHOP__b2c__string_var(MID__b2c__string_var(txt__b2c__string_var, INSTR(txt__b2c__string_var, " "))), CONCAT__b2c__string_var( "^" , CHOP__b2c__string_var(element__b2c__string_var[(uint64_t)i])) )  AND  REGEX(txt__b2c__string_var, "SUB|FUNCTION") )  OR  REGEX(txt__b2c__string_var, "INCLUDE$") ){
#line 4794 "bacon.bac"
to_parse=(
long)( 1);
#line 4795 "bacon.bac"
break;
#line 4796 "bacon.bac"
}
#line 4797 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 4798 "bacon.bac"
}
#line 4800 "bacon.bac"
if( (LEN(txt__b2c__string_var) )> 0  AND  (to_parse )> 0 ){
#line 4801 "bacon.bac"
if( NOT(g_QUIET) ){
__b2c__assign = (char*)"\rConverting '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) newfeed__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs(STR__b2c__string_var( g_COUNTER), stdout);
__b2c__assign = (char*) EL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
}
#line 4802 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(txt__b2c__string_var, 2) ,  " \\") == 0  AND  __b2c__STRCMP(LEFT__b2c__string_var(txt__b2c__string_var, 1) ,  CHR__b2c__string_var(39)) != 0  AND  NOT(REGEX(line__b2c__string_var, "^REM[[:space:]]+")) ){
#line 4803 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , LEFT__b2c__string_var(txt__b2c__string_var, LEN(txt__b2c__string_var)-1)) ;
#line 4804 "bacon.bac"
} else {
#line 4805 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , txt__b2c__string_var) ;
#line 4806 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(total__b2c__string_var, 1) ,  CHR__b2c__string_var(39)) != 0 ){
#line 4807 "bacon.bac"
if( g_DEBUG ){
#line 4808 "bacon.bac"
__b2c__assign = (char*)"/* line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) newfeed__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\" */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4809 "bacon.bac"
__b2c__assign = (char*)"/* line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_HFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) newfeed__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "\" */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4810 "bacon.bac"
} else {
#line 4811 "bacon.bac"
__b2c__assign = (char*)"#line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) newfeed__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4812 "bacon.bac"
__b2c__assign = (char*)"#line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_HFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) newfeed__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 4813 "bacon.bac"
}
#line 4814 "bacon.bac"
Tokenize(total__b2c__string_var);
#line 4816 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) EXTRACT__b2c__string_var(total__b2c__string_var, "\\\\"));
#line 4817 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) EXTRACT__b2c__string_var(total__b2c__string_var, "\\\""));
#line 4818 "bacon.bac"
g_DEPEND__b2c__string_var = F_CONCAT__b2c__string_var(g_DEPEND__b2c__string_var, g_DEPEND__b2c__string_var , EXTRACT__b2c__string_var(total__b2c__string_var, "\"[^\"]*\"", TRUE) , NL__b2c__string_var) ;
#line 4819 "bacon.bac"
}
#line 4820 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) "");
#line 4821 "bacon.bac"
}
#line 4822 "bacon.bac"
}
#line 4824 "bacon.bac"
if( to_parse == 1  AND  INSTR(txt__b2c__string_var, "END")  AND  REGEX(txt__b2c__string_var, "SUB|FUNCTION") ){
to_parse=(
long)( 0);
}
#line 4826 "bacon.bac"
g_COUNTER = g_COUNTER + (1);
#line 4827 "bacon.bac"
} while(!( ENDFILE(newfile) ));
#line 4828 "bacon.bac"
fclose(newfile);
#line 4831 "bacon.bac"
g_TOTAL_LINES = g_TOTAL_LINES + ( g_COUNTER);
#line 4833 "bacon.bac"
g_COUNTER=(long)( copy_counter);
#line 4835 "bacon.bac"
g_CURFILE__b2c__string_var = __b2c_Copy_String(g_CURFILE__b2c__string_var, (char*) copy_curfile__b2c__string_var);
#line 4837 "bacon.bac"
__b2c__assign = (char*)"__b2c__stringarray_ptr = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_CCTR), g_CFILE);
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4838 "bacon.bac"
__b2c__assign = (char*)"__b2c__floatarray_ptr = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_FCTR), g_CFILE);
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4839 "bacon.bac"
}
#line 4841 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "POKE")){
#line 4843 "bacon.bac"
if( dim == 1 ){
#line 4844 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty POKE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4845 "bacon.bac"
exit(1);
#line 4846 "bacon.bac"
} else {
#line 4847 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "POKE") + 4);
#line 4848 "bacon.bac"
if( TALLY(exp__b2c__string_var, " SIZE ") ){
#line 4849 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) TOKEN__b2c__string_var(exp__b2c__string_var, 2, " SIZE "));
#line 4850 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) TOKEN__b2c__string_var(exp__b2c__string_var, 1, " SIZE "));
#line 4851 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4852 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4853 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check((char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CONCAT__b2c__string_var( ", (" , str__b2c__string_var , ")*sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"POKE\", ") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4854 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "memset((void*)(__b2c__MEMTYPE*)(" , token__b2c__string_var , "), " , exp__b2c__string_var , ", (" , str__b2c__string_var , ")*sizeof(__b2c__MEMTYPE));" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4855 "bacon.bac"
} else {
#line 4856 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4857 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 4858 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check((char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"POKE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4859 "bacon.bac"
__b2c__assign = (char*)"*(__b2c__MEMTYPE*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") = ( __b2c__MEMTYPE)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4860 "bacon.bac"
}
#line 4861 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4862 "bacon.bac"
}
#line 4864 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RESIZE")){
#line 4866 "bacon.bac"
if( dim == 1 ){
#line 4867 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty RESIZE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4868 "bacon.bac"
exit(1);
#line 4869 "bacon.bac"
} else {
#line 4870 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "RESIZE") + 6);
#line 4871 "bacon.bac"
lft__b2c__string_var = F_CHOP__b2c__string_var(lft__b2c__string_var,TOKEN__b2c__string_var(exp__b2c__string_var, 1, " TO "));
#line 4872 "bacon.bac"
str__b2c__string_var = F_CHOP__b2c__string_var(str__b2c__string_var,TOKEN__b2c__string_var(exp__b2c__string_var, 2, " TO "));
#line 4873 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check((char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"RESIZE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4874 "bacon.bac"
__b2c__assign = (char*)lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) Get_Var__b2c__string_var(EXTRACT__b2c__string_var(lft__b2c__string_var, "."), g_FUNCNAME__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")realloc((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE)*("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+1));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4875 "bacon.bac"
__b2c__assign = (char*)"if((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL) { ERROR=6; RUNTIMEERROR(\"RESIZE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4876 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4877 "bacon.bac"
}
#line 4879 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "COPY")){
#line 4880 "bacon.bac"
Handle_Copy(statement__b2c__string_var);
#line 4882 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DELETE")){
#line 4884 "bacon.bac"
if( dim == 1 ){
#line 4885 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty DELETE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4886 "bacon.bac"
exit(1);
#line 4887 "bacon.bac"
} else {
#line 4889 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "FILE") == 0 ){
#line 4890 "bacon.bac"
__b2c__assign = (char*)"if(unlink("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, " FILE ") + 6); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")==-1){ ERROR = 7; RUNTIMEERROR(\"DELETE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4891 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4892 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "DIRECTORY") == 0 ){
#line 4893 "bacon.bac"
__b2c__assign = (char*)"if(rmdir("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, " DIRECTORY ") + 11); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") == -1){ ERROR = 20; RUNTIMEERROR(\"DELETE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4894 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4895 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "RECURSIVE") == 0 ){
#line 4896 "bacon.bac"
__b2c__assign = (char*)"__b2c__rmrecursive(__LINE__, __FILE__, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, " RECURSIVE ") + 11); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4897 "bacon.bac"
} else if( ISTOKEN(statement__b2c__string_var, "FROM") ){
#line 4898 "bacon.bac"
sym__b2c__string_var = F_CHOP__b2c__string_var(sym__b2c__string_var,LAST__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "FROM")));
#line 4899 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) HEAD__b2c__string_var(statement__b2c__string_var, ISTOKEN(statement__b2c__string_var, "FROM")-1));
#line 4900 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(exp__b2c__string_var, ISTOKEN(exp__b2c__string_var, "DELETE")));
#line 4901 "bacon.bac"
txt__b2c__string_var = __b2c_Copy_String(txt__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__tree_" , sym__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 4902 "bacon.bac"
uniq__b2c__string_var = F_CONCAT__b2c__string_var(uniq__b2c__string_var, "__b2c__" , sym__b2c__string_var , "_" , STR__b2c__string_var(g_COUNTER) , "_" , STR__b2c__string_var(RND)) ;
#line 4903 "bacon.bac"
if( __b2c__STRCMP(TOKEN__b2c__string_var(txt__b2c__string_var, 2, ":") ,  "char*") == 0 ){
#line 4904 "bacon.bac"
__b2c__assign = (char*)"char *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __b2c__assign2 = tfind((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 1, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); if(__b2c__assign2) { __b2c__assign = *__b2c__assign2; tdelete((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 1, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__STRFREE(__b2c__assign); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4905 "bacon.bac"
} else {
#line 4906 "bacon.bac"
__b2c__assign = (char*)TOKEN__b2c__string_var(txt__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)malloc(sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")); *"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 2, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __b2c__assign2 = tfind((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 1, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); if(__b2c__assign2) { __b2c__assign = *__b2c__assign2; tdelete((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(txt__b2c__string_var, 1, ":"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); free(__b2c__assign); } free("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) uniq__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4907 "bacon.bac"
}
#line 4908 "bacon.bac"
} else {
#line 4909 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: erronuous argument for DELETE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4910 "bacon.bac"
exit(1);
#line 4911 "bacon.bac"
}
#line 4912 "bacon.bac"
}
#line 4914 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RENAME")){
#line 4915 "bacon.bac"
Handle_Rename(statement__b2c__string_var);
#line 4917 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "MAKEDIR")){
#line 4919 "bacon.bac"
if( dim == 1 ){
#line 4920 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty MAKEDIR at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4921 "bacon.bac"
exit(1);
#line 4922 "bacon.bac"
} else {
#line 4924 "bacon.bac"
__b2c__assign = (char*)"ERROR = __b2c__makedir("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(statement__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); if(ERROR){ RUNTIMEERROR(\"MAKEDIR\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4925 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4926 "bacon.bac"
}
#line 4928 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CHANGEDIR")){
#line 4930 "bacon.bac"
if( dim == 1 ){
#line 4931 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CHANGEDIR at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4932 "bacon.bac"
exit(1);
#line 4933 "bacon.bac"
} else {
#line 4935 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(statement__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL || chdir("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(statement__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") == -1){ ERROR = 22; RUNTIMEERROR(\"CHANGEDIR\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4936 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4937 "bacon.bac"
}
#line 4939 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "FREE")){
#line 4941 "bacon.bac"
if( dim == 1 ){
#line 4942 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty FREE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4943 "bacon.bac"
exit(1);
#line 4944 "bacon.bac"
} else {
#line 4946 "bacon.bac"
if( REGEX(statement__b2c__string_var, "[a-zA-Z]+\\(.*\\)$") ){
#line 4948 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) LAST__b2c__string_var(statement__b2c__string_var));
#line 4949 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 4950 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,LEFT__b2c__string_var(exp__b2c__string_var, INSTR(exp__b2c__string_var, "(")-1));
#line 4951 "bacon.bac"
str__b2c__string_var = F_CHOP__b2c__string_var(str__b2c__string_var,Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 4952 "bacon.bac"
txt__b2c__string_var = F_MID__b2c__string_var(txt__b2c__string_var,str__b2c__string_var, INSTR(str__b2c__string_var, "(")+1);
#line 4953 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_del(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(txt__b2c__string_var, LEN(txt__b2c__string_var)-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4954 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(str__b2c__string_var)+2);
#line 4955 "bacon.bac"
}
#line 4956 "bacon.bac"
} else {
#line 4957 "bacon.bac"
__b2c__forin_str__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_string, EXTRACT__b2c__string_var(LAST__b2c__string_var(statement__b2c__string_var), " ")); __b2c__forin_str__b2c__string_var_string_org = __b2c__forin_str__b2c__string_var_string;
__b2c__forin_str__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_step, ",");
__b2c__forin_str__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_str__b2c__string_var_string, __b2c__forin_str__b2c__string_var_step);
for(; __b2c__forin_str__b2c__string_var_ptr > 0; __b2c__forin_str__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_str__b2c__string_var_string_org, __b2c__forin_str__b2c__string_var_step, &str__b2c__string_var);
#line 4958 "bacon.bac"
if( LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , str__b2c__string_var) ))  OR  LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , str__b2c__string_var) , g_FUNCNAME__b2c__string_var)) ){
#line 4959 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_clear(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4960 "bacon.bac"
} else {
#line 4961 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check((char *)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE)))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4962 "bacon.bac"
__b2c__assign = (char*)"{ ERROR=1; RUNTIMEERROR(\"FREE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); } free((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4963 "bacon.bac"
__b2c__hash_del(__b2c__assoc_g_SEMANTIC_MEMFREE__b2c__string_var, str__b2c__string_var);
#line 4964 "bacon.bac"
}
#line 4965 "bacon.bac"
}
#line 4966 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 4967 "bacon.bac"
}
#line 4968 "bacon.bac"
}
#line 4970 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ON")){
#line 4972 "bacon.bac"
if( dim == 1 ){
#line 4973 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty ON at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4974 "bacon.bac"
exit(1);
#line 4975 "bacon.bac"
} else if( NOT(ISTOKEN(statement__b2c__string_var, "GOTO"))  AND  NOT(INSTR(statement__b2c__string_var, "CALL")) ){
#line 4976 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: ON without CALL/GOTO at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 4977 "bacon.bac"
exit(1);
#line 4978 "bacon.bac"
} else {
#line 4979 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(statement__b2c__string_var), CONCAT__b2c__string_var( "ON * " , IIF__b2c__string_var(ISTOKEN(statement__b2c__string_var, "CALL"), "CALL", "GOTO") , " *" ), __b2c__option_delim);
#line 4981 "bacon.bac"
i=(
long)( 1);
#line 4982 "bacon.bac"
__b2c__assign = (char*)"switch("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) match__b2c__string_var[(uint64_t)1]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4983 "bacon.bac"
while( LEN(match__b2c__string_var[(uint64_t)2]) ){
#line 4984 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(match__b2c__string_var[(uint64_t)2]));
#line 4985 "bacon.bac"
if( ISTOKEN(statement__b2c__string_var, "GOTO") ){
#line 4986 "bacon.bac"
__b2c__assign = (char*)"case "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( i), g_CFILE);
__b2c__assign = (char*) ": goto "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4987 "bacon.bac"
} else {
#line 4988 "bacon.bac"
if( NOT(REGEX(token__b2c__string_var, "\\(.*\\)$")) ){
#line 4989 "bacon.bac"
__b2c__assign = (char*)"case "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( i), g_CFILE);
__b2c__assign = (char*) ": "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "(); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4990 "bacon.bac"
} else {
#line 4991 "bacon.bac"
__b2c__assign = (char*)"case "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( i), g_CFILE);
__b2c__assign = (char*) ": "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4992 "bacon.bac"
}
#line 4993 "bacon.bac"
}
#line 4994 "bacon.bac"
match__b2c__string_var[(uint64_t)2] = F_MID__b2c__string_var(match__b2c__string_var[(uint64_t)2],match__b2c__string_var[(uint64_t)2], LEN(token__b2c__string_var)+2);
#line 4995 "bacon.bac"
i = i + (1);
#line 4996 "bacon.bac"
}
#line 4997 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 4998 "bacon.bac"
}
#line 5000 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GOTO")){
#line 5002 "bacon.bac"
if( dim == 1 ){
#line 5003 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty GOTO at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5004 "bacon.bac"
exit(1);
#line 5005 "bacon.bac"
} else {
#line 5007 "bacon.bac"
__b2c__assign = (char*)"goto "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5008 "bacon.bac"
}
#line 5010 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GOSUB")){
#line 5012 "bacon.bac"
if( dim == 1 ){
#line 5013 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty GOSUB at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5014 "bacon.bac"
exit(1);
#line 5015 "bacon.bac"
} else {
#line 5017 "bacon.bac"
__b2c__assign = (char*)"__b2c__gosub_buffer_ptr++; if (__b2c__gosub_buffer_ptr >= "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_RBUFFERS), g_CFILE);
__b2c__assign = (char*) ") { ERROR=31; RUNTIMEERROR(\"GOSUB\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5018 "bacon.bac"
__b2c__assign = (char*)"if(!setjmp(__b2c__gosub_buffer[__b2c__gosub_buffer_ptr])) goto "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5019 "bacon.bac"
__b2c__assign = (char*)"__b2c__gosub_buffer_ptr--; if(__b2c__gosub_buffer_ptr < -1) __b2c__gosub_buffer_ptr = -1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5020 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 5021 "bacon.bac"
}
#line 5023 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "LABEL")){
#line 5025 "bacon.bac"
if( dim == 1 ){
#line 5026 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty LABEL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5027 "bacon.bac"
exit(1);
#line 5028 "bacon.bac"
} else {
#line 5030 "bacon.bac"
__b2c__assign = (char*)element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ":"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5031 "bacon.bac"
__b2c__assign = (char*)";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5033 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__label_floatarray_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5034 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__label_floatarray_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_FCTR), g_HFILE);
fputs("\n", g_HFILE);
#line 5035 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__label_stringarray_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5036 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__label_stringarray_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_CCTR), g_HFILE);
fputs("\n", g_HFILE);
#line 5037 "bacon.bac"
}
#line 5039 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "TRAP")){
#line 5041 "bacon.bac"
if( dim == 1 ){
#line 5042 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty TRAP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5043 "bacon.bac"
exit(1);
#line 5044 "bacon.bac"
} else {
#line 5045 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "LOCAL") == 0 ){
#line 5046 "bacon.bac"
__b2c__assign = (char*)"/* Error catching is enabled */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5047 "bacon.bac"
__b2c__assign = (char*)"__b2c__trap = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5048 "bacon.bac"
__b2c__assign = (char*)"signal(SIGILL, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5049 "bacon.bac"
__b2c__assign = (char*)"signal(SIGABRT, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5050 "bacon.bac"
__b2c__assign = (char*)"signal(SIGFPE, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5051 "bacon.bac"
__b2c__assign = (char*)"signal(SIGSEGV, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5052 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "SYSTEM") == 0 ){
#line 5053 "bacon.bac"
__b2c__assign = (char*)"/* Error catching is disabled */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5054 "bacon.bac"
__b2c__assign = (char*)"__b2c__trap = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5055 "bacon.bac"
__b2c__assign = (char*)"signal(SIGILL, SIG_DFL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5056 "bacon.bac"
__b2c__assign = (char*)"signal(SIGABRT, SIG_DFL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5057 "bacon.bac"
__b2c__assign = (char*)"signal(SIGFPE, SIG_DFL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5058 "bacon.bac"
__b2c__assign = (char*)"signal(SIGSEGV, SIG_DFL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5059 "bacon.bac"
} else {
#line 5060 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument for TRAP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5061 "bacon.bac"
exit(1);
#line 5062 "bacon.bac"
}
#line 5063 "bacon.bac"
}
#line 5065 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CATCH")){
#line 5067 "bacon.bac"
if( dim == 1 ){
#line 5068 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CATCH at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5069 "bacon.bac"
exit(1);
#line 5070 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "GOTO") == 0 ){
#line 5071 "bacon.bac"
__b2c__assign = (char*)"__b2c__catch_set = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5072 "bacon.bac"
g_CATCHGOTO__b2c__string_var = __b2c_Copy_String(g_CATCHGOTO__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5073 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "ERROR") == 0 ){
#line 5074 "bacon.bac"
__b2c__assign = (char*)"__b2c__error_callback = & "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5075 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "RESET") == 0 ){
#line 5076 "bacon.bac"
__b2c__assign = (char*)"__b2c__catch_set = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5077 "bacon.bac"
g_CATCHGOTO__b2c__string_var = __b2c_Copy_String(g_CATCHGOTO__b2c__string_var, (char*) "__B2C__PROGRAM__EXIT");
#line 5078 "bacon.bac"
} else {
#line 5079 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: CATCH without GOTO or RESET at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5080 "bacon.bac"
exit(1);
#line 5081 "bacon.bac"
}
#line 5083 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RESUME")){
#line 5084 "bacon.bac"
__b2c__assign = (char*)"if(jmp_buf_is_used(__b2c__jump)) { longjmp(__b2c__jump, 1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5086 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CLEAR")){
#line 5087 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[2J\"); fprintf(stdout,\"\\033[0;0f\");fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5089 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "COLOR")){
#line 5090 "bacon.bac"
Handle_Color(statement__b2c__string_var);
#line 5092 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "TYPE")){
#line 5093 "bacon.bac"
Handle_Type(statement__b2c__string_var);
#line 5095 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SCREEN")){
#line 5097 "bacon.bac"
if( dim == 1 ){
#line 5098 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SCREEN at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5099 "bacon.bac"
exit(1);
#line 5100 "bacon.bac"
} else {
#line 5101 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "SAVE") == 0 ){
#line 5102 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[?47h\"); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5103 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "RESTORE") == 0 ){
#line 5104 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[?47l\"); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5105 "bacon.bac"
} else {
#line 5106 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument for SCREEN at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5107 "bacon.bac"
exit(1);
#line 5108 "bacon.bac"
}
#line 5109 "bacon.bac"
}
#line 5111 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GOTOXY")){
#line 5112 "bacon.bac"
Handle_Gotoxy(statement__b2c__string_var);
#line 5114 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RECEIVE")){
#line 5115 "bacon.bac"
Handle_Receive(CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "RECEIVE") + 7)));
#line 5117 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SEND")){
#line 5118 "bacon.bac"
Handle_Send(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SEND") + 4));
#line 5120 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RECORD")){
#line 5122 "bacon.bac"
if( dim == 1 ){
#line 5123 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty RECORD at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5124 "bacon.bac"
exit(1);
#line 5125 "bacon.bac"
} else if( ISTRUE(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 5126 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: cannot define a record within a record!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5127 "bacon.bac"
exit(1);
#line 5128 "bacon.bac"
} else {
#line 5130 "bacon.bac"
g_RECORDVAR__b2c__string_var = F_MID__b2c__string_var(g_RECORDVAR__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "RECORD")+6);
#line 5131 "bacon.bac"
if( INSTR(g_RECORDVAR__b2c__string_var, " ARRAY ") ){
#line 5132 "bacon.bac"
g_RECORDARRAY__b2c__string_var = F_MID__b2c__string_var(g_RECORDARRAY__b2c__string_var,g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "ARRAY")+5);
#line 5133 "bacon.bac"
g_RECORDVAR__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDVAR__b2c__string_var, CHOP__b2c__string_var(LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "ARRAY")-1)) , "[" , g_RECORDARRAY__b2c__string_var , "]") ;
#line 5134 "bacon.bac"
}
#line 5136 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 5137 "bacon.bac"
g_RECORDNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDNAME__b2c__string_var, LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1) , "_TYPE") ;
#line 5138 "bacon.bac"
__b2c__assign = (char*)"typedef struct {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5139 "bacon.bac"
Save_Func_Var("", g_FUNCNAME__b2c__string_var, g_RECORDNAME__b2c__string_var);
#line 5140 "bacon.bac"
} else {
#line 5141 "bacon.bac"
g_RECORDNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_RECORDNAME__b2c__string_var, LEFT__b2c__string_var(g_RECORDVAR__b2c__string_var, INSTR(g_RECORDVAR__b2c__string_var, "[")-1) , "_TYPE") ;
#line 5142 "bacon.bac"
__b2c__assign = (char*)"typedef struct {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5143 "bacon.bac"
Save_Main_Var("", g_RECORDNAME__b2c__string_var);
#line 5144 "bacon.bac"
}
#line 5145 "bacon.bac"
}
#line 5147 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "WITH")){
#line 5149 "bacon.bac"
if( dim == 1 ){
#line 5150 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty WITH at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5151 "bacon.bac"
exit(1);
#line 5152 "bacon.bac"
} else if( ISTRUE(LEN(g_RECORDNAME__b2c__string_var)) ){
#line 5153 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: cannot define a WITH within a WITH!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5154 "bacon.bac"
exit(1);
#line 5155 "bacon.bac"
} else {
#line 5156 "bacon.bac"
g_WITHVAR__b2c__string_var = __b2c_Copy_String(g_WITHVAR__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)2]);
#line 5157 "bacon.bac"
}
#line 5159 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SPLIT")){
#line 5160 "bacon.bac"
Handle_Split(statement__b2c__string_var);
#line 5162 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "JOIN")){
#line 5163 "bacon.bac"
Handle_Join(statement__b2c__string_var);
#line 5165 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SELECT")){
#line 5167 "bacon.bac"
if( dim == 1 ){
#line 5168 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SELECT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5169 "bacon.bac"
exit(1);
#line 5170 "bacon.bac"
} else {
#line 5171 "bacon.bac"
g_SELECTVAR_CTR = g_SELECTVAR_CTR + (1);
#line 5172 "bacon.bac"
if( Check_String_Type(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SELECT") + 6)) ){
#line 5173 "bacon.bac"
g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR] = F_CONCAT__b2c__string_var(g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR], "__b2c__select_" , STR__b2c__string_var(g_COUNTER) , g_STRINGSIGN__b2c__string_var) ;
#line 5174 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) ){
#line 5175 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char* " , g_SELECTVAR__b2c__string_var[g_SELECTVAR_CTR] , " = NULL;") ;
#line 5176 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , g_SELECTVAR__b2c__string_var[g_SELECTVAR_CTR]) ;
#line 5177 "bacon.bac"
} else {
#line 5178 "bacon.bac"
__b2c__assign = (char*)"char* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5179 "bacon.bac"
}
#line 5180 "bacon.bac"
__b2c__assign = (char*)g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "= __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SELECT") + 6); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5181 "bacon.bac"
} else {
#line 5182 "bacon.bac"
g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR] = F_CONCAT__b2c__string_var(g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR], "__b2c__select_" , STR__b2c__string_var(g_COUNTER)) ;
#line 5183 "bacon.bac"
__b2c__assign = (char*)"double "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5184 "bacon.bac"
__b2c__assign = (char*)g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (double)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SELECT") + 6); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5185 "bacon.bac"
}
#line 5186 "bacon.bac"
g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 0;
#line 5187 "bacon.bac"
g_CASE_FALL__b2c__string_var = __b2c_Copy_String(g_CASE_FALL__b2c__string_var, (char*) "");
#line 5188 "bacon.bac"
g_CASE_CONT__b2c__string_var = __b2c_Copy_String(g_CASE_CONT__b2c__string_var, (char*)"");
#line 5189 "bacon.bac"
}
#line 5191 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CASE")){
#line 5193 "bacon.bac"
if( dim == 1 ){
#line 5194 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CASE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5195 "bacon.bac"
exit(1);
#line 5196 "bacon.bac"
} else {
#line 5198 "bacon.bac"
if( ISTRUE(g_IN_CASE[(uint64_t)g_SELECTVAR_CTR]) ){
g_CASE_CONT__b2c__string_var = __b2c_Copy_String(g_CASE_CONT__b2c__string_var, (char*) "} else ");
}
#line 5200 "bacon.bac"
if( Check_String_Type(g_SELECTVAR__b2c__string_var[(uint64_t)g_SELECTVAR_CTR]) ){
#line 5201 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "CASE") + 4);
#line 5202 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(statement__b2c__string_var, 1) ,  ";") == 0 ){
#line 5203 "bacon.bac"
g_CASE_FALL__b2c__string_var = F_CONCAT__b2c__string_var(g_CASE_FALL__b2c__string_var, g_CASE_FALL__b2c__string_var , "!__b2c__strcmp(" , g_SELECTVAR__b2c__string_var[g_SELECTVAR_CTR] , ", " , LEFT__b2c__string_var(exp__b2c__string_var, LEN(exp__b2c__string_var)-1) , ") ||") ;
#line 5204 "bacon.bac"
} else {
#line 5205 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 5206 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 5207 "bacon.bac"
g_CASE_FALL__b2c__string_var = F_CONCAT__b2c__string_var(g_CASE_FALL__b2c__string_var, g_CASE_FALL__b2c__string_var , "!__b2c__strcmp(" , g_SELECTVAR__b2c__string_var[g_SELECTVAR_CTR] , ", " , str__b2c__string_var , ") ") ;
#line 5208 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(str__b2c__string_var)+2);
#line 5209 "bacon.bac"
if( LEN(exp__b2c__string_var) ){
g_CASE_FALL__b2c__string_var = F_CONCAT__b2c__string_var(g_CASE_FALL__b2c__string_var, g_CASE_FALL__b2c__string_var , "||");
}
#line 5210 "bacon.bac"
}
#line 5211 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( g_CASE_CONT__b2c__string_var , "if (") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CASE_FALL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5212 "bacon.bac"
g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 1;
#line 5213 "bacon.bac"
g_CASE_FALL__b2c__string_var = __b2c_Copy_String(g_CASE_FALL__b2c__string_var, (char*) "");
#line 5214 "bacon.bac"
}
#line 5215 "bacon.bac"
} else {
#line 5216 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "CASE") + 4);
#line 5217 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(statement__b2c__string_var, 1) ,  ";") == 0 ){
#line 5218 "bacon.bac"
g_CASE_FALL__b2c__string_var = F_CONCAT__b2c__string_var(g_CASE_FALL__b2c__string_var, g_CASE_FALL__b2c__string_var , "(" , g_SELECTVAR__b2c__string_var[g_SELECTVAR_CTR] , ") == (" , LEFT__b2c__string_var(exp__b2c__string_var, LEN(exp__b2c__string_var)-1) , ") ||") ;
#line 5219 "bacon.bac"
} else {
#line 5220 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 5221 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 5222 "bacon.bac"
g_CASE_FALL__b2c__string_var = F_CONCAT__b2c__string_var(g_CASE_FALL__b2c__string_var, g_CASE_FALL__b2c__string_var , "(" , g_SELECTVAR__b2c__string_var[g_SELECTVAR_CTR] , ") == (" , str__b2c__string_var , ")") ;
#line 5223 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(str__b2c__string_var)+2);
#line 5224 "bacon.bac"
if( LEN(exp__b2c__string_var) ){
g_CASE_FALL__b2c__string_var = F_CONCAT__b2c__string_var(g_CASE_FALL__b2c__string_var, g_CASE_FALL__b2c__string_var , "||");
}
#line 5225 "bacon.bac"
}
#line 5226 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( g_CASE_CONT__b2c__string_var , "if (") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CASE_FALL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5227 "bacon.bac"
g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 1;
#line 5228 "bacon.bac"
g_CASE_FALL__b2c__string_var = __b2c_Copy_String(g_CASE_FALL__b2c__string_var, (char*) "");
#line 5229 "bacon.bac"
}
#line 5230 "bacon.bac"
}
#line 5231 "bacon.bac"
}
#line 5233 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DEFAULT")){
#line 5234 "bacon.bac"
if( ISTRUE(g_IN_CASE[(uint64_t)g_SELECTVAR_CTR]) ){
#line 5235 "bacon.bac"
__b2c__assign = (char*)"} else {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5236 "bacon.bac"
} else {
#line 5237 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: cannot use DEFAULT without previous CASE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5238 "bacon.bac"
exit(1);
#line 5239 "bacon.bac"
}
#line 5240 "bacon.bac"
g_IN_CASE[(uint64_t)g_SELECTVAR_CTR] = 0;
#line 5241 "bacon.bac"
g_CASE_FALL__b2c__string_var = __b2c_Copy_String(g_CASE_FALL__b2c__string_var, (char*) "");
#line 5243 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SETENVIRON")){
#line 5245 "bacon.bac"
if( dim == 1 ){
#line 5246 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SETENVIRON at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5247 "bacon.bac"
exit(1);
#line 5248 "bacon.bac"
} else {
#line 5250 "bacon.bac"
__b2c__assign = (char*)"SETENVIRON("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LAST__b2c__string_var(statement__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5251 "bacon.bac"
}
#line 5253 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SORT")){
#line 5254 "bacon.bac"
Handle_Sort(statement__b2c__string_var);
#line 5256 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "STOP")){
#line 5258 "bacon.bac"
if( dim == 1 ){
#line 5259 "bacon.bac"
__b2c__assign = (char*)"kill(getpid(), SIGSTOP);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5260 "bacon.bac"
} else {
#line 5261 "bacon.bac"
__b2c__assign = (char*)"kill(getpid(),"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) EXTRACT__b2c__string_var(LAST__b2c__string_var(statement__b2c__string_var), CHR__b2c__string_var(34)); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5262 "bacon.bac"
}
#line 5264 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "TRACE")){
#line 5266 "bacon.bac"
if( dim == 1 ){
#line 5267 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty TRACE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5268 "bacon.bac"
exit(1);
#line 5269 "bacon.bac"
} else {
#line 5270 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "MONITOR") == 0 ){
#line 5271 "bacon.bac"
g_TRACE=(long)( 1);
#line 5272 "bacon.bac"
__b2c__assign = (char*)"fprintf(stderr, \"File '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "' line %d: TRACE ON - press <SPACE> to execute the program step by step, <ESC> to exit.\\n\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5273 "bacon.bac"
g_MONITOR__b2c__string_var = __b2c_Copy_String(g_MONITOR__b2c__string_var, (char*) "");
#line 5274 "bacon.bac"
__b2c__forin_sym__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_sym__b2c__string_var_string, MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "MONITOR")+7)); __b2c__forin_sym__b2c__string_var_string_org = __b2c__forin_sym__b2c__string_var_string;
__b2c__forin_sym__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_sym__b2c__string_var_step, ",");
__b2c__forin_sym__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_sym__b2c__string_var_string, __b2c__forin_sym__b2c__string_var_step);
for(; __b2c__forin_sym__b2c__string_var_ptr > 0; __b2c__forin_sym__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_sym__b2c__string_var_string_org, __b2c__forin_sym__b2c__string_var_step, &sym__b2c__string_var);
#line 5275 "bacon.bac"
sym__b2c__string_var = F_CHOP__b2c__string_var(sym__b2c__string_var,EXTRACT__b2c__string_var(sym__b2c__string_var,"\\(.*", TRUE));
#line 5276 "bacon.bac"
if( Check_String_Type(sym__b2c__string_var) ){
#line 5277 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) REPLACE__b2c__string_var(sym__b2c__string_var, g_STRINGSIGN__b2c__string_var, "$"));
#line 5278 "bacon.bac"
g_MONITOR__b2c__string_var = F_CONCAT__b2c__string_var(g_MONITOR__b2c__string_var, g_MONITOR__b2c__string_var , "&& (" , sym__b2c__string_var , "== NULL ? fprintf(stderr, \"MONITOR: " , exp__b2c__string_var , " = NULL\\n\") : fprintf(stderr, \"MONITOR: " , exp__b2c__string_var , " = %s\\n\", " , sym__b2c__string_var , ") )") ;
#line 5279 "bacon.bac"
} else {
#line 5280 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) REPLACE__b2c__string_var(sym__b2c__string_var, g_FLOATSIGN__b2c__string_var, "#"));
#line 5281 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) REPLACE__b2c__string_var(exp__b2c__string_var, g_LONGSIGN__b2c__string_var, "%"));
#line 5282 "bacon.bac"
g_MONITOR__b2c__string_var = F_CONCAT__b2c__string_var(g_MONITOR__b2c__string_var, g_MONITOR__b2c__string_var , "&& fprintf(stderr, \"MONITOR: " , exp__b2c__string_var , " = %s\\n\", STR" , g_STRINGSIGN__b2c__string_var , "(" , sym__b2c__string_var , "))") ;
#line 5283 "bacon.bac"
}
#line 5284 "bacon.bac"
}
#line 5285 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "ON") == 0 ){
#line 5286 "bacon.bac"
g_TRACE=(long)( 1);
#line 5287 "bacon.bac"
__b2c__assign = (char*)"fprintf(stderr, \"File '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "' line %d: TRACE ON - press <SPACE> to execute the program step by step, <ESC> to exit.\\n\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5288 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "OFF") == 0 ){
#line 5289 "bacon.bac"
g_MONITOR__b2c__string_var = __b2c_Copy_String(g_MONITOR__b2c__string_var, (char*) "");
#line 5290 "bacon.bac"
g_TRACE=(long)( 0);
#line 5291 "bacon.bac"
}
#line 5292 "bacon.bac"
}
#line 5294 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "OPTION")){
#line 5296 "bacon.bac"
if( dim == 1 ){
#line 5297 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty OPTION at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5298 "bacon.bac"
exit(1);
#line 5299 "bacon.bac"
} else {
#line 5300 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "BASE") == 0  AND  dim == 3 ){
#line 5301 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-9]") ){
#line 5302 "bacon.bac"
g_OPTION_BASE=(long)( VAL(element__b2c__string_var[(uint64_t)3]));
#line 5303 "bacon.bac"
} else {
#line 5304 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION BASE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5305 "bacon.bac"
exit(1);
#line 5306 "bacon.bac"
}
#line 5307 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "COMPARE") == 0  AND  dim == 3 ){
#line 5308 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5309 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_compare = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5310 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__STRCMP"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5311 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "1|TRUE") ){
#line 5312 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__STRCMP __b2c__strcasecmp"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5313 "bacon.bac"
} else {
#line 5314 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__STRCMP __b2c__strcmp"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5315 "bacon.bac"
}
#line 5316 "bacon.bac"
} else {
#line 5317 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION COMPARE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5318 "bacon.bac"
exit(1);
#line 5319 "bacon.bac"
}
#line 5320 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "QUOTED") == 0  AND  dim == 3 ){
#line 5321 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5322 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_quoted = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5323 "bacon.bac"
} else {
#line 5324 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION QUOTED at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5325 "bacon.bac"
exit(1);
#line 5326 "bacon.bac"
}
#line 5327 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "UTF8") == 0  AND  dim == 3 ){
#line 5328 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5329 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_utf8 = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5330 "bacon.bac"
} else {
#line 5331 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION UTF8 at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5332 "bacon.bac"
exit(1);
#line 5333 "bacon.bac"
}
#line 5334 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "TLS") == 0  AND  dim >= 3 ){
#line 5335 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5336 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)3] ,  "1") == 0  OR  __b2c__STRCMP(element__b2c__string_var[(uint64_t)3] ,  "TRUE") == 0 ){
#line 5337 "bacon.bac"
g_OPTION_TLS=(long)( TRUE);
#line 5338 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_tls = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5339 "bacon.bac"
g_INC_TLS__b2c__string_var = F_CONCAT__b2c__string_var(g_INC_TLS__b2c__string_var, "#include <openssl/ssl.h>" , NL__b2c__string_var , "#include <openssl/err.h>") ;
#line 5340 "bacon.bac"
g_LIB_TLS__b2c__string_var = F_CHOP__b2c__string_var(g_LIB_TLS__b2c__string_var,EXEC__b2c__string_var("pkg-config --libs openssl"));
#line 5341 "bacon.bac"
} else {
#line 5342 "bacon.bac"
g_OPTION_TLS=(long)( FALSE);
#line 5343 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_tls = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5344 "bacon.bac"
}
#line 5345 "bacon.bac"
} else {
#line 5346 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION TLS at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5347 "bacon.bac"
exit(1);
#line 5348 "bacon.bac"
}
#line 5349 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "EVAL") == 0  AND  dim >= 3 ){
#line 5350 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5351 "bacon.bac"
g_CCFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_CCFLAGS__b2c__string_var, g_CCFLAGS__b2c__string_var , " " , CHOP__b2c__string_var(EXEC__b2c__string_var("pkg-config --cflags libmatheval"))) ;
#line 5352 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " " , CHOP__b2c__string_var(EXEC__b2c__string_var("pkg-config --libs libmatheval"))) ;
#line 5353 "bacon.bac"
g_OPTION_EVAL=(long)( TRUE);
#line 5354 "bacon.bac"
} else {
#line 5355 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION EVAL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5356 "bacon.bac"
exit(1);
#line 5357 "bacon.bac"
}
#line 5358 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "PROPER") == 0  AND  dim == 3 ){
#line 5359 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5360 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_proper = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5361 "bacon.bac"
} else {
#line 5362 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION PROPER at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5363 "bacon.bac"
exit(1);
#line 5364 "bacon.bac"
}
#line 5365 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "DELIM") == 0  AND  (dim )> 2 ){
#line 5366 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_delim = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "DELIM") + 6); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5367 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "INPUT") == 0  AND  (dim )> 2 ){
#line 5368 "bacon.bac"
g_OPTION_INPUT__b2c__string_var = __b2c_Copy_String(g_OPTION_INPUT__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5369 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "DQ") == 0  AND  (dim )> 2 ){
#line 5370 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_dq = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "DQ") + 3); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "&255;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5371 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "NO_C_ESC") == 0  AND  (dim )> 2 ){
#line 5372 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)3] ,  "TRUE") == 0  OR  __b2c__STRCMP(element__b2c__string_var[(uint64_t)3] ,  "1") == 0 ){
#line 5373 "bacon.bac"
g_OPTION_DISABLE_C_ESCAPE=(long)( 1);
#line 5374 "bacon.bac"
} else {
#line 5375 "bacon.bac"
g_OPTION_DISABLE_C_ESCAPE=(long)( 0);
#line 5376 "bacon.bac"
}
#line 5377 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "ESC") == 0  AND  (dim )> 2 ){
#line 5378 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_esc = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "ESC") + 4); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "&255;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5379 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "SOCKET") == 0  AND  dim == 3 ){
#line 5380 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-9]") ){
#line 5381 "bacon.bac"
g_OPTION_SOCKET=(long)( VAL(element__b2c__string_var[(uint64_t)3]));
#line 5382 "bacon.bac"
} else {
#line 5383 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION SOCKET at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5384 "bacon.bac"
exit(1);
#line 5385 "bacon.bac"
}
#line 5386 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "BREAK") == 0  AND  dim == 3 ){
#line 5387 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5388 "bacon.bac"
g_OPTION_BREAK=(long)( IIF(__b2c__STRCMP(element__b2c__string_var[(uint64_t)3] ,  "TRUE") == 0, 1, VAL(element__b2c__string_var[(uint64_t)3])));
#line 5389 "bacon.bac"
} else {
#line 5390 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION BREAK at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5391 "bacon.bac"
exit(1);
#line 5392 "bacon.bac"
}
#line 5393 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "MEMSTREAM") == 0  AND  dim == 3 ){
#line 5394 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5395 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_memstream = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5396 "bacon.bac"
} else {
#line 5397 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION MEMSTREAM at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5398 "bacon.bac"
exit(1);
#line 5399 "bacon.bac"
}
#line 5400 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "MEMTYPE") == 0  AND  (dim )> 2 ){
#line 5401 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__MEMTYPE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5402 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MEMTYPE "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "MEMTYPE")+8); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5403 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "PRIORITY") == 0  AND  (dim )> 2 ){
#line 5404 "bacon.bac"
g_PRIORITY__b2c__string_var = __b2c_Copy_String(g_PRIORITY__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5405 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "COLLAPSE") == 0  AND  dim == 3 ){
#line 5406 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5407 "bacon.bac"
__b2c__assign = (char*)"__b2c__collapse = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5408 "bacon.bac"
} else {
#line 5409 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION COLLAPSE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5410 "bacon.bac"
exit(1);
#line 5411 "bacon.bac"
}
#line 5412 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "DEVICE") == 0  AND  dim >= 3 ){
#line 5413 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_open = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5414 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "STARTPOINT") == 0  AND  dim == 3 ){
#line 5415 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5416 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_startpoint = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) element__b2c__string_var[(uint64_t)3]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5417 "bacon.bac"
} else {
#line 5418 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION STARTPOINT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5419 "bacon.bac"
exit(1);
#line 5420 "bacon.bac"
}
#line 5421 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "INTERNATIONAL") == 0  AND  dim == 3 ){
#line 5422 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "1|TRUE") ){
#line 5423 "bacon.bac"
__b2c__assign = (char*)"#include <libintl.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5424 "bacon.bac"
__b2c__assign = (char*)"setlocale(LC_ALL, \"\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5425 "bacon.bac"
__b2c__assign = (char*)"if(bindtextdomain(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTR(g_SOURCEFILE__b2c__string_var, ".")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\",\"/usr/share/locale\")==NULL){ ERROR = 6; RUNTIMEERROR(\"OPTION INTERNATIONAL\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5426 "bacon.bac"
__b2c__assign = (char*)"if(textdomain(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTR(g_SOURCEFILE__b2c__string_var, ".")-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\")==NULL){ ERROR = 6; RUNTIMEERROR(\"OPTION INTERNATIONAL\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5427 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 5428 "bacon.bac"
} else {
#line 5429 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION INTERNATIONAL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5430 "bacon.bac"
exit(1);
#line 5431 "bacon.bac"
}
#line 5432 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "NETWORK") == 0  AND  dim >= 3 ){
#line 5433 "bacon.bac"
__b2c__select_5433__b2c__string_var = __b2c_Copy_String(__b2c__select_5433__b2c__string_var, element__b2c__string_var[(uint64_t)3]);
#line 5434 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_5433__b2c__string_var, "TCP")){
#line 5435 "bacon.bac"
g_NETWORKTYPE__b2c__string_var = __b2c_Copy_String(g_NETWORKTYPE__b2c__string_var, (char*) "TCP");
#line 5436 "bacon.bac"
g_SOCKTYPE__b2c__string_var = __b2c_Copy_String(g_SOCKTYPE__b2c__string_var, (char*) "SOCK_STREAM");
#line 5437 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_5433__b2c__string_var, "UDP")){
#line 5438 "bacon.bac"
g_NETWORKTYPE__b2c__string_var = __b2c_Copy_String(g_NETWORKTYPE__b2c__string_var, (char*) "UDP");
#line 5439 "bacon.bac"
g_SOCKTYPE__b2c__string_var = __b2c_Copy_String(g_SOCKTYPE__b2c__string_var, (char*) "SOCK_DGRAM");
#line 5440 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_5433__b2c__string_var, "BROADCAST")){
#line 5441 "bacon.bac"
g_NETWORKTYPE__b2c__string_var = __b2c_Copy_String(g_NETWORKTYPE__b2c__string_var, (char*) "BROADCAST");
#line 5442 "bacon.bac"
g_SOCKTYPE__b2c__string_var = __b2c_Copy_String(g_SOCKTYPE__b2c__string_var, (char*) "SOCK_DGRAM");
#line 5443 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_5433__b2c__string_var, "MULTICAST")){
#line 5444 "bacon.bac"
g_NETWORKTYPE__b2c__string_var = __b2c_Copy_String(g_NETWORKTYPE__b2c__string_var, (char*) "MULTICAST");
#line 5445 "bacon.bac"
g_SOCKTYPE__b2c__string_var = __b2c_Copy_String(g_SOCKTYPE__b2c__string_var, (char*) "SOCK_DGRAM");
#line 5446 "bacon.bac"
if( dim == 4  AND  REGEX(element__b2c__string_var[(uint64_t)4], "[0-9]") ){
#line 5447 "bacon.bac"
g_MULTICAST_TTL=(long)( VAL(element__b2c__string_var[(uint64_t)4]));
#line 5448 "bacon.bac"
}
#line 5449 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_5433__b2c__string_var, "SCTP")){
#line 5450 "bacon.bac"
g_INCFILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCFILES__b2c__string_var, g_INCFILES__b2c__string_var , " <netinet/sctp.h>") ;
#line 5451 "bacon.bac"
__b2c__assign = (char*)"struct sctp_initmsg __b2c__initmsg;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5452 "bacon.bac"
g_NETWORKTYPE__b2c__string_var = __b2c_Copy_String(g_NETWORKTYPE__b2c__string_var, (char*) "SCTP");
#line 5453 "bacon.bac"
g_SOCKTYPE__b2c__string_var = __b2c_Copy_String(g_SOCKTYPE__b2c__string_var, (char*) "SOCK_STREAM");
#line 5454 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " -lsctp") ;
#line 5455 "bacon.bac"
if( dim == 4  AND  REGEX(element__b2c__string_var[(uint64_t)4], "[0-9]") ){
#line 5456 "bacon.bac"
g_SCTP_STREAMS=(long)( VAL(element__b2c__string_var[(uint64_t)4]));
#line 5457 "bacon.bac"
}
#line 5458 "bacon.bac"
} else {
#line 5459 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION NETWORK at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5460 "bacon.bac"
exit(1);
#line 5461 "bacon.bac"
}
#line 5462 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "PARSE") == 0  AND  dim == 3 ){
#line 5463 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5464 "bacon.bac"
g_IGNORE_PARSE__b2c__string_var = __b2c_Copy_String(g_IGNORE_PARSE__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5465 "bacon.bac"
} else {
#line 5466 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION PARSE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5467 "bacon.bac"
exit(1);
#line 5468 "bacon.bac"
}
#line 5469 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "EXPLICIT") == 0  AND  dim == 3 ){
#line 5470 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5471 "bacon.bac"
g_OPTION_EXPLICIT__b2c__string_var = __b2c_Copy_String(g_OPTION_EXPLICIT__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5472 "bacon.bac"
} else {
#line 5473 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION EXPLICIT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5474 "bacon.bac"
exit(1);
#line 5475 "bacon.bac"
}
#line 5476 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "LOCAL") == 0  AND  dim == 3 ){
#line 5477 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "[0-1]|TRUE|FALSE") ){
#line 5478 "bacon.bac"
g_OPTION_LOCAL__b2c__string_var = __b2c_Copy_String(g_OPTION_LOCAL__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5479 "bacon.bac"
} else {
#line 5480 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: invalid argument to OPTION LOCAL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5481 "bacon.bac"
exit(1);
#line 5482 "bacon.bac"
}
#line 5483 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "VARTYPE") == 0  AND  (dim )> 2 ){
#line 5484 "bacon.bac"
g_VARTYPE__b2c__string_var = F_MID__b2c__string_var(g_VARTYPE__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "VARTYPE")+8);
#line 5485 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "GUI") == 0  AND  dim == 3 ){
#line 5486 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)3], "1|TRUE") ){
#line 5487 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5488 "bacon.bac"
__b2c__assign = (char*)"#ifdef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5489 "bacon.bac"
__b2c__assign = (char*)"#include <AllWidgets.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5490 "bacon.bac"
__b2c__assign = (char*)"#include <AsciiText.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5491 "bacon.bac"
__b2c__assign = (char*)"#include <Box.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5492 "bacon.bac"
__b2c__assign = (char*)"#include <Dialog.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5493 "bacon.bac"
__b2c__assign = (char*)"#include <Command.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5494 "bacon.bac"
__b2c__assign = (char*)"#include <Form.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5495 "bacon.bac"
__b2c__assign = (char*)"#include <Grip.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5496 "bacon.bac"
__b2c__assign = (char*)"#include <List.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5497 "bacon.bac"
__b2c__assign = (char*)"#include <MenuButton.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5498 "bacon.bac"
__b2c__assign = (char*)"#include <MultiSink.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5499 "bacon.bac"
__b2c__assign = (char*)"#include <Paned.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5500 "bacon.bac"
__b2c__assign = (char*)"#include <Panner.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5501 "bacon.bac"
__b2c__assign = (char*)"#include <Porthole.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5502 "bacon.bac"
__b2c__assign = (char*)"#include <Repeater.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5503 "bacon.bac"
__b2c__assign = (char*)"#include <Scrollbar.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5504 "bacon.bac"
__b2c__assign = (char*)"#include <SimpleMenu.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5505 "bacon.bac"
__b2c__assign = (char*)"#include <SmeBSB.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5506 "bacon.bac"
__b2c__assign = (char*)"#include <SmeLine.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5507 "bacon.bac"
__b2c__assign = (char*)"#include <StripChart.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5508 "bacon.bac"
__b2c__assign = (char*)"#include <Tip.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5509 "bacon.bac"
__b2c__assign = (char*)"#include <Toggle.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5510 "bacon.bac"
__b2c__assign = (char*)"#include <Tree.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5511 "bacon.bac"
__b2c__assign = (char*)"#include <Viewport.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5512 "bacon.bac"
__b2c__assign = (char*)"#include <X11/Intrinsic.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5513 "bacon.bac"
__b2c__assign = (char*)"#include <X11/Shell.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5514 "bacon.bac"
__b2c__assign = (char*)"#include <X11/StringDefs.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5515 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5516 "bacon.bac"
g_CCFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_CCFLAGS__b2c__string_var, g_CCFLAGS__b2c__string_var , " -I/usr/include/X11/Xaw") ;
#line 5517 "bacon.bac"
g_INCLUDE_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCLUDE_FILES__b2c__string_var, g_INCLUDE_FILES__b2c__string_var , " " , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".gui.h") ;
#line 5518 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var,  g_LDFLAGS__b2c__string_var , " -lXaw -lXmu -lXt -lX11") ;
#line 5519 "bacon.bac"
}
#line 5520 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "ERROR") == 0  AND  dim == 3 ){
#line 5521 "bacon.bac"
__b2c__assign = (char*)"WARNING: OPTION ERROR is deprecated."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 5522 "bacon.bac"
} else {
#line 5523 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: argument to OPTION at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' not recognized!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5524 "bacon.bac"
exit(1);
#line 5525 "bacon.bac"
}
#line 5526 "bacon.bac"
}
#line 5528 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PROTO")){
#line 5530 "bacon.bac"
if( dim == 1 ){
#line 5531 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty PROTO at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5532 "bacon.bac"
exit(1);
#line 5533 "bacon.bac"
} else {
#line 5534 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) EXTRACT__b2c__string_var(LAST__b2c__string_var(statement__b2c__string_var), CHR__b2c__string_var(34)));
#line 5536 "bacon.bac"
if( ISTOKEN(exp__b2c__string_var, "ALIAS") ){
#line 5537 "bacon.bac"
__b2c__assign = (char*)"#define "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(TOKEN__b2c__string_var(exp__b2c__string_var, 2, "ALIAS")); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(TOKEN__b2c__string_var(exp__b2c__string_var, 1, "ALIAS")); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5538 "bacon.bac"
g_IMPORTED__b2c__string_var = F_CONCAT__b2c__string_var(g_IMPORTED__b2c__string_var, TOKEN__b2c__string_var(exp__b2c__string_var, 2, "ALIAS") , " " , g_IMPORTED__b2c__string_var) ;
#line 5539 "bacon.bac"
g_IMPORTED__b2c__string_var = F_CONCAT__b2c__string_var(g_IMPORTED__b2c__string_var, TOKEN__b2c__string_var(exp__b2c__string_var, 1, "ALIAS") , " " , g_IMPORTED__b2c__string_var) ;
#line 5540 "bacon.bac"
} else if( ISTOKEN(exp__b2c__string_var, "TYPE") ){
#line 5541 "bacon.bac"
__b2c__assign = (char*)TOKEN__b2c__string_var(exp__b2c__string_var, 2, "TYPE"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(exp__b2c__string_var, 1, "TYPE"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5542 "bacon.bac"
} else {
#line 5543 "bacon.bac"
g_IMPORTED__b2c__string_var = F_CONCAT__b2c__string_var(g_IMPORTED__b2c__string_var, REPLACE__b2c__string_var(exp__b2c__string_var, ",", " ") , " " , g_IMPORTED__b2c__string_var) ;
#line 5544 "bacon.bac"
}
#line 5545 "bacon.bac"
}
#line 5547 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "INCR")){
#line 5549 "bacon.bac"
if( dim == 1 ){
#line 5550 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty INCR at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5551 "bacon.bac"
exit(1);
#line 5552 "bacon.bac"
} else {
#line 5554 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(statement__b2c__string_var));
#line 5556 "bacon.bac"
exp__b2c__string_var = F_CHOP__b2c__string_var(exp__b2c__string_var,MID__b2c__string_var(statement__b2c__string_var, LEN(token__b2c__string_var)+2));
#line 5557 "bacon.bac"
if( NOT(LEN(exp__b2c__string_var)) ){
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) "1");
}
#line 5558 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,MID__b2c__string_var(token__b2c__string_var, INSTR(token__b2c__string_var, " ")));
#line 5560 "bacon.bac"
if( REGEX(token__b2c__string_var, "[a-zA-Z]+\\(.*\\)$") ){
#line 5561 "bacon.bac"
lft__b2c__string_var = __b2c_Copy_String(lft__b2c__string_var, (char*) LEFT__b2c__string_var(token__b2c__string_var, INSTR(token__b2c__string_var, "(") - 1));
#line 5562 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) INBETWEEN__b2c__string_var(token__b2c__string_var, "(", ")", 2));
#line 5563 "bacon.bac"
__b2c__assign = (char*)"__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " + ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__hash_add(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5565 "bacon.bac"
Relate_Recurse(lft__b2c__string_var, str__b2c__string_var, CONCAT__b2c__string_var( token__b2c__string_var , "+(" , exp__b2c__string_var , ")") , -1);
#line 5566 "bacon.bac"
} else {
#line 5568 "bacon.bac"
if( REGEX(exp__b2c__string_var, "[0-9]\\.[0-9]") ){
#line 5569 "bacon.bac"
Register_Numeric(token__b2c__string_var, "double");
#line 5570 "bacon.bac"
} else if( NOT(LEN(Get_Var__b2c__string_var(token__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 5571 "bacon.bac"
Register_Numeric(token__b2c__string_var, "default");
#line 5572 "bacon.bac"
}
#line 5573 "bacon.bac"
__b2c__assign = (char*)token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " + ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5574 "bacon.bac"
}
#line 5575 "bacon.bac"
}
#line 5577 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "DECR")){
#line 5579 "bacon.bac"
if( dim == 1 ){
#line 5580 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty DECR at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5581 "bacon.bac"
exit(1);
#line 5582 "bacon.bac"
} else {
#line 5584 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(statement__b2c__string_var));
#line 5586 "bacon.bac"
exp__b2c__string_var = F_CHOP__b2c__string_var(exp__b2c__string_var,MID__b2c__string_var(statement__b2c__string_var, LEN(token__b2c__string_var)+2));
#line 5587 "bacon.bac"
if( NOT(LEN(exp__b2c__string_var)) ){
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) "1");
}
#line 5588 "bacon.bac"
token__b2c__string_var = F_CHOP__b2c__string_var(token__b2c__string_var,MID__b2c__string_var(token__b2c__string_var, INSTR(token__b2c__string_var, " ")));
#line 5590 "bacon.bac"
if( REGEX(token__b2c__string_var, "[a-zA-Z]+\\(.*\\)$") ){
#line 5591 "bacon.bac"
lft__b2c__string_var = __b2c_Copy_String(lft__b2c__string_var, (char*) LEFT__b2c__string_var(token__b2c__string_var, INSTR(token__b2c__string_var, "(") - 1));
#line 5592 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) INBETWEEN__b2c__string_var(token__b2c__string_var, "(", ")", 2));
#line 5593 "bacon.bac"
__b2c__assign = (char*)"__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " - ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__hash_add(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5595 "bacon.bac"
Relate_Recurse(lft__b2c__string_var, str__b2c__string_var, CONCAT__b2c__string_var( token__b2c__string_var , "+(" , exp__b2c__string_var , ")") , -1);
#line 5596 "bacon.bac"
} else {
#line 5598 "bacon.bac"
if( REGEX(exp__b2c__string_var, "[0-9]\\.[0-9]") ){
#line 5599 "bacon.bac"
Register_Numeric(token__b2c__string_var, "double");
#line 5600 "bacon.bac"
} else if( NOT(LEN(Get_Var__b2c__string_var(token__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 5601 "bacon.bac"
Register_Numeric(token__b2c__string_var, "default");
#line 5602 "bacon.bac"
}
#line 5603 "bacon.bac"
__b2c__assign = (char*)token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " - ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5604 "bacon.bac"
}
#line 5605 "bacon.bac"
}
#line 5607 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ALARM")){
#line 5609 "bacon.bac"
if( dim == 1 ){
#line 5610 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty ALARM at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5611 "bacon.bac"
exit(1);
#line 5612 "bacon.bac"
} else {
#line 5613 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) EXTRACT__b2c__string_var(TOKEN__b2c__string_var(statement__b2c__string_var, 1, ","), "^ALARM ", TRUE));
#line 5614 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) TOKEN__b2c__string_var(statement__b2c__string_var, 2, ","));
#line 5615 "bacon.bac"
__b2c__assign = (char*)"__b2c__alarm((void*)(uintptr_t)(&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5616 "bacon.bac"
}
#line 5618 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SIGNAL")){
#line 5620 "bacon.bac"
if( dim == 1 ){
#line 5621 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SIGNAL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5622 "bacon.bac"
exit(1);
#line 5623 "bacon.bac"
} else {
#line 5625 "bacon.bac"
__b2c__split_by(&symbol__b2c__string_var, 1, &symbol__b2c__string_var__b2c_array, LAST__b2c__string_var(statement__b2c__string_var), ",");
dim = symbol__b2c__string_var__b2c_array;
#line 5626 "bacon.bac"
if( dim == 2 ){
#line 5627 "bacon.bac"
if( ISTOKEN(symbol__b2c__string_var[(uint64_t)1], "SIG_DFL")  OR  ISTOKEN(symbol__b2c__string_var[(uint64_t)1], "SIG_IGN") ){
#line 5628 "bacon.bac"
__b2c__assign = (char*)"__b2c__signal((void*)(uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)1]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5629 "bacon.bac"
} else {
#line 5630 "bacon.bac"
__b2c__assign = (char*)"__b2c__signal((void*)(uintptr_t)(&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)1]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5631 "bacon.bac"
}
#line 5632 "bacon.bac"
} else {
#line 5633 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing argument in SIGNAL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5634 "bacon.bac"
exit(1);
#line 5635 "bacon.bac"
}
#line 5636 "bacon.bac"
}
#line 5638 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CURSOR")){
#line 5640 "bacon.bac"
if( dim == 1 ){
#line 5641 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CURSOR at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5642 "bacon.bac"
exit(1);
#line 5643 "bacon.bac"
} else {
#line 5644 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) IIF__b2c__string_var(dim == 3, element__b2c__string_var[(uint64_t)3], "1"));
#line 5645 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "ON") == 0 ){
#line 5646 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[?25h\"); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5647 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "OFF") == 0 ){
#line 5648 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[?25l\"); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5649 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "UP") == 0 ){
#line 5650 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ldA\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5651 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "DOWN") == 0 ){
#line 5652 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ldB\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5653 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "FORWARD") == 0 ){
#line 5654 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ldC\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5655 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "BACK") == 0 ){
#line 5656 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ldD\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5657 "bacon.bac"
}
#line 5658 "bacon.bac"
}
#line 5660 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SCROLL")){
#line 5661 "bacon.bac"
if( dim == 1 ){
#line 5662 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SCROLL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5663 "bacon.bac"
exit(1);
#line 5664 "bacon.bac"
} else {
#line 5665 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) IIF__b2c__string_var(dim == 3, element__b2c__string_var[(uint64_t)3], "1"));
#line 5666 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "UP") == 0 ){
#line 5667 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ldS\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5668 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "DOWN") == 0 ){
#line 5669 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ldT\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5670 "bacon.bac"
}
#line 5671 "bacon.bac"
}
#line 5673 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ALIAS")){
#line 5674 "bacon.bac"
Handle_Alias(statement__b2c__string_var);
#line 5676 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "LOOKUP")){
#line 5677 "bacon.bac"
Handle_Lookup(statement__b2c__string_var);
#line 5679 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RELATE")){
#line 5680 "bacon.bac"
Handle_Relate(CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "RELATE") + 6)));
#line 5682 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "TEXTDOMAIN")){
#line 5684 "bacon.bac"
if( dim == 1 ){
#line 5685 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty TEXTDOMAIN at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5686 "bacon.bac"
exit(1);
#line 5687 "bacon.bac"
} else {
#line 5689 "bacon.bac"
__b2c__split_by(&symbol__b2c__string_var, 1, &symbol__b2c__string_var__b2c_array, CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "TEXTDOMAIN") + 10)), ",");
dim = symbol__b2c__string_var__b2c_array;
#line 5690 "bacon.bac"
if( dim == 2 ){
#line 5691 "bacon.bac"
__b2c__assign = (char*)"if(bindtextdomain("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)1]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)2]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")==NULL){ ERROR = 6; RUNTIMEERROR(\"TEXTDOMAIN\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5692 "bacon.bac"
__b2c__assign = (char*)"if(textdomain("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) symbol__b2c__string_var[(uint64_t)1]; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")==NULL){ ERROR = 6; RUNTIMEERROR(\"TEXTDOMAIN\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5693 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 5694 "bacon.bac"
} else {
#line 5695 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing argument in TEXTDOMAIN at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5696 "bacon.bac"
exit(1);
#line 5697 "bacon.bac"
}
#line 5698 "bacon.bac"
}
#line 5700 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "REDIM")){
#line 5701 "bacon.bac"
Handle_Redim(CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "REDIM") + 5)));
#line 5703 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "EXIT")){
#line 5704 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) == 0 ){
#line 5705 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: EXIT not in FUNCTION or SUB at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5706 "bacon.bac"
exit(1);
#line 5707 "bacon.bac"
}
#line 5709 "bacon.bac"
__b2c__assign = (char*)g_STRINGARRAYS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5710 "bacon.bac"
__b2c__forin_exp__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_exp__b2c__string_var_string, g_LOCALSTRINGS__b2c__string_var); __b2c__forin_exp__b2c__string_var_string_org = __b2c__forin_exp__b2c__string_var_string;
__b2c__forin_exp__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_exp__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_exp__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_exp__b2c__string_var_string, __b2c__forin_exp__b2c__string_var_step);
for(; __b2c__forin_exp__b2c__string_var_ptr > 0; __b2c__forin_exp__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_exp__b2c__string_var_string_org, __b2c__forin_exp__b2c__string_var_step, &exp__b2c__string_var);
#line 5711 "bacon.bac"
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5712 "bacon.bac"
}
#line 5713 "bacon.bac"
__b2c__assign = (char*)"__b2c__catch_set = __b2c__catch_set_backup;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5715 "bacon.bac"
if( INSTR(g_FUNCNAME__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 5716 "bacon.bac"
__b2c__assign = (char*)"return(NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5717 "bacon.bac"
} else {
#line 5718 "bacon.bac"
__b2c__assign = (char*)"return __b2c__exitval;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5719 "bacon.bac"
}
#line 5721 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PRAGMA")){
#line 5723 "bacon.bac"
if( dim == 1 ){
#line 5724 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty PRAGMA at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5725 "bacon.bac"
exit(1);
#line 5726 "bacon.bac"
} else {
#line 5727 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "OPTIONS") == 0  AND  dim >= 3 ){
#line 5728 "bacon.bac"
for(i=3; i <= dim; i+=1){
#line 5729 "bacon.bac"
g_CCFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_CCFLAGS__b2c__string_var, g_CCFLAGS__b2c__string_var , " " , element__b2c__string_var[i]) ;
#line 5730 "bacon.bac"
}
#line 5731 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "COMPILER") == 0  AND  dim == 3 ){
#line 5732 "bacon.bac"
g_CCNAME__b2c__string_var = __b2c_Copy_String(g_CCNAME__b2c__string_var, (char*) element__b2c__string_var[(uint64_t)3]);
#line 5733 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "FRAMEWORK") == 0  AND  dim >= 3 ){
#line 5734 "bacon.bac"
for(i=3; i <= dim; i+=1){
#line 5735 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " -framework " , element__b2c__string_var[i]) ;
#line 5736 "bacon.bac"
}
#line 5737 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "RE") == 0  AND  dim >= 3 ){
#line 5738 "bacon.bac"
g_PRAGMA_REGEX__b2c__string_var = F_MID__b2c__string_var(g_PRAGMA_REGEX__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "RE")+3);
#line 5739 "bacon.bac"
if( NOT(REGEX(g_PRAGMA_REGEX__b2c__string_var, " LDFLAGS ")) ){
#line 5740 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) HEAD__b2c__string_var(g_PRAGMA_REGEX__b2c__string_var));
#line 5741 "bacon.bac"
if( INSTR(exp__b2c__string_var, "tre") ){
#line 5742 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " " , CHOP__b2c__string_var(EXEC__b2c__string_var("pkg-config --libs tre"))) ;
#line 5743 "bacon.bac"
} else if( INSTR(exp__b2c__string_var, "pcre") ){
#line 5744 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " " , CHOP__b2c__string_var(EXEC__b2c__string_var("pkg-config --libs libpcreposix"))) ;
#line 5745 "bacon.bac"
} else if( INSTR(exp__b2c__string_var, "onig") ){
#line 5746 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " " , CHOP__b2c__string_var(EXEC__b2c__string_var("pkg-config --libs oniguruma"))) ;
#line 5747 "bacon.bac"
}
#line 5748 "bacon.bac"
} else {
#line 5749 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,g_PRAGMA_REGEX__b2c__string_var, INSTR(g_PRAGMA_REGEX__b2c__string_var, " LDFLAGS ")+9);
#line 5750 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, exp__b2c__string_var , " " , g_LDFLAGS__b2c__string_var) ;
#line 5751 "bacon.bac"
}
#line 5752 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "TLS") == 0  AND  dim >= 3 ){
#line 5753 "bacon.bac"
g_LIB_TLS__b2c__string_var = F_MID__b2c__string_var(g_LIB_TLS__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "TLS")+4);
#line 5754 "bacon.bac"
g_OPTION_TLS=(long)( TRUE);
#line 5755 "bacon.bac"
__b2c__assign = (char*)"__b2c__option_tls = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5756 "bacon.bac"
if( NOT(REGEX(g_LIB_TLS__b2c__string_var, " LDFLAGS ")) ){
#line 5757 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) HEAD__b2c__string_var(g_LIB_TLS__b2c__string_var));
#line 5758 "bacon.bac"
if( TALLY(exp__b2c__string_var, "openssl") ){
#line 5759 "bacon.bac"
g_LIB_TLS__b2c__string_var = F_CHOP__b2c__string_var(g_LIB_TLS__b2c__string_var,EXEC__b2c__string_var("pkg-config --libs openssl"));
#line 5760 "bacon.bac"
g_INC_TLS__b2c__string_var = F_CONCAT__b2c__string_var(g_INC_TLS__b2c__string_var, "#include <openssl/ssl.h>" , NL__b2c__string_var , "#include <openssl/err.h>") ;
#line 5761 "bacon.bac"
} else if( TALLY(exp__b2c__string_var, "gnutls") ){
#line 5762 "bacon.bac"
g_LIB_TLS__b2c__string_var = F_CONCAT__b2c__string_var(g_LIB_TLS__b2c__string_var, CHOP__b2c__string_var(EXEC__b2c__string_var("pkg-config --libs gnutls")) , " -lgnutls-openssl") ;
#line 5763 "bacon.bac"
g_INC_TLS__b2c__string_var = __b2c_Copy_String(g_INC_TLS__b2c__string_var, (char*) "#include <gnutls/openssl.h>");
#line 5764 "bacon.bac"
} else if( INSTR(exp__b2c__string_var, "wolfssl") ){
#line 5765 "bacon.bac"
g_LIB_TLS__b2c__string_var = F_CHOP__b2c__string_var(g_LIB_TLS__b2c__string_var,EXEC__b2c__string_var("pkg-config --libs wolfssl"));
#line 5766 "bacon.bac"
g_INC_TLS__b2c__string_var = F_CONCAT__b2c__string_var(g_INC_TLS__b2c__string_var, "#include <wolfssl/options.h>" , NL__b2c__string_var , "#include <wolfssl/openssl/ssl.h>") ;
#line 5767 "bacon.bac"
}
#line 5768 "bacon.bac"
} else {
#line 5769 "bacon.bac"
g_INC_TLS__b2c__string_var = __b2c_Copy_String(g_INC_TLS__b2c__string_var, (char*) LEFT__b2c__string_var(g_LIB_TLS__b2c__string_var, INSTR(g_LIB_TLS__b2c__string_var, " LDFLAGS ")-1));
#line 5770 "bacon.bac"
g_LIB_TLS__b2c__string_var = F_MID__b2c__string_var(g_LIB_TLS__b2c__string_var,g_LIB_TLS__b2c__string_var, INSTR(g_LIB_TLS__b2c__string_var, " LDFLAGS ")+9);
#line 5771 "bacon.bac"
}
#line 5772 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "GUI") == 0  AND  dim >= 3 ){
#line 5773 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "GUI")+4);
#line 5774 "bacon.bac"
if( NOT(INSTR(exp__b2c__string_var, " LDFLAGS ")) ){
#line 5775 "bacon.bac"
if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "xaw3d") == 0 ){
#line 5776 "bacon.bac"
__b2c__assign = (char*)"#include <ThreeD.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5777 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw", "-lXaw3d"));
#line 5778 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", "-I/usr/include/X11/Xaw3d"));
#line 5779 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "motif") == 0 ){
#line 5780 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5781 "bacon.bac"
__b2c__assign = (char*)"#include <Xm/XmAll.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5782 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw", "-lXm"));
#line 5783 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) EXTRACT__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw"));
#line 5784 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "uil") == 0 ){
#line 5785 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5786 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__gui_uil"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5787 "bacon.bac"
__b2c__assign = (char*)"#include <Xm/XmAll.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5788 "bacon.bac"
__b2c__assign = (char*)"#include <Mrm/MrmAppl.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5789 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw", "-lMrm -lXm"));
#line 5790 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) EXTRACT__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw"));
#line 5791 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "gtk2") == 0 ){
#line 5792 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5793 "bacon.bac"
__b2c__assign = (char*)"#include <gtk/gtk.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5794 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs gtk+-2.0`"));
#line 5795 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", "`pkg-config --cflags gtk+-2.0`"));
#line 5796 "bacon.bac"
g_WHICH_GUI=(long)( 1);
#line 5797 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "gtk3") == 0 ){
#line 5798 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5799 "bacon.bac"
__b2c__assign = (char*)"#include <gtk/gtk.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5800 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs gtk+-3.0`"));
#line 5801 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", "`pkg-config --cflags gtk+-3.0`"));
#line 5802 "bacon.bac"
g_WHICH_GUI=(long)( 1);
#line 5803 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "gtk4") == 0 ){
#line 5804 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5805 "bacon.bac"
__b2c__assign = (char*)"#include <gtk/gtk.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5806 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs gtk4`"));
#line 5807 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", "`pkg-config --cflags gtk4`"));
#line 5808 "bacon.bac"
g_WHICH_GUI=(long)( 3);
#line 5809 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "cdk") == 0 ){
#line 5810 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5811 "bacon.bac"
__b2c__assign = (char*)"#include <cdk.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5812 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw -lXmu -lXt -lX11", "-lncurses -lcdk"));
#line 5813 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", "-I/usr/include/cdk"));
#line 5814 "bacon.bac"
g_WHICH_GUI=(long)( 2);
#line 5815 "bacon.bac"
} else if( __b2c__STRCMP(LCASE__b2c__string_var(HEAD__b2c__string_var(exp__b2c__string_var)) ,  "tk") == 0 ){
#line 5816 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__gui_xaw"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 5817 "bacon.bac"
__b2c__assign = (char*)"#include <tcl.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5818 "bacon.bac"
__b2c__assign = (char*)"#include <tk.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5819 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw -lXmu -lXt -lX11", "`pkg-config --libs tk tcl`"));
#line 5820 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", "`pkg-config --cflags tk tcl`"));
#line 5821 "bacon.bac"
g_WHICH_GUI=(long)( 4);
#line 5822 "bacon.bac"
}
#line 5823 "bacon.bac"
if( g_WHICH_GUI == 1 ){
#line 5824 "bacon.bac"
__b2c__assign = (char*)"#define GTKINIT gtk_init(NULL,NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5825 "bacon.bac"
__b2c__assign = (char*)"#define GTKMAINITERATION gtk_main_iteration()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5826 "bacon.bac"
__b2c__assign = (char*)"#define GTKWIDGETSHOW gtk_widget_show_all"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5827 "bacon.bac"
__b2c__assign = (char*)"#define GTKCONTAINERADD(x,y) gtk_container_add(GTK_CONTAINER(x), GTK_WIDGET(y))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5828 "bacon.bac"
} else if( g_WHICH_GUI == 3 ){
#line 5829 "bacon.bac"
__b2c__assign = (char*)"#define GTKINIT gtk_init()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5830 "bacon.bac"
__b2c__assign = (char*)"#define GTKMAINITERATION g_main_context_iteration(NULL,1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5831 "bacon.bac"
__b2c__assign = (char*)"#define GTKWIDGETSHOW gtk_widget_show"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5832 "bacon.bac"
__b2c__assign = (char*)"#define GTKCONTAINERADD(x,y) (GTK_IS_BOX(x) ? gtk_box_append(GTK_BOX(x), GTK_WIDGET(y)) : g_object_set(GTK_WIDGET(x), \"child\", GTK_WIDGET(y), NULL))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5833 "bacon.bac"
}
#line 5834 "bacon.bac"
} else {
#line 5835 "bacon.bac"
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_LDFLAGS__b2c__string_var, "-lXaw", TOKEN__b2c__string_var(exp__b2c__string_var, 2, " LDFLAGS ")));
#line 5836 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) REPLACE__b2c__string_var(g_CCFLAGS__b2c__string_var, "-I/usr/include/X11/Xaw", TOKEN__b2c__string_var(TOKEN__b2c__string_var(exp__b2c__string_var, 1, " LDFLAGS "), 2, " OPTIONS ")));
#line 5837 "bacon.bac"
}
#line 5838 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "LDFLAGS") == 0  AND  dim >= 3 ){
#line 5839 "bacon.bac"
if( TALLY(TOKEN__b2c__string_var(statement__b2c__string_var, 2, "LDFLAGS"), "pkg-config")  OR  TALLY(TOKEN__b2c__string_var(statement__b2c__string_var, 2, "LDFLAGS"), "fltk-config") ){
#line 5840 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, TOKEN__b2c__string_var(statement__b2c__string_var, 2, "LDFLAGS") , " " , g_LDFLAGS__b2c__string_var) ;
#line 5841 "bacon.bac"
} else {
#line 5842 "bacon.bac"
for(i=3; i <= dim; i+=1){
#line 5843 "bacon.bac"
if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)i] ,  "TRUE") == 0 ){
#line 5844 "bacon.bac"
found=(
long)( TRUE);
#line 5845 "bacon.bac"
break;
#line 5846 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)i], 1) ,  "-") == 0  OR  __b2c__STRCMP(RIGHT__b2c__string_var(element__b2c__string_var[(uint64_t)i], 2) ,  ".a") == 0 ){
#line 5847 "bacon.bac"
exp__b2c__string_var = F_CONCAT__b2c__string_var(exp__b2c__string_var, exp__b2c__string_var , " " , element__b2c__string_var[i]) ;
#line 5848 "bacon.bac"
} else {
#line 5849 "bacon.bac"
exp__b2c__string_var = F_CONCAT__b2c__string_var(exp__b2c__string_var, exp__b2c__string_var , " -l" , element__b2c__string_var[i]) ;
#line 5850 "bacon.bac"
}
#line 5851 "bacon.bac"
}
#line 5852 "bacon.bac"
if( found ){
#line 5853 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, exp__b2c__string_var , " " , g_LDFLAGS__b2c__string_var) ;
#line 5854 "bacon.bac"
} else {
#line 5855 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " " , exp__b2c__string_var) ;
#line 5856 "bacon.bac"
}
#line 5857 "bacon.bac"
}
#line 5858 "bacon.bac"
} else if( __b2c__STRCMP(element__b2c__string_var[(uint64_t)2] ,  "INCLUDE") == 0  AND  dim >= 3 ){
#line 5859 "bacon.bac"
for(i=3; i <= dim; i+=1){
#line 5860 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)i], 1) ,  "/") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)i], 2) ,  "./") == 0 ){
#line 5861 "bacon.bac"
g_PRAGMA_INCLUDE__b2c__string_var = F_CONCAT__b2c__string_var(g_PRAGMA_INCLUDE__b2c__string_var, g_PRAGMA_INCLUDE__b2c__string_var , NL__b2c__string_var , "#include " , CHR__b2c__string_var(34) , element__b2c__string_var[(uint64_t)i] , CHR__b2c__string_var(34)) ;
#line 5862 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(element__b2c__string_var[(uint64_t)i], 1) ,  "<") == 0 ){
#line 5863 "bacon.bac"
g_PRAGMA_INCLUDE__b2c__string_var = F_CONCAT__b2c__string_var(g_PRAGMA_INCLUDE__b2c__string_var, g_PRAGMA_INCLUDE__b2c__string_var , NL__b2c__string_var , "#include " , element__b2c__string_var[(uint64_t)i]) ;
#line 5864 "bacon.bac"
} else {
#line 5865 "bacon.bac"
g_PRAGMA_INCLUDE__b2c__string_var = F_CONCAT__b2c__string_var(g_PRAGMA_INCLUDE__b2c__string_var, g_PRAGMA_INCLUDE__b2c__string_var , NL__b2c__string_var , "#include " , CHR__b2c__string_var(34) , CURDIR__b2c__string_var , "/" , element__b2c__string_var[(uint64_t)i] , CHR__b2c__string_var(34)) ;
#line 5866 "bacon.bac"
}
#line 5867 "bacon.bac"
}
#line 5868 "bacon.bac"
} else {
#line 5869 "bacon.bac"
__b2c__assign = (char*)"#pragma "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "PRAGMA") + 6)); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5870 "bacon.bac"
}
#line 5871 "bacon.bac"
}
#line 5873 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SWAP")){
#line 5874 "bacon.bac"
Handle_Swap(statement__b2c__string_var);
#line 5876 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SETSERIAL")){
#line 5877 "bacon.bac"
Handle_Setserial(CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SETSERIAL") + 9)));
#line 5879 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "ENUM")){
#line 5880 "bacon.bac"
if( NOT(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 5881 "bacon.bac"
__b2c__assign = (char*)"enum {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 5882 "bacon.bac"
g_USE_H=(long)( 1);
#line 5883 "bacon.bac"
} else {
#line 5884 "bacon.bac"
__b2c__assign = (char*)"enum {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5885 "bacon.bac"
g_USE_C=(long)( 1);
#line 5886 "bacon.bac"
}
#line 5888 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RUN")){
#line 5889 "bacon.bac"
Handle_Run(statement__b2c__string_var);
#line 5891 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "SAVE")){
#line 5892 "bacon.bac"
Handle_Save(0, CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "SAVE") + 4)));
#line 5894 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "BSAVE")){
#line 5895 "bacon.bac"
Handle_Save(1, CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "BSAVE") + 5)));
#line 5897 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "APPEND")){
#line 5898 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "APPEND") + 6);
#line 5899 "bacon.bac"
if( NOT(ISTOKEN(exp__b2c__string_var, "TO"))  AND  HASDELIM(exp__b2c__string_var, ",") ){
#line 5900 "bacon.bac"
__b2c__assign = (char*)TOKEN__b2c__string_var(exp__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "= F_CONCAT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(exp__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5901 "bacon.bac"
} else {
#line 5902 "bacon.bac"
Handle_Save(2, CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "APPEND") + 6)));
#line 5903 "bacon.bac"
}
#line 5905 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "BAPPEND")){
#line 5906 "bacon.bac"
Handle_Save(3, CHOP__b2c__string_var(MID__b2c__string_var(statement__b2c__string_var, INSTR(statement__b2c__string_var, "BAPPEND") + 7)));
#line 5908 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "MAP")){
#line 5909 "bacon.bac"
Handle_Map(statement__b2c__string_var);
#line 5911 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "RESET")){
#line 5912 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033c\"); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5914 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "CERTIFICATE")){
#line 5916 "bacon.bac"
if( dim == 1 ){
#line 5917 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CERTIFICATE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 5918 "bacon.bac"
exit(1);
#line 5919 "bacon.bac"
} else {
#line 5920 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,statement__b2c__string_var, INSTR(statement__b2c__string_var, "CERTIFICATE") + 11);
#line 5921 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 5922 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__caprivate"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5923 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__caprivate "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5924 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 5925 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 5926 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__caserver"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5927 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__caserver "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5928 "bacon.bac"
}
#line 5930 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "TREE")){
#line 5931 "bacon.bac"
Handle_Tree(statement__b2c__string_var);
#line 5933 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "COLLECT")){
#line 5934 "bacon.bac"
Handle_Collect(statement__b2c__string_var);
#line 5936 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "PARSE")){
#line 5937 "bacon.bac"
Handle_Parse(statement__b2c__string_var);
#line 5939 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_4250__b2c__string_var, "GETKEY")){
#line 5940 "bacon.bac"
__b2c__assign = (char*)"__b2c__getch();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5942 "bacon.bac"
} else {
#line 5944 "bacon.bac"
if( INSTR(element__b2c__string_var[(uint64_t)1], "(") ){
element__b2c__string_var[(uint64_t)1] = __b2c_Copy_String(element__b2c__string_var[(uint64_t)1], (char*) TOKEN__b2c__string_var(element__b2c__string_var[(uint64_t)1], 1, "("));
}
#line 5946 "bacon.bac"
if( ISTOKEN(g_IMPORTED__b2c__string_var, element__b2c__string_var[(uint64_t)1]) ){
#line 5947 "bacon.bac"
if( REGEX(statement__b2c__string_var, "\\(.*\\)") ){
#line 5948 "bacon.bac"
__b2c__assign = (char*)statement__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5949 "bacon.bac"
} else {
#line 5950 "bacon.bac"
__b2c__assign = (char*)statement__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 5951 "bacon.bac"
}
#line 5952 "bacon.bac"
} else {
#line 5953 "bacon.bac"
Handle_Let(statement__b2c__string_var);
#line 5954 "bacon.bac"
}
#line 5955 "bacon.bac"
}
#line 5956 "bacon.bac"
}
#line 5957 "bacon.bac"
}
#line 5959 "bacon.bac"
 __b2c__free_str_array_members(&element__b2c__string_var, 1, element__b2c__string_var__b2c_array); __b2c__STRFREE(__b2c__forin_str__b2c__string_var_string); __b2c__forin_str__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_step); __b2c__forin_str__b2c__string_var_step = NULL; __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array); __b2c__STRFREE(__b2c__forin_sym__b2c__string_var_string); __b2c__forin_sym__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_sym__b2c__string_var_step); __b2c__forin_sym__b2c__string_var_step = NULL; __b2c__free_str_array_members(&symbol__b2c__string_var, 1, symbol__b2c__string_var__b2c_array); __b2c__STRFREE(__b2c__forin_exp__b2c__string_var_string); __b2c__forin_exp__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_exp__b2c__string_var_step); __b2c__forin_exp__b2c__string_var_step = NULL;
__b2c__STRFREE(statement__b2c__string_var);
__b2c__STRFREE(inc__b2c__string_var);
__b2c__STRFREE(copy_curfile__b2c__string_var);
__b2c__STRFREE(total__b2c__string_var);
__b2c__STRFREE(txt__b2c__string_var);
__b2c__STRFREE(sym__b2c__string_var);
__b2c__STRFREE(exp__b2c__string_var);
__b2c__STRFREE(then__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(newfeed__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(rel__b2c__string_var);
__b2c__STRFREE(uniq__b2c__string_var);
__b2c__STRFREE(element__b2c__string_var);
__b2c__STRFREE(__b2c__select_4250__b2c__string_var);
__b2c__STRFREE(__b2c__select_4459__b2c__string_var);
__b2c__STRFREE(__b2c__select_4580__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__STRFREE(__b2c__select_5433__b2c__string_var);
__b2c__STRFREE(symbol__b2c__string_var);
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
