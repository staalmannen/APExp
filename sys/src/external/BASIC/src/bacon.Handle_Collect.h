/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Collect( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; char *__b2c__select_3829__b2c__string_var = NULL;
#line 3786 "bacon.bac"
char *source__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *sort__b2c__string_var = NULL;
char *func__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
long total = 0;
long nr = 0;
long use_static = 0;
#line 3789 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 3790 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in COLLECT statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3791 "bacon.bac"
exit(1);
#line 3792 "bacon.bac"
}
#line 3795 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "STATIC") ){
#line 3796 "bacon.bac"
use_static=(
long)( 1);
#line 3797 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "STATIC")));
#line 3798 "bacon.bac"
}
#line 3799 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "COLLECT * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3800 "bacon.bac"
source__b2c__string_var = __b2c_Copy_String(source__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3801 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3802 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 3805 "bacon.bac"
if( LEN(size__b2c__string_var) ){
Register_Numeric(size__b2c__string_var, "default");
}
#line 3808 "bacon.bac"
func__b2c__string_var = __b2c_Copy_String(func__b2c__string_var, (char*) Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__tree_" , source__b2c__string_var) , g_FUNCNAME__b2c__string_var));
#line 3809 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) TOKEN__b2c__string_var(func__b2c__string_var, 2, ":"));
#line 3812 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3813 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 3814 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3815 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , type__b2c__string_var , "* " , to__b2c__string_var , " = { NULL }; long " , to__b2c__string_var , "__b2c_array = " , STR__b2c__string_var(g_OPTION_BASE) , ";") ;
#line 3816 "bacon.bac"
Save_Func_Var(to__b2c__string_var, g_FUNCNAME__b2c__string_var, CONCAT__b2c__string_var( type__b2c__string_var , "*") );
#line 3817 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 3818 "bacon.bac"
}
#line 3819 "bacon.bac"
} else {
#line 3820 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var))) ){
#line 3821 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3822 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( type__b2c__string_var , "* ") ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { NULL }; long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_HFILE);
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 3823 "bacon.bac"
Save_Main_Var(to__b2c__string_var, CONCAT__b2c__string_var( type__b2c__string_var , "*") );
#line 3824 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , "long");
#line 3825 "bacon.bac"
}
#line 3826 "bacon.bac"
}
#line 3829 "bacon.bac"
__b2c__select_3829__b2c__string_var = __b2c_Copy_String(__b2c__select_3829__b2c__string_var, type__b2c__string_var);
#line 3830 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "char*") || !__b2c__strcmp(__b2c__select_3829__b2c__string_var,  "STRING")){
#line 3831 "bacon.bac"
nr=(
long)( 0);
#line 3832 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "double") || !__b2c__strcmp(__b2c__select_3829__b2c__string_var,  "FLOATING")){
#line 3833 "bacon.bac"
nr=(
long)( 1);
#line 3834 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "float")){
#line 3835 "bacon.bac"
nr=(
long)( 2);
#line 3836 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "long") || !__b2c__strcmp(__b2c__select_3829__b2c__string_var,  "NUMBER")){
#line 3837 "bacon.bac"
nr=(
long)( 3);
#line 3838 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "int")){
#line 3839 "bacon.bac"
nr=(
long)( 4);
#line 3840 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "short")){
#line 3841 "bacon.bac"
nr=(
long)( 5);
#line 3842 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_3829__b2c__string_var, "char")){
#line 3843 "bacon.bac"
nr=(
long)( 6);
#line 3844 "bacon.bac"
}
#line 3845 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = __b2c__collect("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void***)&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( nr), g_CFILE);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3846 "bacon.bac"
if( LEN(size__b2c__string_var) ){
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 3849 "bacon.bac"
if( NOT(use_static) ){
#line 3850 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_STRINGARRAYS__b2c__string_var, CONCAT__b2c__string_var( "(" , to__b2c__string_var , ")") )) ){
#line 3851 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " free(" , to__b2c__string_var , ");") ;
#line 3852 "bacon.bac"
} else if( ISFALSE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_GLOBALARRAYS__b2c__string_var, CONCAT__b2c__string_var( "(" , to__b2c__string_var , ")") )) ){
#line 3853 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " free(" , to__b2c__string_var , ");") ;
#line 3854 "bacon.bac"
}
#line 3855 "bacon.bac"
}
#line 3857 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(sort__b2c__string_var);
__b2c__STRFREE(func__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__STRFREE(__b2c__select_3829__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
