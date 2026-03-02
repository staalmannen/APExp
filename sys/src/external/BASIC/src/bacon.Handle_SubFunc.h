/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_SubFunc( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; char **element__b2c__string_var = NULL; long element__b2c__string_var__b2c_array = 0;
#line 2410 "bacon.bac"
long x = 0;
long dim = 0;
long total = 0;
char *dim__b2c__string_var = NULL;
char *arr__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *var__b2c__string_var = NULL;
char *no_arg__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
#line 2413 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 2414 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SUB/FUNCTION at at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2415 "bacon.bac"
exit(1);
#line 2416 "bacon.bac"
}
#line 2417 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 2420 "bacon.bac"
if( (LEN(g_FUNCNAME__b2c__string_var) )> 0 ){
#line 2421 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: cannot define a SUB/FUNCTION within a SUB/FUNCTION at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2422 "bacon.bac"
exit(1);
#line 2423 "bacon.bac"
}
#line 2426 "bacon.bac"
if( MATCH(COLLAPSE__b2c__string_var(arg__b2c__string_var), "* ( * ) *") ){
#line 2427 "bacon.bac"
no_arg__b2c__string_var = __b2c_Copy_String(no_arg__b2c__string_var, (char*) OUTBETWEEN__b2c__string_var(arg__b2c__string_var, "(", ")", 1));
#line 2428 "bacon.bac"
} else {
#line 2429 "bacon.bac"
no_arg__b2c__string_var = __b2c_Copy_String(no_arg__b2c__string_var, (char*) arg__b2c__string_var);
#line 2430 "bacon.bac"
}
#line 2431 "bacon.bac"
if( ISTOKEN(no_arg__b2c__string_var, "TYPE") ){
#line 2432 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(no_arg__b2c__string_var), "* TYPE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 2433 "bacon.bac"
g_FUNCTYPE__b2c__string_var = F_CHOP__b2c__string_var(g_FUNCTYPE__b2c__string_var,match__b2c__string_var[(uint64_t)2]);
#line 2434 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) FIRST__b2c__string_var(arg__b2c__string_var, 1, "TYPE"));
#line 2435 "bacon.bac"
}
#line 2438 "bacon.bac"
if( INSTR(arg__b2c__string_var, "(") ){
#line 2439 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, CHOP__b2c__string_var(TOKEN__b2c__string_var(arg__b2c__string_var, 1, "(")) , "(") ;
#line 2440 "bacon.bac"
g_PROTOTYPE__b2c__string_var = __b2c_Copy_String(g_PROTOTYPE__b2c__string_var, (char*) g_ORIGFUNCNAME__b2c__string_var);
#line 2441 "bacon.bac"
g_FUNCNAME__b2c__string_var = F_CHOP__b2c__string_var(g_FUNCNAME__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 1, "("));
#line 2442 "bacon.bac"
} else {
#line 2443 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, CHOP__b2c__string_var(arg__b2c__string_var) , "(") ;
#line 2444 "bacon.bac"
g_PROTOTYPE__b2c__string_var = __b2c_Copy_String(g_PROTOTYPE__b2c__string_var, (char*) g_ORIGFUNCNAME__b2c__string_var);
#line 2445 "bacon.bac"
g_FUNCNAME__b2c__string_var = F_CHOP__b2c__string_var(g_FUNCNAME__b2c__string_var,arg__b2c__string_var);
#line 2446 "bacon.bac"
}
#line 2449 "bacon.bac"
if( INSTR(g_FUNCNAME__b2c__string_var, "::") ){
g_FUNCNAME__b2c__string_var = __b2c_Copy_String(g_FUNCNAME__b2c__string_var, (char*) REPLACE__b2c__string_var(g_FUNCNAME__b2c__string_var, "::", "__"));
}
#line 2452 "bacon.bac"
if( ISTOKEN(g_IMPORTED__b2c__string_var, g_FUNCNAME__b2c__string_var) ){
#line 2453 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: duplicate SUB or FUNCTION name at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2454 "bacon.bac"
exit(1);
#line 2455 "bacon.bac"
}
#line 2458 "bacon.bac"
if( INSTR(arg__b2c__string_var, "(") ){
__b2c__split_by(&element__b2c__string_var, 1, &element__b2c__string_var__b2c_array, CHOP__b2c__string_var(MID__b2c__string_var(arg__b2c__string_var, INSTR(arg__b2c__string_var, "(")), "() "), ",");
dim = element__b2c__string_var__b2c_array;
}
#line 2461 "bacon.bac"
if( dim == 0 ){
#line 2462 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , " void)") ;
#line 2463 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , " void)") ;
#line 2464 "bacon.bac"
}
#line 2466 "bacon.bac"
for(x=1; x <= dim; x+=1){
#line 2467 "bacon.bac"
element__b2c__string_var[(uint64_t)x] = F_CHOP__b2c__string_var(element__b2c__string_var[(uint64_t)x],element__b2c__string_var[(uint64_t)x]);
#line 2469 "bacon.bac"
if( __b2c__STRCMP(TOKEN__b2c__string_var(element__b2c__string_var[(uint64_t)x], 1) ,  "VAR") == 0 ){
#line 2470 "bacon.bac"
if( (dim )> 1 ){
#line 2471 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable argument list cannot be followed by other arguments at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2472 "bacon.bac"
exit(1);
#line 2473 "bacon.bac"
} else if( INSTR(g_PROTOTYPE__b2c__string_var, ",") ){
#line 2474 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable argument list cannot be preceded by other arguments at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2475 "bacon.bac"
exit(1);
#line 2476 "bacon.bac"
}
#line 2477 "bacon.bac"
if( NOT(ISTOKEN(element__b2c__string_var[(uint64_t)x], "SIZE")) ){
#line 2478 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable argument list lacks SIZE argument at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2479 "bacon.bac"
exit(1);
#line 2480 "bacon.bac"
}
#line 2481 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(element__b2c__string_var[(uint64_t)x]), CONCAT__b2c__string_var( "VAR * " , IIF__b2c__string_var(ISTOKEN(element__b2c__string_var[x], "TYPE"), "TYPE * ") , "SIZE *" ), __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 2482 "bacon.bac"
arr__b2c__string_var = __b2c_Copy_String(arr__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 2483 "bacon.bac"
if( total == 2 ){
#line 2484 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "long");
#line 2485 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 2486 "bacon.bac"
} else {
#line 2487 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 2488 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 2489 "bacon.bac"
}
#line 2491 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " long " , size__b2c__string_var , ";") ;
#line 2492 "bacon.bac"
Save_Func_Var(size__b2c__string_var, g_FUNCNAME__b2c__string_var, "long");
#line 2493 "bacon.bac"
if( Check_String_Type(arr__b2c__string_var)  OR  REGEX(type__b2c__string_var, "STRING|char\\*$") ){
#line 2494 "bacon.bac"
Save_Func_Var(arr__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 2495 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "long __b2c__var_" , arr__b2c__string_var , " = " , STR__b2c__string_var(g_OPTION_BASE) , "; va_list __b2c__ap; char **" , arr__b2c__string_var , " = NULL;" , arr__b2c__string_var , " = (char **)calloc(__b2c__arg_tot+" , STR__b2c__string_var(g_OPTION_BASE) , ", sizeof(char*));") ;
#line 2496 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , size__b2c__string_var , " = __b2c__arg_tot; va_start(__b2c__ap, __b2c__arg_tot); while(__b2c__arg_tot)") ;
#line 2497 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "{" , arr__b2c__string_var , "[__b2c__var_" , arr__b2c__string_var , "] = __b2c_Copy_String(" , arr__b2c__string_var , "[__b2c__var_" , arr__b2c__string_var , "], va_arg(__b2c__ap, char*)); __b2c__var_" , arr__b2c__string_var , "++; __b2c__arg_tot--; } va_end(__b2c__ap);") ;
#line 2498 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, "__" , g_PROTOTYPE__b2c__string_var , "int, ...") ;
#line 2499 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , "int __b2c__arg_tot, ...") ;
#line 2500 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , arr__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , size__b2c__string_var , "); free(" , arr__b2c__string_var , ");") ;
#line 2501 "bacon.bac"
__b2c__assign = (char*)"#define "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "(...) __"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), (char*)__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2502 "bacon.bac"
} else {
#line 2504 "bacon.bac"
if( INSTR(arr__b2c__string_var, g_FLOATSIGN__b2c__string_var)  OR  __b2c__STRCMP(type__b2c__string_var ,  "float") == 0 ){
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "double");
}
#line 2505 "bacon.bac"
Save_Func_Var(arr__b2c__string_var, g_FUNCNAME__b2c__string_var, CONCAT__b2c__string_var( type__b2c__string_var , "*") );
#line 2506 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "long __b2c__var_" , arr__b2c__string_var , " = " , STR__b2c__string_var(g_OPTION_BASE) , "; va_list __b2c__ap; " , type__b2c__string_var , "*" , arr__b2c__string_var , " = NULL;" , arr__b2c__string_var , " = (" , type__b2c__string_var , "*)calloc(__b2c__arg_tot+" , STR__b2c__string_var(g_OPTION_BASE) , ", sizeof(" , type__b2c__string_var , "));") ;
#line 2507 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , size__b2c__string_var , " = __b2c__arg_tot; va_start(__b2c__ap, __b2c__arg_tot); while(__b2c__arg_tot)") ;
#line 2508 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "{" , arr__b2c__string_var , "[__b2c__var_" , arr__b2c__string_var , "] = va_arg(__b2c__ap, " , type__b2c__string_var , "); __b2c__var_" , arr__b2c__string_var , "++; __b2c__arg_tot--; } va_end(__b2c__ap);") ;
#line 2509 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, "__" , g_PROTOTYPE__b2c__string_var , "int, ...") ;
#line 2510 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , "int __b2c__arg_tot, ...") ;
#line 2511 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " free(" , arr__b2c__string_var , ");") ;
#line 2512 "bacon.bac"
__b2c__assign = (char*)"#define "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "(...) __"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CONCAT__b2c__string_var( "(sizeof((const " , type__b2c__string_var , "[]) {__VA_ARGS__}) / sizeof(" , type__b2c__string_var , "), (" , type__b2c__string_var , ")__VA_ARGS__)" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2513 "bacon.bac"
}
#line 2515 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, "__" , g_ORIGFUNCNAME__b2c__string_var) ;
#line 2516 "bacon.bac"
} else if( INSTR(element__b2c__string_var[(uint64_t)x], "STRING ")  OR  INSTR(element__b2c__string_var[(uint64_t)x], "char* ")  OR  INSTR(element__b2c__string_var[(uint64_t)x], g_STRINGSIGN__b2c__string_var) ){
#line 2518 "bacon.bac"
if( NOT(HASDELIM(element__b2c__string_var[(uint64_t)x])) ){
element__b2c__string_var[(uint64_t)x] = F_CONCAT__b2c__string_var(element__b2c__string_var[(uint64_t)x], "char* " , element__b2c__string_var[(uint64_t)x]);
}
#line 2520 "bacon.bac"
if( REGEX(TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]), g_C_KEYWORDS__b2c__string_var) ){
#line 2521 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in SUB/FUNCTION statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' is a C keyword or function!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2522 "bacon.bac"
exit(1);
#line 2523 "bacon.bac"
} else if( NOT(LEN(Get_Var__b2c__string_var(TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]), g_FUNCNAME__b2c__string_var))) ){
#line 2524 "bacon.bac"
Save_Func_Var(TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]), g_FUNCNAME__b2c__string_var, FIRST__b2c__string_var(element__b2c__string_var[(uint64_t)x]));
#line 2525 "bacon.bac"
} else {
#line 2526 "bacon.bac"
if( g_SEMANTIC == 0 ){
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "WARNING: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in function header at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined previously!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 2527 "bacon.bac"
}
#line 2528 "bacon.bac"
arr__b2c__string_var = F_MID__b2c__string_var(arr__b2c__string_var,element__b2c__string_var[(uint64_t)x], INSTR(element__b2c__string_var[(uint64_t)x], " ")+1, INSTR(element__b2c__string_var[(uint64_t)x], "[") - INSTR(element__b2c__string_var[(uint64_t)x], " ")-1);
#line 2529 "bacon.bac"
dim__b2c__string_var = F_MID__b2c__string_var(dim__b2c__string_var,element__b2c__string_var[(uint64_t)x], INSTR(element__b2c__string_var[(uint64_t)x], "[")+1, INSTR(element__b2c__string_var[(uint64_t)x], "]") - INSTR(element__b2c__string_var[(uint64_t)x], "[")-1);
#line 2530 "bacon.bac"
if( NOT(INSTR(element__b2c__string_var[(uint64_t)x], g_STRINGSIGN__b2c__string_var))  AND  REGEX(element__b2c__string_var[(uint64_t)x], ".*\\[.*\\].*") ){
#line 2531 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , "char *__b2c_" , arr__b2c__string_var , "[" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) ,"]") ;
#line 2532 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char** " , arr__b2c__string_var , " = __b2c_" , arr__b2c__string_var , ";") ;
#line 2533 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , " " , element__b2c__string_var[x]) ;
#line 2534 "bacon.bac"
} else if( NOT(INSTR(element__b2c__string_var[(uint64_t)x], g_STRINGSIGN__b2c__string_var)) ){
#line 2535 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , HEAD__b2c__string_var(element__b2c__string_var[x], AMOUNT(element__b2c__string_var[x])-1) , " __b2c_" , TAIL__b2c__string_var(element__b2c__string_var[x])) ;
#line 2536 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , HEAD__b2c__string_var(element__b2c__string_var[x], AMOUNT(element__b2c__string_var[x])-1) , " " , TAIL__b2c__string_var(element__b2c__string_var[x]) , " = __b2c_" , TAIL__b2c__string_var(element__b2c__string_var[x]) , ";") ;
#line 2537 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , " " , element__b2c__string_var[x]) ;
#line 2538 "bacon.bac"
} else if( REGEX(element__b2c__string_var[(uint64_t)x], ".*\\[.*\\].*") ){
#line 2539 "bacon.bac"
if( (LEN(dim__b2c__string_var) )< 1 ){
#line 2540 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CHOP__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var , " " , element__b2c__string_var[x]) );
#line 2541 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , " " , element__b2c__string_var[x]) ;
#line 2542 "bacon.bac"
} else {
#line 2543 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , "char *__b2c_" , arr__b2c__string_var , "[" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) ,"]") ;
#line 2544 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "char *" , arr__b2c__string_var , "[" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "] = { NULL };") ;
#line 2545 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "for(__b2c__ctr=0; __b2c__ctr<" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "; __b2c__ctr++){if(__b2c_" , arr__b2c__string_var , "[__b2c__ctr]!=NULL) " , arr__b2c__string_var , "[__b2c__ctr] = __b2c_Copy_String(" , arr__b2c__string_var , "[__b2c__ctr], __b2c_" , arr__b2c__string_var , "[__b2c__ctr]); }") ;
#line 2546 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , "for(__b2c__ctr=0; __b2c__ctr<" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "; __b2c__ctr++) { __b2c__STRFREE(" , arr__b2c__string_var , "[__b2c__ctr]); }") ;
#line 2547 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var,g_PROTOTYPE__b2c__string_var , "char *__b2c_" , CHOP__b2c__string_var(MID__b2c__string_var(element__b2c__string_var[x], INSTR(element__b2c__string_var[x], " ")))) ;
#line 2548 "bacon.bac"
}
#line 2549 "bacon.bac"
} else {
#line 2550 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , "char *__b2c_" , CHOP__b2c__string_var(MID__b2c__string_var(element__b2c__string_var[x], INSTR(element__b2c__string_var[x], " ")))) ;
#line 2551 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,MID__b2c__string_var(element__b2c__string_var[(uint64_t)x], INSTR(element__b2c__string_var[(uint64_t)x], " ")));
#line 2552 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "char *" , var__b2c__string_var , " = NULL;" , var__b2c__string_var , " = __b2c_Copy_String(NULL, __b2c_" , var__b2c__string_var , ");") ;
#line 2553 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , CHOP__b2c__string_var(MID__b2c__string_var(element__b2c__string_var[x], INSTR(element__b2c__string_var[x], " ")))) ;
#line 2554 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , " " , element__b2c__string_var[x]) ;
#line 2555 "bacon.bac"
}
#line 2556 "bacon.bac"
} else {
#line 2558 "bacon.bac"
if( NOT(HASDELIM(element__b2c__string_var[(uint64_t)x]))  AND  NOT(REGEX(element__b2c__string_var[(uint64_t)x], "^DIR|^FILE|^short|^int|^long|^float|^double|^char|^void|^STRING|^NUMBER|^FLOATING")) ){
#line 2559 "bacon.bac"
element__b2c__string_var[(uint64_t)x] = F_CONCAT__b2c__string_var(element__b2c__string_var[(uint64_t)x], IIF__b2c__string_var(REGEX(element__b2c__string_var[(uint64_t)x], CONCAT__b2c__string_var( g_FLOATSIGN__b2c__string_var , "$") ), "double ", CONCAT__b2c__string_var( g_VARTYPE__b2c__string_var , " ") ) , element__b2c__string_var[(uint64_t)x]) ;
#line 2560 "bacon.bac"
}
#line 2562 "bacon.bac"
if( REGEX(TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]), g_C_KEYWORDS__b2c__string_var) ){
#line 2563 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in SUB/FUNCTION statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' is a C keyword or function!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2564 "bacon.bac"
exit(1);
#line 2565 "bacon.bac"
} else if( NOT(LEN(Get_Var__b2c__string_var(TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]), g_FUNCNAME__b2c__string_var))) ){
#line 2566 "bacon.bac"
Save_Func_Var(TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]), g_FUNCNAME__b2c__string_var, FIRST__b2c__string_var(element__b2c__string_var[(uint64_t)x]));
#line 2567 "bacon.bac"
} else {
#line 2568 "bacon.bac"
if( g_SEMANTIC == 0 ){
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "WARNING: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) TAIL__b2c__string_var(element__b2c__string_var[(uint64_t)x]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in function header at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined previously!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 2569 "bacon.bac"
}
#line 2570 "bacon.bac"
if( REGEX(element__b2c__string_var[(uint64_t)x], ".*\\[.*\\].*\\].*") ){
#line 2571 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: cannot pass multidimensional numeric array at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2572 "bacon.bac"
exit(1);
#line 2573 "bacon.bac"
} else if( REGEX(element__b2c__string_var[(uint64_t)x], ".*\\[\\].*") ){
#line 2574 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CHOP__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var , " " , element__b2c__string_var[x]) );
#line 2575 "bacon.bac"
} else if( REGEX(element__b2c__string_var[(uint64_t)x], ".*\\[.*\\].*") ){
#line 2576 "bacon.bac"
dim__b2c__string_var = F_MID__b2c__string_var(dim__b2c__string_var,element__b2c__string_var[(uint64_t)x], INSTR(element__b2c__string_var[(uint64_t)x], "[")+1, INSTR(element__b2c__string_var[(uint64_t)x], "]") - INSTR(element__b2c__string_var[(uint64_t)x], "[")-1);
#line 2577 "bacon.bac"
arr__b2c__string_var = F_MID__b2c__string_var(arr__b2c__string_var,element__b2c__string_var[(uint64_t)x], INSTRREV(element__b2c__string_var[(uint64_t)x], " ")+1, INSTR(element__b2c__string_var[(uint64_t)x], "[") - INSTRREV(element__b2c__string_var[(uint64_t)x], " ")-1);
#line 2578 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , TOKEN__b2c__string_var(element__b2c__string_var[(uint64_t)x], 1) , " __b2c_" , arr__b2c__string_var , "[" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "]") ;
#line 2579 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , TOKEN__b2c__string_var(element__b2c__string_var[(uint64_t)x], 1) , " " , arr__b2c__string_var , "[" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "] = { 0 };") ;
#line 2580 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "memmove(" , arr__b2c__string_var , ", __b2c_" , arr__b2c__string_var , ", (" , dim__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , ")*sizeof(" , TOKEN__b2c__string_var(element__b2c__string_var[(uint64_t)x], 1) , "));") ;
#line 2581 "bacon.bac"
} else {
#line 2582 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CHOP__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var , " " , element__b2c__string_var[x]) );
#line 2583 "bacon.bac"
}
#line 2584 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , " " , element__b2c__string_var[x]) ;
#line 2585 "bacon.bac"
}
#line 2587 "bacon.bac"
if( (x )< dim ){
#line 2588 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , ",") ;
#line 2589 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , ",") ;
#line 2590 "bacon.bac"
} else {
#line 2591 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = F_CONCAT__b2c__string_var(g_ORIGFUNCNAME__b2c__string_var, g_ORIGFUNCNAME__b2c__string_var , ")") ;
#line 2592 "bacon.bac"
g_PROTOTYPE__b2c__string_var = F_CONCAT__b2c__string_var(g_PROTOTYPE__b2c__string_var, g_PROTOTYPE__b2c__string_var , ")") ;
#line 2593 "bacon.bac"
}
#line 2594 "bacon.bac"
}
#line 2597 "bacon.bac"
fclose(g_CFILE);
#line 2600 "bacon.bac"
g_IMPORTED__b2c__string_var = F_CONCAT__b2c__string_var(g_IMPORTED__b2c__string_var, g_FUNCNAME__b2c__string_var , " " , g_IMPORTED__b2c__string_var) ;
#line 2603 "bacon.bac"
g_ORIGCATCHGOTO__b2c__string_var = __b2c_Copy_String(g_ORIGCATCHGOTO__b2c__string_var, (char*) g_CATCHGOTO__b2c__string_var);
#line 2604 "bacon.bac"
g_ORIGCATCH_USED=(long)( g_CATCH_USED);
#line 2605 "bacon.bac"
g_CATCHGOTO__b2c__string_var = __b2c_Copy_String(g_CATCHGOTO__b2c__string_var, (char*) "__B2C__PROGRAM__EXIT");
#line 2606 "bacon.bac"
g_CATCH_USED=(long)( 0);
#line 2607 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;") ;
#line 2610 "bacon.bac"
g_COPY_CFILE__b2c__string_var = __b2c_Copy_String(g_COPY_CFILE__b2c__string_var, (char*) g_CFILE__b2c__string_var);
#line 2611 "bacon.bac"
g_COPY_COUNTER=(long)( g_COUNTER);
#line 2612 "bacon.bac"
g_CFILE__b2c__string_var = F_CONCAT__b2c__string_var(g_CFILE__b2c__string_var, LEFT__b2c__string_var(g_CFILE__b2c__string_var, INSTR(g_CFILE__b2c__string_var, ".c")) , g_FUNCNAME__b2c__string_var , ".tmp") ;
#line 2615 "bacon.bac"
g_CFILE = fopen((const char*)g_CFILE__b2c__string_var, "w");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 2615, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2617 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array); __b2c__free_str_array_members(&element__b2c__string_var, 1, element__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(dim__b2c__string_var);
__b2c__STRFREE(arr__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(no_arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__STRFREE(element__b2c__string_var);
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
