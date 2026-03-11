/* Created with Shell BaCon 5.0.3 - (c) Peter van Eerten - MIT License */
#include "bacon.bac.h"
#include "bacon.bac.string.h"
#include "bacon.bac.float.h"
/****************************/
/* Main program starts here */
/****************************/
int main(int argc, char **argv){
setvbuf(stdout, NULL, _IOLBF, 0);
atexit(__b2c_str_free);
__b2c__set_stack_size();
if(argc>0) { __b2c__me_var__b2c__string_var = __b2c_Copy_String(__b2c__me_var__b2c__string_var, argv[0]); }
if(argc==2 && !strncmp(argv[1], "-bacon", 6)) { fprintf(stderr, "Converted by %s.\n", COMPILED_BY_WHICH_BACON__b2c__string_var); exit(EXIT_SUCCESS); }
/* Setup the reserved variable 'ARGUMENT' */
__b2c__argument(&ARGUMENT__b2c__string_var, argc, argv);
/* By default seed random generator */
srandom((unsigned int)time(NULL));
/* Determine current moment and keep it for timer function */
__b2c__nanotimer(1); __b2c__timer(1);
/* Setup error signal handling */
signal(SIGILL, __b2c__catch_signal);
signal(SIGABRT, __b2c__catch_signal);
signal(SIGFPE, __b2c__catch_signal);
signal(SIGSEGV, __b2c__catch_signal);
/* Rest of the program */
#line 21 "bacon.bac"
#line 24 "bacon.bac"
__b2c__collapse = TRUE;
#line 27 "bacon.bac"
#line 30 "bacon.bac"
SETENVIRON("LC_NUMERIC", "POSIX");
#line 33 "bacon.bac"
if( __b2c__STRCMP(VERSION__b2c__string_var ,  g_VERSION__b2c__string_var) != 0 ){
#line 34 "bacon.bac"
__b2c__assign = (char*)"System error: this BaCon binary was compiled with a previous BaCon version and therefore may not function correctly."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 35 "bacon.bac"
__b2c__assign = (char*)"Recompile BaCon with the Shell implementation version "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 36 "bacon.bac"
exit(1);
#line 37 "bacon.bac"
}
#line 40 "bacon.bac"
if( TALLY(OS__b2c__string_var, "SunOS") ){
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) "-lnsl -lsocket");
}
#line 43 "bacon.bac"
if( TALLY(OS__b2c__string_var, "Haiku") ){
g_LDFLAGS__b2c__string_var = __b2c_Copy_String(g_LDFLAGS__b2c__string_var, (char*) "-lbsd -lnetwork");
}
#line 46 "bacon.bac"
if( ISTRUE(LEN(EXEC__b2c__string_var("command -v objdump 2>/dev/null"))) ){
#line 47 "bacon.bac"
if( INSTR(EXEC__b2c__string_var( CONCAT__b2c__string_var("objdump -p $(command -v " , ME__b2c__string_var , ")") ), "musl") ){
#line 48 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " -lfts") ;
#line 49 "bacon.bac"
}
#line 50 "bacon.bac"
}
#line 53 "bacon.bac"
#line 54 "bacon.bac"
#line 55 "bacon.bac"
#line 56 "bacon.bac"
#line 57 "bacon.bac"
#line 60 "bacon.bac"
#line 62 "bacon.bac"
#line 64 "bacon.bac"
#line 67 "bacon.bac"
#line 70 "bacon.bac"
__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var = __b2c__hash_new();
__b2c__assoc_g_ALL_FUNC_VARS__b2c__string_var = __b2c__hash_new();
__b2c__assoc_g_ALL_DIM_VARS__b2c__string_var = __b2c__hash_new();
__b2c__assoc_g_SEMANTIC_MEMFREE__b2c__string_var = __b2c__hash_new();
__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var = __b2c__hash_new();
__b2c__assoc_g_MACRO_STRINGS__b2c__string_var = __b2c__hash_new();
#line 74 "bacon.bac"
#line 120 "bacon.bac"
#line 152 "bacon.bac"
#line 180 "bacon.bac"
#line 210 "bacon.bac"
#line 257 "bacon.bac"
#line 282 "bacon.bac"
#line 324 "bacon.bac"
#line 358 "bacon.bac"
#line 384 "bacon.bac"
#line 433 "bacon.bac"
#line 446 "bacon.bac"
#line 508 "bacon.bac"
#line 562 "bacon.bac"
#line 642 "bacon.bac"
#line 656 "bacon.bac"
#line 684 "bacon.bac"
#line 830 "bacon.bac"
#line 929 "bacon.bac"
#line 961 "bacon.bac"
#line 994 "bacon.bac"
#line 1049 "bacon.bac"
#line 1104 "bacon.bac"
#line 1147 "bacon.bac"
#line 1208 "bacon.bac"
#line 1258 "bacon.bac"
#line 1290 "bacon.bac"
#line 1324 "bacon.bac"
#line 1403 "bacon.bac"
#line 1524 "bacon.bac"
#line 1562 "bacon.bac"
#line 1607 "bacon.bac"
#line 1800 "bacon.bac"
#line 2147 "bacon.bac"
#line 2184 "bacon.bac"
#line 2278 "bacon.bac"
#line 2343 "bacon.bac"
#line 2370 "bacon.bac"
#line 2408 "bacon.bac"
#line 2621 "bacon.bac"
#line 2705 "bacon.bac"
#line 2732 "bacon.bac"
#line 2756 "bacon.bac"
#line 2788 "bacon.bac"
#line 2822 "bacon.bac"
#line 2845 "bacon.bac"
#line 2911 "bacon.bac"
#line 2962 "bacon.bac"
#line 2989 "bacon.bac"
#line 3064 "bacon.bac"
#line 3115 "bacon.bac"
#line 3199 "bacon.bac"
#line 3222 "bacon.bac"
#line 3316 "bacon.bac"
#line 3351 "bacon.bac"
#line 3386 "bacon.bac"
#line 3431 "bacon.bac"
#line 3489 "bacon.bac"
#line 3537 "bacon.bac"
#line 3583 "bacon.bac"
#line 3603 "bacon.bac"
#line 3633 "bacon.bac"
#line 3738 "bacon.bac"
#line 3784 "bacon.bac"
#line 3861 "bacon.bac"
#line 3938 "bacon.bac"
#line 4205 "bacon.bac"
#line 5963 "bacon.bac"
#line 6253 "bacon.bac"
#line 6544 "bacon.bac"
#line 6831 "bacon.bac"
#line 6920 "bacon.bac"
#line 7039 "bacon.bac"
#line 7082 "bacon.bac"
#line 7100 "bacon.bac"
#line 7140 "bacon.bac"
#line 7916 "bacon.bac"
g_MAX_DIGITS=(long)( 32);
#line 7919 "bacon.bac"
g_BUFFER_SIZE=(long)( 512);
#line 7922 "bacon.bac"
g_MAX_RBUFFERS=(long)( 64);
#line 7925 "bacon.bac"
g_CCNAME__b2c__string_var = __b2c_Copy_String(g_CCNAME__b2c__string_var, (char*) "");
#line 7926 "bacon.bac"
g_TEMPDIR__b2c__string_var = __b2c_Copy_String(g_TEMPDIR__b2c__string_var, (char*) "");
#line 7927 "bacon.bac"
g_INCFILES__b2c__string_var = __b2c_Copy_String(g_INCFILES__b2c__string_var, (char*) "");
#line 7928 "bacon.bac"
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) "");
#line 7929 "bacon.bac"
g_BINEXT__b2c__string_var = __b2c_Copy_String(g_BINEXT__b2c__string_var, (char*) "");
#line 7931 "bacon.bac"
g_CCNAME_TMP__b2c__string_var = __b2c_Copy_String(g_CCNAME_TMP__b2c__string_var, (char*) "");
#line 7932 "bacon.bac"
g_TEMPDIR_TMP__b2c__string_var = __b2c_Copy_String(g_TEMPDIR_TMP__b2c__string_var, (char*) "");
#line 7933 "bacon.bac"
g_INCFILES_TMP__b2c__string_var = __b2c_Copy_String(g_INCFILES_TMP__b2c__string_var, (char*) "");
#line 7934 "bacon.bac"
g_LDFLAGS_TMP__b2c__string_var = __b2c_Copy_String(g_LDFLAGS_TMP__b2c__string_var, (char*) "");
#line 7935 "bacon.bac"
g_CCFLAGS_TMP__b2c__string_var = __b2c_Copy_String(g_CCFLAGS_TMP__b2c__string_var, (char*) "");
#line 7937 "bacon.bac"
g_NO_COMPILE=(long)( 0);
#line 7938 "bacon.bac"
g_TMP_PRESERVE=(long)( 0);
#line 7939 "bacon.bac"
g_QUIET=(long)( 0);
#line 7940 "bacon.bac"
g_EXEC=(long)( 0);
#line 7941 "bacon.bac"
g_SEMANTIC=(long)( 0);
#line 7942 "bacon.bac"
g_NO_QUESTION=(long)( 0);
#line 7943 "bacon.bac"
g_CPP=(long)( 0);
#line 7944 "bacon.bac"
g_XGETTEXT=(long)( 0);
#line 7945 "bacon.bac"
g_SAVE_CONFIG=(long)( 0);
#line 7946 "bacon.bac"
g_DEBUG=(long)( 0);
#line 7947 "bacon.bac"
g_LOWERCASE=(long)( 0);
#line 7949 "bacon.bac"
g_USE_C=(long)( 0);
#line 7950 "bacon.bac"
g_USE_H=(long)( 0);
#line 7951 "bacon.bac"
g_MAX_BACKLOG=(long)( 5);
#line 7953 "bacon.bac"
g_INCLUDE_FILES__b2c__string_var = __b2c_Copy_String(g_INCLUDE_FILES__b2c__string_var, (char*) "");
#line 7954 "bacon.bac"
g_PRAGMA_INCLUDE__b2c__string_var = __b2c_Copy_String(g_PRAGMA_INCLUDE__b2c__string_var, (char*) "");
#line 7955 "bacon.bac"
g_PRAGMA_REGEX__b2c__string_var = __b2c_Copy_String(g_PRAGMA_REGEX__b2c__string_var, (char*) "");
#line 7956 "bacon.bac"
g_TRACE=(long)( 0);
#line 7957 "bacon.bac"
g_OPTION_BASE=(long)( 0);
#line 7958 "bacon.bac"
g_OPTION_SOCKET=(long)( 5);
#line 7959 "bacon.bac"
g_OPTION_TLS=(long)( 0);
#line 7960 "bacon.bac"
g_OPTION_EVAL=(long)( 0);
#line 7961 "bacon.bac"
g_INC_TLS__b2c__string_var = __b2c_Copy_String(g_INC_TLS__b2c__string_var, (char*) "");
#line 7962 "bacon.bac"
g_LIB_TLS__b2c__string_var = __b2c_Copy_String(g_LIB_TLS__b2c__string_var, (char*) "");
#line 7963 "bacon.bac"
g_WHICH_GUI=(long)( 0);
#line 7964 "bacon.bac"
g_OPTION_BREAK=(long)( 1);
#line 7965 "bacon.bac"
g_OPTION_DISABLE_C_ESCAPE=(long)( 0);
#line 7968 "bacon.bac"
g_CURFILE__b2c__string_var = __b2c_Copy_String(g_CURFILE__b2c__string_var, (char*) "");
#line 7969 "bacon.bac"
g_FUNCNAME__b2c__string_var = __b2c_Copy_String(g_FUNCNAME__b2c__string_var, (char*) "");
#line 7970 "bacon.bac"
g_SOURCEFILE__b2c__string_var = __b2c_Copy_String(g_SOURCEFILE__b2c__string_var, (char*) "");
#line 7971 "bacon.bac"
g_FUNCTYPE__b2c__string_var = __b2c_Copy_String(g_FUNCTYPE__b2c__string_var, (char*) "");
#line 7972 "bacon.bac"
g_PROTOTYPE__b2c__string_var = __b2c_Copy_String(g_PROTOTYPE__b2c__string_var, (char*) "");
#line 7973 "bacon.bac"
g_TMP_FILES__b2c__string_var = __b2c_Copy_String(g_TMP_FILES__b2c__string_var, (char*) "");
#line 7974 "bacon.bac"
g_LOCALSTRINGS__b2c__string_var = __b2c_Copy_String(g_LOCALSTRINGS__b2c__string_var, (char*) "");
#line 7975 "bacon.bac"
g_STRINGARRAYS__b2c__string_var = __b2c_Copy_String(g_STRINGARRAYS__b2c__string_var, (char*) "");
#line 7976 "bacon.bac"
g_GLOBALARRAYS__b2c__string_var = __b2c_Copy_String(g_GLOBALARRAYS__b2c__string_var, (char*) "");
#line 7977 "bacon.bac"
g_STRINGARGS__b2c__string_var = __b2c_Copy_String(g_STRINGARGS__b2c__string_var, (char*) "");
#line 7978 "bacon.bac"
g_DYNAMICARRAYS__b2c__string_var = __b2c_Copy_String(g_DYNAMICARRAYS__b2c__string_var, (char*) "");
#line 7979 "bacon.bac"
g_STATICARRAYS__b2c__string_var = __b2c_Copy_String(g_STATICARRAYS__b2c__string_var, (char*) "");
#line 7980 "bacon.bac"
g_RECORDCACHE__b2c__string_var = __b2c_Copy_String(g_RECORDCACHE__b2c__string_var, (char*) "");
#line 7981 "bacon.bac"
g_LOOPCTR=(long)( 0);
#line 7982 "bacon.bac"
g_ERRORTXT__b2c__string_var = __b2c_Copy_String(g_ERRORTXT__b2c__string_var, (char*) "");
#line 7983 "bacon.bac"
g_COMMENT=(long)( FALSE);
#line 7984 "bacon.bac"
g_TRACE_PREFIX__b2c__string_var = __b2c_Copy_String(g_TRACE_PREFIX__b2c__string_var, (char*) "");
#line 7985 "bacon.bac"
g_IGNORE_PARSE__b2c__string_var = __b2c_Copy_String(g_IGNORE_PARSE__b2c__string_var, (char*) "TRUE");
#line 7986 "bacon.bac"
g_PRIORITY__b2c__string_var = __b2c_Copy_String(g_PRIORITY__b2c__string_var, (char*) "\"NORMAL:-VERS-TLS1.3:%COMPAT\"");
#line 7987 "bacon.bac"
g_OPTION_EXPLICIT__b2c__string_var = __b2c_Copy_String(g_OPTION_EXPLICIT__b2c__string_var, (char*) "FALSE");
#line 7988 "bacon.bac"
g_OPTION_LOCAL__b2c__string_var = __b2c_Copy_String(g_OPTION_LOCAL__b2c__string_var, (char*) "FALSE");
#line 7989 "bacon.bac"
g_OPTION_INPUT__b2c__string_var = __b2c_Copy_String(g_OPTION_INPUT__b2c__string_var, (char*) "\"\\n\"");
#line 7990 "bacon.bac"
g_VARTYPE__b2c__string_var = __b2c_Copy_String(g_VARTYPE__b2c__string_var, (char*) "long");
#line 7991 "bacon.bac"
g_OBJ_FILES__b2c__string_var = __b2c_Copy_String(g_OBJ_FILES__b2c__string_var, (char*) "");
#line 7992 "bacon.bac"
g_MAKE_LINE__b2c__string_var = __b2c_Copy_String(g_MAKE_LINE__b2c__string_var, (char*) "");
#line 7993 "bacon.bac"
g_MONITOR__b2c__string_var = __b2c_Copy_String(g_MONITOR__b2c__string_var, (char*) "");
#line 7994 "bacon.bac"
g_STRING_FUNC=(long)( 1);
#line 7995 "bacon.bac"
g_DOTIMES=(long)( 0);
#line 7996 "bacon.bac"
g_LOCAL_SBUFFER__b2c__string_var = __b2c_Copy_String(g_LOCAL_SBUFFER__b2c__string_var, (char*) "");
#line 7997 "bacon.bac"
g_TWEAK__b2c__string_var = __b2c_Copy_String(g_TWEAK__b2c__string_var, (char*) "");
#line 7998 "bacon.bac"
g_DEPEND__b2c__string_var = __b2c_Copy_String(g_DEPEND__b2c__string_var, (char*) "");
#line 8001 "bacon.bac"
g_CATCHGOTO__b2c__string_var = __b2c_Copy_String(g_CATCHGOTO__b2c__string_var, (char*) "__B2C__PROGRAM__EXIT");
#line 8002 "bacon.bac"
g_CATCH_USED=(long)( 0);
#line 8005 "bacon.bac"
g_RECORDNAME__b2c__string_var = __b2c_Copy_String(g_RECORDNAME__b2c__string_var, (char*) "");
#line 8006 "bacon.bac"
g_RECORDVAR__b2c__string_var = __b2c_Copy_String(g_RECORDVAR__b2c__string_var, (char*) "");
#line 8007 "bacon.bac"
g_RECORDARRAY__b2c__string_var = __b2c_Copy_String(g_RECORDARRAY__b2c__string_var, (char*) "");
#line 8008 "bacon.bac"
g_WITHVAR__b2c__string_var = __b2c_Copy_String(g_WITHVAR__b2c__string_var, (char*) "");
#line 8009 "bacon.bac"
g_RECORDEND_BODY__b2c__string_var = __b2c_Copy_String(g_RECORDEND_BODY__b2c__string_var, (char*) "");
#line 8010 "bacon.bac"
g_RECORDEND_HEADER__b2c__string_var = __b2c_Copy_String(g_RECORDEND_HEADER__b2c__string_var, (char*) "");
#line 8013 "bacon.bac"
g_SOCKTYPE__b2c__string_var = __b2c_Copy_String(g_SOCKTYPE__b2c__string_var, (char*) "SOCK_STREAM");
#line 8014 "bacon.bac"
g_NETWORKTYPE__b2c__string_var = __b2c_Copy_String(g_NETWORKTYPE__b2c__string_var, (char*) "TCP");
#line 8015 "bacon.bac"
g_MULTICAST_TTL=(long)( 1);
#line 8016 "bacon.bac"
g_SCTP_STREAMS=(long)( 1);
#line 8019 "bacon.bac"
#line 8020 "bacon.bac"
#line 8021 "bacon.bac"
g_SELECTVAR_CTR=(long)( 0);
#line 8024 "bacon.bac"
#line 8025 "bacon.bac"
g_RELATE_CTR=(long)( 0);
#line 8027 "bacon.bac"
g_FCTR=(long)( 0);
#line 8028 "bacon.bac"
g_CCTR=(long)( 0);
#line 8031 "bacon.bac"
g_CURSOR_X=(long)( 0);
#line 8032 "bacon.bac"
g_CURSOR_Y=(long)( 0);
#line 8035 "bacon.bac"
#line 8036 "bacon.bac"
#line 8039 "bacon.bac"
if( NOT(FILEEXISTS( CONCAT__b2c__string_var(GETENVIRON__b2c__string_var("HOME") , "/.bacon/") )) ){
ERROR = __b2c__makedir(CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/")); if(ERROR) { RUNTIMEERROR("MAKEDIR", 8039, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
}
#line 8041 "bacon.bac"
if( FILEEXISTS( CONCAT__b2c__string_var(GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg" ) ) ){
#line 8042 "bacon.bac"
cfgfile = fopen((const char*)CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg" ), "r");
if(cfgfile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8042, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8043 "bacon.bac"
while( NOT(ENDFILE(cfgfile)) ){
#line 8044 "bacon.bac"
__b2c__readln(&__b2c__assign, cfgfile);
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 8045 "bacon.bac"
__b2c__select_8045__b2c__string_var = __b2c_Copy_String(__b2c__select_8045__b2c__string_var, TOKEN__b2c__string_var(line__b2c__string_var, 1));
#line 8046 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "ccname")){
#line 8047 "bacon.bac"
g_CCNAME_TMP__b2c__string_var = __b2c_Copy_String(g_CCNAME_TMP__b2c__string_var, (char*) TOKEN__b2c__string_var(line__b2c__string_var, 2));
#line 8048 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "tempdir")){
#line 8049 "bacon.bac"
g_TEMPDIR_TMP__b2c__string_var = __b2c_Copy_String(g_TEMPDIR_TMP__b2c__string_var, (char*) TOKEN__b2c__string_var(line__b2c__string_var, 2));
#line 8050 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "incfiles")){
#line 8051 "bacon.bac"
g_INCFILES_TMP__b2c__string_var = __b2c_Copy_String(g_INCFILES_TMP__b2c__string_var, (char*) TOKEN__b2c__string_var(line__b2c__string_var, 2));
#line 8052 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "ldflags")){
#line 8053 "bacon.bac"
g_LDFLAGS_TMP__b2c__string_var = __b2c_Copy_String(g_LDFLAGS_TMP__b2c__string_var, (char*) TOKEN__b2c__string_var(line__b2c__string_var, 2));
#line 8054 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "ccflags")){
#line 8055 "bacon.bac"
g_CCFLAGS_TMP__b2c__string_var = __b2c_Copy_String(g_CCFLAGS_TMP__b2c__string_var, (char*) TOKEN__b2c__string_var(line__b2c__string_var, 2));
#line 8056 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "lowercase")){
#line 8057 "bacon.bac"
g_LOWERCASE_TMP=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8058 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "intense")){
#line 8059 "bacon.bac"
Color_Intense=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8060 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "linenr")){
#line 8061 "bacon.bac"
Line_Number_Active=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8062 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "default_color")){
#line 8063 "bacon.bac"
Def_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8064 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "function_color")){
#line 8065 "bacon.bac"
Func_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8066 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "quote_color")){
#line 8067 "bacon.bac"
Quot_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8068 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "number_color")){
#line 8069 "bacon.bac"
Num_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8070 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "type_color")){
#line 8071 "bacon.bac"
Type_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8072 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "variable_color")){
#line 8073 "bacon.bac"
Var_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8074 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "statement_color")){
#line 8075 "bacon.bac"
Stat_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8076 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8045__b2c__string_var, "comment_color")){
#line 8077 "bacon.bac"
Comm_Col=(long)( VAL(TOKEN__b2c__string_var(line__b2c__string_var, 2)));
#line 8078 "bacon.bac"
}
#line 8079 "bacon.bac"
}
#line 8080 "bacon.bac"
fclose(cfgfile);
#line 8081 "bacon.bac"
}
#line 8083 "bacon.bac"
do{
#line 8084 "bacon.bac"
opt=(long)( CMDLINE(":c:d:i:l:o:t:e:xnjfpqrsvwyz@"));
#line 8085 "bacon.bac"
__b2c__select_8085 = (double)opt;
#line 8087 "bacon.bac"
 if ( (__b2c__select_8085) == (99)){
#line 8088 "bacon.bac"
g_CCNAME__b2c__string_var = __b2c_Copy_String(g_CCNAME__b2c__string_var, (char*) ARGUMENT__b2c__string_var);
#line 8091 "bacon.bac"
} else  if ( (__b2c__select_8085) == (105)){
#line 8092 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(ARGUMENT__b2c__string_var) ,  "/") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(ARGUMENT__b2c__string_var, 2) ,  "./") == 0 ){
#line 8093 "bacon.bac"
g_INCFILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCFILES__b2c__string_var, g_INCFILES__b2c__string_var , "#include " , CHR__b2c__string_var(34) , ARGUMENT__b2c__string_var , CHR__b2c__string_var(34)) ;
#line 8094 "bacon.bac"
} else if( __b2c__STRCMP(LEFT__b2c__string_var(ARGUMENT__b2c__string_var) ,  "<") == 0 ){
#line 8095 "bacon.bac"
g_INCFILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCFILES__b2c__string_var, g_INCFILES__b2c__string_var , "#include " , ARGUMENT__b2c__string_var) ;
#line 8096 "bacon.bac"
} else {
#line 8097 "bacon.bac"
g_INCFILES__b2c__string_var = F_CONCAT__b2c__string_var(g_INCFILES__b2c__string_var, g_INCFILES__b2c__string_var , "#include " , CHR__b2c__string_var(34) , CURDIR__b2c__string_var , "/" , ARGUMENT__b2c__string_var , CHR__b2c__string_var(34)) ;
#line 8098 "bacon.bac"
}
#line 8101 "bacon.bac"
} else  if ( (__b2c__select_8085) == (108)){
#line 8102 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(ARGUMENT__b2c__string_var, 1) ,  "`") == 0  OR  __b2c__STRCMP(LEFT__b2c__string_var(ARGUMENT__b2c__string_var, 1) ,  "-") == 0 ){
#line 8103 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, ARGUMENT__b2c__string_var , " " , g_LDFLAGS__b2c__string_var) ;
#line 8104 "bacon.bac"
} else {
#line 8105 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, "-l" , ARGUMENT__b2c__string_var , " " , g_LDFLAGS__b2c__string_var) ;
#line 8106 "bacon.bac"
}
#line 8109 "bacon.bac"
} else  if ( (__b2c__select_8085) == (111)){
#line 8110 "bacon.bac"
g_CCFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_CCFLAGS__b2c__string_var, g_CCFLAGS__b2c__string_var , " " , ARGUMENT__b2c__string_var) ;
#line 8113 "bacon.bac"
} else  if ( (__b2c__select_8085) == (100)){
#line 8114 "bacon.bac"
if( NOT(FILEEXISTS(ARGUMENT__b2c__string_var)) ){
ERROR = __b2c__makedir(ARGUMENT__b2c__string_var); if(ERROR) { RUNTIMEERROR("MAKEDIR", 8114, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
}
#line 8115 "bacon.bac"
g_TEMPDIR__b2c__string_var = __b2c_Copy_String(g_TEMPDIR__b2c__string_var, (char*) ARGUMENT__b2c__string_var);
#line 8118 "bacon.bac"
} else  if ( (__b2c__select_8085) == (116)){
#line 8119 "bacon.bac"
__b2c__select_8119__b2c__string_var = __b2c_Copy_String(__b2c__select_8119__b2c__string_var, LCASE__b2c__string_var(TOKEN__b2c__string_var(ARGUMENT__b2c__string_var, 1, "=")));
#line 8120 "bacon.bac"
 if ( !__b2c__strcmp(__b2c__select_8119__b2c__string_var, "pbc")){
#line 8121 "bacon.bac"
g_TWEAK__b2c__string_var = F_CONCAT__b2c__string_var(g_TWEAK__b2c__string_var, g_TWEAK__b2c__string_var , "#define __b2c_Pool_Block_Count " , TOKEN__b2c__string_var(ARGUMENT__b2c__string_var, 2, "=") , NL__b2c__string_var) ;
#line 8122 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8119__b2c__string_var, "pbs")){
#line 8123 "bacon.bac"
g_TWEAK__b2c__string_var = F_CONCAT__b2c__string_var(g_TWEAK__b2c__string_var, g_TWEAK__b2c__string_var , "#define __b2c_Pool_Block_Size " , TOKEN__b2c__string_var(ARGUMENT__b2c__string_var, 2, "=") , NL__b2c__string_var) ;
#line 8124 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8119__b2c__string_var, "hld")){
#line 8125 "bacon.bac"
g_TWEAK__b2c__string_var = F_CONCAT__b2c__string_var(g_TWEAK__b2c__string_var, g_TWEAK__b2c__string_var , "#define __b2c_HASH_LINEAR_DEPTH " , TOKEN__b2c__string_var(ARGUMENT__b2c__string_var, 2, "=") , NL__b2c__string_var) ;
#line 8126 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8119__b2c__string_var, "hss")){
#line 8127 "bacon.bac"
g_TWEAK__b2c__string_var = F_CONCAT__b2c__string_var(g_TWEAK__b2c__string_var, g_TWEAK__b2c__string_var , "#define __b2c_HASH_STR_STORE " , TOKEN__b2c__string_var(ARGUMENT__b2c__string_var, 2, "=") , NL__b2c__string_var) ;
#line 8128 "bacon.bac"
} else  if ( !__b2c__strcmp(__b2c__select_8119__b2c__string_var, "mrb")){
#line 8129 "bacon.bac"
g_MAX_RBUFFERS=(long)( VAL(TOKEN__b2c__string_var(ARGUMENT__b2c__string_var, 2, "=")));
#line 8130 "bacon.bac"
}
#line 8133 "bacon.bac"
} else  if ( (__b2c__select_8085) == (63) || (__b2c__select_8085) == ( 104)){
#line 8134 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "USAGE: bacon [options] program[.bac]"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8135 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "OPTIONS:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8136 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) " -c <compiler>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Compiler to use (default: cc)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8137 "bacon.bac"
__b2c__assign = (char*)" -l <ldflags>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Pass libraries to linker"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8138 "bacon.bac"
__b2c__assign = (char*)" -o <options>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Pass compiler options"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8139 "bacon.bac"
__b2c__assign = (char*)" -i <include>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Add include file to C code"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8140 "bacon.bac"
__b2c__assign = (char*)" -d <tmpdir>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Temporary directory (default: .)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8141 "bacon.bac"
__b2c__assign = (char*)" -t <param=val>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Tweak internal parameter"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8142 "bacon.bac"
__b2c__assign = (char*)" -e <file.bac>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Use embedded editor"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8143 "bacon.bac"
__b2c__assign = (char*)" -y "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Automatically delete temporary files"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8144 "bacon.bac"
__b2c__assign = (char*)" -x "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Extract gettext strings"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8145 "bacon.bac"
__b2c__assign = (char*)" -z "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Allow lowercase keywords"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8146 "bacon.bac"
__b2c__assign = (char*)" -f "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Create Shared Object"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8147 "bacon.bac"
__b2c__assign = (char*)" -n "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Do not compile, only convert"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8148 "bacon.bac"
__b2c__assign = (char*)" -j "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Invoke C Preprocessor"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8149 "bacon.bac"
__b2c__assign = (char*)" -p "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Preserve temporary files"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8150 "bacon.bac"
__b2c__assign = (char*)" -q "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Show summary after conversion only"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8151 "bacon.bac"
__b2c__assign = (char*)" -r "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Compile and execute in one step"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8152 "bacon.bac"
__b2c__assign = (char*)" -s "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Suppress semantic error warnings"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8153 "bacon.bac"
__b2c__assign = (char*)" -w "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Save options to BaCon configfile"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8154 "bacon.bac"
__b2c__assign = (char*)" -@ "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Add debug information"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8155 "bacon.bac"
__b2c__assign = (char*)" -v "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Show version"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8156 "bacon.bac"
__b2c__assign = (char*)" -h "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) TAB__b2c__string_var(2); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "Show help"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8157 "bacon.bac"
exit(EXIT_SUCCESS);
#line 8160 "bacon.bac"
} else  if ( (__b2c__select_8085) == (118)){
#line 8161 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "BaCon version "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) " on "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) OS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8162 "bacon.bac"
exit(EXIT_SUCCESS);
#line 8165 "bacon.bac"
} else  if ( (__b2c__select_8085) == (112)){
#line 8166 "bacon.bac"
g_TMP_PRESERVE=(long)( 1);
#line 8169 "bacon.bac"
} else  if ( (__b2c__select_8085) == (113)){
#line 8170 "bacon.bac"
g_QUIET=(long)( 1);
#line 8173 "bacon.bac"
} else  if ( (__b2c__select_8085) == (114)){
#line 8174 "bacon.bac"
g_EXEC=(long)( 1);
#line 8177 "bacon.bac"
} else  if ( (__b2c__select_8085) == (115)){
#line 8178 "bacon.bac"
g_SEMANTIC=(long)( 1);
#line 8181 "bacon.bac"
} else  if ( (__b2c__select_8085) == (120)){
#line 8182 "bacon.bac"
g_XGETTEXT=(long)( 1);
#line 8185 "bacon.bac"
} else  if ( (__b2c__select_8085) == (121)){
#line 8186 "bacon.bac"
g_NO_QUESTION=(long)( 1);
#line 8189 "bacon.bac"
} else  if ( (__b2c__select_8085) == (110)){
#line 8190 "bacon.bac"
g_NO_COMPILE=(long)( 1);
#line 8193 "bacon.bac"
} else  if ( (__b2c__select_8085) == (101)){
#line 8194 "bacon.bac"
g_SOURCEFILE__b2c__string_var = __b2c_Copy_String(g_SOURCEFILE__b2c__string_var, (char*) IIF__b2c__string_var(__b2c__STRCMP(RIGHT__b2c__string_var(ARGUMENT__b2c__string_var, 4) ,  ".bac") != 0, CONCAT__b2c__string_var( ARGUMENT__b2c__string_var , ".bac") , ARGUMENT__b2c__string_var));
#line 8195 "bacon.bac"
if( FILEEXISTS(g_SOURCEFILE__b2c__string_var) ){
#line 8196 "bacon.bac"
Editor_Handle_Input(g_SOURCEFILE__b2c__string_var, LOAD__b2c__string_var(g_SOURCEFILE__b2c__string_var));
#line 8197 "bacon.bac"
} else {
#line 8198 "bacon.bac"
Editor_Handle_Input(g_SOURCEFILE__b2c__string_var, "");
#line 8199 "bacon.bac"
}
#line 8200 "bacon.bac"
exit(EXIT_SUCCESS);
#line 8203 "bacon.bac"
} else  if ( (__b2c__select_8085) == (106)){
#line 8204 "bacon.bac"
g_CPP=(long)( 1);
#line 8207 "bacon.bac"
} else  if ( (__b2c__select_8085) == (122)){
#line 8208 "bacon.bac"
g_LOWERCASE=(long)( 1);
#line 8211 "bacon.bac"
} else  if ( (__b2c__select_8085) == (102)){
#line 8212 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " -shared -rdynamic") ;
#line 8213 "bacon.bac"
g_CCFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_CCFLAGS__b2c__string_var, g_CCFLAGS__b2c__string_var , " -fPIC") ;
#line 8214 "bacon.bac"
g_BINEXT__b2c__string_var = __b2c_Copy_String(g_BINEXT__b2c__string_var, (char*) ".so");
#line 8217 "bacon.bac"
} else  if ( (__b2c__select_8085) == (119)){
#line 8218 "bacon.bac"
g_SAVE_CONFIG=(long)( 1);
#line 8221 "bacon.bac"
} else  if ( (__b2c__select_8085) == (64)){
#line 8222 "bacon.bac"
g_DEBUG=(long)( 1);
#line 8224 "bacon.bac"
}
#line 8225 "bacon.bac"
} while(!( opt == -1 ));
#line 8228 "bacon.bac"
if( g_SAVE_CONFIG == 1 ){
#line 8229 "bacon.bac"
cfgfile = fopen((const char*)CONCAT__b2c__string_var( GETENVIRON__b2c__string_var("HOME") , "/.bacon/bacon.cfg" ), "w");
if(cfgfile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8229, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8230 "bacon.bac"
__b2c__assign = (char*)"ccname "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
__b2c__assign = (char*) g_CCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs("\n", cfgfile);
#line 8231 "bacon.bac"
__b2c__assign = (char*)"tempdir "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
__b2c__assign = (char*) g_TEMPDIR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs("\n", cfgfile);
#line 8232 "bacon.bac"
__b2c__assign = (char*)"incfiles "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
__b2c__assign = (char*) REPLACE__b2c__string_var(g_INCFILES__b2c__string_var, "#include", "@"); if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs("\n", cfgfile);
#line 8233 "bacon.bac"
__b2c__assign = (char*)"ldflags "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
__b2c__assign = (char*) g_LDFLAGS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs("\n", cfgfile);
#line 8234 "bacon.bac"
__b2c__assign = (char*)"ccflags "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
__b2c__assign = (char*) g_CCFLAGS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs("\n", cfgfile);
#line 8235 "bacon.bac"
__b2c__assign = (char*)"lowercase "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs(STR__b2c__string_var( g_LOWERCASE), cfgfile);
fputs("\n", cfgfile);
#line 8236 "bacon.bac"
__b2c__assign = (char*)"intense "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs(STR__b2c__string_var( Color_Intense), cfgfile);
fputs("\n", cfgfile);
#line 8237 "bacon.bac"
__b2c__assign = (char*)"linenr "; if(__b2c__assign != NULL) { fputs(__b2c__assign, cfgfile); }
fputs(STR__b2c__string_var( Line_Number_Active), cfgfile);
fputs("\n", cfgfile);
#line 8238 "bacon.bac"
fclose(cfgfile);
#line 8239 "bacon.bac"
g_CCNAME_TMP__b2c__string_var = __b2c_Copy_String(g_CCNAME_TMP__b2c__string_var, (char*) g_CCNAME__b2c__string_var);
#line 8240 "bacon.bac"
g_TEMPDIR_TMP__b2c__string_var = __b2c_Copy_String(g_TEMPDIR_TMP__b2c__string_var, (char*) g_TEMPDIR__b2c__string_var);
#line 8241 "bacon.bac"
g_INCFILES_TMP__b2c__string_var = __b2c_Copy_String(g_INCFILES_TMP__b2c__string_var, (char*) REPLACE__b2c__string_var(g_INCFILES__b2c__string_var, "#include", "@"));
#line 8242 "bacon.bac"
g_LDFLAGS_TMP__b2c__string_var = __b2c_Copy_String(g_LDFLAGS_TMP__b2c__string_var, (char*) g_LDFLAGS__b2c__string_var);
#line 8243 "bacon.bac"
g_CCFLAGS_TMP__b2c__string_var = __b2c_Copy_String(g_CCFLAGS_TMP__b2c__string_var, (char*) g_CCFLAGS__b2c__string_var);
#line 8244 "bacon.bac"
g_LOWERCASE_TMP=(long)( g_LOWERCASE);
#line 8245 "bacon.bac"
}
#line 8248 "bacon.bac"
if( NOT(LEN(g_CCNAME__b2c__string_var)) ){
#line 8249 "bacon.bac"
g_CCNAME__b2c__string_var = __b2c_Copy_String(g_CCNAME__b2c__string_var, (char*) g_CCNAME_TMP__b2c__string_var);
#line 8250 "bacon.bac"
if( NOT(LEN(g_CCNAME__b2c__string_var)) ){
g_CCNAME__b2c__string_var = __b2c_Copy_String(g_CCNAME__b2c__string_var, (char*) "pcc");
}
#line 8251 "bacon.bac"
}
#line 8252 "bacon.bac"
if( NOT(LEN(g_TEMPDIR__b2c__string_var)) ){
#line 8253 "bacon.bac"
g_TEMPDIR__b2c__string_var = __b2c_Copy_String(g_TEMPDIR__b2c__string_var, (char*) g_TEMPDIR_TMP__b2c__string_var);
#line 8254 "bacon.bac"
if( NOT(LEN(g_TEMPDIR__b2c__string_var)) ){
g_TEMPDIR__b2c__string_var = __b2c_Copy_String(g_TEMPDIR__b2c__string_var, (char*) ".");
}
#line 8255 "bacon.bac"
}
#line 8256 "bacon.bac"
if( NOT(LEN(g_INCFILES__b2c__string_var)) ){
g_INCFILES__b2c__string_var = __b2c_Copy_String(g_INCFILES__b2c__string_var, (char*) REPLACE__b2c__string_var(g_INCFILES_TMP__b2c__string_var, "@", "#include"));
}
#line 8257 "bacon.bac"
g_LDFLAGS__b2c__string_var = F_CONCAT__b2c__string_var(g_LDFLAGS__b2c__string_var, g_LDFLAGS__b2c__string_var , " " , g_LDFLAGS_TMP__b2c__string_var) ;
#line 8258 "bacon.bac"
if( NOT(LEN(g_CCFLAGS__b2c__string_var)) ){
g_CCFLAGS__b2c__string_var = __b2c_Copy_String(g_CCFLAGS__b2c__string_var, (char*) g_CCFLAGS_TMP__b2c__string_var);
}
#line 8259 "bacon.bac"
if( g_LOWERCASE == 0 ){
g_LOWERCASE=(long)( g_LOWERCASE_TMP);
}
#line 8261 "bacon.bac"
if( NOT(LEN(ARGUMENT__b2c__string_var)) ){
#line 8262 "bacon.bac"
if( g_SAVE_CONFIG == 0 ){
__b2c__assign = (char*)"System error: no filename? Run with '-h' to see usage."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 8263 "bacon.bac"
exit(1);
#line 8264 "bacon.bac"
} else {
#line 8265 "bacon.bac"
g_SOURCEFILE__b2c__string_var = __b2c_Copy_String(g_SOURCEFILE__b2c__string_var, (char*) ARGUMENT__b2c__string_var);
#line 8266 "bacon.bac"
}
#line 8268 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(g_SOURCEFILE__b2c__string_var, 7) ,  "http://") == 0 ){
#line 8269 "bacon.bac"
g_SOURCEFILE__b2c__string_var = F_MID__b2c__string_var(g_SOURCEFILE__b2c__string_var,g_SOURCEFILE__b2c__string_var, 8);
#line 8270 "bacon.bac"
Download_File(g_SOURCEFILE__b2c__string_var);
#line 8271 "bacon.bac"
g_SOURCEFILE__b2c__string_var = F_MID__b2c__string_var(g_SOURCEFILE__b2c__string_var,g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/")+1);
#line 8272 "bacon.bac"
} else if( __b2c__STRCMP(RIGHT__b2c__string_var(g_SOURCEFILE__b2c__string_var, 4) ,  ".bac") != 0 ){
#line 8273 "bacon.bac"
g_SOURCEFILE__b2c__string_var = F_CONCAT__b2c__string_var(g_SOURCEFILE__b2c__string_var, CHOP__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".bac") ;
#line 8274 "bacon.bac"
}
#line 8276 "bacon.bac"
if( NOT(FILEEXISTS(g_SOURCEFILE__b2c__string_var)) ){
#line 8277 "bacon.bac"
__b2c__assign = (char*)"System error: file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' not found!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 8278 "bacon.bac"
exit(1);
#line 8279 "bacon.bac"
}
#line 8282 "bacon.bac"
if( INSTR(g_SOURCEFILE__b2c__string_var, "/")  AND  __b2c__STRCMP(LEFT__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1) ,  "/") == 0 ){
if(MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1, INSTRREV(g_SOURCEFILE__b2c__string_var, "/")-1) == NULL || chdir(MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1, INSTRREV(g_SOURCEFILE__b2c__string_var, "/")-1)) == -1){ ERROR = 22; RUNTIMEERROR("CHANGEDIR", 8282, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
}
#line 8285 "bacon.bac"
g_CFILE__b2c__string_var = F_CONCAT__b2c__string_var(g_CFILE__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".c") ;
#line 8286 "bacon.bac"
g_HFILE__b2c__string_var = F_CONCAT__b2c__string_var(g_HFILE__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".h") ;
#line 8287 "bacon.bac"
g_GENERIC__b2c__string_var = F_CONCAT__b2c__string_var(g_GENERIC__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".generic.h") ;
#line 8288 "bacon.bac"
g_FUNCTIONS__b2c__string_var = F_CONCAT__b2c__string_var(g_FUNCTIONS__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".functions.h") ;
#line 8289 "bacon.bac"
STRINGARRAYFILE__b2c__string_var = F_CONCAT__b2c__string_var(STRINGARRAYFILE__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".string.h") ;
#line 8290 "bacon.bac"
FLOATARRAYFILE__b2c__string_var = F_CONCAT__b2c__string_var(FLOATARRAYFILE__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".float.h") ;
#line 8291 "bacon.bac"
SRCARRAYFILE__b2c__string_var = F_CONCAT__b2c__string_var(SRCARRAYFILE__b2c__string_var, g_TEMPDIR__b2c__string_var , "/" , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".src.h") ;
#line 8294 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_CFILE__b2c__string_var , " " , g_HFILE__b2c__string_var , " " , STRINGARRAYFILE__b2c__string_var , " " , FLOATARRAYFILE__b2c__string_var) ;
#line 8297 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) WALK__b2c__string_var(g_TEMPDIR__b2c__string_var, 1, CONCAT__b2c__string_var( BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1) , "\\..+\\..+") , FALSE));
#line 8299 "bacon.bac"
if( g_NO_QUESTION ){
#line 8300 "bacon.bac"
__b2c__forin_tmpfile__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_string, total__b2c__string_var); __b2c__forin_tmpfile__b2c__string_var_string_org = __b2c__forin_tmpfile__b2c__string_var_string;
__b2c__forin_tmpfile__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_tmpfile__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_tmpfile__b2c__string_var_string, __b2c__forin_tmpfile__b2c__string_var_step);
for(; __b2c__forin_tmpfile__b2c__string_var_ptr > 0; __b2c__forin_tmpfile__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_tmpfile__b2c__string_var_string_org, __b2c__forin_tmpfile__b2c__string_var_step, &tmpfile__b2c__string_var);
#line 8301 "bacon.bac"
if(unlink(tmpfile__b2c__string_var)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 8301, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8302 "bacon.bac"
}
#line 8303 "bacon.bac"
} else {
#line 8304 "bacon.bac"
if( AMOUNT(total__b2c__string_var) ){
#line 8305 "bacon.bac"
__b2c__assign = (char*)"WARNING: "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs(STR__b2c__string_var( AMOUNT(total__b2c__string_var)), stdout);
__b2c__assign = (char*) " temporary files found!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) DELIM__b2c__string_var(SORT__b2c__string_var(total__b2c__string_var), " ", NL__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8306 "bacon.bac"
if( __b2c__STRCMP(GETENVIRON__b2c__string_var("BACON_IN_DOCKER") ,  "true") == 0 ){
#line 8307 "bacon.bac"
response__b2c__string_var = __b2c_Copy_String(response__b2c__string_var, (char*) "y");
#line 8308 "bacon.bac"
} else {
#line 8309 "bacon.bac"
__b2c__assign = (char*)"Do you want to delete them ([y]/n)? "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
response__b2c__string_var = __b2c_Copy_String(response__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 8310 "bacon.bac"
}
#line 8311 "bacon.bac"
if( LEN(response__b2c__string_var) == 0  OR  __b2c__STRCMP(LCASE__b2c__string_var(response__b2c__string_var) ,  "y") == 0 ){
#line 8312 "bacon.bac"
__b2c__forin_tmpfile__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_string, total__b2c__string_var); __b2c__forin_tmpfile__b2c__string_var_string_org = __b2c__forin_tmpfile__b2c__string_var_string;
__b2c__forin_tmpfile__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_tmpfile__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_tmpfile__b2c__string_var_string, __b2c__forin_tmpfile__b2c__string_var_step);
for(; __b2c__forin_tmpfile__b2c__string_var_ptr > 0; __b2c__forin_tmpfile__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_tmpfile__b2c__string_var_string_org, __b2c__forin_tmpfile__b2c__string_var_step, &tmpfile__b2c__string_var);
#line 8313 "bacon.bac"
if(unlink(tmpfile__b2c__string_var)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 8313, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8314 "bacon.bac"
}
#line 8315 "bacon.bac"
__b2c__assign = (char*)"Temporary files were deleted."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8316 "bacon.bac"
} else {
#line 8317 "bacon.bac"
__b2c__assign = (char*)"Exiting..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8318 "bacon.bac"
exit(1);
#line 8319 "bacon.bac"
}
#line 8320 "bacon.bac"
}
#line 8321 "bacon.bac"
}
#line 8324 "bacon.bac"
starttime=(long)( TIMER);
#line 8327 "bacon.bac"
g_CFILE = fopen((const char*)g_CFILE__b2c__string_var, "w");
if(g_CFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8327, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8328 "bacon.bac"
__b2c__assign = (char*)"/* Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8329 "bacon.bac"
__b2c__assign = (char*)"#include \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ".h\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8330 "bacon.bac"
__b2c__assign = (char*)"#include \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ".string.h\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8331 "bacon.bac"
__b2c__assign = (char*)"#include \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ".float.h\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8334 "bacon.bac"
g_HFILE = fopen((const char*)g_HFILE__b2c__string_var, "w");
if(g_HFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8334, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8335 "bacon.bac"
__b2c__assign = (char*)"/* Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8336 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "#include " , CHR__b2c__string_var(34) , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".generic.h" , CHR__b2c__string_var(34) ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8337 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "#include " , CHR__b2c__string_var(34) , MID__b2c__string_var(g_SOURCEFILE__b2c__string_var, INSTRREV(g_SOURCEFILE__b2c__string_var, "/") + 1) , ".functions.h" , CHR__b2c__string_var(34) ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8340 "bacon.bac"
g_GENERIC = fopen((const char*)g_GENERIC__b2c__string_var, "w");
if(g_GENERIC == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8340, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8341 "bacon.bac"
__b2c__assign = (char*)"/* Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8343 "bacon.bac"
STRINGARRAYFILE = fopen((const char*)STRINGARRAYFILE__b2c__string_var, "w");
if(STRINGARRAYFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8343, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8344 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__stringarray[] = {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, STRINGARRAYFILE); }
fputs("\n", STRINGARRAYFILE);
#line 8346 "bacon.bac"
FLOATARRAYFILE = fopen((const char*)FLOATARRAYFILE__b2c__string_var, "w");
if(FLOATARRAYFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8346, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8347 "bacon.bac"
__b2c__assign = (char*)"double __b2c__floatarray[] = {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, FLOATARRAYFILE); }
fputs("\n", FLOATARRAYFILE);
#line 8349 "bacon.bac"
if( INSTR(g_LDFLAGS__b2c__string_var, "shared") ){
#line 8350 "bacon.bac"
__b2c__assign = (char*)"/************************************/"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8351 "bacon.bac"
__b2c__assign = (char*)"/* Init function for shared objects */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8352 "bacon.bac"
__b2c__assign = (char*)"/************************************/"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8353 "bacon.bac"
__b2c__assign = (char*)"#ifdef __GNUC__"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8354 "bacon.bac"
__b2c__assign = (char*)"static int BaCon_init() __attribute__((constructor));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8355 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8356 "bacon.bac"
__b2c__assign = (char*)"int BaCon_init(void){int argc=0; char *argv[2] = { NULL };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8357 "bacon.bac"
} else {
#line 8358 "bacon.bac"
__b2c__assign = (char*)"/****************************/"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8359 "bacon.bac"
__b2c__assign = (char*)"/* Main program starts here */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8360 "bacon.bac"
__b2c__assign = (char*)"/****************************/"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8361 "bacon.bac"
__b2c__assign = (char*)"int main(int argc, char **argv){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8362 "bacon.bac"
}
#line 8365 "bacon.bac"
__b2c__assign = (char*)"setvbuf(stdout, NULL, _IOLBF, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8366 "bacon.bac"
__b2c__assign = (char*)"atexit(__b2c_str_free);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8367 "bacon.bac"
__b2c__assign = (char*)"__b2c__set_stack_size();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8370 "bacon.bac"
__b2c__assign = (char*)"if(argc>0) { __b2c__me_var"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) " = __b2c_Copy_String(__b2c__me_var"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", argv[0]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8373 "bacon.bac"
__b2c__assign = (char*)"if(argc==2 && !strncmp(argv[1], \"-bacon\", 6)) { fprintf(stderr, \"Converted by %s.\\n\", COMPILED_BY_WHICH_BACON"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "); exit(EXIT_SUCCESS); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8376 "bacon.bac"
__b2c__assign = (char*)"/* Setup the reserved variable 'ARGUMENT' */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8377 "bacon.bac"
__b2c__assign = (char*)"__b2c__argument(&ARGUMENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) ", argc, argv);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8378 "bacon.bac"
__b2c__assign = (char*)"/* By default seed random generator */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8379 "bacon.bac"
__b2c__assign = (char*)"srandom((unsigned int)time(NULL));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8380 "bacon.bac"
__b2c__assign = (char*)"/* Determine current moment and keep it for timer function */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8381 "bacon.bac"
__b2c__assign = (char*)"__b2c__nanotimer(1); __b2c__timer(1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8382 "bacon.bac"
__b2c__assign = (char*)"/* Setup error signal handling */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8383 "bacon.bac"
__b2c__assign = (char*)"signal(SIGILL, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8384 "bacon.bac"
__b2c__assign = (char*)"signal(SIGABRT, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8385 "bacon.bac"
__b2c__assign = (char*)"signal(SIGFPE, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8386 "bacon.bac"
__b2c__assign = (char*)"signal(SIGSEGV, __b2c__catch_signal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8387 "bacon.bac"
__b2c__assign = (char*)"/* Rest of the program */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8390 "bacon.bac"
g_IMPORTED__b2c__string_var = __b2c_Copy_String(g_IMPORTED__b2c__string_var, (char*) "");
#line 8402 "bacon.bac"
#line 8413 "bacon.bac"
#line 8416 "bacon.bac"
#line 8419 "bacon.bac"
#line 8422 "bacon.bac"
#line 8425 "bacon.bac"
#line 8426 "bacon.bac"
#line 8429 "bacon.bac"
if( ISTRUE(g_LOWERCASE) ){
#line 8430 "bacon.bac"
__b2c__forin_kwd__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_string, Stat__b2c__string_var); __b2c__forin_kwd__b2c__string_var_string_org = __b2c__forin_kwd__b2c__string_var_string;
__b2c__forin_kwd__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_step, "|");
__b2c__forin_kwd__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_kwd__b2c__string_var_string, __b2c__forin_kwd__b2c__string_var_step);
for(; __b2c__forin_kwd__b2c__string_var_ptr > 0; __b2c__forin_kwd__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_kwd__b2c__string_var_string_org, __b2c__forin_kwd__b2c__string_var_step, &kwd__b2c__string_var);
#line 8431 "bacon.bac"
if( __b2c__STRCMP(kwd__b2c__string_var ,  "CONST") != 0  AND  __b2c__STRCMP(kwd__b2c__string_var ,  "STATIC") != 0 ){
mapping__b2c__string_var = F_CONCAT__b2c__string_var(mapping__b2c__string_var, mapping__b2c__string_var , " -D" , LCASE__b2c__string_var(kwd__b2c__string_var) , "=" , kwd__b2c__string_var);
}
#line 8432 "bacon.bac"
}
#line 8433 "bacon.bac"
__b2c__forin_kwd__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_string, EXTRACT__b2c__string_var(Func__b2c__string_var, "\\")); __b2c__forin_kwd__b2c__string_var_string_org = __b2c__forin_kwd__b2c__string_var_string;
__b2c__forin_kwd__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_step, "|");
__b2c__forin_kwd__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_kwd__b2c__string_var_string, __b2c__forin_kwd__b2c__string_var_step);
for(; __b2c__forin_kwd__b2c__string_var_ptr > 0; __b2c__forin_kwd__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_kwd__b2c__string_var_string_org, __b2c__forin_kwd__b2c__string_var_step, &kwd__b2c__string_var);
#line 8434 "bacon.bac"
if( __b2c__STRCMP(kwd__b2c__string_var ,  "INT") != 0 ){
mapping__b2c__string_var = F_CONCAT__b2c__string_var(mapping__b2c__string_var, mapping__b2c__string_var , " -D" , LCASE__b2c__string_var(kwd__b2c__string_var) , "=" , kwd__b2c__string_var);
}
#line 8435 "bacon.bac"
}
#line 8436 "bacon.bac"
__b2c__forin_kwd__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_string, EXTRACT__b2c__string_var(Var__b2c__string_var, "\\")); __b2c__forin_kwd__b2c__string_var_string_org = __b2c__forin_kwd__b2c__string_var_string;
__b2c__forin_kwd__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_step, "|");
__b2c__forin_kwd__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_kwd__b2c__string_var_string, __b2c__forin_kwd__b2c__string_var_step);
for(; __b2c__forin_kwd__b2c__string_var_ptr > 0; __b2c__forin_kwd__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_kwd__b2c__string_var_string_org, __b2c__forin_kwd__b2c__string_var_step, &kwd__b2c__string_var);
#line 8437 "bacon.bac"
mapping__b2c__string_var = F_CONCAT__b2c__string_var(mapping__b2c__string_var, mapping__b2c__string_var , " -D" , LCASE__b2c__string_var(kwd__b2c__string_var) , "=" , kwd__b2c__string_var) ;
#line 8438 "bacon.bac"
}
#line 8439 "bacon.bac"
g_CPP=(long)( 1);
#line 8440 "bacon.bac"
} else {
#line 8441 "bacon.bac"
mapping__b2c__string_var = __b2c_Copy_String(mapping__b2c__string_var, (char*) "");
#line 8442 "bacon.bac"
}
#line 8445 "bacon.bac"
if( ISTRUE(g_CPP) ){
#line 8446 "bacon.bac"
if( ISTRUE(LEN(EXEC__b2c__string_var("command -v cpp 2>/dev/null"))) ){
#line 8447 "bacon.bac"
__b2c__assign = (char*)"Preprocessing '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 8449 "bacon.bac"
src_tmp = fopen((const char*)CONCAT__b2c__string_var( g_SOURCEFILE__b2c__string_var , ".tmp" ), "w");
if(src_tmp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8449, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8450 "bacon.bac"
src_in = fopen((const char*)g_SOURCEFILE__b2c__string_var, "r");
if(src_in == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8450, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8451 "bacon.bac"
while( NOT(ENDFILE(src_in)) ){
#line 8452 "bacon.bac"
__b2c__readln(&__b2c__assign, src_in);
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 8453 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(line__b2c__string_var, 1) ,  "#") == 0 ){
#line 8454 "bacon.bac"
__b2c__assign = (char*)line__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, src_tmp); }
fputs("\n", src_tmp);
#line 8455 "bacon.bac"
} else {
#line 8456 "bacon.bac"
__b2c__assign = (char*)CONCAT__b2c__string_var( "@" , line__b2c__string_var , "@" ); if(__b2c__assign != NULL) { fputs(__b2c__assign, src_tmp); }
fputs("\n", src_tmp);
#line 8457 "bacon.bac"
}
#line 8458 "bacon.bac"
}
#line 8459 "bacon.bac"
fclose(src_in);
fclose( src_tmp);
#line 8460 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "cpp -w -P " , mapping__b2c__string_var , " " , g_SOURCEFILE__b2c__string_var , ".tmp " , g_SOURCEFILE__b2c__string_var , ".cpp") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 8462 "bacon.bac"
src_cpp = fopen((const char*)CONCAT__b2c__string_var( g_SOURCEFILE__b2c__string_var , ".cpp" ), "r");
if(src_cpp == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8462, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8463 "bacon.bac"
src_out = fopen((const char*)CONCAT__b2c__string_var( g_SOURCEFILE__b2c__string_var , ".bac2" ), "w");
if(src_out == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 8463, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8464 "bacon.bac"
while( NOT(ENDFILE(src_cpp)) ){
#line 8465 "bacon.bac"
__b2c__readln(&__b2c__assign, src_cpp);
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 8466 "bacon.bac"
__b2c__assign = (char*)MID__b2c__string_var(line__b2c__string_var, 2, LEN(line__b2c__string_var)-2); if(__b2c__assign != NULL) { fputs(__b2c__assign, src_out); }
fputs("\n", src_out);
#line 8467 "bacon.bac"
}
#line 8468 "bacon.bac"
fclose(src_out);
fclose( src_cpp);
#line 8469 "bacon.bac"
FEED__b2c__string_var = F_CONCAT__b2c__string_var(FEED__b2c__string_var, g_SOURCEFILE__b2c__string_var , ".bac2") ;
#line 8470 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_SOURCEFILE__b2c__string_var , ".cpp" , " " , g_SOURCEFILE__b2c__string_var , ".tmp" , " " , g_SOURCEFILE__b2c__string_var , ".bac2") ;
#line 8471 "bacon.bac"
__b2c__assign = (char*)"done."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8472 "bacon.bac"
} else {
#line 8473 "bacon.bac"
__b2c__assign = (char*)"System error: the C Preprocessor 'cpp' not found on this system! Exiting..."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 8474 "bacon.bac"
exit(1);
#line 8475 "bacon.bac"
}
#line 8476 "bacon.bac"
} else {
#line 8477 "bacon.bac"
FEED__b2c__string_var = __b2c_Copy_String(FEED__b2c__string_var, (char*) g_SOURCEFILE__b2c__string_var);
#line 8478 "bacon.bac"
}
#line 8480 "bacon.bac"
g_CURFILE__b2c__string_var = __b2c_Copy_String(g_CURFILE__b2c__string_var, (char*) g_SOURCEFILE__b2c__string_var);
#line 8483 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) "");
#line 8484 "bacon.bac"
g_COUNTER=(long)( 0);
#line 8485 "bacon.bac"
g_TOTAL_LINES=(long)( 0);
#line 8488 "bacon.bac"
Save_Main_Var( CONCAT__b2c__string_var("__b2c__loop_result" , g_STRINGSIGN__b2c__string_var) , "char*");
#line 8489 "bacon.bac"
Save_Main_Var("__b2c__loop_result", "long");
#line 8492 "bacon.bac"
Save_Main_Var("ERROR", "int");
#line 8493 "bacon.bac"
Save_Main_Var("_", "long");
#line 8496 "bacon.bac"
g_SOURCEFILE = fopen((const char*)FEED__b2c__string_var, "r");
if(g_SOURCEFILE == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR READING", 8496, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 8499 "bacon.bac"
__b2c__assign = (char*)"\rConverting '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 8501 "bacon.bac"
do{
#line 8502 "bacon.bac"
__b2c__readln(&__b2c__assign, g_SOURCEFILE);
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 8503 "bacon.bac"
line__b2c__string_var = F_CHOP__b2c__string_var(line__b2c__string_var,line__b2c__string_var);
#line 8505 "bacon.bac"
g_COUNTER = g_COUNTER + (1);
#line 8508 "bacon.bac"
if( (LEN(line__b2c__string_var) )> 0 ){
#line 8509 "bacon.bac"
if( NOT(g_QUIET) ){
__b2c__assign = (char*)"\rConverting '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs(STR__b2c__string_var( g_COUNTER), stdout);
__b2c__assign = (char*) EL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
}
#line 8510 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(line__b2c__string_var, 2) ,  " \\") == 0  AND  __b2c__STRCMP(LEFT__b2c__string_var(line__b2c__string_var, 1) ,  CHR__b2c__string_var(39)) != 0  AND  NOT(REGEX(line__b2c__string_var, "^REM[[:space:]]+")) ){
#line 8511 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , LEFT__b2c__string_var(line__b2c__string_var, LEN(line__b2c__string_var) - 1)) ;
#line 8512 "bacon.bac"
} else {
#line 8513 "bacon.bac"
total__b2c__string_var = F_CONCAT__b2c__string_var(total__b2c__string_var, total__b2c__string_var , line__b2c__string_var) ;
#line 8514 "bacon.bac"
if( __b2c__STRCMP(LEFT__b2c__string_var(total__b2c__string_var, 1) ,  CHR__b2c__string_var(39)) != 0 ){
#line 8515 "bacon.bac"
if( g_DEBUG ){
#line 8516 "bacon.bac"
__b2c__assign = (char*)"/* line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\" */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8517 "bacon.bac"
__b2c__assign = (char*)"/* line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_HFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "\" */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8518 "bacon.bac"
} else {
#line 8519 "bacon.bac"
__b2c__assign = (char*)"#line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_CFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
__b2c__assign = (char*) "\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8520 "bacon.bac"
__b2c__assign = (char*)"#line "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs(STR__b2c__string_var( g_COUNTER), g_HFILE);
__b2c__assign = (char*) " \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8521 "bacon.bac"
}
#line 8522 "bacon.bac"
Tokenize(total__b2c__string_var);
#line 8524 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) EXTRACT__b2c__string_var(total__b2c__string_var, "\\\\"));
#line 8525 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) EXTRACT__b2c__string_var(total__b2c__string_var, "\\\""));
#line 8526 "bacon.bac"
g_DEPEND__b2c__string_var = F_CONCAT__b2c__string_var(g_DEPEND__b2c__string_var, g_DEPEND__b2c__string_var , EXTRACT__b2c__string_var(total__b2c__string_var, "\"[^\"]*\"", TRUE) , NL__b2c__string_var) ;
#line 8527 "bacon.bac"
}
#line 8528 "bacon.bac"
total__b2c__string_var = __b2c_Copy_String(total__b2c__string_var, (char*) "");
#line 8529 "bacon.bac"
}
#line 8530 "bacon.bac"
}
#line 8531 "bacon.bac"
} while(!( ENDFILE(g_SOURCEFILE) ));
#line 8532 "bacon.bac"
fclose(g_SOURCEFILE);
#line 8534 "bacon.bac"
if( g_DEBUG == 1 ){
#line 8535 "bacon.bac"
__b2c__assign = (char*)"__b2c_str_realloc_debug_string();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8536 "bacon.bac"
__b2c__assign = (char*)"__b2c_mempool_realloc_debug();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8537 "bacon.bac"
}
#line 8540 "bacon.bac"
if( g_CATCH_USED == 1 ){
__b2c__assign = (char*)"__B2C__PROGRAM__EXIT:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
}
#line 8541 "bacon.bac"
__b2c__assign = (char*)"return(0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8542 "bacon.bac"
__b2c__assign = (char*)"}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_CFILE); }
fputs("\n", g_CFILE);
#line 8545 "bacon.bac"
__b2c__assign = (char*)" \"\" };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, STRINGARRAYFILE); }
fputs("\n", STRINGARRAYFILE);
#line 8548 "bacon.bac"
__b2c__assign = (char*)" 0.0};"; if(__b2c__assign != NULL) { fputs(__b2c__assign, FLOATARRAYFILE); }
fputs("\n", FLOATARRAYFILE);
#line 8550 "bacon.bac"
g_TOTAL_LINES = g_TOTAL_LINES + ( g_COUNTER);
#line 8551 "bacon.bac"
ttime=(long)( TIMER-starttime);
#line 8552 "bacon.bac"
msec_time__b2c__string_var = (char*)__b2c_str_realloc(msec_time__b2c__string_var, (512+1)*sizeof(char));
snprintf(msec_time__b2c__string_var, 512+1, "%.3ld", MOD(ttime, 1000)); __b2c__SETLEN(msec_time__b2c__string_var, strlen(msec_time__b2c__string_var));
#line 8553 "bacon.bac"
__b2c__assign = (char*)"\rConverting '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... done, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs(STR__b2c__string_var( g_TOTAL_LINES), stdout);
__b2c__assign = (char*) " lines were processed in "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs(STR__b2c__string_var( FLOOR(ttime/1000)), stdout);
__b2c__assign = (char*) "."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) msec_time__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) " seconds."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 8556 "bacon.bac"
if( g_DEBUG == 1 ){
Debug_Vars();
}
#line 8559 "bacon.bac"
if( FILEEXISTS(SRCARRAYFILE__b2c__string_var) ){
#line 8560 "bacon.bac"
__b2c__assign = (char*)"#include \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) SRCARRAYFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8561 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , SRCARRAYFILE__b2c__string_var) ;
#line 8562 "bacon.bac"
}
#line 8565 "bacon.bac"
if( LEN(g_LOCAL_SBUFFER__b2c__string_var) ){
__b2c__assign = (char*)g_LOCAL_SBUFFER__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 8568 "bacon.bac"
__b2c__forin_incfiles__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_incfiles__b2c__string_var_string, g_INCLUDE_FILES__b2c__string_var); __b2c__forin_incfiles__b2c__string_var_string_org = __b2c__forin_incfiles__b2c__string_var_string;
__b2c__forin_incfiles__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_incfiles__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_incfiles__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_incfiles__b2c__string_var_string, __b2c__forin_incfiles__b2c__string_var_step);
for(; __b2c__forin_incfiles__b2c__string_var_ptr > 0; __b2c__forin_incfiles__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_incfiles__b2c__string_var_string_org, __b2c__forin_incfiles__b2c__string_var_step, &incfiles__b2c__string_var);
#line 8569 "bacon.bac"
if( (LEN(incfiles__b2c__string_var) )> 0 ){
__b2c__assign = (char*)"#include \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) incfiles__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 8570 "bacon.bac"
}
#line 8571 "bacon.bac"
__b2c__assign = (char*)"void __b2c__set_stack_size(void) { struct rlimit rl; getrlimit (RLIMIT_STACK, &rl); rl.rlim_cur = RLIM_INFINITY; setrlimit (RLIMIT_STACK, &rl); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
#line 8574 "bacon.bac"
if( LEN(g_GLOBALARRAYS__b2c__string_var) ){
__b2c__assign = (char*)"void __b2c__arrays_free(void) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) g_GLOBALARRAYS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
__b2c__assign = (char*) "}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 8575 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COLLECT[[:space:]]|TREE[[:space:]]") ){
__b2c__assign = (char*)"void __b2c__twalk_free(void) { if (__b2c__twalk_array) { free (__b2c__twalk_array); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_HFILE); }
fputs("\n", g_HFILE);
}
#line 8578 "bacon.bac"
fclose(g_HFILE);
#line 8581 "bacon.bac"
__b2c__assign = (char*)g_PRAGMA_INCLUDE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8583 "bacon.bac"
if( LEN(g_INCFILES__b2c__string_var) ){
__b2c__assign = (char*)REPLACE__b2c__string_var(g_INCFILES__b2c__string_var, "#include", CONCAT__b2c__string_var( NL__b2c__string_var , "#include") ); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
}
#line 8584 "bacon.bac"
__b2c__assign = (char*)"#include <stdio.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8585 "bacon.bac"
__b2c__assign = (char*)"#include <stdlib.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8586 "bacon.bac"
__b2c__assign = (char*)"#include <stdarg.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8587 "bacon.bac"
__b2c__assign = (char*)"#include <stdint.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8588 "bacon.bac"
__b2c__assign = (char*)"#include <libgen.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8589 "bacon.bac"
__b2c__assign = (char*)"#include <limits.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8590 "bacon.bac"
__b2c__assign = (char*)"#include <float.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8591 "bacon.bac"
__b2c__assign = (char*)"#include <sys/resource.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8592 "bacon.bac"
__b2c__assign = (char*)"#include <sys/time.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8593 "bacon.bac"
__b2c__assign = (char*)"#include <sys/stat.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8594 "bacon.bac"
__b2c__assign = (char*)"#include <sys/types.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8595 "bacon.bac"
__b2c__assign = (char*)"#include <sys/wait.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8596 "bacon.bac"
__b2c__assign = (char*)"#include <sys/socket.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8597 "bacon.bac"
__b2c__assign = (char*)"#include <sys/utsname.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8598 "bacon.bac"
__b2c__assign = (char*)"#include <sys/ioctl.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8599 "bacon.bac"
__b2c__assign = (char*)"#include <dirent.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8600 "bacon.bac"
__b2c__assign = (char*)"#include <setjmp.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8601 "bacon.bac"
__b2c__assign = (char*)"#include <netdb.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8602 "bacon.bac"
if( INSTR(OS__b2c__string_var, "BSD") ){
#line 8603 "bacon.bac"
__b2c__assign = (char*)"#include <netinet/in.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8604 "bacon.bac"
__b2c__assign = (char*)"#define strcat(x, y) __b2c_strlcat(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8605 "bacon.bac"
__b2c__assign = (char*)"#define strcpy(x, y) __b2c_strlcpy(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8606 "bacon.bac"
__b2c__assign = (char*)"#define random(void) arc4random(void)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8607 "bacon.bac"
}
#line 8608 "bacon.bac"
__b2c__assign = (char*)"#include <arpa/inet.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8609 "bacon.bac"
__b2c__assign = (char*)"#include <signal.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8610 "bacon.bac"
if( LEN(g_PRAGMA_REGEX__b2c__string_var) ){
#line 8611 "bacon.bac"
if( NOT(REGEX(g_PRAGMA_REGEX__b2c__string_var, " INCLUDE ")) ){
#line 8612 "bacon.bac"
kwd__b2c__string_var = __b2c_Copy_String(kwd__b2c__string_var, (char*) HEAD__b2c__string_var(g_PRAGMA_REGEX__b2c__string_var));
#line 8613 "bacon.bac"
if( INSTR(kwd__b2c__string_var, "tre") ){
#line 8614 "bacon.bac"
__b2c__assign = (char*)"#include <tre/regex.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8615 "bacon.bac"
} else if( INSTR(kwd__b2c__string_var, "pcre") ){
#line 8616 "bacon.bac"
__b2c__assign = (char*)"#include <pcreposix.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8617 "bacon.bac"
} else if( INSTR(kwd__b2c__string_var, "onig") ){
#line 8618 "bacon.bac"
__b2c__assign = (char*)"#include <onigposix.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8619 "bacon.bac"
}
#line 8620 "bacon.bac"
} else {
#line 8621 "bacon.bac"
kwd__b2c__string_var = F_MID__b2c__string_var(kwd__b2c__string_var,g_PRAGMA_REGEX__b2c__string_var, INSTR(g_PRAGMA_REGEX__b2c__string_var, " INCLUDE ")+9);
#line 8622 "bacon.bac"
__b2c__assign = (char*)"#include "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) HEAD__b2c__string_var(kwd__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8623 "bacon.bac"
}
#line 8624 "bacon.bac"
} else {
#line 8625 "bacon.bac"
__b2c__assign = (char*)"#include <regex.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8626 "bacon.bac"
}
#line 8628 "bacon.bac"
if( LEN(g_INC_TLS__b2c__string_var) ){
#line 8629 "bacon.bac"
if( REGEX(g_INC_TLS__b2c__string_var, " INCLUDE ") ){
#line 8630 "bacon.bac"
__b2c__forin_kwd__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_string, MID__b2c__string_var(g_INC_TLS__b2c__string_var, INSTR(g_INC_TLS__b2c__string_var, " INCLUDE ")+9)); __b2c__forin_kwd__b2c__string_var_string_org = __b2c__forin_kwd__b2c__string_var_string;
__b2c__forin_kwd__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_kwd__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_kwd__b2c__string_var_string, __b2c__forin_kwd__b2c__string_var_step);
for(; __b2c__forin_kwd__b2c__string_var_ptr > 0; __b2c__forin_kwd__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_kwd__b2c__string_var_string_org, __b2c__forin_kwd__b2c__string_var_step, &kwd__b2c__string_var);
#line 8631 "bacon.bac"
__b2c__assign = (char*)"#include "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) kwd__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8632 "bacon.bac"
}
#line 8633 "bacon.bac"
} else {
#line 8634 "bacon.bac"
__b2c__assign = (char*)g_INC_TLS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8635 "bacon.bac"
}
#line 8636 "bacon.bac"
}
#line 8637 "bacon.bac"
__b2c__assign = (char*)"#include <fcntl.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8638 "bacon.bac"
__b2c__assign = (char*)"#include <math.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8639 "bacon.bac"
__b2c__assign = (char*)"#include <unistd.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8640 "bacon.bac"
__b2c__assign = (char*)"#include <string.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8641 "bacon.bac"
__b2c__assign = (char*)"#include <ctype.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8642 "bacon.bac"
__b2c__assign = (char*)"#include <wctype.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8643 "bacon.bac"
__b2c__assign = (char*)"#include <locale.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8644 "bacon.bac"
__b2c__assign = (char*)"#include <dlfcn.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8645 "bacon.bac"
__b2c__assign = (char*)"#include <errno.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8646 "bacon.bac"
__b2c__assign = (char*)"#include <termios.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8647 "bacon.bac"
__b2c__assign = (char*)"#include <time.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8648 "bacon.bac"
__b2c__assign = (char*)"#include <fts.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8649 "bacon.bac"
__b2c__assign = (char*)"#define ENTRY ENTRY_libc"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8650 "bacon.bac"
__b2c__assign = (char*)"#include <search.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8651 "bacon.bac"
__b2c__assign = (char*)"#undef ENTRY"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8652 "bacon.bac"
__b2c__assign = (char*)"/* Undefine all symbols which happen to be BaCon keywords */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8653 "bacon.bac"
__b2c__forin_kwd__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_string, SORT__b2c__string_var( CONCAT__b2c__string_var(Stat__b2c__string_var , EXTRACT__b2c__string_var(Func__b2c__string_var, "\\") , EXTRACT__b2c__string_var(Var__b2c__string_var, "\\")) , "|")); __b2c__forin_kwd__b2c__string_var_string_org = __b2c__forin_kwd__b2c__string_var_string;
__b2c__forin_kwd__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_kwd__b2c__string_var_step, "|");
__b2c__forin_kwd__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_kwd__b2c__string_var_string, __b2c__forin_kwd__b2c__string_var_step);
for(; __b2c__forin_kwd__b2c__string_var_ptr > 0; __b2c__forin_kwd__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_kwd__b2c__string_var_string_org, __b2c__forin_kwd__b2c__string_var_step, &kwd__b2c__string_var);
#line 8654 "bacon.bac"
if( __b2c__STRCMP(RIGHT__b2c__string_var(kwd__b2c__string_var, 1) ,  "$") != 0  AND  __b2c__STRCMP(kwd__b2c__string_var ,  "NULL") != 0 ){
__b2c__assign = (char*)"#undef "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) kwd__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
}
#line 8655 "bacon.bac"
}
#line 8657 "bacon.bac"
__b2c__assign = (char*)"/* Declarations for internal variables */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8658 "bacon.bac"
__b2c__assign = (char*)"jmp_buf __b2c__jump = { 0 };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8659 "bacon.bac"
__b2c__assign = (char*)"int __b2c__trap = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8660 "bacon.bac"
__b2c__assign = (char*)"int __b2c__catch_set_backup = 0, __b2c__catch_set = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8661 "bacon.bac"
__b2c__assign = (char*)"void (*__b2c__error_callback)(char*, char*, long) = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8662 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_compare = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8663 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_quoted = 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8664 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_dq = 34;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8665 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_esc = 92;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8666 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_utf8 = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8667 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_proper = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8668 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_tls = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8669 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__option_delim = \" \";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8670 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_memstream = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8671 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_startpoint = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8672 "bacon.bac"
__b2c__assign = (char*)"int __b2c__option_open = O_RDWR|O_NOCTTY|O_SYNC;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8673 "bacon.bac"
__b2c__assign = (char*)"int __b2c__collapse = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8674 "bacon.bac"
__b2c__assign = (char*)"int __b2c__break_ctr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8675 "bacon.bac"
__b2c__assign = (char*)"int __b2c__break_flag = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8676 "bacon.bac"
__b2c__assign = (char*)"char __b2c__chop_default[] = \"\\r\\n\\t\\f\\v \";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8677 "bacon.bac"
__b2c__assign = (char*)"int __b2c__stringarray_ptr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8678 "bacon.bac"
__b2c__assign = (char*)"int __b2c__floatarray_ptr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8679 "bacon.bac"
__b2c__assign = (char*)"long __b2c__ctr = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8681 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_STRING_FUNC ("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs(STR__b2c__string_var( g_STRING_FUNC), g_GENERIC);
__b2c__assign = (char*) ")"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8682 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_EMPTYSTRING (char*)\"\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8683 "bacon.bac"
__b2c__assign = (char*)"jmp_buf __b2c__gosub_buffer["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs(STR__b2c__string_var( g_MAX_RBUFFERS), g_GENERIC);
__b2c__assign = (char*) "];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8684 "bacon.bac"
__b2c__assign = (char*)"int __b2c__gosub_buffer_ptr = -1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8685 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8686 "bacon.bac"
__b2c__assign = (char*)"long __b2c__loop_result = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8687 "bacon.bac"
__b2c__assign = (char*)"jmp_buf __b2c__data_jump, __b2c__loop1, __b2c__loop2;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8688 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__assign = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8689 "bacon.bac"
__b2c__assign = (char*)"void **__b2c__assign2 = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8690 "bacon.bac"
__b2c__assign = (char*)"int __b2c__counter = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8691 "bacon.bac"
__b2c__assign = (char*)"char **__b2c__stack = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8692 "bacon.bac"
__b2c__assign = (char*)"void **__b2c__twalk_array = NULL; int __b2c__twalk_idx = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8693 "bacon.bac"
__b2c__assign = (char*)"extern char *__b2c__stringarray[];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8694 "bacon.bac"
__b2c__assign = (char*)"extern double __b2c__floatarray[];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8695 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__me_var"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8696 "bacon.bac"
__b2c__assign = (char*)"/* Declarations for BaCon variables */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8697 "bacon.bac"
__b2c__assign = (char*)"char *ARGUMENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8698 "bacon.bac"
__b2c__assign = (char*)"int ERROR = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8699 "bacon.bac"
__b2c__assign = (char*)"int RETVAL = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8700 "bacon.bac"
__b2c__assign = (char*)"int REGLEN = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8701 "bacon.bac"
__b2c__assign = (char*)"int SP = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8702 "bacon.bac"
__b2c__assign = (char*)"long _ = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8703 "bacon.bac"
__b2c__assign = (char*)"char VERSION"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "[] = \""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "\";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8705 "bacon.bac"
__b2c__assign = (char*)"/* Prototypes for internal functions */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8706 "bacon.bac"
__b2c__assign = (char*)"int __b2c__strcmp(const char*, const char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8707 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__strdup(char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8708 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__strndup(char*, size_t);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8709 "bacon.bac"
__b2c__assign = (char*)"void *__b2c_mempool_realloc_core(void*, size_t, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8710 "bacon.bac"
__b2c__assign = (char*)"void* __b2c_str_realloc_core(char*, size_t, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8711 "bacon.bac"
__b2c__assign = (char*)"long __b2c__delim_engine_core(int, int, long*, char*, char*, long, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8712 "bacon.bac"
if( INSTR(OS__b2c__string_var, "BSD") ){
#line 8713 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_strlcat(char*, const char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8714 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_strlcpy(char*, const char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8715 "bacon.bac"
}
#line 8716 "bacon.bac"
__b2c__assign = (char*)"/* Prototypes for BaCon functions */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8717 "bacon.bac"
__b2c__assign = (char*)"char *ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8718 "bacon.bac"
__b2c__assign = (char*)"int __b2c_utf8_conv(int,char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8719 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_Copy_String_core(char*, char*, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8720 "bacon.bac"
__b2c__assign = (char*)"char* __b2c_Swap_String(char**, char**);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8721 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__len(const char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8722 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__ulen(int,char*,char*,char*,int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8723 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__blen(int,char*,char*,char*,long,int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8724 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__ucs2_clen(int,char*,char*,char*,int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8725 "bacon.bac"
__b2c__assign = (char*)"long __b2c__regex_core(int, int, char*, char*, char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8726 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__extract_core(int, int, char*, char*, char*, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8727 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__replace_core(int, int, char*, char*, char*, char*, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8728 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__walk_core(int, int, char*, char*, int, char*, int, char*);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8729 "bacon.bac"
__b2c__assign = (char*)"void __b2c_str_free(void);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8730 "bacon.bac"
__b2c__assign = (char*)"void __b2c__arrays_free(void);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8731 "bacon.bac"
__b2c__assign = (char*)"void __b2c__twalk_free(void);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8732 "bacon.bac"
__b2c__assign = (char*)"int __b2c__collect(void*, void***, int, int);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8733 "bacon.bac"
__b2c__assign = (char*)"/* Internal macro definitions */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8734 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MEMTYPE char"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8735 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__STRCMP __b2c__strcmp"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8736 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__BUFOFFSET 16"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8737 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__LBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+8))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8738 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RBUFSIZE(x) (*(uint32_t*)((uint8_t*)x-__b2c__BUFOFFSET+4))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8739 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__STRFREE(x) if(__b2c_str_realloc_get_string(x)) { if(!__b2c_mempool_realloc_free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x))) { free((uint8_t*)x-__b2c__BUFOFFSET-__b2c__LBUFSIZE(x)); } __b2c_str_realloc_del_string(x); } else { if(x) { free(x); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8740 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__SETLEN(x,y) *(uint32_t*)(x-__b2c__BUFOFFSET) = y;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8741 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FUNCSELECT2(_1, _2, x, ...) x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8742 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FUNCSELECT3(_1, _2, _3, x, ...) x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8743 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FUNCSELECT4(_1, _2, _3, _4, x, ...) x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8744 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FUNCSELECT5(_1, _2, _3, _4, _5, x, ...) x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8745 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FUNCSELECT10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _0, x, ...) x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8746 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_mempool_realloc_debug() __b2c_mempool_realloc_core(NULL, 0, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8747 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_mempool_realloc_free(x) __b2c_mempool_realloc_core(x, 0, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8748 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_mempool_realloc_in_block(x) __b2c_mempool_realloc_core(x, 0, 2)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8749 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_mempool_realloc(x, y) __b2c_mempool_realloc_core(x, y, 3)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8750 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc(x, y) __b2c_str_realloc_core(x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8751 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc_left(x, y) __b2c_str_realloc_core(x, y, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8752 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc_add_string(x) __b2c_str_realloc_core((char*)x, 0, 2)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8753 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc_del_string(x) __b2c_str_realloc_core((char*)x, 0, 3)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8754 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc_get_string(x) (x!=NULL && __b2c_str_realloc_core((char*)x, 0, 4))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8755 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc_free_string() __b2c_str_realloc_core(NULL, 0, 6)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8756 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_str_realloc_debug_string() __b2c_str_realloc_core(NULL, 0, 5)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8757 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_Copy_String(x, y) __b2c_Copy_String_core(x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8758 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_Copy_N_String(x, y, z) __b2c_Copy_String_core(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8759 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__delim_engine(x, y, z, a, b) __b2c__delim_engine_core(1, x, y, z, a, b, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8760 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__delim_engine_cache(x, y, z, a, b) __b2c__delim_engine_core(1, x, y, z, a, b, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8761 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__delim_engine_free() __b2c__delim_engine_core(0, 0, NULL, NULL, NULL, 0, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8762 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__regex(x, y, z, q) __b2c__regex_core(1, x, y, z, q)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8763 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__regex_free() __b2c__regex_core(0, 0, NULL, NULL, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8764 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__extract(x, y, z, q, r) __b2c__extract_core(1, x, y, z, q, r)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8765 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__extract_free() __b2c__extract_core(0, 0, NULL, NULL, NULL, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8766 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__replace(x, y, z, q, r, s) __b2c__replace_core(1, x, y, z, q, r, s)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8767 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__replace_free() __b2c__replace_core(0, 0, NULL, NULL, NULL, NULL, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8768 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__walk(x, y, z, a, b, c, d) __b2c__walk_core(1, x, y, z, a, b, c, d)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8769 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__walk_free() __b2c__walk_core(0, 0, NULL, NULL, 0, NULL, 0, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8770 "bacon.bac"
__b2c__assign = (char*)"#if INTPTR_MAX == INT64_MAX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8771 "bacon.bac"
__b2c__assign = (char*)"#define HASH_FUNC (uint64_t)__b2c__HashFNV1a_64"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8772 "bacon.bac"
__b2c__assign = (char*)"#elif INTPTR_MAX == INT32_MAX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8773 "bacon.bac"
__b2c__assign = (char*)"#define HASH_FUNC (uint32_t)__b2c__HashFNV1a_32"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8774 "bacon.bac"
__b2c__assign = (char*)"#else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8775 "bacon.bac"
__b2c__assign = (char*)"#define HASH_FUNC (uint16_t)__b2c__HashFNV1a_16_new"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8776 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8777 "bacon.bac"
__b2c__assign = (char*)"#define COMPILED_BY_WHICH_BACON"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "BaCon executable "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) CHR__b2c__string_var(34); if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8778 "bacon.bac"
__b2c__assign = (char*)"#define RUNTIMEERROR(a, x, y, z, q) do { if(!__b2c__catch_set) { if(__b2c__trap) { fprintf(stderr, \"Runtime error: statement '%s' at line %d in '%s': %s\\n\", a, x, y, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(z)); exit(z); } if(__b2c__error_callback){ (*__b2c__error_callback)(a,y,x); } } else { if(!setjmp(__b2c__jump)) { goto q; } } } while(0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8779 "bacon.bac"
__b2c__assign = (char*)"#define RUNTIMEFERR(a, x, y, z) do { if(__b2c__trap) { fprintf(stderr, \"Runtime error: function '%s' at line %d in '%s': %s\\n\", a, z, y, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x)); exit(x); } if(__b2c__error_callback) { (*__b2c__error_callback)(a,y,z); } } while(0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8780 "bacon.bac"
__b2c__assign = (char*)"#define RUNTIMEDEBUG(x, y, z) (__b2c__getch() == 27 ? fprintf(stderr, \"TRACE OFF - exiting trace mode.\\n\") && __b2c__stop_program() : fprintf(stderr, \"File '%s' line %d: %s\\n\", #x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_MONITOR__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8781 "bacon.bac"
__b2c__assign = (char*)"int __b2c__stop_program(void) { exit(EXIT_SUCCESS); return(1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8782 "bacon.bac"
__b2c__assign = (char*)"/* BaCon functions */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8783 "bacon.bac"
__b2c__assign = (char*)"#define ABS(x) fabs((double)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8784 "bacon.bac"
__b2c__assign = (char*)"#define ACOS(x) acos((double)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8785 "bacon.bac"
__b2c__assign = (char*)"#define ADDRESS(x) (uintptr_t)(&x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8786 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ALIGN3(x, y, z) __b2c__align(__LINE__, __FILE__, x, y, z, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8787 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ALIGN4(x, y, z, f) __b2c__align(__LINE__, __FILE__, x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8788 "bacon.bac"
__b2c__assign = (char*)"#define ALIGN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__ALIGN4, __b2c__ALIGN3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8789 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__AMOUNT1(x) __b2c__amount(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8790 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__AMOUNT2(x, y) __b2c__amount(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8791 "bacon.bac"
__b2c__assign = (char*)"#define AMOUNT(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__AMOUNT2, __b2c__AMOUNT1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8792 "bacon.bac"
__b2c__assign = (char*)"#define AND &&"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8793 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__APPEND3(x, y, z) __b2c__append(NULL, 0, x, y, z, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8794 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__APPEND4(x, y, z, f) __b2c__append(NULL, 0, x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8795 "bacon.bac"
__b2c__assign = (char*)"#define APPEND"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__APPEND4, __b2c__APPEND3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8796 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FAPPEND4(s, x, y, z) __b2c__append(&s, 1, x, y, z, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8797 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FAPPEND5(s, x, y, z, f) __b2c__append(&s, 1, x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8798 "bacon.bac"
__b2c__assign = (char*)"#define F_APPEND"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__FAPPEND5, __b2c__FAPPEND4)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8799 "bacon.bac"
__b2c__assign = (char*)"#define ASC(x) __b2c__asc(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8800 "bacon.bac"
__b2c__assign = (char*)"#define ASIN(x) asin((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8801 "bacon.bac"
__b2c__assign = (char*)"#define ATN(x) atan((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8802 "bacon.bac"
__b2c__assign = (char*)"#define ATN2(x,y) atan2((double)(x),(double)(y))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8803 "bacon.bac"
__b2c__assign = (char*)"#define B64DEC"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__b64dec(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8804 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__B64ENC1(x) __b2c__b64enc(x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8805 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__B64ENC2(x, y) __b2c__b64enc((char*)x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8806 "bacon.bac"
__b2c__assign = (char*)"#define B64ENC"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__B64ENC2, __b2c__B64ENC1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8807 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__BASENAME1(x) __b2c__dirname(__LINE__, __FILE__, 1, x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8808 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__BASENAME2(x, y) __b2c__dirname(__LINE__, __FILE__, 1, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8809 "bacon.bac"
__b2c__assign = (char*)"#define BASENAME"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__BASENAME2, __b2c__BASENAME1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8810 "bacon.bac"
__b2c__assign = (char*)"#define BIN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__bin(sizeof(__b2c__MEMTYPE), x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8811 "bacon.bac"
__b2c__assign = (char*)"#define BIT(x) __b2c__bit(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8812 "bacon.bac"
__b2c__assign = (char*)"#define BLOAD(x) (void*)__b2c__load(1, __LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8813 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__BYTELEN2(x, y) __b2c__blen(__LINE__, __FILE__, \"BYTELEN\", x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8814 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__BYTELEN3(x, y, z) __b2c__blen(__LINE__, __FILE__, \"BYTELEN\", x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8815 "bacon.bac"
__b2c__assign = (char*)"#define BYTELEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__BYTELEN3, __b2c__BYTELEN2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8816 "bacon.bac"
__b2c__assign = (char*)"#define CA"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__ca(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8817 "bacon.bac"
__b2c__assign = (char*)"#define CN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__cn(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8818 "bacon.bac"
__b2c__assign = (char*)"#define CIPHER"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__cipher(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8819 "bacon.bac"
__b2c__assign = (char*)"#define VERIFY(x, y) ((SSL*)x == NULL ? -1 : (long)SSL_get_verify_result((SSL*)x) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8820 "bacon.bac"
__b2c__assign = (char*)"#define ACCEPT(x) __b2c__accept(__LINE__, __FILE__, __b2c__caprivate, __b2c__caserver, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8821 "bacon.bac"
__b2c__assign = (char*)"#define CEIL(x) (double)ceil(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8822 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CHANGE3(x, y, z) __b2c__change(x, y, z, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8823 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CHANGE4(x, y, z, f) __b2c__change(x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8824 "bacon.bac"
__b2c__assign = (char*)"#define CHANGE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CHANGE4, __b2c__CHANGE3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8825 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CHOP1(x) __b2c__chop(NULL, 0, x, NULL, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8826 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CHOP2(x, y) __b2c__chop(NULL, 0, x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8827 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CHOP3(x, y, z) __b2c__chop(NULL, 0, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8828 "bacon.bac"
__b2c__assign = (char*)"#define CHOP"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__CHOP3, __b2c__CHOP2, __b2c__CHOP1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8829 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FCHOP2(s, x) __b2c__chop(&s, 1, x, NULL, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8830 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FCHOP3(s, x, y) __b2c__chop(&s, 1, x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8831 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FCHOP4(s, x, y, z) __b2c__chop(&s, 1, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8832 "bacon.bac"
__b2c__assign = (char*)"#define F_CHOP"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FCHOP4, __b2c__FCHOP3, __b2c__FCHOP2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8833 "bacon.bac"
__b2c__assign = (char*)"#define CHR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__asc2char(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8834 "bacon.bac"
__b2c__assign = (char*)"#define UTF8"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__asc2utf8(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8835 "bacon.bac"
__b2c__assign = (char*)"#define CL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " \"\\033[2K\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8836 "bacon.bac"
__b2c__assign = (char*)"#define CMDLINE(x) __b2c__getopt(argc, argv, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8837 "bacon.bac"
__b2c__assign = (char*)"#define COIL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper(__b2c__loop2) : __b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8838 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__COLLAPSE1(x) __b2c__collapse_func(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8839 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__COLLAPSE2(x, y) __b2c__collapse_func(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8840 "bacon.bac"
__b2c__assign = (char*)"#define COLLAPSE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__COLLAPSE2, __b2c__COLLAPSE1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8841 "bacon.bac"
__b2c__assign = (char*)"#define COLUMNS __b2c__screen(0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8842 "bacon.bac"
__b2c__assign = (char*)"#define CONCAT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__concat(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8843 "bacon.bac"
__b2c__assign = (char*)"#define F_CONCAT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__concat2(sizeof((const char*[]) {__VA_ARGS__}) / sizeof(char*), __VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8844 "bacon.bac"
__b2c__assign = (char*)"#define COS(x) cos((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8845 "bacon.bac"
__b2c__assign = (char*)"#define COUNT(x, y) __b2c__count(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8846 "bacon.bac"
__b2c__assign = (char*)"#define CR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " \"\\r\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8847 "bacon.bac"
__b2c__assign = (char*)"#define CURDIR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " __b2c__curdir()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8848 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CUT3(x, y, z) __b2c__cut(x, y, z, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8849 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__CUT4(x, y, z, f) __b2c__cut(x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8850 "bacon.bac"
__b2c__assign = (char*)"#define CUT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__CUT4, __b2c__CUT3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8851 "bacon.bac"
__b2c__assign = (char*)"#define DAY(x) __b2c__time(x, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8852 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__DEC1(x) __b2c__hex2dec(__LINE__, __FILE__, x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8853 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__DEC2(x, y) __b2c__hex2dec(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8854 "bacon.bac"
__b2c__assign = (char*)"#define DEC(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__DEC2, __b2c__DEC1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8855 "bacon.bac"
__b2c__assign = (char*)"#define DEG(x) (x*180/PI)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8856 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__DEL2(x, y) __b2c__del(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8857 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__DEL3(x, y, z) __b2c__del(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8858 "bacon.bac"
__b2c__assign = (char*)"#define DEL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__DEL3, __b2c__DEL2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8859 "bacon.bac"
__b2c__assign = (char*)"#define DELIM"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x, y, z) __b2c__delim(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8860 "bacon.bac"
__b2c__assign = (char*)"#define DIRNAME"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__dirname(__LINE__, __FILE__, 2, x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8861 "bacon.bac"
__b2c__assign = (char*)"#define DLE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " \"\\r\\n\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8862 "bacon.bac"
__b2c__assign = (char*)"#define EDITBOM"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x, y) __b2c__editbom(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8863 "bacon.bac"
__b2c__assign = (char*)"#define EL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " \"\\033[0K\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8864 "bacon.bac"
__b2c__assign = (char*)"#define ENDFILE(x) feof(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8865 "bacon.bac"
__b2c__assign = (char*)"#define EQ =="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8866 "bacon.bac"
__b2c__assign = (char*)"#define EQUAL(x, y) !__b2c__STRCMP(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8867 "bacon.bac"
__b2c__assign = (char*)"#define ESCAPE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__escape(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8868 "bacon.bac"
__b2c__assign = (char*)"#define EVAL(x, y, z, q) __b2c__eval(__LINE__, __FILE__, x, y, z, q)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8869 "bacon.bac"
__b2c__assign = (char*)"#define EVEN(x) (((long)(x) % 2 == 0) ? 1 : 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8870 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXCHANGE3(x, y, z) __b2c__exchange(x, y, z, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8871 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXCHANGE4(x, y, z, f) __b2c__exchange(x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8872 "bacon.bac"
__b2c__assign = (char*)"#define EXCHANGE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__EXCHANGE4, __b2c__EXCHANGE3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8873 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXEC1(x) __b2c__exec(0, __LINE__, __FILE__, x, NULL, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8874 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXEC2(x, y) __b2c__exec(0, __LINE__, __FILE__, x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8875 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXEC3(x, y, z) __b2c__exec(0, __LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8876 "bacon.bac"
__b2c__assign = (char*)"#define EXEC"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXEC3, __b2c__EXEC2, __b2c__EXEC1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8877 "bacon.bac"
__b2c__assign = (char*)"#define EXP(x) exp((double)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8878 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXPLODE1(x) __b2c__explode(__LINE__, __FILE__, x, 1, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8879 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXPLODE2(x, y) __b2c__explode(__LINE__, __FILE__, x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8880 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXPLODE3(x, y, z) __b2c__explode(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8881 "bacon.bac"
__b2c__assign = (char*)"#define EXPLODE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXPLODE3, __b2c__EXPLODE2, __b2c__EXPLODE1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8882 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXTRACT2(x, y) __b2c__extract(__LINE__, __FILE__, x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8883 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__EXTRACT3(x, y, z) __b2c__extract(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8884 "bacon.bac"
__b2c__assign = (char*)"#define EXTRACT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__EXTRACT3, __b2c__EXTRACT2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8885 "bacon.bac"
__b2c__assign = (char*)"#define FALSE 0"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8886 "bacon.bac"
__b2c__assign = (char*)"#define FILEEXISTS(x) __b2c__filestat(__LINE__, __FILE__, x, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8887 "bacon.bac"
__b2c__assign = (char*)"#define FILELEN(x) __b2c__filestat(__LINE__, __FILE__, x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8888 "bacon.bac"
__b2c__assign = (char*)"#define FILETIME(x, y) __b2c__filetime(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8889 "bacon.bac"
__b2c__assign = (char*)"#define FILETYPE(x) __b2c__filetype(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8890 "bacon.bac"
__b2c__assign = (char*)"#define FILL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x, y) __b2c__fill(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8891 "bacon.bac"
__b2c__assign = (char*)"#define FIND(x, y, z, a) __b2c__find(x, y, z, a)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8892 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FIRST1(x) __b2c__first(x, 1, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8893 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FIRST2(x, y) __b2c__first(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8894 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FIRST3(x, y, z) __b2c__first(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8895 "bacon.bac"
__b2c__assign = (char*)"#define FIRST"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__FIRST3, __b2c__FIRST2, __b2c__FIRST1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8896 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FLATTEN1(x) __b2c__flatten(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8897 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FLATTEN2(x, y) __b2c__flatten(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8898 "bacon.bac"
__b2c__assign = (char*)"#define FLATTEN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__FLATTEN2, __b2c__FLATTEN1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8899 "bacon.bac"
__b2c__assign = (char*)"#define FLOATING double"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8900 "bacon.bac"
__b2c__assign = (char*)"#define FLOOR(x) (long)floor(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8901 "bacon.bac"
__b2c__assign = (char*)"#define FORK fork()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8902 "bacon.bac"
__b2c__assign = (char*)"#define FP(x) (void*)(&x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8903 "bacon.bac"
__b2c__assign = (char*)"#define GE >="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8904 "bacon.bac"
__b2c__assign = (char*)"#define GETENVIRON"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__getenv(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8905 "bacon.bac"
__b2c__assign = (char*)"#define GETKEY __b2c__getch()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8906 "bacon.bac"
__b2c__assign = (char*)"#define GETPEER"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__getpeer(__LINE__, __FILE__, (uintptr_t)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8907 "bacon.bac"
__b2c__assign = (char*)"#define GETX __b2c__getxy(0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8908 "bacon.bac"
__b2c__assign = (char*)"#define GETY __b2c__getxy(1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8909 "bacon.bac"
__b2c__assign = (char*)"#define GUIDEFINE(x) __b2c__guiDefine()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8910 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__GUIEVENT1(x) __b2c__guiExecute(x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8911 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__GUIEVENT2(x, y) __b2c__guiExecute(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8912 "bacon.bac"
__b2c__assign = (char*)"#define GUIEVENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__GUIEVENT2, __b2c__GUIEVENT1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8913 "bacon.bac"
if( g_WHICH_GUI == 4 ){
#line 8914 "bacon.bac"
__b2c__assign = (char*)"#define GUIFN(id, x) Tcl_Eval((Tcl_Interp*)id, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8915 "bacon.bac"
} else {
#line 8916 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__GUIFN1(id, x, func) func(GUIWIDGET(id, x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8917 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__GUIFN2(id, x, func, ...) func(GUIWIDGET(id, x), __VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8918 "bacon.bac"
__b2c__assign = (char*)"#define GUIFN(...) __b2c__FUNCSELECT10(__VA_ARGS__, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN2, __b2c__GUIFN1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8919 "bacon.bac"
}
#line 8920 "bacon.bac"
if( g_WHICH_GUI == 2 ){
#line 8921 "bacon.bac"
__b2c__assign = (char*)"#define GUIWIDGET(id, x) __b2c_get_by_name(id, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8922 "bacon.bac"
__b2c__assign = (char*)"#define GUIGET(id, x, p, q) (*(q)) = getCDK ## p( ( GUIWIDGET(id, x) == NULL ? (void*)(uintptr_t)fprintf(stderr, \"Runtime error: function 'GUIGET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(42)) : GUIWIDGET(id, x) ) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8923 "bacon.bac"
__b2c__assign = (char*)"#define GUISET(id, x, p, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUISET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(42)) : setCDK ## p(GUIWIDGET(id, x), __VA_ARGS__) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8924 "bacon.bac"
__b2c__assign = (char*)"#define GUICB(x, y, z, q) bindCDKObject(x, y, z, __b2c_cdk_callback, q)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8925 "bacon.bac"
} else if( g_WHICH_GUI == 1  OR  g_WHICH_GUI == 3 ){
#line 8926 "bacon.bac"
__b2c__assign = (char*)"#define GUIWIDGET(id, x) __b2c_get_by_name(id, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8927 "bacon.bac"
__b2c__assign = (char*)"#define GUIGET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUIGET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(42)) : g_object_get(G_OBJECT(GUIWIDGET(id, x)), __VA_ARGS__, NULL) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8928 "bacon.bac"
__b2c__assign = (char*)"#define GUISET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUISET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(42)) : g_object_set(G_OBJECT(GUIWIDGET(id, x)), __VA_ARGS__, NULL) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8929 "bacon.bac"
__b2c__assign = (char*)"#define GUICB(x, y, z) g_signal_connect_swapped(G_OBJECT(x), y, G_CALLBACK(__b2c_gtk_callback), z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8930 "bacon.bac"
} else if( g_WHICH_GUI == 0 ){
#line 8931 "bacon.bac"
__b2c__assign = (char*)"#define GUIWIDGET(id, x) XtNameToWidget((Widget)id, \"*\" x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8932 "bacon.bac"
__b2c__assign = (char*)"#define GUIGET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUIGET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(42)) : XtVaGetValues(GUIWIDGET(id, x), __VA_ARGS__, NULL) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8933 "bacon.bac"
__b2c__assign = (char*)"#define GUISET(id, x, ...) ( GUIWIDGET(id, x) == NULL ? fprintf(stderr, \"Runtime error: function 'GUISET' at line %d in '%s': %s\\n\", __LINE__, __FILE__, ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(42)) : XtVaSetValues(GUIWIDGET(id, x), __VA_ARGS__, NULL) )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8934 "bacon.bac"
__b2c__assign = (char*)"#define GUICB(x, y, z) XtAddCallback(x, y, __b2c_xt_callback, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8935 "bacon.bac"
} else {
#line 8936 "bacon.bac"
__b2c__assign = (char*)"#define GUIWIDGET(id, x) x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8937 "bacon.bac"
__b2c__assign = (char*)"#define GUIGET(id, x, y) y = __b2c_Copy_String(y, (char*)Tcl_GetVar((Tcl_Interp*)id, x, TCL_GLOBAL_ONLY))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8938 "bacon.bac"
__b2c__assign = (char*)"#define GUISET(id, x, y) Tcl_SetVar((Tcl_Interp*)id, x, y, TCL_GLOBAL_ONLY)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8939 "bacon.bac"
__b2c__assign = (char*)"#define GUICB(id, x, y) Tcl_CreateObjCommand((Tcl_Interp*)id, x, __b2c_tk_callback, (ClientData)y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8940 "bacon.bac"
}
#line 8941 "bacon.bac"
__b2c__assign = (char*)"#define GT >"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8942 "bacon.bac"
__b2c__assign = (char*)"#define HASBOM(x) __b2c__hasbom(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8943 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HASDELIM1(x) __b2c__hasdelim(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8944 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HASDELIM2(x, y) __b2c__hasdelim(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8945 "bacon.bac"
__b2c__assign = (char*)"#define HASDELIM(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASDELIM2, __b2c__HASDELIM1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8946 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HASH1(x) HASH_FUNC((char*)x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8947 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HASH2(x, y) HASH_FUNC((char*)x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8948 "bacon.bac"
__b2c__assign = (char*)"#define HASH(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__HASH2, __b2c__HASH1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8949 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HEAD1(x) __b2c__head(x, 1, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8950 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HEAD2(x, y) __b2c__head(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8951 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HEAD3(x, y, z) __b2c__head(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8952 "bacon.bac"
__b2c__assign = (char*)"#define HEAD"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__HEAD3, __b2c__HEAD2, __b2c__HEAD1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8953 "bacon.bac"
__b2c__assign = (char*)"#define HEX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__dec2hex(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8954 "bacon.bac"
__b2c__assign = (char*)"#define HOST"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__nethost(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8955 "bacon.bac"
__b2c__assign = (char*)"#define HOSTNAME"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " __b2c__hostname(__LINE__, __FILE__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8956 "bacon.bac"
__b2c__assign = (char*)"#define HOUR(x) __b2c__time(x, 4)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8957 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__IIF2(x, y) (x ? y : 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8958 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__IIF3(x, y, z) (x ? y : z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8959 "bacon.bac"
__b2c__assign = (char*)"#define IIF(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIF3, __b2c__IIF2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8960 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__IIFS2(x, y) (char*)(x ? y : NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8961 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__IIFS3(x, y, z) (char*)(x ? y : z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8962 "bacon.bac"
__b2c__assign = (char*)"#define IIF"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__IIFS3, __b2c__IIFS2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8963 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INBETWEEN3(x, y, z) __b2c__inbetween(0, x, y, z, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8964 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INBETWEEN4(x, y, z, f) __b2c__inbetween(0, x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8965 "bacon.bac"
__b2c__assign = (char*)"#define INBETWEEN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__INBETWEEN4, __b2c__INBETWEEN3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8966 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INDEX4(r, t, x, y) __b2c__index(__LINE__, __FILE__, r+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_GENERIC);
__b2c__assign = (char*) ", t, (void*)x, 0, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8967 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INDEX5(r, t, x, y, z) __b2c__index(__LINE__, __FILE__, r+"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_GENERIC);
__b2c__assign = (char*) ", t, (void*)x, z, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8968 "bacon.bac"
__b2c__assign = (char*)"#define INDEX(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__INDEX5, __b2c__INDEX4)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8969 "bacon.bac"
__b2c__assign = (char*)"#define INDEX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(t, x, y) __b2c__index_assoc(__LINE__, __FILE__, t, (__b2c__htable*)__b2c__assoc_ ## x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8970 "bacon.bac"
__b2c__assign = (char*)"#define INSERT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x, y, z) __b2c__insert(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8971 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INSTR2(x, y) __b2c__instr(__LINE__, __FILE__, x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8972 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INSTR3(x, y, z) __b2c__instr(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8973 "bacon.bac"
__b2c__assign = (char*)"#define INSTR(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTR3, __b2c__INSTR2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8974 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INSTRREV2(x, y) __b2c__instrrev(__LINE__, __FILE__, x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8975 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__INSTRREV3(x, y, z) __b2c__instrrev(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8976 "bacon.bac"
__b2c__assign = (char*)"#define INSTRREV(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__INSTRREV3, __b2c__INSTRREV2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8977 "bacon.bac"
__b2c__assign = (char*)"#define INT(x) lrint((double)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8978 "bacon.bac"
__b2c__assign = (char*)"#define INTL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) gettext(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8979 "bacon.bac"
__b2c__assign = (char*)"#define INVERT(t, x) __b2c__invert(__LINE__, __FILE__, t, &__b2c__assoc_ ## x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8980 "bacon.bac"
__b2c__assign = (char*)"#define IS =="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8981 "bacon.bac"
__b2c__assign = (char*)"#define ISASCII(x) __b2c__isascii(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8982 "bacon.bac"
__b2c__assign = (char*)"#define ISFALSE(x) ((x) == 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8983 "bacon.bac"
__b2c__assign = (char*)"#define ISKEY(x, ...) (__b2c__hash_find_key_do(__b2c__assoc_ ## x, 0, __b2c__KEYCOLLECT(__VA_ARGS__)) == NULL ? 0 : 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8984 "bacon.bac"
__b2c__assign = (char*)"#define ISNOT !="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8985 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ISTOKEN2(x, y) __b2c__istoken(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8986 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ISTOKEN3(x, y, z) __b2c__istoken(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8987 "bacon.bac"
__b2c__assign = (char*)"#define ISTOKEN(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ISTOKEN3, __b2c__ISTOKEN2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8988 "bacon.bac"
__b2c__assign = (char*)"#define ISTRUE(x) ((x) != 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8989 "bacon.bac"
__b2c__assign = (char*)"#define ISUTF8(x) __b2c__isutf8(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8990 "bacon.bac"
__b2c__assign = (char*)"#define LCASE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__lcase(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8991 "bacon.bac"
__b2c__assign = (char*)"#define LE <="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8992 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__LEFT1(x) __b2c__left(__LINE__, __FILE__, x, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8993 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__LEFT2(x, y) __b2c__left(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8994 "bacon.bac"
__b2c__assign = (char*)"#define LEFT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__LEFT2, __b2c__LEFT1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8995 "bacon.bac"
__b2c__assign = (char*)"#define LEN(x) (__b2c__option_utf8 ? __b2c__ulen(__LINE__, __FILE__, \"LEN\", (char*)x, -1) : __b2c__len(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8996 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ULEN1(x) __b2c__ulen(__LINE__, __FILE__, \"ULEN\", (char*)x, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8997 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ULEN2(x, y) __b2c__ulen(__LINE__, __FILE__, \"ULEN\", (char*)x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8998 "bacon.bac"
__b2c__assign = (char*)"#define ULEN(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__ULEN2, __b2c__ULEN1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 8999 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__LAST1(x) __b2c__last(x, 1, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9000 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__LAST2(x, y) __b2c__last(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9001 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__LAST3(x, y, z) __b2c__last(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9002 "bacon.bac"
__b2c__assign = (char*)"#define LAST"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__LAST3, __b2c__LAST2, __b2c__LAST1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9003 "bacon.bac"
__b2c__assign = (char*)"#define LINENO __LINE__"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9004 "bacon.bac"
__b2c__assign = (char*)"#define LOAD"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__load(0, __LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9005 "bacon.bac"
__b2c__assign = (char*)"#define LOG(x) log((double)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9006 "bacon.bac"
__b2c__assign = (char*)"#define LOOP"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper(__b2c__loop2) : __b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9007 "bacon.bac"
__b2c__assign = (char*)"#define LOOP(...) ( !setjmp(__b2c__loop1) ? __b2c__loop_helper2(__b2c__loop2) : __b2c__loop_result )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9008 "bacon.bac"
__b2c__assign = (char*)"#define LT <"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9009 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MATCH2(x, y) __b2c__match(x, y, -1, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9010 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MATCH3(x, y, z) __b2c__match(x, y, z, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9011 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MATCH4(x, y, z, f) __b2c__match(x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9012 "bacon.bac"
__b2c__assign = (char*)"#define MATCH(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__MATCH4, __b2c__MATCH3, __b2c__MATCH2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9013 "bacon.bac"
__b2c__assign = (char*)"#define MAX(x, y) fmax(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9014 "bacon.bac"
__b2c__assign = (char*)"#define MAX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x, y) __b2c__max_str(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9015 "bacon.bac"
__b2c__assign = (char*)"#define MAXNUM(x) (x)POW(2, SIZEOF(x)*8)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9016 "bacon.bac"
if( INSTR(OS__b2c__string_var, "SunOS")  OR  INSTR(OS__b2c__string_var, "OSF1") ){
#line 9017 "bacon.bac"
__b2c__assign = (char*)"#define MAXRANDOM 2147483647"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9018 "bacon.bac"
} else {
#line 9019 "bacon.bac"
__b2c__assign = (char*)"#define MAXRANDOM RAND_MAX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9020 "bacon.bac"
}
#line 9021 "bacon.bac"
__b2c__assign = (char*)"#define ME"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " __b2c__me_var"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9022 "bacon.bac"
__b2c__assign = (char*)"#define MEMCHECK(x) __b2c__memory__check((char*)x, sizeof(__b2c__MEMTYPE))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9023 "bacon.bac"
__b2c__assign = (char*)"#define MEMORY(x) (calloc(x+__b2c__option_memstream, sizeof(__b2c__MEMTYPE)))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9024 "bacon.bac"
__b2c__assign = (char*)"#define MEMTELL(x) (long)x"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9025 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MERGE1(x) __b2c__merge(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9026 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MERGE2(x, y) __b2c__merge(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9027 "bacon.bac"
__b2c__assign = (char*)"#define MERGE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__MERGE2, __b2c__MERGE1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9028 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MID2(x, y) __b2c__mid(__LINE__, __FILE__, NULL, 0, x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9029 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MID3(x, y, z) __b2c__mid(__LINE__, __FILE__, NULL, 0, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9030 "bacon.bac"
__b2c__assign = (char*)"#define MID"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MID3, __b2c__MID2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9031 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FMID3(s, x, y) __b2c__mid(__LINE__, __FILE__, &s, 1, x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9032 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__FMID4(s, x, y, z) __b2c__mid(__LINE__, __FILE__, &s, 1, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9033 "bacon.bac"
__b2c__assign = (char*)"#define F_MID"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__FMID4, __b2c__FMID3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9034 "bacon.bac"
__b2c__assign = (char*)"#define MIN(x, y) fmin(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9035 "bacon.bac"
__b2c__assign = (char*)"#define MIN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x, y) __b2c__min_str(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9036 "bacon.bac"
__b2c__assign = (char*)"#define MINUTE(x) __b2c__time(x, 5)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9037 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MOD2(x, y) ((long)(x) % (long)(y))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9038 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__MOD3(x, y, z) (z == 0 ? ((long)(x) % (long)(y)) : fmod((double)x, (double)y))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9039 "bacon.bac"
__b2c__assign = (char*)"#define MOD(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__MOD3, __b2c__MOD2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9040 "bacon.bac"
__b2c__assign = (char*)"#define MONTH(x) __b2c__time(x, 2)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9041 "bacon.bac"
__b2c__assign = (char*)"#define MONTH"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__datename(x, 2)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9042 "bacon.bac"
__b2c__assign = (char*)"#define MYPID getpid()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9043 "bacon.bac"
__b2c__assign = (char*)"#define NANOTIMER __b2c__nanotimer(0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9044 "bacon.bac"
__b2c__assign = (char*)"#define NE !="; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9045 "bacon.bac"
__b2c__assign = (char*)"#define NL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " \"\\n\""; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9046 "bacon.bac"
__b2c__assign = (char*)"#define NNTL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x,y,z) ngettext(x,y,z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9047 "bacon.bac"
__b2c__assign = (char*)"#define NOT(x) (!(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9048 "bacon.bac"
__b2c__assign = (char*)"#define NOW (long)time(NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9049 "bacon.bac"
__b2c__assign = (char*)"#define NRKEYS(x) __b2c__hash_nrkeys(__b2c__assoc_ ## x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9050 "bacon.bac"
__b2c__assign = (char*)"#define NUMBER long"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9051 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__OBTAIN1(x) __b2c__hash_obtain(__b2c__assoc_ ## x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9052 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__OBTAIN2(x, y) __b2c__hash_obtain(__b2c__assoc_ ## x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9053 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__OBTAIN3(x, y, z) __b2c__hash_obtain_by_sort(__LINE__, __FILE__, __b2c__assoc_ ## x, y, z, __b2c__obtain_type_ ## x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9054 "bacon.bac"
__b2c__assign = (char*)"#define OBTAIN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__OBTAIN3, __b2c__OBTAIN2, __b2c__OBTAIN1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9055 "bacon.bac"
__b2c__assign = (char*)"#define ODD(x) (((long)(x) % 2 != 0) ? 1 : 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9056 "bacon.bac"
__b2c__assign = (char*)"#define OR ||"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9057 "bacon.bac"
__b2c__assign = (char*)"#define OS"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) " __b2c__os(__LINE__, __FILE__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9058 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__OUTBETWEEN3(x, y, z) __b2c__inbetween(1, x, y, z, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9059 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__OUTBETWEEN4(x, y, z, f) __b2c__inbetween(1, x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9060 "bacon.bac"
__b2c__assign = (char*)"#define OUTBETWEEN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__OUTBETWEEN4, __b2c__OUTBETWEEN3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9061 "bacon.bac"
__b2c__assign = (char*)"#define PEEK(x) *(__b2c__MEMTYPE*)__b2c__peek_check(__LINE__, __FILE__, (char*)x, sizeof(__b2c__MEMTYPE))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9062 "bacon.bac"
__b2c__assign = (char*)"#define PI 3.14159265358979323846"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9063 "bacon.bac"
__b2c__assign = (char*)"#define POW(x, y) pow((double)x, (double)y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9064 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__PROPER1(x) __b2c__proper(__LINE__, __FILE__, x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9065 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__PROPER2(x, y) __b2c__proper(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9066 "bacon.bac"
__b2c__assign = (char*)"#define PROPER"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__PROPER2, __b2c__PROPER1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9067 "bacon.bac"
__b2c__assign = (char*)"#define RAD(x) (x*PI/180)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9068 "bacon.bac"
__b2c__assign = (char*)"#define RANDOM(x) (long)((x+0.0)*random()/(MAXRANDOM+0.0))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9069 "bacon.bac"
__b2c__assign = (char*)"#define REALPATH"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__dirname(__LINE__, __FILE__, 0, x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9070 "bacon.bac"
__b2c__assign = (char*)"#define REAP(x) waitpid(x, NULL, WNOHANG)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9071 "bacon.bac"
__b2c__assign = (char*)"#define REGEX(x, y) __b2c__regex(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9072 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__REPLACE3(x, y, z) __b2c__replace(__LINE__, __FILE__, x, y, z, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9073 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__REPLACE4(x, y, z, f) __b2c__replace(__LINE__, __FILE__, x, y, z, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9074 "bacon.bac"
__b2c__assign = (char*)"#define REPLACE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT4(__VA_ARGS__, __b2c__REPLACE4, __b2c__REPLACE3)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9075 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__REV1(x) __b2c__rev(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9076 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__REV2(x, y) __b2c__rev(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9077 "bacon.bac"
__b2c__assign = (char*)"#define REV"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__REV2, __b2c__REV1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9078 "bacon.bac"
__b2c__assign = (char*)"#define REVERSE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__reverse(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9079 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RIGHT1(x) __b2c__right(__LINE__, __FILE__, x, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9080 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RIGHT2(x, y) __b2c__right(__LINE__, __FILE__, x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9081 "bacon.bac"
__b2c__assign = (char*)"#define RIGHT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__RIGHT2, __b2c__RIGHT1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9082 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RIP2(x, y) __b2c__rip(__LINE__, __FILE__, x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9083 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RIP3(x, y, z) __b2c__rip(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9084 "bacon.bac"
__b2c__assign = (char*)"#define RIP"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RIP3, __b2c__RIP2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9085 "bacon.bac"
__b2c__assign = (char*)"#define RND random()"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9086 "bacon.bac"
__b2c__assign = (char*)"#define ROL(x) __b2c__rol(sizeof(__b2c__MEMTYPE), x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9087 "bacon.bac"
__b2c__assign = (char*)"#define ROR(x) __b2c__ror(sizeof(__b2c__MEMTYPE), x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9088 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ROTATE2(x, y) __b2c__rotate(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9089 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__ROTATE3(x, y, z) __b2c__rotate(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9090 "bacon.bac"
__b2c__assign = (char*)"#define ROTATE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__ROTATE3, __b2c__ROTATE2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9091 "bacon.bac"
__b2c__assign = (char*)"#define ROUND(x) lrint((double)x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9092 "bacon.bac"
__b2c__assign = (char*)"#define ROWS __b2c__screen(1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9093 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RUN1(x) __b2c__exec(1, __LINE__, __FILE__, x, NULL, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9094 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RUN2(x, y) __b2c__exec(1, __LINE__, __FILE__, x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9095 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__RUN3(x, y, z) __b2c__exec(1, __LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9096 "bacon.bac"
__b2c__assign = (char*)"#define RUN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__RUN3, __b2c__RUN2, __b2c__RUN1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9097 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__SEARCH2(x, y) __b2c__search(__LINE__, __FILE__, x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9098 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__SEARCH3(x, y, z) __b2c__search(__LINE__, __FILE__, x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9099 "bacon.bac"
__b2c__assign = (char*)"#define SEARCH(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__SEARCH3, __b2c__SEARCH2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9100 "bacon.bac"
__b2c__assign = (char*)"#define SECOND(x) __b2c__time(x, 6)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9101 "bacon.bac"
__b2c__assign = (char*)"#define SETENVIRON(x, y) __b2c__setenviron(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9102 "bacon.bac"
__b2c__assign = (char*)"#define SGN(x) __b2c__sgn((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9103 "bacon.bac"
__b2c__assign = (char*)"#define SIN(x) sin((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9104 "bacon.bac"
__b2c__assign = (char*)"#define SIZEOF(x) sizeof(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9105 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__SORT1(x) __b2c__sort(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9106 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__SORT2(x, y) __b2c__sort(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9107 "bacon.bac"
__b2c__assign = (char*)"#define SORT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__SORT2, __b2c__SORT1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9108 "bacon.bac"
__b2c__assign = (char*)"#define SPC"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__spc(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9109 "bacon.bac"
__b2c__assign = (char*)"#define SQR(x) sqrt((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9110 "bacon.bac"
__b2c__assign = (char*)"#define STR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__str(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9111 "bacon.bac"
__b2c__assign = (char*)"#define STRING char*"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9112 "bacon.bac"
__b2c__assign = (char*)"#define SUM(x,...) __b2c__sum("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_GENERIC);
__b2c__assign = (char*) ", x, __VA_ARGS__, LONG_MAX)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9113 "bacon.bac"
__b2c__assign = (char*)"#define SUMF(x,...) __b2c__sumf("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_GENERIC);
__b2c__assign = (char*) ", x, __VA_ARGS__, DBL_MAX)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9114 "bacon.bac"
__b2c__assign = (char*)"#define TAB"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__tab(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9115 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TAIL1(x) __b2c__tail(x, 1, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9116 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TAIL2(x, y) __b2c__tail(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9117 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TAIL3(x, y, z) __b2c__tail(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9118 "bacon.bac"
__b2c__assign = (char*)"#define TAIL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TAIL3, __b2c__TAIL2, __b2c__TAIL1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9119 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TALLY2(x, y) __b2c__tally(x, y, -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9120 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TALLY3(x, y, z) __b2c__tally(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9121 "bacon.bac"
__b2c__assign = (char*)"#define TALLY(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TALLY3, __b2c__TALLY2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9122 "bacon.bac"
__b2c__assign = (char*)"#define TAN(x) tan((double)(x))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9123 "bacon.bac"
__b2c__assign = (char*)"#define TELL(x) ftell(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9124 "bacon.bac"
__b2c__assign = (char*)"#define TIMER __b2c__timer(0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9125 "bacon.bac"
__b2c__assign = (char*)"#define TIMEVALUE(x,y,z,a,b,c) __b2c__epoch(x,y,z,a,b,c)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9126 "bacon.bac"
__b2c__assign = (char*)"#define TOASCII"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__toascii(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9127 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TOKEN2(x, y) __b2c__token(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9128 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__TOKEN3(x, y, z) __b2c__token(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9129 "bacon.bac"
__b2c__assign = (char*)"#define TOKEN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__TOKEN3, __b2c__TOKEN2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9130 "bacon.bac"
__b2c__assign = (char*)"#define TOTAL(x) __b2c__total(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9131 "bacon.bac"
__b2c__assign = (char*)"#define TRUE 1"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9132 "bacon.bac"
__b2c__assign = (char*)"#define UCASE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__ucase(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9133 "bacon.bac"
__b2c__assign = (char*)"#define UCS(x) (unsigned int)__b2c__utf8toasc(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9134 "bacon.bac"
__b2c__assign = (char*)"#define UNESCAPE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__unescape(__LINE__, __FILE__, x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9135 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__UNFLATTEN1(x) __b2c__unflatten(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9136 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__UNFLATTEN2(x, y) __b2c__unflatten(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9137 "bacon.bac"
__b2c__assign = (char*)"#define UNFLATTEN"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNFLATTEN2, __b2c__UNFLATTEN1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9138 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__UNIQ1(x) __b2c__uniq(x, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9139 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__UNIQ2(x, y) __b2c__uniq(x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9140 "bacon.bac"
__b2c__assign = (char*)"#define UNIQ"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT2(__VA_ARGS__, __b2c__UNIQ2, __b2c__UNIQ1)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9141 "bacon.bac"
__b2c__assign = (char*)"#define VAL(x) __b2c__val(x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9142 "bacon.bac"
__b2c__assign = (char*)"#define WAIT(x, y) __b2c__netpeek(__LINE__, __FILE__, (uintptr_t)x, y)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9143 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__WALK4(x, y, z, q) __b2c__walk(__LINE__, __FILE__, x, y, z, q, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9144 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__WALK5(x, y, z, q, f) __b2c__walk(__LINE__, __FILE__, x, y, z, q, f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9145 "bacon.bac"
__b2c__assign = (char*)"#define WALK"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(...) __b2c__FUNCSELECT5(__VA_ARGS__, __b2c__WALK5, __b2c__WALK4)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9146 "bacon.bac"
__b2c__assign = (char*)"#define WEEK(x) __b2c__time(x, 7)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9147 "bacon.bac"
__b2c__assign = (char*)"#define WEEKDAY"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
__b2c__assign = (char*) "(x) __b2c__datename(x, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9148 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__WHERE2(x, y) __b2c__where(x, y, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9149 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__WHERE3(x, y, z) __b2c__where(x, y, z)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9150 "bacon.bac"
__b2c__assign = (char*)"#define WHERE(...) __b2c__FUNCSELECT3(__VA_ARGS__, __b2c__WHERE3, __b2c__WHERE2)(__VA_ARGS__)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9151 "bacon.bac"
__b2c__assign = (char*)"#define YEAR(x) __b2c__time(x, 3)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9152 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__cacerts NULL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9153 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__capeer 0"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9154 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__caprivate NULL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9155 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__caserver NULL"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_GENERIC); }
fputs("\n", g_GENERIC);
#line 9157 "bacon.bac"
fclose(g_GENERIC);
fclose( g_CFILE);
fclose( FLOATARRAYFILE);
fclose( STRINGARRAYFILE);
#line 9160 "bacon.bac"
g_FUNCTIONS = fopen((const char*)g_FUNCTIONS__b2c__string_var, "w");
if(g_FUNCTIONS == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 9160, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 9161 "bacon.bac"
__b2c__assign = (char*)"/* Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9162 "bacon.bac"
__b2c__assign = (char*)g_TWEAK__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9165 "bacon.bac"
__b2c__assign = (char*)"char *ERR"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) "(int nr){ static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long flen = 0, slen = 0; char *first = NULL, *second = NULL; switch (nr)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9166 "bacon.bac"
__b2c__assign = (char*)"{ case 0: first = \"Success\"; break; case 1: first = \"Trying to access illegal memory: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9167 "bacon.bac"
__b2c__assign = (char*)"case 2: first = \"Error opening file: \"; second = strerror (errno); break; case 3: first = \"Could not open library.\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9168 "bacon.bac"
__b2c__assign = (char*)"case 4: first = \"Symbol not found in library.\"; break; case 5: first = \"Wrong value: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9169 "bacon.bac"
__b2c__assign = (char*)"case 6: first = \"Unable to claim memory.\"; break; case 7: first = \"Unable to delete file: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9170 "bacon.bac"
__b2c__assign = (char*)"case 8: first = \"Could not open directory: \"; second = strerror(errno); break; case 9: first = \"Unable to rename file: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9171 "bacon.bac"
__b2c__assign = (char*)"case 10: first = \"NETWORK argument should contain colon with port number\"; break; case 11: first = \"Could not resolve hostname!\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9172 "bacon.bac"
__b2c__assign = (char*)"case 12: first = \"Socket error: \"; second = strerror(errno); break; case 13: first = \"Unable to open address: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9173 "bacon.bac"
__b2c__assign = (char*)"case 14: first = \"Error reading from socket: \"; second = strerror(errno); break; case 15: first = \"Error sending to socket: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9174 "bacon.bac"
__b2c__assign = (char*)"case 16: first = \"Error checking socket: \"; second = strerror(errno); break; case 17: first = \"Unable to bind the specified socket address: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9175 "bacon.bac"
__b2c__assign = (char*)"case 18: first = \"Unable to listen to socket address: \"; second = strerror(errno); break; case 19: first = \"Cannot accept incoming connection: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9176 "bacon.bac"
__b2c__assign = (char*)"case 20: first = \"Unable to remove directory: \"; second = strerror(errno); break; case 21: first = \"Unable to create directory: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9177 "bacon.bac"
__b2c__assign = (char*)"case 22: first = \"Unable to change to directory: \"; second = strerror(errno); break; case 23: first = \"GETENVIRON argument does not exist as environment variable\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9178 "bacon.bac"
__b2c__assign = (char*)"case 24: first = \"Unable to stat file: \"; second = strerror(errno); break; case 25: first = \"Search contains illegal string\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9179 "bacon.bac"
__b2c__assign = (char*)"case 26: first = \"Cannot return name: \"; second = strerror(errno); break; case 27: first = \"Illegal regex expression\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9180 "bacon.bac"
__b2c__assign = (char*)"case 28: first = \"Unable to create bidirectional pipes: \"; second = strerror(errno); break; case 29: first = \"Unable to fork process: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9181 "bacon.bac"
__b2c__assign = (char*)"case 30: first = \"Cannot read from pipe: \"; second = strerror(errno); break; case 31: first = \"Gosub nesting too deep!\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9182 "bacon.bac"
__b2c__assign = (char*)"case 32: first = \"Could not open device: \"; second = strerror(errno); break; case 33: first = \"Error configuring serial port: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9183 "bacon.bac"
__b2c__assign = (char*)"case 34: first = \"Error accessing device: \"; second = strerror(errno); break; case 35: first = \"Error in INPUT: \"; second = strerror(errno); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9184 "bacon.bac"
__b2c__assign = (char*)"case 36: first = \"Illegal value in SORT dimension!\"; break; case 37: first = \"Illegal option for SEARCH!\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9185 "bacon.bac"
__b2c__assign = (char*)"case 38: first = \"Invalid UTF8 string!\"; break; case 39: first = \"Illegal EVAL expression!\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9186 "bacon.bac"
__b2c__assign = (char*)"case 40: first = \"SSL file descriptor error!\"; break; case 41: first = \"Error loading certificate!\"; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9187 "bacon.bac"
__b2c__assign = (char*)"case 42: first = \"Widget not found!\"; ERROR = 42; break; case 43: first = \"Unsupported array type!\"; break; };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9188 "bacon.bac"
__b2c__assign = (char*)"if(first) { flen = strlen(first); } if(second) { slen = strlen(second); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], flen+slen+1);if(first)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9189 "bacon.bac"
__b2c__assign = (char*)"{ memmove(buf[idx], first, flen); } if(second) { memmove(buf[idx]+flen, second, slen); } __b2c__SETLEN(buf[idx], flen+slen); buf[idx][flen+slen] = '\\0'; return((char*)buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9192 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__strdup(char *s) { if(s == NULL) { return(NULL); } return(__b2c_Copy_String(NULL, s)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9193 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__strndup(char *s, size_t n) { if(s == NULL) { return(NULL); } return(__b2c_Copy_N_String(NULL, s, n)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9194 "bacon.bac"
__b2c__assign = (char*)"int __b2c__strcmp(const char *__b2c__s1, const char *__b2c__s2){ int len1 = 0, len2 = 0; len1 = __b2c__len(__b2c__s1); len2 = __b2c__len(__b2c__s2); if((__b2c__s1 == NULL || len1 == 0) && (__b2c__s2 == NULL || len2 == 0)) { return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9195 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__s1 == NULL || len1 == 0) { return(-1); } if(__b2c__s2 == NULL || len2 == 0) { return(1); } return(strcmp(__b2c__s1, __b2c__s2)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9196 "bacon.bac"
__b2c__assign = (char*)"int __b2c__strcasecmp(const char *__b2c__s1, const char *__b2c__s2){ int len1 = 0, len2 = 0; len1 = __b2c__len(__b2c__s1); len2 = __b2c__len(__b2c__s2); if((__b2c__s1 == NULL || len1 == 0) && (__b2c__s2 == NULL || len2 == 0)) { return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9197 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__s1 == NULL || len1 == 0) { return(-1); } if(__b2c__s2 == NULL || len2 == 0) { return(1); } return(strcasecmp(__b2c__s1, __b2c__s2)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9198 "bacon.bac"
__b2c__assign = (char*)"#ifndef __b2c_Pool_Block_Count"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9199 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_Pool_Block_Count 2048"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9200 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9201 "bacon.bac"
__b2c__assign = (char*)"#ifndef __b2c_Pool_Block_Size"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9202 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_Pool_Block_Size 1024"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9203 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9204 "bacon.bac"
__b2c__assign = (char*)"void *__b2c_mempool_realloc_core (void *address, size_t size, int action) { static char bottom[__b2c_Pool_Block_Count*__b2c_Pool_Block_Size] = { 0 }; static void *top = NULL, *current = NULL; static int inited = 0, amount_used = 0; void *result = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9205 "bacon.bac"
__b2c__assign = (char*)"if(!inited) { current = bottom; top = bottom + (__b2c_Pool_Block_Size * __b2c_Pool_Block_Count); *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } switch(action) { case 0: fprintf(stderr, \"Memory pool contains %d slots, each %d bytes, of which %d were used.\\n\", __b2c_Pool_Block_Count, __b2c_Pool_Block_Size, inited);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9206 "bacon.bac"
__b2c__assign = (char*)"break; case 1: if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { *(uintptr_t *)address = (uintptr_t)current; current = address; amount_used--; return(address); } break; case 2:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9207 "bacon.bac"
__b2c__assign = (char*)"if ((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { return(address); } break; default: if(amount_used < __b2c_Pool_Block_Count-1 && size < __b2c_Pool_Block_Size) { if(address == NULL) { result = current;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9208 "bacon.bac"
__b2c__assign = (char*)"current = (void*)*(uintptr_t*)current; amount_used++; if(amount_used == inited) { *(uintptr_t*)current = (uintptr_t)((uint8_t*)current + __b2c_Pool_Block_Size); inited++; } } else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9209 "bacon.bac"
__b2c__assign = (char*)"{ if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = address; } } else { result = realloc(address, size); } } else { if(address == NULL) { result = realloc(address, size); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9210 "bacon.bac"
__b2c__assign = (char*)"else if((uintptr_t)address >= (uintptr_t)bottom && (uintptr_t)address < (uintptr_t)top) { if(size == 0) { *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } else { result = malloc(size > __b2c_Pool_Block_Size ? size : __b2c_Pool_Block_Size);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9211 "bacon.bac"
__b2c__assign = (char*)"memcpy(result, address, __b2c_Pool_Block_Size); *(uintptr_t*)address = (uintptr_t)current; current = address; amount_used--; } } else { result = realloc(address, size); } } break; } return ((void *) result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9212 "bacon.bac"
__b2c__assign = (char*)"#ifndef __b2c_HASH_STR_STORE"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9213 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_HASH_STR_STORE 0x100000"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9214 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9215 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_HASH_STR_INDEX (__b2c_HASH_STR_STORE-1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9216 "bacon.bac"
__b2c__assign = (char*)"#ifndef __b2c_HASH_LINEAR_DEPTH"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9217 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_HASH_LINEAR_DEPTH 16"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9218 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9219 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_get_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { p=NULL; break; }}}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9220 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_del_string(p, e, i, d, l) if(p) { while(e[i] != p) { i++; if(++d == l) { break; } } if(d < l) { e[i] = NULL; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9221 "bacon.bac"
__b2c__assign = (char*)"#define __b2c_add_string(p, e, i, d, l) if(p) { while(e[i] != NULL && e[i]!=p) { i++; if(++d == l) { if(++l == __b2c_HASH_LINEAR_DEPTH) { fprintf (stderr, \"\\nInternal error: cannot register string! Try to tweak the 'hld' parameter.\\n\"); __b2c_str_realloc_debug_string(); exit (EXIT_FAILURE); } } } e[i] = p; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9222 "bacon.bac"
__b2c__assign = (char*)"void *__b2c_str_realloc_core (char *ptr, size_t size, int action) { static char *even_addr[__b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH] = { NULL }; static int linear_depth = 1; char *next; uint32_t lbufsize = 0, rbufsize = 0, idx, len, depth = 0, total = 0; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); switch (action)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9223 "bacon.bac"
__b2c__assign = (char*)"{ case 0: case 1: next = ptr; __b2c_get_string(next, even_addr, idx, depth, linear_depth); if(next) { lbufsize = __b2c__LBUFSIZE (ptr); rbufsize = __b2c__RBUFSIZE (ptr); if (action == 0) { if (rbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2 + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9224 "bacon.bac"
__b2c__assign = (char*)"ptr = next + lbufsize; *(uint32_t *) ((char *) ptr + 4) = size * 2 + 1 + rbufsize; } else { return (ptr); } } else { if (lbufsize <= size) { __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); next = (char*)__b2c_mempool_realloc(ptr - __b2c__BUFOFFSET - lbufsize, __b2c__BUFOFFSET + lbufsize + rbufsize + size * 2);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9225 "bacon.bac"
__b2c__assign = (char*)"memmove (next + lbufsize + size * 2, next + lbufsize, __b2c__BUFOFFSET + rbufsize); ptr = next + size * 2 + lbufsize; *(uint32_t *) ((char *) ptr + 8) = size * 2 + lbufsize; } else { return (ptr); } } } else { rbufsize = __b2c__len (ptr); next = (char*)__b2c_mempool_realloc(ptr, __b2c__BUFOFFSET + rbufsize + size * 2 + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9226 "bacon.bac"
__b2c__assign = (char*)"if (action == 0) { ptr = next; *(uint32_t *) ((char *) ptr) = rbufsize; *(uint32_t *) ((char *) ptr + 4) = rbufsize + size * 2 + 1; *(uint32_t *) ((char *) ptr + 8) = 0; } else { memmove (next + size * 2, next, __b2c__BUFOFFSET + rbufsize); ptr = next+size * 2; *(uint32_t *) ((char *) ptr) = rbufsize;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9227 "bacon.bac"
__b2c__assign = (char*)"*(uint32_t *) ((char *) ptr + 4) = rbufsize + 1; *(uint32_t *) ((char *) ptr + 8) = size * 2; } } ptr += __b2c__BUFOFFSET; idx = (((uintptr_t) ptr % __b2c_HASH_STR_STORE) & __b2c_HASH_STR_INDEX); depth = 0; __b2c_add_string(ptr, even_addr, idx, depth, linear_depth); break; case 2: __b2c_add_string(ptr, even_addr, idx, depth, linear_depth);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9228 "bacon.bac"
__b2c__assign = (char*)"break; case 3: __b2c_del_string(ptr, even_addr, idx, depth, linear_depth); break; case 4: __b2c_get_string(ptr, even_addr, idx, depth, linear_depth); break; case 5: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if (even_addr[idx] != NULL) { total++; len = (*(uint32_t*)(even_addr[idx]-__b2c__BUFOFFSET));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9229 "bacon.bac"
__b2c__assign = (char*)"lbufsize = __b2c__LBUFSIZE(even_addr[idx]); rbufsize = __b2c__RBUFSIZE(even_addr[idx]); if(len > 64) { even_addr[idx][64] = 0; fprintf(stderr, \"Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s[...]\\n\", idx, lbufsize, rbufsize, len, even_addr[idx]); } else { fprintf(stderr, \"Bucketnr:lbuf:rbuf:length:string = %d:%d:%d:%d:%s\\n\", idx, lbufsize, rbufsize, len, even_addr[idx]); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9230 "bacon.bac"
__b2c__assign = (char*)"fprintf(stderr, \"Total optimized strings: %d - max depth: %d\\n\", total, linear_depth); break; case 6: for (idx = 0; idx < __b2c_HASH_STR_STORE + __b2c_HASH_LINEAR_DEPTH; idx++) { if(even_addr[idx] && !__b2c_mempool_realloc_in_block(even_addr[idx])) { free(even_addr[idx] - __b2c__BUFOFFSET - __b2c__LBUFSIZE(even_addr[idx])); } } break; } return (ptr); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9231 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_Copy_String_core(char *x, char *y, int len) { long ylen; if(y == NULL) { __b2c__STRFREE(x); return(NULL); } if(len == -1) { ylen = __b2c__len(y); } else { ylen = len; } if (ylen == 0) { __b2c__STRFREE (x); return (NULL); } x = (char*)__b2c_str_realloc(x, ylen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9232 "bacon.bac"
__b2c__assign = (char*)"memmove(x, y, ylen); __b2c__SETLEN(x, ylen); x[ylen] = '\\0'; return(x); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9233 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_Swap_String(char **x, char **y) { char *ptr; ptr = *x; *x = *y; *y = ptr; return(*x); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9234 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__len (const char *ptr) { if (ptr == NULL) { return (0); } if(__b2c_str_realloc_get_string(ptr)) { return (*(uint32_t *) (ptr - __b2c__BUFOFFSET)); } return ((unsigned long) strlen (ptr)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9235 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__loop_helper(jmp_buf buf) { if(__b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) " != NULL) { __b2c__SETLEN (__b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) ", 0); __b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) " = __b2c_Copy_String(__b2c__loop_result"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) ", NULL); } longjmp(buf, 1); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9236 "bacon.bac"
__b2c__assign = (char*)"long __b2c__loop_helper2(jmp_buf buf) { __b2c__loop_result = 0; longjmp(buf, 1); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9237 "bacon.bac"
__b2c__assign = (char*)"void __b2c__free_str_array_members(char ***array, int base, int size) { int i; if(*array != NULL) { for(i=0; i < size; i++){ __b2c__STRFREE((*array)[i+base]); (*array)[i+base] = NULL; } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9238 "bacon.bac"
if( INSTR(OS__b2c__string_var, "BSD") ){
#line 9239 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_strlcat(char *dest, const char *src) { strlcat(dest, src, __b2c__len(dest)+__b2c__len(src)+1); return(dest); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9240 "bacon.bac"
__b2c__assign = (char*)"char *__b2c_strlcpy(char *dest, const char *src) { strlcpy(dest, src, __b2c__len(src)+1); return(dest); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9241 "bacon.bac"
}
#line 9242 "bacon.bac"
__b2c__assign = (char*)"void __b2c_str_free(void) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9243 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "REGEX\\(") ){
__b2c__assign = (char*)"__b2c__regex_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9244 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EXTRACT\\$\\(") ){
__b2c__assign = (char*)"__b2c__extract_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9245 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "REPLACE\\$\\(") ){
__b2c__assign = (char*)"__b2c__replace_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9246 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "WALK\\$\\(") ){
__b2c__assign = (char*)"__b2c__walk_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9247 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ALIGN\\$\\(|AMOUNT\\(|APPEND\\$\\(|CHANGE\\$\\(|COIL\\$\\(|COLLAPSE\\$\\(|CUT\\$\\(|DEL\\$\\(|DELIM\\$\\(|EXCHANGE\\$\\(|EXEC\\$\\(|EXPLODE\\$\\(|FIRST\\$\\(|FOR[[:space:]]|HASDELIM\\(|HEAD\\$\\(|INBETWEEN\\$\\(|ISTOKEN\\(|LAST\\$\\(|MAKEDIR[[:space:]]|MATCH\\(|MERGE\\$\\(|NETWORK[[:space:]]|OUTBETWEEN\\$\\(|PARSE[[:space:]]|PROPER\\$\\(|REV\\$\\(|ROTATE\\$\\(|SERVER[[:space:]]|SORT\\$\\(|SPLIT[[:space:]]|TAIL\\$\\(|TOKEN\\$\\(|UNIQ\\$\\(|WHERE\\(") ){
__b2c__assign = (char*)"__b2c__delim_engine_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9248 "bacon.bac"
if( LEN(g_GLOBALARRAYS__b2c__string_var) ){
__b2c__assign = (char*)"__b2c__arrays_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9249 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COLLECT[[:space:]]|TREE[[:space:]]") ){
__b2c__assign = (char*)"__b2c__twalk_free();"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 9250 "bacon.bac"
__b2c__assign = (char*)"__b2c_str_realloc_free_string(); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9253 "bacon.bac"
__b2c__assign = (char*)"void __b2c__catch_signal(int sig){"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9254 "bacon.bac"
__b2c__assign = (char*)"switch (sig) {case SIGABRT: fprintf(stderr, \"ERROR: signal ABORT received - internal error. Try to compile the program with TRAP LOCAL to find the cause.\\n\"); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9255 "bacon.bac"
__b2c__assign = (char*)"case SIGFPE: fprintf(stderr, \"ERROR: signal for FPE received - division by zero? Examine the calculations in the program.\\n\"); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9256 "bacon.bac"
__b2c__assign = (char*)"case SIGSEGV: fprintf(stderr, \"ERROR: signal for SEGMENTATION FAULT received - memory invalid or array out of bounds? Try to compile the program with TRAP LOCAL to find the cause.\\n\"); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9257 "bacon.bac"
__b2c__assign = (char*)"case SIGILL: fprintf(stderr, \"ERROR: signal for ILLEGAL INSTRUCTION received - executing the program on other hardware? Try to recompile the program from scratch.\\n\"); break;} exit(sig);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9258 "bacon.bac"
__b2c__assign = (char*)"void __b2c__segv(int sig){ longjmp(__b2c__jump, 1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9259 "bacon.bac"
__b2c__assign = (char*)"int __b2c__memory__check (char *x, int size) { volatile char c; unsigned int i, illegal = 1; struct sigaction osa, psa; sigaction(SIGSEGV, NULL, &osa); if (osa.sa_handler != SIG_IGN)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9260 "bacon.bac"
__b2c__assign = (char*)"{ memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_NODEFER|SA_RESTART; psa.sa_handler = __b2c__segv; sigaction(SIGSEGV, &psa, NULL); } if (!setjmp (__b2c__jump))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9261 "bacon.bac"
__b2c__assign = (char*)"{ for (i = 0; i < size; i++) { c = *(char*)(x+i); /* Use c to avoid warning */ if(c) {;} } } else { illegal = 0; } sigaction(SIGSEGV, &osa, NULL); return (illegal); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9262 "bacon.bac"
__b2c__assign = (char*)"int jmp_buf_is_used(jmp_buf data) { jmp_buf p = { 0 }; if(!data) {return(0);} if(memcmp(data, p, sizeof(jmp_buf))) { return(1); } return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9265 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__min_str(char* x, char* y) {if(strcmp(x, y) < 0) { return(x); } return(y);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9266 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__max_str(char* x, char* y) {if(strcmp(x, y) > 0) { return(x); } return(y);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9269 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__str(double nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc (buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) "); if(floor(nr) == nr)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9270 "bacon.bac"
__b2c__assign = (char*)"{ len = snprintf(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", (long)nr); } else { len = snprintf(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", (double)nr); } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9273 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__timer(int init) { struct timeval time; static time_t elapsed_secs = 0; static int elapsed_usecs = 0; if(init) { gettimeofday(&time, NULL); elapsed_usecs = time.tv_usec; elapsed_secs = time.tv_sec; return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9274 "bacon.bac"
__b2c__assign = (char*)"else { gettimeofday(&time, NULL); if(difftime(time.tv_sec, elapsed_secs) < 1) { return((unsigned long) (time.tv_usec-elapsed_usecs)/1000); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9275 "bacon.bac"
__b2c__assign = (char*)"else { return((unsigned long) (difftime(time.tv_sec, elapsed_secs)-1)*1000+((1000000-elapsed_usecs)+time.tv_usec)/1000); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9278 "bacon.bac"
__b2c__assign = (char*)"uint64_t __b2c__nanotimer(int init) { static struct timespec before = { 0 }; struct timespec after; if (init) { clock_gettime(CLOCK_MONOTONIC, &before); return(0); } else { clock_gettime(CLOCK_MONOTONIC, &after); return((int64_t)(after.tv_sec - before.tv_sec) * (int64_t)1000000000UL + (int64_t)(after.tv_nsec - before.tv_nsec)); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9281 "bacon.bac"
__b2c__assign = (char*)"void __b2c__argument(char **arg, int total, char **data) { long x, dlen, slen, pos, tot_len = 0; char quote[] = { 34, 0 }; if (total == 0) { *arg = NULL; } else { dlen = __b2c__len (__b2c__option_delim); for (pos = 0; pos < total; pos++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9282 "bacon.bac"
__b2c__assign = (char*)"{ slen = strlen(data[pos]); *arg = (char*)__b2c_str_realloc(*arg, tot_len + slen * 2 + dlen + 1); if (strstr (data[pos], \" \") || strstr (data[pos], \"\\\"\")) { (*arg)[tot_len++] = 34; for (x = 0; data[pos][x] != 0; x++) { if (data[pos][x] == quote[0])"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9283 "bacon.bac"
__b2c__assign = (char*)"{ (*arg)[tot_len++] = __b2c__option_esc; } (*arg)[tot_len++] = data[pos][x]; } (*arg)[tot_len++] = 34; } else { memmove (*arg + tot_len, data[pos], slen); tot_len += slen; } if (pos < total - 1) { memmove (*arg + tot_len, __b2c__option_delim, dlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9284 "bacon.bac"
__b2c__assign = (char*)"tot_len += dlen; } } __b2c__SETLEN(*arg, tot_len); (*arg)[tot_len] = 0; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9287 "bacon.bac"
__b2c__assign = (char*)"int __b2c_utf8_conv(int txt, char* utf8) { unsigned char b1, b2, b3; int len; if (txt > 0xFFFF) { b1 = txt & 0x0000FF; b2 = (txt & 0x00FF00) >> 8; b3 = (txt & 0xFF0000) >> 16;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9288 "bacon.bac"
__b2c__assign = (char*)"len = snprintf (utf8, 5, \"%c%c%c%c\", 0xF0 | (b3 >> 2), 0x80 | ((b3 & 0x03) << 4) | ((b2 & 0xF0) >> 4), 0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6),"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9289 "bacon.bac"
__b2c__assign = (char*)"0x80 | (b1 & 0x3F)); } else if (txt > 0x07FF) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 4, \"%c%c%c\", 0xE0 | ((b2 & 0xF0) >> 4),"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9290 "bacon.bac"
__b2c__assign = (char*)"0x80 | ((b2 & 0x0F) << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else if (txt > 0x007F) { b1 = txt & 0x00FF; b2 = (txt & 0xFF00) >> 8; len = snprintf (utf8, 3, \"%c%c\","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9291 "bacon.bac"
__b2c__assign = (char*)"0xC0 | (b2 << 2) | ((b1 & 0xC0) >> 6), 0x80 | (b1 & 0x3F)); } else { len = snprintf (utf8, 2, \"%c\", txt & 0x7F); } return(len); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9292 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__ulen (int l, char *k, char *func, char *ptr, int pos) { long len = 0; if (ptr == NULL) { return(0); } if(pos < 0) { while(*ptr){ if((*ptr&0xF0) == 0xF0) { len++; ptr += 4; } else if((*ptr&0xE0) == 0xE0) { len++; ptr += 3; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9293 "bacon.bac"
__b2c__assign = (char*)"else if((*ptr&0xC0) == 0xC0) { len++; ptr += 2; } else if((*ptr&0x80) == 0) { len++; ptr++; } else { ERROR = 38; RUNTIMEFERR(func, ERROR, k, l); return(0); } } } else { len = __b2c__ucs2_clen(l, k, \"ULEN\", ptr, pos); } return(len); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9294 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__blen (int l, char *k, char *func, char *ptr, long c, int flag) { char *org = ptr; if (ptr == NULL){ return (0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9295 "bacon.bac"
__b2c__assign = (char*)"if(flag) { c = __b2c__ulen (l, k, \"BYTELEN\", org, -1)-c; } while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; } else if ((*ptr & 0xE0) == 0xE0) { ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; } else if ((*ptr & 0x80) == 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9296 "bacon.bac"
__b2c__assign = (char*)"{ ptr++; } else { ERROR = 38; fprintf (stderr, \"Cannot decode UTF-8 string: '%s'\\n\", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } c--; } if(flag) { return (__b2c__len(org) - (ptr - org)); } else { return (ptr - org); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9297 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__ucs2_clen (int l, char* k, char *func, char *ptr, int c) { int len = 0; char *org; if (ptr == NULL) return (0); org = ptr; while (*ptr && c > 0) { if ((*ptr & 0xF0) == 0xF0) { ptr += 4; c -= 4; } else if ((*ptr & 0xE0) == 0xE0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9298 "bacon.bac"
__b2c__assign = (char*)"{ ptr += 3; c -= 3; } else if ((*ptr & 0xC0) == 0xC0) { ptr += 2; c -= 2; } else if ((*ptr & 0x80) == 0) { ptr++; c--; } else { ERROR = 38; fprintf(stderr, \"Cannot decode UTF-8 string: '%s'\\n\", org); RUNTIMEFERR (func, ERROR, k, l); return(0); } len++; } return (len); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9301 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "B64DEC\\$\\(|B64ENC\\$\\(") ){
#line 9302 "bacon.bac"
__b2c__assign = (char*)"/* Portions of this code based on Bob Trower's C implementation at http://base64.sourceforge.net - MIT licensed */ static const char cd64[]=\"|$$$}rstuvwxyz{$$$$$$$>?@ABCDEFGHIJKLMNOPQRSTUVW$$$$$$XYZ[\\\\]^_`abcdefghijklmnopq\";"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9303 "bacon.bac"
__b2c__assign = (char*)"static const char cb64[]=\"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/\"; static void __b2c__encodeblock( unsigned char *in, unsigned char *out, int len)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9304 "bacon.bac"
__b2c__assign = (char*)"{ out[0] = (unsigned char) cb64[ (int)(in[0] >> 2) ]; out[1] = (unsigned char) cb64[ (int)(((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4)) ];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9305 "bacon.bac"
__b2c__assign = (char*)"out[2] = (unsigned char) (len > 1 ? cb64[ (int)(((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6)) ] : '='); out[3] = (unsigned char) (len > 2 ? cb64[ (int)(in[2] & 0x3f) ] : '='); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9306 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__b64enc (char* src, int len) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[4]; int i, j, cur = 0, posit = 0; if (src == NULL) { return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9307 "bacon.bac"
__b2c__assign = (char*)"if (len == 0) { len = __b2c__len (src); } if (len == 0) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], ((len + 2) / 3) * 4 + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9308 "bacon.bac"
__b2c__assign = (char*)"while( cur < len ){ for( i = 0; i < 3 && (cur + i < len); i++ ){ in[i] = (unsigned char) src[cur+i]; } in[i] = 0; cur += i; if( i > 0 ) { __b2c__encodeblock( in, out, i );"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9309 "bacon.bac"
__b2c__assign = (char*)"for( j = 0; j < 4; j++ ) { buf[idx][posit+j] = out[j]; } posit += 4; } } buf[idx][posit] = '\\0'; __b2c__SETLEN (buf[idx], posit); return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9310 "bacon.bac"
__b2c__assign = (char*)"static void __b2c__decodeblock(unsigned char in[4], unsigned char out[3]) { out[0] = (unsigned char ) (in[0] << 2 | in[1] >> 4); out[1] = (unsigned char)(in[1] << 4 | in[2] >> 2);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9311 "bacon.bac"
__b2c__assign = (char*)"out[2] = (unsigned char ) (((in[2] << 6) & 0xc0) | in[3]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9312 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__b64dec(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned char in[4], out[3], v; int i = 0, stlen, dec_len, len, cur = 0, posit = 0; if(src == NULL){ return (NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9313 "bacon.bac"
__b2c__assign = (char*)"stlen = __b2c__len (src); if (stlen == 0) { return (NULL); } if(stlen % 4) { ERROR = 5; RUNTIMEFERR (\"B64DEC$\", ERROR, k, l); return(NULL); } dec_len = 3*stlen/4; while(src[stlen+i-1] == 61) { dec_len--; i--; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9314 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], dec_len + 4); while(cur < stlen){ for (len = 0, i = 0; i < 4 && (cur < stlen); i++) { v = 0; while (cur < stlen && v == 0){ v = (unsigned char) src[cur]; cur++; v = (unsigned char) ((v < 43 || v > 122) ? 0 : cd64[ v - 43 ]);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9315 "bacon.bac"
__b2c__assign = (char*)"if (v) {v = (unsigned char) ((v == '$') ? 0 : v - 61);} } if(cur <= stlen){ len++; if (v) { in[i] = (unsigned char)(v - 1); } else { in[i] = 0; } } } if(len){ __b2c__decodeblock(in, out);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9316 "bacon.bac"
__b2c__assign = (char*)"for(i = 0; i < len - 1; i++) { buf[idx][posit + i] = out[i]; } buf[idx][posit + i] = '\\0'; posit += len - 1; } } __b2c__SETLEN(buf[idx], dec_len); return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9317 "bacon.bac"
}
#line 9319 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "BIT\\(|BIN\\$\\(|ROL\\(|ROR\\(") ){
#line 9320 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__bit(long x) { return(x ? 2<<(x-1) : 1); } unsigned long __b2c__rol(int type, long x)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9321 "bacon.bac"
__b2c__assign = (char*)"{ return((x)&lrint(pow(2, type*8-1)) ? (((x)<<1)|1)&lrint(pow(2, type*8)-1) : ((x)<<1)&lrint(pow(2, type*8)-1)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9322 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__ror(int type, long x) { return((x)&1 ? (((x)>>1)&lrint(pow(2, type*8)-1))|lrint(pow(2, type*8-1)) : ((x)>>1)&lrint(pow(2, type*8)-1)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9323 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__bin(int type, long x) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9324 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], type*8+1); for(i = 0; i<type*8; i++) { if(x&1) { buf[idx][type*8-1-i] = 49; } else { buf[idx][type*8-1-i] = 48; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9325 "bacon.bac"
__b2c__assign = (char*)"x = x>>1; } buf[idx][type*8] = '\\0'; __b2c__SETLEN(buf[idx], type*8); return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9326 "bacon.bac"
}
#line 9328 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CHOP\\$\\(") ){
#line 9329 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__chop(char **swap, int type, char *source, char *string, int location) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long length; if (source == NULL || *source == '\\0') { if (type == 1) { *swap = __b2c_Copy_String(*swap, NULL); } return (NULL); } if (string == NULL) { string = (char *) __b2c__chop_default; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9330 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len(string); if (location == 0 || location == 1) { while (*source != '\\0') { if(memchr(string, *source, length)) { source++; } else { break; } } if (*source == '\\0'){ if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); } } tmp = source + __b2c__len(source) - 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9331 "bacon.bac"
__b2c__assign = (char*)"if(location == 0 || location == 2) { while (tmp >= source && *tmp != '\\0') { if(memchr(string, *tmp, length)) { tmp--; } else { break; } } } tmp++; buf[idx] = (char*)__b2c_str_realloc(buf[idx], tmp-source+1); memmove(buf[idx], source, tmp - source);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9332 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], tmp - source); buf[idx][tmp - source] = '\\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9333 "bacon.bac"
}
#line 9335 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CHR\\$\\(|COUNT\\(|ESCAPE\\$\\(|ISASCII\\(|ISUTF8\\(|TOASCII\\$\\(|UCS\\(|UTF8\\$\\(") ){
#line 9336 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__asc2char (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9337 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2); len = snprintf(buf[idx], 2, \"%c\", i); __b2c__SETLEN(buf[idx], len); return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9338 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__asc2utf8 (int i) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; char buffer[5]; len = __b2c_utf8_conv(i, buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9339 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); memcpy(buf[idx], buffer, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9340 "bacon.bac"
__b2c__assign = (char*)"unsigned int __b2c__utf8toasc(char* ptr) { unsigned int result = 0; if((*ptr&0xF0)==0xF0) { result = (*ptr&0x07)<<2; ptr++; result = result | ((*ptr&0x30)>>4); result = result << 8; result = result | ((*ptr&0x0F)<<4);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9341 "bacon.bac"
__b2c__assign = (char*)"ptr++; result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xE0)==0xE0) { result = (*ptr&0x0F)<<4; ptr++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9342 "bacon.bac"
__b2c__assign = (char*)"result = result | ((*ptr&0x3C)>>2); result = result << 8; result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0xC0)==0xC0) { result = (*ptr&0x1C)>>2; result = result << 8;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9343 "bacon.bac"
__b2c__assign = (char*)"result = result | ((*ptr&0x03)<<6); ptr++; result = result | (*ptr&0x3F); } else if((*ptr&0x80) == 0) { result = (*ptr&0x7F); } return (result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9344 "bacon.bac"
__b2c__assign = (char*)"unsigned char __b2c__isascii(const char *ptr) { long x; for(x=0; *(ptr+x); x++) { if(*(ptr+x)&128) return(0); } return(1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9345 "bacon.bac"
__b2c__assign = (char*)"unsigned char __b2c__isutf8(const char *ptr) { int result = 1; if (ptr == NULL) { return (0); } while (*ptr) { if ((*ptr & 0xF0) == 0xF0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9346 "bacon.bac"
__b2c__assign = (char*)"{ if ((*(ptr + 1) & 0xC0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 || (*(ptr + 3) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 4; } else if ((*ptr & 0xE0) == 0xE0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9347 "bacon.bac"
__b2c__assign = (char*)"{ if ((*(ptr + 1) & 0xc0) != 0x80 || (*(ptr + 2) & 0xc0) != 0x80 ) { result = 0; break; } ptr += 3; } else if ((*ptr & 0xC0) == 0xC0) { if ((*(ptr + 1) & 0xc0) != 0x80 )"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9348 "bacon.bac"
__b2c__assign = (char*)"{ result = 0; break; } ptr += 2; } else if ((*ptr & 0x80) == 0) { ptr++; } else { result = 0; break; } } return (result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9349 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__toascii(char *ptr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len, x; len = __b2c__len (ptr); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9350 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], len); for(x = 0; x < len; x++) { *(buf[idx] + x) = *(ptr + x) & 0x7f; } __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\\0'; return((char*)buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9351 "bacon.bac"
}
#line 9353 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CMDLINE\\(") ){
#line 9354 "bacon.bac"
__b2c__assign = (char*)"int __b2c__getopt(int argc, char **argv, char* str){int opt; extern char *optarg; extern int optind, opterr; opterr = 0; opt = getopt(argc, argv, str); if(opt != -1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9355 "bacon.bac"
__b2c__assign = (char*)"{ ARGUMENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) " = __b2c_Copy_String(ARGUMENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) ", optarg); } else { ARGUMENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) " = __b2c_Copy_String(ARGUMENT"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_STRINGSIGN__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) ", argv[optind]); } return(opt); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9356 "bacon.bac"
}
#line 9358 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "APPEND[[:space:]]|&|\\+|CONCAT\\$\\(|LOOP\\$\\(") ){
#line 9359 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__concat(int n, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } idx++;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9360 "bacon.bac"
__b2c__assign = (char*)"if (idx == __b2c_STRING_FUNC) { idx = 0; } va_start (ap, n); if(buf[idx]) { buflen = __b2c__RBUFSIZE(buf[idx]); } while (n) { next = va_arg (ap, char *); if (next) { cnew = __b2c__len (next);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9361 "bacon.bac"
__b2c__assign = (char*)"if(length+cnew >= buflen) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + cnew); buflen = __b2c__RBUFSIZE(buf[idx]); } memcpy(buf[idx] + length, next, cnew); length += cnew; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9362 "bacon.bac"
__b2c__assign = (char*)"n--; } va_end (ap); if (buf[idx]) { __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\\0'; } return ((char *) buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9363 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__concat2(int total, ...) { char *iter, *result, *first, *next, *offset; int n_copy = 0, pos = 0, length = 0, cnew, flen = 0, stage = 0; uint32_t lbufsize = 0, rbufsize = 0; va_list ap_copy, ap; va_start (ap, total);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9364 "bacon.bac"
__b2c__assign = (char*)"first = result = offset = va_arg (ap, char *); total--; if (total == 0) { return (NULL); } va_copy (ap_copy, ap); if(first) { n_copy = total; } while (n_copy) { iter = va_arg (ap_copy, char *); if (iter == first) { flen = __b2c__len (first); break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9365 "bacon.bac"
__b2c__assign = (char*)"pos += __b2c__len (iter); n_copy--; } va_end (ap_copy); if (__b2c_str_realloc_get_string(result) ) { lbufsize = __b2c__LBUFSIZE (result); rbufsize = __b2c__RBUFSIZE (result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9366 "bacon.bac"
__b2c__assign = (char*)"else { rbufsize = __b2c__len(first); } if (n_copy) { if (pos >= lbufsize) { result = (char *) __b2c_str_realloc_left(result, lbufsize + rbufsize + pos); offset = result; } __b2c_str_realloc_del_string(result);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9367 "bacon.bac"
__b2c__assign = (char*)"memmove (result - __b2c__BUFOFFSET - pos, result - __b2c__BUFOFFSET, __b2c__BUFOFFSET); result -= pos; __b2c_str_realloc_add_string(result); __b2c__LBUFSIZE (result) -= pos; __b2c__RBUFSIZE (result) += pos;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9368 "bacon.bac"
__b2c__assign = (char*)"rbufsize = __b2c__RBUFSIZE (result); } next = va_arg (ap, char *); total--; while (total >= 0) { if (next) { if (next == first) { cnew = flen; } else { cnew = __b2c__len (next); } if (cnew + flen + length >= rbufsize)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9369 "bacon.bac"
__b2c__assign = (char*)"{ result = (char *) __b2c_str_realloc (result, cnew + flen + length); rbufsize = __b2c__RBUFSIZE (result); offset = result + pos; } if (next != first) { memmove (result + length, next, cnew); } else { if (stage == 0) { stage = 1; } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9370 "bacon.bac"
__b2c__assign = (char*)"{ memmove (result + length, offset, cnew); } } length += cnew; } next = va_arg (ap, char *); total--; } va_end (ap); if(result) { __b2c__SETLEN (result, length); result[length] = '\\0'; } return ((char *) result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9371 "bacon.bac"
}
#line 9373 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COUNT\\(") ){
#line 9374 "bacon.bac"
__b2c__assign = (char*)"long __b2c__count (int l, char *k, char *x, unsigned int y) { long i, z = 0; if(x == NULL) { return(0); } if (__b2c__option_utf8) { while (*x) { if (__b2c__utf8toasc (x) == y) { z++; } if ((*x & 0xF0) == 0xF0) { x += 4; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9375 "bacon.bac"
__b2c__assign = (char*)"else if ((*x & 0xE0) == 0xE0) { x += 3; } else if ((*x & 0xC0) == 0xC0) { x += 2; } else if ((*x & 0x80) == 0) { x++; } else { ERROR = 38; RUNTIMEFERR (\"COUNT\", ERROR, k, l); return(0); } } } else "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9376 "bacon.bac"
__b2c__assign = (char*)"{ for (i = 0; x[i] != '\\0'; i++) { if (x[i] == y) { z++; } } } return z; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9377 "bacon.bac"
}
#line 9379 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CURDIR\\$") ){
#line 9380 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__curdir (void) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9381 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = getcwd(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx]["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "-1] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9382 "bacon.bac"
}
#line 9384 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "MONTH\\$\\(|WEEKDAY\\$\\(") ){
#line 9385 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__datename(time_t now, int which) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; struct tm *ts; int len = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9386 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) "); ts = localtime (&now); switch (which) { case 1: len = strftime(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%A\", ts); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9387 "bacon.bac"
__b2c__assign = (char*)"case 2: len = strftime(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%B\", ts); break; } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9388 "bacon.bac"
}
#line 9390 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "DEC\\(") ){
#line 9391 "bacon.bac"
__b2c__assign = (char*)"uint64_t __b2c__hex2dec (int l, char *k, char *h, int flag) { uint64_t j=0; char *status = NULL; if(h == NULL) { return(0); } if(flag == 1) { flag = 2; } else if(flag > 36) {ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9392 "bacon.bac"
__b2c__assign = (char*)"if(flag == 0) { j = strtol(h, &status, 16); if(*status != '\\0') { ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); } } else { j = strtol(h, &status, flag);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9393 "bacon.bac"
__b2c__assign = (char*)"if(*status != '\\0') { ERROR = 5; RUNTIMEFERR (\"DEC\", ERROR, k, l); return(0); } } return(uint64_t)(j); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9394 "bacon.bac"
}
#line 9396 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "BASENAME\\$\\(|DIRNAME\\$\\(|REALPATH\\$\\(") ){
#line 9397 "bacon.bac"
__b2c__assign = (char*)"#ifndef PATH_MAX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9398 "bacon.bac"
__b2c__assign = (char*)"#define PATH_MAX 4096"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9399 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9400 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__dirname(int l, char *k, int x, char *y, long arg) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i; char *dup; if(y == NULL || __b2c__len(y) == 0){ return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9401 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], PATH_MAX*sizeof(char)); dup = __b2c__strdup(y); switch(x) {case 0: if ((realpath(y, buf[idx])) == NULL) { ERROR = 26; RUNTIMEFERR(\"REALPATH$\", ERROR, k, l); strncpy(buf[idx], \"Error getting real path\","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9402 "bacon.bac"
__b2c__assign = (char*)"return(NULL); } break; case 1: if(strncpy(buf[idx], basename(dup), PATH_MAX) == NULL) { ERROR = 26; RUNTIMEFERR(\"BASENAME$\", ERROR, k, l); strncpy (buf[idx], \"Error getting basename\","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9403 "bacon.bac"
__b2c__assign = (char*)"break; case 2: if(strncpy(buf[idx], dirname(dup), PATH_MAX) == NULL) { ERROR = 26; RUNTIMEFERR(\"DIRNAME$\", ERROR, k, l); strncpy(buf[idx], \"Error getting dirname\","; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9404 "bacon.bac"
__b2c__assign = (char*)"break; } __b2c__STRFREE(dup); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx][PATH_MAX - 1] = '\\0'; if(arg && x==1){ for(i=__b2c__len(buf[idx]); i>=0; i--) { if(buf[idx][i] == 46) break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9405 "bacon.bac"
__b2c__assign = (char*)"if(i >= 0){ if(arg == 1) {buf[idx][i] = '\\0'; __b2c__SETLEN(buf[idx], i);} if(arg == 2){ i++; memmove(buf[idx], buf[idx]+i, __b2c__len(buf[idx])-i+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9406 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], __b2c__len(buf[idx])-i);} } else if(arg == 2) {buf[idx][0] = '\\0'; __b2c__SETLEN(buf[idx], 0);} } return(char*)(buf[idx]);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9407 "bacon.bac"
}
#line 9409 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TIMEVALUE\\(") ){
#line 9410 "bacon.bac"
__b2c__assign = (char*)"unsigned long __b2c__epoch(int year, int month, int day, int hour, int minute, int second){struct tm tm; time_t t; tm.tm_year = year - 1900; tm.tm_mon = month - 1; tm.tm_mday = day;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9411 "bacon.bac"
__b2c__assign = (char*)"tm.tm_hour = hour; tm.tm_min = minute; tm.tm_sec = second; tm.tm_isdst = -1; t = mktime(&tm); if (t == -1) return (0); return(long) t; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9412 "bacon.bac"
}
#line 9414 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EXEC\\$\\(|RUN\\$\\(") ){
#line 9415 "bacon.bac"
__b2c__assign = (char*)"static char **__b2c__Get_Args(char *line) { char **ptr = NULL; long start, x, collapse; long length = 0, amount = 0; collapse = __b2c__collapse; __b2c__collapse = 1; start = __b2c__delim_engine (2, &amount, line, \" \", 0); ptr = (char**)calloc(amount, sizeof(char*));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9416 "bacon.bac"
__b2c__assign = (char*)"for(x = 0; x < amount; x++) { start = __b2c__delim_engine_cache (1, &length, line, \" \", x + 1); ptr[x] = __b2c__strndup(line+start, length); } ptr[x] = NULL; __b2c__collapse = collapse; return (ptr); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9417 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__exec(int t, int l, char *k, char *cmd, char *str, int out) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int forking, length, dnull; ssize_t result = 0; int wpipe[2], rpipe[2]; char **args; char *ans = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9418 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); if (pipe (rpipe) < 0 || pipe (wpipe) < 0) { ERROR = 29; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); } if ((forking = fork ()) < 0) { ERROR = 29; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9419 "bacon.bac"
__b2c__assign = (char*)"else if (forking == 0) { fflush(stdout); close (wpipe[1]); close (rpipe[0]); dup2 (wpipe[0], STDIN_FILENO); close (wpipe[0]); dnull = open(\"/dev/null\", O_RDWR); if(out == 1) { dup2 (rpipe[1], STDOUT_FILENO); dup2(dnull, STDERR_FILENO); } else if (out == 2) { dup2(dnull, STDOUT_FILENO);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9420 "bacon.bac"
__b2c__assign = (char*)"dup2(rpipe[1], STDERR_FILENO); } else { dup2(rpipe[1], STDOUT_FILENO); dup2(rpipe[1], STDERR_FILENO); } close (rpipe[1]); if(t == 0) { forking = system (cmd); if (WIFEXITED (forking)) result = WEXITSTATUS (forking); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9421 "bacon.bac"
__b2c__assign = (char*)"else { args = __b2c__Get_Args(cmd); if(execvp(args[0], args) < 0 ) { ERROR = 29; RUNTIMEFERR (\"EXEC$\", ERROR, k, l); return(NULL); } } close(dnull); __b2c_str_free(); _exit(result); } else { close (wpipe[0]); close (rpipe[1]); ans = (char*)malloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9422 "bacon.bac"
__b2c__assign = (char*)"length = 0; if (str != NULL) result = write (wpipe[1], str, __b2c__len(str)); close (wpipe[1]); do { result = read (rpipe[0], ans, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); if (result == -1) { ERROR = 30; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9423 "bacon.bac"
__b2c__assign = (char*)"if (result == 0) { break; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + result + 1); if(buf[idx] == NULL) { ERROR = 6; RUNTIMEFERR(\"EXEC$\", ERROR, k, l); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9424 "bacon.bac"
__b2c__assign = (char*)"memcpy(buf[idx] + length, ans, (size_t)labs(result)); length += result; } while (result > 0); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0';"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9425 "bacon.bac"
__b2c__assign = (char*)"close (rpipe[0]); free (ans); wait (&RETVAL); RETVAL = WEXITSTATUS (RETVAL); } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9426 "bacon.bac"
}
#line 9428 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FILEEXISTS\\(|FILELEN\\(") ){
#line 9429 "bacon.bac"
__b2c__assign = (char*)"long __b2c__filestat(int l, char *k, const char *x, int check) { struct stat buf = { 0 }; int result; if(x == NULL) { if(check == 0) { return(-1); } return(0); } result = stat(x, &buf); if(result < 0 && check == 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9430 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 24; RUNTIMEFERR(\"FILELEN\", ERROR, k, l); return(-1); } if(check == 0) { return((long)buf.st_size); } if(buf.st_mode) { return(1); } return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9431 "bacon.bac"
}
#line 9433 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FILETIME\\(") ){
#line 9434 "bacon.bac"
__b2c__assign = (char*)"long __b2c__filetime(int l, char *k, const char *x, int y) { struct stat buf = { 0 }; int result; if (x == NULL || y < 0 || y > 2) { return(-1); } result = stat(x, &buf); if(result < 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9435 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 24; RUNTIMEFERR(\"FILETIME\", ERROR, k, l); return(-1); } if(y == 0) { return((long)buf.st_atime); } if(y == 1) { return((long)buf.st_mtime); } return((long)buf.st_ctime); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9436 "bacon.bac"
}
#line 9438 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FILETYPE\\(") ){
#line 9439 "bacon.bac"
__b2c__assign = (char*)"int __b2c__filetype(int l, char *k, const char *file) { int type = 0; struct stat buf = { 0 }; if(file == NULL) { return(0); } if(lstat(file, &buf) < 0) { ERROR = 24; RUNTIMEFERR (\"FILETYPE\", ERROR, k, l); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9440 "bacon.bac"
__b2c__assign = (char*)"switch (buf.st_mode & S_IFMT) { case S_IFBLK: type = 4; break; case S_IFCHR: type = 3; break; case S_IFDIR: type = 2; break; case S_IFIFO: type = 5; break; case S_IFLNK: type = 6; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9441 "bacon.bac"
__b2c__assign = (char*)"case S_IFREG: type = 1; break; case S_IFSOCK: type = 7; break; default: ERROR = 24; RUNTIMEFERR(\"FILETYPE\", ERROR, k, l); return(0); break; } return(type); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9442 "bacon.bac"
}
#line 9444 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FILL\\$\\(") ){
#line 9445 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__fill(long amount, int txt) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char bf[5]; int x, len; if(amount < 0 || txt > 0x10FFFF) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (__b2c__option_utf8)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9446 "bacon.bac"
__b2c__assign = (char*)"{ len = __b2c_utf8_conv (txt, bf); buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount*len+1); for (x = 0; x < (amount * len); x += len) { memcpy(buf[idx] + x, bf, len); } __b2c__SETLEN(buf[idx], amount * len); buf[idx][amount * len] = '\\0'; } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9447 "bacon.bac"
__b2c__assign = (char*)"{ buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1); memset(buf[idx], txt, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\\0'; } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9448 "bacon.bac"
}
#line 9450 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FLATTEN\\$\\(|UNFLATTEN\\$\\(") ){
#line 9451 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__flatten(char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long len, x, pos=0, escaped=0; quote[0] = __b2c__option_dq; if(src == NULL) { return(src); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9452 "bacon.bac"
__b2c__assign = (char*)"if (meta == NULL) { meta = quote; } len = __b2c__len(src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9453 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx], src, len); buf[idx][len] = '\\0'; for(x = 0; src[x] != 0; x++) { if(src[x] == meta[0]) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9454 "bacon.bac"
__b2c__assign = (char*)"else { pos++; escaped = 0; } } else { if(src[x] == __b2c__option_esc) { if(!escaped) { memmove(buf[idx]+pos, src+x+1, len-x-1); escaped = 1; } else { pos++; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9455 "bacon.bac"
__b2c__assign = (char*)"else { pos++; escaped = 0; } } } __b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9456 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__unflatten (char *src, char *meta) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char quote[1]; long x, pos = 1; quote[0] = __b2c__option_dq; if (src == NULL) { return (src); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9457 "bacon.bac"
__b2c__assign = (char*)"if (meta == NULL) { meta = quote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], 2*__b2c__len(src)+1); buf[idx][0] = meta[0];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9458 "bacon.bac"
__b2c__assign = (char*)"for (x = 0; src[x] != 0; x++) { if (src[x] == meta[0]) { buf[idx][pos++] = __b2c__option_esc; buf[idx][pos++] = src[x]; } else {buf[idx][pos++] = src[x];} } buf[idx][pos++] = meta[0];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9459 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], pos); buf[idx][pos] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9460 "bacon.bac"
}
#line 9462 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "GETENVIRON\\$\\(") ){
#line 9463 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__getenv (char *env) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *result; long len; if(env == NULL) { return(NULL); } result = getenv (env); if(result == NULL) { return(NULL); } len = strlen(result); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9464 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], (len+1)*sizeof(char)); strncpy(buf[idx], result, len); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9465 "bacon.bac"
}
#line 9467 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "GETKEY|TRACE[[:space:]]") ){
#line 9468 "bacon.bac"
__b2c__assign = (char*)"long __b2c__getch(void){long ch; struct termios oldt, newt; tcflush(STDIN_FILENO, TCIFLUSH); tcgetattr(STDIN_FILENO, &oldt); newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9469 "bacon.bac"
__b2c__assign = (char*)"newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt); ch = getchar(); tcsetattr(STDIN_FILENO, TCSANOW, &oldt); return(ch);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9470 "bacon.bac"
}
#line 9472 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "GETPEER\\$\\(") ){
#line 9473 "bacon.bac"
if( INSTR(OS__b2c__string_var, "OSF1") ){
#line 9474 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) "int");
#line 9475 "bacon.bac"
} else {
#line 9476 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) "unsigned int");
#line 9477 "bacon.bac"
}
#line 9478 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__getpeer(int l, char *k, uintptr_t remote) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; struct sockaddr_in *peer; "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) line__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) " length = sizeof (peer); char port[6]; int desc = 0; peer = (struct sockaddr_in*)calloc (1, sizeof(*peer));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9479 "bacon.bac"
if( g_OPTION_TLS ){
#line 9480 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "gnutls") ){
#line 9481 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__option_tls) { BIO_get_fd(((SSL*)remote)->gnutls_state, &desc); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9482 "bacon.bac"
} else {
#line 9483 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__option_tls) { desc = SSL_get_fd((SSL*)remote); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9484 "bacon.bac"
}
#line 9485 "bacon.bac"
}
#line 9486 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__option_tls) { desc = remote; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "*sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9487 "bacon.bac"
__b2c__assign = (char*)"if (getpeername(desc, (struct sockaddr *) peer, &length) < 0) { free(peer); ERROR = 16; RUNTIMEFERR(\"GETPEER$\", ERROR, k, l); strncpy(buf[idx], \"Peer not found\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9488 "bacon.bac"
__b2c__assign = (char*)"else { strncpy(buf[idx], inet_ntoa (peer->sin_addr), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "-7); strcat(buf[idx], \":\"); snprintf (port, 6, \"%d\", ntohs (peer->sin_port)); strcat(buf[idx], port); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9489 "bacon.bac"
__b2c__assign = (char*)"free (peer); __b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx]["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "-1] = '\\0'; return(char*)(buf[idx]);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9490 "bacon.bac"
}
#line 9492 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "GETX|GETY") ){
#line 9493 "bacon.bac"
__b2c__assign = (char*)"long __b2c__getxy(int type){char asw["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "]; struct termios old, cnew; int len, x = 0, y = 0; tcgetattr(STDIN_FILENO, &old); cnew = old; cnew.c_lflag &= ~(ICANON | ECHO); tcsetattr(STDIN_FILENO, TCSANOW, &cnew);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9494 "bacon.bac"
__b2c__assign = (char*)"if(write(STDOUT_FILENO, \"\\033[6n\", 4)>=0){len = read(STDIN_FILENO, asw, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); asw[len] = '\\0'; tcsetattr(STDIN_FILENO, TCSANOW, &old); sscanf(asw, \"\\033[%d;%dR\", &y, &x);} if (!type) return(long)x; return(long)y;}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9495 "bacon.bac"
}
#line 9497 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ASSOC[[:space:]]|HASH\\(|INDEX\\(|LOOKUP[[:space:]]|OBTAIN\\$\\(|SORT[[:space:]]|TREE[[:space:]]|UNIQ\\$\\(") ){
#line 9498 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrd(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(-1); else return(1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9499 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrd_wrap(const void *a, const void *b) { return(__b2c__sortnrd(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9500 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrd_down(const void *a, const void *b) {if (*(double*)a==*(double*)b) return(0); else if (*(double*)a < *(double*)b) return(1); else return(-1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9501 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrd_wrap_down(const void *a, const void *b) { return(__b2c__sortnrd_down(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9502 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrf(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(-1); else return(1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9503 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrf_wrap(const void *a, const void *b) { return(__b2c__sortnrf(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9504 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrf_down(const void *a, const void *b) {if (*(float*)a==*(float*)b) return(0); else if (*(float*)a < *(float*)b) return(1); else return(-1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9505 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrf_wrap_down(const void *a, const void *b) { return(__b2c__sortnrf_down(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9506 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrl(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(-1); else return(1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9507 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrl_wrap(const void *a, const void *b) { return(__b2c__sortnrl(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9508 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrl_down(const void *a, const void *b) {if (*(long*)a==*(long*)b) return(0); else if (*(long*)a < *(long*)b) return(1); else return(-1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9509 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrl_wrap_down(const void *a, const void *b) { return(__b2c__sortnrl_down(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9510 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnri(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(-1); else return(1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9511 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnri_wrap(const void *a, const void *b) { return(__b2c__sortnri(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9512 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnri_down(const void *a, const void *b) {if (*(int*)a==*(int*)b) return(0); else if (*(int*)a < *(int*)b) return(1); else return(-1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9513 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnri_wrap_down(const void *a, const void *b) { return(__b2c__sortnri_down(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9514 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrs(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(-1); else return(1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9515 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrs_wrap(const void *a, const void *b) { return(__b2c__sortnrs(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9516 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrs_down(const void *a, const void *b) {if (*(short*)a==*(short*)b) return(0); else if (*(short*)a < *(short*)b) return(1); else return(-1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9517 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrs_wrap_down(const void *a, const void *b) { return(__b2c__sortnrs_down(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9518 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrc(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(-1); else return(1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9519 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrc_wrap(const void *a, const void *b) { return(__b2c__sortnrc(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9520 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrc_down(const void *a, const void *b) {if (*(char*)a==*(char*)b) return(0); else if (*(char*)a < *(char*)b) return(1); else return(-1);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9521 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortnrc_wrap_down(const void *a, const void *b) { return(__b2c__sortnrc_down(*(void**)a, *(void**)b)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9522 "bacon.bac"
}
#line 9524 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ASSOC[[:space:]]|HASH\\(|INDEX\\(|LOOKUP[[:space:]]|OBTAIN\\$\\(|SORT[[:space:]]|SORT\\$\\(|TREE[[:space:]]|UNIQ\\$\\(") ){
#line 9525 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortstr(const void *a, const void *b)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9526 "bacon.bac"
__b2c__assign = (char*)"{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)a, *(char **)b);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9527 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortstr2(const void *a, const void *b)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9528 "bacon.bac"
__b2c__assign = (char*)"{if(a == NULL) return(-1); if(b == NULL) return(1); return strcmp((char*)a, (char*)b);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9529 "bacon.bac"
__b2c__assign = (char*)"int __b2c__sortstr_down(const void *a, const void *b)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9530 "bacon.bac"
__b2c__assign = (char*)"{if(*(char **)a == NULL) return(-1); if(*(char **)b == NULL) return(1); return strcmp(*(char **)b, *(char **)a);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9531 "bacon.bac"
}
#line 9533 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ASSOC[[:space:]]|EXTRACT\\$\\(|HASH\\(|INDEX\\$\\(|INVERT\\(|LOOKUP[[:space:]]|OBTAIN\\$\\(|REGEX\\(|REPLACE\\$\\(|SORT[[:space:]]|UNIQ\\$\\(|WALK\\$\\(") ){
#line 9534 "bacon.bac"
__b2c__assign = (char*)"typedef struct __b2c__htable { char *key[65536]; void *value[65536]; char *index[65536]; int total; struct __b2c__htable *next; } __b2c__htable;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9535 "bacon.bac"
__b2c__assign = (char*)"const char *__b2c__hash_key_collect(int n, const char *first, ...) { static char *keys[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long length = 0, buflen = 0, cnew; char *next; va_list ap; if (n == 0) { return (NULL); } if (n == 1) { return (first); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9536 "bacon.bac"
__b2c__assign = (char*)"idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (keys[idx]) { buflen = __b2c__RBUFSIZE(keys[idx]); } cnew = __b2c__len(first); if(cnew >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], cnew); buflen = __b2c__RBUFSIZE(keys[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9537 "bacon.bac"
__b2c__assign = (char*)"memcpy(keys[idx], first, cnew); length += cnew; n--; va_start (ap, first); while (n) { next = va_arg (ap, char *); if (next) { cnew = __b2c__len (next); if(length + cnew + 1 >= buflen) { keys[idx] = (char *) __b2c_str_realloc(keys[idx], (length + cnew + 1 + 1) * sizeof (char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9538 "bacon.bac"
__b2c__assign = (char*)"buflen = __b2c__RBUFSIZE(keys[idx]); } keys[idx][length] = 32; length++; memmove (keys[idx] + length, next, cnew); length += cnew; } n--; } va_end (ap); __b2c__SETLEN(keys[idx], length); keys[idx][length] = '\\0'; return ((char *) keys[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9539 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__KEYCOLLECT(...) __b2c__hash_key_collect(sizeof((const char*[]){__VA_ARGS__}) / sizeof(char*), __VA_ARGS__, NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9540 "bacon.bac"
__b2c__assign = (char*)"uint64_t __b2c__HashFNV1a_64(const char *key, int len){ uint64_t hash = 14695981039346656037UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 1099511628211 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 1099511628211 * (hash ^ *key); key++; } } return(hash); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9541 "bacon.bac"
__b2c__assign = (char*)"uint32_t __b2c__HashFNV1a_32(const char *key, int len){ uint32_t hash = 2166136261UL; if(key==NULL) { return(0); } if(len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else { while(*key) { hash = 16777619 * (hash ^ *key); key++; } } return(hash); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9542 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__HashFNV1a_16(x) __b2c__HashFNV1a_16_new(x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9543 "bacon.bac"
__b2c__assign = (char*)"uint16_t __b2c__HashFNV1a_16_new(const char *key, int len) { uint32_t hash = 2166136261UL; if (key == NULL) { return (0); } if (len) { while(len) { hash = 16777619 * (hash ^ *key); key++; len--; } } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9544 "bacon.bac"
__b2c__assign = (char*)"{ while (*key) { hash = 16777619 * (hash ^ *key); key++; } } return ((hash >> 16) ^ (hash & 0xffff)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9545 "bacon.bac"
__b2c__assign = (char*)"__b2c__htable *__b2c__hash_new(void) { __b2c__htable *name; name = (__b2c__htable*)calloc(1, sizeof(__b2c__htable)); name->next = NULL; name->total = 0; return(name); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9546 "bacon.bac"
__b2c__assign = (char*)"__b2c__htable* __b2c__hash_find_key_do(__b2c__htable *name, unsigned short hash, const char *key) { if(key == NULL || name == NULL) { return(NULL); } if(hash == 0) { hash = __b2c__HashFNV1a_16(key); } do"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9547 "bacon.bac"
__b2c__assign = (char*)"{ if(name->key[hash] && !strcmp(name->key[hash], key)) { return(name); } name = name->next; } while(name); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9548 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_find_key(x, y, ...) __b2c__hash_find_key_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9549 "bacon.bac"
__b2c__assign = (char*)"void *__b2c__hash_find_value_do(__b2c__htable *name, const char *key) { __b2c__htable *table; unsigned short pos; if(name == NULL || key == NULL) { return(NULL); } pos = __b2c__HashFNV1a_16(key); table = __b2c__hash_find_key(name, pos, key);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9550 "bacon.bac"
__b2c__assign = (char*)"if(table) { return(table->value[pos]); } return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9551 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_find_value(x, ...) __b2c__hash_find_value_do(x, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9552 "bacon.bac"
__b2c__assign = (char*)"void __b2c__hash_add_do(__b2c__htable *name, const void *value, int flag, unsigned int len, const char *key) { unsigned short hash; if(name == NULL) { return; } hash = __b2c__HashFNV1a_16(key);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9553 "bacon.bac"
__b2c__assign = (char*)"while(1) { if(name->key[hash] == NULL) { name->total++; break; } if(!strcmp(name->key[hash], key)) { if(flag != 2) { break; } } if(name->next) { name = name->next; } else { name->next = __b2c__hash_new(); name = name->next;} }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9554 "bacon.bac"
__b2c__assign = (char*)"if(!name->key[hash]) { name->key[hash] = __b2c_Copy_String(name->key[hash], (char*)key); name->index[name->total-1] = name->key[hash]; } if(flag == 0) { if(!name->value[hash]) { name->value[hash] = calloc(1, sizeof(void*)); } memcpy(name->value[hash], value, sizeof(void*)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9555 "bacon.bac"
__b2c__assign = (char*)"else if(flag == 3) { name->value[hash] = realloc(name->value[hash], len); memcpy(name->value[hash], value, len); } else { name->value[hash] = __b2c_Copy_String((char*)name->value[hash], (char*)value); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9556 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_add(x, y, ...) __b2c__hash_add_do(x, y, 0, 0, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9557 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_add_str(x, y, ...) __b2c__hash_add_do(x, y, 1, 0, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9558 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_add_redundant(x, y, ...) __b2c__hash_add_do(x, y, 2, 0, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9559 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_add_data(x, y, len, ...) __b2c__hash_add_do(x, y, 3, len, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9560 "bacon.bac"
__b2c__assign = (char*)"void *__b2c__hash_realloc_str_value_do(__b2c__htable *name, int len, const char *key) { __b2c__htable *table; unsigned short pos; if (name == NULL || key == NULL) { return (NULL); } __b2c__hash_add_str(name, \"\", key); pos = __b2c__HashFNV1a_16(key);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9561 "bacon.bac"
__b2c__assign = (char*)"table = __b2c__hash_find_key(name, pos, key); table->value[pos] = realloc(table->value[pos], len); return (table->value[pos]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9562 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_realloc_str_value(x, y, ...) __b2c__hash_realloc_str_value_do(x, y, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9563 "bacon.bac"
__b2c__assign = (char*)"void __b2c__hash_del_do(__b2c__htable *name, int rebuild, const char *key) { __b2c__htable *found; unsigned short pos; int i, which; if(name == NULL) { return; } pos = __b2c__HashFNV1a_16(key); found = __b2c__hash_find_key(name, pos, key);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9564 "bacon.bac"
__b2c__assign = (char*)"if(found) { if (rebuild) { for (i = 0; i < found->total; i++) { which = __b2c__HashFNV1a_16(found->index[i]); if (which == pos) { if(i != found->total-1) { found->index[i] = found->index[found->total-1]; } found->index[found->total-1] = NULL; break; } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9565 "bacon.bac"
__b2c__assign = (char*)"__b2c__STRFREE(found->key[pos]); found->key[pos] = NULL; if(found->value[pos]) { __b2c__STRFREE(found->value[pos]); } found->value[pos] = NULL; found->total -= 1; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9566 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_del(x, ...) __b2c__hash_del_do(x, 1, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9567 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_del_norebuild(x, ...) __b2c__hash_del_do(x, 0, __b2c__KEYCOLLECT(__VA_ARGS__))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9568 "bacon.bac"
__b2c__assign = (char*)"void __b2c__hash_clear_do(__b2c__htable *name, int regex) { __b2c__htable *orig, *next; int i; orig = name; while(name) { for(i = 0; i < 65536; i++) { if(name->key[i]) { __b2c__STRFREE(name->key[i]); } name->key[i] = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9569 "bacon.bac"
__b2c__assign = (char*)"if(name->value[i]) { if(regex) { regfree(&(*(regex_t*)name->value[i])); } __b2c__STRFREE(name->value[i]); } name->value[i] = NULL; } next = name->next; name->next = NULL; name->total = 0; if(name != orig) { free(name); } name = next; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9570 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_clear(x) __b2c__hash_clear_do(x, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9571 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_clear_regfree(x) __b2c__hash_clear_do(x, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9572 "bacon.bac"
__b2c__assign = (char*)"int __b2c__hash_nrkeys(__b2c__htable *name) { int total = 0; while(name) { total += name->total; name = name->next; } return(total); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9573 "bacon.bac"
__b2c__assign = (char*)"void __b2c__hash_dup_do(__b2c__htable *from, __b2c__htable *to, int flag) { int i; char *value; while(from) { for(i = 0; i < 65536; i++) { if(from->key[i]) { value = (char*)__b2c__hash_find_value(from, from->key[i]); if(flag==0) { __b2c__hash_add(to, value, from->key[i]); } "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9574 "bacon.bac"
__b2c__assign = (char*)"else { __b2c__hash_add_str(to, value, from->key[i]); } } } from = from->next; if(to->next == NULL) { to->next = __b2c__hash_new(); } to = to->next; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9575 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_dup(x, y) __b2c__hash_dup_do(x, y, 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9576 "bacon.bac"
__b2c__assign = (char*)"#define __b2c__hash_dup_str(x, y) __b2c__hash_dup_do(x, y, 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9577 "bacon.bac"
}
#line 9579 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "OBTAIN\\$\\(|UNIQ\\$\\(") ){
#line 9580 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__hash_obtain(__b2c__htable *name, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long ctr, dlen, len, total = 0; if(name == NULL) { return (NULL); } if(delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9581 "bacon.bac"
__b2c__assign = (char*)"if(name->total == 0) { return (NULL); } dlen = __b2c__len(delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen); do { for(ctr=0; ctr < name->total; ctr++) { len = __b2c__len(name->index[ctr]);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9582 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], total+len+dlen); memmove(buf[idx] + total, name->index[ctr], len); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } name = name->next; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9583 "bacon.bac"
__b2c__assign = (char*)"while(name); __b2c__SETLEN(buf[idx], total-dlen); buf[idx][total-dlen] = '\\0'; return((char*)buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9584 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__hash_obtain_by_sort(int l, char *k, __b2c__htable * name, char *delim, int up_down, int type) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; void **values = { NULL }; char **keys = { NULL }; void **dups = { NULL }; __b2c__htable *ptr, *inv; int i, j, pos = 0, start = 0, cur = 0; long dlen, len, total = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9585 "bacon.bac"
__b2c__assign = (char*)"unsigned short loc; char *value; char bf["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) " + 1] = { 0 }; if (name == NULL || name->total == 0) { return (NULL); } if (delim == NULL) { delim = __b2c__option_delim; } values = (void **) calloc (__b2c__hash_nrkeys (name), sizeof (char *)); inv = __b2c__hash_new (); ptr = name; do { for(i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16(ptr->index[i]); switch(type)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9586 "bacon.bac"
__b2c__assign = (char*)"{ case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(double *) ptr->value[loc]); value = bf; break; case 2: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(float *) ptr->value[loc]); value = bf; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9587 "bacon.bac"
__b2c__assign = (char*)"case 3: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", *(long *) ptr->value[loc]); value = bf; break; case 4: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(int *) ptr->value[loc]); value = bf; break; case 5: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(short *) ptr->value[loc]); value = bf; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9588 "bacon.bac"
__b2c__assign = (char*)"case 6: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(char *) ptr->value[loc]); value = bf; break; default: ERROR = 43; RUNTIMEFERR(\"OBTAIN$\", ERROR, k, l); return(NULL); } __b2c__hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9589 "bacon.bac"
__b2c__assign = (char*)"switch (type) { case 0: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortstr); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortstr_down); } break; case 1: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrd_wrap); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9590 "bacon.bac"
__b2c__assign = (char*)"else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrd_wrap_down); } break; case 2: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrf_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrf_wrap_down); } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9591 "bacon.bac"
__b2c__assign = (char*)"case 3: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrl_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrl_wrap_down); } break; case 4: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnri_wrap); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9592 "bacon.bac"
__b2c__assign = (char*)"else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnri_wrap_down); } break; case 5: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrs_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrs_wrap_down); } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9593 "bacon.bac"
__b2c__assign = (char*)"case 6: if (up_down) { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrc_wrap); } else { qsort (&values[0], pos, sizeof (void *), __b2c__sortnrc_wrap_down); } break; } dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], dlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9594 "bacon.bac"
__b2c__assign = (char*)"keys = (char**)calloc(__b2c__hash_nrkeys(name), sizeof(char*)); dups = (void**)calloc(__b2c__hash_nrkeys(name), sizeof(void*)); for(i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", sizeof(char)); } switch (type)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9595 "bacon.bac"
__b2c__assign = (char*)"{ case 0: keys[i] = __b2c__strdup((char*)values[i]); break; case 1: snprintf (keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(double *) values[i]); break; case 2: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(float*)values[i]); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9596 "bacon.bac"
__b2c__assign = (char*)"case 3: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", *(long *) values[i]); break; case 4: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(int *) values[i]); break; case 5: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(short*)values[i]); break; case 6:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9597 "bacon.bac"
__b2c__assign = (char*)"snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(char *) values[i]); break; } dups[i] = __b2c__strdup((char*)__b2c__hash_find_value_do (inv, keys[i])); __b2c__hash_del_norebuild (inv, keys[i]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9598 "bacon.bac"
__b2c__assign = (char*)"do { if(type == 0) { while(cur < pos-1 && !strcmp(keys[cur], keys[cur+1])) { cur++; } } else { while(cur < pos-1 && !memcmp(keys[cur], keys[cur+1], sizeof(void*))) { cur++; } } qsort (&dups[start], cur-start+1, sizeof (char *), __b2c__sortstr);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9599 "bacon.bac"
__b2c__assign = (char*)"for (j = start; j <= cur; j++) { len = __b2c__len ((char *) dups[j]); buf[idx] = (char*)__b2c_str_realloc(buf[idx], total + len + dlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9600 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + total, dups[j], len); free(dups[j]); free(keys[j]); total += len; memmove(buf[idx] + total, delim, dlen); total += dlen; } cur++; start = cur; } while(cur < pos);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9601 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_clear (inv); free(inv); free(values); free(dups); free(keys); total -= dlen; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return((char*)buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9602 "bacon.bac"
}
#line 9604 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "LOOKUP[[:space:]]|SORT[[:space:]]") ){
#line 9605 "bacon.bac"
__b2c__assign = (char*)"int __b2c__lookup_by_order(__b2c__htable *name, char ***array, int size, int base) { int i, count = 0; if(name) { if(*array) { __b2c__free_str_array_members (&(*array), base, size); free(*array); } *array = (char **)calloc(__b2c__hash_nrkeys(name)+base, sizeof(char*));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9606 "bacon.bac"
__b2c__assign = (char*)"count = base; do { for(i = 0; i < name->total; i++) { (*array)[count] = __b2c_Copy_String((*array)[count], name->index[i]); count++; } name = name->next; } while(name); count -= base; } return(count); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9607 "bacon.bac"
__b2c__assign = (char*)"int __b2c__lookup_by_sort (__b2c__htable * name, char ***array, int size, int base, int type, int (*compare)(const void*, const void*)) { void **values = { NULL }; char **keys = { NULL }; __b2c__htable *ptr, *inv; char *value; int i, j, pos = 0, count = 0, cur = 0, start = 0; unsigned short loc; char buf["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) " + 1] = { 0 };"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9608 "bacon.bac"
__b2c__assign = (char*)"if (*array) { __b2c__free_str_array_members (&(*array), base, size); free (*array); } if (name) { values = (void **) calloc (__b2c__hash_nrkeys (name), sizeof (char *)); inv = __b2c__hash_new (); ptr = name; do"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9609 "bacon.bac"
__b2c__assign = (char*)"{ for (i = 0; i < ptr->total; i++) { loc = __b2c__HashFNV1a_16 (ptr->index[i]); switch (type) { case 0: value = (char*)ptr->value[loc]; break; case 1: snprintf (buf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(double *) ptr->value[loc]); value = buf; break; case 2: snprintf (buf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(float *) ptr->value[loc]); value = buf;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9610 "bacon.bac"
__b2c__assign = (char*)"break; case 3: snprintf (buf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", *(long *) ptr->value[loc]); value = buf; break; case 4: snprintf (buf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(int *) ptr->value[loc]); value = buf; break; case 5: snprintf (buf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(short *) ptr->value[loc]); value = buf; break; case 6: snprintf (buf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(char *) ptr->value[loc]);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9611 "bacon.bac"
__b2c__assign = (char*)"value = buf; break; } __b2c__hash_add_redundant(inv, ptr->index[i], value); values[pos++] = ptr->value[loc]; } ptr = ptr->next; } while (ptr); qsort (&values[0], pos, sizeof (void *), compare); *array = (char**)calloc(__b2c__hash_nrkeys(name) + base, sizeof(char*)); keys = (char**)calloc(__b2c__hash_nrkeys(name) + base, sizeof(char*));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9612 "bacon.bac"
__b2c__assign = (char*)"count = base; for (i = 0; i < pos; i++) { if(type > 0) { keys[i] = (char*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", sizeof(char)); } switch (type) { case 0: keys[i] = __b2c__strdup((char*)values[i]); break; case 1: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(double *) values[i]); break; case 2: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(float *) values[i]); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9613 "bacon.bac"
__b2c__assign = (char*)"case 3: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", *(long *) values[i]); break; case 4: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(int *) values[i]); break; case 5: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(short *) values[i]); break; case 6: snprintf(keys[i], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(char *) values[i]); break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9614 "bacon.bac"
__b2c__assign = (char*)"value = (char*)__b2c__hash_find_value_do(inv, keys[i]); (*array)[count++] = __b2c__strdup (value); __b2c__hash_del_norebuild (inv, keys[i]); } do { if (type == 0) { while (cur < pos - 1 && !strcmp (keys[cur], keys[cur + 1])) { cur++; } } else { while (cur < pos - 1 && !memcmp (keys[cur], keys[cur + 1], sizeof(void*))) { cur++; }}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9615 "bacon.bac"
__b2c__assign = (char*)"qsort(&(*array)[start+base], cur - start + 1, sizeof(char*), __b2c__sortstr); for (j = start; j <= cur; j++) { free (keys[j]); } cur++; start = cur; } while (cur < pos); __b2c__hash_clear (inv); free (inv); free (values);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9616 "bacon.bac"
__b2c__assign = (char*)"free (keys); count -= base; } return (count); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9617 "bacon.bac"
}
#line 9619 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "HEX\\$\\(") ){
#line 9620 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__dec2hex(int nr) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int len; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9621 "bacon.bac"
__b2c__assign = (char*)"len = snprintf(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%X\", nr); __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9622 "bacon.bac"
}
#line 9624 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "HOST\\$\\(") ){
#line 9625 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__nethost(int l, char *k, char *host) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int y, flag = 0; struct hostent *he = NULL; unsigned char bf[sizeof(struct sockaddr_in*)]; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9626 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); for (y = 0; host[y] != '\\0'; y++) { if (isalpha (*(host + y))) { flag = 1; break; } } if (flag){ he = gethostbyname (host); strncpy(buf[idx], inet_ntoa(*((struct in_addr*)he->h_addr)), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9627 "bacon.bac"
__b2c__assign = (char*)"else { if (inet_pton(AF_INET, host, bf) <= 0) { ERROR = 11; RUNTIMEFERR (\"HOST$\", ERROR, k, l); strncpy(buf[idx], \"Host not found\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9628 "bacon.bac"
__b2c__assign = (char*)"else { he = gethostbyaddr(bf, sizeof(struct sockaddr_in*), AF_INET); if(he == NULL) { ERROR = 11; RUNTIMEFERR (\"HOST$\", ERROR, k, l); strncpy(buf[idx], \"Host not found\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); return(NULL); } else { strncpy(buf[idx], he->h_name, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9629 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx]["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "-1] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9630 "bacon.bac"
}
#line 9632 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "HOSTNAME\\$") ){
#line 9633 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__hostname(int l, char *k) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) " * sizeof (char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9634 "bacon.bac"
__b2c__assign = (char*)"if(gethostname(buf[idx], "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ")) { ERROR = 26; RUNTIMEFERR(\"HOSTNAME$\", ERROR, k, l); strncpy(buf[idx], \"Error getting hostname\", "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9635 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], strlen(buf[idx])); buf[idx]["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "-1] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9636 "bacon.bac"
}
#line 9638 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INDEX\\(") ){
#line 9639 "bacon.bac"
__b2c__assign = (char*)"int __b2c__index (int line, char *k, size_t range, int type, void *array, int flag, ...) { int result = 0 + "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_FUNCTIONS);
__b2c__assign = (char*) "; double d; float f; long l; int i; short s; char c; char *term; void *index; va_list ap; va_start (ap, flag); if (flag == 0) { switch (type)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9640 "bacon.bac"
__b2c__assign = (char*)"{ case 0: term = va_arg(ap, char*); if ((index = lfind (&term, array, &range, sizeof (char *), __b2c__sortstr)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char *) + 1; } break; case 1: d = va_arg (ap, double); if ((index = lfind (&d, array, &range, sizeof (double), __b2c__sortnrd)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (double) + 1; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9641 "bacon.bac"
__b2c__assign = (char*)"case 2: f = va_arg (ap, double); if ((index = lfind (&f, array, &range, sizeof (float), __b2c__sortnrf)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (float) + 1; } break; case 3: l = va_arg (ap, long); if ((index = lfind (&l, array, &range, sizeof (long), __b2c__sortnrl)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (long) + 1; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9642 "bacon.bac"
__b2c__assign = (char*)"case 4: i = va_arg (ap, int); if ((index = lfind (&i, array, &range, sizeof (int), __b2c__sortnri)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (int) + 1; } break; case 5: s = va_arg (ap, int); if ((index = lfind (&s, array, &range, sizeof (short), __b2c__sortnrs)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (short) + 1; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9643 "bacon.bac"
__b2c__assign = (char*)"case 6: c = va_arg (ap, int); if ((index = lfind (&c, array, &range, sizeof (char), __b2c__sortnrc)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char) + 1; } break; default: ERROR = 43; RUNTIMEFERR (\"INDEX\", ERROR, k, line); return(0); } } else { switch (type)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9644 "bacon.bac"
__b2c__assign = (char*)"{ case 0: term = va_arg(ap, char*); if ((index = bsearch (&term, array, range, sizeof (char *), __b2c__sortstr)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char *) + 1; } break; case 1: d = va_arg (ap, double); if ((index = bsearch (&d, array, range, sizeof (double), __b2c__sortnrd)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (double) + 1; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9645 "bacon.bac"
__b2c__assign = (char*)"case 2: f = va_arg (ap, double); if ((index = bsearch (&f, array, range, sizeof (float), __b2c__sortnrf)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (float) + 1; } break; case 3: l = va_arg (ap, long); if ((index = bsearch (&l, array, range, sizeof (long), __b2c__sortnrl)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (long) + 1; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9646 "bacon.bac"
__b2c__assign = (char*)"case 4: i = va_arg (ap, int); if ((index = bsearch (&i, array, range, sizeof (int), __b2c__sortnri)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (int) + 1; } break; case 5: s = va_arg (ap, int); if ((index = bsearch (&s, array, range, sizeof (short), __b2c__sortnrs)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (short) + 1; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9647 "bacon.bac"
__b2c__assign = (char*)"case 6: c = va_arg (ap, int); if ((index = bsearch (&c, array, range, sizeof (char), __b2c__sortnrc)) != NULL) { result = ((uintptr_t) index - (uintptr_t) array) / sizeof (char) + 1; } break; default: ERROR = 43; RUNTIMEFERR (\"INDEX\", ERROR, k, line); return(0); } } va_end (ap); return (result - "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_FUNCTIONS);
__b2c__assign = (char*) "); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9648 "bacon.bac"
}
#line 9650 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INDEX\\$\\(") ){
#line 9651 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__index_assoc (int l, char *k, int type, __b2c__htable * name, ...) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; __b2c__htable *inv; unsigned short pos; char *value, *result; char bf["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) " + 1] = { 0 }; int i, len; va_list ap; if(name == NULL || name->total == 0) { return (NULL); } inv = __b2c__hash_new (); do { for(i = 0; i < name->total; i++) { pos = __b2c__HashFNV1a_16(name->index[i]); switch(type) { case 0: value = (char*)name->value[pos];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9652 "bacon.bac"
__b2c__assign = (char*)"break; case 1: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(double *) name->value[pos]); value = bf; break; case 2: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(float *) name->value[pos]); value = bf; break; case 3: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", *(long *) name->value[pos]); value = bf; break; case 4: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(int *) name->value[pos]); value = bf; break; case 5: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(short *) name->value[pos]); value = bf; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9653 "bacon.bac"
__b2c__assign = (char*)"case 6: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(char *) name->value[pos]); value = bf; break; default: ERROR = 43; RUNTIMEFERR (\"INDEX$\", ERROR, k, l); return(NULL); } __b2c__hash_add_redundant (inv, name->index[i], value); } name = name->next; } while (name); va_start (ap, name); switch (type) { case 0: value = va_arg (ap, char *); break; case 1: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", va_arg (ap, double)); value = bf; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9654 "bacon.bac"
__b2c__assign = (char*)"case 2: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", va_arg (ap, double)); value = bf; break; case 3: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", va_arg (ap, long)); value = bf; break; case 4: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", va_arg (ap, int)); value = bf; break; case 5: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", va_arg (ap, int)); value = bf; break; case 6: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", va_arg (ap, int)); value = bf; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9655 "bacon.bac"
__b2c__assign = (char*)"default: ERROR = 43; RUNTIMEFERR (\"INDEX$\", ERROR, k, l); return(NULL); } va_end (ap); result = (char *) __b2c__hash_find_value_do (inv, value); idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } len = __b2c__len (result); buf[idx] = (char *) __b2c_str_realloc (buf[idx], len + 1); memmove (buf[idx], result, len); __b2c__SETLEN (buf[idx], len); buf[idx][len] = '\\0'; __b2c__hash_clear (inv); free (inv); return ((char *) buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9656 "bacon.bac"
}
#line 9658 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INVERT\\(") ){
#line 9659 "bacon.bac"
__b2c__assign = (char*)"int __b2c__invert (int line, char *k, int type, __b2c__htable ** name) { __b2c__htable *inv, *ptr; char bf["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) " + 1] = { 0 }; unsigned short pos; char *swap = NULL; int j, coll = 0; double d; float f; int i; long l; short s; char c; if (*name == NULL || (*name)->total == 0) { return (0); } inv = __b2c__hash_new (); ptr = *name; do { for (j = 0; j < ptr->total; j++) { pos = __b2c__HashFNV1a_16(ptr->index[j]); switch (type) { case 0: swap = (char*)ptr->value[pos]; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9660 "bacon.bac"
__b2c__assign = (char*)"case 1: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(double *) ptr->value[pos]); d = atof(ptr->index[j]); break; case 2: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%g\", *(float *) ptr->value[pos]); f = atof(ptr->index[j]); break; case 3: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%ld\", *(long *) ptr->value[pos]); l = atol(ptr->index[j]); break; case 4: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(int *) ptr->value[pos]); i = atoi(ptr->index[j]); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9661 "bacon.bac"
__b2c__assign = (char*)"case 5: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(short *) ptr->value[pos]); s = atoi(ptr->index[j]); break; case 6: snprintf (bf, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", *(char *) ptr->value[pos]); c = atoi(ptr->index[j]); break; default: ERROR = 43; RUNTIMEFERR (\"INVERT\", ERROR, k, line); return(0); } if(__b2c__hash_find_value_do(inv, bf) || __b2c__hash_find_value_do(inv, swap)) { coll++; } switch(type) { case 0: __b2c__hash_add_str(inv, ptr->index[j], swap); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9662 "bacon.bac"
__b2c__assign = (char*)"case 1: __b2c__hash_add(inv, &d, bf); break; case 2: __b2c__hash_add(inv, &f, bf); break; case 3: __b2c__hash_add(inv, &l, bf); break; case 4: __b2c__hash_add(inv, &i, bf); break; case 5: __b2c__hash_add(inv, &s, bf); break; case 6: __b2c__hash_add(inv, &c, bf); break; default: ERROR = 43; RUNTIMEFERR (\"INVERT\", ERROR, k, line); return(0); } } ptr = ptr->next; } while (ptr); __b2c__hash_clear (*name);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9663 "bacon.bac"
__b2c__assign = (char*)"free(*name); *name = inv; return(coll); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9664 "bacon.bac"
}
#line 9666 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INSERT\\$\\(") ){
#line 9667 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__insert (int l, char *k, char *src, int pos, char *str) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tot, blen; if (str == NULL) { return (src); } if (src == NULL) { return(str); } len = __b2c__len (src); tot = __b2c__len (str);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9668 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+tot+1); pos--; if (pos <= 0) { memmove(buf[idx], str, tot); memmove(buf[idx] + tot, src, len); } else if (pos > len) { memmove(buf[idx], src, len);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9669 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + len, str, tot); } else { if (__b2c__option_utf8) { blen = __b2c__blen (l, k, \"INSERT$\", src, pos, 0); memmove(buf[idx], src, blen); memmove(buf[idx] + blen, str, tot);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9670 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + blen + tot, src + blen, len - blen); } else { memmove(buf[idx], src, pos); memmove(buf[idx] + pos, str, tot); memmove(buf[idx] + pos + tot, src + pos, len - pos); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9671 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], len + tot); buf[idx][len + tot] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9672 "bacon.bac"
}
#line 9674 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INSTR\\(") ){
#line 9675 "bacon.bac"
__b2c__assign = (char*)"long __b2c__instr(int l, char *k, char *first, char *tmp, int pos) { char *result; if (first == NULL) { return (0); } if (tmp == NULL || __b2c__len (tmp) == 0) { return (0); } if (pos <= 0) { pos = 1; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9676 "bacon.bac"
__b2c__assign = (char*)"result = strstr (first + pos - 1, tmp); if(result == NULL) { return (0); } if (__b2c__option_utf8) { return (long) __b2c__ucs2_clen (l, k, \"INSTR\", first, result - first + 1); } return (long) (result - first + 1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9677 "bacon.bac"
}
#line 9679 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INSTRREV\\(") ){
#line 9680 "bacon.bac"
__b2c__assign = (char*)"long __b2c__instrrev(int m, char *k, char *first, char *tmp, int pos) { char *result, *found; long l; if (first == NULL){ return (0);} if (tmp == NULL || __b2c__len (tmp) == 0) { return (0); } if (pos < 0) { pos = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9681 "bacon.bac"
__b2c__assign = (char*)"l = __b2c__len (first); found = first; do { result = strstr (found, tmp); if (result != NULL && result <= first + l - pos) { found = result + 1; continue; } if (result > first + l - pos) result = NULL; } while (result != NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9682 "bacon.bac"
__b2c__assign = (char*)"if (__b2c__option_startpoint) { if (l - (found - first) + 1 > l) { return(0); } if (__b2c__option_utf8) { return (long) (__b2c__ulen (l, k, \"INSTRREV\", first, -1) - __b2c__ucs2_clen (l, k, \"INSTRREV\", first, found - first) + 1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9683 "bacon.bac"
__b2c__assign = (char*)"return (long) (l - (found - first) + 1); } if (__b2c__option_utf8) { return (long) __b2c__ucs2_clen (m, k, \"INSTRREV\", first, found - first); } return (long) (found - first); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9684 "bacon.bac"
}
#line 9686 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "LCASE\\$\\(") ){
#line 9687 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__lcase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } len = __b2c__len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9688 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], len+1); if (__b2c__option_utf8) { local = setlocale (LC_ALL, \"\"); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9689 "bacon.bac"
__b2c__assign = (char*)"if(mbstowcs(wcs, src, mbslen + 1) == (size_t)-1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towlower (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t)-1) { ERROR = 38; RUNTIMEFERR (\"LCASE$\", ERROR, k, l); return(NULL); } free (wcs);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9690 "bacon.bac"
__b2c__assign = (char*)"setlocale (LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = tolower(src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9691 "bacon.bac"
}
#line 9693 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "LEFT\\$\\(") ){
#line 9694 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__left(int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len (src);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9695 "bacon.bac"
__b2c__assign = (char*)"if (n > (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"LEFT$\", src, length) : length)) { return(src); } else { if (__b2c__option_utf8)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9696 "bacon.bac"
__b2c__assign = (char*)"{ n = __b2c__blen (l, k, \"LEFT$\", src, n, 0); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], n+1); memmove(buf[idx], src, n); __b2c__SETLEN (buf[idx], n); buf[idx][n] = '\\0'; } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9697 "bacon.bac"
}
#line 9699 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "BLOAD\\(|LOAD\\$\\(") ){
#line 9700 "bacon.bac"
__b2c__assign = (char*)"char* __b2c__load(int flag, int l, char *k, char *file) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; FILE *handle; struct stat bf; void* mem; handle = fopen ((const char*)file, \"r\"); if(handle == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9701 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 2; RUNTIMEFERR (\"LOAD$/BLOAD\", ERROR, k, l); return(NULL); } if(stat(file, &bf) < 0) { ERROR = 24; RUNTIMEFERR (\"LOAD$/BLOAD\", ERROR, k, l); return(NULL); } if(flag) { mem = calloc(bf.st_size+__b2c__option_memstream, sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9702 "bacon.bac"
__b2c__assign = (char*)"if(fread (mem, sizeof (char), bf.st_size, handle) != (size_t)bf.st_size) { ERROR = 2; RUNTIMEFERR(\"BLOAD\", ERROR, k, l); return(NULL); } fclose(handle); return(char*)(mem); } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9703 "bacon.bac"
__b2c__assign = (char*)"{ idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], bf.st_size + 1); if(fread(buf[idx], sizeof (char), bf.st_size, handle) != (size_t)bf.st_size)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9704 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 2; RUNTIMEFERR (\"LOAD$\", ERROR, k, l); return(NULL); } __b2c__SETLEN(buf[idx], bf.st_size); buf[idx][bf.st_size] = '\\0'; fclose(handle); return(char*)(buf[idx]); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9705 "bacon.bac"
}
#line 9707 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "MID\\$\\(") ){
#line 9708 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__mid(int l, char *k, char **swap, int type, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9709 "bacon.bac"
__b2c__assign = (char*)"idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } src_len = __b2c__len (src); pos -= 1; if (pos < 0) { pos = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"MID$\", src, src_len) : src_len) + 1 + pos; } if (__b2c__option_utf8) { pos = __b2c__blen (l, k, \"MID$\", src, pos, 0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9710 "bacon.bac"
__b2c__assign = (char*)"if (pos > src_len) { if (type == 1) { *swap = __b2c_Copy_String (*swap, NULL); } return(NULL); } if (__b2c__option_utf8 && length >= 0) { length = __b2c__blen (l, k, \"MID$\", src + pos, length, 0); } if (length < 0 || pos + length > src_len) { length = src_len - pos; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9711 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + 1); memmove (buf[idx], src + pos, length); __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\\0'; if (type == 1) { return (__b2c_Swap_String (swap, &buf[idx])); } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9712 "bacon.bac"
}
#line 9714 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "OS\\$") ){
#line 9715 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__os(int l, char *k) { static char *result = NULL ; struct utsname bf; unsigned int len = 0; if(!result) { result = (char*)__b2c_str_realloc(result, 256 * sizeof (char)); if (uname(&bf) < 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9716 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 26; RUNTIMEFERR(\"OS$\", ERROR, k, l); return(NULL); } strncpy(result, bf.sysname, 64); len += strlen(bf.sysname); strncat(result, \" \", 2); len++; strncat(result, bf.machine, 128);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9717 "bacon.bac"
__b2c__assign = (char*)"len += strlen(bf.machine); __b2c__SETLEN(result, len); result[len] = '\\0'; } return(char*)result; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9718 "bacon.bac"
}
#line 9720 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "PEEK\\(") ){
#line 9721 "bacon.bac"
__b2c__assign = (char*)"void *__b2c__peek_check(int l, char *k, char *x, int size) { if(!__b2c__memory__check((char*)x, size)) { ERROR=1; RUNTIMEFERR(\"PEEK\", ERROR, k, l); } return((void*)x); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9722 "bacon.bac"
}
#line 9724 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "RECURSIVE[[:space:]]") ){
#line 9725 "bacon.bac"
__b2c__assign = (char*)"int __b2c__rmrecursive(int l, char *k, char *dir){ DIR *mydir; char *path, *item = NULL; struct stat buf = { 0 }; struct dirent *next = { NULL }; mydir = opendir(dir); if(mydir == NULL) { ERROR = 8; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9726 "bacon.bac"
__b2c__assign = (char*)"while (1) { if (item != NULL) free(item); next = readdir(mydir); if(next != NULL) { item = (char*)calloc((strlen (next->d_name) + 1), sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9727 "bacon.bac"
__b2c__assign = (char*)"strcpy(item, next->d_name); } else { break; } if (!strcmp (item, \".\") || !strcmp(item, \"..\") ) continue; path = (char*)calloc(strlen(dir)+strlen(item)+2, sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9728 "bacon.bac"
__b2c__assign = (char*)"strcpy(path, dir); strcat(path, \"/\"); strcat(path, item); lstat(path, &buf); if(S_ISDIR (buf.st_mode)) { __b2c__rmrecursive(l, k, path); } else { if(remove(path) < 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9729 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 7; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); } } if(path != NULL) free(path); } closedir(mydir); if(remove(dir) < 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9730 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 7; RUNTIMEFERR(\"DELETE RECURSIVE\", ERROR, k, l); return(0); } return(0);}"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9731 "bacon.bac"
}
#line 9733 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "REVERSE\\$\\(") ){
#line 9734 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__reverse(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long i, length, len, blen; if (src == NULL) { return (NULL); } length = __b2c__len (src); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9735 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); if(__b2c__option_utf8) { len = length; while (len > 0) { blen = __b2c__blen (l, k, \"REVERSE$\", src, 1, 0); memcpy(buf[idx] + len - blen, src, blen); src += blen; len -= blen; } } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9736 "bacon.bac"
__b2c__assign = (char*)"{ for (i = 0; i < length; i++) { buf[idx][i] = src[length-i-1]; } } __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9737 "bacon.bac"
}
#line 9739 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "RIGHT\\$\\(") ){
#line 9740 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__right (int l, char *k, char *src, unsigned long n) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; unsigned long length; if (src == NULL) { return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } length = __b2c__len (src);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9741 "bacon.bac"
__b2c__assign = (char*)"if (n > (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"RIGHT$\", src, length) : length)) { return(src); } else { if (__b2c__option_utf8)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9742 "bacon.bac"
__b2c__assign = (char*)"{ n = __b2c__blen (l, k, \"RIGHT$\", src, n, 1); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], n+1); memmove(buf[idx], src + length - n, n); __b2c__SETLEN(buf[idx], n); buf[idx][n] = '\\0'; } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9743 "bacon.bac"
}
#line 9745 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "RIP\\$\\(") ){
#line 9746 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__rip(int l, char *k, char *src, long pos, long length) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long src_len; if (src == NULL) { return (NULL); } src_len = __b2c__len (src); pos -= 1;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9747 "bacon.bac"
__b2c__assign = (char*)"if (pos < 0) { pos = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"RIP$\", src, src_len) : src_len) + 1 + pos; } if (__b2c__option_utf8) { pos = __b2c__blen (l, k, \"RIP$\", src, pos, 0); } if (pos > src_len)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9748 "bacon.bac"
__b2c__assign = (char*)"{ return (NULL); } if (__b2c__option_utf8 && length >= 0) { length = __b2c__blen (l, k, \"RIP$\", src + pos, length, 0); } if (length < 0 || pos + length > src_len)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9749 "bacon.bac"
__b2c__assign = (char*)"{ length = src_len - pos; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], src_len); memmove(buf[idx], src, pos); memmove(buf[idx]+pos, src+pos+length, src_len-pos-length);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9750 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], src_len-length); buf[idx][src_len-length] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9751 "bacon.bac"
}
#line 9753 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COLUMNS|ROWS") ){
#line 9754 "bacon.bac"
__b2c__assign = (char*)"long __b2c__screen(int type){long x; struct winsize tmp; ioctl(STDOUT_FILENO, TIOCGWINSZ, &tmp); if(type) { x = tmp.ws_row; } else { x = tmp.ws_col; } return(x); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9755 "bacon.bac"
}
#line 9757 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SEARCH\\(") ){
#line 9758 "bacon.bac"
__b2c__assign = (char*)"long __b2c__search (int l, char *k, FILE * x, char *y, int whence) { long off, pos=0, org_pos; int flag = 0; char *ptr; if (x == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9759 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 2; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } if (y == NULL) { ERROR = 25; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } org_pos = ftell (x); ptr = (char *) malloc (__b2c__len (y) + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9760 "bacon.bac"
__b2c__assign = (char*)"switch(whence) { case -1: case 0: off = 1; break; case 1: off = 1; break; case 2: off = -1; break; case 3: off = -1; break; default: ERROR = 37; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } do { switch(whence) { case -1: case 0: fseek (x, pos, SEEK_SET);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9761 "bacon.bac"
__b2c__assign = (char*)"break; case 1: fseek (x, org_pos+pos, SEEK_SET);break; case 2: flag = fseek (x, org_pos- __b2c__len (y)+pos, SEEK_SET); break; case 3: fseek (x, pos-__b2c__len (y), SEEK_END); break; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9762 "bacon.bac"
__b2c__assign = (char*)"if (fread (ptr, sizeof (char), __b2c__len (y), x) <= 0) { ERROR = 2; RUNTIMEFERR (\"SEARCH\", ERROR, k, l); return(0); } pos += off; } while (!feof (x) && !flag && memcmp (ptr, y, __b2c__len (y)));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9763 "bacon.bac"
__b2c__assign = (char*)"if (memcmp (ptr, y, __b2c__len (y))) { pos = -1; } else {pos = ftell(x)-__b2c__len (y); } fseek (x, org_pos, SEEK_SET); free (ptr); return(pos); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9764 "bacon.bac"
}
#line 9766 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SPC\\$\\(") ){
#line 9767 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__spc(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; if(amount <= 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9768 "bacon.bac"
__b2c__assign = (char*)"memset(buf[idx], 32, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9769 "bacon.bac"
}
#line 9771 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SUM\\(|SUMF\\(") ){
#line 9772 "bacon.bac"
__b2c__assign = (char*)"long __b2c__sum(int base, long *array, long nr, ...) { va_list ap; long limit = 0, total = 0; int x; va_start (ap, nr); limit = va_arg (ap, long); va_end (ap);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9773 "bacon.bac"
__b2c__assign = (char*)"for(x = base; x < nr+base; x++) { if(limit == LONG_MAX){ total += array[x]; } else { if(array[x]>limit) { total += array[x]; } } } return(total); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9774 "bacon.bac"
__b2c__assign = (char*)"double __b2c__sumf(int base, double *array, double nr, ...) { va_list ap; double limit = 0, total = 0; int x; va_start (ap, nr); limit = va_arg (ap, double); va_end (ap);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9775 "bacon.bac"
__b2c__assign = (char*)"for(x = base; x < nr+base; x++) { if(limit == DBL_MAX){ total += array[x]; } else { if(array[x]>limit) { total += array[x]; } } } return(total); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9776 "bacon.bac"
}
#line 9778 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TAB\\$\\(") ){
#line 9779 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__tab(int amount) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; if(amount <= 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], amount+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9780 "bacon.bac"
__b2c__assign = (char*)"memset(buf[idx], 9, amount); __b2c__SETLEN(buf[idx], amount); buf[idx][amount] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9781 "bacon.bac"
}
#line 9783 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TALLY\\(") ){
#line 9784 "bacon.bac"
__b2c__assign = (char*)"long __b2c__tally(char *haystack, char *needle, int pos) { char *res; long total = 0; if (haystack == NULL) { return (0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9785 "bacon.bac"
__b2c__assign = (char*)"if (needle == NULL || __b2c__len(needle) == 0) { return (0); } if (pos <= 0) { pos = 1; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9786 "bacon.bac"
__b2c__assign = (char*)"haystack+=pos-1; while((res = strstr(haystack, needle)) != NULL) { haystack = res+1; total++; } return((long)total); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9787 "bacon.bac"
}
#line 9789 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "DAY\\(|HOUR\\(|MINUTE\\(|MONTH\\(|SECOND\\(|WEEK\\(|YEAR\\(") ){
#line 9790 "bacon.bac"
__b2c__assign = (char*)"long __b2c__time (time_t now, int which){ long result; char *buffer; struct tm *ts; buffer = (char*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", sizeof (char)); ts = localtime (&now); switch (which) {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9791 "bacon.bac"
__b2c__assign = (char*)"case 1: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%d\", ts); break; case 2: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%m\", ts); break; case 3: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%Y\", ts); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9792 "bacon.bac"
__b2c__assign = (char*)"case 4: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%H\", ts); break; case 5: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%M\", ts); break; case 6: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%S\", ts); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9793 "bacon.bac"
__b2c__assign = (char*)"case 7: strftime (buffer, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_DIGITS), g_FUNCTIONS);
__b2c__assign = (char*) ", \"%W\", ts); break; } result = atol(buffer); free(buffer); return(result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9794 "bacon.bac"
}
#line 9796 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ALIGN\\$\\(|AMOUNT\\(|APPEND\\$\\(|CHANGE\\$\\(|COIL\\$\\(|COLLAPSE\\$\\(|CUT\\$\\(|DEL\\$\\(|DELIM\\$\\(|EXCHANGE\\$\\(|EXEC\\$\\(|EXPLODE\\$\\(|FIRST\\$\\(|FOR[[:space:]]|HASDELIM\\(|HEAD\\$\\(|INBETWEEN\\$\\(|ISTOKEN\\(|LAST\\$\\(|MAKEDIR[[:space:]]|MATCH\\(|MERGE\\$\\(|NETWORK[[:space:]]|OUTBETWEEN\\$\\(|PARSE[[:space:]]|PROPER\\$\\(|REV\\$\\(|ROTATE\\$\\(|SERVER[[:space:]]|SORT\\$\\(|SPLIT[[:space:]]|TAIL\\$\\(|TOKEN\\$\\(|UNIQ\\$\\(|WHERE\\(") ){
#line 9797 "bacon.bac"
__b2c__assign = (char*)"/* API >>>> nr == 0, use_cache == 0 : rebuild cache | nr != 0, use_cache == 0 : dynamic calc member | nr != 0, use_cache == 1 : use member from cache */"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9798 "bacon.bac"
__b2c__assign = (char*)"long __b2c__delim_engine_core(int action, int type, long *returned_value, char *string, char *delim, long nr, int use_cache) { static long *cache = NULL, cache_tot = 0, cnt = 0; long x, len, pos = 0, start = 0; int in_string = 0, is_escaped = 0; if(action == 0) { if(cache) { free(cache); cache = NULL; } return(0); } *returned_value = 0; if (string == NULL || string[0] == 0) { return (0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9799 "bacon.bac"
__b2c__assign = (char*)"if (delim == NULL) { delim = __b2c__option_delim; } len = __b2c__len (delim); if(!use_cache) { cnt = 0; for (x = 0; string[x] != 0; x++) { if (!in_string) { if (len == 1 ? string[x] == delim[0] : !strncmp (string + x, delim, len)) { if (__b2c__collapse == 0 || x > start) { cnt++; if (cnt > cache_tot)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9800 "bacon.bac"
__b2c__assign = (char*)"{ cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start; cache[cnt * 2 + 1] = start; } if(nr && nr == cnt) { break; } start = x + len; } } if (string[x] == __b2c__option_esc) { if (!is_escaped) { is_escaped = 1; } else { is_escaped = 0; } } else if (string[x] == __b2c__option_dq)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9801 "bacon.bac"
__b2c__assign = (char*)"{ if (!is_escaped && __b2c__option_quoted) { in_string = 1 - in_string; } is_escaped = 0; } else { is_escaped = 0; } } if (__b2c__collapse == 0 || x > start) { cnt++; if (cnt > cache_tot) { cache = (long*)realloc(cache, (cnt*2+2) * sizeof(long)); cache_tot = cnt; } cache[cnt * 2] = x - start;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9802 "bacon.bac"
__b2c__assign = (char*)"cache[cnt * 2 + 1] = start; } } if (nr <= cnt) { if (type == 1) { *returned_value = cache[nr*2]; pos = cache[nr*2+1]; } else { *returned_value = cnt; pos = cache[nr*2+1]; } } return(pos); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9803 "bacon.bac"
}
#line 9805 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TOKEN\\$\\(") ){
#line 9806 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__token(char *string, long nr, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long length = 0; if (string == NULL || nr < 1) { return (NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9807 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine(1, &length, string, delim, nr); if(length == 0) { return(NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9808 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], length+1); memmove(buf[idx], string + start, length); __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9809 "bacon.bac"
}
#line 9811 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "WHERE\\(") ){
#line 9812 "bacon.bac"
__b2c__assign = (char*)"long __b2c__where(char *string, long nr, char *delim) { long result = 0, length = 0; if (string == NULL || nr < 1) { return (0); } result = __b2c__delim_engine (1, &length, string, delim, nr); return(result+1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9813 "bacon.bac"
}
#line 9815 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "AMOUNT\\(") ){
#line 9816 "bacon.bac"
__b2c__assign = (char*)"long __b2c__amount(char *string, char *delim) { long amount = 0; if (string == NULL) { return (0); } __b2c__delim_engine(2, &amount, string, delim, 0); return(amount); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9817 "bacon.bac"
}
#line 9819 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "HASDELIM\\(") ){
#line 9820 "bacon.bac"
__b2c__assign = (char*)"int __b2c__hasdelim (char *string, char *delim) { long length = 0; long start = 0; if (string == NULL) { return (0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9821 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine (2, &length, string, delim, 2); if(start == 0) { return (0); } if (delim == NULL) { delim = __b2c__option_delim; } return (start-__b2c__len (delim)+1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9822 "bacon.bac"
}
#line 9824 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EXCHANGE\\$\\(") ){
#line 9825 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__exchange (char *string, int index1, int index2, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tmp, tlen, len1, len2, start1 = 0, start2 = 0; long length = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9826 "bacon.bac"
__b2c__assign = (char*)"if (string == NULL || index1 <= 0 || index2 <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start1 = __b2c__delim_engine(1, &length, string, delim, index1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9827 "bacon.bac"
__b2c__assign = (char*)"len1 = length; length = 0; start2 = __b2c__delim_engine(1, &length, string, delim, index2); len2 = length; if (start1 == start2) { return (string); } else if (start2 < start1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9828 "bacon.bac"
__b2c__assign = (char*)"{ tmp = start2; start2 = start1; start1 = tmp; tmp = len2; len2 = len1; len1 = tmp; } tlen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen+1); memmove(buf[idx], string, start1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9829 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + start1, string + start2, len2); memmove(buf[idx] + start1 + len2, string + start1 + len1, start2 - (start1 + len1));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9830 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + start1 + len2 + start2 - (start1 + len1), string + start1, len1); memmove(buf[idx] + start1 + len2 + start2 - (start1 + len1) + len1, string + start2 + len2, tlen - (start2 + len2));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9831 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], tlen); buf[idx][tlen] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9832 "bacon.bac"
}
#line 9834 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CHANGE\\$\\(") ){
#line 9835 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__change(char *string, int index, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long tlen, start, len, nlen; long length = 0; if(string == NULL) { return(cnew); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9836 "bacon.bac"
__b2c__assign = (char*)"if (index <= 0) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine(1, &length, string, delim, index); len = length; tlen = __b2c__len(string); nlen = __b2c__len(cnew);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9837 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], tlen-len+nlen+1); memmove(buf[idx], string, start); memmove(buf[idx] + start, cnew, nlen); memmove(buf[idx] + start + nlen, string + start + len, tlen - (start + len));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9838 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], tlen - len + nlen); buf[idx][tlen-len+nlen] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9839 "bacon.bac"
}
#line 9841 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ISTOKEN\\(") ){
#line 9842 "bacon.bac"
__b2c__assign = (char*)"long __b2c__istoken(char *string, char *token, char *delim) { long len, start, x, result = 0; long length = 0, amount = 0; if(string == NULL) { return(0); } if(delim == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9843 "bacon.bac"
__b2c__assign = (char*)"{ delim = __b2c__option_delim; } len = __b2c__len(token); if(len==0) { return(0); } start = __b2c__delim_engine (2, &amount, string, delim, 0); for(x = 0; x < amount; x++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9844 "bacon.bac"
__b2c__assign = (char*)"{ start = __b2c__delim_engine_cache(1, &length, string, delim, x+1); if(len == length && memcmp(string + start, token, len) == 0) { result = x+1; break; } } return (result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9845 "bacon.bac"
}
#line 9847 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "UNIQ\\$\\(") ){
#line 9848 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__uniq(char *string, char *delim) { long x, start, amount = 0, length = 0; int t = 1; __b2c__htable *table; char *item, *result; if(string == NULL) { return (string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9849 "bacon.bac"
__b2c__assign = (char*)"if(delim == NULL) { delim = __b2c__option_delim; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if(amount <= 1) { return (string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9850 "bacon.bac"
__b2c__assign = (char*)"table = __b2c__hash_new(); for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache(1, &length, string, delim, x+1); item = __b2c__strndup(string+start, length);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9851 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__hash_find_key(table, 0, item)) { __b2c__hash_add(table, &t, item); } __b2c__STRFREE(item); } result = __b2c__hash_obtain(table, delim);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9852 "bacon.bac"
__b2c__assign = (char*)"__b2c__hash_clear(table); free(table); return(result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9853 "bacon.bac"
}
#line 9855 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SORT\\$\\(") ){
#line 9856 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__sort(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char **array; char *buffer, *backup; long start, total = 0, x, len, dlen; long amount = 0; long length = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9857 "bacon.bac"
__b2c__assign = (char*)"if(string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9858 "bacon.bac"
__b2c__assign = (char*)"buffer = __b2c__strdup (string); backup = buffer; start = __b2c__delim_engine (2, &amount, buffer, delim, 0); array = (char **) calloc(amount, sizeof (char *)); for (x = 0; x < amount; x++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9859 "bacon.bac"
__b2c__assign = (char*)"{ start = __b2c__delim_engine (1, &length, string, delim, 1); buffer[start + length] = '\\0'; if(buffer[start] == 34 && buffer[start+length-1] == 34) { buffer[start + length-1] = '\\0';"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9860 "bacon.bac"
__b2c__assign = (char*)"array[x] = buffer + start + 1; } else { array[x] = buffer + start; } string += (start + length + dlen); buffer += (start + length + dlen); } qsort (&array[0], amount, sizeof (char *), __b2c__sortstr);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9861 "bacon.bac"
__b2c__assign = (char*)"for (x = 0; x < amount; x++) { len = strlen (array[x]); if(strstr(array[x], delim)) { buf[idx][total] = 34; memmove(buf[idx] + total+1, array[x], len);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9862 "bacon.bac"
__b2c__assign = (char*)"buf[idx][total+len+1] = 34; total += len+2;} else { memmove(buf[idx] + total, array[x], len); total += len; } if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9863 "bacon.bac"
__b2c__assign = (char*)"total += dlen; } } __b2c__STRFREE(backup); free(array); __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9864 "bacon.bac"
}
#line 9866 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SORT[[:space:]]") ){
#line 9867 "bacon.bac"
__b2c__assign = (char*)"void __b2c__assoc_sort(__b2c__htable **name, int type, int (*compare) (const void *, const void *)) { char **results = {  NULL }; int total; char *value; __b2c__htable *ptr; int i; total =  __b2c__lookup_by_sort(*name, &results, 0, 0, type, compare);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9868 "bacon.bac"
__b2c__assign = (char*)"ptr = __b2c__hash_new(); for (i = 0; i < total; i++) { value = (char *) __b2c__hash_find_value_do(*name, results[i]); if(type == 0) { __b2c__hash_add_str(ptr, value, results[i]); } else { __b2c__hash_add(ptr, value, results[i]); } } __b2c__hash_clear (*name); free (*name); *name = ptr;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9869 "bacon.bac"
__b2c__assign = (char*)"if(results) { __b2c__free_str_array_members(&results, 0, total); free(results); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9870 "bacon.bac"
}
#line 9872 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "REV\\$\\(") ){
#line 9873 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__rev(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total, x, len, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9874 "bacon.bac"
__b2c__assign = (char*)"len = __b2c__len (string); if (delim == NULL) { delim = __b2c__option_delim; } dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9875 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); total = len; for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache(1, &length, string, delim, x+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9876 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + total-length, string + start, length); total -= length; if (x < amount-1) { memmove(buf[idx] + total-dlen, delim, dlen); total -= dlen; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9877 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9878 "bacon.bac"
}
#line 9880 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "DELIM\\$\\(") ){
#line 9881 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__delim(char *string, char *from, char *to) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, tlen, dlen; long amount = 0; long length = 0; if (string == NULL) { return (string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9882 "bacon.bac"
__b2c__assign = (char*)"if(from == NULL) { from = __b2c__option_delim; } if(to == NULL) { to = __b2c__option_delim; } dlen = __b2c__len (from); tlen = __b2c__len (to); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, from, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9883 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+amount*tlen+1); for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, from, 1); memmove(buf[idx] + total, string + start, length);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9884 "bacon.bac"
__b2c__assign = (char*)"total += length; if (x < amount-1) { memmove(buf[idx] + total, to, tlen); total += tlen; } string += (start + length + dlen); } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9885 "bacon.bac"
}
#line 9887 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "HEAD\\$\\(") ){
#line 9888 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__head (char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start; long amount = 0; long length = 0; if (string == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9889 "bacon.bac"
__b2c__assign = (char*)"{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9890 "bacon.bac"
__b2c__assign = (char*)"if(amount < 1 || pos < 1) { return (NULL); } if (pos > amount) { pos = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1); start = __b2c__delim_engine_cache(1, &length, string, delim, pos);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9891 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx], string, start + length); __b2c__SETLEN(buf[idx], start + length); buf[idx][start + length] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9892 "bacon.bac"
}
#line 9894 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TAIL\\$\\(") ){
#line 9895 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__tail(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9896 "bacon.bac"
__b2c__assign = (char*)"{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9897 "bacon.bac"
__b2c__assign = (char*)"if (amount < 1 || pos < 1) { return (NULL); } if (amount - pos + 1 < 1) { pos = 1; } else { pos = amount - pos + 1; } slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9898 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9899 "bacon.bac"
}
#line 9901 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "APPEND\\$\\(|COIL\\$\\(") ){
#line 9902 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__append(char **swap, int type, char *string, long pos, char *cnew, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, slen, nlen, total = 0; long amount = 0; long length = 0; if (cnew == NULL || pos < 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9903 "bacon.bac"
__b2c__assign = (char*)"{ if (type == 1) { *swap = __b2c_Copy_String(*swap, string); } return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9904 "bacon.bac"
__b2c__assign = (char*)"dlen = __b2c__len (delim); nlen = __b2c__len (cnew); slen = __b2c__len (string); buf[idx] = (char *) __b2c_str_realloc (buf[idx], slen + nlen + dlen + 1); if (pos == 0 || pos > amount) { if (__b2c__collapse == 0 || (__b2c__collapse == 1 && slen > 0)) { memmove (buf[idx], string, slen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9905 "bacon.bac"
__b2c__assign = (char*)"total += slen; } if (__b2c__collapse == 0 || (__b2c__collapse == 1 && nlen > 0)) { if(__b2c__collapse == 0 || total) { memmove (buf[idx] + total, delim, dlen); total += dlen; } memmove (buf[idx] + total, cnew, nlen); total += nlen; } } else { start = __b2c__delim_engine_cache (1, &length, string, delim, pos);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9906 "bacon.bac"
__b2c__assign = (char*)"memmove (buf[idx], string, start); total += start; memmove (buf[idx] + total, cnew, nlen); total += nlen; memmove (buf[idx] + total, delim, dlen); total += dlen; memmove (buf[idx] + total, string + start, slen - start); total += (slen - start); } __b2c__SETLEN (buf[idx], total);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9907 "bacon.bac"
__b2c__assign = (char*)"buf[idx][total] = '\\0'; if (type == 1) { return(__b2c_Swap_String(swap, &buf[idx])); } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9908 "bacon.bac"
}
#line 9910 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "DEL\\$\\(") ){
#line 9911 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__del(char *string, long pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen, dlen, total = 0; long amount = 0; long length = 0; if (string == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9912 "bacon.bac"
__b2c__assign = (char*)"{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos < 1 || pos > amount)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9913 "bacon.bac"
__b2c__assign = (char*)"{ return(string); } dlen = __b2c__len (delim); slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1); start = __b2c__delim_engine_cache(1, &length, string, delim, pos); memmove(buf[idx], string, start);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9914 "bacon.bac"
__b2c__assign = (char*)"total += start; if (pos < amount) { memmove(buf[idx] + total, string + start + length + dlen, slen-(start + length + dlen)); total += slen-(start + length + dlen); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9915 "bacon.bac"
__b2c__assign = (char*)"else { if(total >= dlen) { total -= dlen; } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9916 "bacon.bac"
}
#line 9918 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CUT\\$\\(") ){
#line 9919 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__cut(char *string, long pos1, long pos2, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start1, start2, tmp, total = 0; long amount = 0; long length = 0; if (string == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9920 "bacon.bac"
__b2c__assign = (char*)"{ return (string); } if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } if (pos1 > pos2) { tmp = pos1; pos1 = pos2; pos2 = tmp; } __b2c__delim_engine (2, &amount, string, delim, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9921 "bacon.bac"
__b2c__assign = (char*)"if(pos1 < 1) { pos1 = 1; } if(pos2 > amount) { pos2 = amount; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1); start1 = __b2c__delim_engine (1, &length, string, delim, pos1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9922 "bacon.bac"
__b2c__assign = (char*)"start2 = __b2c__delim_engine (1, &length, string, delim, pos2); memmove(buf[idx], string + start1, start2-start1+length); total += (start2-start1+length); __b2c__SETLEN(buf[idx], total);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9923 "bacon.bac"
__b2c__assign = (char*)"buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9924 "bacon.bac"
}
#line 9926 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ALIGN\\$\\(") ){
#line 9927 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__align (int l, char *k, char *str, unsigned long width, int mode, int indent) { static unsigned char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, x, y, left, line_start = 0, paragraph_end = 0, last_write_pos, write_pos = 0, characters, last_read_pos, read_pos = 0, wtotal = 0, ctotal = 0, found = 0, tab, pos, spaces;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9928 "bacon.bac"
__b2c__assign = (char*)"int quoted, collapse, utf8, preserve = 0; long amount = 0, length = 0, total, lw; char *string = NULL, *backup, *concat, *wrap, *line; if (str == NULL) { return (str); } if (width < 1) { return (NULL); } collapse = __b2c__collapse; quoted = __b2c__option_quoted; utf8 = __b2c__option_utf8; __b2c__option_quoted = 0; backup = string = __b2c__strdup (str);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9929 "bacon.bac"
__b2c__assign = (char*)"if ((unsigned char) string[0] == 0xEF && (unsigned char) string[1] == 0xBB && (unsigned char) string[2] == 0xBF) { string += 3; __b2c__option_utf8 = 1; preserve = 1; } for (x = 0; string[x]; x++) { if (string[x] == 10 && string[x + 1] == 10) x++; else if (string[x] == 10) string[x] = 32; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9930 "bacon.bac"
__b2c__assign = (char*)"__b2c__collapse = 1; start = __b2c__delim_engine (2, &amount, string, \" \", 0); concat = (char *) calloc (x + amount + 1, sizeof (char)); for (x = 0; x < amount; x++) { start = __b2c__delim_engine_cache (1, &length, string, \" \", x+1); memmove (concat + ctotal, string + start, length); ctotal += length;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9931 "bacon.bac"
__b2c__assign = (char*)"if (x < amount - 1) { memset (concat + ctotal, 32, 1); ctotal += 1; } } __b2c__STRFREE(backup); backup = wrap = (char *) calloc (ctotal*2 + 1, sizeof (char)); while (read_pos < ctotal) { if (*(concat + read_pos) == 32) { if (write_pos == 0) { read_pos++; continue; } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9932 "bacon.bac"
__b2c__assign = (char*)"{ last_write_pos = wtotal; last_read_pos = read_pos; found = 1; } } memmove (wrap + wtotal, concat + read_pos, 1); write_pos++; wtotal++; if (*(concat + read_pos) == 10) { write_pos = 0; line_start = wtotal; } else if ((__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"ALIGN$\", wrap + line_start, write_pos) : write_pos) >= width)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9933 "bacon.bac"
__b2c__assign = (char*)"{ if (found) { memset (wrap + last_write_pos, 10, 1); wtotal = last_write_pos + 1; read_pos = last_read_pos; if (*(concat + read_pos + 1) == 10) { read_pos++; } } else { memset (wrap + wtotal, 10, 1); wtotal += 1; } found = 0; write_pos = 0; line_start = wtotal; } read_pos++; } __b2c__collapse = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9934 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine (2, &amount, wrap, \"\\n\", 0); line_start = 0; idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (unsigned char*)__b2c_str_realloc((char*)buf[idx], amount * indent + amount * width * 4 + 3 + 1); if(preserve) { buf[idx][0] = 0xEF; buf[idx][1] = 0xBB; buf[idx][2] = 0xBF;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9935 "bacon.bac"
__b2c__assign = (char*)"line_start += 3; } line = (char *) calloc (width * 4, sizeof (char)); for (x = 1; x <= amount; x++) { __b2c__collapse = 0; paragraph_end = 0; start = __b2c__delim_engine (1, &length, wrap, \"\\n\", 1); if(length && (*(wrap + start + length + 1) == 10 || x == amount )) { paragraph_end = 1; } characters = (__b2c__option_utf8 ? __b2c__ucs2_clen (l, k, \"ALIGN$\", wrap + start, length) : length);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9936 "bacon.bac"
__b2c__assign = (char*)"switch (mode) { case 0: memset (buf[idx] + line_start, 32, indent); line_start += indent; memmove (buf[idx] + line_start, wrap + start, length); line_start += length; memset (buf[idx] + line_start, 32, width - characters); line_start += (width - characters); if (x < amount) { memset (buf[idx] + line_start, '\\n', 1); line_start++; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9937 "bacon.bac"
__b2c__assign = (char*)"case 1: memset (buf[idx] + line_start, 32, indent); line_start += indent; memset (buf[idx] + line_start, 32, width - characters); line_start += (width - characters); memmove (buf[idx] + line_start, wrap + start, length); line_start += length; if (x < amount) { memset (buf[idx] + line_start, '\\n', 1); line_start++; } break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9938 "bacon.bac"
__b2c__assign = (char*)"case 2: tab = (width - characters) / 2; memset (buf[idx] + line_start, 32, indent + tab); line_start += (indent + tab); memmove (buf[idx] + line_start, wrap + start, length); line_start += length; memset (buf[idx] + line_start, 32, tab + (width - characters) % 2); line_start += (tab + (width - characters) % 2); if (x < amount)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9939 "bacon.bac"
__b2c__assign = (char*)"{ memset (buf[idx] + line_start, '\\n', 1); line_start++; } break; case 3: memmove (line, wrap + start, length); line[length] = '\\0'; pos = __b2c__delim_engine (2, &total, line, \" \", 0); left = width - characters; spaces = total - 1; memset (buf[idx] + line_start, 32, indent); line_start += indent; for (y = 1; y <= total; y++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9940 "bacon.bac"
__b2c__assign = (char*)"{ pos = __b2c__delim_engine_cache (1, &lw, line, \" \", y); memmove (buf[idx] + line_start, line + pos, lw); line_start += lw; if(y<total) { memset (buf[idx] + line_start, 32, 1); line_start++; if (left && total > 1 && !paragraph_end && y > (spaces/2)-(left/2)) { tab = (left < spaces ? 1 : left / spaces); memset (buf[idx] + line_start, 32, tab); left -= tab;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9941 "bacon.bac"
__b2c__assign = (char*)"spaces--; line_start += tab; } } } if (x < amount) { memset (buf[idx] + line_start, '\\n', 1); line_start++; } break; } wrap += (start + length + 1); } free(backup); free (concat); free (line); __b2c__option_quoted = quoted; __b2c__collapse = collapse; __b2c__option_utf8 = utf8; __b2c__SETLEN (buf[idx], line_start); buf[idx][line_start] = '\\0'; return (char *) (buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9942 "bacon.bac"
}
#line 9944 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EDITBOM\\$\\(|HASBOM\\(") ){
#line 9945 "bacon.bac"
__b2c__assign = (char*)"int __b2c__hasbom(char *string) { if (string == NULL || __b2c__len(string) < 3) { return (0); } if ((unsigned char) string[0] == 0xEF && (unsigned char) string[1] == 0xBB && (unsigned char) string[2] == 0xBF) { return(1); } return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9946 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__editbom(char *string, int edit) { static unsigned char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int slen; if (string == NULL) { return(NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } slen = __b2c__len(string);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9947 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (unsigned char*)__b2c_str_realloc((char*)buf[idx], 3+slen+1); if(edit) { if ((unsigned char)string[0] == 0xEF && (unsigned char)string[1] == 0xBB && (unsigned char)string[2] == 0xBF) { return (string); } buf[idx][0] = 0xEF; buf[idx][1] = 0xBB;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9948 "bacon.bac"
__b2c__assign = (char*)"buf[idx][2] = 0xBF; memcpy(buf[idx]+3, string, slen); __b2c__SETLEN(buf[idx], slen+3); buf[idx][slen+3] = '\\0'; } else { if ((unsigned char)string[0] != 0xEF || (unsigned char)string[1] != 0xBB || (unsigned char)string[2] != 0xBF) { return(string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9949 "bacon.bac"
__b2c__assign = (char*)"memcpy(buf[idx], string+3, slen-3); __b2c__SETLEN(buf[idx], slen-3); buf[idx][slen-3] = '\\0'; } return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9950 "bacon.bac"
}
#line 9952 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "PROPER\\$\\(") ){
#line 9953 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__proper(int l, char *k, char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *local; long start, total = 0, x, y, dlen, blen; long amount = 0; long length = 0; wchar_t wcs[8] = { 0 }; if (string == NULL) { return (string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9954 "bacon.bac"
__b2c__assign = (char*)"if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); start = __b2c__delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string)+1); if(__b2c__option_utf8)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9955 "bacon.bac"
__b2c__assign = (char*)"{ local = setlocale (LC_ALL, \"\"); for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1); blen = __b2c__blen (l, k, \"PROPER$\", string + start, 1, 0); if (mbtowc (wcs, string + start, blen) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9956 "bacon.bac"
__b2c__assign = (char*)"*wcs = towupper (*wcs); if (wctomb(buf[idx] + total, *wcs) == (int) -1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } for (y = blen; y < length; y += blen) { blen = __b2c__blen (l, k, \"PROPER$\", string + start + y, 1, 0); if (mbtowc (wcs, string + start + y, blen) == (int) - 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9957 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } if(__b2c__option_proper == 0) { *wcs = towlower (*wcs); } if (wctomb(buf[idx] + total + y, *wcs) == (int) - 1) { ERROR = 38; RUNTIMEFERR (\"PROPER$\", ERROR, k, l); return(NULL); } } total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9958 "bacon.bac"
__b2c__assign = (char*)"total += dlen; } string += (start + length + dlen); } setlocale (LC_ALL, local); } else { for (x = 0; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1); *(buf[idx] + total) = toupper(*(string+start)); for (y = 1; y < length; y ++) { *(buf[idx]+total+y) = (__b2c__option_proper == 0 ? tolower(*(string+start+y)) : *(string+start+y)); } "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9959 "bacon.bac"
__b2c__assign = (char*)"total += length; if (x < amount-1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } string += (start + length + dlen); } } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9960 "bacon.bac"
}
#line 9962 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ROTATE\\$\\(") ){
#line 9963 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__rotate (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x, dlen; long amount = 0, length = 0; char *next; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9964 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } dlen = __b2c__len (delim); start = __b2c__delim_engine (2, &amount, string, delim, 0); if (amount <= 1) { return (string); } if (abs (pos) >= amount) { pos = pos % amount; } if (pos == 0) { return (string); } if (pos < 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9965 "bacon.bac"
__b2c__assign = (char*)"{ pos = amount + pos; } next = string; buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); start = __b2c__delim_engine (1, &length, string, delim, amount-pos+1); string += start; for (x = amount - pos; x < amount; x++) { start = __b2c__delim_engine (1, &length, string, delim, 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9966 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + total, string + start, length); total += length; memmove(buf[idx] + total, delim, dlen); total += dlen; string += (start + length + dlen); } for (x = 0; x < amount - pos; x++) { start = __b2c__delim_engine (1, &length, next, delim, 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9967 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx] + total, next + start, length); total += length; if (x < amount - pos - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; } next += (start + length + dlen); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9968 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN(buf[idx], total);buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9969 "bacon.bac"
}
#line 9971 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "LAST\\$\\(") ){
#line 9972 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__last (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, slen; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9973 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } slen = __b2c__len (string); buf[idx] = (char*)__b2c_str_realloc(buf[idx], slen + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9974 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine_cache(1, &length, string, delim, pos+1); memmove(buf[idx], string + start, slen-start); __b2c__SETLEN(buf[idx], slen-start); buf[idx][slen-start] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9975 "bacon.bac"
}
#line 9977 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FIRST\\$\\(") ){
#line 9978 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__first (char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long dlen, end; long amount = 0; long length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9979 "bacon.bac"
__b2c__assign = (char*)"idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } end = __b2c__delim_engine (2, &amount, string, delim, 0); if (pos <= 0) { return (string); } if (amount < 1 || pos >= amount) { return (NULL); } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len(string)+1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9980 "bacon.bac"
__b2c__assign = (char*)"end = __b2c__delim_engine_cache(1, &length, string, delim, amount-pos+1); dlen = __b2c__len (delim); memmove(buf[idx], string, end-dlen); __b2c__SETLEN(buf[idx], end-dlen); buf[idx][end-dlen] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9981 "bacon.bac"
}
#line 9983 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "MATCH\\(") ){
#line 9984 "bacon.bac"
__b2c__assign = (char*)"int __b2c__match(char *string1, char *string2, long count, char *delim) { long dlen, start1, start2, amount1, amount2, length1, length2, tmplen; int x, found = 1, wildcard = 0, after = 0; if (string1 == NULL && string2 == NULL) { return (1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9985 "bacon.bac"
__b2c__assign = (char*)"if (count == 0) { return (1); } if (delim == NULL) { delim = __b2c__option_delim; } start1 = __b2c__delim_engine (2, &amount1, string1, delim, 0); if (count > amount1 || amount1 == 0) { return (0); } if(count == -1) { count = amount1; } dlen = __b2c__len (delim);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9986 "bacon.bac"
__b2c__assign = (char*)"for (x = 0; x < count; x++) { start1 = __b2c__delim_engine (1, &length1, string1, delim, 1); start2 = __b2c__delim_engine (1, &length2, string2, delim, 1); if (length1 == 0) { found = wildcard; break; } if (length2 == 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9987 "bacon.bac"
__b2c__assign = (char*)"{ found = wildcard; break; } if (strncmp (string2, \"?\", 1)) { if (!strncmp (string2, \"*\", 1)) { wildcard = 1; __b2c__delim_engine (2, &amount2, string2+1, delim, 0); if(amount2) { after = 1; string2+=1+dlen; } else { after = 0; found = wildcard; break; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9988 "bacon.bac"
__b2c__assign = (char*)"else { if (!strncmp (string2, \"\\\\?\", 2) || !strncmp (string2, \"\\\\*\", 2)) { string2++; length2--; } } __b2c__delim_engine (1, &tmplen, string2, delim, 1); if(length1 != tmplen || memcmp (string1, string2, tmplen)) { if (wildcard == 0) { found = 0; break; } else { string2 = string2-1-dlen; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9989 "bacon.bac"
__b2c__assign = (char*)"else { wildcard = 0; after = 0; } if(wildcard == 0) { string2 += (start2 + length1 + dlen); } } else { string2 += (start2 + length2 + dlen); } string1 += (start1 + length1 + dlen); } if(after) { found = 0; } return (found); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9990 "bacon.bac"
}
#line 9992 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EXPLODE\\$\\(") ){
#line 9993 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__explode (int l, char *k, char *string, int pos, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long x, dlen, len, blen, ctr=0, where = 0, escaped = 0, in_string = 0; if (string == NULL || pos <= 0 || pos >= (len = __b2c__len (string)) ) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9994 "bacon.bac"
__b2c__assign = (char*)"dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } blen = pos; buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + (len - 1) * dlen + 1); for (x = 0; x < len; x += blen) { if (__b2c__option_utf8) { blen = __b2c__blen(l, k, \"EXPLODE$\", string + x, pos, 0); } if(*(string+x) == __b2c__option_esc) { escaped = 1 - escaped; } if(*(string+x) == 34)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9995 "bacon.bac"
__b2c__assign = (char*)"{ if(!escaped && __b2c__option_quoted) { in_string = 1 - in_string; } escaped = 0; } else { escaped = 0; } memmove(buf[idx] + where, string + x, blen); where+=blen; if (x < (len - blen) && !in_string) { memmove(buf[idx] + where, delim, dlen); where+=dlen; ctr+=dlen; } } __b2c__SETLEN(buf[idx], len+ctr); buf[idx][len+ctr] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 9996 "bacon.bac"
}
#line 9998 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "MERGE\\$\\(") ){
#line 9999 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__merge(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, total = 0, x; long amount = 0; long length = 0; if (string == NULL) { return (string); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10000 "bacon.bac"
__b2c__assign = (char*)"if (delim == NULL) { delim = __b2c__option_delim; } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &amount, string, delim, 0); buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); for(x = 1; x <= amount; x++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10001 "bacon.bac"
__b2c__assign = (char*)"{ start = __b2c__delim_engine_cache(1, &length, string, delim, x); memmove(buf[idx] + total, string + start, length); total += length; } __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10002 "bacon.bac"
}
#line 10004 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INBETWEEN\\$\\(|OUTBETWEEN\\$\\(") ){
#line 10005 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__inbetween(int flag, char *haystack, char *lm, char *rm, int greedy) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *l, *pos; int collapse; long len, start, end=0, in, w1, w2; long length = 0;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10006 "bacon.bac"
__b2c__assign = (char*)"if (haystack == NULL || lm == NULL || rm == NULL) { return (NULL); } collapse = __b2c__collapse; __b2c__collapse = 0; idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } start = __b2c__delim_engine (2, &length, haystack, lm, 2);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10007 "bacon.bac"
__b2c__assign = (char*)"if (start == 0) { __b2c__collapse = collapse; return (NULL); } if (greedy == 0) { in = __b2c__delim_engine (2, &length, haystack+start+end, rm, 2); if (in == 0) { __b2c__collapse = collapse; return (NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10008 "bacon.bac"
__b2c__assign = (char*)"l = haystack+start-__b2c__len(lm); pos = haystack+start+in-__b2c__len(rm); } else if (greedy == 1) { while (1) { in = __b2c__delim_engine (2, &length, haystack+start+end, rm, 2); if(in) { end += in; } else { break; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10009 "bacon.bac"
__b2c__assign = (char*)"if (end == 0) { __b2c__collapse = collapse; return (NULL); } l = haystack+start-__b2c__len(lm); pos = haystack+start+end-__b2c__len(rm); } else { w1 = start; w2 = start;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10010 "bacon.bac"
__b2c__assign = (char*)"while (1) { end = __b2c__delim_engine (2, &length, haystack + w1, rm, 2); if (end == 0) { __b2c__collapse = collapse; return (NULL); } in = __b2c__delim_engine (2, &length, haystack + w2, lm, 2); if (in && ((w2 + in) < (w1 + end)))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10011 "bacon.bac"
__b2c__assign = (char*)"{ w1 = w1 + end; w2 = w2 + in; } else { break; } } l = haystack + start - __b2c__len (lm); pos = haystack + w1 + end - __b2c__len (rm); } if (flag) { pos += strlen (rm); len = strlen (pos); buf[idx] = (char*)__b2c_str_realloc(buf[idx], (l - haystack) + len + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10012 "bacon.bac"
__b2c__assign = (char*)"memmove(buf[idx], haystack, l - haystack); memmove(buf[idx] + (l - haystack), pos, len); __b2c__SETLEN(buf[idx], (l - haystack) + len); buf[idx][(l - haystack) + len] = '\\0'; } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10013 "bacon.bac"
__b2c__assign = (char*)"{ l += strlen (lm); buf[idx] = (char*)__b2c_str_realloc(buf[idx], pos - l + 1); memmove(buf[idx], l, pos - l); __b2c__SETLEN(buf[idx], pos - l); buf[idx][pos - l] = '\\0'; } __b2c__collapse = collapse; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10014 "bacon.bac"
}
#line 10016 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "UCASE\\$\\(") ){
#line 10017 "bacon.bac"
__b2c__assign = (char*)"char * __b2c__ucase(int l, char *k, char *src) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, i; size_t mbslen; wchar_t *wcs, *wp; char *local; if (src == NULL) { return (NULL); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } len = __b2c__len (src);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10018 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); if(__b2c__option_utf8) { local = setlocale (LC_ALL, \"\"); if ((mbslen = mbstowcs (NULL, src, 0)) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } wcs = (wchar_t*)calloc (mbslen + 1, sizeof (wchar_t)); if (mbstowcs (wcs, src, mbslen + 1) == (size_t) - 1)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10019 "bacon.bac"
__b2c__assign = (char*)"{ ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } for (wp = wcs; *wp != 0; wp++) { *wp = towupper (*wp); } if(wcstombs(buf[idx], wcs, len) == (size_t) - 1) { ERROR = 38; RUNTIMEFERR (\"UCASE$\", ERROR, k, l); return(NULL); } free (wcs);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10020 "bacon.bac"
__b2c__assign = (char*)"setlocale(LC_ALL, local); } else { for (i = 0; i < len; i++) { buf[idx][i] = toupper (src[i]); } } __b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10021 "bacon.bac"
}
#line 10023 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "WAIT\\(") ){
#line 10024 "bacon.bac"
__b2c__assign = (char*)"long __b2c__netpeek(int l, char *k, uintptr_t fd, int usec){fd_set rfds; struct timeval tv; int desc = 0; long retval = 0; struct termios oldt = { 0 }, newt = { 0 }; if(fd == STDIN_FILENO){tcgetattr(STDIN_FILENO, &oldt);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10025 "bacon.bac"
__b2c__assign = (char*)"newt = oldt; newt.c_lflag &= ~(ICANON | ECHO); newt.c_cc[VMIN]=1; newt.c_cc[VTIME]=0; tcsetattr(STDIN_FILENO, TCSANOW, &newt);} tv.tv_usec = (usec%1000)*1000; tv.tv_sec = usec/1000; FD_ZERO(&rfds);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10026 "bacon.bac"
__b2c__assign = (char*)"if(fd == STDIN_FILENO) { desc = fd; } else {"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10027 "bacon.bac"
if( g_OPTION_TLS ){
#line 10028 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "gnutls") ){
#line 10029 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__option_tls) { BIO_get_fd(((SSL*)fd)->gnutls_state, &desc); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10030 "bacon.bac"
} else {
#line 10031 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__option_tls) { desc = SSL_get_fd((SSL*)fd); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10032 "bacon.bac"
}
#line 10033 "bacon.bac"
}
#line 10034 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__option_tls) { desc = fd; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10035 "bacon.bac"
__b2c__assign = (char*)"FD_SET(desc, &rfds); retval = select(desc + 1, &rfds, NULL, NULL, &tv); if(retval == -1) { ERROR = 16; RUNTIMEFERR(\"WAIT\", ERROR, k, l); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10036 "bacon.bac"
__b2c__assign = (char*)"if(fd == STDIN_FILENO){ if(retval) if(read(fd, &retval, 1)==0) { retval=0; } tcsetattr(STDIN_FILENO, TCSANOW, &oldt);} return(retval); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10037 "bacon.bac"
}
#line 10039 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EXTRACT\\$\\(") ){
#line 10040 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__extract_core(int action, int l, char *k, char *src, char *needle, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; int reti = 0, len, pos = 0; char *tmp; regex_t regex; char __b2c__buf[100]; regmatch_t where[1];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10041 "bacon.bac"
__b2c__assign = (char*)"static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (src == NULL || needle == NULL) { return (src); } if (__b2c__len (src) == 0 || __b2c__len (needle) == 0) { return (src); } idx++; if (idx == __b2c_STRING_FUNC)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10042 "bacon.bac"
__b2c__assign = (char*)"{ idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], __b2c__len (src) + 1); if (flag > 0) { if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new(); } found = __b2c__hash_find_value_do(table_normal, needle);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10043 "bacon.bac"
__b2c__assign = (char*)"if(!found) { reti = regcomp(&regex, needle, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data(table_normal, (void *) &regex, sizeof(regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new(); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10044 "bacon.bac"
__b2c__assign = (char*)"found = __b2c__hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED|REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10045 "bacon.bac"
__b2c__assign = (char*)"if(reti) { ERROR = 27; regerror (reti, &regex, __b2c__buf, sizeof (__b2c__buf)); fprintf (stderr, \"%s\\n\", __b2c__buf); RUNTIMEFERR(\"EXTRACT$\", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, src, 1, where, 0)) == 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10046 "bacon.bac"
__b2c__assign = (char*)"{ memcpy (buf[idx] + pos, src, (size_t) where[0].rm_so); pos += where[0].rm_so; src += (long) where[0].rm_eo; } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } else { while ((tmp = strstr (src, needle)) != NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10047 "bacon.bac"
__b2c__assign = (char*)"{ memcpy (buf[idx] + pos, src, (size_t) (tmp - src)); pos += tmp - src; src = tmp + __b2c__len (needle); } len = strlen (src); memcpy (buf[idx] + pos, src, len); pos += len; } __b2c__SETLEN (buf[idx], pos); buf[idx][pos] = '\\0'; return (char *) (buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10048 "bacon.bac"
}
#line 10050 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "REGEX\\(") ){
#line 10051 "bacon.bac"
__b2c__assign = (char*)"long __b2c__regex_core (int action, int l, char *k, char *x, char *y) { regex_t reg; int reti = 0; char buf[100]; regmatch_t where[1]; static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10052 "bacon.bac"
__b2c__assign = (char*)"return(0); } if (x == NULL || y == NULL) { return (0); } if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new(); } found = __b2c__hash_find_value_do (table_normal, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &reg, sizeof (reg), y); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10053 "bacon.bac"
__b2c__assign = (char*)"else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new(); } found = __b2c__hash_find_value_do (table_icase, y); if (!found) { reti = regcomp (&reg, y, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &reg, sizeof (reg), y); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10054 "bacon.bac"
__b2c__assign = (char*)"else { reg = *(regex_t*)found; } } if(reti) { ERROR = 27; regerror (reti, &reg, buf, sizeof (buf)); fprintf(stderr, \"%s\\n\", buf); RUNTIMEFERR(\"REGEX\", ERROR, k, l); return (0); } reti = regexec (&reg, x, 1, where, 0); if (!reti) { REGLEN = where[0].rm_eo - where[0].rm_so;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10055 "bacon.bac"
__b2c__assign = (char*)"return (where[0].rm_so + 1); } else { REGLEN = 0; return (0); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10056 "bacon.bac"
}
#line 10058 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "REPLACE\\$\\(") ){
#line 10059 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__replace_core (int action, int l, char *k, char *haystack, char *needle, char *replace, int flag) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; char *tmp; long replen, hstlen, ndllen, length = 0; regex_t regex; int i, reti = 0; char buffer[100]; regmatch_t where[1];"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10060 "bacon.bac"
__b2c__assign = (char*)"static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (haystack == NULL || needle == NULL) { return (haystack); } if (replace == NULL) { replace = __b2c_EMPTYSTRING; } ndllen = __b2c__len (needle); hstlen = __b2c__len (haystack); if (hstlen == 0 || ndllen == 0)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10061 "bacon.bac"
__b2c__assign = (char*)"{ return (haystack); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } if (flag == 2) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], hstlen + 1); strncpy (buf[idx], haystack, hstlen); for (i = 0; i < hstlen; i++) { if ((tmp = strchr (needle, buf[idx][i])) != NULL) { buf[idx][i] = replace[tmp - needle]; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10062 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN (buf[idx], i); buf[idx][i] = '\\0'; return (char *) (buf[idx]); } buf[idx] = (char *) __b2c_str_realloc (buf[idx], sizeof (char)); buf[idx][0] = '\\0'; replen = __b2c__len (replace); if (flag == 1) { if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new (); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10063 "bacon.bac"
__b2c__assign = (char*)"found = __b2c__hash_find_value_do(table_normal, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } } else { if (table_icase == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10064 "bacon.bac"
__b2c__assign = (char*)"{ table_icase = __b2c__hash_new (); } found = __b2c__hash_find_value_do(table_icase, needle); if (!found) { reti = regcomp (&regex, needle, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &regex, sizeof (regex), needle); } } else { regex = *(regex_t*)found; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10065 "bacon.bac"
__b2c__assign = (char*)"if(reti) { ERROR = 27; regerror (reti, &regex, buffer, sizeof (buffer)); fprintf (stderr, \"%s\\n\", buffer); RUNTIMEFERR (\"REPLACE$\", ERROR, k, l); return (NULL); } while ((reti = regexec (&regex, haystack, 1, where, 0)) == 0) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + where[0].rm_so + replen + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10066 "bacon.bac"
__b2c__assign = (char*)"memcpy (buf[idx] + length, haystack, (size_t) where[0].rm_so); length += where[0].rm_so; memcpy (buf[idx] + length, replace, replen); length += replen; haystack += (long) where[0].rm_eo; }} else { while ((tmp = strstr (haystack, needle)) != NULL) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + tmp - haystack + replen + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10067 "bacon.bac"
__b2c__assign = (char*)"memcpy (buf[idx] + length, haystack, (size_t) (tmp - haystack)); length += tmp - haystack; memcpy (buf[idx] + length, replace, replen); length += replen; haystack = tmp + ndllen; }} hstlen = strlen (haystack); buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + hstlen + 1); memcpy (buf[idx] + length, haystack, hstlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10068 "bacon.bac"
__b2c__assign = (char*)"length += hstlen; __b2c__SETLEN (buf[idx], length); buf[idx][length] = '\\0'; return (char *) (buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10069 "bacon.bac"
}
#line 10071 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "WALK\\$\\(") ){
#line 10072 "bacon.bac"
__b2c__assign = (char*)"#ifndef PATH_MAX"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10073 "bacon.bac"
__b2c__assign = (char*)"#define PATH_MAX 4096"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10074 "bacon.bac"
__b2c__assign = (char*)"#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10075 "bacon.bac"
__b2c__assign = (char*)"static int __b2c__walk_filter_file(regex_t reg, char *file, int type, struct stat bf) { regmatch_t where[1]; if (regexec(&reg, file, 1, where, 0) == 0) { if (((type & 1) && S_ISREG(bf.st_mode)) || ((type & 2) && S_ISDIR(bf.st_mode)) || ((type & 4) && S_ISCHR(bf.st_mode)) || ((type & 8) && S_ISBLK(bf.st_mode)) ||"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10076 "bacon.bac"
__b2c__assign = (char*)" ((type & 16) && S_ISFIFO(bf.st_mode)) || ((type & 32) && S_ISLNK(bf.st_mode)) || ((type & 64) && S_ISSOCK(bf.st_mode))) { return(1); } } return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10077 "bacon.bac"
__b2c__assign = (char*)"static int __b2c__walk_each_file_recurse(regex_t reg, char **buf, char *dir, int type, char *delim) { FTS *fts; FTSENT *ent; struct stat bf; char *item[2]; int dlen, flen, total = 0, result = 0; item[0] = dir; item[1] = NULL; fts = fts_open(item, FTS_PHYSICAL | FTS_NOCHDIR | FTS_XDEV, NULL); if(fts == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10078 "bacon.bac"
__b2c__assign = (char*)"{ return(-1); } dlen = __b2c__len(delim); while(1) { ent = fts_read(fts); if(ent == NULL) { break; } if (lstat(ent->fts_path, &bf) < 0 && __b2c__trap) { result = -1; break; } if(__b2c__walk_filter_file(reg, ent->fts_path, type, bf))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10079 "bacon.bac"
__b2c__assign = (char*)"{ if(ent->fts_info != FTS_D) { flen = __b2c__len(ent->fts_path); *buf = (char*)__b2c_str_realloc(*buf, total+flen+dlen+1); memcpy(*buf+total, ent->fts_path, flen); memcpy(*buf+total+flen, delim, dlen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10080 "bacon.bac"
__b2c__assign = (char*)"total += flen + dlen; } } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total-dlen); (*buf)[total - dlen] = '\\0'; fts_close(fts); return (result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10081 "bacon.bac"
__b2c__assign = (char*)"static int __b2c__walk_each_file_dir (regex_t reg, char **buf, const char *dir, int type, char *delim) { DIR *here; struct dirent *item; struct stat bf; int dlen, flen, plen, total = 0, result = 0; char path[PATH_MAX] = { 0 }; here = opendir (dir); if (here == NULL) { return (-1); } dlen = __b2c__len(delim); plen = strlen(dir);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10082 "bacon.bac"
__b2c__assign = (char*)"if (plen >= PATH_MAX) { return (-1); } strncpy (path, dir, PATH_MAX - 1); plen++; if (plen >= PATH_MAX) { return (-1); } strncat (path, \"/\", PATH_MAX - plen - 1); while (1) { item = readdir (here); if (item == NULL) { break; } if (!strcmp (item->d_name, \".\") || !strcmp (item->d_name, \"..\")) { continue; } memset (path + plen, 0, 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10083 "bacon.bac"
__b2c__assign = (char*)"flen = strlen(item->d_name); if (plen + flen >= PATH_MAX) { return (-1); } strncat (path, item->d_name, PATH_MAX - plen - 1); flen += plen; if (lstat (path, &bf) < 0 && __b2c__trap) { result = -1; break; } if (__b2c__walk_filter_file (reg, path, type, bf)) { *buf = (char*)__b2c_str_realloc(*buf, total + flen + dlen + 1);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10084 "bacon.bac"
__b2c__assign = (char*)"memcpy(*buf+total, path, flen); memcpy(*buf+total+flen, delim, dlen); total += flen + dlen; } } if(total == 0) { dlen = 0; } __b2c__SETLEN(*buf, total - dlen); (*buf)[total - dlen] = '\\0'; closedir (here); return (result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10085 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__walk_core(int action, int l, char *k, char *dir, int type, char *exp, int recurse, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; regex_t reg; char buffer[100]; int reti = 0; static __b2c__htable *table_icase = NULL, *table_normal = NULL; void *found = NULL; if(action == 0) { __b2c__hash_clear_regfree(table_icase); free(table_icase); __b2c__hash_clear_regfree(table_normal); free(table_normal); return(NULL); } if (dir == NULL || exp == NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10086 "bacon.bac"
__b2c__assign = (char*)"{ return (NULL); } if (delim == NULL) { delim = __b2c__option_delim; } if(type < 1 || type > 127) { ERROR = 5; RUNTIMEFERR(\"WALK$\", ERROR, k, l); return (NULL); } if (__b2c__option_compare == 0) { if (table_normal == NULL) { table_normal = __b2c__hash_new (); } found = __b2c__hash_find_value_do (table_normal, exp);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10087 "bacon.bac"
__b2c__assign = (char*)"if (!found) { reti = regcomp (&reg, exp, REG_EXTENDED); if (reti == 0) { __b2c__hash_add_data (table_normal, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } else { if (table_icase == NULL) { table_icase = __b2c__hash_new (); } found = __b2c__hash_find_value_do (table_icase, exp); if (!found)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10088 "bacon.bac"
__b2c__assign = (char*)"{ reti = regcomp (&reg, exp, REG_EXTENDED | REG_ICASE); if (reti == 0) { __b2c__hash_add_data (table_icase, (void *) &reg, sizeof (reg), exp); } } else { reg = *(regex_t*)found; } } if(reti) { ERROR = 27; regerror (reti, &reg, buffer, sizeof (buffer)); fprintf(stderr, \"%s\\n\", buffer); RUNTIMEFERR(\"WALK$\", ERROR, k, l);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10089 "bacon.bac"
__b2c__assign = (char*)"return (NULL); } idx++; if (idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char *) __b2c_str_realloc (buf[idx], PATH_MAX * sizeof (char)); if (recurse) { if (__b2c__walk_each_file_recurse (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR(\"WALK$\", ERROR, k, l); return (NULL); } } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10090 "bacon.bac"
__b2c__assign = (char*)"{ if (__b2c__walk_each_file_dir (reg, &buf[idx], dir, type, delim) == -1) { ERROR = 24; RUNTIMEFERR (\"WALK$\", ERROR, k, l); return (NULL); } } return (char *) (buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10091 "bacon.bac"
}
#line 10093 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "EVAL\\(")  OR  g_OPTION_EVAL ){
#line 10094 "bacon.bac"
__b2c__assign = (char*)"#include <matheval.h>"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10095 "bacon.bac"
__b2c__assign = (char*)"double __b2c__eval(int l, char *k, char **vars, double *vals, int nr, char *expr) { void *f; double result; if (expr == NULL) return (0); f = evaluator_create(expr);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10096 "bacon.bac"
__b2c__assign = (char*)"if(f) { result = evaluator_evaluate(f, nr, vars, vals); } else { ERROR = 39; RUNTIMEFERR(\"EVAL\", ERROR, k, l); return(0); } evaluator_destroy(f); return(result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10097 "bacon.bac"
}
#line 10099 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "GETFILE[[:space:]]") ){
#line 10100 "bacon.bac"
__b2c__assign = (char*)"void __b2c__getfile(int l, char *k, char **result, DIR * from, int *type) { struct dirent *dir; *type = -1; dir = readdir (from); if (dir != NULL) { *result = __b2c__strdup (dir->d_name);\n#ifdef _DIRENT_HAVE_D_TYPE\nswitch (dir->d_type) { case DT_UNKNOWN: *type = 0; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10101 "bacon.bac"
__b2c__assign = (char*)"case DT_REG: *type = 1; break; case DT_DIR: *type = 2; break; case DT_FIFO: *type = 5; break; case DT_SOCK: *type = 7; break; case DT_CHR: *type = 3; break; case DT_BLK: *type = 4; break; case DT_LNK: *type = 6; break; default:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10102 "bacon.bac"
__b2c__assign = (char*)"ERROR = 24; RUNTIMEFERR(\"GETFILE\", ERROR, k, l); return; }\n#endif\n } else { *result = NULL; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10103 "bacon.bac"
}
#line 10105 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COPY[[:space:]]") ){
#line 10106 "bacon.bac"
__b2c__assign = (char*)"int __b2c__copy(const char *from, const char *to) { char buffer["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "]; FILE *in, *out; size_t size; in = fopen(from, \"r\"); out = fopen(to, \"w\"); if(in == NULL || out == NULL) { return(1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10107 "bacon.bac"
__b2c__assign = (char*)"while((size = fread(buffer, sizeof(char), "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ", in)) > 0) { if(fwrite(buffer, sizeof(char), size, out) != size) { return(1); } } fclose(in); fclose(out); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10108 "bacon.bac"
}
#line 10110 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ASC\\(|INPUT[[:space:]]") ){
#line 10111 "bacon.bac"
__b2c__assign = (char*)"unsigned char __b2c__asc(char *data) { if(data == NULL) { return(0); } return((unsigned char)*data); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10112 "bacon.bac"
}
#line 10114 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "INPUT[[:space:]]") ){
#line 10115 "bacon.bac"
__b2c__assign = (char*)"void __b2c__input(int l, char *k, char **result, char *sep) { size_t size; ssize_t total; size = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "; *result = (char*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ", sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10116 "bacon.bac"
__b2c__assign = (char*)"total = getdelim(&(*result), &size, ASC(sep), stdin); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == ASC(sep)) { (*result)[total-1] = '\\0'; } else { ERROR = 2; RUNTIMEFERR(\"INPUT\", ERROR, k, l); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10117 "bacon.bac"
}
#line 10119 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "READLN[[:space:]]") ){
#line 10120 "bacon.bac"
__b2c__assign = (char*)"void __b2c__readln(char **result, FILE *from) { size_t size; ssize_t total; size = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "; *result = (char*)calloc("; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ", sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10121 "bacon.bac"
__b2c__assign = (char*)"total = getline(&(*result), &size, from); if(total == 0) { free(*result); *result = NULL; } else if(total > 0 && (*result)[total-1] == '\\n') { (*result)[total-1] = '\\0'; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10122 "bacon.bac"
}
#line 10124 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "RETURN[[:space:]]") ){
#line 10125 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__return (char *data) { static char *rbuffer["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_RBUFFERS), g_FUNCTIONS);
__b2c__assign = (char*) "] = { NULL }; static int rbuffer_ptr = 0; size_t size; if(data == NULL) { return(NULL); } size = __b2c__len (data); if(size == 0) { return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10126 "bacon.bac"
__b2c__assign = (char*)"rbuffer_ptr++; if(rbuffer_ptr >= "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_RBUFFERS), g_FUNCTIONS);
__b2c__assign = (char*) ") { rbuffer_ptr = 0; } rbuffer[rbuffer_ptr] = (char *) __b2c_str_realloc (rbuffer[rbuffer_ptr], size); memcpy (rbuffer[rbuffer_ptr], data, size);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10127 "bacon.bac"
__b2c__assign = (char*)"__b2c__SETLEN (rbuffer[rbuffer_ptr], size); rbuffer[rbuffer_ptr][size] = '\\0'; return (rbuffer[rbuffer_ptr]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10128 "bacon.bac"
}
#line 10130 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "JOIN[[:space:]]") ){
#line 10131 "bacon.bac"
__b2c__assign = (char*)"void __b2c__join (char **result, char **array, int base, int size, char *by) { long dlen, i, slen, total; dlen = __b2c__len (by); total = __b2c__len (array[0 + base]);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10132 "bacon.bac"
__b2c__assign = (char*)"*result = (char*)calloc(total, sizeof(char)+1); memmove(*result, array[0 + base], total); for (i = 1; i < size; i++) { if (array[i + base] != NULL) { slen = __b2c__len (array[i + base]);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10133 "bacon.bac"
__b2c__assign = (char*)"*result = (char *) realloc (*result, (total + dlen + slen + 1) * sizeof (char)); memmove (*result + total, by, dlen); total += dlen; memmove (*result + total, array[i + base], slen);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10134 "bacon.bac"
__b2c__assign = (char*)"total += slen; } } (*result)[total] = '\\0'; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10135 "bacon.bac"
}
#line 10137 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "NETWORK[[:space:]]") ){
#line 10138 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "gnutls") ){
#line 10139 "bacon.bac"
__b2c__assign = (char*)"#define SSL_set_tlsext_host_name(connection, name) gnutls_server_name_set(((SSL*)connection)->gnutls_state, GNUTLS_NAME_DNS, name, LEN(name))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10140 "bacon.bac"
__b2c__assign = (char*)"#undef VERIFY"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10141 "bacon.bac"
__b2c__assign = (char*)"long VERIFY(uintptr_t ssl, char* pem) { int result = 0; gnutls_certificate_credentials_t cred = 0; if((SSL*)ssl == NULL) { return(-1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10142 "bacon.bac"
__b2c__assign = (char*)"gnutls_certificate_allocate_credentials(&cred); gnutls_certificate_set_x509_trust_file(cred, pem, GNUTLS_X509_FMT_PEM);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10143 "bacon.bac"
__b2c__assign = (char*)"if(gnutls_credentials_set(((SSL*)ssl)->gnutls_state, GNUTLS_CRD_CERTIFICATE, cred) != 0) { return(-1); } if(gnutls_certificate_verify_peers2(((SSL*)ssl)->gnutls_state, &result) !=0) { return(-1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10144 "bacon.bac"
__b2c__assign = (char*)"gnutls_certificate_free_credentials(cred); return(result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10145 "bacon.bac"
__b2c__assign = (char*)"SSL_METHOD *TLS_client_method(void) { SSL_METHOD *tls; tls = calloc(1, sizeof(SSL_METHOD)); strncpy(tls->priority_string, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) g_PRIORITY__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) ", 256); tls->connend = 2; return(tls); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10146 "bacon.bac"
}
#line 10147 "bacon.bac"
__b2c__assign = (char*)"int __b2c__network_init(uintptr_t *handle, char *site, char *org, int sock_type, int sock_opt, char *nw_type, int multicast_ttl, int sctp_streams, int capeer, char *cacerts, char *priv, char *cert) { struct sockaddr_in *addr, *from; struct hostent *he;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10148 "bacon.bac"
__b2c__assign = (char*)"long amount = 0; long length = 0; char data_client["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "]; char *host, *local, *port, *from_client; struct timeval tval; int sock, i, yes = 1; long start; char ttl = 1; __b2c__delim_engine (2, &amount, site, \",\", 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10149 "bacon.bac"
__b2c__assign = (char*)"addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++) { start = __b2c__delim_engine (1, &length, site, \",\", i+1); if(length >= "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ") { return(5); } memset(data_client, 0, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ");"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10150 "bacon.bac"
__b2c__assign = (char*)"strncpy(data_client, site+start, length); if(strstr(data_client, \":\") == NULL) { return(10); } host = strtok(data_client, \":\"); port = strtok(NULL, \":\"); he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10151 "bacon.bac"
__b2c__assign = (char*)"addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); addr[i].sin_addr = *((struct in_addr *) he->h_addr); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10152 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "SCTP") == 0 ){
#line 10153 "bacon.bac"
__b2c__assign = (char*)"sock = socket(AF_INET, sock_type, IPPROTO_SCTP);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10154 "bacon.bac"
} else {
#line 10155 "bacon.bac"
__b2c__assign = (char*)"sock = socket(AF_INET, sock_type, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10156 "bacon.bac"
}
#line 10157 "bacon.bac"
__b2c__assign = (char*)"if(sock == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof (struct timeval));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10158 "bacon.bac"
__b2c__assign = (char*)"setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)); if(org) { __b2c__delim_engine (2, &amount, org, \",\", 0); from = (struct sockaddr_in*)calloc(amount, sizeof(*from));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10159 "bacon.bac"
__b2c__assign = (char*)"for(i = 0; i < amount; i++) { start = __b2c__delim_engine (1, &length, site, \",\", i+1); from_client = __b2c__strndup(org+start, length); if(strstr(from_client, \":\"))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10160 "bacon.bac"
__b2c__assign = (char*)"{ local = strtok(from_client, \":\"); port = strtok(NULL, \":\"); } else { local = from_client; port = NULL; } he = gethostbyname(local); if(he == NULL || he->h_addr == NULL) { return(11); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10161 "bacon.bac"
__b2c__assign = (char*)"from[i].sin_family = AF_INET; if(port) { from[i].sin_port = htons((long)atol(port)); } from[i].sin_addr = *((struct in_addr *)he->h_addr); free(from_client); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10162 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "SCTP") == 0 ){
#line 10163 "bacon.bac"
__b2c__assign = (char*)"if(sctp_bindx(sock, (struct sockaddr *)from, 1, SCTP_BINDX_ADD_ADDR) < 0) { return(17); } free(from); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10164 "bacon.bac"
__b2c__assign = (char*)"struct sctp_initmsg initmsg; memset (&initmsg, 0, sizeof (initmsg)); initmsg.sinit_max_attempts = 3; initmsg.sinit_num_ostreams = sctp_streams; initmsg.sinit_max_instreams = sctp_streams;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10165 "bacon.bac"
__b2c__assign = (char*)"setsockopt(sock, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof (initmsg));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) "#ifdef SCTP_SOCKOPT_CONNECTX_OLD"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) "if(sctp_connectx(sock, (struct sockaddr *) addr, 1, NULL) < 0) { return(13); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10166 "bacon.bac"
__b2c__assign = (char*)"#else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) "if(sctp_connectx(sock, (struct sockaddr *) addr, 1) < 0) { return(13); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
__b2c__assign = (char*) "#endif"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10167 "bacon.bac"
} else {
#line 10168 "bacon.bac"
__b2c__assign = (char*)"if(bind(sock, (struct sockaddr *)from, sizeof(struct sockaddr)) < 0) { return(17); } free(from); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10169 "bacon.bac"
__b2c__assign = (char*)"if (!strcmp(nw_type, \"BROADCAST\")) { setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(int)); } if(!strcmp(nw_type, \"MULTICAST\")) { setsockopt(sock, IPPROTO_IP, IP_MULTICAST_LOOP, &yes, sizeof(int));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10170 "bacon.bac"
__b2c__assign = (char*)"ttl = multicast_ttl; setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(unsigned char)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10171 "bacon.bac"
__b2c__assign = (char*)"if(connect(sock, (struct sockaddr*)addr, sizeof(struct sockaddr)) < 0) { return(13); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10172 "bacon.bac"
}
#line 10173 "bacon.bac"
__b2c__assign = (char*)"*handle = sock;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10174 "bacon.bac"
if( g_OPTION_TLS ){
#line 10175 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__option_tls) { int ret; SSL_CTX *ssl_context = NULL; SSL *ssl_sock; SSL_library_init(); ssl_context = SSL_CTX_new(TLS_client_method()); SSL_CTX_set_verify(ssl_context, capeer, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10176 "bacon.bac"
if( NOT(TALLY(g_LIB_TLS__b2c__string_var, "gnutls")) ){
__b2c__assign = (char*)"SSL_CTX_load_verify_locations(ssl_context, cacerts, NULL);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 10177 "bacon.bac"
if( NOT(TALLY(g_LIB_TLS__b2c__string_var, "gnutls"))  AND  NOT(TALLY(g_LIB_TLS__b2c__string_var, "wolfssl")) ){
__b2c__assign = (char*)"SSL_CTX_set_options(ssl_context, SSL_OP_LEGACY_SERVER_CONNECT);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 10178 "bacon.bac"
__b2c__assign = (char*)"if(priv != NULL && SSL_CTX_use_PrivateKey_file(ssl_context, priv, SSL_FILETYPE_PEM) <= 0) { return(41); } if(cert != NULL && SSL_CTX_use_certificate_file(ssl_context, cert, SSL_FILETYPE_PEM) <= 0) { return(41); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10179 "bacon.bac"
__b2c__assign = (char*)"SSL_CTX_set_options(ssl_context, SSL_OP_ALL); ssl_sock = SSL_new(ssl_context); SSL_set_tlsext_host_name(ssl_sock, host); if(SSL_set_fd(ssl_sock, *handle) == 0) { return(40); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10180 "bacon.bac"
__b2c__assign = (char*)"if((ret = SSL_connect(ssl_sock)) <= 0) { fprintf(stderr, \"SSL CONNECT error: %s\\n\", ERR_error_string(SSL_get_error(ssl_sock, ret), NULL)); return(40); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10181 "bacon.bac"
__b2c__assign = (char*)"*handle = (uintptr_t)ssl_sock; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10182 "bacon.bac"
}
#line 10183 "bacon.bac"
__b2c__assign = (char*)"free(addr); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10184 "bacon.bac"
}
#line 10186 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SERVER[[:space:]]") ){
#line 10187 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "gnutls") ){
__b2c__assign = (char*)"SSL_METHOD *TLS_server_method(void) { SSL_METHOD *tls; tls = calloc(1, sizeof(SSL_METHOD)); strncpy(tls->priority_string, \"NONE:PFS:+VERS-ALL:+VERS-DTLS-ALL:+CIPHER-ALL:+CIPHER-GOST-ALL:+MAC-ALL:+MAC-GOST-ALL\", 256); tls->connend = 1; return(tls); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 10188 "bacon.bac"
__b2c__assign = (char*)"int __b2c__server_init(uintptr_t *handle, char *site, int sock_type, int sock_opt, int sctp_streams) { struct sockaddr_in *addr; struct hostent *he; long amount = 0; long length = 0; char *host, *port;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10189 "bacon.bac"
__b2c__assign = (char*)"char data_client["; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "]; struct timeval tval; int fd, i, yes = 1; long start; __b2c__delim_engine (2, &amount, site, \",\", 0); addr = (struct sockaddr_in*)calloc(amount, sizeof(*addr)); for(i = 0; i < amount; i++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10190 "bacon.bac"
__b2c__assign = (char*)"{ start = __b2c__delim_engine(1, &length, site, \",\", i + 1); if (length >= "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) ") { return (5); } memset (data_client, 0, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_BUFFER_SIZE), g_FUNCTIONS);
__b2c__assign = (char*) "); strncpy(data_client, site + start, length);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10191 "bacon.bac"
__b2c__assign = (char*)"if(strstr(data_client, \":\") == NULL) { return(10); } host = strtok(data_client, \":\"); port = strtok(NULL, \":\"); if(strstr(site, \"INADDR_ANY:\") || strstr(site, \"*:\")) { addr[i].sin_addr.s_addr = htonl(INADDR_ANY); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10192 "bacon.bac"
__b2c__assign = (char*)"else { he = gethostbyname(host); if(he == NULL || he->h_addr == NULL) { return(11); } addr[i].sin_addr = *((struct in_addr*)he->h_addr); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10193 "bacon.bac"
__b2c__assign = (char*)"addr[i].sin_family = AF_INET; addr[i].sin_port = htons((long)atol(port)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10194 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "SCTP") == 0 ){
#line 10195 "bacon.bac"
__b2c__assign = (char*)"fd = socket(AF_INET, sock_type, IPPROTO_SCTP);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10196 "bacon.bac"
__b2c__assign = (char*)"struct sctp_initmsg initmsg; memset(&initmsg, 0, sizeof(initmsg)); initmsg.sinit_max_attempts = 3;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10197 "bacon.bac"
__b2c__assign = (char*)"initmsg.sinit_num_ostreams = sctp_streams; initmsg.sinit_max_instreams = sctp_streams;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10198 "bacon.bac"
__b2c__assign = (char*)"setsockopt(fd, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(initmsg));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10199 "bacon.bac"
} else {
#line 10200 "bacon.bac"
__b2c__assign = (char*)"fd = socket(AF_INET, sock_type, 0);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10201 "bacon.bac"
}
#line 10202 "bacon.bac"
__b2c__assign = (char*)"if(fd == -1) { return(12); } tval.tv_sec = sock_opt; tval.tv_usec = 0; setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tval, sizeof(struct timeval));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10203 "bacon.bac"
__b2c__assign = (char*)"setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10204 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "SCTP") == 0 ){
#line 10205 "bacon.bac"
__b2c__assign = (char*)"if(sctp_bindx(fd, (struct sockaddr *)addr, 1, SCTP_BINDX_ADD_ADDR) < 0) { return(17); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10206 "bacon.bac"
} else {
#line 10207 "bacon.bac"
__b2c__assign = (char*)"if(bind(fd, (struct sockaddr *)addr, sizeof(struct sockaddr)) < 0) { return(17); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10208 "bacon.bac"
}
#line 10209 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "MULTICAST") == 0 ){
#line 10210 "bacon.bac"
__b2c__assign = (char*)"struct ip_mreq imreq; imreq.imr_multiaddr.s_addr = inet_addr(host); imreq.imr_interface.s_addr = INADDR_ANY;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10211 "bacon.bac"
__b2c__assign = (char*)"setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &imreq, sizeof(imreq));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10212 "bacon.bac"
}
#line 10213 "bacon.bac"
if( __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "UDP") != 0  AND  __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "BROADCAST") != 0  AND  __b2c__STRCMP(g_NETWORKTYPE__b2c__string_var ,  "MULTICAST") != 0 ){
#line 10214 "bacon.bac"
__b2c__assign = (char*)"if(listen(fd, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_MAX_BACKLOG), g_FUNCTIONS);
__b2c__assign = (char*) ") < 0) { return(18); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10215 "bacon.bac"
}
#line 10216 "bacon.bac"
__b2c__assign = (char*)"*handle = fd; free(addr); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10217 "bacon.bac"
__b2c__assign = (char*)"uintptr_t __b2c__accept(int l, char *k, char *priv, char *cert, uintptr_t fd) { uintptr_t handle; int desc; desc = accept(fd, NULL, NULL); if(desc < 0){ ERROR = 19; RUNTIMEFERR(\"ACCEPT\", ERROR, k, l); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10218 "bacon.bac"
if( g_OPTION_TLS ){
#line 10219 "bacon.bac"
__b2c__assign = (char*)"if(__b2c__option_tls) { int result = 0; SSL_CTX *ssl_context = NULL; SSL *ssl_sock = NULL; SSL_library_init(); ssl_context = SSL_CTX_new(TLS_server_method());"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10220 "bacon.bac"
__b2c__assign = (char*)"if(SSL_CTX_use_PrivateKey_file(ssl_context, priv, SSL_FILETYPE_PEM) <= 0) { return(41); } if(SSL_CTX_use_certificate_file(ssl_context, cert, SSL_FILETYPE_PEM) <= 0) { return(41); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10221 "bacon.bac"
__b2c__assign = (char*)"ssl_sock = SSL_new(ssl_context); SSL_set_fd(ssl_sock, desc); if((result = SSL_accept(ssl_sock)) <= 0){ fprintf(stderr, \"SSL ACCEPT error: %s\\n\", ERR_error_string(SSL_get_error(ssl_sock, result), NULL));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10222 "bacon.bac"
__b2c__assign = (char*)"return(-1); } handle = (uintptr_t)ssl_sock; } else { handle = (uintptr_t)desc; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10223 "bacon.bac"
} else {
#line 10224 "bacon.bac"
__b2c__assign = (char*)"if(!__b2c__option_tls) { handle = (uintptr_t)desc; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10225 "bacon.bac"
}
#line 10226 "bacon.bac"
__b2c__assign = (char*)"return(handle); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10227 "bacon.bac"
}
#line 10229 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "APPEND[[:space:]]|SAVE[[:space:]]")  OR  g_OPTION_EVAL ){
#line 10230 "bacon.bac"
__b2c__assign = (char*)"int __b2c__save(int mode, size_t size, char *file, ...) { FILE *outfile; va_list args; char *item; switch(mode){ case 0: case 1: outfile = fopen((const char *) file, \"w\"); break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10231 "bacon.bac"
__b2c__assign = (char*)"case 2: case 3: outfile = fopen((const char *) file, \"a\"); break; } if (outfile == NULL) { return(2); } switch(mode) { case 0: case 2: va_start(args, file); while((item = va_arg(args, char*)) != NULL)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10232 "bacon.bac"
__b2c__assign = (char*)"{ fprintf(outfile, \"%s\", item); } va_end(args); break; case 1: case 3: va_start(args, file); if(fwrite(va_arg(args, void*), 1, size, outfile) != size){ return(2); } va_end(args); break; } fclose (outfile); return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10233 "bacon.bac"
}
#line 10235 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SETSERIAL[[:space:]]") ){
#line 10236 "bacon.bac"
__b2c__assign = (char*)"int __b2c_setserial(int device, int mode, int param, int value, int donot) { struct termios tty; memset(&tty, 0, sizeof(tty)); if(tcgetattr(device, &tty) != 0) { return(33); } switch(mode)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10237 "bacon.bac"
__b2c__assign = (char*)"{ case 0: if(donot) { tty.c_iflag &= value; } else { tty.c_iflag |= value; } break; case 1: if(donot) { tty.c_oflag &= value; } else { tty.c_oflag |= value; } break; case 2: if(donot) { tty.c_cflag &= value; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10238 "bacon.bac"
__b2c__assign = (char*)"else { tty.c_cflag |= value; } break; case 3: if(donot) { tty.c_lflag &= value; } else { tty.c_lflag |= value; } break; case 4: tty.c_cc[param] = value; break; case 5: cfsetospeed(&tty, value); cfsetispeed(&tty, value);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10239 "bacon.bac"
__b2c__assign = (char*)"break; } if(tcsetattr(device, TCSANOW, &tty) != 0) { return(33); } return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10240 "bacon.bac"
}
#line 10242 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "GETLINE[[:space:]]") ){
#line 10243 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__getline(char **handle) { char *pos, *result; if(*handle == NULL || (*handle)[0] == '\\0') { return(NULL); } else { pos = strchr(*handle, '\\n'); if(pos)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10244 "bacon.bac"
__b2c__assign = (char*)"{ result = __b2c_Copy_N_String(NULL, *handle, (size_t)(pos - *handle)); } else { result = __b2c_Copy_String(NULL, *handle); } *handle += __b2c__len(result); if((*handle)[0] == '\\n') { (*handle)++; } } return(result); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10245 "bacon.bac"
}
#line 10247 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SPLIT[[:space:]]") ){
#line 10248 "bacon.bac"
__b2c__assign = (char*)"void __b2c__split_by(char ***array, int base, long *amount, char *string, char *by) { long length, i, start; __b2c__free_str_array_members(&(*array), base, *amount);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10249 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine(2, amount, string, by, 0); *array = (char**)realloc(*array, (*amount+base) * sizeof(char*)); for (i = 0; i < *amount; i++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10250 "bacon.bac"
__b2c__assign = (char*)"{ start = __b2c__delim_engine_cache(1, &length, string, by, i+1); (*array)[i + base] =__b2c_Copy_N_String(NULL, string + start, (size_t)length); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10251 "bacon.bac"
__b2c__assign = (char*)"void __b2c__split_with(char ***array, int base, long *amount, char *string, int counter) { long length, i; __b2c__free_str_array_members (&(*array), base, *amount);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10252 "bacon.bac"
__b2c__assign = (char*)"length = __b2c__len(string); if (counter > length) { counter = length; } *amount = (length / counter) + (length % counter != 0 ? 1 : 0); *array = (char**)realloc(*array, (*amount+base)*sizeof(char*));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10253 "bacon.bac"
__b2c__assign = (char*)"if (counter > 0) { for (i = 0; i < *amount; i++) { (*array)[i + base] = __b2c_Copy_N_String(NULL, string + i*counter, (size_t)counter); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10254 "bacon.bac"
}
#line 10256 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FOR[[:space:]]") ){
#line 10257 "bacon.bac"
__b2c__assign = (char*)"long __b2c__for_amount(char *string, char *step) { long amount = 0; __b2c__delim_engine(2, &amount, string, step, 0); return(amount); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10258 "bacon.bac"
__b2c__assign = (char*)"void __b2c__for_item (char **string, char *step, char **result) { long length = 0; long start; start = __b2c__delim_engine (1, &length, *string, step, 1); if(length == 0) { *result = NULL; } else"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10259 "bacon.bac"
__b2c__assign = (char*)"{ *result = (char *) __b2c_str_realloc (*result, length + 1); memmove (*result, *string + start, length); __b2c__SETLEN (*result, length); (*result)[length] = '\\0'; } *string += (start + length + __b2c__len (step)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10260 "bacon.bac"
}
#line 10262 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "MAKEDIR[[:space:]]") ){
#line 10263 "bacon.bac"
__b2c__assign = (char*)"int __b2c__makedir(char *newdir) { long start, amount = 0, length = 0; int item, collapse; char *dir; if (newdir != NULL && *newdir != 0) { collapse = __b2c__collapse; __b2c__collapse = 0; dir = (char*)calloc(__b2c__len(newdir)+1, sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10264 "bacon.bac"
__b2c__assign = (char*)"start = __b2c__delim_engine(2, &amount, newdir, \"/\", 0); for(item = 1; item <= amount; item++) { start = __b2c__delim_engine(1, &length, newdir, \"/\", item); if(length) { strncat(dir, newdir+start, length);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10265 "bacon.bac"
__b2c__assign = (char*)"if(mkdir(dir, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) < 0 && errno != EEXIST && errno != 0) { return(21); } } if(item < amount) { strcat(dir, \"/\"); } } free(dir); __b2c__collapse = collapse; } return(0); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10266 "bacon.bac"
}
#line 10268 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ALARM[[:space:]]") ){
#line 10269 "bacon.bac"
__b2c__assign = (char*)"void __b2c__alarm(void *func, long time) { void(*target)(int); struct itimerval alarm; struct sigaction psa; memset(&psa, 0, sizeof(psa)); psa.sa_flags = SA_RESETHAND|SA_RESTART;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10270 "bacon.bac"
__b2c__assign = (char*)"*((void**)&target) = func; psa.sa_handler = target; sigaction(SIGALRM, &psa, NULL); alarm.it_value.tv_sec = (long)(time)/1000; alarm.it_value.tv_usec = ((time)%1000)*1000;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10271 "bacon.bac"
__b2c__assign = (char*)"alarm.it_interval.tv_sec = 0; alarm.it_interval.tv_usec = 0; setitimer(ITIMER_REAL, &alarm, NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10272 "bacon.bac"
}
#line 10274 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SIGNAL[[:space:]]") ){
#line 10275 "bacon.bac"
__b2c__assign = (char*)"void __b2c__signal(void *func, int action) { void(*target)(int); struct sigaction psa; memset(&psa, 0, sizeof(psa)); *((void**)&target) = func; psa.sa_flags = SA_RESETHAND|SA_RESTART; psa.sa_handler = target; sigaction(action, &psa, NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10276 "bacon.bac"
}
#line 10278 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "CA\\$\\(|CIPHER\\$\\(|CN\\$\\(")  OR  g_OPTION_TLS ){
#line 10279 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__ca(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; X509 *cert; X509_NAME *name; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); } cert = (X509*)SSL_get_peer_certificate((SSL*)desc); if(cert==NULL) { ERROR = 41; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10280 "bacon.bac"
__b2c__assign = (char*)"name = X509_get_issuer_name(cert); X509_NAME_oneline(name, buffer, 4095); len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0';"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10281 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "gnutls") ){
__b2c__assign = (char*)"free(name);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 10282 "bacon.bac"
__b2c__assign = (char*)"X509_free(cert); return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10283 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__cn(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; X509 *cert; X509_NAME *name; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CN$\", ERROR, k, l); return(NULL); } cert = (X509*)SSL_get_peer_certificate((SSL*)desc); if(cert==NULL) { ERROR = 41; RUNTIMEFERR(\"CA$\", ERROR, k, l); return(NULL); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10284 "bacon.bac"
__b2c__assign = (char*)"name = X509_get_subject_name(cert); X509_NAME_oneline(name, buffer, 4095); len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0';"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10285 "bacon.bac"
if( TALLY(g_LIB_TLS__b2c__string_var, "gnutls") ){
__b2c__assign = (char*)"free(name);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
}
#line 10286 "bacon.bac"
__b2c__assign = (char*)"X509_free(cert); return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10287 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__cipher(int l, char *k, uintptr_t desc) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len; char buffer[4096] = { 0 }; if((SSL*)desc == NULL) { ERROR = 40; RUNTIMEFERR(\"CIPHER$\", ERROR, k, l); return(NULL); } SSL_CIPHER_description(SSL_get_current_cipher((SSL*)desc), buffer, 4095);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10288 "bacon.bac"
__b2c__assign = (char*)"len = strlen(buffer); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], len + 1); memmove(buf[idx], buffer, len);__b2c__SETLEN(buf[idx], len); buf[idx][len] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10289 "bacon.bac"
}
#line 10291 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "ESCAPE\\$\\(") ){
#line 10292 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__escape(int l, char *k, char *string) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long slen, length = 0; unsigned int current; if (string == NULL) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10293 "bacon.bac"
__b2c__assign = (char*)"while(*string) { current = __b2c__utf8toasc(string); if(current > 0xffff) { buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + 11); snprintf(buf[idx]+length, 11, \"\\\\U%08X\", current); length += 10; } else if(current > 0x7f)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10294 "bacon.bac"
__b2c__assign = (char*)"{ buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 7); snprintf(buf[idx]+length, 7, \"\\\\u%04X\", current); length += 6; } else { buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + 2);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10295 "bacon.bac"
__b2c__assign = (char*)"switch(current) { case 7: snprintf(buf[idx]+length, 3, \"\\\\a\"); length+=2; break; case 8: snprintf(buf[idx]+length, 3, \"\\\\b\"); length+=2; break; case 27: snprintf(buf[idx]+length, 3, \"\\\\e\"); length+=2; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10296 "bacon.bac"
__b2c__assign = (char*)"case 12: snprintf(buf[idx]+length, 3, \"\\\\f\"); length+=2; break; case 10: snprintf(buf[idx]+length, 3, \"\\\\n\"); length+=2; break; case 13: snprintf(buf[idx]+length, 3, \"\\\\r\"); length+=2; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10297 "bacon.bac"
__b2c__assign = (char*)"case 9: snprintf(buf[idx]+length, 3, \"\\\\t\"); length+=2; break; case 11: snprintf(buf[idx]+length, 3, \"\\\\v\"); length+=2; break; case 92: snprintf(buf[idx]+length, 3, \"\\\\\\\\\"); length+=2; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10298 "bacon.bac"
__b2c__assign = (char*)"case 39: snprintf(buf[idx]+length, 3, \"\\\\'\"); length+=2; break; case 34: snprintf(buf[idx]+length, 3, \"\\\\\\\"\"); length+=2; break; case 63: snprintf(buf[idx]+length, 3, \"\\\\?\"); length+=2; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10299 "bacon.bac"
__b2c__assign = (char*)"default: snprintf(buf[idx]+length, 2, \"%c\", current); length+=1; } } slen = __b2c__blen(l, k, \"ESCAPE$\", string, 1, 0); if(slen == 0) { break; } else {string += slen; } } __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10300 "bacon.bac"
}
#line 10302 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "UNESCAPE\\$\\(") ){
#line 10303 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__unescape(int l, char *k, char *string) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long len, tlen, length = 0; char *pos, *status = NULL; char hex[9], buffer[9]; uint32_t byte; if (string == NULL) { return (string); } idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10304 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char*)__b2c_str_realloc(buf[idx], sizeof(char)); while((pos = strchr (string, 92)) != NULL) { switch (*(pos + 1)) { case 'u': case 'U': buf[idx] = (char *) __b2c_str_realloc (buf[idx], length + (pos - string)); memcpy(buf[idx] + length, string, (size_t) (pos - string));"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10305 "bacon.bac"
__b2c__assign = (char*)"length += (uintptr_t) (pos - string); string = pos + 2; if (*(pos + 1) == 'u') { tlen = 4; } else { tlen = 8; } if (__b2c__len (string) < tlen) { ERROR = 5; RUNTIMEFERR(\"UNESCAPE$\", ERROR, k, l); return(NULL); } strncpy (hex, string, tlen); hex[tlen] = '\\0';"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10306 "bacon.bac"
__b2c__assign = (char*)"byte = strtol (hex, &status, 16); len = __b2c_utf8_conv (byte, buffer); buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + len); memcpy(buf[idx] + length, buffer, len); string += tlen; length += len;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10307 "bacon.bac"
__b2c__assign = (char*)"break; default: buf[idx] = (char*)__b2c_str_realloc(buf[idx], length + (pos - string) + 1); memcpy(buf[idx] + length, string, (size_t) (pos - string)); length += (uintptr_t) (pos - string);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10308 "bacon.bac"
__b2c__assign = (char*)"switch (*(pos + 1)) { case 'a': byte = 7; string = pos + 2; break; case 'b': byte = 8; string = pos + 2; break; case 'e': byte = 27; string = pos + 2; break; case 'f': byte = 12; string = pos + 2; break; case 'n': byte = 10; string = pos + 2; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10309 "bacon.bac"
__b2c__assign = (char*)"case 'r': byte = 13; string = pos + 2; break; case 't': byte = 9; string = pos + 2; break; case 'v': byte = 11; string = pos + 2; break; case 92: byte = 92; string = pos + 2; break; case 39: byte = 39; string = pos + 2; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10310 "bacon.bac"
__b2c__assign = (char*)"case 34: byte = 34; string = pos + 2; break; case 63: byte = 63; string = pos + 2; break; default: byte = (uint8_t)(*(pos)); string = pos + 1; } buf[idx][length] = (uint8_t) byte; length += 1; } } len = __b2c__len(string);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10311 "bacon.bac"
__b2c__assign = (char*)"buf[idx] = (char *) __b2c_str_realloc(buf[idx], length + len + 1); memcpy(buf[idx] + length, string, len); length += len; __b2c__SETLEN(buf[idx], length); buf[idx][length] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10312 "bacon.bac"
}
#line 10314 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TREE[[:space:]]") ){
#line 10315 "bacon.bac"
__b2c__assign = (char*)"void __b2c__tree_add(void *node, void **tree, int(*func)(const void*, const void*)) { void *result; if(node) { result = tsearch(node, tree, func); if(*(uintptr_t**)result != (uintptr_t*)node) { __b2c__STRFREE(node); } } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10316 "bacon.bac"
__b2c__assign = (char*)"void __b2c__binary_tree_free(void *tree, int(*func)(const void*, const void*)) { int total, i; void **array = { NULL }; total = __b2c__collect(tree, &array, "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_FUNCTIONS);
__b2c__assign = (char*) ", 0); for(i = "; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs(STR__b2c__string_var( g_OPTION_BASE), g_FUNCTIONS);
__b2c__assign = (char*) "; i<total; i++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10317 "bacon.bac"
__b2c__assign = (char*)"{ tdelete((void*)array[i], &tree, func); __b2c__STRFREE(array[i]); } if(array) { free(array); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10318 "bacon.bac"
}
#line 10320 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "FIND\\(") ){
#line 10321 "bacon.bac"
__b2c__assign = (char*)"int __b2c__find(int (*func)(const void*, const void*), void* tree, void* node, int dofree) { void **result; result = tfind(node, &tree, func); if(dofree) { free(node); } if(result == NULL) { return(0); } return(1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10322 "bacon.bac"
}
#line 10324 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SGN\\(") ){
#line 10325 "bacon.bac"
__b2c__assign = (char*)"char __b2c__sgn(double data) { if(data == 0) { return(0); } if(data > 0) { return(1); } return(-1); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10326 "bacon.bac"
}
#line 10328 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "VAL\\(") ){
#line 10329 "bacon.bac"
__b2c__assign = (char*)"double __b2c__val(char *data) { if(data == NULL) { return(0); } return(atof(data)); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10330 "bacon.bac"
}
#line 10332 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "SETENVIRON[[:space:]]") ){
#line 10333 "bacon.bac"
__b2c__assign = (char*)"void __b2c__setenviron(char *name, char *value) { if(name != NULL && value != NULL) { setenv(name, value, 1); } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10334 "bacon.bac"
}
#line 10336 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COLLECT[[:space:]]|TREE[[:space:]]") ){
#line 10337 "bacon.bac"
__b2c__assign = (char*)"static void __b2c__collect_do(const void *node, VISIT which, int depth) { switch (which) { case preorder: break; case endorder: break; case postorder: case leaf: __b2c__twalk_idx++; __b2c__twalk_array = (void**)realloc(__b2c__twalk_array, sizeof(void*)*__b2c__twalk_idx);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10338 "bacon.bac"
__b2c__assign = (char*)"__b2c__twalk_array[__b2c__twalk_idx-1] = *(uintptr_t**)node; break; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10339 "bacon.bac"
__b2c__assign = (char*)"int __b2c__collect(void *tree, void ***array, int base, int type) { int i, count; if(__b2c__twalk_array) { free(__b2c__twalk_array); __b2c__twalk_array = NULL; } if(*array) { free(*array); *array = NULL; } __b2c__twalk_idx = 0; twalk(tree, __b2c__collect_do); count = base;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10340 "bacon.bac"
__b2c__assign = (char*)"*array = (void*)calloc(__b2c__twalk_idx, sizeof(void*)); for (i = 0; i < __b2c__twalk_idx; i++) { switch(type) { case 0: (*array)[count++] = (char*)__b2c__twalk_array[i]; break; case 1: (*(double**)array)[count++] = *(double*)__b2c__twalk_array[i]; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10341 "bacon.bac"
__b2c__assign = (char*)"case 2: (*(float**)array)[count++] = *(float*)__b2c__twalk_array[i]; break; case 3: (*(long**)array)[count++] = *(long*)__b2c__twalk_array[i]; break; case 4: (*(int**)array)[count++] = *(int*)__b2c__twalk_array[i]; break;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10342 "bacon.bac"
__b2c__assign = (char*)"case 5: (*(short**)array)[count++] = *(short*)__b2c__twalk_array[i]; break; case 6: (*(char**)array)[count++] = *(char*)__b2c__twalk_array[i]; break; } } return (count-base); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10343 "bacon.bac"
}
#line 10345 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "TOTAL\\(") ){
#line 10346 "bacon.bac"
__b2c__assign = (char*)"static void __b2c__total_do(const void *node, VISIT which, int depth) { switch (which) { case preorder: break; case endorder: break; case postorder: case leaf: __b2c__twalk_idx++; break; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10347 "bacon.bac"
__b2c__assign = (char*)"int __b2c__total(void *tree) { __b2c__twalk_idx = 0; twalk(tree, __b2c__total_do); return(__b2c__twalk_idx); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10348 "bacon.bac"
}
#line 10350 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "PARSE[[:space:]]") ){
#line 10351 "bacon.bac"
__b2c__assign = (char*)"void __b2c__parse(char ***array, int base, long *amount1, char *string, char *with, char *delim) { long dlen, start1, start2, amount2, length1, length2, tmplen, sublen = 0; int x, i = 0, wildcard = 0, next = 0; char *pos = NULL;"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10352 "bacon.bac"
__b2c__assign = (char*)"__b2c__free_str_array_members (&(*array), base, *amount1); free (*array); *array = NULL; if (string == NULL && with == NULL) { *amount1 = 0; return; } if (delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10353 "bacon.bac"
__b2c__assign = (char*)"start1 = __b2c__delim_engine (2, amount1, string, delim, 0); if(*amount1 == 0) { return; } *array = (char **) realloc (*array, (*amount1 + base) * sizeof (char *)); dlen = __b2c__len (delim);"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10354 "bacon.bac"
__b2c__assign = (char*)"for (x = 0; x < *amount1; x++) { start1 = __b2c__delim_engine (1, &length1, string, delim, 1); start2 = __b2c__delim_engine (1, &length2, with, delim, 1); if(!strncmp (with, \"?\", 1))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10355 "bacon.bac"
__b2c__assign = (char*)"{ (*array)[i + base] = __b2c_Copy_N_String(NULL, string, (size_t) length1); i++; string += (start1 + length1 + dlen); with += (start2 + length2 + dlen); } else { next = 0; if(!strncmp (with, \"*\", 1))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10356 "bacon.bac"
__b2c__assign = (char*)"{ wildcard = 1; if(!pos) { pos = string; } __b2c__delim_engine (2, &amount2, with + 1, delim, 0); if(amount2) { next = 1 + dlen; } else { next = 1; } } else if(!strncmp(with, \"\\\\*\", 2) || !strncmp(with, \"\\\\?\", 2))"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10357 "bacon.bac"
__b2c__assign = (char*)"{ with++; length2--; } __b2c__delim_engine (1, &tmplen, with + next, delim, 1); if(length1 != tmplen || memcmp(string, with+next, tmplen)) { if (wildcard == 1) { if(sublen == 0) { sublen += length1; } else { sublen += length1 + dlen; } }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10358 "bacon.bac"
__b2c__assign = (char*)"else { __b2c__free_str_array_members (&(*array), base, i); free (*array); *array = NULL; i = 0; break; } } else { if(wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t)sublen); pos = NULL; sublen = 0; i++; } wildcard = 0; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10359 "bacon.bac"
__b2c__assign = (char*)"string += (start1 + length1 + dlen); if (wildcard == 0) { with += (start2 + length1 + dlen + next); } } } if (wildcard) { (*array)[i + base] = __b2c_Copy_N_String(NULL, pos, (size_t) sublen); i++; } *amount1 = i; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10360 "bacon.bac"
}
#line 10362 "bacon.bac"
if( REGEX(g_DEPEND__b2c__string_var, "COLLAPSE\\$\\(") ){
#line 10363 "bacon.bac"
__b2c__assign = (char*)"char *__b2c__collapse_func(char *string, char *delim) { static char *buf[__b2c_STRING_FUNC] = { NULL }; static int idx = 0; long start, dlen, option, x, total = 0; long amount = 0, length = 0; if (string == NULL) { return (string); } if (delim == NULL) { delim = __b2c__option_delim; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10364 "bacon.bac"
__b2c__assign = (char*)"option = __b2c__collapse; __b2c__collapse = 1; dlen = __b2c__len (delim); idx++; if(idx == __b2c_STRING_FUNC) { idx = 0; } buf[idx] = (char*)__b2c_str_realloc(buf[idx], __b2c__len (string) + 1); __b2c__delim_engine(2, &amount, string, delim, 0); for (x = 0; x < amount; x++)"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10365 "bacon.bac"
__b2c__assign = (char*)"{ start = __b2c__delim_engine (1, &length, string, delim, 1); memmove(buf[idx] + total, string + start, length); total += length; if (x < amount - 1) { memmove(buf[idx] + total, delim, dlen); total += dlen; }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10366 "bacon.bac"
__b2c__assign = (char*)"string += (start + length); } __b2c__collapse = option; __b2c__SETLEN(buf[idx], total); buf[idx][total] = '\\0'; return(char*)(buf[idx]); }"; if(__b2c__assign != NULL) { fputs(__b2c__assign, g_FUNCTIONS); }
fputs("\n", g_FUNCTIONS);
#line 10367 "bacon.bac"
}
#line 10369 "bacon.bac"
fclose(g_FUNCTIONS);
#line 10372 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_GENERIC__b2c__string_var , " " , g_FUNCTIONS__b2c__string_var) ;
#line 10375 "bacon.bac"
if( g_SEMANTIC == 0 ){
#line 10376 "bacon.bac"
semantic__b2c__string_var__b2c_array = __b2c__lookup_by_order(__b2c__assoc_g_SEMANTIC_MEMFREE__b2c__string_var, &semantic__b2c__string_var, semantic__b2c__string_var__b2c_array, 1);
COUNTER = semantic__b2c__string_var__b2c_array;
#line 10377 "bacon.bac"
while( (COUNTER )> 0 ){
#line 10378 "bacon.bac"
if( LEN(g_SEMANTIC_MEMFREE__b2c__string_var(semantic__b2c__string_var[(uint64_t)COUNTER])) ){
__b2c__assign = (char*)"WARNING: no FREE for the memory address "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_SEMANTIC_MEMFREE__b2c__string_var(semantic__b2c__string_var[(uint64_t)COUNTER]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 10379 "bacon.bac"
COUNTER = COUNTER - (1);
#line 10380 "bacon.bac"
}
#line 10381 "bacon.bac"
}
#line 10384 "bacon.bac"
if( g_SEMANTIC == 0 ){
#line 10385 "bacon.bac"
semantic__b2c__string_var__b2c_array = __b2c__lookup_by_order(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var, &semantic__b2c__string_var, semantic__b2c__string_var__b2c_array, 1);
COUNTER = semantic__b2c__string_var__b2c_array;
#line 10386 "bacon.bac"
while( (COUNTER )> 0 ){
#line 10387 "bacon.bac"
if( LEN(g_SEMANTIC_OPENCLOSE__b2c__string_var(semantic__b2c__string_var[(uint64_t)COUNTER])) ){
__b2c__assign = (char*)"WARNING: no CLOSE for the OPEN handle "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_SEMANTIC_OPENCLOSE__b2c__string_var(semantic__b2c__string_var[(uint64_t)COUNTER]); if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
}
#line 10388 "bacon.bac"
COUNTER = COUNTER - (1);
#line 10389 "bacon.bac"
}
#line 10390 "bacon.bac"
}
#line 10393 "bacon.bac"
if( LEN(g_FUNCNAME__b2c__string_var) ){
#line 10394 "bacon.bac"
__b2c__assign = (char*)"Syntax error: the SUB/FUNCTION '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_FUNCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' has no END in file '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CURFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "'!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 10395 "bacon.bac"
exit(1);
#line 10396 "bacon.bac"
}
#line 10399 "bacon.bac"
if( ISTRUE(g_TMP_PRESERVE) ){
#line 10400 "bacon.bac"
if( ISTRUE(LEN(EXEC__b2c__string_var("command -v indent 2>/dev/null"))) ){
#line 10401 "bacon.bac"
__b2c__assign = (char*)"Applying indentation... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 10402 "bacon.bac"
__b2c__forin_tmpfile__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_string, g_TMP_FILES__b2c__string_var); __b2c__forin_tmpfile__b2c__string_var_string_org = __b2c__forin_tmpfile__b2c__string_var_string;
__b2c__forin_tmpfile__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_tmpfile__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_tmpfile__b2c__string_var_string, __b2c__forin_tmpfile__b2c__string_var_step);
for(; __b2c__forin_tmpfile__b2c__string_var_ptr > 0; __b2c__forin_tmpfile__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_tmpfile__b2c__string_var_string_org, __b2c__forin_tmpfile__b2c__string_var_step, &tmpfile__b2c__string_var);
#line 10403 "bacon.bac"
if( NOT(REGEX(tmpfile__b2c__string_var, ".*\\.cpp"))  AND  NOT(REGEX(tmpfile__b2c__string_var, ".*\\.tmp"))  AND  NOT(REGEX(tmpfile__b2c__string_var, ".*\\.bac$"))  AND  NOT(REGEX(tmpfile__b2c__string_var, ".*\\.nostr$")) ){
#line 10404 "bacon.bac"
if( ISTRUE(INSTR(OS__b2c__string_var, "Darwin"))  OR  ISTRUE(INSTR(OS__b2c__string_var, "BSD")) ){
#line 10405 "bacon.bac"
if(rename(tmpfile__b2c__string_var, CONCAT__b2c__string_var( tmpfile__b2c__string_var , ".BAK")) < 0) { ERROR = 9; RUNTIMEERROR("RENAME", 10405, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 10406 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "indent " , tmpfile__b2c__string_var , ".BAK " , tmpfile__b2c__string_var) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 10407 "bacon.bac"
if(unlink(CONCAT__b2c__string_var( tmpfile__b2c__string_var , ".BAK") )==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 10407, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 10408 "bacon.bac"
} else {
#line 10410 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "indent -bad -bap -bli0 -cli4 -cbi0 -nbc -nbfda -nsc -nprs -bls -blf -lp -ts4 -ppi2 -npsl -i4 -il4 -l140 -nbbo " , tmpfile__b2c__string_var) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 10411 "bacon.bac"
if(unlink(CONCAT__b2c__string_var( tmpfile__b2c__string_var , "~") )==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 10411, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 10412 "bacon.bac"
}
#line 10413 "bacon.bac"
}
#line 10414 "bacon.bac"
}
#line 10415 "bacon.bac"
__b2c__assign = (char*)"done."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10416 "bacon.bac"
} else {
#line 10417 "bacon.bac"
__b2c__assign = (char*)"WARNING: 'indent' not found on this system!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10418 "bacon.bac"
__b2c__assign = (char*)"Generated source code cannot be beautified."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10419 "bacon.bac"
}
#line 10420 "bacon.bac"
}
#line 10423 "bacon.bac"
if( g_XGETTEXT ){
#line 10424 "bacon.bac"
if( ISTRUE(LEN(EXEC__b2c__string_var("command -v xgettext 2>/dev/null"))) ){
#line 10425 "bacon.bac"
__b2c__assign = (char*)"Executing xgettext... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 10426 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "xgettext --keyword=INTL" , g_STRINGSIGN__b2c__string_var , " --keyword=NNTL" , g_STRINGSIGN__b2c__string_var , ":1,2 -d " , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1) , " -s -o " , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1) , ".pot " , g_TMP_FILES__b2c__string_var) ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 10427 "bacon.bac"
if( FILEEXISTS( CONCAT__b2c__string_var(BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1) , ".pot") ) ){
#line 10428 "bacon.bac"
__b2c__assign = (char*)"done."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10429 "bacon.bac"
} else {
#line 10430 "bacon.bac"
__b2c__assign = (char*)"WARNING: catalog file not created!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10431 "bacon.bac"
}
#line 10432 "bacon.bac"
} else {
#line 10433 "bacon.bac"
__b2c__assign = (char*)"WARNING: 'xgettext' not found on this system!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10434 "bacon.bac"
}
#line 10435 "bacon.bac"
}
#line 10438 "bacon.bac"
makefile = fopen((const char*)CONCAT__b2c__string_var( g_TEMPDIR__b2c__string_var , "/Makefile.bacon" ), "w");
if(makefile == NULL){ ERROR = 2; RUNTIMEERROR("OPEN FOR WRITING", 10438, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 10439 "bacon.bac"
__b2c__assign = (char*)"# Created with BaCon "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_VERSION__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " - (c) Peter van Eerten - MIT License"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10440 "bacon.bac"
__b2c__assign = (char*)BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_BINEXT__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ": "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".o"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10441 "bacon.bac"
__b2c__assign = (char*)TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_CCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " -o "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_BINEXT__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".o "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_LDFLAGS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_LIB_TLS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " -lm"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10442 "bacon.bac"
__b2c__assign = (char*)BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".o: "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".c"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10443 "bacon.bac"
__b2c__assign = (char*)TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_CCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_CCFLAGS__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " -c "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".c"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10444 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".PHONY: clean"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10445 "bacon.bac"
__b2c__assign = (char*)"clean:"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10446 "bacon.bac"
__b2c__assign = (char*)TAB__b2c__string_var(1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) "rm -f *.o *.c "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) g_BINEXT__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) " "; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
__b2c__assign = (char*) ".*.* Makefile.bacon"; if(__b2c__assign != NULL) { fputs(__b2c__assign, makefile); }
fputs("\n", makefile);
#line 10447 "bacon.bac"
fclose(makefile);
#line 10448 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_TEMPDIR__b2c__string_var , "/Makefile.bacon") ;
#line 10451 "bacon.bac"
if( ISFALSE(g_NO_COMPILE) ){
#line 10453 "bacon.bac"
if( ISFALSE(LEN(EXEC__b2c__string_var( CONCAT__b2c__string_var("command -v " , g_CCNAME__b2c__string_var , " 2>/dev/null") ))) ){
#line 10454 "bacon.bac"
__b2c__assign = (char*)"ERROR: '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) g_CCNAME__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
__b2c__assign = (char*) "' not found on this system!"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 10455 "bacon.bac"
__b2c__assign = (char*)"Generated source code cannot be compiled."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 10456 "bacon.bac"
exit(0);
#line 10457 "bacon.bac"
}
#line 10458 "bacon.bac"
__b2c__assign = (char*)"Compiling '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_SOURCEFILE__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "'... "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
#line 10461 "bacon.bac"
SETENVIRON("LANG", "C");
#line 10463 "bacon.bac"
old_curdir__b2c__string_var = __b2c_Copy_String(old_curdir__b2c__string_var, (char*) CURDIR__b2c__string_var);
#line 10464 "bacon.bac"
if(g_TEMPDIR__b2c__string_var == NULL || chdir(g_TEMPDIR__b2c__string_var) == -1){ ERROR = 22; RUNTIMEERROR("CHANGEDIR", 10464, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 10465 "bacon.bac"
RETVAL = system(CONCAT__b2c__string_var( "make -f Makefile.bacon 2>" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".log") ); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
#line 10466 "bacon.bac"
RETURN_CODE=(long)( RETVAL);
#line 10469 "bacon.bac"
if(old_curdir__b2c__string_var == NULL || chdir(old_curdir__b2c__string_var) == -1){ ERROR = 22; RUNTIMEERROR("CHANGEDIR", 10469, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
#line 10472 "bacon.bac"
g_TMP_FILES__b2c__string_var = F_CONCAT__b2c__string_var(g_TMP_FILES__b2c__string_var, g_TMP_FILES__b2c__string_var , " " , g_TEMPDIR__b2c__string_var , "/" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".log " , g_TEMPDIR__b2c__string_var , "/" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".o") ;
#line 10474 "bacon.bac"
if( ISFALSE(FILELEN( CONCAT__b2c__string_var(g_TEMPDIR__b2c__string_var , "/" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".log") )) ){
#line 10475 "bacon.bac"
__b2c__assign = (char*)"Done, program '"; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1); if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) g_BINEXT__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "' ready."; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fputs("\n", stdout);
#line 10476 "bacon.bac"
if( g_EXEC ){
RETVAL = system(CONCAT__b2c__string_var( g_TEMPDIR__b2c__string_var , "/" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var, 1))); if(WIFEXITED(RETVAL)) { RETVAL = WEXITSTATUS(RETVAL); }
}
#line 10477 "bacon.bac"
} else {
#line 10478 "bacon.bac"
__b2c__forin_line__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_line__b2c__string_var_string, LOAD__b2c__string_var( CONCAT__b2c__string_var(g_TEMPDIR__b2c__string_var , "/" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".log") )); __b2c__forin_line__b2c__string_var_string_org = __b2c__forin_line__b2c__string_var_string;
__b2c__forin_line__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_line__b2c__string_var_step, NL__b2c__string_var);
__b2c__forin_line__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_line__b2c__string_var_string, __b2c__forin_line__b2c__string_var_step);
for(; __b2c__forin_line__b2c__string_var_ptr > 0; __b2c__forin_line__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_line__b2c__string_var_string_org, __b2c__forin_line__b2c__string_var_step, &line__b2c__string_var);
#line 10479 "bacon.bac"
if( REGEX(line__b2c__string_var, "\\.generic\\.h") ){
continue;
}
#line 10480 "bacon.bac"
if( REGEX(line__b2c__string_var, "error:|warning:|note:") ){
#line 10481 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, g_STRINGSIGN__b2c__string_var, "$"));
#line 10482 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, g_FLOATSIGN__b2c__string_var, "#"));
#line 10483 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, g_LONGSIGN__b2c__string_var, "%"));
#line 10484 "bacon.bac"
__b2c__assign = (char*)line__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 10485 "bacon.bac"
break;
#line 10486 "bacon.bac"
}
#line 10487 "bacon.bac"
}
#line 10488 "bacon.bac"
if( NOT(g_QUIET) ){
#line 10489 "bacon.bac"
if( __b2c__STRCMP(GETENVIRON__b2c__string_var("BACON_IN_DOCKER") ,  "true") == 0 ){
#line 10490 "bacon.bac"
response__b2c__string_var = __b2c_Copy_String(response__b2c__string_var, (char*) "y");
#line 10491 "bacon.bac"
} else {
#line 10492 "bacon.bac"
__b2c__assign = (char*)NL__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
__b2c__assign = (char*) "INFO: see full error report (y/[n])? "; if(__b2c__assign != NULL) { fputs(__b2c__assign, stdout); }
fflush(stdout);
__b2c__input(__LINE__, __FILE__, &__b2c__assign, "\n");
response__b2c__string_var = __b2c_Copy_String(response__b2c__string_var, __b2c__assign);
__b2c__STRFREE(__b2c__assign); __b2c__assign = NULL;
#line 10493 "bacon.bac"
}
#line 10494 "bacon.bac"
if( __b2c__STRCMP(LCASE__b2c__string_var(response__b2c__string_var) ,  "y") == 0 ){
#line 10495 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) LOAD__b2c__string_var( CONCAT__b2c__string_var(g_TEMPDIR__b2c__string_var , "/" , BASENAME__b2c__string_var(g_SOURCEFILE__b2c__string_var) , ".log") ));
#line 10496 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, g_STRINGSIGN__b2c__string_var, "$"));
#line 10497 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, g_FLOATSIGN__b2c__string_var, "#"));
#line 10498 "bacon.bac"
line__b2c__string_var = __b2c_Copy_String(line__b2c__string_var, (char*) REPLACE__b2c__string_var(line__b2c__string_var, g_LONGSIGN__b2c__string_var, "%"));
#line 10499 "bacon.bac"
__b2c__assign = (char*)line__b2c__string_var; if(__b2c__assign != NULL) { fputs(__b2c__assign, stderr); }
fputs("\n", stderr);
#line 10500 "bacon.bac"
}
#line 10501 "bacon.bac"
}
#line 10504 "bacon.bac"
g_TMP_PRESERVE=(long)( 1);
#line 10505 "bacon.bac"
}
#line 10506 "bacon.bac"
}
#line 10509 "bacon.bac"
if( ISFALSE(g_TMP_PRESERVE) ){
#line 10510 "bacon.bac"
__b2c__forin_tmpfile__b2c__string_var_string = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_string, g_TMP_FILES__b2c__string_var); __b2c__forin_tmpfile__b2c__string_var_string_org = __b2c__forin_tmpfile__b2c__string_var_string;
__b2c__forin_tmpfile__b2c__string_var_step = __b2c_Copy_String(__b2c__forin_tmpfile__b2c__string_var_step, __b2c__option_delim);
__b2c__forin_tmpfile__b2c__string_var_ptr = __b2c__for_amount(__b2c__forin_tmpfile__b2c__string_var_string, __b2c__forin_tmpfile__b2c__string_var_step);
for(; __b2c__forin_tmpfile__b2c__string_var_ptr > 0; __b2c__forin_tmpfile__b2c__string_var_ptr--) { __b2c__for_item(&__b2c__forin_tmpfile__b2c__string_var_string_org, __b2c__forin_tmpfile__b2c__string_var_step, &tmpfile__b2c__string_var);
#line 10511 "bacon.bac"
if( FILEEXISTS(tmpfile__b2c__string_var)  AND  NOT(REGEX(tmpfile__b2c__string_var, ".bac$")) ){
if(unlink(tmpfile__b2c__string_var)==-1){ ERROR = 7; RUNTIMEERROR("DELETE", 10511, "../bacon.bac", ERROR, __B2C__PROGRAM__EXIT); }
}
#line 10512 "bacon.bac"
}
#line 10513 "bacon.bac"
}
#line 10515 "bacon.bac"
__b2c__hash_clear(__b2c__assoc_g_ALL_MAIN_VARS__b2c__string_var);
__b2c__hash_clear(__b2c__assoc_g_ALL_FUNC_VARS__b2c__string_var);
__b2c__hash_clear(__b2c__assoc_g_ALL_DIM_VARS__b2c__string_var);
__b2c__hash_clear(__b2c__assoc_g_SEMANTIC_MEMFREE__b2c__string_var);
__b2c__hash_clear(__b2c__assoc_g_SEMANTIC_OPENCLOSE__b2c__string_var);
__b2c__hash_clear(__b2c__assoc_g_MACRO_STRINGS__b2c__string_var);
#line 10517 "bacon.bac"
exit(RETURN_CODE);
__B2C__PROGRAM__EXIT:
return(0);
}
