/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Getfile( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 1106 "bacon.bac"
char *var__b2c__string_var = NULL;
char *from__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *ftype__b2c__string_var = NULL;
#line 1109 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "FROM")) ){
#line 1110 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing FROM in GETFILE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1111 "bacon.bac"
exit(1);
#line 1112 "bacon.bac"
}
#line 1115 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "FTYPE") ){
#line 1116 "bacon.bac"
ftype__b2c__string_var = __b2c_Copy_String(ftype__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "FTYPE")));
#line 1117 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "FTYPE")-1));
#line 1118 "bacon.bac"
}
#line 1119 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "GETFILE * FROM *", __b2c__option_delim);
#line 1120 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 1121 "bacon.bac"
from__b2c__string_var = __b2c_Copy_String(from__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 1124 "bacon.bac"
if( NOT(Check_String_Type(var__b2c__string_var)) ){
#line 1125 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable for GETFILE at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' must be string!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1126 "bacon.bac"
exit(1);
#line 1127 "bacon.bac"
}
#line 1130 "bacon.bac"
if( REGEX(var__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
Register_Pointer(var__b2c__string_var, "char*");
}
#line 1133 "bacon.bac"
if( LEN(ftype__b2c__string_var) ){
#line 1134 "bacon.bac"
Register_Numeric(ftype__b2c__string_var, "default");
#line 1135 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(ftype__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 1136 "bacon.bac"
}
#line 1139 "bacon.bac"
__b2c__assign = (char*)"__b2c__getfile(__LINE__, __FILE__, &__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &__b2c__counter);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1140 "bacon.bac"
Assign_To_String("__b2c__assign", var__b2c__string_var, NULL);
#line 1141 "bacon.bac"
if( LEN(ftype__b2c__string_var) ){
__b2c__assign = (char*)ftype__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")__b2c__counter;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 1143 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(from__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(ftype__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
