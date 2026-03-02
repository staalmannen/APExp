/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Map( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; int __b2c__forin_i__b2c__string_var_ptr = 0; char* __b2c__forin_i__b2c__string_var_string = NULL; char* __b2c__forin_i__b2c__string_var_string_org = NULL; char* __b2c__forin_i__b2c__string_var_step = NULL;
#line 3635 "bacon.bac"
char *source__b2c__string_var = NULL;
char *by__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *i__b2c__string_var = NULL;
long use_static = 0;
long total = 0;
#line 3638 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 3639 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty MAP at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3640 "bacon.bac"
exit(1);
#line 3641 "bacon.bac"
}
#line 3644 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "BY")) ){
#line 3645 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing BY in MAP statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3646 "bacon.bac"
exit(1);
#line 3647 "bacon.bac"
}
#line 3650 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 3651 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in MAP statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3652 "bacon.bac"
exit(1);
#line 3653 "bacon.bac"
}
#line 3656 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "STATIC") ){
#line 3657 "bacon.bac"
use_static=(
long)( 1);
#line 3658 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "STATIC")));
#line 3659 "bacon.bac"
}
#line 3660 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "MAP * BY * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3661 "bacon.bac"
source__b2c__string_var = __b2c_Copy_String(source__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3662 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3663 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 3664 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 3, match__b2c__string_var[(uint64_t)4]));
#line 3667 "bacon.bac"
if( NOT(LEN(size__b2c__string_var)) ){
#line 3668 "bacon.bac"
if( ISTOKEN(g_DYNAMICARRAYS__b2c__string_var, CONCAT__b2c__string_var( CHOP__b2c__string_var(TOKEN__b2c__string_var(source__b2c__string_var, 1, ",")) , "@" , g_FUNCNAME__b2c__string_var) ) ){
#line 3669 "bacon.bac"
size__b2c__string_var = F_CONCAT__b2c__string_var(size__b2c__string_var, CHOP__b2c__string_var(TOKEN__b2c__string_var(source__b2c__string_var, 1, ",")) , "__b2c_array") ;
#line 3670 "bacon.bac"
} else {
#line 3671 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(CHOP__b2c__string_var(TOKEN__b2c__string_var(source__b2c__string_var, 1, ",")), g_FUNCNAME__b2c__string_var));
#line 3672 "bacon.bac"
size__b2c__string_var = F_CONCAT__b2c__string_var(size__b2c__string_var, "(sizeof(" , CHOP__b2c__string_var(TOKEN__b2c__string_var(source__b2c__string_var, 1, ",")) , ")/sizeof(" , type__b2c__string_var , ")-" , STR__b2c__string_var(g_OPTION_BASE) , ")") ;
#line 3673 "bacon.bac"
}
#line 3674 "bacon.bac"
}
#line 3677 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) EXTRACT__b2c__string_var(by__b2c__string_var, CHR__b2c__string_var(34)));
#line 3680 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "long");
#line 3682 "bacon.bac"
if( Check_String_Type(by__b2c__string_var) ){
#line 3683 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "char*");
#line 3684 "bacon.bac"
} else {
#line 3685 "bacon.bac"
__b2c__forin_i__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_i__b2c__string_var_string, source__b2c__string_var); __b2c__forin_i__b2c__string_var_string_org = __b2c__forin_i__b2c__string_var_string;
__b2c__forin_i__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_i__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_i__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_i__b2c__string_var_string, __b2c__forin_i__b2c__string_var_step);
for(; __b2c__forin_i__b2c__string_var_ptr > 0; __b2c__forin_i__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_i__b2c__string_var_string_org, __b2c__forin_i__b2c__string_var_step, &i__b2c__string_var);
#line 3686 "bacon.bac"
if( REGEX(Get_Var__b2c__string_var(i__b2c__string_var, g_FUNCNAME__b2c__string_var), ".*double.*|.*FLOATING.*") ){
#line 3687 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) "double");
#line 3688 "bacon.bac"
break;
#line 3689 "bacon.bac"
}
#line 3690 "bacon.bac"
}
#line 3691 "bacon.bac"
}
#line 3694 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 3695 "bacon.bac"
if( __b2c__STRCMP(g_OPTION_EXPLICIT__b2c__string_var ,  "1") == 0  OR  __b2c__STRCMP(g_OPTION_EXPLICIT__b2c__string_var ,  "TRUE") == 0 ){
#line 3696 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: OPTION EXPLICIT forces explicit variable declaration at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3697 "bacon.bac"
exit(1);
#line 3698 "bacon.bac"
}
#line 3699 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3700 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3701 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3702 "bacon.bac"
Save_Func_Var(to__b2c__string_var, g_FUNCNAME__b2c__string_var, CONCAT__b2c__string_var( type__b2c__string_var , "*") );
#line 3703 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 3704 "bacon.bac"
} else {
#line 3705 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3706 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "; long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 3707 "bacon.bac"
Save_Main_Var(to__b2c__string_var, CONCAT__b2c__string_var( type__b2c__string_var , "*") );
#line 3708 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , "long");
#line 3709 "bacon.bac"
}
#line 3710 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)calloc((size_t)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) "), sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3711 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3714 "bacon.bac"
if( use_static == 0 ){
#line 3715 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "char*") == 0 ){
#line 3716 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3717 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , size__b2c__string_var , ");") ;
#line 3718 "bacon.bac"
} else {
#line 3719 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , "free(" , to__b2c__string_var , ");") ;
#line 3720 "bacon.bac"
}
#line 3721 "bacon.bac"
}
#line 3722 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , to__b2c__string_var) ;
#line 3723 "bacon.bac"
}
#line 3724 "bacon.bac"
}
#line 3727 "bacon.bac"
__b2c__assign = (char*)"for(__b2c__ctr="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) "; __b2c__ctr<"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) "; __b2c__ctr++){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3728 "bacon.bac"
if( __b2c__STRCMP(type__b2c__string_var ,  "char*") == 0 ){
#line 3729 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "[__b2c__ctr] = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "[__b2c__ctr], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) by__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(source__b2c__string_var, ",", "[__b2c__ctr],"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "[__b2c__ctr])); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3730 "bacon.bac"
} else {
#line 3731 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "[__b2c__ctr] = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) by__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) REPLACE__b2c__string_var(source__b2c__string_var, ",", "[__b2c__ctr],"); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "[__b2c__ctr]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3732 "bacon.bac"
}
#line 3734 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array); __b2c__STRFREE(__b2c__forin_i__b2c__string_var_string); __b2c__forin_i__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_i__b2c__string_var_step); __b2c__forin_i__b2c__string_var_step = NULL;
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(by__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(i__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
