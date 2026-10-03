/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Call( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 3539 "bacon.bac"
char *var__b2c__string_var = NULL;
char *lft__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
#line 3542 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 3543 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty CALL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3544 "bacon.bac"
exit(1);
#line 3545 "bacon.bac"
}
#line 3546 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 3549 "bacon.bac"
if( NOT(REGEX(TOKEN__b2c__string_var(arg__b2c__string_var, 1, " TO "), "\\(.*\\)")) ){
#line 3550 "bacon.bac"
if( INSTR(arg__b2c__string_var, " TO ") ){
#line 3551 "bacon.bac"
arg__b2c__string_var = F_CONCAT__b2c__string_var(arg__b2c__string_var, TOKEN__b2c__string_var(arg__b2c__string_var, 1, " TO ") , "() TO " , TOKEN__b2c__string_var(arg__b2c__string_var, 2, " TO ")) ;
#line 3552 "bacon.bac"
} else {
#line 3553 "bacon.bac"
arg__b2c__string_var = F_CONCAT__b2c__string_var(arg__b2c__string_var, arg__b2c__string_var , "()") ;
#line 3554 "bacon.bac"
}
#line 3555 "bacon.bac"
}
#line 3558 "bacon.bac"
if( NOT(INSTR(arg__b2c__string_var, " TO ")) ){
#line 3559 "bacon.bac"
__b2c__assign = (char*)arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3560 "bacon.bac"
} else {
#line 3561 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(arg__b2c__string_var, 2, " TO "));
#line 3563 "bacon.bac"
if( REGEX(var__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 3564 "bacon.bac"
Register_Pointer(var__b2c__string_var, "char*");
#line 3566 "bacon.bac"
} else {
#line 3567 "bacon.bac"
Register_Numeric(var__b2c__string_var, "default");
#line 3568 "bacon.bac"
}
#line 3571 "bacon.bac"
if( Check_String_Type(var__b2c__string_var) ){
#line 3572 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(arg__b2c__string_var, 1, " TO "); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3573 "bacon.bac"
Assign_To_String("__b2c__assign", var__b2c__string_var, NULL);
#line 3574 "bacon.bac"
} else {
#line 3575 "bacon.bac"
Assign_To_Number(TOKEN__b2c__string_var(arg__b2c__string_var, 1, " TO "), var__b2c__string_var, 0);
#line 3576 "bacon.bac"
}
#line 3577 "bacon.bac"
}
#line 3579 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
