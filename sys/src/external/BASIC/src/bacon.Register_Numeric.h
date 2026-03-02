/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Register_Numeric( char *__b2c_arg__b2c__string_var, char *__b2c_type__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); char*type__b2c__string_var = NULL; type__b2c__string_var = __b2c_Copy_String(NULL, __b2c_type__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 212 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 214 "bacon.bac"
if( NOT(INSTR(arg__b2c__string_var, "::"))  AND  NOT(REGEX(arg__b2c__string_var, "\\[.*\\]"))  AND  NOT(TALLY(arg__b2c__string_var, "."))  AND  NOT(REGEX(arg__b2c__string_var, "\\(.*\\)"))  AND  NOT(TALLY(arg__b2c__string_var, "->")) ){
#line 215 "bacon.bac"
if( __b2c__STRCMP(g_OPTION_EXPLICIT__b2c__string_var ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_EXPLICIT__b2c__string_var ,  "TRUE") == 0 ){
#line 216 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: OPTION EXPLICIT forces explicit variable declaration at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 217 "bacon.bac"
exit(1);
#line 218 "bacon.bac"
}
#line 219 "bacon.bac"
if( __b2c__STRCMP(g_OPTION_LOCAL__b2c__string_var ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_LOCAL__b2c__string_var ,  "TRUE") == 0 ){
#line 220 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "default") != 0 ){
#line 221 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 222 "bacon.bac"
Save_Func_Var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 223 "bacon.bac"
} else {
#line 224 "bacon.bac"
if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_FLOATSIGN__b2c__string_var , "$") ) ){
#line 225 "bacon.bac"
__b2c__assign = (char*)"double "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = 0.0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 226 "bacon.bac"
Save_Func_Var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var, "double");
#line 227 "bacon.bac"
} else if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_LONGSIGN__b2c__string_var , "$") ) ){
#line 228 "bacon.bac"
__b2c__assign = (char*)"long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 229 "bacon.bac"
Save_Func_Var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var, "long");
#line 230 "bacon.bac"
} else {
#line 231 "bacon.bac"
__b2c__assign = (char*)g_VARTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 232 "bacon.bac"
Save_Func_Var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var, g_VARTYPE__b2c__string_var);
#line 233 "bacon.bac"
}
#line 234 "bacon.bac"
}
#line 235 "bacon.bac"
} else {
#line 236 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "default") != 0 ){
#line 237 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 238 "bacon.bac"
Save_Main_Var(arg__b2c__string_var, type__b2c__string_var);
#line 239 "bacon.bac"
} else {
#line 240 "bacon.bac"
if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_FLOATSIGN__b2c__string_var , "$") ) ){
#line 241 "bacon.bac"
__b2c__assign = (char*)"double "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0.0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 242 "bacon.bac"
Save_Main_Var(arg__b2c__string_var, "double");
#line 243 "bacon.bac"
} else if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_LONGSIGN__b2c__string_var , "$") ) ){
#line 244 "bacon.bac"
__b2c__assign = (char*)"long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 245 "bacon.bac"
Save_Main_Var(arg__b2c__string_var, "long");
#line 246 "bacon.bac"
} else {
#line 247 "bacon.bac"
__b2c__assign = (char*)g_VARTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 248 "bacon.bac"
Save_Main_Var(arg__b2c__string_var, g_VARTYPE__b2c__string_var);
#line 249 "bacon.bac"
}
#line 250 "bacon.bac"
}
#line 251 "bacon.bac"
}
#line 252 "bacon.bac"
}
#line 253 "bacon.bac"
}
#line 255 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
