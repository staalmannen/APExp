/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Lookup( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 3224 "bacon.bac"
char *source__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *sort__b2c__string_var = NULL;
char *down__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
long total = 0;
long use_sort = 0;
long use_static = 0;
#line 3227 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 3228 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in LOOKUP statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3229 "bacon.bac"
exit(1);
#line 3230 "bacon.bac"
}
#line 3233 "bacon.bac"
if( MATCH(COLLAPSE__b2c__string_var(arg__b2c__string_var), "* SORT *") ){
#line 3234 "bacon.bac"
use_sort=(
long)( 1);
#line 3235 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SORT")));
#line 3236 "bacon.bac"
}
#line 3237 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "DOWN") ){
#line 3238 "bacon.bac"
down__b2c__string_var = __b2c_Copy_String(down__b2c__string_var, (char*) "_down");
#line 3239 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "DOWN")));
#line 3240 "bacon.bac"
}
#line 3241 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "STATIC") ){
#line 3242 "bacon.bac"
use_static=(
long)( 1);
#line 3243 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "STATIC")));
#line 3244 "bacon.bac"
}
#line 3245 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "LOOKUP * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3246 "bacon.bac"
source__b2c__string_var = __b2c_Copy_String(source__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3247 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3248 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 3251 "bacon.bac"
if( Check_String_Type(to__b2c__string_var) == 0 ){
#line 3252 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " in LOOKUP statement must be string at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3253 "bacon.bac"
exit(1);
#line 3254 "bacon.bac"
}
#line 3257 "bacon.bac"
if( LEN(size__b2c__string_var) ){
Register_Numeric(size__b2c__string_var, "default");
}
#line 3260 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3261 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 3262 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3263 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char **" , to__b2c__string_var , " = { NULL }; long " , to__b2c__string_var , "__b2c_array = 0;") ;
#line 3264 "bacon.bac"
Save_Func_Var(to__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 3265 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 3266 "bacon.bac"
}
#line 3267 "bacon.bac"
} else {
#line 3268 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var))) ){
#line 3269 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3270 "bacon.bac"
__b2c__assign = (char*)"char **"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { NULL }; long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 3271 "bacon.bac"
Save_Main_Var(to__b2c__string_var, "char*");
#line 3272 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , "long");
#line 3273 "bacon.bac"
}
#line 3274 "bacon.bac"
}
#line 3277 "bacon.bac"
if( NOT(use_sort) ){
#line 3278 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_order(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3279 "bacon.bac"
} else {
#line 3280 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , source__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 3281 "bacon.bac"
if( REGEX(type__b2c__string_var, "char\\*|STRING") ){
#line 3282 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 0, __b2c__sortstr"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3283 "bacon.bac"
} else if( REGEX(type__b2c__string_var, "double|FLOATING") ){
#line 3284 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 1, __b2c__sortnrd_wrap"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3285 "bacon.bac"
} else if( REGEX(type__b2c__string_var, "float") ){
#line 3286 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 2, __b2c__sortnrf_wrap"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3287 "bacon.bac"
} else if( REGEX(type__b2c__string_var, "long|NUMBER") ){
#line 3288 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 3, __b2c__sortnrl_wrap"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3289 "bacon.bac"
} else if( REGEX(type__b2c__string_var, "int") ){
#line 3290 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 4, __b2c__sortnri_wrap"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3291 "bacon.bac"
} else if( REGEX(type__b2c__string_var, "short") ){
#line 3292 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 5, __b2c__sortnrs_wrap"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3293 "bacon.bac"
} else if( REGEX(type__b2c__string_var, "char") ){
#line 3294 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__lookup_by_sort(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", 6, __b2c__sortnrc_wrap"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) down__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3295 "bacon.bac"
} else {
#line 3296 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: unsupported array type in LOOKUP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3297 "bacon.bac"
exit(1);
#line 3298 "bacon.bac"
}
#line 3299 "bacon.bac"
}
#line 3300 "bacon.bac"
if( LEN(size__b2c__string_var) ){
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 3303 "bacon.bac"
if( NOT(use_static) ){
#line 3304 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_STRINGARRAYS__b2c__string_var, CONCAT__b2c__string_var( to__b2c__string_var , "__b2c_array") )) ){
#line 3305 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , to__b2c__string_var , "__b2c_array);") ;
#line 3306 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , to__b2c__string_var) ;
#line 3307 "bacon.bac"
} else if( ISFALSE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_GLOBALARRAYS__b2c__string_var, CONCAT__b2c__string_var( to__b2c__string_var , "__b2c_array") )) ){
#line 3308 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , to__b2c__string_var , "__b2c_array); free(" , to__b2c__string_var , ");") ;
#line 3309 "bacon.bac"
}
#line 3310 "bacon.bac"
}
#line 3312 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(sort__b2c__string_var);
__b2c__STRFREE(down__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
