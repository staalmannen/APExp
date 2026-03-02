/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval 0
char* __Get_Var__b2c__string_var(int __b2c__arg_tot, ...) {
 long amount; long __b2c__var_arg__b2c__string_var = 1; va_list __b2c__ap; char **arg__b2c__string_var = NULL; arg__b2c__string_var = (char **)calloc(__b2c__arg_tot+1, sizeof(char*)); amount = __b2c__arg_tot; va_start(__b2c__ap, __b2c__arg_tot); while (__b2c__arg_tot) { arg__b2c__string_var[__b2c__var_arg__b2c__string_var] = __b2c_Copy_String(arg__b2c__string_var[__b2c__var_arg__b2c__string_var], va_arg(__b2c__ap, char*)); __b2c__var_arg__b2c__string_var++; __b2c__arg_tot--; } va_end(__b2c__ap); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 76 "bacon.bac"
char *var__b2c__string_var = NULL;
char *result__b2c__string_var = NULL;
char *record__b2c__string_var = NULL;
#line 79 "bacon.bac"
if( INSTR(arg__b2c__string_var[(uint64_t)1], "=") ){
#line 80 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(arg__b2c__string_var[(uint64_t)1], INSTR(arg__b2c__string_var[(uint64_t)1], "=")-1));
#line 81 "bacon.bac"
} else {
#line 82 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) arg__b2c__string_var[(uint64_t)1]);
#line 83 "bacon.bac"
}
#line 86 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) EXTRACT__b2c__string_var(var__b2c__string_var, CHR__b2c__string_var(42)));
#line 89 "bacon.bac"
if( (AMOUNT(var__b2c__string_var, ".") )> 1 ){
#line 90 "bacon.bac"
record__b2c__string_var = __b2c_Copy_String(record__b2c__string_var, (char*) TOKEN__b2c__string_var(var__b2c__string_var, 1, "."));
#line 91 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) TOKEN__b2c__string_var(var__b2c__string_var, 2, "."));
#line 92 "bacon.bac"
} else {
#line 93 "bacon.bac"
record__b2c__string_var = __b2c_Copy_String(record__b2c__string_var, (char*) g_RECORDVAR__b2c__string_var);
#line 94 "bacon.bac"
}
#line 95 "bacon.bac"
record__b2c__string_var = F_CHOP__b2c__string_var(record__b2c__string_var,EXTRACT__b2c__string_var(record__b2c__string_var,"\\[.*", TRUE));
#line 98 "bacon.bac"
if( LEN(record__b2c__string_var) ){
record__b2c__string_var = F_CONCAT__b2c__string_var(record__b2c__string_var, record__b2c__string_var , ".");
}
#line 101 "bacon.bac"
if( INSTR(var__b2c__string_var, "[") ){
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "[")-1));
}
#line 104 "bacon.bac"
if( INSTR(var__b2c__string_var, "(") ){
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "(")-1));
}
#line 107 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) REPLACE__b2c__string_var(var__b2c__string_var, "$", g_STRINGSIGN__b2c__string_var));
#line 108 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) REPLACE__b2c__string_var(var__b2c__string_var, "#", g_FLOATSIGN__b2c__string_var));
#line 109 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) REPLACE__b2c__string_var(var__b2c__string_var, "%", g_LONGSIGN__b2c__string_var));
#line 111 "bacon.bac"
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) g_ALL_MAIN_VARS__b2c__string_var( CONCAT__b2c__string_var(record__b2c__string_var , var__b2c__string_var) ));
#line 112 "bacon.bac"
if( (amount )> 1  AND  NOT(LEN(result__b2c__string_var)) ){
result__b2c__string_var = __b2c_Copy_String(result__b2c__string_var, (char*) g_ALL_FUNC_VARS__b2c__string_var( CONCAT__b2c__string_var(record__b2c__string_var , var__b2c__string_var) , arg__b2c__string_var[(uint64_t)2]));
}
#line 114 "bacon.bac"
__b2c__assign = __b2c__return(result__b2c__string_var);
 __b2c__free_str_array_members(&arg__b2c__string_var, 1, amount); free(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(result__b2c__string_var);
__b2c__STRFREE(record__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(__b2c__assign);
#line 116 "bacon.bac"
__b2c__catch_set = __b2c__catch_set_backup;
return (NULL);}
