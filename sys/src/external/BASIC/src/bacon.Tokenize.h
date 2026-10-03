/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Tokenize( char *__b2c_current__b2c__string_var) {
 char*current__b2c__string_var = NULL; current__b2c__string_var = __b2c_Copy_String(NULL, __b2c_current__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_str__b2c__string_var_ptr = 0; char* __b2c__forin_str__b2c__string_var_string = NULL; char* __b2c__forin_str__b2c__string_var_string_org = NULL; char* __b2c__forin_str__b2c__string_var_step = NULL;
#line 6255 "bacon.bac"
long i = 0;
long is_string = 0;
long is_escaped = 0;
long in_func = 0;
long in_char = 0;
long j = 0;
long in_str = 0;
long in_spac = 0;
long bracket = 0;
long direct = 0;
long inescaped = 0;
long isquote = 0;
long sftot = 0;
#line 6256 "bacon.bac"
char *token__b2c__string_var = NULL;
char *item1__b2c__string_var = NULL;
char *item2__b2c__string_var = NULL;
char *part__b2c__string_var = NULL;
char *result__b2c__string_var = NULL;
char *txt__b2c__string_var = NULL;
char *sep__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
#line 6259 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(current__b2c__string_var, 5) ,  "CLASS") == 0  OR  g_COMMENT == TRUE ){
#line 6260 "bacon.bac"
Parse_Line(CHOP__b2c__string_var(current__b2c__string_var));
#line 6261 "bacon.bac"

__b2c__STRFREE(current__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(item1__b2c__string_var);
__b2c__STRFREE(item2__b2c__string_var);
__b2c__STRFREE(part__b2c__string_var);
__b2c__STRFREE(result__b2c__string_var);
__b2c__STRFREE(txt__b2c__string_var);
__b2c__STRFREE(sep__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return __b2c__exitval;
#line 6262 "bacon.bac"
}
#line 6265 "bacon.bac"
if( g_TRACE == 1 ){
#line 6266 "bacon.bac"
if( NOT(REGEX(CHOP__b2c__string_var(current__b2c__string_var), "^FUNCTION|^SUB|^ELIF|^ELSE"))  AND  NOT(LEN(g_TRACE_PREFIX__b2c__string_var)) ){
#line 6267 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__getch() == 27) {fprintf(stderr, \"TRACE OFF - exiting trace mode.\\n\"); exit(EXIT_SUCCESS);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6268 "bacon.bac"
txt__b2c__string_var = __b2c_Copy_String(txt__b2c__string_var, (char*) REPLACE__b2c__string_var(current__b2c__string_var, CONCAT__b2c__string_var( CHR__b2c__string_var(34) , CHR__b2c__string_var(92) , CHR__b2c__string_var(37)) , CONCAT__b2c__string_var( CHR__b2c__string_var(39) , CHR__b2c__string_var(47) , CHR__b2c__string_var(35)) , 2));
#line 6269 "bacon.bac"
__b2c__assign = (char*)"fprintf(stderr, \"File '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "' line %d: "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) txt__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\\n\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 6270 "bacon.bac"
if( LEN(g_MONITOR__b2c__string_var) ){
__b2c__assign = (char*)CHOP__b2c__string_var(g_MONITOR__b2c__string_var, "&&"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 6271 "bacon.bac"
}
#line 6272 "bacon.bac"
g_TRACE_PREFIX__b2c__string_var = __b2c_Copy_String(g_TRACE_PREFIX__b2c__string_var, (char*) "");
#line 6273 "bacon.bac"
}
#line 6276 "bacon.bac"
current__b2c__string_var = __b2c_Copy_String(current__b2c__string_var, (char*) Pre_Tokenize_Functions__b2c__string_var(current__b2c__string_var));
#line 6278 "bacon.bac"
while( TRUE ){
#line 6280 "bacon.bac"
in_func=(
long)( 0);
#line 6281 "bacon.bac"
is_string=(
long)( FALSE);
#line 6282 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6283 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6286 "bacon.bac"
for(i=1; i <= LEN(current__b2c__string_var); i+=1){
#line 6287 "bacon.bac"
in_char=(
long)( ASC(MID__b2c__string_var(current__b2c__string_var, i, 1)));
#line 6288 "bacon.bac"
__b2c__select_6288 = (double)in_char;
#line 6290 "bacon.bac"
 if ( (__b2c__select_6288) == (58)){
#line 6291 "bacon.bac"
if( NOT(is_string)  AND  ASC(MID__b2c__string_var(current__b2c__string_var, i+1, 1)) == 58 ){
#line 6292 "bacon.bac"
i = i + (1);
#line 6293 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "::") ;
#line 6294 "bacon.bac"
} else if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H)  AND  NOT(in_func) ){
#line 6295 "bacon.bac"
Tokenize(CHOP__b2c__string_var(token__b2c__string_var));
#line 6296 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) "");
#line 6297 "bacon.bac"
} else {
#line 6298 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , ":") ;
#line 6299 "bacon.bac"
}
#line 6301 "bacon.bac"
} else  if ( (__b2c__select_6288) == (9)){
#line 6302 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , IIF__b2c__string_var(NOT(is_string), CHR__b2c__string_var(32), CHR__b2c__string_var(9))) ;
#line 6304 "bacon.bac"
} else  if ( (__b2c__select_6288) == (36)){
#line 6305 "bacon.bac"
if( NOT(is_string)  OR  MATCH(current__b2c__string_var, "IMPORT * FROM * TYPE *") ){
#line 6306 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , g_STRINGSIGN__b2c__string_var) ;
#line 6307 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6308 "bacon.bac"
} else {
#line 6309 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "$") ;
#line 6310 "bacon.bac"
}
#line 6312 "bacon.bac"
} else  if ( (__b2c__select_6288) == (40)){
#line 6313 "bacon.bac"
if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
in_func = in_func + (1);
}
#line 6314 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(40)) ;
#line 6316 "bacon.bac"
} else  if ( (__b2c__select_6288) == (41)){
#line 6317 "bacon.bac"
if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
in_func = in_func - (1);
}
#line 6318 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(41)) ;
#line 6320 "bacon.bac"
} else  if ( (__b2c__select_6288) == (63)){
#line 6321 "bacon.bac"
if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H)  AND  NOT(in_func) ){
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "PRINT ");
}
#line 6322 "bacon.bac"
else {
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(63));
}
#line 6324 "bacon.bac"
} else  if ( (__b2c__select_6288) == (91)){
#line 6325 "bacon.bac"
if( NOT(is_string)  AND  __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 2) ,  "[]") != 0  AND  __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, i, 11) ,  "[(uint64_t)") != 0 ){
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "[(uint64_t)");
}
#line 6326 "bacon.bac"
else {
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(91));
}
#line 6328 "bacon.bac"
} else  if ( (__b2c__select_6288) == (37)){
#line 6329 "bacon.bac"
if( NOT(is_string)  AND  REGEX(RIGHT__b2c__string_var(token__b2c__string_var, 1), "[a-zA-Z0-9_]+") ){
#line 6330 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , g_LONGSIGN__b2c__string_var) ;
#line 6331 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6332 "bacon.bac"
} else {
#line 6333 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "%") ;
#line 6334 "bacon.bac"
}
#line 6336 "bacon.bac"
} else  if ( (__b2c__select_6288) == (35)){
#line 6337 "bacon.bac"
if( NOT(is_string)  AND  REGEX(RIGHT__b2c__string_var(token__b2c__string_var, 1), "[a-zA-Z0-9_]+")  AND  (i )> 1 ){
#line 6338 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , g_FLOATSIGN__b2c__string_var) ;
#line 6339 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6340 "bacon.bac"
} else {
#line 6341 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , "#") ;
#line 6342 "bacon.bac"
}
#line 6344 "bacon.bac"
} else  if ( (__b2c__select_6288) == (92)){
#line 6345 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(92)) ;
#line 6346 "bacon.bac"
is_escaped=(
long)( NOT(is_escaped));
#line 6348 "bacon.bac"
} else  if ( (__b2c__select_6288) == (34)){
#line 6349 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(34)) ;
#line 6350 "bacon.bac"
if( NOT(is_escaped) ){
#line 6351 "bacon.bac"
if( NOT(is_string) ){
#line 6352 "bacon.bac"
is_string=(
long)( TRUE);
#line 6353 "bacon.bac"
} else {
#line 6354 "bacon.bac"
is_string=(
long)( FALSE);
#line 6355 "bacon.bac"
}
#line 6356 "bacon.bac"
}
#line 6357 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6359 "bacon.bac"
} else  if ( (__b2c__select_6288) == (38) || (__b2c__select_6288) == ( 43)){
#line 6360 "bacon.bac"
if( NOT(is_string)  AND  ISFALSE(g_USE_C)  AND  ISFALSE(g_USE_H) ){
#line 6362 "bacon.bac"
item1__b2c__string_var = __b2c_Copy_String(item1__b2c__string_var, (char*) "");
bracket=(
long)( 0);
in_spac=(
long)( 0);
in_str=(
long)( 0);
direct=(
long)( 0);
isquote=(
long)( 0);
#line 6363 "bacon.bac"
for(j=1; j <= LEN(token__b2c__string_var); j+=1){
#line 6364 "bacon.bac"
__b2c__select_6364 = (double)ASC(MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j+1, 1));
#line 6366 "bacon.bac"
 if ( (__b2c__select_6364) == (41) || (__b2c__select_6364) == ( 93)){
#line 6367 "bacon.bac"
isquote=(
long)( 0);
#line 6368 "bacon.bac"
direct = direct + (1);
#line 6369 "bacon.bac"
if( NOT(in_str) ){
#line 6370 "bacon.bac"
bracket = bracket + (1);
#line 6371 "bacon.bac"
}
#line 6373 "bacon.bac"
} else  if ( (__b2c__select_6364) == (40) || (__b2c__select_6364) == ( 91)){
#line 6374 "bacon.bac"
isquote=(
long)( 0);
#line 6375 "bacon.bac"
direct = direct + (1);
#line 6376 "bacon.bac"
if( NOT(in_str) ){
#line 6377 "bacon.bac"
bracket = bracket - (1);
#line 6378 "bacon.bac"
if( (bracket )< 0 ){
#line 6379 "bacon.bac"
break;
#line 6380 "bacon.bac"
}
#line 6381 "bacon.bac"
}
#line 6383 "bacon.bac"
} else  if ( (__b2c__select_6364) == (61)){
#line 6384 "bacon.bac"
isquote=(
long)( 0);
#line 6385 "bacon.bac"
if( NOT(in_str) ){
break;
}
#line 6387 "bacon.bac"
} else  if ( (__b2c__select_6364) == (62)){
#line 6388 "bacon.bac"
if( ASC(MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j, 1)) != 45 ){
#line 6389 "bacon.bac"
isquote=(
long)( 0);
#line 6390 "bacon.bac"
if( NOT(in_str) ){
break;
}
#line 6391 "bacon.bac"
}
#line 6393 "bacon.bac"
} else  if ( (__b2c__select_6364) == (44) || (__b2c__select_6364) == ( 45) || (__b2c__select_6364) == ( 42) || (__b2c__select_6364) == ( 47) || (__b2c__select_6364) == ( 37) || (__b2c__select_6364) == ( 60)){
#line 6394 "bacon.bac"
isquote=(
long)( 0);
#line 6395 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
break;
}
#line 6397 "bacon.bac"
} else  if ( (__b2c__select_6364) == (92)){
#line 6398 "bacon.bac"
if( isquote ){
#line 6399 "bacon.bac"
in_str=(
long)( 1);
#line 6400 "bacon.bac"
}
#line 6401 "bacon.bac"
isquote=(
long)( 0);
#line 6403 "bacon.bac"
} else  if ( (__b2c__select_6364) == (34)){
#line 6404 "bacon.bac"
isquote=(
long)( 1);
#line 6405 "bacon.bac"
direct = direct + (1);
#line 6406 "bacon.bac"
in_str=(
long)( NOT(in_str));
#line 6407 "bacon.bac"
} else  if ( (__b2c__select_6364) == (32)){
#line 6408 "bacon.bac"
isquote=(
long)( 0);
#line 6409 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
#line 6410 "bacon.bac"
if( (direct )> 0 ){
#line 6411 "bacon.bac"
in_spac = in_spac + (1);
#line 6412 "bacon.bac"
}
#line 6413 "bacon.bac"
}
#line 6415 "bacon.bac"
} else  if ( (__b2c__select_6364) == (58)){
#line 6416 "bacon.bac"
if( NOT(bracket) ){
#line 6417 "bacon.bac"
isquote=(
long)( 0);
#line 6418 "bacon.bac"
if( NOT(in_str) ){
break;
}
#line 6419 "bacon.bac"
}
#line 6420 "bacon.bac"
}
#line 6421 "bacon.bac"
if( (__b2c__STRCMP(MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j+1, 1) , __b2c__min_str( "a" , "z")) >= 0 && __b2c__STRCMP(MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j+1, 1) , __b2c__max_str( "a" , "z")) <= 0 ? 1 : 0)  OR  (__b2c__STRCMP(MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j+1, 1) , __b2c__min_str( "A" , "Z")) >= 0 && __b2c__STRCMP(MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j+1, 1) , __b2c__max_str( "A" , "Z")) <= 0 ? 1 : 0) ){
#line 6422 "bacon.bac"
isquote=(
long)( 0);
#line 6423 "bacon.bac"
direct = direct + (1);
#line 6424 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
#line 6425 "bacon.bac"
if( (in_spac )> 0 ){
#line 6426 "bacon.bac"
break;
#line 6427 "bacon.bac"
}
#line 6428 "bacon.bac"
}
#line 6429 "bacon.bac"
}
#line 6430 "bacon.bac"
item1__b2c__string_var = F_CONCAT__b2c__string_var(item1__b2c__string_var, MID__b2c__string_var(token__b2c__string_var, LEN(token__b2c__string_var)-j+1, 1) , item1__b2c__string_var) ;
#line 6431 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6433 "bacon.bac"
if( Check_String_Type(item1__b2c__string_var) ){
#line 6434 "bacon.bac"
part__b2c__string_var = F_MID__b2c__string_var(part__b2c__string_var,token__b2c__string_var, 1, LEN(token__b2c__string_var)-j+1);
#line 6436 "bacon.bac"
item2__b2c__string_var = __b2c_Copy_String(item2__b2c__string_var, (char*) "");
bracket=(
long)( 0);
in_str=(
long)( 0);
inescaped=(
long)( 0);
in_spac=(
long)( 0);
direct=(
long)( 0);
#line 6437 "bacon.bac"
for(j=i+1; j <= LEN(current__b2c__string_var); j+=1){
#line 6438 "bacon.bac"
__b2c__select_6438 = (double)ASC(MID__b2c__string_var(current__b2c__string_var, j, 1));
#line 6440 "bacon.bac"
 if ( (__b2c__select_6438) == (40)){
#line 6441 "bacon.bac"
direct = direct + (1);
#line 6442 "bacon.bac"
if( NOT(in_str) ){
bracket = bracket + (1);
}
#line 6444 "bacon.bac"
} else  if ( (__b2c__select_6438) == (41)){
#line 6445 "bacon.bac"
direct = direct + (1);
#line 6446 "bacon.bac"
if( NOT(in_str) ){
#line 6447 "bacon.bac"
bracket = bracket - (1);
#line 6448 "bacon.bac"
if( (bracket )< 0 ){
#line 6449 "bacon.bac"
break;
#line 6450 "bacon.bac"
}
#line 6451 "bacon.bac"
}
#line 6453 "bacon.bac"
} else  if ( (__b2c__select_6438) == (44) || (__b2c__select_6438) == ( 60) || (__b2c__select_6438) == ( 61) || (__b2c__select_6438) == ( 33) || (__b2c__select_6438) == ( 45) || (__b2c__select_6438) == ( 42) || (__b2c__select_6438) == ( 47) || (__b2c__select_6438) == ( 37)){
#line 6454 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
break;
}
#line 6456 "bacon.bac"
} else  if ( (__b2c__select_6438) == (38) || (__b2c__select_6438) == ( 43)){
#line 6457 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
#line 6458 "bacon.bac"
in_spac=(
long)( 0);
direct=(
long)( 0);
#line 6459 "bacon.bac"
}
#line 6461 "bacon.bac"
} else  if ( (__b2c__select_6438) == (92)){
#line 6462 "bacon.bac"
inescaped=(
long)( NOT(inescaped));
#line 6464 "bacon.bac"
} else  if ( (__b2c__select_6438) == (34)){
#line 6465 "bacon.bac"
direct = direct + (1);
#line 6466 "bacon.bac"
if( NOT(inescaped) ){
in_str=(
long)( NOT(in_str));
}
#line 6467 "bacon.bac"
inescaped=(
long)( 0);
#line 6468 "bacon.bac"
} else  if ( (__b2c__select_6438) == (32)){
#line 6469 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
#line 6470 "bacon.bac"
if( (direct )> 0 ){
#line 6471 "bacon.bac"
in_spac = in_spac + (1);
#line 6472 "bacon.bac"
}
#line 6473 "bacon.bac"
}
#line 6475 "bacon.bac"
} else  if ( (__b2c__select_6438) == (58) || (__b2c__select_6438) == ( 59)){
#line 6476 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
break;
}
#line 6477 "bacon.bac"
}
#line 6478 "bacon.bac"
if( (__b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) , __b2c__min_str( "a" , "z")) >= 0 && __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) , __b2c__max_str( "a" , "z")) <= 0 ? 1 : 0)  OR  (__b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) , __b2c__min_str( "A" , "Z")) >= 0 && __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) , __b2c__max_str( "A" , "Z")) <= 0 ? 1 : 0) ){
#line 6479 "bacon.bac"
direct = direct + (1);
#line 6480 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
#line 6481 "bacon.bac"
if( (in_spac )> 0 ){
#line 6482 "bacon.bac"
break;
#line 6483 "bacon.bac"
}
#line 6484 "bacon.bac"
}
#line 6485 "bacon.bac"
}
#line 6486 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) ,  "$") == 0 ){
#line 6487 "bacon.bac"
if( NOT(in_str)  OR  MATCH(current__b2c__string_var, "IMPORT * FROM * TYPE *") ){
#line 6488 "bacon.bac"
item2__b2c__string_var = F_CONCAT__b2c__string_var(item2__b2c__string_var, item2__b2c__string_var , g_STRINGSIGN__b2c__string_var) ;
#line 6489 "bacon.bac"
} else {
#line 6490 "bacon.bac"
item2__b2c__string_var = F_CONCAT__b2c__string_var(item2__b2c__string_var, item2__b2c__string_var , "$") ;
#line 6491 "bacon.bac"
}
#line 6492 "bacon.bac"
} else if( __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) ,  "&") == 0  OR  __b2c__STRCMP(MID__b2c__string_var(current__b2c__string_var, j, 1) ,  "+") == 0 ){
#line 6493 "bacon.bac"
if( NOT(in_str)  AND  NOT(bracket) ){
#line 6494 "bacon.bac"
item2__b2c__string_var = F_CONCAT__b2c__string_var(item2__b2c__string_var, item2__b2c__string_var , ",") ;
#line 6495 "bacon.bac"
} else {
#line 6496 "bacon.bac"
item2__b2c__string_var = F_CONCAT__b2c__string_var(item2__b2c__string_var, item2__b2c__string_var , MID__b2c__string_var(current__b2c__string_var, j, 1)) ;
#line 6497 "bacon.bac"
}
#line 6498 "bacon.bac"
} else {
#line 6499 "bacon.bac"
item2__b2c__string_var = F_CONCAT__b2c__string_var(item2__b2c__string_var, item2__b2c__string_var , MID__b2c__string_var(current__b2c__string_var, j, 1)) ;
#line 6500 "bacon.bac"
}
#line 6501 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6503 "bacon.bac"
if( Check_String_Type(CHOP__b2c__string_var(Mini_Parser__b2c__string_var(item2__b2c__string_var))) ){
#line 6504 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, part__b2c__string_var , " CONCAT" , g_STRINGSIGN__b2c__string_var , "(" , item1__b2c__string_var , "," , item2__b2c__string_var , ") ") ;
#line 6506 "bacon.bac"
i=(
long)( j-1);
#line 6507 "bacon.bac"
} else {
#line 6508 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(in_char)) ;
#line 6509 "bacon.bac"
}
#line 6510 "bacon.bac"
} else {
#line 6511 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(in_char)) ;
#line 6512 "bacon.bac"
}
#line 6513 "bacon.bac"
} else {
#line 6514 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , CHR__b2c__string_var(in_char)) ;
#line 6515 "bacon.bac"
}
#line 6516 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6517 "bacon.bac"
} else {
#line 6518 "bacon.bac"
token__b2c__string_var = F_CONCAT__b2c__string_var(token__b2c__string_var, token__b2c__string_var , MID__b2c__string_var(current__b2c__string_var, i, 1)) ;
#line 6519 "bacon.bac"
is_escaped=(
long)( FALSE);
#line 6520 "bacon.bac"
}
#line 6521 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 6522 "bacon.bac"
if( __b2c__STRCMP(token__b2c__string_var ,  result__b2c__string_var) == 0 ){
break;
}
#line 6523 "bacon.bac"
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) token__b2c__string_var);
#line 6525 "bacon.bac"
if( NOT(REGEX(token__b2c__string_var, "[&+%#\\$]")) ){
break;
}
#line 6526 "bacon.bac"
current__b2c__string_var = __b2c_Copy_String(current__b2c__string_var, (char*) token__b2c__string_var);
#line 6527 "bacon.bac"
}
#line 6530 "bacon.bac"
#undef __b2c__obtain_type_g_MACRO_STRINGS__b2c__string_var
#define __b2c__obtain_type_g_MACRO_STRINGS__b2c__string_var 0
__b2c__forin_str__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_string, OBTAIN__b2c__string_var(g_MACRO_STRINGS__b2c__string_var)); __b2c__forin_str__b2c__string_var_string_org = __b2c__forin_str__b2c__string_var_string;
__b2c__forin_str__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_str__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_str__b2c__string_var_string, __b2c__forin_str__b2c__string_var_step);
for(; __b2c__forin_str__b2c__string_var_ptr > 0; __b2c__forin_str__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_str__b2c__string_var_string_org, __b2c__forin_str__b2c__string_var_step, &str__b2c__string_var);
#line 6531 "bacon.bac"
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) REPLACE__b2c__string_var(result__b2c__string_var, str__b2c__string_var, g_MACRO_STRINGS__b2c__string_var(str__b2c__string_var)));
#line 6532 "bacon.bac"
}
#line 6534 "bacon.bac"
sftot=(
long)( TALLY(result__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "(") ));
#line 6535 "bacon.bac"
if( (sftot )> g_STRING_FUNC ){
g_STRING_FUNC=(long)( sftot);
}
#line 6538 "bacon.bac"
Parse_Line(CHOP__b2c__string_var(token__b2c__string_var));
#line 6540 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_str__b2c__string_var_string); __b2c__forin_str__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_step); __b2c__forin_str__b2c__string_var_step = NULL;
__b2c__STRFREE(current__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(item1__b2c__string_var);
__b2c__STRFREE(item2__b2c__string_var);
__b2c__STRFREE(part__b2c__string_var);
__b2c__STRFREE(result__b2c__string_var);
__b2c__STRFREE(txt__b2c__string_var);
__b2c__STRFREE(sep__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
