/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Relate( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_str__b2c__string_var_ptr = 0; char* __b2c__forin_str__b2c__string_var_string = NULL; char* __b2c__forin_str__b2c__string_var_string_org = NULL; char* __b2c__forin_str__b2c__string_var_step = NULL;
#line 3318 "bacon.bac"
char *source__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
#line 3321 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 3322 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in RELATE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3323 "bacon.bac"
exit(1);
#line 3324 "bacon.bac"
}
#line 3327 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")));
#line 3328 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")-1));
#line 3329 "bacon.bac"
source__b2c__string_var = F_CHOP__b2c__string_var(source__b2c__string_var,arg__b2c__string_var);
#line 3332 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , source__b2c__string_var) )))  AND  NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , source__b2c__string_var) , g_FUNCNAME__b2c__string_var))) ){
#line 3333 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' not declared as ASSOC in RELATE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3334 "bacon.bac"
exit(1);
#line 3335 "bacon.bac"
}
#line 3338 "bacon.bac"
__b2c__forin_str__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_string, EXTRACT__b2c__string_var(to__b2c__string_var, " ")); __b2c__forin_str__b2c__string_var_string_org = __b2c__forin_str__b2c__string_var_string;
__b2c__forin_str__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_step, ",");
__b2c__forin_str__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_str__b2c__string_var_string, __b2c__forin_str__b2c__string_var_step);
for(; __b2c__forin_str__b2c__string_var_ptr > 0; __b2c__forin_str__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_str__b2c__string_var_string_org, __b2c__forin_str__b2c__string_var_step, &str__b2c__string_var);
#line 3339 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , str__b2c__string_var) )))  AND  NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , str__b2c__string_var) , g_FUNCNAME__b2c__string_var))) ){
#line 3340 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' not declared as ASSOC in RELATE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3341 "bacon.bac"
exit(1);
#line 3342 "bacon.bac"
}
#line 3343 "bacon.bac"
g_RELATE__b2c__string_var[(uint64_t)g_RELATE_CTR] = F_CONCAT__b2c__string_var(g_RELATE__b2c__string_var[(uint64_t)g_RELATE_CTR], source__b2c__string_var , " " , str__b2c__string_var) ;
#line 3344 "bacon.bac"
g_RELATE_CTR = g_RELATE_CTR + (1);
#line 3345 "bacon.bac"
}
#line 3347 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_str__b2c__string_var_string); __b2c__forin_str__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_step); __b2c__forin_str__b2c__string_var_step = NULL;
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
