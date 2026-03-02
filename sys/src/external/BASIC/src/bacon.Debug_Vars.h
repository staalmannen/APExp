/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Debug_Vars( void) {
 __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **mainvar__b2c__string_var = { NULL }; long mainvar__b2c__string_var__b2c_array = 0; char **funcvar__b2c__string_var = { NULL }; long funcvar__b2c__string_var__b2c_array = 0; int __b2c__forin_item__b2c__string_var_ptr = 0; char* __b2c__forin_item__b2c__string_var_string = NULL; char* __b2c__forin_item__b2c__string_var_string_org = NULL; char* __b2c__forin_item__b2c__string_var_step = NULL;
#line 182 "bacon.bac"
long xxx = 0;
long many = 0;
char *item__b2c__string_var = NULL;
char *total__b2c__string_var = NULL;
#line 184 "bacon.bac"
mainvar__b2c__string_var__b2c_array = __b2c__lookup_by_order(__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var, &mainvar__b2c__string_var, mainvar__b2c__string_var__b2c_array, 1);
many = mainvar__b2c__string_var__b2c_array;
#line 185 "bacon.bac"
if( many ){
#line 186 "bacon.bac"
for(xxx=1; xxx <= many; xxx+=1){
#line 187 "bacon.bac"
__b2c__assign = (char*)g_ALL_MAIN_VARS__b2c__string_var(mainvar__b2c__string_var[(uint64_t)xxx]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) ":MAIN:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) mainvar__b2c__string_var[(uint64_t)xxx]; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fflush(stderr);
#line 188 "bacon.bac"
}
#line 189 "bacon.bac"
fputs("\n", stdout);
#line 190 "bacon.bac"
}
#line 192 "bacon.bac"
funcvar__b2c__string_var__b2c_array = __b2c__lookup_by_order(__b2c__assoc_g_ALL_FUNC_VARS__b2c__string_var, &funcvar__b2c__string_var, funcvar__b2c__string_var__b2c_array, 1);
many = funcvar__b2c__string_var__b2c_array;
#line 193 "bacon.bac"
if( many ){
#line 194 "bacon.bac"
for(xxx=1; xxx <= many; xxx+=1){
#line 195 "bacon.bac"
__b2c__assign = (char*)g_ALL_FUNC_VARS__b2c__string_var(funcvar__b2c__string_var[(uint64_t)xxx]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) ":"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) TOKEN__b2c__string_var(funcvar__b2c__string_var[(uint64_t)xxx], 2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) ":"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) TOKEN__b2c__string_var(funcvar__b2c__string_var[(uint64_t)xxx], 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fflush(stderr);
#line 196 "bacon.bac"
}
#line 197 "bacon.bac"
fputs("\n", stdout);
#line 198 "bacon.bac"
}
#line 200 "bacon.bac"
__b2c__forin_item__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_string, CONCAT__b2c__string_var( Stat__b2c__string_var , Func__b2c__string_var , Var__b2c__string_var )); __b2c__forin_item__b2c__string_var_string_org = __b2c__forin_item__b2c__string_var_string;
__b2c__forin_item__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_item__b2c__string_var_step, "|");
__b2c__forin_item__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_item__b2c__string_var_string, __b2c__forin_item__b2c__string_var_step);
for(; __b2c__forin_item__b2c__string_var_ptr > 0; __b2c__forin_item__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_item__b2c__string_var_string_org, __b2c__forin_item__b2c__string_var_step, &item__b2c__string_var);
#line 201 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, CONCAT__b2c__string_var( item__b2c__string_var , "\\(") )  OR  REGEX(g_DEPEND__b2c__string_var, CONCAT__b2c__string_var( item__b2c__string_var , "[[:space:]]") ) ){
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , EXTRACT__b2c__string_var(item__b2c__string_var, "\\") , " ");
}
#line 202 "bacon.bac"
}
#line 203 "bacon.bac"
__b2c__assign = (char*)SORT__b2c__string_var(UNIQ__b2c__string_var(total__b2c__string_var)); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 205 "bacon.bac"
 __b2c__free_str_array_members(&mainvar__b2c__string_var, 1, mainvar__b2c__string_var__b2c_array); __b2c__free_str_array_members(&funcvar__b2c__string_var, 1, funcvar__b2c__string_var__b2c_array); __b2c__STRFREE(__b2c__forin_item__b2c__string_var_string); __b2c__forin_item__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_item__b2c__string_var_step); __b2c__forin_item__b2c__string_var_step = NULL;
__b2c__STRFREE(item__b2c__string_var);
__b2c__STRFREE(total__b2c__string_var);
__b2c__STRFREE(mainvar__b2c__string_var);
__b2c__STRFREE(funcvar__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
