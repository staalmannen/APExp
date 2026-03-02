/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval 0
char* __Mini_Parser__b2c__string_var(int __b2c__arg_tot, ...) {
 long amount; long __b2c__var_exp__b2c__string_var = 1; va_list __b2c__ap; char **exp__b2c__string_var = NULL; exp__b2c__string_var = (char **)calloc(__b2c__arg_tot+1, sizeof(char*)); amount = __b2c__arg_tot; va_start(__b2c__ap, __b2c__arg_tot); while (__b2c__arg_tot) { exp__b2c__string_var[__b2c__var_exp__b2c__string_var] = __b2c_Copy_String(exp__b2c__string_var[__b2c__var_exp__b2c__string_var], va_arg(__b2c__ap, char*)); __b2c__var_exp__b2c__string_var++; __b2c__arg_tot--; } va_end(__b2c__ap); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 284 "bacon.bac"
unsigned long in_string = 0;
unsigned long escaped = 0;
unsigned long x = 0;
#line 285 "bacon.bac"
long in_func = 0;
#line 287 "bacon.bac"
for(x=1; x <= LEN(exp__b2c__string_var[(uint64_t)1]); x+=1){
#line 288 "bacon.bac"
if( amount == 2 ){
#line 289 "bacon.bac"
if( __b2c__STRCMP(MID__b2c__string_var(exp__b2c__string_var[(uint64_t)1], x, LEN(exp__b2c__string_var[(uint64_t)2])) ,  exp__b2c__string_var[(uint64_t)2]) == 0 ){
#line 290 "bacon.bac"
if( ISFALSE(in_string)  AND  ISFALSE(in_func) ){
break;
}
#line 291 "bacon.bac"
}
#line 292 "bacon.bac"
}
#line 293 "bacon.bac"
__b2c__select_293 = (double)ASC(MID__b2c__string_var(exp__b2c__string_var[(uint64_t)1], x, 1));
#line 294 "bacon.bac"
#line 295 "bacon.bac"
 if ( (__b2c__select_293) == (44) || (__b2c__select_293) == (59)){
#line 296 "bacon.bac"
if( ISFALSE(in_string)  AND  ISFALSE(in_func) ){
break;
}
#line 297 "bacon.bac"
} else  if ( (__b2c__select_293) == (92)){
#line 298 "bacon.bac"
if( escaped ){
#line 299 "bacon.bac"
escaped=(
unsigned long)( FALSE);
#line 300 "bacon.bac"
} else {
#line 301 "bacon.bac"
escaped=(
unsigned long)( TRUE);
#line 302 "bacon.bac"
}
#line 303 "bacon.bac"
} else  if ( (__b2c__select_293) == (34)){
#line 304 "bacon.bac"
if( ISFALSE(escaped) ){
in_string=(
unsigned long)( NOT(in_string));
}
#line 305 "bacon.bac"
escaped=(
unsigned long)( FALSE);
#line 306 "bacon.bac"
} else  if ( (__b2c__select_293) == (40) || (__b2c__select_293) == ( 123)){
#line 307 "bacon.bac"
if( ISFALSE(in_string) ){
in_func = in_func + (1);
}
#line 308 "bacon.bac"
escaped=(
unsigned long)( FALSE);
#line 309 "bacon.bac"
} else  if ( (__b2c__select_293) == (41) || (__b2c__select_293) == ( 125)){
#line 310 "bacon.bac"
if( ISFALSE(in_string) ){
in_func = in_func - (1);
}
#line 311 "bacon.bac"
escaped=(
unsigned long)( FALSE);
#line 312 "bacon.bac"
} else {
#line 313 "bacon.bac"
escaped=(
unsigned long)( FALSE);
#line 314 "bacon.bac"
}
#line 315 "bacon.bac"
if( (in_func )< 0 ){
break;
}
#line 316 "bacon.bac"
}
#line 318 "bacon.bac"
__b2c__assign = __b2c__return(LEFT__b2c__string_var(exp__b2c__string_var[(uint64_t)1], x-1));
 __b2c__free_str_array_members(&exp__b2c__string_var, 1, amount); free(exp__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(__b2c__assign);
#line 320 "bacon.bac"
__b2c__catch_set = __b2c__catch_set_backup;
return (NULL);}
