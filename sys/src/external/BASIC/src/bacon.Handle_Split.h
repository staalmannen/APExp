/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Split( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 2991 "bacon.bac"
char *source__b2c__string_var = NULL;
char *by__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
long use_static = 0;
long total = 0;
#line 2994 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 2995 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in SPLIT statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2996 "bacon.bac"
exit(1);
#line 2997 "bacon.bac"
}
#line 3000 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "STATIC") ){
#line 3001 "bacon.bac"
use_static=(
long)( 1);
#line 3002 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "STATIC")));
#line 3003 "bacon.bac"
}
#line 3004 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "BY") ){
#line 3005 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "SPLIT * BY * TO * SIZE *", __b2c__option_delim);
#line 3006 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3007 "bacon.bac"
arg__b2c__string_var = F_APPEND__b2c__string_var(arg__b2c__string_var,HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "BY")-1), 0, LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")-1));
#line 3008 "bacon.bac"
} else {
#line 3009 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) "__b2c__option_delim");
#line 3010 "bacon.bac"
}
#line 3011 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "SPLIT * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3012 "bacon.bac"
source__b2c__string_var = __b2c_Copy_String(source__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3013 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3014 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 3017 "bacon.bac"
if( Check_String_Type(to__b2c__string_var) == 0 ){
#line 3018 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " in SPLIT statement must be string at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3019 "bacon.bac"
exit(1);
#line 3020 "bacon.bac"
}
#line 3023 "bacon.bac"
if( LEN(size__b2c__string_var) ){
Register_Numeric(size__b2c__string_var, "default");
}
#line 3026 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3027 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 3028 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3029 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char **" , to__b2c__string_var , " = NULL; long " , CHOP__b2c__string_var(to__b2c__string_var) , "__b2c_array = 0;") ;
#line 3030 "bacon.bac"
Save_Func_Var(to__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 3031 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 3032 "bacon.bac"
}
#line 3033 "bacon.bac"
} else {
#line 3034 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var))) ){
#line 3035 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3036 "bacon.bac"
__b2c__assign = (char*)"char **"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL; long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(to__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 3037 "bacon.bac"
Save_Main_Var(to__b2c__string_var, "char*");
#line 3038 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , "long");
#line 3039 "bacon.bac"
}
#line 3040 "bacon.bac"
}
#line 3043 "bacon.bac"
if( Check_String_Type(by__b2c__string_var)  OR  __b2c__STRCMP(by__b2c__string_var ,  "__b2c__option_delim") == 0 ){
#line 3044 "bacon.bac"
__b2c__assign = (char*)"__b2c__split_by(&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) by__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3045 "bacon.bac"
} else {
#line 3046 "bacon.bac"
__b2c__assign = (char*)"__b2c__split_with(&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) by__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3047 "bacon.bac"
}
#line 3048 "bacon.bac"
if( LEN(size__b2c__string_var) ){
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 3051 "bacon.bac"
if( NOT(use_static) ){
#line 3052 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_STRINGARRAYS__b2c__string_var, to__b2c__string_var)) ){
#line 3053 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , to__b2c__string_var , "__b2c_array);") ;
#line 3054 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , to__b2c__string_var) ;
#line 3055 "bacon.bac"
} else if( ISFALSE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_GLOBALARRAYS__b2c__string_var, to__b2c__string_var)) ){
#line 3056 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , to__b2c__string_var , "__b2c_array); free(" , to__b2c__string_var , ");") ;
#line 3057 "bacon.bac"
}
#line 3058 "bacon.bac"
}
#line 3060 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(by__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
