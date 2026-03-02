/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Getbyte( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 996 "bacon.bac"
char *var__b2c__string_var = NULL;
char *from__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *chunk__b2c__string_var = NULL;
long total = 0;
#line 999 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "FROM")) ){
#line 1000 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing FROM in GETBYTE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1001 "bacon.bac"
exit(1);
#line 1002 "bacon.bac"
}
#line 1005 "bacon.bac"
if( MATCH(COLLAPSE__b2c__string_var(arg__b2c__string_var), "* CHUNK *") ){
#line 1006 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "GETBYTE * FROM * CHUNK * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 1007 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 1008 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 3, match__b2c__string_var[(uint64_t)4]));
#line 1009 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "CHUNK")-1));
#line 1010 "bacon.bac"
} else if( MATCH(COLLAPSE__b2c__string_var(arg__b2c__string_var), "* SIZE *") ){
#line 1011 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "GETBYTE * FROM * SIZE *", __b2c__option_delim);
#line 1012 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 1013 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SIZE")-1));
#line 1014 "bacon.bac"
}
#line 1015 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "GETBYTE * FROM *", __b2c__option_delim);
#line 1016 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 1017 "bacon.bac"
from__b2c__string_var = __b2c_Copy_String(from__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 1020 "bacon.bac"
if( LEN(size__b2c__string_var) ){
#line 1021 "bacon.bac"
if( LEN(chunk__b2c__string_var) == 0 ){
#line 1022 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) size__b2c__string_var);
#line 1023 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) "__b2c__counter");
#line 1024 "bacon.bac"
}
#line 1025 "bacon.bac"
} else {
#line 1026 "bacon.bac"
if( LEN(chunk__b2c__string_var) == 0 ){
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) "1");
}
#line 1027 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) "__b2c__counter");
#line 1028 "bacon.bac"
}
#line 1031 "bacon.bac"
if( LEN(size__b2c__string_var)  AND  __b2c__STRCMP(size__b2c__string_var ,  "__b2c__counter") != 0 ){
Register_Numeric(size__b2c__string_var, "default");
}
#line 1034 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(from__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 1037 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check((char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"GETBYTE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1038 "bacon.bac"
if( INSTR(type__b2c__string_var, "int") ){
#line 1039 "bacon.bac"
__b2c__assign = (char*)"if(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = read("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")) < 0) { ERROR = 34; RUNTIMEERROR(\"GETBYTE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1040 "bacon.bac"
} else {
#line 1041 "bacon.bac"
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = fread((void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), sizeof(__b2c__MEMTYPE), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1042 "bacon.bac"
}
#line 1043 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 1045 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(from__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(chunk__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
