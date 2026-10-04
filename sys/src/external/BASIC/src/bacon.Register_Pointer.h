/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Register_Pointer( char *__b2c_arg__b2c__string_var, char *__b2c_type__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); char*type__b2c__string_var = NULL; type__b2c__string_var = __b2c_Copy_String(NULL, __b2c_type__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 259 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 261 "bacon.bac"
if( NOT(TALLY(arg__b2c__string_var, "."))  AND  NOT(TALLY(arg__b2c__string_var, "->")) ){
#line 262 "bacon.bac"
if( __b2c__STRCMP(g_OPTION_EXPLICIT__b2c__string_var ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_EXPLICIT__b2c__string_var ,  "TRUE") == 0 ){
#line 263 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: OPTION EXPLICIT forces explicit variable declaration at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 264 "bacon.bac"
exit(1);
#line 265 "bacon.bac"
}
#line 266 "bacon.bac"
if( __b2c__STRCMP(g_OPTION_LOCAL__b2c__string_var ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_LOCAL__b2c__string_var ,  "TRUE") == 0 ){
#line 267 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 268 "bacon.bac"
Save_Func_Var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 269 "bacon.bac"
} else {
#line 270 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 271 "bacon.bac"
Save_Main_Var(arg__b2c__string_var, type__b2c__string_var);
#line 272 "bacon.bac"
}
#line 273 "bacon.bac"
}
#line 274 "bacon.bac"
}
#line 276 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
