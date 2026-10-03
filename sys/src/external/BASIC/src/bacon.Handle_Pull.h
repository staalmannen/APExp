/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Pull( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 2373 "bacon.bac"
if( AMOUNT(arg__b2c__string_var) == 1 ){
#line 2374 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: empty PULL at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2375 "bacon.bac"
exit(1);
#line 2376 "bacon.bac"
}
#line 2377 "bacon.bac"
arg__b2c__string_var = __b2c_Copy_String(arg__b2c__string_var, (char*) LAST__b2c__string_var(arg__b2c__string_var));
#line 2380 "bacon.bac"
if( NOT(REGEX(arg__b2c__string_var, "^[a-zA-Z]+.*")) ){
#line 2381 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: argument in PULL statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' is not a variable!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2382 "bacon.bac"
exit(1);
#line 2383 "bacon.bac"
}
#line 2386 "bacon.bac"
if( REGEX(arg__b2c__string_var, CONCAT__b2c__string_var( g_STRINGSIGN__b2c__string_var , "$") ) ){
#line 2387 "bacon.bac"
Register_Pointer(arg__b2c__string_var, "char*");
#line 2389 "bacon.bac"
} else {
#line 2390 "bacon.bac"
Register_Numeric(arg__b2c__string_var, "default");
#line 2391 "bacon.bac"
}
#line 2394 "bacon.bac"
__b2c__assign = (char*)"SP--; if(SP >= 0) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2397 "bacon.bac"
if( Check_String_Type(arg__b2c__string_var) ){
#line 2398 "bacon.bac"
Assign_To_String("__b2c__stack[SP]", arg__b2c__string_var, NULL);
#line 2399 "bacon.bac"
} else {
#line 2400 "bacon.bac"
Assign_To_Number("__b2c__stack[SP]", arg__b2c__string_var, 1);
#line 2401 "bacon.bac"
}
#line 2402 "bacon.bac"
__b2c__assign = (char*)"} else { SP = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2404 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
