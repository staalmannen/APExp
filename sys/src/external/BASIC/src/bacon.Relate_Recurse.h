/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Relate_Recurse( char *__b2c_var__b2c__string_var, char *__b2c_str__b2c__string_var, char *__b2c_tmp__b2c__string_var, NUMBER lvl) {
 char*var__b2c__string_var = NULL; var__b2c__string_var = __b2c_Copy_String(NULL, __b2c_var__b2c__string_var); char*str__b2c__string_var = NULL; str__b2c__string_var = __b2c_Copy_String(NULL, __b2c_str__b2c__string_var); char*tmp__b2c__string_var = NULL; tmp__b2c__string_var = __b2c_Copy_String(NULL, __b2c_tmp__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0;
#line 658 "bacon.bac"
char *rel__b2c__string_var = NULL;
long ctr = 0;
#line 661 "bacon.bac"
lvl = lvl + (1);
#line 662 "bacon.bac"
if( (lvl )> g_RELATE_CTR ){
#line 663 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: endless recursion in RELATE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 664 "bacon.bac"
exit(1);
#line 665 "bacon.bac"
}
#line 668 "bacon.bac"
for(ctr=0; ctr <= g_RELATE_CTR; ctr+=1){
#line 669 "bacon.bac"
if( __b2c__STRCMP(TOKEN__b2c__string_var(g_RELATE__b2c__string_var[(uint64_t)ctr], 1) ,  var__b2c__string_var) == 0 ){
#line 670 "bacon.bac"
rel__b2c__string_var = __b2c_Copy_String(rel__b2c__string_var, (char*) TOKEN__b2c__string_var(g_RELATE__b2c__string_var[(uint64_t)ctr], 2));
#line 671 "bacon.bac"
if( INSTR(rel__b2c__string_var, g_STRINGSIGN__b2c__string_var) ){
#line 672 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_add_str(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) rel__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 673 "bacon.bac"
} else {
#line 674 "bacon.bac"
__b2c__assign = (char*)"__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) rel__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval = " ; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) tmp__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "; __b2c__hash_add(__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) rel__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", &__b2c__assoc_"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) rel__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "_eval, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) str__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 675 "bacon.bac"
}
#line 676 "bacon.bac"
Relate_Recurse(rel__b2c__string_var, str__b2c__string_var, tmp__b2c__string_var, lvl);
#line 677 "bacon.bac"
}
#line 678 "bacon.bac"
}
#line 680 "bacon.bac"

__b2c__STRFREE(var__b2c__string_var);
__b2c__STRFREE(str__b2c__string_var);
__b2c__STRFREE(tmp__b2c__string_var);
__b2c__STRFREE(rel__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
