/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Push( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 2346 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 2347 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty PUSH at at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2348 "bacon.bac"
exit(1);
#line 2349 "bacon.bac"
}
#line 2350 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 2353 "bacon.bac"
if( NOT(INSTR(g_GLOBALARRAYS__b2c__string_var, "__b2c__stack")) ){
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " __b2c__free_str_array_members(&__b2c__stack, " , STR__b2c__string_var(g_OPTION_BASE) , ", SP); free(__b2c__stack);");
}
#line 2356 "bacon.bac"
__b2c__assign = (char*)"__b2c__stack = (char**)realloc(__b2c__stack, (SP+1)*sizeof(char*));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2357 "bacon.bac"
if( Check_String_Type(arg__b2c__string_var) ){
#line 2358 "bacon.bac"
__b2c__assign = (char*)"__b2c__stack[SP] = __b2c_Copy_String(NULL, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2359 "bacon.bac"
} else {
#line 2360 "bacon.bac"
__b2c__assign = (char*)"__b2c__stack[SP] = calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_CFILE);
__b2c__assign = (char*) ", sizeof(char)); snprintf(__b2c__stack[SP], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MAX_DIGITS-1), g_CFILE);
__b2c__assign = (char*) ", \"%g\", (double)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2361 "bacon.bac"
}
#line 2364 "bacon.bac"
__b2c__assign = (char*)"SP++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2366 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
