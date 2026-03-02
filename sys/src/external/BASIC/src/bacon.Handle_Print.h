/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Print( char *__b2c_arg__b2c__string_var, char *__b2c_std__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); char*std__b2c__string_var = NULL; std__b2c__string_var = __b2c_Copy_String(NULL, __b2c_std__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 448 "bacon.bac"
char *exp__b2c__string_var = NULL;
char *form__b2c__string_var = NULL;
char *to__b2c__string_var = NULL;
char *token__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
char *lft__b2c__string_var = NULL;
long size = 0;
long total = 0;
#line 451 "bacon.bac"
if( ISTRUE(LEN(arg__b2c__string_var)) ){
#line 454 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "PRINT * FORMAT * TO * SIZE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 455 "bacon.bac"
exp__b2c__string_var = __b2c_Copy_String(exp__b2c__string_var, (char*) IIF__b2c__string_var((total )> 0, match__b2c__string_var[(uint64_t)1]));
#line 456 "bacon.bac"
form__b2c__string_var = __b2c_Copy_String(form__b2c__string_var, (char*) IIF__b2c__string_var((total )> 1, match__b2c__string_var[(uint64_t)2]));
#line 457 "bacon.bac"
to__b2c__string_var = __b2c_Copy_String(to__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 458 "bacon.bac"
size=(
long)( IIF((total )> 3, VAL(match__b2c__string_var[(uint64_t)4]), g_BUFFER_SIZE));
#line 460 "bacon.bac"
if( LEN(form__b2c__string_var) ){
#line 461 "bacon.bac"
if( LEN(to__b2c__string_var) ){
#line 463 "bacon.bac"
if( REGEX(to__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 464 "bacon.bac"
Register_Pointer(to__b2c__string_var, "char*");
#line 465 "bacon.bac"
} else if( NOT(REGEX(to__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "\\(.*\\)$") )) ){
#line 466 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: variable for PRINT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' must be string!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 467 "bacon.bac"
exit(1);
#line 468 "bacon.bac"
}
#line 469 "bacon.bac"
if( REGEX(to__b2c__string_var, "\\(.*\\)$") ){
#line 470 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) INBETWEEN__b2c__string_var(to__b2c__string_var, "(", ")", 2));
#line 471 "bacon.bac"
lft__b2c__string_var = F_MID__b2c__string_var(lft__b2c__string_var,to__b2c__string_var, 1, INSTR(to__b2c__string_var, "(")-1);
#line 472 "bacon.bac"
__b2c__assign = (char*)"snprintf(__b2c__hash_realloc_str_value(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( size), g_CFILE);
__b2c__assign = (char*) "+1, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( size), g_CFILE);
__b2c__assign = (char*) "+1, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) form__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 473 "bacon.bac"
Relate_Recurse(lft__b2c__string_var, str__b2c__string_var, to__b2c__string_var, -1);
#line 474 "bacon.bac"
} else {
#line 475 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = (char*)__b2c_str_realloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( size), g_CFILE);
__b2c__assign = (char*) "+1)*sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 476 "bacon.bac"
__b2c__assign = (char*)"snprintf("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( size), g_CFILE);
__b2c__assign = (char*) "+1, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) form__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); __b2c__SETLEN("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", strlen("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 477 "bacon.bac"
}
#line 478 "bacon.bac"
} else {
#line 479 "bacon.bac"
__b2c__assign = (char*)"fprintf("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) std__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHOP__b2c__string_var(form__b2c__string_var, ";", 2); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) exp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 480 "bacon.bac"
}
#line 481 "bacon.bac"
} else {
#line 483 "bacon.bac"
while( LEN(exp__b2c__string_var) ){
#line 484 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(exp__b2c__string_var));
#line 485 "bacon.bac"
Print_Element(CHOP__b2c__string_var(token__b2c__string_var), std__b2c__string_var);
#line 486 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, LEN(token__b2c__string_var)+1);
#line 487 "bacon.bac"
if( (LEN(exp__b2c__string_var)  AND  __b2c__STRCMP(LEFT__b2c__string_var(exp__b2c__string_var) ,  ",") != 0  AND  __b2c__STRCMP(LEFT__b2c__string_var(exp__b2c__string_var) ,  ";") != 0)  OR  __b2c__STRCMP(CHOP__b2c__string_var(exp__b2c__string_var) ,  ",") == 0 ){
#line 488 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: malformed expression in PRINT at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 489 "bacon.bac"
exit(1);
#line 490 "bacon.bac"
}
#line 491 "bacon.bac"
exp__b2c__string_var = F_MID__b2c__string_var(exp__b2c__string_var,exp__b2c__string_var, 2);
#line 492 "bacon.bac"
}
#line 494 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(arg__b2c__string_var, 1) ,  ";") != 0 ){
#line 495 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\n\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) std__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 496 "bacon.bac"
} else {
#line 497 "bacon.bac"
__b2c__assign = (char*)"fflush("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) std__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 498 "bacon.bac"
}
#line 499 "bacon.bac"
}
#line 500 "bacon.bac"
} else {
#line 501 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\n\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) std__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 502 "bacon.bac"
}
#line 504 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(std__b2c__string_var);
__b2c__STRFREE(exp__b2c__string_var);
__b2c__STRFREE(form__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
