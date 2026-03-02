/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Color( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0; char *__b2c__select_2852__b2c__string_var = NULL; char *__b2c__select_2866__b2c__string_var = NULL; char *__b2c__select_2883__b2c__string_var = NULL;
#line 2847 "bacon.bac"
char *bfg__b2c__string_var = NULL;
char *col__b2c__string_var = NULL;
long total = 0;
#line 2850 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), "COLOR * TO *", __b2c__option_delim);
total = match__b2c__string_var__b2c_array;
#line 2852 "bacon.bac"
__b2c__select_2852__b2c__string_var = __b2c_Copy_String(__b2c__select_2852__b2c__string_var, match__b2c__string_var[(uint64_t)1]);
#line 2853 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_2852__b2c__string_var, "RESET")){
#line 2854 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[0m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2855 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2852__b2c__string_var, "INTENSE")){
#line 2856 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[1m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2857 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2852__b2c__string_var, "INVERSE")){
#line 2858 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[7m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2859 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2852__b2c__string_var, "NORMAL")){
#line 2860 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[22m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2861 "bacon.bac"
} else {
#line 2862 "bacon.bac"
if( total <= 1 ){
#line 2863 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing TO in COLOR statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2864 "bacon.bac"
exit(1);
#line 2865 "bacon.bac"
} else {
#line 2866 "bacon.bac"
__b2c__select_2866__b2c__string_var = __b2c_Copy_String(__b2c__select_2866__b2c__string_var, match__b2c__string_var[(uint64_t)1]);
#line 2867 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_2866__b2c__string_var, "FG")){
#line 2868 "bacon.bac"
bfg__b2c__string_var = __b2c_Copy_String(bfg__b2c__string_var, (char*) "3");
#line 2869 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2866__b2c__string_var, "BG")){
#line 2870 "bacon.bac"
bfg__b2c__string_var = __b2c_Copy_String(bfg__b2c__string_var, (char*) "4");
#line 2871 "bacon.bac"
} else {
#line 2872 "bacon.bac"
if( REGEX(match__b2c__string_var[(uint64_t)1], "0|1") ){
bfg__b2c__string_var = __b2c_Copy_String(bfg__b2c__string_var, (char*) STR__b2c__string_var(VAL(match__b2c__string_var[(uint64_t)1]) + 3));
}
#line 2873 "bacon.bac"
else {
bfg__b2c__string_var = __b2c_Copy_String(bfg__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)1]);
}
#line 2874 "bacon.bac"
}
#line 2875 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)2], "INTENSE") ){
#line 2876 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[1m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2877 "bacon.bac"
match__b2c__string_var[(uint64_t)2] = __b2c_Copy_String(match__b2c__string_var[(uint64_t)2], (char*) DEL__b2c__string_var(match__b2c__string_var[(uint64_t)2], ISTOKEN(match__b2c__string_var[(uint64_t)2], "INTENSE")));
#line 2878 "bacon.bac"
}
#line 2879 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)2], "NORMAL") ){
#line 2880 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[22m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2881 "bacon.bac"
match__b2c__string_var[(uint64_t)2] = __b2c_Copy_String(match__b2c__string_var[(uint64_t)2], (char*) DEL__b2c__string_var(match__b2c__string_var[(uint64_t)2], ISTOKEN(match__b2c__string_var[(uint64_t)2], "NORMAL")));
#line 2882 "bacon.bac"
}
#line 2883 "bacon.bac"
__b2c__select_2883__b2c__string_var = __b2c_Copy_String(__b2c__select_2883__b2c__string_var, match__b2c__string_var[(uint64_t)2]);
#line 2884 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "BLACK")){
#line 2885 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "0");
#line 2886 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "RED")){
#line 2887 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "1");
#line 2888 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "GREEN")){
#line 2889 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "2");
#line 2890 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "YELLOW")){
#line 2891 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "3");
#line 2892 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "BLUE")){
#line 2893 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "4");
#line 2894 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "MAGENTA")){
#line 2895 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "5");
#line 2896 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "CYAN")){
#line 2897 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "6");
#line 2898 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_2883__b2c__string_var, "WHITE")){
#line 2899 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) "7");
#line 2900 "bacon.bac"
} else {
#line 2901 "bacon.bac"
col__b2c__string_var = __b2c_Copy_String(col__b2c__string_var, (char*) match__b2c__string_var[(uint64_t)2]);
#line 2902 "bacon.bac"
}
#line 2903 "bacon.bac"
__b2c__assign = (char*)"fprintf(stdout,\"\\033[%ld%ldm\", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) bfg__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", (long)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) col__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2904 "bacon.bac"
}
#line 2905 "bacon.bac"
}
#line 2907 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(bfg__b2c__string_var);
__b2c__STRFREE(col__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__STRFREE(__b2c__select_2852__b2c__string_var);
__b2c__STRFREE(__b2c__select_2866__b2c__string_var);
__b2c__STRFREE(__b2c__select_2883__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
