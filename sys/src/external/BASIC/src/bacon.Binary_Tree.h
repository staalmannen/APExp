/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Binary_Tree( char *__b2c_var__b2c__string_var, char *__b2c_type__b2c__string_var, int by_local) {
 char*var__b2c__string_var = NULL; var__b2c__string_var = __b2c_Copy_String(NULL, __b2c_var__b2c__string_var); char*type__b2c__string_var = NULL; type__b2c__string_var = __b2c_Copy_String(NULL, __b2c_type__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_str__b2c__string_var_ptr = 0; char* __b2c__forin_str__b2c__string_var_string = NULL; char* __b2c__forin_str__b2c__string_var_string_org = NULL; char* __b2c__forin_str__b2c__string_var_step = NULL;
#line 1564 "bacon.bac"
char *str__b2c__string_var = NULL;
char *value__b2c__string_var = NULL;
#line 1566 "bacon.bac"
__b2c__forin_str__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_string, var__b2c__string_var); __b2c__forin_str__b2c__string_var_string_org = __b2c__forin_str__b2c__string_var_string;
__b2c__forin_str__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_str__b2c__string_var_step, ",");
__b2c__forin_str__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_str__b2c__string_var_string, __b2c__forin_str__b2c__string_var_step);
for(; __b2c__forin_str__b2c__string_var_ptr > 0; __b2c__forin_str__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_str__b2c__string_var_string_org, __b2c__forin_str__b2c__string_var_step, &str__b2c__string_var);
#line 1567 "bacon.bac"
value__b2c__string_var = F_CHOP__b2c__string_var(value__b2c__string_var,str__b2c__string_var);
#line 1570 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var)  AND  LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__tree_" , value__b2c__string_var) )) ){
#line 1571 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: tree variable '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' in LOCAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' was defined previously!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1572 "bacon.bac"
exit(1);
#line 1573 "bacon.bac"
}
#line 1575 "bacon.bac"
if( REGEX(type__b2c__string_var, "STRING|char\\*$") ){
#line 1576 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortstr2:char*");
#line 1577 "bacon.bac"
} else if( INSTR(type__b2c__string_var, "double")  OR  INSTR(type__b2c__string_var, "FLOATING") ){
#line 1578 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortnrd:double");
#line 1579 "bacon.bac"
} else if( INSTR(type__b2c__string_var, "float") ){
#line 1580 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortnrf:float");
#line 1581 "bacon.bac"
} else if( INSTR(type__b2c__string_var, "long")  OR  INSTR(type__b2c__string_var, "NUMBER") ){
#line 1582 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortnrl:long");
#line 1583 "bacon.bac"
} else if( INSTR(type__b2c__string_var, "int") ){
#line 1584 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortnri:int");
#line 1585 "bacon.bac"
} else if( INSTR(type__b2c__string_var, "short") ){
#line 1586 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortnrs:short");
#line 1587 "bacon.bac"
} else if( INSTR(type__b2c__string_var, "short") ){
#line 1588 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "__b2c__sortnrc:char");
#line 1589 "bacon.bac"
} else {
#line 1590 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: unsupported TREE type at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1591 "bacon.bac"
exit(1);
#line 1592 "bacon.bac"
}
#line 1594 "bacon.bac"
if( by_local ){
#line 1595 "bacon.bac"
__b2c__assign = (char*)"void* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1596 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__tree_" , value__b2c__string_var) , g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 1597 "bacon.bac"
} else {
#line 1598 "bacon.bac"
__b2c__assign = (char*)"void* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1599 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__tree_" , value__b2c__string_var) , type__b2c__string_var);
#line 1600 "bacon.bac"
}
#line 1601 "bacon.bac"
}
#line 1603 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_str__b2c__string_var_string); __b2c__forin_str__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_str__b2c__string_var_step); __b2c__forin_str__b2c__string_var_step = NULL;
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(value__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
