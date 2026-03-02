/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Setserial( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 3491 "bacon.bac"
char *desc__b2c__string_var = NULL;
char *value__b2c__string_var = NULL;
static char *param__b2c__string_var  = NULL;
param__b2c__string_var  = __b2c_Copy_String(param__b2c__string_var ,  "0");
static char *not__b2c__string_var  = NULL;
not__b2c__string_var  = __b2c_Copy_String(not__b2c__string_var ,  "0");
long which = 0;
#line 3494 "bacon.bac"
if( NOT(REGEX(arg__b2c__string_var, " IMODE | OMODE | CMODE | LMODE | OTHER | SPEED ")) ){
#line 3495 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: no mode specified in SETSERIAL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3496 "bacon.bac"
exit(1);
#line 3497 "bacon.bac"
}
#line 3499 "bacon.bac"
desc__b2c__string_var = __b2c_Copy_String(desc__b2c__string_var, (char*) LEFT__b2c__string_var(arg__b2c__string_var, INSTR(arg__b2c__string_var, " ")));
#line 3502 "bacon.bac"
if( INSTR(arg__b2c__string_var, " OTHER ") ){
#line 3503 "bacon.bac"
value__b2c__string_var = F_MID__b2c__string_var(value__b2c__string_var,arg__b2c__string_var, INSTRREV(arg__b2c__string_var, "OTHER ")+6);
#line 3504 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, " SPEED ") ){
#line 3505 "bacon.bac"
value__b2c__string_var = F_MID__b2c__string_var(value__b2c__string_var,arg__b2c__string_var, INSTRREV(arg__b2c__string_var, "SPEED ")+6);
#line 3506 "bacon.bac"
} else {
#line 3507 "bacon.bac"
value__b2c__string_var = F_MID__b2c__string_var(value__b2c__string_var,arg__b2c__string_var, INSTRREV(arg__b2c__string_var, "MODE ")+5);
#line 3508 "bacon.bac"
}
#line 3510 "bacon.bac"
if( INSTR(arg__b2c__string_var, "IMODE") ){
#line 3511 "bacon.bac"
which=(
long)( 0);
#line 3512 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, "OMODE") ){
#line 3513 "bacon.bac"
which=(
long)( 1);
#line 3514 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, "CMODE") ){
#line 3515 "bacon.bac"
which=(
long)( 2);
#line 3516 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, "LMODE") ){
#line 3517 "bacon.bac"
which=(
long)( 3);
#line 3518 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, "OTHER") ){
#line 3519 "bacon.bac"
which=(
long)( 4);
#line 3520 "bacon.bac"
param__b2c__string_var = __b2c_Copy_String(param__b2c__string_var, (char*) TOKEN__b2c__string_var(value__b2c__string_var, 1, "="));
#line 3521 "bacon.bac"
value__b2c__string_var = __b2c_Copy_String(value__b2c__string_var, (char*) TOKEN__b2c__string_var(value__b2c__string_var, 2, "="));
#line 3522 "bacon.bac"
} else if( INSTR(arg__b2c__string_var, "SPEED") ){
#line 3523 "bacon.bac"
which=(
long)( 5);
#line 3524 "bacon.bac"
}
#line 3526 "bacon.bac"
if( INSTR(value__b2c__string_var, "~") ){
not__b2c__string_var = __b2c_Copy_String(not__b2c__string_var, (char*) "1");
}
#line 3528 "bacon.bac"
__b2c__assign = (char*)"ERROR = __b2c_setserial("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) desc__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( which), g_CFILE);
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) param__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) value__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) not__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3529 "bacon.bac"
__b2c__assign = (char*)"if(ERROR){ RUNTIMEERROR(\"SETSERIAL\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) ", \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", ERROR, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_CATCHGOTO__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3531 "bacon.bac"
if( __b2c__STRCMP(g_CATCHGOTO__b2c__string_var ,  "__B2C__PROGRAM__EXIT") == 0 ){
g_CATCH_USED=(long)( 1);
}
#line 3533 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(desc__b2c__string_var);
__b2c__STRFREE(value__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
