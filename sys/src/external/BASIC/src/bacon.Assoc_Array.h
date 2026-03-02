/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Assoc_Array( char *__b2c_var__b2c__string_var, char *__b2c_type__b2c__string_var, int by_local) {
 char*var__b2c__string_var = NULL; var__b2c__string_var = __b2c_Copy_String(NULL, __b2c_var__b2c__string_var); char*type__b2c__string_var = NULL; type__b2c__string_var = __b2c_Copy_String(NULL, __b2c_type__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_str__b2c__string_var_ptr = 0; char* __b2c__forin_str__b2c__string_var_string = NULL; char* __b2c__forin_str__b2c__string_var_string_org = NULL; char* __b2c__forin_str__b2c__string_var_step = NULL;
#line 1526 "bacon.bac"
char *str__b2c__string_var = NULL;
char *value__b2c__string_var = NULL;
#line 1528 "bacon.bac"
__b2c__forin_str__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_string, var__b2c__string_var); __b2c__forin_str__b2c__string_var_string_org = __b2c__forin_str__b2c__string_var_string;
__b2c__forin_str__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_step, ",");
__b2c__forin_str__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_str__b2c__string_var_string, __b2c__forin_str__b2c__string_var_step);
for(; __b2c__forin_str__b2c__string_var_ptr > 0; __b2c__forin_str__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_str__b2c__string_var_string_org, __b2c__forin_str__b2c__string_var_step, &str__b2c__string_var);
#line 1529 "bacon.bac"
value__b2c__string_var = F_CHOP__b2c__string_var(value__b2c__string_var,str__b2c__string_var);
#line 1532 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var)  AND  LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__assoc_" , value__b2c__string_var) )) ){
#line 1533 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: associative array '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in LOCAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined previously!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1534 "bacon.bac"
exit(1);
#line 1535 "bacon.bac"
}
#line 1537 "bacon.bac"
if( by_local ){
#line 1538 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " __b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1539 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__assoc_" , value__b2c__string_var) , g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 1540 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__hash_clear(__b2c__assoc_" , value__b2c__string_var , "); free(__b2c__assoc_" , value__b2c__string_var , "); __b2c__assoc_" , value__b2c__string_var , " = NULL;") ;
#line 1541 "bacon.bac"
} else {
#line 1542 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " __b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_eval;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1543 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__assoc_" , value__b2c__string_var) , type__b2c__string_var);
#line 1544 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " __b2c__hash_clear(__b2c__assoc_" , value__b2c__string_var , "); free(__b2c__assoc_" , value__b2c__string_var , "); __b2c__assoc_" , value__b2c__string_var , " = NULL;") ;
#line 1545 "bacon.bac"
}
#line 1546 "bacon.bac"
__b2c__assign = (char*)"__b2c__htable *__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ", *__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_orig;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1547 "bacon.bac"
__b2c__assign = (char*)"__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c__hash_new();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1549 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " __b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_func(const char *key){void *result; result = __b2c__hash_find_value(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ", key);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1550 "bacon.bac"
if( INSTR(value__b2c__string_var, g_STRINGSIGN__b2c__string_var)  OR  REGEX(type__b2c__string_var, "STRING|char\\*$") ){
#line 1551 "bacon.bac"
__b2c__assign = (char*)"if(result == NULL) { return(NULL); } return(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ")result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1552 "bacon.bac"
} else {
#line 1553 "bacon.bac"
__b2c__assign = (char*)"if(result == NULL) { return(0); } return(*("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "*)result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1554 "bacon.bac"
}
#line 1555 "bacon.bac"
__b2c__assign = (char*)"#define "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "(...) __b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_func(__b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1556 "bacon.bac"
}
#line 1558 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_str__b2c__string_var_string); __b2c__forin_str__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_step); __b2c__forin_str__b2c__string_var_step = NULL;
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(value__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
