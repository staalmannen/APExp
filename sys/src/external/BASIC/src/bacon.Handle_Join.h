/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Join( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 3066 "bacon.bac"
char *source__b2c__string_var = NULL;
char *by__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
long total = 0;
#line 3069 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 3070 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in JOIN statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3071 "bacon.bac"
exit(1);
#line 3072 "bacon.bac"
}
#line 3075 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "BY") ){
#line 3076 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "JOIN * BY * TO * SIZE *", __b2c__option_delim);
#line 3077 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3078 "bacon.bac"
arg__b2c__string_var = F_APPEND__b2c__string_var(arg__b2c__string_var,HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "BY")-1), 0, LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")-1));
#line 3079 "bacon.bac"
} else {
#line 3080 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) "__b2c_EMPTYSTRING");
#line 3081 "bacon.bac"
}
#line 3082 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "JOIN * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3083 "bacon.bac"
source__b2c__string_var = __b2c_Copy_String(source__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3084 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3085 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 3088 "bacon.bac"
if( NOT(LEN(size__b2c__string_var)) ){
#line 3089 "bacon.bac"
if( ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( source__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) ) ){
#line 3090 "bacon.bac"
size__b2c__string_var = F_CONCAT__b2c__string_var(size__b2c__string_var, source__b2c__string_var , "__b2c_array") ;
#line 3091 "bacon.bac"
} else {
#line 3092 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(source__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 3093 "bacon.bac"
size__b2c__string_var = F_CONCAT__b2c__string_var(size__b2c__string_var, "(sizeof(" , source__b2c__string_var , ")/sizeof(" , type__b2c__string_var , ")-" , STR__b2c__string_var(g_OPTION_BASE) , ")") ;
#line 3094 "bacon.bac"
}
#line 3095 "bacon.bac"
}
#line 3098 "bacon.bac"
if( Check_String_Type(to__b2c__string_var) == 0 ){
#line 3099 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " in JOIN statement must be string at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3100 "bacon.bac"
exit(1);
#line 3101 "bacon.bac"
} else {
#line 3102 "bacon.bac"
if( REGEX(to__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 3103 "bacon.bac"
Register_Pointer(to__b2c__string_var, "char*");
#line 3104 "bacon.bac"
}
#line 3105 "bacon.bac"
}
#line 3108 "bacon.bac"
__b2c__assign = (char*)"__b2c__join(&__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) by__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3109 "bacon.bac"
Assign_To_String("__b2c__assign", to__b2c__string_var, NULL);
#line 3111 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(by__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
