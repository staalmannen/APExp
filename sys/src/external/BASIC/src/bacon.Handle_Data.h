/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Data( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 3353 "bacon.bac"
char *token__b2c__string_var = NULL;
#line 3356 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 3357 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty DATA at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3358 "bacon.bac"
exit(1);
#line 3359 "bacon.bac"
}
#line 3360 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 3363 "bacon.bac"
while( LEN(arg__b2c__string_var) ){
#line 3364 "bacon.bac"
token__b2c__string_var = __b2c_Copy_String(token__b2c__string_var, (char*) Mini_Parser__b2c__string_var(arg__b2c__string_var));
#line 3365 "bacon.bac"
if( INSTR(token__b2c__string_var, CHR__b2c__string_var(34)) ){
#line 3366 "bacon.bac"
__b2c__assign = (char*)CHOP__b2c__string_var(token__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, STRINGARRAYFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, STRINGARRAYFILE); }
fflush(STRINGARRAYFILE);
#line 3367 "bacon.bac"
g_CCTR = g_CCTR + (1);
#line 3368 "bacon.bac"
} else {
#line 3369 "bacon.bac"
__b2c__assign = (char*)CHOP__b2c__string_var(token__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, FLOATARRAYFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, FLOATARRAYFILE); }
fflush(FLOATARRAYFILE);
#line 3370 "bacon.bac"
g_FCTR = g_FCTR + (1);
#line 3371 "bacon.bac"
}
#line 3372 "bacon.bac"
arg__b2c__string_var = F_MID__b2c__string_var(arg__b2c__string_var,arg__b2c__string_var, LEN(token__b2c__string_var)+2);
#line 3373 "bacon.bac"
}
#line 3376 "bacon.bac"
if( INSTR(token__b2c__string_var, CHR__b2c__string_var(34)) ){
#line 3377 "bacon.bac"
__b2c__assign = (char*)""; if(__b2c__assign != NULL) { fputs(__b2c__assign, STRINGARRAYFILE); }
fputs("\n", STRINGARRAYFILE);
#line 3378 "bacon.bac"
} else {
#line 3379 "bacon.bac"
__b2c__assign = (char*)""; if(__b2c__assign != NULL) { fputs(__b2c__assign, FLOATARRAYFILE); }
fputs("\n", FLOATARRAYFILE);
#line 3380 "bacon.bac"
}
#line 3382 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(token__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
