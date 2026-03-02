/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Deffn( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 2707 "bacon.bac"
char *var__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
#line 2710 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 2711 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty DEF FN at at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2712 "bacon.bac"
exit(1);
#line 2713 "bacon.bac"
}
#line 2716 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "DEF FN *", __b2c__option_delim);
#line 2717 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(match__b2c__string_var[(uint64_t)1], 1, "="));
#line 2718 "bacon.bac"
str__b2c__string_var = F_CHOP__b2c__string_var(str__b2c__string_var,LAST__b2c__string_var(match__b2c__string_var[(uint64_t)1], 1, "="));
#line 2720 "bacon.bac"
__b2c__assign = (char*)"#define "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ")"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 2723 "bacon.bac"
if( REGEX(TOKEN__b2c__string_var(var__b2c__string_var, 1, "("), CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
__b2c__hash_add_str(__b2c__assoc_g_MACRO_STRINGS__b2c__string_var, str__b2c__string_var, TOKEN__b2c__string_var(var__b2c__string_var, 1, "("));
}
#line 2726 "bacon.bac"
g_IMPORTED__b2c__string_var = F_CONCAT__b2c__string_var(g_IMPORTED__b2c__string_var, TOKEN__b2c__string_var(var__b2c__string_var, 1, "(") , " " , g_IMPORTED__b2c__string_var) ;
#line 2728 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
