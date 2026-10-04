/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Print_Element ( char *__b2c_arg__b2c__string_var, char *__b2c_std__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); char*std__b2c__string_var = NULL; std__b2c__string_var = __b2c_Copy_String(NULL, __b2c_std__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 436 "bacon.bac"
if( Check_String_Type(arg__b2c__string_var) ){
#line 437 "bacon.bac"
__b2c__assign = (char*)"__b2c__assign = (char*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; if(__b2c__assign != NULL) { fputs(__b2c__assign, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) std__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 438 "bacon.bac"
} else {
#line 439 "bacon.bac"
__b2c__assign = (char*)"fputs(STR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) arg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) std__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 440 "bacon.bac"
}
#line 442 "bacon.bac"

__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(std__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
