/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Open( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; char *__b2c__select_885__b2c__string_var = NULL;
#line 832 "bacon.bac"
long check = 0;
char *var__b2c__string_var = NULL;
char *mode__b2c__string_var = NULL;
char *handle__b2c__string_var = NULL;
static char *from__b2c__string_var  = NULL;
from__b2c__string_var  = __b2c_Copy_String(from__b2c__string_var ,  "NULL");
#line 835 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "FOR")) ){
#line 836 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing FOR in OPEN statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 837 "bacon.bac"
exit(1);
#line 838 "bacon.bac"
}
#line 841 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "AS")) ){
#line 842 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing AS in OPEN statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 843 "bacon.bac"
exit(1);
#line 844 "bacon.bac"
}
#line 847 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "FROM") ){
#line 848 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "OPEN * FOR * FROM * AS *", __b2c__option_delim);
#line 849 "bacon.bac"
from__b2c__string_var = __b2c_Copy_String(from__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 850 "bacon.bac"
arg__b2c__string_var = F_APPEND__b2c__string_var(arg__b2c__string_var,HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "FROM")-1), 0, LAST__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "AS")-1));
#line 851 "bacon.bac"
}
#line 852 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "OPEN * FOR * AS *", __b2c__option_delim);
#line 853 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 854 "bacon.bac"
mode__b2c__string_var = __b2c_Copy_String(mode__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 855 "bacon.bac"
handle__b2c__string_var = __b2c_Copy_String(handle__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 858 "bacon.bac"
if( REGEX(handle__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") )  AND  __b2c__STRCMP(mode__b2c__string_var ,  "MEMORY") != 0 ){
#line 859 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable for OPEN at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' cannot be string!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 860 "bacon.bac"
exit(1);
#line 861 "bacon.bac"
}
#line 864 "bacon.bac"
__b2c__hash_add_str(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var, CONCAT__b2c__string_var( "'" , handle__b2c__string_var , "' at line " , STR__b2c__string_var(g_COUNTER) , " in file '" , g_CURFILE__b2c__string_var , "'"), handle__b2c__string_var);
#line 867 "bacon.bac"
if( NOT(INSTR(handle__b2c__string_var, ".")) ){
#line 868 "bacon.bac"
check=(
long)( LEN(Get_Var__b2c__string_var(handle__b2c__string_var, g_FUNCNAME__b2c__string_var)));
#line 869 "bacon.bac"
} else {
#line 870 "bacon.bac"
check=(
long)( TRUE);
#line 871 "bacon.bac"
}
#line 872 "bacon.bac"
if( ISFALSE(check) ){
#line 873 "bacon.bac"
if( __b2c__STRCMP(mode__b2c__string_var ,  "DIRECTORY") == 0 ){
#line 874 "bacon.bac"
Register_Pointer(handle__b2c__string_var, "DIR*");
#line 875 "bacon.bac"
} else if( __b2c__STRCMP(mode__b2c__string_var ,  "MEMORY") == 0 ){
#line 876 "bacon.bac"
Register_Pointer(handle__b2c__string_var, "char*");
#line 877 "bacon.bac"
} else if( __b2c__STRCMP(mode__b2c__string_var ,  "NETWORK") == 0  OR  __b2c__STRCMP(mode__b2c__string_var ,  "SERVER") == 0  OR  __b2c__STRCMP(mode__b2c__string_var ,  "UDP") == 0  OR  __b2c__STRCMP(mode__b2c__string_var ,  "DEVICE") == 0 ){
#line 878 "bacon.bac"
Register_Numeric(handle__b2c__string_var, "uintptr_t");
#line 879 "bacon.bac"
} else {
#line 880 "bacon.bac"
Register_Pointer(handle__b2c__string_var, "FILE*");
#line 881 "bacon.bac"
}
#line 882 "bacon.bac"
}
#line 885 "bacon.bac"
__b2c__select_885__b2c__string_var = __b2c_Copy_String(__b2c__select_885__b2c__string_var, mode__b2c__string_var);
#line 886 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "READING")){
#line 887 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = fopen((const char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", \"r\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 888 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR READING\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 889 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "WRITING")){
#line 890 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = fopen((const char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", \"w\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 891 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR WRITING\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 892 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "APPENDING")){
#line 893 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = fopen((const char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", \"a\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 894 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR APPENDING\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 895 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "READWRITE")){
#line 896 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = fopen((const char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", \"r+\");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 897 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR READWRITE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 898 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "DIRECTORY")){
#line 899 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = opendir("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 900 "bacon.bac"
__b2c__assign = (char*)"if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){ ERROR = 2; RUNTIMEERROR(\"OPEN FOR DIRECTORY\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 901 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "MEMORY")){
#line 902 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c_mem_" , handle__b2c__string_var) , g_FUNCNAME__b2c__string_var))) ){
#line 903 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "long __b2c_mem_" , handle__b2c__string_var) ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 904 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c_mem_" , handle__b2c__string_var) , "long");
#line 905 "bacon.bac"
}
#line 906 "bacon.bac"
if( INSTR(handle__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 907 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __b2c_mem_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (uintptr_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 908 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"OPEN FOR MEMORY\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 909 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "NETWORK")){
#line 911 "bacon.bac"
__b2c__assign = (char*)"ERROR = __b2c__network_init((uintptr_t*)&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_SOCKTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_SOCKET), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_NETWORKTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_MULTICAST_TTL), g_CFILE);
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_SCTP_STREAMS), g_CFILE);
__b2c__assign = (char*) ", __b2c__capeer, __b2c__cacerts, __b2c__caprivate, __b2c__caserver);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 912 "bacon.bac"
__b2c__assign = (char*)"if(ERROR){ RUNTIMEERROR(\"OPEN FOR NETWORK\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 913 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "SERVER")){
#line 915 "bacon.bac"
__b2c__assign = (char*)"ERROR = __b2c__server_init((uintptr_t*)&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_SOCKTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_SOCKET), g_CFILE);
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_SCTP_STREAMS), g_CFILE);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 916 "bacon.bac"
__b2c__assign = (char*)"if(ERROR ){ RUNTIMEERROR(\"OPEN FOR SERVER\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 917 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_885__b2c__string_var, "DEVICE")){
#line 918 "bacon.bac"
__b2c__assign = (char*)handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = open("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", __b2c__option_open, S_IRUSR|S_IWUSR); if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) handle__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " < 0){ ERROR = 32; RUNTIMEERROR(\"OPEN FOR DEVICE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 919 "bacon.bac"
} else {
#line 920 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: wrong mode '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) mode__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' to OPEN statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 921 "bacon.bac"
exit(1);
#line 922 "bacon.bac"
}
#line 923 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 925 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(mode__b2c__string_var);
__b2c__STRFREE(handle__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__STRFREE(__b2c__select_885__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
