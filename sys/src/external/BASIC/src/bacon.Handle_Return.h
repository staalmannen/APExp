/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Return( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_name__b2c__string_var_ptr = 0; char* __b2c__forin_name__b2c__string_var_string = NULL; char* __b2c__forin_name__b2c__string_var_string_org = NULL; char* __b2c__forin_name__b2c__string_var_step = NULL; int __b2c__forin_str__b2c__string_var_ptr = 0; char* __b2c__forin_str__b2c__string_var_string = NULL; char* __b2c__forin_str__b2c__string_var_string_org = NULL; char* __b2c__forin_str__b2c__string_var_step = NULL;
#line 2280 "bacon.bac"
char *type__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *name__b2c__string_var = NULL;
long x = 0;
#line 2282 "bacon.bac"
arg__b2c__string_var = F_CHOP__b2c__string_var(arg__b2c__string_var,arg__b2c__string_var);
#line 2285 "bacon.bac"
if( ISFALSE(LEN(arg__b2c__string_var)) ){
#line 2286 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__gosub_buffer_ptr >= 0) longjmp(__b2c__gosub_buffer[__b2c__gosub_buffer_ptr], 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2287 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(name__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return __b2c__exitval;
#line 2288 "bacon.bac"
}
#line 2290 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) IIF__b2c__string_var((LEN(g_FUNCTYPE__b2c__string_var))>0, g_FUNCTYPE__b2c__string_var, Get_Var__b2c__string_var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var)));
#line 2293 "bacon.bac"
if( Check_String_Type(arg__b2c__string_var)  OR  REGEX(g_FUNCTYPE__b2c__string_var, "char\\*$|STRING$")  OR  REGEX(g_FUNCNAME__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 2295 "bacon.bac"
if( ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( arg__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) ) ){
#line 2296 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) "char**");
#line 2298 "bacon.bac"
} else {
#line 2299 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) "char*");
#line 2300 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = __b2c__return("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2301 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) "__b2c__assign");
#line 2302 "bacon.bac"
}
#line 2305 "bacon.bac"
} else if( ISTRUE(LEN(type__b2c__string_var)) ){
#line 2306 "bacon.bac"
if( INSTR(arg__b2c__string_var, "[") ){
#line 2307 "bacon.bac"
for(x=1; x <= COUNT(arg__b2c__string_var, 91); x+=1){
#line 2308 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(type__b2c__string_var, 1) ,  "*") == 0 ){
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) LEFT__b2c__string_var(type__b2c__string_var, LEN(type__b2c__string_var)-1));
}
#line 2309 "bacon.bac"
}
#line 2310 "bacon.bac"
} else {
#line 2311 "bacon.bac"
__b2c__forin_name__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_name__b2c__string_var_string, g_STATICARRAYS__b2c__string_var); __b2c__forin_name__b2c__string_var_string_org = __b2c__forin_name__b2c__string_var_string;
__b2c__forin_name__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_name__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_name__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_name__b2c__string_var_string, __b2c__forin_name__b2c__string_var_step);
for(; __b2c__forin_name__b2c__string_var_ptr > 0; __b2c__forin_name__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_name__b2c__string_var_string_org, __b2c__forin_name__b2c__string_var_step, &name__b2c__string_var);
#line 2312 "bacon.bac"
if( INSTR(name__b2c__string_var, arg__b2c__string_var) ){
#line 2313 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , FILL__b2c__string_var(VAL(MID__b2c__string_var(name__b2c__string_var, INSTR(name__b2c__string_var, ":")+1)), 42)) ;
#line 2314 "bacon.bac"
break;
#line 2315 "bacon.bac"
}
#line 2316 "bacon.bac"
}
#line 2317 "bacon.bac"
}
#line 2318 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) type__b2c__string_var);
#line 2321 "bacon.bac"
} else if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_LONGSIGN__b2c__string_var , "$") )  OR  REGEX(g_FUNCNAME__b2c__string_var, CONCAT__b2c__string_var( g_LONGSIGN__b2c__string_var , "$") ) ){
#line 2322 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) "long");
#line 2323 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, ".")  OR  REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_FLOATSIGN__b2c__string_var , "$") )  OR  REGEX(g_FUNCNAME__b2c__string_var, CONCAT__b2c__string_var( g_FLOATSIGN__b2c__string_var , "$") ) ){
#line 2324 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) "double");
#line 2325 "bacon.bac"
} else {
#line 2326 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) g_VARTYPE__b2c__string_var);
#line 2327 "bacon.bac"
}
#line 2330 "bacon.bac"
__b2c__assign = (char*)g_STRINGARRAYS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2331 "bacon.bac"
__b2c__forin_str__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_string, g_LOCALSTRINGS__b2c__string_var); __b2c__forin_str__b2c__string_var_string_org = __b2c__forin_str__b2c__string_var_string;
__b2c__forin_str__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_str__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_str__b2c__string_var_string, __b2c__forin_str__b2c__string_var_step);
for(; __b2c__forin_str__b2c__string_var_ptr > 0; __b2c__forin_str__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_str__b2c__string_var_string_org, __b2c__forin_str__b2c__string_var_step, &str__b2c__string_var);
#line 2332 "bacon.bac"
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2333 "bacon.bac"
}
#line 2336 "bacon.bac"
__b2c__assign = (char*)"__b2c__catch_set = __b2c__catch_set_backup;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2337 "bacon.bac"
__b2c__assign = (char*)"return("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2339 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_name__b2c__string_var_string); __b2c__forin_name__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_name__b2c__string_var_step); __b2c__forin_name__b2c__string_var_step = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_string); __b2c__forin_str__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_step); __b2c__forin_str__b2c__string_var_step = NULL;
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(name__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
