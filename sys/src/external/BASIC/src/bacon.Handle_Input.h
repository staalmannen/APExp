/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Input( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 510 "bacon.bac"
char *type__b2c__string_var = NULL;
char *lft__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *token__b2c__string_var = NULL;
#line 513 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 514 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty INPUT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 515 "bacon.bac"
exit(1);
#line 516 "bacon.bac"
}
#line 517 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 520 "bacon.bac"
while( LEN(arg__b2c__string_var) ){
#line 521 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(arg__b2c__string_var));
#line 522 "bacon.bac"
arg__b2c__string_var = F_MID__b2c__string_var(arg__b2c__string_var,arg__b2c__string_var, LEN(token__b2c__string_var)+1);
#line 523 "bacon.bac"
if( LEN(arg__b2c__string_var) ){
#line 524 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(arg__b2c__string_var) ,  ",") != 0  OR  __b2c__STRCMP(CHOP__b2c__string_var(arg__b2c__string_var) ,  ",") == 0 ){
#line 525 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: malformed expression in INPUT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 526 "bacon.bac"
exit(1);
#line 527 "bacon.bac"
} else {
#line 528 "bacon.bac"
Print_Element(CHOP__b2c__string_var(token__b2c__string_var), "stdout");
#line 529 "bacon.bac"
}
#line 530 "bacon.bac"
}
#line 531 "bacon.bac"
arg__b2c__string_var = F_MID__b2c__string_var(arg__b2c__string_var,arg__b2c__string_var, 2);
#line 532 "bacon.bac"
}
#line 533 "bacon.bac"
__b2c__assign = (char*)"fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 534 "bacon.bac"
arg__b2c__string_var = F_CHOP__b2c__string_var(arg__b2c__string_var,token__b2c__string_var);
#line 537 "bacon.bac"
if( NOT(REGEX(arg__b2c__string_var, "^[a-zA-Z]+.*")) ){
#line 538 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: argument in INPUT statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' is not a variable!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 539 "bacon.bac"
exit(1);
#line 540 "bacon.bac"
}
#line 543 "bacon.bac"
if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 544 "bacon.bac"
Register_Pointer(arg__b2c__string_var, "char*");
#line 545 "bacon.bac"
} else {
#line 546 "bacon.bac"
Register_Numeric(arg__b2c__string_var, "default");
#line 547 "bacon.bac"
}
#line 550 "bacon.bac"
__b2c__assign = (char*)"__b2c__input(__LINE__, __FILE__, &__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_OPTION_INPUT__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 552 "bacon.bac"
if( Check_String_Type(arg__b2c__string_var) ){
#line 553 "bacon.bac"
Assign_To_String("__b2c__assign", arg__b2c__string_var, NULL);
#line 554 "bacon.bac"
} else {
#line 555 "bacon.bac"
Assign_To_Number("__b2c__assign", arg__b2c__string_var, 1);
#line 556 "bacon.bac"
}
#line 558 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
