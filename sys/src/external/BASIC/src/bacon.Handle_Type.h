/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#undef __b2c__exitval
#define __b2c__exitval
void Handle_Type( char *__b2c_arg__b2c__string_var) {
 char*arg__b2c__string_var = NULL; arg__b2c__string_var = __b2c_Copy_String(NULL, __b2c_arg__b2c__string_var); __b2c__catch_set_backup = __b2c__catch_set; __b2c__catch_set = 0; char **match__b2c__string_var = NULL; long match__b2c__string_var__b2c_array = 0;
#line 2913 "bacon.bac"
char *type__b2c__string_var = NULL;
long offset = 0;
long cfg = 0;
#line 2916 "bacon.bac"
if( NOT(ISTOKEN(arg__b2c__string_var, "SET"))  AND  NOT(ISTOKEN(arg__b2c__string_var, "UNSET"))  AND  NOT(ISTOKEN(arg__b2c__string_var, "RESET")) ){
#line 2917 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: missing SET/UNSET/RESET in TYPE statement at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2918 "bacon.bac"
exit(1);
#line 2919 "bacon.bac"
}
#line 2922 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "RESET") ){
#line 2923 "bacon.bac"
__b2c__assign = (char*)"fputs(\"\\033[21m\\033[23m\\033[24m\\033[25m\\033[27m\\033[29m\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2924 "bacon.bac"
} else {
#line 2925 "bacon.bac"
if( ISTOKEN(arg__b2c__string_var, "UNSET") ){
offset=(
long)( 20);
}
#line 2926 "bacon.bac"
__b2c__parse(&match__b2c__string_var, 1, &match__b2c__string_var__b2c_array, COLLAPSE__b2c__string_var(arg__b2c__string_var), CONCAT__b2c__string_var( "TYPE " , IIF__b2c__string_var(ISTOKEN(arg__b2c__string_var, "SET"), "SET", "UNSET") , " *" ), __b2c__option_delim);
#line 2927 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)1], "BOLD") ){
#line 2928 "bacon.bac"
cfg=(
long)( 1 + offset);
#line 2929 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "\\033[" , STR__b2c__string_var(cfg) , "m") ;
#line 2930 "bacon.bac"
}
#line 2931 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)1], "ITALIC") ){
#line 2932 "bacon.bac"
cfg=(
long)( 3 + offset);
#line 2933 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "\\033[" , STR__b2c__string_var(cfg) , "m") ;
#line 2934 "bacon.bac"
}
#line 2935 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)1], "UNDERLINE") ){
#line 2936 "bacon.bac"
cfg=(
long)( 4 + offset);
#line 2937 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "\\033[" , STR__b2c__string_var(cfg) , "m") ;
#line 2938 "bacon.bac"
}
#line 2939 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)1], "BLINK") ){
#line 2940 "bacon.bac"
cfg=(
long)( 5 + offset);
#line 2941 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "\\033[" , STR__b2c__string_var(cfg) , "m") ;
#line 2942 "bacon.bac"
}
#line 2943 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)1], "INVERSE") ){
#line 2944 "bacon.bac"
cfg=(
long)( 7 + offset);
#line 2945 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "\\033[" , STR__b2c__string_var(cfg) , "m") ;
#line 2946 "bacon.bac"
}
#line 2947 "bacon.bac"
if( ISTOKEN(match__b2c__string_var[(uint64_t)1], "STRIKE") ){
#line 2948 "bacon.bac"
cfg=(
long)( 9 + offset);
#line 2949 "bacon.bac"
type__b2c__string_var = F_CONCAT__b2c__string_var(type__b2c__string_var, type__b2c__string_var , "\\033[" , STR__b2c__string_var(cfg) , "m") ;
#line 2950 "bacon.bac"
}
#line 2951 "bacon.bac"
if( NOT(LEN(type__b2c__string_var)) ){
#line 2952 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "Syntax error: argument in TYPE statement not recognized at line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs(STR__b2c__string_var( g_COUNTER), stderr);
__b2c__assign = (char*) " in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 2953 "bacon.bac"
exit(1);
#line 2954 "bacon.bac"
}
#line 2955 "bacon.bac"
__b2c__assign = (char*)"fputs(\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) type__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\", stdout); fflush(stdout);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 2956 "bacon.bac"
}
#line 2958 "bacon.bac"
 __b2c__free_str_array_members(&match__b2c__string_var, 1, match__b2c__string_var__b2c_array);
__b2c__STRFREE(arg__b2c__string_var);
__b2c__STRFREE(type__b2c__string_var);
__b2c__STRFREE(match__b2c__string_var);
__b2c__catch_set = __b2c__catch_set_backup;
}
