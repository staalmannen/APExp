/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Read( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_element__b2c__string_var_ptr = 0; char* __b2c__forin_element__b2c__string_var_string = NULL; char* __b2c__forin_element__b2c__string_var_string_org = NULL; char* __b2c__forin_element__b2c__string_var_step = NULL;
#line 2149 "bacon.bac"
char *type__b2c__string_var = NULL;
char *element__b2c__string_var = NULL;
char *lft__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
#line 2152 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 2153 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty READ at at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2154 "bacon.bac"
exit(1);
#line 2155 "bacon.bac"
}
#line 2156 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 2158 "bacon.bac"
__b2c__forin_element__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_element__b2c__string_var_string, EXTRACT__b2c__string_var(arg__b2c__string_var, " ")); __b2c__forin_element__b2c__string_var_string_org = __b2c__forin_element__b2c__string_var_string;
__b2c__forin_element__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_element__b2c__string_var_step, ",");
__b2c__forin_element__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_element__b2c__string_var_string, __b2c__forin_element__b2c__string_var_step);
for(; __b2c__forin_element__b2c__string_var_ptr > 0; __b2c__forin_element__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_element__b2c__string_var_string_org, __b2c__forin_element__b2c__string_var_step, &element__b2c__string_var);
#line 2161 "bacon.bac"
if( REGEX(element__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 2162 "bacon.bac"
Register_Pointer(element__b2c__string_var, "char*");
#line 2163 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "char*");
#line 2164 "bacon.bac"
} else {
#line 2165 "bacon.bac"
Register_Numeric(element__b2c__string_var, "default");
#line 2166 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(element__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 2167 "bacon.bac"
}
#line 2170 "bacon.bac"
if( Check_String_Type(element__b2c__string_var) ){
#line 2172 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = __b2c_Copy_String(NULL, __b2c__stringarray[__b2c__stringarray_ptr]); __b2c__stringarray_ptr++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2173 "bacon.bac"
Assign_To_String("__b2c__assign", element__b2c__string_var, NULL);
#line 2174 "bacon.bac"
} else {
#line 2175 "bacon.bac"
Assign_To_Number("__b2c__floatarray[__b2c__floatarray_ptr]", element__b2c__string_var, 0);
#line 2176 "bacon.bac"
__b2c__assign = (char*)"__b2c__floatarray_ptr++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2177 "bacon.bac"
}
#line 2178 "bacon.bac"
}
#line 2180 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_element__b2c__string_var_string); __b2c__forin_element__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_element__b2c__string_var_step); __b2c__forin_element__b2c__string_var_step = NULL;
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(element__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
