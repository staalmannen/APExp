/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Putbyte( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 1051 "bacon.bac"
char *var__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *size__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *chunk__b2c__string_var = NULL;
long total = 0;
#line 1054 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TO")) ){
#line 1055 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in PUTBYTE statement at line at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1056 "bacon.bac"
exit(1);
#line 1057 "bacon.bac"
}
#line 1060 "bacon.bac"
if( MATCH(COLLAPSE__b2c__string_var(arg__b2c__string_var), "* CHUNK *") ){
#line 1061 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "PUTBYTE * TO * CHUNK * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 1062 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 1063 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) IIF__b2c__string_var((total )> 3, match__b2c__string_var[(uint64_t)4]));
#line 1064 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "CHUNK")-1));
#line 1065 "bacon.bac"
} else if( MATCH(COLLAPSE__b2c__string_var(arg__b2c__string_var), "* SIZE *") ){
#line 1066 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "PUTBYTE * TO * SIZE *", __b2c__option_delim);
#line 1067 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 1068 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) HEAD__b2c__string_var(arg__b2c__string_var, ISTOKEN(arg__b2c__string_var, "SIZE")-1));
#line 1069 "bacon.bac"
}
#line 1070 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "PUTBYTE * TO *", __b2c__option_delim);
#line 1071 "bacon.bac"
var__b2c__string_var = __b2c_Copy_String(var__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 1072 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 1075 "bacon.bac"
if( LEN(size__b2c__string_var) ){
#line 1076 "bacon.bac"
if( LEN(chunk__b2c__string_var) == 0 ){
#line 1077 "bacon.bac"
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) size__b2c__string_var);
#line 1078 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) "__b2c__counter");
#line 1079 "bacon.bac"
}
#line 1080 "bacon.bac"
} else {
#line 1081 "bacon.bac"
if( LEN(chunk__b2c__string_var) == 0 ){
chunk__b2c__string_var = __b2c_Copy_String(chunk__b2c__string_var, (char*) "1");
}
#line 1082 "bacon.bac"
size__b2c__string_var = __b2c_Copy_String(size__b2c__string_var, (char*) "__b2c__counter");
#line 1083 "bacon.bac"
}
#line 1086 "bacon.bac"
if( LEN(size__b2c__string_var)  AND  __b2c__STRCMP(size__b2c__string_var ,  "__b2c__counter") != 0 ){
Register_Numeric(size__b2c__string_var, "default");
}
#line 1089 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) Get_Var__b2c__string_var(to__b2c__string_var, g_FUNCNAME__b2c__string_var));
#line 1092 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__memory__check((char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE))) { ERROR=1; RUNTIMEERROR(\"PUTBYTE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1093 "bacon.bac"
if( INSTR(type__b2c__string_var, "int") ){
#line 1094 "bacon.bac"
__b2c__assign = (char*)"if(("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = write("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")) < 0) { ERROR = 34; RUNTIMEERROR(\"PUTBYTE\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1095 "bacon.bac"
} else {
#line 1096 "bacon.bac"
__b2c__assign = (char*)size__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = fwrite((void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) var__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", sizeof(__b2c__MEMTYPE), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) chunk__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1097 "bacon.bac"
}
#line 1098 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 1100 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(size__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(chunk__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
