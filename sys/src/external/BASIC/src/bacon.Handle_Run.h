/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Run( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 3586 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 3587 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty RUN at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 3588 "bacon.bac"
exit(1);
#line 3589 "bacon.bac"
}
#line 3590 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 3592 "bacon.bac"
if( TALLY(arg__b2c__string_var, CHR__b2c__string_var(34)) ){
#line 3593 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) EXTRACT__b2c__string_var(arg__b2c__string_var, CHR__b2c__string_var(34)));
#line 3594 "bacon.bac"
__b2c__assign = (char*)"execlp("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) TOKEN__b2c__string_var(arg__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", NULL); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3595 "bacon.bac"
} else {
#line 3596 "bacon.bac"
__b2c__assign = (char*)"execlp("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", NULL); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 3597 "bacon.bac"
}
#line 3599 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
