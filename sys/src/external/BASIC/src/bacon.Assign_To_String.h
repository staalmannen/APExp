/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Assign_To_String( char *__b2c_from__b2c__string_var, char *__b2c_to__b2c__string_var, char *__b2c_memsize__b2c__string_var) {
 char*from__b2c__string_var = NULL; from__b2c__string_var = __b2c_Copy_String(NULL, __b2c_from__b2c__string_var); char*to__b2c__string_var = NULL; to__b2c__string_var = __b2c_Copy_String(NULL, __b2c_to__b2c__string_var); char*memsize__b2c__string_var = NULL; memsize__b2c__string_var = __b2c_Copy_String(NULL, __b2c_memsize__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 360 "bacon.bac"
char *lft__b2c__string_var = NULL;
char *str__b2c__string_var = NULL;
#line 362 "bacon.bac"
if( REGEX(to__b2c__string_var, "\\(.*\\)$") ){
#line 363 "bacon.bac"
str__b2c__string_var = __b2c_Copy_String(str__b2c__string_var, (char*) INBETWEEN__b2c__string_var(to__b2c__string_var, "(", ")", 2));
#line 364 "bacon.bac"
lft__b2c__string_var = F_MID__b2c__string_var(lft__b2c__string_var,to__b2c__string_var, 1, INSTR(to__b2c__string_var, "(")-1);
#line 365 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_add_str(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) lft__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 366 "bacon.bac"
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 368 "bacon.bac"
Relate_Recurse(lft__b2c__string_var, str__b2c__string_var, to__b2c__string_var, -1);
#line 369 "bacon.bac"
} else if( Check_String_Type(to__b2c__string_var) ){
#line 370 "bacon.bac"
if( INSTR(to__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 371 "bacon.bac"
__b2c__assign = (char*)to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 372 "bacon.bac"
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 373 "bacon.bac"
} else {
#line 374 "bacon.bac"
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 375 "bacon.bac"
}
#line 376 "bacon.bac"
} else {
#line 377 "bacon.bac"
__b2c__assign = (char*)"memcpy((void*)("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) to__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "), (void*)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) memsize__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); free("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) from__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 378 "bacon.bac"
}
#line 380 "bacon.bac"

__b2c__STRFREE(from__b2c__string_var);
__b2c__STRFREE(to__b2c__string_var);
__b2c__STRFREE(memsize__b2c__string_var);
__b2c__STRFREE(lft__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
