/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Seek( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; char *__b2c__select_2773__b2c__string_var = NULL;
#line 2758 "bacon.bac"
char *descriptor__b2c__string_var = NULL;
char *offset__b2c__string_var = NULL;
char *whence__b2c__string_var = NULL;
long total = 0;
#line 2761 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "OFFSET")) ){
#line 2762 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing OFFSET in SEEK statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2763 "bacon.bac"
exit(1);
#line 2764 "bacon.bac"
}
#line 2767 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "SEEK * OFFSET * WHENCE *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 2768 "bacon.bac"
descriptor__b2c__string_var = __b2c_Copy_String(descriptor__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
#line 2769 "bacon.bac"
offset__b2c__string_var = __b2c_Copy_String(offset__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 2770 "bacon.bac"
whence__b2c__string_var = __b2c_Copy_String(whence__b2c__string_var, (char*) IIF__b2c__string_var((total )> 2, match__b2c__string_var[(uint64_t)3]));
#line 2773 "bacon.bac"
__b2c__select_2773__b2c__string_var = __b2c_Copy_String(__b2c__select_2773__b2c__string_var, whence__b2c__string_var);
#line 2774 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_2773__b2c__string_var, "START")){
#line 2775 "bacon.bac"
__b2c__assign = (char*)"fseek("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) descriptor__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) offset__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", SEEK_SET);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2776 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2773__b2c__string_var, "CURRENT")){
#line 2777 "bacon.bac"
__b2c__assign = (char*)"fseek("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) descriptor__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) offset__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", SEEK_CUR);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2778 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2773__b2c__string_var, "END")){
#line 2779 "bacon.bac"
__b2c__assign = (char*)"fseek("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) descriptor__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) offset__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", SEEK_END);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2780 "bacon.bac"
} else {
#line 2781 "bacon.bac"
__b2c__assign = (char*)"fseek("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) descriptor__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) offset__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", SEEK_SET);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2782 "bacon.bac"
}
#line 2784 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(descriptor__b2c__string_var);
__b2c__STRFREE(offset__b2c__string_var);
__b2c__STRFREE(whence__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__STRFREE(__b2c__select_2773__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
