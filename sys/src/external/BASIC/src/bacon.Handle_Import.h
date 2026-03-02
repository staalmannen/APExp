/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Import( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 1326 "bacon.bac"
char *lib__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *sym__b2c__string_var = NULL;
char *token__b2c__string_var = NULL;
char *alias__b2c__string_var = NULL;
char *ptr__b2c__string_var = NULL;
long total = 0;
#line 1329 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "FROM")) ){
#line 1330 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing FROM in IMPORT statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1331 "bacon.bac"
exit(1);
#line 1332 "bacon.bac"
}
#line 1335 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "TYPE")) ){
#line 1336 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TYPE in IMPORT statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1337 "bacon.bac"
exit(1);
#line 1338 "bacon.bac"
}
#line 1341 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "IMPORT * FROM * TYPE * ALIAS *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 1342 "bacon.bac"
sym__b2c__string_var = __b2c_Copy_String(sym__b2c__string_var, (char*) EXTRACT__b2c__string_var(match__b2c__string_var[(uint64_t)1], CHR__b2c__string_var(34)));
#line 1343 "bacon.bac"
lib__b2c__string_var = __b2c_Copy_String(lib__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 1344 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)3]);
#line 1345 "bacon.bac"
if( (total )> 3 ){
#line 1346 "bacon.bac"
alias__b2c__string_var = __b2c_Copy_String(alias__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)4]);
#line 1347 "bacon.bac"
g_IMPORTED__b2c__string_var = F_CONCAT__b2c__string_var(g_IMPORTED__b2c__string_var, alias__b2c__string_var , " " , g_IMPORTED__b2c__string_var) ;
#line 1348 "bacon.bac"
}
#line 1351 "bacon.bac"
if( INSTR(sym__b2c__string_var, "(") ){
#line 1352 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) INBETWEEN__b2c__string_var(sym__b2c__string_var, "(", ")"));
#line 1353 "bacon.bac"
sym__b2c__string_var = F_CHOP__b2c__string_var(sym__b2c__string_var,TOKEN__b2c__string_var(sym__b2c__string_var, 1, "("));
#line 1354 "bacon.bac"
}
#line 1357 "bacon.bac"
if( NOT(INSTR(lib__b2c__string_var, "libc.so") )  AND  NOT(INSTR(lib__b2c__string_var, "libm.so")) ){
#line 1359 "bacon.bac"
if( NOT(TALLY(OS__b2c__string_var, "OSF1"))  AND  NOT(TALLY(OS__b2c__string_var, "BSD"))  AND  NOT(TALLY(OS__b2c__string_var, "Haiku"))  AND  NOT(INSTR(g_LDFLAGS__b2c__string_var, "-ldl")) ){
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " -ldl");
}
#line 1362 "bacon.bac"
ptr__b2c__string_var = __b2c_Copy_String(ptr__b2c__string_var, (char*) EXTRACT__b2c__string_var(lib__b2c__string_var, "[[:punct:]]", TRUE));
#line 1365 "bacon.bac"
if( NOT(LEN(Get_Var__b2c__string_var( CONCAT__b2c__string_var("__b2c__dlopen__pointer_" , ptr__b2c__string_var) , g_FUNCNAME__b2c__string_var))) ){
#line 1366 "bacon.bac"
if( ISTRUE(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 1367 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , "static void *__b2c__dlopen__pointer_" , ptr__b2c__string_var , " = NULL;") ;
#line 1368 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var("__b2c__dlopen__pointer_" , ptr__b2c__string_var) , g_FUNCNAME__b2c__string_var, "void*");
#line 1369 "bacon.bac"
} else {
#line 1370 "bacon.bac"
__b2c__assign = (char*)"void* __b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1371 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__dlopen__pointer_" , ptr__b2c__string_var) , "void*");
#line 1372 "bacon.bac"
}
#line 1373 "bacon.bac"
}
#line 1374 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = dlopen("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lib__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", RTLD_LAZY); if(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL){ ERROR = 3; RUNTIMEERROR(\"IMPORT\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1377 "bacon.bac"
if( __b2c__STRCMP(lib__b2c__string_var ,  "NULL") != 0 ){
#line 1378 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "(*"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ")("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1379 "bacon.bac"
__b2c__assign = (char*)"*("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "**) (&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*)"*)dlsym(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\"); if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL) { ERROR = 4; RUNTIMEERROR(\"IMPORT\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1380 "bacon.bac"
} else {
#line 1381 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "(*"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) alias__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ")("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) token__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1382 "bacon.bac"
__b2c__assign = (char*)"*("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "**) (&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) alias__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ") = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*)"*)dlsym(__b2c__dlopen__pointer_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ptr__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\"); if("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) alias__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " == NULL) { ERROR = 4; RUNTIMEERROR(\"IMPORT\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1383 "bacon.bac"
}
#line 1384 "bacon.bac"
}
#line 1387 "bacon.bac"
if( __b2c__STRCMP(lib__b2c__string_var ,  "NULL") != 0 ){
#line 1388 "bacon.bac"
if( ISTOKEN(g_IMPORTED__b2c__string_var, sym__b2c__string_var) ){
#line 1389 "bacon.bac"
if( g_SEMANTIC == 0 ){
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "WARNING: duplicate symbol '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 1390 "bacon.bac"
} else {
#line 1391 "bacon.bac"
g_IMPORTED__b2c__string_var = F_APPEND__b2c__string_var(g_IMPORTED__b2c__string_var,g_IMPORTED__b2c__string_var, 0, sym__b2c__string_var);
#line 1392 "bacon.bac"
}
#line 1393 "bacon.bac"
if( LEN(alias__b2c__string_var) ){
__b2c__assign = (char*)"#define "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) alias__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) sym__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 1394 "bacon.bac"
}
#line 1397 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 1399 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(lib__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(sym__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(alias__b2c__string_var);
__b2c__STRFREE(ptr__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
