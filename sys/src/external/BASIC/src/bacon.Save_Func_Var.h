/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Save_Func_Var( char *__b2c_var__b2c__string_var, char *__b2c_func__b2c__string_var, char *__b2c_type__b2c__string_var) {
 char*var__b2c__string_var = NULL; var__b2c__string_var = __b2c_Copy_String(NULL, __b2c_var__b2c__string_var); char*func__b2c__string_var = NULL; func__b2c__string_var = __b2c_Copy_String(NULL, __b2c_func__b2c__string_var); char*type__b2c__string_var = NULL; type__b2c__string_var = __b2c_Copy_String(NULL, __b2c_type__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 155 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(var__b2c__string_var, 1) ,  "*") == 0 ){
#line 156 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , FILL__b2c__string_var(COUNT(var__b2c__string_var, 42), 42)) ;
#line 157 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) EXTRACT__b2c__string_var(var__b2c__string_var, CHR__b2c__string_var(42)));
#line 158 "bacon.bac"
}
#line 161 "bacon.bac"
if( INSTR(var__b2c__string_var, "=") ){
#line 162 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "=")-1));
#line 163 "bacon.bac"
}
#line 166 "bacon.bac"
if( INSTR(var__b2c__string_var, "[") ){
#line 167 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "[")-1));
#line 168 "bacon.bac"
}
#line 170 "bacon.bac"
if( LEN(g_RECORDVAR__b2c__string_var) ){
#line 171 "bacon.bac"
__b2c__hash_add_str(__b2c__assoc_g_ALL_FUNC_VARS__b2c__string_var, type__b2c__string_var,  CONCAT__b2c__string_var(CHOP__b2c__string_var(EXTRACT__b2c__string_var(g_RECORDVAR__b2c__string_var,"\\[.*", TRUE)) , "." , CHOP__b2c__string_var(var__b2c__string_var)) , func__b2c__string_var);
#line 172 "bacon.bac"
} else {
#line 173 "bacon.bac"
__b2c__hash_add_str(__b2c__assoc_g_ALL_FUNC_VARS__b2c__string_var, type__b2c__string_var, CHOP__b2c__string_var(var__b2c__string_var), func__b2c__string_var);
#line 174 "bacon.bac"
}
#line 176 "bacon.bac"

__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(func__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
