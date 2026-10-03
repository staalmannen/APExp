/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Normal_Dyn_Array( char *__b2c_t__b2c__string_var, char *__b2c_var__b2c__string_var, char *__b2c_array__b2c__string_var, int is_static, int is_local) {
 char*t__b2c__string_var = NULL; t__b2c__string_var = __b2c_Copy_String(NULL, __b2c_t__b2c__string_var); char*var__b2c__string_var = NULL; var__b2c__string_var = __b2c_Copy_String(NULL, __b2c_var__b2c__string_var); char*array__b2c__string_var = NULL; array__b2c__string_var = __b2c_Copy_String(NULL, __b2c_array__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_i__b2c__string_var_ptr = 0; char* __b2c__forin_i__b2c__string_var_string = NULL; char* __b2c__forin_i__b2c__string_var_string_org = NULL; char* __b2c__forin_i__b2c__string_var_step = NULL; int __b2c__forin_j__b2c__string_var_ptr = 0; char* __b2c__forin_j__b2c__string_var_string = NULL; char* __b2c__forin_j__b2c__string_var_string_org = NULL; char* __b2c__forin_j__b2c__string_var_step = NULL;
#line 1405 "bacon.bac"
char *i__b2c__string_var = NULL;
char *j__b2c__string_var = NULL;
char *old__b2c__string_var = NULL;
char *end__b2c__string_var = NULL;
char *tmp_arr__b2c__string_var = NULL;
char *idx__b2c__string_var = NULL;
char *type__b2c__string_var = NULL;
char *org_type__b2c__string_var = NULL;
char *global__b2c__string_var = NULL;
long nr = 0;
#line 1407 "bacon.bac"
__b2c__forin_i__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_i__b2c__string_var_string, var__b2c__string_var); __b2c__forin_i__b2c__string_var_string_org = __b2c__forin_i__b2c__string_var_string;
__b2c__forin_i__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_i__b2c__string_var_step, ",");
__b2c__forin_i__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_i__b2c__string_var_string, __b2c__forin_i__b2c__string_var_step);
for(; __b2c__forin_i__b2c__string_var_ptr > 0; __b2c__forin_i__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_i__b2c__string_var_string_org, __b2c__forin_i__b2c__string_var_step, &i__b2c__string_var);
#line 1408 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) t__b2c__string_var);
#line 1409 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = F_APPEND__b2c__string_var(g_DYNAMICARRAYS__b2c__string_var,g_DYNAMICARRAYS__b2c__string_var, 0, CONCAT__b2c__string_var( CHOP__b2c__string_var(i__b2c__string_var) , "@" , g_FUNCNAME__b2c__string_var) );
#line 1412 "bacon.bac"
if( REGEX(type__b2c__string_var, "STRING|char\\*$")  OR  INSTR(i__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 1413 "bacon.bac"
if( INSTR(IIF__b2c__string_var(TALLY(array__b2c__string_var, "("), TOKEN__b2c__string_var(array__b2c__string_var, 1, "("), array__b2c__string_var), ",") ){
#line 1414 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: string array cannot have more than one dimension line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 1415 "bacon.bac"
exit(1);
#line 1416 "bacon.bac"
}
#line 1417 "bacon.bac"
if( is_local ){
#line 1418 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1419 "bacon.bac"
Save_Func_Var(i__b2c__string_var, g_FUNCNAME__b2c__string_var, type__b2c__string_var);
#line 1420 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " long " , CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array;") ;
#line 1421 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 1422 "bacon.bac"
if( NOT(is_static) ){
#line 1423 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " __b2c__free_str_array_members(&" , CHOP__b2c__string_var(i__b2c__string_var) , ", " , STR__b2c__string_var(g_OPTION_BASE) , ", " , CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array);") ;
#line 1424 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , i__b2c__string_var) ;
#line 1425 "bacon.bac"
}
#line 1426 "bacon.bac"
} else {
#line 1427 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "* "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1428 "bacon.bac"
Save_Main_Var(i__b2c__string_var, type__b2c__string_var);
#line 1429 "bacon.bac"
__b2c__assign = (char*)"long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1430 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array") , "long");
#line 1431 "bacon.bac"
if( NOT(is_static) ){
#line 1432 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , "free(" , CHOP__b2c__string_var(i__b2c__string_var) , ");") ;
#line 1433 "bacon.bac"
}
#line 1434 "bacon.bac"
}
#line 1435 "bacon.bac"
__b2c__assign = (char*)i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) array__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1436 "bacon.bac"
__b2c__assign = (char*)CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) array__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1437 "bacon.bac"
} else {
#line 1438 "bacon.bac"
org_type__b2c__string_var = __b2c_Copy_String(org_type__b2c__string_var, (char*) type__b2c__string_var);
#line 1440 "bacon.bac"
nr=(
long)( 0);
#line 1441 "bacon.bac"
__b2c__forin_j__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_j__b2c__string_var_string, array__b2c__string_var); __b2c__forin_j__b2c__string_var_string_org = __b2c__forin_j__b2c__string_var_string;
__b2c__forin_j__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_j__b2c__string_var_step, ",");
__b2c__forin_j__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_j__b2c__string_var_string, __b2c__forin_j__b2c__string_var_step);
for(; __b2c__forin_j__b2c__string_var_ptr > 0; __b2c__forin_j__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_j__b2c__string_var_string_org, __b2c__forin_j__b2c__string_var_step, &j__b2c__string_var);
#line 1442 "bacon.bac"
nr = nr + (1);
#line 1443 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "*") ;
#line 1444 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1447 "bacon.bac"
if( is_local ){
#line 1448 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1449 "bacon.bac"
Save_Func_Var(i__b2c__string_var, g_FUNCNAME__b2c__string_var, org_type__b2c__string_var);
#line 1450 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " long " , CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array;") ;
#line 1451 "bacon.bac"
Save_Func_Var( CONCAT__b2c__string_var(CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array") , g_FUNCNAME__b2c__string_var, "long");
#line 1452 "bacon.bac"
if( NOT(is_static) ){
#line 1453 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LOCALSTRINGS__b2c__string_var, g_LOCALSTRINGS__b2c__string_var , " " , CHOP__b2c__string_var(i__b2c__string_var)) ;
#line 1454 "bacon.bac"
} else {
#line 1455 "bacon.bac"
g_STATICARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STATICARRAYS__b2c__string_var, g_STATICARRAYS__b2c__string_var , " " , CHOP__b2c__string_var(i__b2c__string_var) , ":" , STR__b2c__string_var(COUNT(type__b2c__string_var, 42))) ;
#line 1456 "bacon.bac"
}
#line 1457 "bacon.bac"
} else {
#line 1458 "bacon.bac"
__b2c__assign = (char*)type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1459 "bacon.bac"
Save_Main_Var(i__b2c__string_var, org_type__b2c__string_var);
#line 1460 "bacon.bac"
__b2c__assign = (char*)"long "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "__b2c_array;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1461 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var(CHOP__b2c__string_var(i__b2c__string_var) , "__b2c_array") , "long");
#line 1462 "bacon.bac"
if( nr == 1 ){
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , "free(" , CHOP__b2c__string_var(i__b2c__string_var) , ");");
}
#line 1463 "bacon.bac"
}
#line 1464 "bacon.bac"
__b2c__assign = (char*)CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "__b2c_array = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(array__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1465 "bacon.bac"
__b2c__assign = (char*)i__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")calloc((size_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(array__b2c__string_var, 1, ","); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(type__b2c__string_var, LEN(type__b2c__string_var)-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1468 "bacon.bac"
if( (nr )> 1 ){
#line 1469 "bacon.bac"
old__b2c__string_var = __b2c_Copy_String(old__b2c__string_var, (char*) LEFT__b2c__string_var(array__b2c__string_var, INSTR(array__b2c__string_var, ",")-1));
#line 1470 "bacon.bac"
tmp_arr__b2c__string_var = F_MID__b2c__string_var(tmp_arr__b2c__string_var,array__b2c__string_var, INSTR(array__b2c__string_var, ",")+1);
#line 1471 "bacon.bac"
nr=(
long)( 0);
#line 1472 "bacon.bac"
idx__b2c__string_var = __b2c_Copy_String(idx__b2c__string_var, (char*) i__b2c__string_var);
#line 1473 "bacon.bac"
end__b2c__string_var = __b2c_Copy_String(end__b2c__string_var, (char*) "");
#line 1475 "bacon.bac"
__b2c__forin_j__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_j__b2c__string_var_string, tmp_arr__b2c__string_var); __b2c__forin_j__b2c__string_var_string_org = __b2c__forin_j__b2c__string_var_string;
__b2c__forin_j__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_j__b2c__string_var_step, ",");
__b2c__forin_j__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_j__b2c__string_var_string, __b2c__forin_j__b2c__string_var_step);
for(; __b2c__forin_j__b2c__string_var_ptr > 0; __b2c__forin_j__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_j__b2c__string_var_string_org, __b2c__forin_j__b2c__string_var_step, &j__b2c__string_var);
#line 1476 "bacon.bac"
nr = nr + (1);
#line 1477 "bacon.bac"
if( is_local ){
#line 1478 "bacon.bac"
g_STRINGARGS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARGS__b2c__string_var, g_STRINGARGS__b2c__string_var , " int __b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , ";") ;
#line 1479 "bacon.bac"
} else {
#line 1480 "bacon.bac"
__b2c__assign = (char*)"int __b2c_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( nr), g_HFILE);
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 1481 "bacon.bac"
}
#line 1482 "bacon.bac"
idx__b2c__string_var = F_CONCAT__b2c__string_var(idx__b2c__string_var, idx__b2c__string_var , "[__b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , "]") ;
#line 1483 "bacon.bac"
__b2c__assign = (char*)"for(__b2c_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( nr), g_CFILE);
__b2c__assign = (char*) " = 0; __b2c_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) STR__b2c__string_var(nr); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " < "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) old__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) "; __b2c_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(i__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( nr), g_CFILE);
__b2c__assign = (char*) "++){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1484 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) LEFT__b2c__string_var(type__b2c__string_var, LEN(type__b2c__string_var)-1));
#line 1485 "bacon.bac"
__b2c__assign = (char*)idx__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ")calloc((size_t)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) j__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_CFILE);
__b2c__assign = (char*) ", sizeof("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) LEFT__b2c__string_var(type__b2c__string_var, LEN(type__b2c__string_var)-1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1486 "bacon.bac"
end__b2c__string_var = F_CONCAT__b2c__string_var(end__b2c__string_var, end__b2c__string_var , " }") ;
#line 1487 "bacon.bac"
old__b2c__string_var = __b2c_Copy_String(old__b2c__string_var, (char*) j__b2c__string_var);
#line 1488 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1489 "bacon.bac"
__b2c__assign = (char*)end__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 1490 "bacon.bac"
type__b2c__string_var = __b2c_Copy_String(type__b2c__string_var, (char*) LEFT__b2c__string_var(type__b2c__string_var, LEN(type__b2c__string_var)-1));
#line 1493 "bacon.bac"
if( (nr )> 0 ){
#line 1494 "bacon.bac"
nr=(
long)( 1);
#line 1495 "bacon.bac"
end__b2c__string_var = __b2c_Copy_String(end__b2c__string_var, (char*) "");
#line 1496 "bacon.bac"
__b2c__forin_j__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_j__b2c__string_var_string, LEFT__b2c__string_var(array__b2c__string_var, INSTRREV(array__b2c__string_var, ",")-1)); __b2c__forin_j__b2c__string_var_string_org = __b2c__forin_j__b2c__string_var_string;
__b2c__forin_j__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_j__b2c__string_var_step, ",");
__b2c__forin_j__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_j__b2c__string_var_string, __b2c__forin_j__b2c__string_var_step);
for(; __b2c__forin_j__b2c__string_var_ptr > 0; __b2c__forin_j__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_j__b2c__string_var_string_org, __b2c__forin_j__b2c__string_var_step, &j__b2c__string_var);
#line 1497 "bacon.bac"
if( NOT(is_static) ){
#line 1498 "bacon.bac"
if( is_local ){
#line 1499 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " for(__b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , " = 0; __b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , " < " , j__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "; __b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , "++){") ;
#line 1500 "bacon.bac"
} else {
#line 1501 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " for(__b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , " = 0; __b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , " < " , j__b2c__string_var , "+" , STR__b2c__string_var(g_OPTION_BASE) , "; __b2c_" , CHOP__b2c__string_var(i__b2c__string_var) , STR__b2c__string_var(nr) , "++){") ;
#line 1502 "bacon.bac"
}
#line 1503 "bacon.bac"
end__b2c__string_var = F_CONCAT__b2c__string_var(end__b2c__string_var, end__b2c__string_var , " __b2c__STRFREE(" , idx__b2c__string_var , "); }") ;
#line 1504 "bacon.bac"
idx__b2c__string_var = __b2c_Copy_String(idx__b2c__string_var, (char*) LEFT__b2c__string_var(idx__b2c__string_var, INSTRREV(idx__b2c__string_var, "[")-1));
#line 1505 "bacon.bac"
nr = nr + (1);
#line 1506 "bacon.bac"
}
#line 1507 "bacon.bac"
}
if(__b2c__break_ctr) {__b2c__break_ctr--; if (!__b2c__break_ctr){if(__b2c__break_flag == 1) break; else continue;} else break; }
#line 1508 "bacon.bac"
if( NOT(is_static) ){
#line 1509 "bacon.bac"
if( is_local ){
#line 1510 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_STRINGARRAYS__b2c__string_var, g_STRINGARRAYS__b2c__string_var , " " , end__b2c__string_var) ;
#line 1511 "bacon.bac"
} else {
#line 1512 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = F_CONCAT__b2c__string_var(g_GLOBALARRAYS__b2c__string_var, g_GLOBALARRAYS__b2c__string_var , " " , end__b2c__string_var , "free(" , CHOP__b2c__string_var(i__b2c__string_var) , ");") ;
#line 1513 "bacon.bac"
}
#line 1514 "bacon.bac"
}
#line 1515 "bacon.bac"
}
#line 1516 "bacon.bac"
}
#line 1517 "bacon.bac"
}
#line 1518 "bacon.bac"
}
#line 1520 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_i__b2c__string_var_string); __b2c__forin_i__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_i__b2c__string_var_step); __b2c__forin_i__b2c__string_var_step = NULL; __b2c__STRFREE(__b2c__forin_j__b2c__string_var_string); __b2c__forin_j__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_j__b2c__string_var_step); __b2c__forin_j__b2c__string_var_step = NULL;
__b2c__STRFREE(t__b2c__string_var);
__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(array__b2c__string_var);
__b2c__STRFREE(i__b2c__string_var);
__b2c__STRFREE(j__b2c__string_var);
__b2c__STRFREE(old__b2c__string_var);
__b2c__STRFREE(end__b2c__string_var);
__b2c__STRFREE(tmp_arr__b2c__string_var);
__b2c__STRFREE(idx__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(org_type__b2c__string_var);
__b2c__STRFREE(global__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
