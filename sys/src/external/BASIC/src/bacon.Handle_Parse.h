/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Parse( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 3863 "bacon.bac"
char *source__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *with__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
static char *by__b2c__string_var  = NULL;
by__b2c__string_var  = __b2c_Copy_String(by__b2c__string_var ,  "__b2c__option_delim");
long use_static = 0;
long total = 0;
#line 3866 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "WITH")) ){
#line 3867 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing WITH in PARSE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3868 "bacon.bac"
exit(1);
#line 3869 "bacon.bac"
}
#line 3872 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 3873 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in PARSE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3874 "bacon.bac"
exit(1);
#line 3875 "bacon.bac"
}
#line 3878 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "STATIC") ){
#line 3879 "bacon.bac"
use_static=(
long)( 1);
#line 3880 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) DEL__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "STATIC")));
#line 3881 "bacon.bac"
}
#line 3882 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "BY") ){
#line 3883 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "PARSE * WITH * BY * TO * SIZE *", __b2c__option_delim);
#line 3884 "bacon.bac"
by__b2c__string_var = __b2c_Copy_String(by__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 3885 "bacon.bac"
arg__b2c__string_var = F_APPEND__b2c__string_var(arg__b2c__string_var,HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "BY")-1), 0, LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "TO")-1));
#line 3886 "bacon.bac"
}
#line 3887 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "PARSE * WITH * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 3888 "bacon.bac"
source__b2c__string_var = __b2c_Copy_String(source__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 3889 "bacon.bac"
with__b2c__string_var = __b2c_Copy_String(with__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 3890 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 3891 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 3, match__b2c__string_var[(uint64_t)4]));
#line 3894 "bacon.bac"
if( Check_String_Type(to__b2c__string_var) == 0 ){
#line 3895 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) " in PARSE statement must be string at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3896 "bacon.bac"
exit(1);
#line 3897 "bacon.bac"
}
#line 3900 "bacon.bac"
if( LEN(size__b2c__string_var) ){
Register_Numeric(size__b2c__string_var, "default");
}
#line 3903 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 3904 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var, g_FUNCNAME__b2c__string_var))) ){
#line 3905 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3906 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " char **" , to__b2c__string_var , " = NULL; long " , CHOP__b2c__string_var(to__b2c__string_var) , "__b2c_array = 0;") ;
#line 3907 "bacon.bac"
Save_Func_Var(to__b2c__string_var, g_FUNCNAME__b2c__string_var, "char*");
#line 3908 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 3909 "bacon.bac"
}
#line 3910 "bacon.bac"
} else {
#line 3911 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var(to__b2c__string_var))) ){
#line 3912 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( to__b2c__string_var , "@" , g_FUNCNAME__b2c__string_var) );
#line 3913 "bacon.bac"
__b2c__assign = (char*)"char **"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL; long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(to__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 3914 "bacon.bac"
Save_Main_Var(to__b2c__string_var, "char*");
#line 3915 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(to__b2c__string_var , "__b2c_array") , "long");
#line 3916 "bacon.bac"
}
#line 3917 "bacon.bac"
}
#line 3920 "bacon.bac"
__b2c__assign = (char*)"__b2c__parse(&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", &"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) source__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) with__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) by__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3922 "bacon.bac"
if( LEN(size__b2c__string_var) ){
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 3925 "bacon.bac"
if( NOT(use_static) ){
#line 3926 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_STRINGARRAYS__b2c__string_var, to__b2c__string_var)) ){
#line 3927 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , to__b2c__string_var , "__b2c_array);") ;
#line 3928 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , to__b2c__string_var) ;
#line 3929 "bacon.bac"
} else if( ISFALSE(LEN(g_FUNCNAME__b2c__string_var))  AND  NOT(INSTR(g_GLOBALARRAYS__b2c__string_var, to__b2c__string_var)) ){
#line 3930 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , to__b2c__string_var , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , to__b2c__string_var , "__b2c_array); free(" , to__b2c__string_var , ");") ;
#line 3931 "bacon.bac"
}
#line 3932 "bacon.bac"
}
#line 3934 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(source__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(with__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
