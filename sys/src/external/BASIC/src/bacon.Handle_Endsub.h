/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Endsub( void) {
 __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; int __b2c__forin_element__b2c__string_var_ptr = 0; char* __b2c__forin_element__b2c__string_var_string = NULL; char* __b2c__forin_element__b2c__string_var_string_org = NULL; char* __b2c__forin_element__b2c__string_var_step = NULL;
#line 2623 "bacon.bac"
FILE* tmp_HFILE = NULL;
#line 2624 "bacon.bac"
char *line__b2c__string_var = NULL;
char *element__b2c__string_var = NULL;
char *tfil__b2c__string_var = NULL;
#line 2627 "bacon.bac"
if( NOT(LEN(g_FUNCNAME__b2c__string_var)) ){
#line 2628 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: ENDSUB outside SUB at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2629 "bacon.bac"
exit(1);
#line 2630 "bacon.bac"
}
#line 2633 "bacon.bac"
fclose(g_CFILE);
#line 2636 "bacon.bac"
if( NOT(INSTR(g_PROTOTYPE__b2c__string_var, "::")) ){
__b2c__assign = (char*)"void "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_PROTOTYPE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) ";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 2637 "bacon.bac"
g_PROTOTYPE__b2c__string_var = __b2c_Copy_String(g_PROTOTYPE__b2c__string_var, (char*) "");
#line 2640 "bacon.bac"
tfil__b2c__string_var = F_MID__b2c__string_var(tfil__b2c__string_var,g_CURFILE__b2c__string_var, INSTRREV(g_CURFILE__b2c__string_var, "/") + 1);
#line 2641 "bacon.bac"
tmp_HFILE = fopen((const char*)CONCAT__b2c__string_var( g_TEMPDIR__b2c__string_var , "/" , LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h" ), "w");
if(tmp_HFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 2641, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2644 "bacon.bac"
__b2c__assign = (char*)"/* Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2645 "bacon.bac"
__b2c__assign = (char*)"#undef __b2c__exitval"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2646 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__exitval"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2647 "bacon.bac"
if( INSTR(g_ORIGFUNCNAME__b2c__string_var, " (") ){
#line 2648 "bacon.bac"
__b2c__assign = (char*)"void "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_ORIGFUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2649 "bacon.bac"
} else if( INSTR(g_ORIGFUNCNAME__b2c__string_var, "(") ){
#line 2650 "bacon.bac"
__b2c__assign = (char*)"void "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_ORIGFUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) " {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2651 "bacon.bac"
} else {
#line 2652 "bacon.bac"
__b2c__assign = (char*)"void "; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) "(void) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2653 "bacon.bac"
}
#line 2656 "bacon.bac"
__b2c__assign = (char*)g_STRINGARGS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2657 "bacon.bac"
g_CFILE = fopen((const char*)g_CFILE__b2c__string_var, "r");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 2657, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2658 "bacon.bac"
while( NOT(ENDFILE(g_CFILE)) ){
#line 2659 "bacon.bac"
__b2c__readln(&__b2c__assign, g_CFILE);
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 2660 "bacon.bac"
if( NOT(ENDFILE(g_CFILE)) ){
__b2c__assign = (char*)line__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
}
#line 2661 "bacon.bac"
}
#line 2662 "bacon.bac"
fclose(g_CFILE);
#line 2665 "bacon.bac"
__b2c__assign = (char*)g_STRINGARRAYS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2666 "bacon.bac"
__b2c__forin_element__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_element__b2c__string_var_string, g_LOCALSTRINGS__b2c__string_var); __b2c__forin_element__b2c__string_var_string_org = __b2c__forin_element__b2c__string_var_string;
__b2c__forin_element__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_element__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_element__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_element__b2c__string_var_string, __b2c__forin_element__b2c__string_var_step);
for(; __b2c__forin_element__b2c__string_var_ptr > 0; __b2c__forin_element__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_element__b2c__string_var_string_org, __b2c__forin_element__b2c__string_var_step, &element__b2c__string_var);
#line 2667 "bacon.bac"
if( (LEN(element__b2c__string_var) )> 0 ){
__b2c__assign = (char*)"__b2c__STRFREE("; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) element__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
}
#line 2668 "bacon.bac"
}
#line 2669 "bacon.bac"
if( g_CATCH_USED == 1 ){
__b2c__assign = (char*)"__B2C__PROGRAM__EXIT: ;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
}
#line 2670 "bacon.bac"
__b2c__assign = (char*)"__b2c__catch_set = __b2c__catch_set_backup;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2671 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, tmp_HFILE); }
fputs("\n", tmp_HFILE);
#line 2673 "bacon.bac"
fclose(tmp_HFILE);
#line 2676 "bacon.bac"
if( NOT(INSTR(g_INCLUDE_FILES__b2c__string_var, CONCAT__b2c__string_var( LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h") )) ){
#line 2677 "bacon.bac"
g_INCLUDE_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCLUDE_FILES__b2c__string_var, g_INCLUDE_FILES__b2c__string_var , " " , LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h") ;
#line 2678 "bacon.bac"
}
#line 2681 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_TEMPDIR__b2c__string_var , "/" , LEFT__b2c__string_var(tfil__b2c__string_var, INSTR(tfil__b2c__string_var, ".bac")) , g_FUNCNAME__b2c__string_var , ".h") ;
#line 2684 "bacon.bac"
if(unlink(g_CFILE__b2c__string_var)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 2684, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2687 "bacon.bac"
g_CFILE__b2c__string_var = __b2c_Copy_String(g_CFILE__b2c__string_var, (char*) g_COPY_CFILE__b2c__string_var);
#line 2688 "bacon.bac"
g_CFILE = fopen((const char*)g_CFILE__b2c__string_var, "a");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR APPENDING", 2688, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 2691 "bacon.bac"
g_CATCHGOTO__b2c__string_var = __b2c_Copy_String(g_CATCHGOTO__b2c__string_var, (char*) g_ORIGCATCHGOTO__b2c__string_var);
#line 2692 "bacon.bac"
g_CATCH_USED=(long)( g_ORIGCATCH_USED);
#line 2695 "bacon.bac"
g_ORIGFUNCNAME__b2c__string_var = __b2c_Copy_String(g_ORIGFUNCNAME__b2c__string_var, (char*) "");
#line 2696 "bacon.bac"
g_FUNCNAME__b2c__string_var = __b2c_Copy_String(g_FUNCNAME__b2c__string_var, (char*) "");
#line 2697 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = __b2c_Copy_String(g_LOCALSTRINGS__b2c__string_var, (char*) "");
#line 2698 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = __b2c_Copy_String(g_STRINGARRAYS__b2c__string_var, (char*) "");
#line 2699 "bacon.bac"
g_STRINGARGS__b2c__string_var = __b2c_Copy_String(g_STRINGARGS__b2c__string_var, (char*) "");
#line 2701 "bacon.bac"
 __b2c__STRFREE(__b2c__forin_element__b2c__string_var_string); __b2c__forin_element__b2c__string_var_string = NULL; __b2c__STRFREE(__b2c__forin_element__b2c__string_var_step); __b2c__forin_element__b2c__string_var_step = NULL;
__b2c__STRFREE(line__b2c__string_var);
__b2c__STRFREE(element__b2c__string_var);
__b2c__STRFREE(tfil__b2c__string_var);
__B2C__PROGRAM__EXIT: ;
__b2c__catch_set = __b2c__catch_set_backup;
}
