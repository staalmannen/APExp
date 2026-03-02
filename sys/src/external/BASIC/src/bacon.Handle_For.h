/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_For( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 564 "bacon.bac"
char *var__b2c__string_var = NULL;
char *in__b2c__string_var = NULL;
char *from__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *step__b2c__string_var = NULL;
long total = 0;
#line 567 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO"))  AND  NOT(ISTOKEN(arg__b2c__string_var, "DOWNTO"))  AND  NOT(ISTOKEN(arg__b2c__string_var, "IN")) ){
#line 568 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing IN/TO/DOWNTO in FOR statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 569 "bacon.bac"
exit(1);
#line 570 "bacon.bac"
}
#line 573 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "TO")  OR  ISTOKEN(arg__b2c__string_var, "DOWNTO") ){
#line 575 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), CONCAT__b2c__string_var( "FOR * " , IIF__b2c__string_var(ISTOKEN(arg__b2c__string_var, "TO"), "TO", "DOWNTO") , " * STEP *" ), __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 576 "bacon.bac"
var__b2c__string_var = F_CHOP__b2c__string_var(var__b2c__string_var,TOKEN__b2c__string_var(match__b2c__string_var[(uint64_t)1], 1, "="));
#line 577 "bacon.bac"
from__b2c__string_var = F_CHOP__b2c__string_var(from__b2c__string_var,TOKEN__b2c__string_var(match__b2c__string_var[(uint64_t)1], 2, "="));
#line 578 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 579 "bacon.bac"
step__b2c__string_var = __b2c_Copy_String(step__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3], "1"));
#line 580 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "DOWNTO") ){
step__b2c__string_var = F_CONCAT__b2c__string_var(step__b2c__string_var, "-" , step__b2c__string_var);
}
#line 581 "bacon.bac"
} else {
#line 582 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "FOR * IN * STEP *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 583 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 584 "bacon.bac"
in__b2c__string_var = __b2c_Copy_String(in__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 585 "bacon.bac"
step__b2c__string_var = __b2c_Copy_String(step__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3], "__b2c__option_delim"));
#line 587 "bacon.bac"
if( (LEN(g_FUNCNAME__b2c__string_var) )> 0 ){
#line 588 "bacon.bac"
if( NOT(INSTR(g_STRINGARGS__b2c__string_var, CONCAT__b2c__string_var( "__b2c__forin_" , var__b2c__string_var , "_ptr") )) ){
#line 589 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " int __b2c__forin_" , var__b2c__string_var , "_ptr = 0;") ;
#line 590 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_ptr") , g_FUNCNAME__b2c__string_var, "int");
#line 591 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char* __b2c__forin_" , var__b2c__string_var , "_string = NULL;") ;
#line 592 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_string") , g_FUNCNAME__b2c__string_var, "char*");
#line 593 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char* __b2c__forin_" , var__b2c__string_var , "_string_org = NULL;") ;
#line 594 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_string_org") , g_FUNCNAME__b2c__string_var, "char*");
#line 595 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char* __b2c__forin_" , var__b2c__string_var , "_step = NULL;") ;
#line 596 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_step") , g_FUNCNAME__b2c__string_var, "char*");
#line 597 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__STRFREE(__b2c__forin_" , var__b2c__string_var , "_string); __b2c__forin_" , var__b2c__string_var , "_string = NULL;") ;
#line 598 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__STRFREE(__b2c__forin_" , var__b2c__string_var , "_step); __b2c__forin_" , var__b2c__string_var , "_step = NULL;") ;
#line 599 "bacon.bac"
}
#line 600 "bacon.bac"
} else {
#line 601 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_ptr") ))) ){
#line 602 "bacon.bac"
__b2c__assign = (char*)"int __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_ptr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 603 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_ptr") , "int");
#line 604 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_string = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 605 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_string") , "char*");
#line 606 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_string_org = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 607 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_string_org") , "char*");
#line 608 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "_step = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 609 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__forin_" , var__b2c__string_var , "_step") , "char*");
#line 610 "bacon.bac"
}
#line 611 "bacon.bac"
}
#line 612 "bacon.bac"
}
#line 615 "bacon.bac"
if( REGEX(var__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 616 "bacon.bac"
Register_Pointer(var__b2c__string_var, "char*");
#line 617 "bacon.bac"
} else if( REGEX( CONCAT__b2c__string_var(from__b2c__string_var , to__b2c__string_var , step__b2c__string_var) , "[0-9]\\.[0-9]")  OR  REGEX(Get_Var__b2c__string_var(step__b2c__string_var, g_FUNCNAME__b2c__string_var), "double|float|FLOATING") ){
#line 618 "bacon.bac"
Register_Numeric(var__b2c__string_var, "double");
#line 619 "bacon.bac"
} else {
#line 620 "bacon.bac"
Register_Numeric(var__b2c__string_var, "default");
#line 621 "bacon.bac"
}
#line 624 "bacon.bac"
if( Check_String_Type(var__b2c__string_var) ){
#line 625 "bacon.bac"
__b2c__assign = (char*)"__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_string = __b2c_Copy_String(__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_string, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) in__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_string_org = __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_string;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 626 "bacon.bac"
__b2c__assign = (char*)"__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_step = __b2c_Copy_String(__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_step, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) step__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 627 "bacon.bac"
__b2c__assign = (char*)"__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_ptr = __b2c__for_amount(__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_string, __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_step);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 628 "bacon.bac"
__b2c__assign = (char*)"for(; __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_ptr > 0; __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_ptr--) { __b2c__for_item(&__b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_string_org, __b2c__forin_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_step, &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 629 "bacon.bac"
} else {
#line 631 "bacon.bac"
if( (VAL(step__b2c__string_var) )< 0 ){
#line 632 "bacon.bac"
__b2c__assign = (char*)"for("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*)" = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " >= "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " += "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) step__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 633 "bacon.bac"
} else {
#line 634 "bacon.bac"
__b2c__assign = (char*)"for("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*)" = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " <= "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " += "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) step__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 635 "bacon.bac"
}
#line 636 "bacon.bac"
}
#line 638 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(in__b2c__string_var);
__b2c__STRFREE(from__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(step__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
