/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Swap( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 3433 "bacon.bac"
char *var__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *tmp__b2c__string_var = NULL;
#line 3436 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 3437 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty SWAP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3438 "bacon.bac"
exit(1);
#line 3439 "bacon.bac"
}
#line 3440 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 3443 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,LEFT__b2c__string_var(arg__b2c__string_var, INSTR(arg__b2c__string_var, ",") - 1));
#line 3444 "bacon.bac"
to__b2c__string_var = F_CHOP__b2c__string_var(to__b2c__string_var,MID__b2c__string_var(arg__b2c__string_var, INSTR(arg__b2c__string_var, ",") + 1));
#line 3447 "bacon.bac"
if( Check_String_Type(var__b2c__string_var)  AND  NOT(Check_String_Type(to__b2c__string_var)) ){
#line 3448 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) "+1, sizeof(char)); if (floor("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") == "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") { __b2c__ctr = snprintf(__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) ", \"%ld\", (long) "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3449 "bacon.bac"
__b2c__assign = (char*)"else { __b2c__ctr = snprintf (__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) ", \"%g\", (double) "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); } "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = VAL("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", __b2c__assign); free(__b2c__assign);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3450 "bacon.bac"
} else if( NOT(Check_String_Type(var__b2c__string_var))  AND  Check_String_Type(to__b2c__string_var) ){
#line 3451 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) "+1, sizeof(char)); if (floor("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") == "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") { __b2c__ctr = snprintf(__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) ", \"%ld\", (long) "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3452 "bacon.bac"
__b2c__assign = (char*)"else { __b2c__ctr = snprintf (__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) ", \"%g\", (double) "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); } "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = VAL("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", __b2c__assign); free(__b2c__assign);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3453 "bacon.bac"
} else {
#line 3455 "bacon.bac"
if( Check_String_Type(var__b2c__string_var) ){
#line 3456 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "char *");
#line 3457 "bacon.bac"
} else {
#line 3458 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(var__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 3459 "bacon.bac"
if( LEN(type__b2c__string_var) == 0 ){
#line 3460 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: cannot determine type of variables in SWAP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3461 "bacon.bac"
exit(1);
#line 3462 "bacon.bac"
}
#line 3464 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) LEFT__b2c__string_var(type__b2c__string_var, INSTR(type__b2c__string_var, "*")-1));
#line 3465 "bacon.bac"
}
#line 3468 "bacon.bac"
tmp__b2c__string_var = __b2c_Copy_String(tmp__b2c__string_var, (char*) IIF__b2c__string_var(INSTR(var__b2c__string_var, "["), LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "[")-1), var__b2c__string_var));
#line 3471 "bacon.bac"
if( (LEN(g_FUNCNAME__b2c__string_var) )> 0 ){
#line 3472 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__" , tmp__b2c__string_var , "_swap") , g_FUNCNAME__b2c__string_var))) ){
#line 3473 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " " , type__b2c__string_var , " __b2c__" , tmp__b2c__string_var , "_swap;") ;
#line 3474 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__" , tmp__b2c__string_var , "_swap") , g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 3475 "bacon.bac"
}
#line 3476 "bacon.bac"
} else {
#line 3477 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__" , tmp__b2c__string_var , "_swap") ))) ){
#line 3478 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " __b2c__"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_swap;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 3479 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__" , tmp__b2c__string_var , "_swap") , type__b2c__string_var);
#line 3480 "bacon.bac"
}
#line 3481 "bacon.bac"
}
#line 3482 "bacon.bac"
__b2c__assign = (char*)"__b2c__"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_swap = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c__"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_swap;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3483 "bacon.bac"
}
#line 3485 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(tmp__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
