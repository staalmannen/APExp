/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Writeln( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 963 "bacon.bac"
char *var__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *token__b2c__string_var = NULL;
char *org__b2c__string_var = NULL;
#line 966 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 967 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in WRITELN statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 968 "bacon.bac"
exit(1);
#line 969 "bacon.bac"
}
#line 972 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "WRITELN * TO *", __b2c__option_delim);
#line 973 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 974 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 975 "bacon.bac"
org__b2c__string_var = __b2c_Copy_String(org__b2c__string_var, (char*) var__b2c__string_var);
#line 978 "bacon.bac"
while( LEN(var__b2c__string_var) ){
#line 979 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(var__b2c__string_var));
#line 980 "bacon.bac"
Print_Element(CHOP__b2c__string_var(token__b2c__string_var), to__b2c__string_var);
#line 981 "bacon.bac"
var__b2c__string_var = F_MID__b2c__string_var(var__b2c__string_var,var__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 982 "bacon.bac"
}
#line 984 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(org__b2c__string_var, 1) ,  ";") != 0 ){
#line 985 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\n\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 986 "bacon.bac"
} else {
#line 987 "bacon.bac"
__b2c__assign = (char*)"fflush("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 988 "bacon.bac"
}
#line 990 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(org__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
