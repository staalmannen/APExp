/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Save_Main_Var( char *__b2c_var__b2c__string_var, char *__b2c_type__b2c__string_var) {
 char*var__b2c__string_var = NULL; var__b2c__string_var = __b2c_Copy_String(NULL, __b2c_var__b2c__string_var); char*type__b2c__string_var = NULL; type__b2c__string_var = __b2c_Copy_String(NULL, __b2c_type__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 123 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(var__b2c__string_var, 1) ,  "*") == 0 ){
#line 124 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , FILL__b2c__string_var(COUNT(var__b2c__string_var, 42), 42)) ;
#line 125 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) EXTRACT__b2c__string_var(var__b2c__string_var, CHR__b2c__string_var(42)));
#line 126 "bacon.bac"
}
#line 129 "bacon.bac"
if( INSTR(var__b2c__string_var, "=") ){
#line 130 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "=")-1));
#line 131 "bacon.bac"
}
#line 134 "bacon.bac"
if( INSTR(var__b2c__string_var, "[") ){
#line 135 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) LEFT__b2c__string_var(var__b2c__string_var, INSTR(var__b2c__string_var, "[")-1));
#line 136 "bacon.bac"
}
#line 138 "bacon.bac"
if( LEN(g_RECORDVAR__b2c__string_var) ){
#line 139 "bacon.bac"
if( LEN(var__b2c__string_var) ){
#line 140 "bacon.bac"
__b2c__hash_add_str(__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var, type__b2c__string_var,  CONCAT__b2c__string_var(CHOP__b2c__string_var(EXTRACT__b2c__string_var(g_RECORDVAR__b2c__string_var,"\\[.*", TRUE)) , "." , CHOP__b2c__string_var(var__b2c__string_var)) );
#line 141 "bacon.bac"
} else {
#line 142 "bacon.bac"
__b2c__hash_add_str(__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var, type__b2c__string_var, CHOP__b2c__string_var(EXTRACT__b2c__string_var(g_RECORDVAR__b2c__string_var,"\\[.*", TRUE)));
#line 143 "bacon.bac"
}
#line 144 "bacon.bac"
} else {
#line 145 "bacon.bac"
__b2c__hash_add_str(__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var, type__b2c__string_var, CHOP__b2c__string_var(var__b2c__string_var));
#line 146 "bacon.bac"
}
#line 148 "bacon.bac"

__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
