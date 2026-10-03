/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval 0
long Check_String_Type( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 326 "bacon.bac"
char *type__b2c__string_var = NULL;
#line 329 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) EXTRACT__b2c__string_var(arg__b2c__string_var, "\\(uint64_t\\)", TRUE));
#line 332 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) IIF__b2c__string_var(TALLY(arg__b2c__string_var, "("), TOKEN__b2c__string_var(arg__b2c__string_var, 1, "("), arg__b2c__string_var));
#line 335 "bacon.bac"
if( INSTR(arg__b2c__string_var, CHR__b2c__string_var(34))  OR  __b2c__STRCMP(RIGHT__b2c__string_var(arg__b2c__string_var, 1) ,  "$") == 0 ){
#line 336 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(TRUE);
#line 337 "bacon.bac"
} else {
#line 339 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(arg__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 341 "bacon.bac"
if( LEN(type__b2c__string_var) ){
#line 342 "bacon.bac"
if( INSTR(type__b2c__string_var, "char*")  OR  INSTR(type__b2c__string_var, "STRING") ){
#line 343 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(TRUE);
#line 344 "bacon.bac"
} else {
#line 345 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(FALSE);
#line 346 "bacon.bac"
}
#line 347 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, g_STRINGSIGN__b2c__string_var)  AND  NOT(INSTR(arg__b2c__string_var, "__b2c_array")) ){
#line 348 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(TRUE);
#line 349 "bacon.bac"
} else {
#line 350 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
return(FALSE);
#line 351 "bacon.bac"
}
#line 352 "bacon.bac"
}
#line 354 "bacon.bac"
__b2c__catch_set = __b2c__catch_set_backup;
return(0);}
